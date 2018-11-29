#include "Precompiled.h"
#include "ResourceManager.h"
#include "LayerManager.h"
#include "PointerManager.h"
#include "CoordConverter.h"
#include "WidgetManager.h"
#include "XmlDocument.h"
#include "Widget.h"
#include "FactoryManager.h"
#include "InputManager.h"
#include "Gui.h"

#include "ResourceManualPointer.h"
#include "ResourceImageSetPointer.h"

namespace GUI
{

	const std::string XML_TYPE("Pointer");
	const std::string XML_TYPE_RESOURCE("Resource");
	const std::string XML_TYPE_PROPERTY("Property");
	const std::string RESOURCE_DEFAULT_NAME("Default");

	INSTANCE_IMPLEMENT(PointerManager)

	void PointerManager::Initialise()
	{
		ASSERT(!mIsInitialise, INSTANCE_TYPE_NAME << " initialised twice");
		LOG(Info, "* Initialise: " << INSTANCE_TYPE_NAME);

		Gui::GetInstance().eventFrameStart += NewDelegate(this, &PointerManager::NotifyFrameStart);
		InputManager::GetInstance().eventChangeMouseFocus += NewDelegate(this, &PointerManager::NotifyChangeMouseFocus);
		WidgetManager::GetInstance().RegisterUnlinker(this);

		ResourceManager::GetInstance().RegisterLoadXmlDelegate(XML_TYPE) = NewDelegate(this, &PointerManager::_load);

		FactoryManager::GetInstance().RegisterFactory<ResourceManualPointer>(XML_TYPE_RESOURCE);
		FactoryManager::GetInstance().RegisterFactory<ResourceImageSetPointer>(XML_TYPE_RESOURCE);

		mPointer = nullptr;
		mMousePointer = nullptr;
		mWidgetOwner = nullptr;
		mVisible = true;

		mSkinName = "StaticImage";

		LOG(Info, INSTANCE_TYPE_NAME << " successfully initialized");
		mIsInitialise = true;
	}

	void PointerManager::Shutdown()
	{
		if (!mIsInitialise) return;
		LOG(Info, "* Shutdown: " << INSTANCE_TYPE_NAME);

		InputManager::GetInstance().eventChangeMouseFocus -= NewDelegate(this, &PointerManager::NotifyChangeMouseFocus);
		Gui::GetInstance().eventFrameStart -= NewDelegate(this, &PointerManager::NotifyFrameStart);

		FactoryManager::GetInstance().UnregisterFactory<ResourceManualPointer>(XML_TYPE_RESOURCE);
		FactoryManager::GetInstance().UnregisterFactory<ResourceImageSetPointer>(XML_TYPE_RESOURCE);

		_destroyAllChildWidget();

		mWidgetOwner = nullptr;

		WidgetManager::GetInstance().UnregisterUnlinker(this);
		ResourceManager::GetInstance().UnregisterLoadXmlDelegate(XML_TYPE);

		LOG(Info, INSTANCE_TYPE_NAME << " successfully shutdown");
		mIsInitialise = false;
	}

	bool PointerManager::Load(const std::string& file)
	{
		return ResourceManager::GetInstance()._loadImplement(file, true, XML_TYPE, INSTANCE_TYPE_NAME);
	}

	void PointerManager::_load(xml::ElementPtr node, const std::string& file, Version version)
	{
		std::string pointer;
		std::string layer;

		xml::ElementEnumerator curNode = node->GetElementEnumerator();
		while (curNode.Next())
		{
			if (curNode->GetName() == XML_TYPE)
			{
				layer = curNode->findAttribute("layer");
				pointer = curNode->findAttribute("default");

				std::string shared_text = curNode->findAttribute("texture");

				xml::ElementEnumerator info = curNode->GetElementEnumerator();
				while (info.Next("Info"))
				{
					std::string name = info->findAttribute("name");
					if (name.empty()) continue;

					std::string texture = info->findAttribute("texture");

					std::string type = (shared_text.empty() && texture.empty()) ? "ResourceImageSetPointer" : "ResourceManualPointer";

					xml::Document doc;
					xml::ElementPtr root = doc.CreateRoot("GUI");
					xml::ElementPtr newnode = root->CreateChild("Resource");
					newnode->AddAttribute("type", type);
					newnode->AddAttribute("name", name);

					std::string tmp;
					if (info->findAttribute("point", tmp))
					{
						xml::ElementPtr prop = newnode->CreateChild("Property");
						prop->AddAttribute("key", "Point");
						prop->AddAttribute("value", tmp);
					}

					if (info->findAttribute("size", tmp))
					{
						xml::ElementPtr prop = newnode->CreateChild("Property");
						prop->AddAttribute("key", "Size");
						prop->AddAttribute("value", tmp);
					}

					if (info->findAttribute("resource", tmp))
					{
						xml::ElementPtr prop = newnode->CreateChild("Property");
						prop->AddAttribute("key", "Resource");
						prop->AddAttribute("value", tmp);
					}

					if (info->findAttribute("offset", tmp))
					{
						xml::ElementPtr prop = newnode->CreateChild("Property");
						prop->AddAttribute("key", "Coord");
						prop->AddAttribute("value", tmp);
					}

					if (!shared_text.empty() || !texture.empty())
					{
						xml::ElementPtr prop = newnode->CreateChild("Property");
						prop->AddAttribute("key", "Texture");
						prop->AddAttribute("value",  shared_text.empty() ? texture : shared_text);
					}

					ResourceManager::GetInstance()._load(root, file, version);
				}

			}
			else if (curNode->GetName() == XML_TYPE_PROPERTY)
			{
				const std::string& key = curNode->findAttribute("key");
				const std::string& value = curNode->findAttribute("value");
				if (key == "Default")
					SetDeafultPointer(value);
				else if (key == "Layer")
					SetLayerName(value);
				else if (key == "Skin")
					mSkinName = value;
			}
		}

		if (!layer.empty())
			SetLayerName(layer);

		if (!pointer.empty())
			SetDeafultPointer(pointer);

	}

