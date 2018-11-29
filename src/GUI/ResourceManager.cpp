#include "Precompiled.h"
#include "ResourceManager.h"
#include "XmlDocument.h"
#include "IResource.h"
#include "DataManager.h"
#include "FactoryManager.h"

#include "ResourceImageSet.h"

namespace GUI
{

	const std::string XML_TYPE("Resource");
	const std::string XML_TYPE_LIST("List");

	INSTANCE_IMPLEMENT(ResourceManager)

	void ResourceManager::Initialise()
	{
		ASSERT(!mIsInitialise, INSTANCE_TYPE_NAME << " initialised twice");
		LOG(Info, "* Initialise: " << INSTANCE_TYPE_NAME);

		RegisterLoadXmlDelegate(XML_TYPE) = NewDelegate(this, &ResourceManager::_load);
		RegisterLoadXmlDelegate(XML_TYPE_LIST) = NewDelegate(this, &ResourceManager::_loadList);

		FactoryManager::GetInstance().RegisterFactory<ResourceImageSet>(XML_TYPE);

		LOG(Info, INSTANCE_TYPE_NAME << " successfully initialized");
		mIsInitialise = true;
	}

	void ResourceManager::Shutdown()
	{
		if (!mIsInitialise) return;
		LOG(Info, "* Shutdown: " << INSTANCE_TYPE_NAME);

		FactoryManager::GetInstance().UnregisterFactory<ResourceImageSet>(XML_TYPE);

		Clear();
		UnregisterLoadXmlDelegate(XML_TYPE);
		UnregisterLoadXmlDelegate(XML_TYPE_LIST);

		mMapLoadXmlDelegate.clear();

		LOG(Info, INSTANCE_TYPE_NAME << " successfully shutdown");
		mIsInitialise = false;
	}

	bool ResourceManager::Load(const std::string& file)
	{
		return _loadImplement(file, false, "", INSTANCE_TYPE_NAME);
	}

	void ResourceManager::_load(xml::ElementPtr node, const std::string& file, Version version)
	{
		FactoryManager& factory = FactoryManager::GetInstance();

		VectorGuid vector_guid;
		xml::ElementEnumerator root = node->GetElementEnumerator();
		while (root.Next(XML_TYPE))
		{
			std::string id, type, name;
			root->findAttribute("type", type);
			root->findAttribute("name", name);
			root->findAttribute("id", id);

			Guid guid(id);
			if (!guid.empty())
			{
				if (mResourcesID.find(guid) != mResourcesID.end())
				{
					LOG(warning, "dublicate resource id " << guid.Print());
				}
			}

			if (mResources.find(name) != mResources.end())
			{
				LOG(warning, "dublicate resource name '" << name << "'");
			}

			vector_guid.push_back(guid);

			IObject* object = factory.CreateObject(XML_TYPE, type);
			if (object == nullptr)
			{
				LOG(Error, "resource type '" << type << "' not found");
				continue;
			}

			IResourcePtr resource = object->CastType<IResource>();
			resource->Deserialization(root.Current(), version);

			if (!guid.empty()) mResourcesID[guid] = resource;
			if (!name.empty()) mResources[name] = resource;
		}

		if (!vector_guid.empty())
		{
			mListFileGuid[file] = vector_guid;
		}

	}

	std::string ResourceManager::GetFileNameByID(const Guid& id)
	{
		for (MapVectorString::iterator item=mListFileGuid.begin(); item!=mListFileGuid.end(); ++item)
		{
			for (VectorGuid::iterator item2=item->second.begin(); item2!=item->second.end(); ++item2)
			{
				if (*item2 == id)
				{
					return item->first;
				}
			}
		}
		return "";
	}

	void ResourceManager::_loadList(xml::ElementPtr node, const std::string& file, Version version)
	{
		xml::ElementEnumerator curNode = node->GetElementEnumerator();
		while (curNode.Next(XML_TYPE_LIST))
		{
			std::string source;
			if (!curNode->findAttribute("file", source)) continue;
			LOG(Info, "Load ini curFile '" << source << "'");
			_loadImplement(source, false, "", INSTANCE_TYPE_NAME);
		}
	}

