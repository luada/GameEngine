#include "Precompiled.h"
#include "FactoryManager.h"
#include "FontManager.h"
#include "XmlDocument.h"

#include "ResourceManualFont.h"
#include "ResourceTrueTypeFont.h"

namespace GUI
{
	const std::string XML_TYPE("Font");
	const std::string XML_TYPE_RESOURCE("Resource");
	const std::string XML_TYPE_PROPERTY("Property");
	const std::string RESOURCE_DEFAULT_NAME("Default");

	INSTANCE_IMPLEMENT(FontManager)

	void FontManager::Initialise()
	{
		ASSERT(!mIsInitialise, INSTANCE_TYPE_NAME << " initialised twice");
		LOG(Info, "* Initialise: " << INSTANCE_TYPE_NAME);

		ResourceManager::GetInstance().RegisterLoadXmlDelegate(XML_TYPE) = NewDelegate(this, &FontManager::_load);

		FactoryManager::GetInstance().RegisterFactory<ResourceManualFont>(XML_TYPE_RESOURCE);
		FactoryManager::GetInstance().RegisterFactory<ResourceTrueTypeFont>(XML_TYPE_RESOURCE);

		mDefaultName = "Default";

		LOG(Info, INSTANCE_TYPE_NAME << " successfully initialized");
		mIsInitialise = true;
	}

	void FontManager::Shutdown()
	{
		if (!mIsInitialise) return;
		LOG(Info, "* Shutdown: " << INSTANCE_TYPE_NAME);

		GUI::ResourceManager::GetInstance().UnregisterLoadXmlDelegate(XML_TYPE);

		FactoryManager::GetInstance().UnregisterFactory<ResourceManualFont>(XML_TYPE_RESOURCE);
		FactoryManager::GetInstance().UnregisterFactory<ResourceTrueTypeFont>(XML_TYPE_RESOURCE);

		LOG(Info, INSTANCE_TYPE_NAME << " successfully shutdown");
		mIsInitialise = false;
	}

	bool FontManager::Load(const std::string& file)
	{
		return GUI::ResourceManager::GetInstance()._loadImplement(file, true, XML_TYPE, INSTANCE_TYPE_NAME);
	}

	void FontManager::_load(xml::ElementPtr node, const std::string& file, Version version)
	{
		xml::ElementEnumerator font = node->GetElementEnumerator();
		while (font.Next())
		{
			if (font->GetName() == XML_TYPE)
			{
				std::string name;
				if (!font->findAttribute("name", name)) continue;

				std::string type;
				if (type.empty())
				{
					if (font->findAttribute("resolution").empty()) type = "ResourceManualFont";
					else type = "ResourceTrueTypeFont";
				}

				xml::Document doc;
				xml::ElementPtr root = doc.CreateRoot("GUI");
				xml::ElementPtr curNode = root->CreateChild("Resource");
				curNode->AddAttribute("type", type);
				curNode->AddAttribute("name", name);

				std::string tmp;
				if (font->findAttribute("source", tmp))
				{
					xml::ElementPtr prop = curNode->CreateChild("Property");
					prop->AddAttribute("key", "Source");
					prop->AddAttribute("value", tmp);
				}

				if (font->findAttribute("size", tmp))
				{
					xml::ElementPtr prop = curNode->CreateChild("Property");
					prop->AddAttribute("key", "Size");
					prop->AddAttribute("value", tmp);
				}

				if (font->findAttribute("resolution", tmp))
				{
					xml::ElementPtr prop = curNode->CreateChild("Property");
					prop->AddAttribute("key", "Resolution");
					prop->AddAttribute("value", tmp);
				}

				if (font->findAttribute("antialias_colour", tmp))
				{
					xml::ElementPtr prop = curNode->CreateChild("Property");
					prop->AddAttribute("key", "Antialias");
					prop->AddAttribute("value", tmp);
				}

				if (font->findAttribute("space_width", tmp))
				{
					xml::ElementPtr prop = curNode->CreateChild("Property");
					prop->AddAttribute("key", "SpaceWidth");
					prop->AddAttribute("value", tmp);
				}

				if (font->findAttribute("tab_width", tmp))
				{
					xml::ElementPtr prop = curNode->CreateChild("Property");
					prop->AddAttribute("key", "TabWidth");
					prop->AddAttribute("value", tmp);
				}

				if (font->findAttribute("cursor_width", tmp))
				{
					xml::ElementPtr prop = curNode->CreateChild("Property");
					prop->AddAttribute("key", "CursorWidth");
					prop->AddAttribute("value", tmp);
				}

				if (font->findAttribute("distance", tmp))
				{
					xml::ElementPtr prop = curNode->CreateChild("Property");
					prop->AddAttribute("key", "Distance");
					prop->AddAttribute("value", tmp);
				}

				if (font->findAttribute("offset_height", tmp))
				{
					xml::ElementPtr prop = curNode->CreateChild("Property");
					prop->AddAttribute("key", "OffsetHeight");
					prop->AddAttribute("value", tmp);
				}

				if (font->findAttribute("default_height", tmp))
				{
					xml::ElementPtr prop = curNode->CreateChild("Property");
					prop->AddAttribute("key", "DefaultHeight");
					prop->AddAttribute("value", tmp);
				}

				xml::ElementPtr codes = curNode->CreateChild("Codes");

				xml::ElementEnumerator codeold = font->GetElementEnumerator();
				while (codeold.Next("Code"))
				{
					xml::ElementPtr codenew = codes->CreateChild("Code");

					if (codeold->findAttribute("range", tmp))
						codenew->AddAttribute("range", tmp);

					if (codeold->findAttribute("hide", tmp))
						codenew->AddAttribute("hide", tmp);

					if (codeold->findAttribute("index", tmp))
						codenew->AddAttribute("index", tmp);

					if (codeold->findAttribute("coord", tmp))
						codenew->AddAttribute("coord", tmp);
				}

				ResourceManager::GetInstance()._load(root, file, version);
			}
			else if (font->GetName() == XML_TYPE_PROPERTY)
			{
				const std::string& key = font->findAttribute("key");
				const std::string& value = font->findAttribute("value");
				if (key == "Default")
					mDefaultName = value;
			}
		}
	}

	void FontManager::SetDefaultFont(const std::string& value)
	{
		mDefaultName = value;
	}

	IFont* FontManager::GetByName(const std::string& name) const
	{
		IResource* result = nullptr;
		//FIXME
		if (!name.empty() && name != RESOURCE_DEFAULT_NAME)
			result = ResourceManager::GetInstance().GetByName(name, false);

		if (result == nullptr)
			result = ResourceManager::GetInstance().GetByName(mDefaultName, false);

		return result ? result->CastType<IFont>(false) : nullptr;
	}

} // namespace GUI
