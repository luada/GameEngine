#include "Precompiled.h"
#include "SkinManager.h"
#include "LanguageManager.h"
#include "ResourceSkin.h"
#include "XmlDocument.h"
#include "SubWidgetManager.h"
#include "Gui.h"
#include "DataManager.h"
#include "FactoryManager.h"
#include "IStateInfo.h"

namespace GUI
{

	const std::string XML_TYPE("Skin");
	const std::string XML_TYPE_RESOURCE("Resource");
	const std::string RESOURCE_DEFAULT_NAME("Default");

	INSTANCE_IMPLEMENT(SkinManager)

	void SkinManager::Initialise()
	{
		ASSERT(!mIsInitialise, INSTANCE_TYPE_NAME << " initialised twice");
		LOG(Info, "* Initialise: " << INSTANCE_TYPE_NAME);

		ResourceManager::GetInstance().RegisterLoadXmlDelegate(XML_TYPE) = NewDelegate(this, &SkinManager::_load);
		FactoryManager::GetInstance().RegisterFactory<ResourceSkin>(XML_TYPE_RESOURCE);

		mDefaultName = "skin_Default";
		CreateDefault(mDefaultName);

		LOG(Info, INSTANCE_TYPE_NAME << " successfully initialized");
		mIsInitialise = true;
	}

	void SkinManager::Shutdown()
	{
		if (!mIsInitialise) return;
		LOG(Info, "* Shutdown: " << INSTANCE_TYPE_NAME);

		ResourceManager::GetInstance().UnregisterLoadXmlDelegate(XML_TYPE);
		FactoryManager::GetInstance().UnregisterFactory<ResourceSkin>(XML_TYPE_RESOURCE);

		LOG(Info, INSTANCE_TYPE_NAME << " successfully shutdown");
		mIsInitialise = false;
	}

	bool SkinManager::Load(const std::string& file)
	{
		return ResourceManager::GetInstance()._loadImplement(file, true, XML_TYPE, INSTANCE_TYPE_NAME);
	}

	void SkinManager::_load(xml::ElementPtr node, const std::string& file, Version version)
	{
		xml::ElementEnumerator skin = node->GetElementEnumerator();
		while (skin.Next(XML_TYPE))
		{
			std::string name = skin->findAttribute("name");
			std::string type = skin->findAttribute("type");
			if (type.empty()) type = "ResourceSkin";

			IObject* object = FactoryManager::GetInstance().CreateObject(XML_TYPE_RESOURCE, type);
			if (object != nullptr)
			{
				ResourceSkin* data = object->CastType<ResourceSkin>();
				data->Deserialization(skin.Current(), version);

				ResourceManager::GetInstance().AddResource(data);
			}
		}
	}

	void SkinManager::CreateDefault(const std::string& value)
	{
		xml::Document doc;
		xml::ElementPtr root = doc.CreateRoot("GUI");
		xml::ElementPtr newnode = root->CreateChild("Resource");
		newnode->AddAttribute("type", ResourceSkin::GetClassTypeName());
		newnode->AddAttribute("name", value);

		ResourceManager::GetInstance()._load(root, "", Version());
	}

	ResourceSkin* SkinManager::GetByName(const std::string& name) const
	{
		IResource* result = nullptr;
		if (!name.empty() && name != RESOURCE_DEFAULT_NAME)
			result = ResourceManager::GetInstance().GetByName(name, false);

		if (result == nullptr)
		{
			result = ResourceManager::GetInstance().GetByName(mDefaultName, false);
			LOG(Error, "Skin '" << name << "' not found. Replaced with default skin.");
		}

		return result ? result->CastType<ResourceSkin>(false) : nullptr;
	}

	bool SkinManager::IsExist(const std::string& name) const
	{
		return ResourceManager::GetInstance().IsExist(name);
	}

	void SkinManager::SetDefaultSkin(const std::string& value)
	{
		mDefaultName = value;
	}

} // namespace GUI