	ResourceManager::LoadXmlDelegate& ResourceManager::RegisterLoadXmlDelegate(const std::string& key)
	{
		MapLoadXmlDelegate::iterator iter = mMapLoadXmlDelegate.find(key);
		ASSERT(iter == mMapLoadXmlDelegate.end(), "name delegate is exist");
		return (mMapLoadXmlDelegate[key] = LoadXmlDelegate());
	}

	void ResourceManager::UnregisterLoadXmlDelegate(const std::string& key)
	{
		MapLoadXmlDelegate::iterator iter = mMapLoadXmlDelegate.find(key);
		if (iter != mMapLoadXmlDelegate.end()) mMapLoadXmlDelegate.erase(iter);
	}

	bool ResourceManager::_loadImplement(const std::string& file, bool match, const std::string& type, const std::string& instance)
	{
		IDataStream* data = DataManager::GetInstance().GetData(file);
		if (data == nullptr)
		{
			LOG(Error, instance << " : '" << file << "', not found");
			return false;
		}

		xml::Document doc;
		if (!doc.Open(data))
		{
			LOG(Error, instance << " : '" << file << "', " << doc.GetLastError());

			// FIXME
			delete data;

			return false;
		}

		// FIXME
		delete data;

		xml::ElementPtr root = doc.GetRoot();
		if ( (nullptr == root) || (root->GetName() != "GUI") )
		{
			LOG(Error, instance << " : '" << file << "', tag 'GUI' not found");
			return false;
		}

		std::string curType;
		if (root->findAttribute("type", curType))
		{
			Version version = Version::Parse(root->findAttribute("version"));
			MapLoadXmlDelegate::iterator iter = mMapLoadXmlDelegate.find(curType);
			if (iter != mMapLoadXmlDelegate.end())
			{
				if ((!match) || (curType == type)) (*iter).second(root, file, version);
				else
				{
					LOG(Error, instance << " : '" << file << "', curType '" << type << "' not found");
					return false;
				}
			}
			else
			{
				LOG(Error, instance << " : '" << file << "', delegate for curType '" << curType << "'not found");
				return false;
			}
		}
		else if (!match)
		{
			xml::ElementEnumerator node = root->GetElementEnumerator();
			while (node.Next("GUI"))
			{
				if (node->findAttribute("type", curType))
				{
					Version version = Version::Parse(root->findAttribute("version"));
					MapLoadXmlDelegate::iterator iter = mMapLoadXmlDelegate.find(curType);
					if (iter != mMapLoadXmlDelegate.end())
					{
						(*iter).second(node.Current(), file, version);
					}
					else
					{
						LOG(Error, instance << " : '" << file << "', delegate for curType '" << curType << "'not found");
					}
				}
				else
				{
					LOG(Error, instance << " : '" << file << "', tag 'curType' not found");
				}
			}
		}

		return true;
	}

	IResourcePtr ResourceManager::GetByID(const Guid& id, bool _throw)
	{
		MapResourceID::iterator iter = mResourcesID.find(id);
		if (iter == mResourcesID.end())
		{
			if (_throw) EXCEPT("resource '" << id.Print() << "' not found");
			LOG(warning, "resource '" << id.Print() << "' not found");
			return nullptr;
		}
		return iter->second;
	}

	void ResourceManager::AddResource(IResourcePtr item)
	{
		if (!item->GetResourceName().empty())
			mResources[item->GetResourceName()] = item;
		if (!item->GetResourceID().empty())
			mResourcesID[item->GetResourceID()] = item;
	}

	void ResourceManager::RemoveResource(IResourcePtr item)
	{
		if (item == nullptr) return;

		if (!item->GetResourceName().empty())
		{
			MapResource::iterator curItem = mResources.find(item->GetResourceName());
			if (curItem != mResources.end())
				mResources.erase(curItem);
		}

		if (!item->GetResourceID().empty())
		{
			MapResourceID::iterator id = mResourcesID.find(item->GetResourceID());
			if (id != mResourcesID.end())
				mResourcesID.erase(id);
		}
	}

} // namespace GUI

