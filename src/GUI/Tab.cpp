#include "Precompiled.h"
#include "Tab.h"
#include "ControllerManager.h"
#include "WidgetManager.h"
#include "Button.h"
#include "TabItem.h"
#include "ResourceSkin.h"

namespace GUI
{

	const float TAB_SPEED_FADE_COEF = 5.0f;

	Tab::Tab() :
		mOffsetTab(0),
		mButtonShow(false),
		mWidthBar(0),
		mWidgetBar(nullptr),
		mButtonLeft(nullptr),
		mButtonRight(nullptr),
		mButtonList(nullptr),
		mButtonDecor(nullptr),
		mEmptyBarWidget(nullptr),
		mItemTemplate(nullptr),
		mStartIndex(0),
		mIndexSelect(ITEM_NONE),
		mButtonDefaultWidth(1),
		mSmoothShow(true),
		mButtonAutoWidth(true),
		mShutdown(false)
	{
	}

	void Tab::_initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name)
	{
		Base::_initialise(style, coord, align, info, parent, croppedParent, creator, name);

		InitialiseWidgetSkin(info);
	}

	Tab::~Tab()
	{
		mShutdown = true;
		ShutdownWidgetSkin();
	}

	void Tab::BaseChangeWidgetSkin(ResourceSkin* info)
	{
		ShutdownWidgetSkin();
		Base::BaseChangeWidgetSkin(info);
		InitialiseWidgetSkin(info);
	}

	void Tab::InitialiseWidgetSkin(ResourceSkin* info)
	{
		const MapString& properties = info->GetProperties();
		if (!properties.empty())
		{
			MapString::const_iterator iter = properties.find("OffsetBar");
			if (iter != properties.end()) mOffsetTab = utility::ParseInt(iter->second);

			iter = properties.find("ButtonSkin");
			if (iter != properties.end()) mButtonSkinName = iter->second;
			iter = properties.find("EmptyBarSkin");
			if (iter != properties.end()) mEmptySkinName = iter->second;
		}

		for (VectorWidgetPtr::iterator iter=mWidgetChildSkin.begin(); iter!=mWidgetChildSkin.end(); ++iter)
		{
			if (*(*iter)->_getInternalData<std::string>() == "Bar")
			{
				DEBUG_ASSERT( ! mWidgetBar, "widget already assigned");
				mWidgetBar = (*iter);
			}
			else if (*(*iter)->_getInternalData<std::string>() == "Left")
			{
				DEBUG_ASSERT( ! mButtonLeft, "widget already assigned");
				mButtonLeft = (*iter)->CastType<Button>();
				mButtonLeft->SetVisible(false);
				mButtonLeft->eventMouseButtonClick = NewDelegate(this, &Tab::NotifyPressedButtonEvent);
			} 
			else if (*(*iter)->_getInternalData<std::string>() == "Right")
			{
				DEBUG_ASSERT( ! mButtonRight, "widget already assigned");
				mButtonRight = (*iter)->CastType<Button>();
				mButtonRight->SetVisible(false);
				mButtonRight->eventMouseButtonClick = NewDelegate(this, &Tab::NotifyPressedButtonEvent);
			}
			else if (*(*iter)->_getInternalData<std::string>() == "List")
			{
				DEBUG_ASSERT( ! mButtonList, "widget already assigned");
				mButtonList = (*iter)->CastType<Button>();
				mButtonList->SetVisible(false);
				mButtonList->eventMouseButtonClick = NewDelegate(this, &Tab::NotifyPressedButtonEvent);
			}
			else if (*(*iter)->_getInternalData<std::string>() == "ButtonDecor")
			{
				DEBUG_ASSERT( ! mButtonDecor, "widget already assigned");
				mButtonDecor = *iter;
				mButtonDecor->SetVisible(false);
			}
			else if (*(*iter)->_getInternalData<std::string>() == "ShowPatch")
			{
				mWidgetsPatch.push_back((*iter));
				(*iter)->SetVisible(false);
			}
			else if ((*(*iter)->_getInternalData<std::string>() == "Sheet") || (*(*iter)->_getInternalData<std::string>() == "TabItem"))
			{
				DEBUG_ASSERT( ! mItemTemplate, "widget already assigned");
				mItemTemplate = (*iter);
				mItemTemplate->SetVisible(false);
			}
		}
		//ASSERT(nullptr != mWidgetBar, "Child Widget Bar not found in Skin (Tab must have Bar)");
		//ASSERT(nullptr != mItemTemplate, "Child Widget TabItem not found in Skin (Tab must have TabItem (Sheet) )");

		mEmptyBarWidget = _getWidgetBar()->CreateWidget<Widget>(mEmptySkinName, IntCoord(), Align::Left | Align::Top);

		UpdateBar();
	}

	void Tab::ShutdownWidgetSkin()
	{
		mWidgetsPatch.clear();
		mWidgetBar = nullptr;
		mButtonLeft = nullptr;
		mButtonRight = nullptr;
		mButtonList = nullptr;
		mButtonDecor = nullptr;
		mItemTemplate = nullptr;
		mEmptyBarWidget = nullptr;
	}


	Widget* Tab::BaseCreateWidget(WidgetStyle style, const std::string& type, const std::string& skin, const IntCoord& coord, Align align, const std::string& layer, const std::string& name)
	{
		if ((TabItem::GetClassTypeName() == type) || ("Sheet" == type))
		{
			TabItem* sheet = static_cast<TabItem*>(Base::BaseCreateWidget(style, TabItem::GetClassTypeName(), "Default", _getWidgetTemplate()->GetCoord(), _getWidgetTemplate()->GetAlign(), "", name));
			_insertItem(ITEM_NONE, name, sheet, Any::Null);

			return sheet;
		}
		return Base::BaseCreateWidget(style, type, skin, coord, align, layer, name);
	}

	TabItem* Tab::InsertItemAt(size_t index, const UString& name, Any data)
	{
		ASSERT_RANGE_INSERT(index, mItemsInfo.size(), "Tab::insertItem");

		TabItem* sheet = static_cast<TabItem*>(Base::BaseCreateWidget(WidgetStyle::Child, TabItem::GetClassTypeName(), "Default", _getWidgetTemplate()->GetCoord(), _getWidgetTemplate()->GetAlign(), "", ""));
		_insertItem(index, name, sheet, data);

		return sheet;
	}

	void Tab::SetPosition(const IntPoint& point)
	{
		Base::SetPosition(point);

		UpdateBar();
	}

	void Tab::SetSize(const IntSize& size)
	{
		Base::SetSize(size);

		UpdateBar();
	}

	void Tab::SetCoord(const IntCoord& coord)
	{
		Base::SetCoord(coord);

		UpdateBar();
	}

	void Tab::UpdateBar()
	{
		if (_getWidgetBar()->GetWidth() < 1) return;

		if ((_getWidgetBar()->GetWidth() < mWidthBar) && (1 < mItemsInfo.size()))
		{
			if (!mButtonShow)
			{
				mButtonShow = true;
				if (nullptr != mButtonLeft) mButtonLeft->SetVisible(true);
				if (nullptr != mButtonRight) mButtonRight->SetVisible(true);
				if (nullptr != mButtonList) mButtonList->SetVisible(true);
				if (nullptr != mButtonDecor) mButtonDecor->SetVisible(true);
				for (VectorWidgetPtr::iterator iter=mWidgetsPatch.begin(); iter!=mWidgetsPatch.end(); ++iter) (*iter)->SetVisible(true);
				if (mWidgetBar != nullptr)
					mWidgetBar->SetSize(mWidgetBar->GetWidth() - mOffsetTab, mWidgetBar->GetHeight());
			}
		}
		else
		{
			if (mButtonShow)
			{
				mButtonShow = false;
				if (nullptr != mButtonLeft) mButtonLeft->SetVisible(false);
				if (nullptr != mButtonRight) mButtonRight->SetVisible(false);
				if (nullptr != mButtonList) mButtonList->SetVisible(false);
				if (nullptr != mButtonDecor) mButtonDecor->SetVisible(false);
				for (VectorWidgetPtr::iterator iter=mWidgetsPatch.begin(); iter!=mWidgetsPatch.end(); ++iter) (*iter)->SetVisible(false);
				if (mWidgetBar != nullptr)
					mWidgetBar->SetSize(mWidgetBar->GetWidth() + mOffsetTab, mWidgetBar->GetHeight());
			}
		}

		if (mStartIndex > 0)
		{
			int width = 0;
			for (size_t pos=mStartIndex; pos<mItemsInfo.size(); pos++) width += mItemsInfo[pos].width;

			while ((mStartIndex > 0) && ((width + mItemsInfo[mStartIndex-1].width) <= _getWidgetBar()->GetWidth()))
			{
				mStartIndex--;
				width += mItemsInfo[mStartIndex].width;
			}
		}

		int width = 0;
		size_t count = 0;
		size_t pos=mStartIndex;
		for (; pos<mItemsInfo.size(); pos++)
		{
			if (width > _getWidgetBar()->GetWidth()) break;

			TabItemInfo& info = mItemsInfo[pos];
			if ((width + info.width) > _getWidgetBar()->GetWidth())
			{
				break;
			}

			if (count >= mItemButton.size()) _createItemButton();

			Button* button = mItemButton[count]->CastType<Button>();
			button->SetVisible(true);

			button->SetButtonPressed(pos == mIndexSelect);

			if (button->GetCaption() != info.name)
				button->SetCaption(info.name);
			IntCoord coord(width, 0, info.width, _getWidgetBar()->GetHeight());
			if (coord != button->GetCoord())
				button->SetCoord(coord);

			width += info.width;
			count ++;
		}

		while (count < mItemButton.size())
		{
			mItemButton[count]->SetVisible(false);
			count ++;
		}

		bool right = true;
		if (pos == mItemsInfo.size()) right = false;

		if (width < _getWidgetBar()->GetWidth())
		{
			mEmptyBarWidget->SetVisible(true);
			mEmptyBarWidget->SetCoord(width, 0, _getWidgetBar()->GetWidth() - width, _getWidgetBar()->GetHeight());
		}
		else
		{
			mEmptyBarWidget->SetVisible(false);
		}

		if (mStartIndex == 0)
		{
			if (nullptr != mButtonLeft) mButtonLeft->SetEnabled(false);
		}
		else
		{
			if (nullptr != mButtonLeft) mButtonLeft->SetEnabled(true);
		}

		if (right)
		{
			if (nullptr != mButtonRight) mButtonRight->SetEnabled(true);
		}
		else
		{
			if (nullptr != mButtonRight) mButtonRight->SetEnabled(false);
		}

	}

	void Tab::NotifyPressedButtonEvent(GUI::Widget* sender)
	{
		if (sender == mButtonLeft)
		{
			if (mStartIndex > 0)
			{
				mStartIndex --;
				UpdateBar();
			}
		}
		else if (sender == mButtonRight)
		{
			if ((mStartIndex+1) < mItemsInfo.size())
			{
				mStartIndex ++;
				UpdateBar();
			}
		}
		else if (sender == mButtonList)
		{
		}
	}

	void Tab::NotifyPressedBarButtonEvent(GUI::Widget* sender)
	{
		size_t select = *sender->_getInternalData<size_t>() + mStartIndex;
		if (select == mIndexSelect)
		{
			BeginToItemSelected();
			return;
		}
		size_t old = mIndexSelect;
		mIndexSelect = select;

		size_t count = 0;
		for (size_t pos=0; pos<mItemButton.size(); pos++)
		{
			Button* button = mItemButton[count]->CastType<Button>();
			if (button->IsVisible())
			{
				button->SetButtonPressed((pos + mStartIndex) == mIndexSelect);
			}
			count ++;
		}

		BeginToItemSelected();

		_forcePeek(mItemsInfo[mIndexSelect].item);

		_showItem(mItemsInfo[mIndexSelect].item, true, mSmoothShow);
		_showItem(mItemsInfo[old].item, false, mSmoothShow);

		eventTabChangeSelect(this, mIndexSelect);
	}

	void Tab::BeginToItemAt(size_t index)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "Tab::beginToItemAt");

		if (_getWidgetBar()->GetWidth() < 1) return;

		if (index == mStartIndex) return;
		else if (index < mStartIndex)
		{
			mStartIndex = index;
			UpdateBar();
		}
		else
		{
			int width = 0;
			for (size_t pos=mStartIndex; pos<=index; pos++)
			{
				width += mItemsInfo[pos].width;
			}

			bool change = false;
			while ((mStartIndex < index) && (width > _getWidgetBar()->GetWidth()))
			{
				width -= mItemsInfo[mStartIndex].width;
				mStartIndex ++;
				change = true;
			}
			if (change) UpdateBar();

		}
	}

	void Tab::SetButtonDefaultWidth(int width)
	{
		mButtonDefaultWidth = width;
		if (mButtonDefaultWidth < 1) mButtonDefaultWidth = 1;
		SetButtonAutoWidth(false);
	}

	void Tab::SetButtonAutoWidth(bool value)
	{
		mButtonAutoWidth = value;

		for (size_t pos=0; pos<mItemsInfo.size(); pos++)
		{
			int width;
			if (mButtonAutoWidth) width = _getTextWidth(mItemsInfo[pos].name);
			else width = mButtonDefaultWidth;

			mWidthBar += width - mItemsInfo[pos].width;
			mItemsInfo[pos].width = width;
		}

		UpdateBar();
	}

	void Tab::SetButtonWidthAt(size_t index, int width)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "Tab::setButtonWidthAt");

		if (width <= 0)
		{
			if (mButtonAutoWidth) width = _getTextWidth(mItemsInfo[index].name);
			else width = mButtonDefaultWidth;
		}

		mWidthBar += width - mItemsInfo[index].width;
		mItemsInfo[index].width = width;

		UpdateBar();
	}

	void Tab::SetItemNameAt(size_t index, const UString& name)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "Tab::setItemNameAt");
		mItemsInfo[index].name = name;

		int width;
		if (mButtonAutoWidth) width = _getTextWidth(name);
		else width = mButtonDefaultWidth;

		mWidthBar += width - mItemsInfo[index].width;
		mItemsInfo[index].width = width;

		UpdateBar();
	}

	void Tab::SetIndexSelected(size_t index)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "Tab::setIndexSelected");
		if (mIndexSelect == index) return;
		size_t old = mIndexSelect;
		mIndexSelect = index;
		UpdateBar();

		if (mSmoothShow) _forcePeek(mItemsInfo[mIndexSelect].item);

		_showItem(mItemsInfo[mIndexSelect].item, true, mSmoothShow);
		_showItem(mItemsInfo[old].item, false, mSmoothShow);

		BeginToItemSelected();
	}

	void Tab::ActionWidgetHide(Widget* widget)
	{
		widget->SetVisible(false);
		widget->SetEnabled(true);
	}

	void Tab::_showItem(TabItem* item, bool show, bool smooth)
	{
		if (!smooth)
		{
			ControllerManager::GetInstance().RemoveItem(item);
			item->SetAlpha(ALPHA_MAX);

			item->SetVisible(show);

			return;
		}

		if (show)
		{
			ControllerFadeAlpha* controller = CreateControllerFadeAlpha(ALPHA_MAX, TAB_SPEED_FADE_COEF, true);
			ControllerManager::GetInstance().AddItem(item, controller);
		}
		else
		{
			ControllerFadeAlpha* controller = CreateControllerFadeAlpha(ALPHA_MIN, TAB_SPEED_FADE_COEF, false);
			controller->eventPostAction = NewDelegate(this, &Tab::ActionWidgetHide);
			ControllerManager::GetInstance().AddItem(item, controller);
		}
	}

	void Tab::_createItemButton()
	{
		Button* button = _getWidgetBar()->CreateWidget<Button>(mButtonSkinName, IntCoord(), Align::Left | Align::Top);
		button->eventMouseButtonClick = NewDelegate(this, &Tab::NotifyPressedBarButtonEvent);
		button->_setInternalData(mItemButton.size()); 
		mItemButton.push_back(button);
	}

	int Tab::_getTextWidth(const UString& text)
	{
		if (0 == mItemButton.size()) _createItemButton();

		UString save = mItemButton[0]->GetCaption();
		mItemButton[0]->SetCaption(text);

		ISubWidgetText* curText = mItemButton[0]->GetSubWidgetText();
		const IntSize& size = curText ? curText->GetTextSize() : IntSize();
		const IntCoord& coord = curText ? curText->GetCoord() : IntCoord();

		mItemButton[0]->SetCaption(save);

		return size.width + mItemButton[0]->GetWidth() - coord.width;
	}

	void Tab::_notifyDeleteItem(TabItem* sheet)
	{
		if (mShutdown) return;

		size_t index = GetItemIndex(sheet);

		mWidthBar -= mItemsInfo[index].width;
		mItemsInfo.erase(mItemsInfo.begin() + index);

		if (0 == mItemsInfo.size()) mIndexSelect = ITEM_NONE;
		else
		{
			if (index < mIndexSelect) mIndexSelect --;
			else if (index == mIndexSelect)
			{
				if (mIndexSelect == mItemsInfo.size()) mIndexSelect --;
				mItemsInfo[mIndexSelect].item->SetVisible(true);
				mItemsInfo[mIndexSelect].item->SetAlpha(ALPHA_MAX);
			}
		}

		UpdateBar();
	}

	void Tab::_insertItem(size_t index, const UString& name, TabItem* sheet, Any data)
	{
		if (index == ITEM_NONE) index = mItemsInfo.size();

		int width = (mButtonAutoWidth ? _getTextWidth(name) : mButtonDefaultWidth);
		mWidthBar += width;

		mItemsInfo.insert(mItemsInfo.begin() + index, TabItemInfo(width, name, sheet, data));

		if (1 == mItemsInfo.size()) mIndexSelect = 0;
		else
		{
			sheet->SetVisible(false);
			if (index <= mIndexSelect) mIndexSelect ++;
		}

		UpdateBar();
	}

	void Tab::SetItemDataAt(size_t index, Any data)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "Tab::setItemDataAt");
		mItemsInfo[index].data = data;
	}

	int Tab::GetButtonWidthAt(size_t index)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "Tab::getButtonWidthAt");
		return mItemsInfo[index].width;
	}

	const UString& Tab::GetItemNameAt(size_t index)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "Tab::getItemNameAt");
		return mItemsInfo[index].name;
	}

	TabItem* Tab::GetItemAt(size_t index)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "Tab::getItemAt");
		return mItemsInfo[index].item;
	}

	void Tab::RemoveItemAt(size_t index)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "Tab::removeItemAt");
		this->_destroyChildWidget(mItemsInfo[index].item);
	}

	void Tab::RemoveAllItems()
	{
		while (mItemsInfo.size() > 0)
		{
			this->_destroyChildWidget(mItemsInfo.back().item);
		}
	}

	ControllerFadeAlpha* Tab::CreateControllerFadeAlpha(float alpha, float coef, bool enable)
	{
		ControllerItem* item = ControllerManager::GetInstance().CreateItem(ControllerFadeAlpha::GetClassTypeName());
		ControllerFadeAlpha* controller = item->CastType<ControllerFadeAlpha>();

		controller->SetAlpha(alpha);
		controller->SetCoef(coef);
		controller->SetEnabled(enable);

		return controller;
	}

	size_t Tab::GetItemIndex(TabItem* item)
	{
		for (size_t pos=0; pos<mItemsInfo.size(); pos++)
		{
			if (mItemsInfo[pos].item == item) return pos;
		}
		EXCEPT("item (" << item << ") not found, source 'Tab::GetItemIndex'");
	}

	size_t Tab::FindItemIndex(TabItem* item)
	{
		for (size_t pos=0; pos<mItemsInfo.size(); pos++)
		{
			if (mItemsInfo[pos].item == item) return pos;
		}
		return ITEM_NONE;
	}

	size_t Tab::FindItemIndexWith(const UString& name)
	{
		for (size_t pos=0; pos<mItemsInfo.size(); pos++)
		{
			if (mItemsInfo[pos].name == name) return pos;
		}
		return ITEM_NONE;
	}

	TabItem* Tab::FindItemWith(const UString& name)
	{
		for (size_t pos=0; pos<mItemsInfo.size(); pos++)
		{
			if (mItemsInfo[pos].name == name) return mItemsInfo[pos].item;
		}
		return nullptr;
	}

	TabItem* Tab::GetItemSelected()
	{
		return GetIndexSelected() != ITEM_NONE ? GetItemAt(GetIndexSelected()) : nullptr;
	}

	void Tab::SetProperty(const std::string& key, const std::string& value)
	{
		if (key == "Tab_ButtonWidth") SetButtonDefaultWidth(utility::ParseValue<int>(value));
		else if (key == "Tab_ButtonAutoWidth") SetButtonAutoWidth(utility::ParseValue<bool>(value));
		else if (key == "Tab_SmoothShow") SetSmoothShow(utility::ParseValue<bool>(value));
		else if (key == "Tab_AddItem") AddItem(value);
		else if (key == "Tab_SelectItem") SetIndexSelected(utility::ParseValue<size_t>(value));
		else
		{
			Base::SetProperty(key, value);
			return;
		}
		eventChangeProperty(this, key, value);
	}

	Widget* Tab::_getWidgetTemplate()
	{
		return mItemTemplate == nullptr ? this : mItemTemplate;
	}

	Widget* Tab::_getWidgetBar()
	{
		return mWidgetBar == nullptr ? this : mWidgetBar;
	}

} // namespace GUI


