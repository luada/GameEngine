#include "Precompiled.h"
#include "ResourceManager.h"
#include "LayoutManager.h"
#include "SkinManager.h"
#include "WidgetManager.h"
#include "Widget.h"
#include "CoordConverter.h"
#include "ControllerManager.h"

namespace GUI
{

	const std::string XML_TYPE("Layout");

	INSTANCE_IMPLEMENT(LayoutManager)

	void LayoutManager::Initialise()
	{
		ASSERT(!mIsInitialise, INSTANCE_TYPE_NAME << " initialised twice");
		LOG(Info, "* Initialise: " << INSTANCE_TYPE_NAME);

		ResourceManager::GetInstance().RegisterLoadXmlDelegate(XML_TYPE) = NewDelegate(this, &LayoutManager::_load);
		layoutPrefix = "";
		layoutParent = nullptr;

		LOG(Info, INSTANCE_TYPE_NAME << " successfully initialized");
		mIsInitialise = true;
	}

	void LayoutManager::Shutdown()
	{
		if (!mIsInitialise) return;
		LOG(Info, "* Shutdown: " << INSTANCE_TYPE_NAME);

		ResourceManager::GetInstance().UnregisterLoadXmlDelegate(XML_TYPE);

		LOG(Info, INSTANCE_TYPE_NAME << " successfully shutdown");
		mIsInitialise = false;
	}

	VectorWidgetPtr& LayoutManager::Load(const std::string& file)
	{
		mVectorWidgetPtr.clear();
		ResourceManager::GetInstance()._loadImplement(file, true, XML_TYPE, INSTANCE_TYPE_NAME);
		return mVectorWidgetPtr;
	}

	void LayoutManager::_load(xml::ElementPtr node, const std::string& file, Version version)
	{
#if DEBUG_MODE == 1
		LOG(Info, "load layout '" << file << "'");
#endif
		ParseLayout(mVectorWidgetPtr, node);
	}

	VectorWidgetPtr& LayoutManager::LoadLayout(const std::string& file, const std::string& prefix, Widget* parent)
	{
		static VectorWidgetPtr widgets;
		widgets.clear();

		layoutPrefix = prefix;
		layoutParent = parent;
		widgets = Load(file);
		layoutPrefix = "";
		layoutParent = nullptr;
		return widgets;
	}

	void LayoutManager::UnloadLayout(VectorWidgetPtr& widgets)
	{
		WidgetManager::GetInstance().DestroyWidgets(widgets);
	}

	Widget* LayoutManager::FindWidget(VectorWidgetPtr& widgets, const std::string name)
	{
		for (VectorWidgetPtr::iterator iter = widgets.begin(), endIt = widgets.end(); iter != endIt; ++iter)
		{
			Widget* find = (*iter)->FindWidget(name);
			if (find != nullptr)
			{
				return find;
			}
		}
		return nullptr;
	}

	void LayoutManager::ParseLayout(VectorWidgetPtr& widgets, xml::ElementPtr root)
	{
		xml::ElementEnumerator widget = root->GetElementEnumerator();
		while (widget.Next("Widget")) 
		{
			ParseWidget(widgets, widget, layoutParent);
		}
	}

	void LayoutManager::ParseWidget(VectorWidgetPtr& widgets, xml::ElementEnumerator& widget, Widget* parent)
	{
		std::string widgetType, widgetSkin, widgetName, widgetLayer, tmp;

		widget->findAttribute("type", widgetType);
		widget->findAttribute("skin", widgetSkin);
		widget->findAttribute("layer", widgetLayer);

		Align align = Align::Default;
		if (widget->findAttribute("align", tmp)) align = Align::Parse(tmp);

		widget->findAttribute("name", widgetName);
		if (!widgetName.empty()) widgetName = layoutPrefix + widgetName;

		WidgetStyle style = WidgetStyle::Child;
		if (widget->findAttribute("style", tmp)) style = WidgetStyle::Parse(tmp);
		if (parent != nullptr && style != WidgetStyle::Popup) widgetLayer.clear();

		IntCoord coord;
		if (widget->findAttribute("position", tmp)) coord = IntCoord::Parse(tmp);
		else if (widget->findAttribute("position_real", tmp))
		{
			if (parent == nullptr || style == WidgetStyle::Popup)
				coord = CoordConverter::ConvertFromRelative(FloatCoord::Parse(tmp), Gui::GetInstance().GetViewSize());
			else
				coord = CoordConverter::ConvertFromRelative(FloatCoord::Parse(tmp), parent->GetSize());
		}

		Widget* wid;
		if (nullptr == parent)
			wid = Gui::GetInstance().CreateWidgetT(widgetType, widgetSkin, coord, align, widgetLayer, widgetName);
		else
			wid = parent->CreateWidgetT(style, widgetType, widgetSkin, coord, align, widgetLayer, widgetName);

		if (layoutParent == parent) widgets.push_back(wid);

		xml::ElementEnumerator node = widget->GetElementEnumerator();
		while (node.Next())
		{
			if (node->GetName() == "Widget")
			{
				ParseWidget(widgets, node, wid);
			}
			else if (node->GetName() == "Property")
			{
				wid->SetProperty(node->findAttribute("key"), node->findAttribute("value"));
			}
			else if (node->GetName() == "UserString")
			{
				wid->SetUserString(node->findAttribute("key"), node->findAttribute("value"));
			}
			else if (node->GetName() == "Controller")
			{
				const std::string& type = node->findAttribute("type");
				GUI::ControllerItem* item = GUI::ControllerManager::GetInstance().CreateItem(type);
				if (item)
				{
					xml::ElementEnumerator prop = node->GetElementEnumerator();
					while (prop.Next("Property"))
					{
						item->SetProperty(prop->findAttribute("key"), prop->findAttribute("value"));
					}
					GUI::ControllerManager::GetInstance().AddItem(wid, item);
				}
				else
				{
					//LOG
				}
			}

		}
		wid->OnLoaded();
	}

} // namespace GUI