	void PointerManager::NotifyFrameStart(float time)
	{
		mPoint = InputManager::GetInstance().GetMousePosition();
		if (nullptr != mMousePointer && mPointer != nullptr)
			mPointer->SetPosition(mMousePointer, mPoint);
	}

	void PointerManager::SetVisible(bool visible)
	{
		if (nullptr != mMousePointer) mMousePointer->SetVisible(visible);
		mVisible = visible;
	}

	void PointerManager::SetPointer(const std::string& name, Widget* owner)
	{
		if (nullptr == mMousePointer)
			return;

		IResource* result = GetByName(name);
		if (result == nullptr)
		{
			mPointer = nullptr;
			mMousePointer->SetVisible(false);
			return;
		}

		mMousePointer->SetVisible(mVisible);
		mPointer = result->CastType<IPointer>();
		mPointer->SetImage(mMousePointer);
		mPointer->SetPosition(mMousePointer, mPoint);

		mWidgetOwner = owner;
	}

	void PointerManager::_unlinkWidget(Widget* widget)
	{
		if (widget == mWidgetOwner) SetPointer(mDefaultName, nullptr);
		else if (widget == mMousePointer) mMousePointer = nullptr;
	}

	void PointerManager::ResetToDefaultPointer()
	{
		SetPointer(mDefaultName, nullptr);
	}

	Widget* PointerManager::BaseCreateWidget(WidgetStyle style, const std::string& type, const std::string& skin, const IntCoord& coord, Align align, const std::string& layer, const std::string& name)
	{
		Widget* widget = WidgetManager::GetInstance().CreateWidget(style, type, skin, coord, align, nullptr, nullptr, this, name);
		mWidgetChild.push_back(widget);
		if (!layer.empty())
			LayerManager::GetInstance().AttachToLayerNode(layer, widget);
		return widget;
	}

	void PointerManager::_destroyChildWidget(Widget* widget)
	{
		ASSERT(nullptr != widget, "invalid curWidget pointer");

		VectorWidgetPtr::iterator iter = std::find(mWidgetChild.begin(), mWidgetChild.end(), widget);
		if (iter != mWidgetChild.end())
		{
			GUI::Widget* curWidget = *iter;

			*iter = mWidgetChild.back();
			mWidgetChild.pop_back();

			WidgetManager::GetInstance().UnlinkFromUnlinkers(widget);

			_deleteWidget(curWidget);
		}
		else
		{
			EXCEPT("Widget '" << widget->GetName() << "' not found");
		}
	}

	void PointerManager::_destroyAllChildWidget()
	{
		WidgetManager& manager = WidgetManager::GetInstance();
		while (!mWidgetChild.empty())
		{
			Widget* widget = mWidgetChild.back();
			mWidgetChild.pop_back();

			manager.UnlinkFromUnlinkers(widget);

			_deleteWidget(widget);
		}
	}

	void PointerManager::SetDeafultPointer(const std::string& value)
	{
		Update();

		mDefaultName = value;
		SetPointer(mDefaultName, nullptr);
	}

	void PointerManager::SetLayerName(const std::string& value)
	{
		Update();

		mLayerName = value;
		if (LayerManager::GetInstance().IsExist(value))
			LayerManager::GetInstance().AttachToLayerNode(mLayerName, mMousePointer);
	}

	void PointerManager::Update()
	{
		if (mMousePointer == nullptr)
			mMousePointer = static_cast<StaticImage*>(BaseCreateWidget(WidgetStyle::Overlapped, StaticImage::GetClassTypeName(), mSkinName, IntCoord(), Align::Default, "", ""));
	}

	IPointer* PointerManager::GetByName(const std::string& name) const
	{
		IResource* result = nullptr;
		if (!name.empty() && name != RESOURCE_DEFAULT_NAME)
			result = ResourceManager::GetInstance().GetByName(name, false);

		if (result == nullptr)
			result = ResourceManager::GetInstance().GetByName(mDefaultName, false);

		return result ? result->CastType<IPointer>(false) : nullptr;
	}

	void PointerManager::NotifyChangeMouseFocus(Widget* widget)
	{
		std::string pointer = widget == nullptr ? "" : widget->GetPointer();
		if (pointer != mCurrentMousePointer)
		{
			mCurrentMousePointer = pointer;
			if (mCurrentMousePointer.empty())
			{
				ResetToDefaultPointer();
				eventChangeMousePointer(mDefaultName);
			}
			else
			{
				SetPointer(mCurrentMousePointer, widget);
				eventChangeMousePointer(mCurrentMousePointer);
			}
		}
	}

	void PointerManager::SetPointer(const std::string& name)
	{
		SetPointer(name, nullptr);
	}

} // namespace GUI

