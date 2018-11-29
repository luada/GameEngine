#include "Precompiled.h"
#include "ComboBox.h"
#include "ControllerManager.h"
#include "InputManager.h"
#include "WidgetManager.h"
#include "Gui.h"
#include "List.h"
#include "Button.h"
#include "ResourceSkin.h"
#include "LayerManager.h"

namespace GUI
{

	const float COMBO_ALPHA_MAX  = ALPHA_MAX;
	const float COMBO_ALPHA_MIN  = ALPHA_MIN;
	const float COMBO_ALPHA_COEF = 4.0f;

	ComboBox::ComboBox() :
		mButton(nullptr),
		mList(nullptr),
		mListShow(false),
		mMaxHeight(0),
		mItemIndex(ITEM_NONE),
		mModeDrop(false),
		mDropMouse(false),
		mShowSmooth(false),
		mManualList(true)
	{
	}

	void ComboBox::_initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name)
	{
		Base::_initialise(style, coord, align, info, parent, croppedParent, creator, name);

		InitialiseWidgetSkin(info);
	}

	ComboBox::~ComboBox()
	{
		ShutdownWidgetSkin();
	}

	void ComboBox::BaseChangeWidgetSkin(ResourceSkin* info)
	{
		ShutdownWidgetSkin();
		Base::BaseChangeWidgetSkin(info);
		InitialiseWidgetSkin(info);
	}

	void ComboBox::InitialiseWidgetSkin(ResourceSkin* info)
	{
		const MapString& properties = info->GetProperties();
		if (!properties.empty())
		{
			MapString::const_iterator iter = properties.find("HeightList");
			if (iter != properties.end()) mMaxHeight = utility::ParseValue<int>(iter->second);

			iter = properties.find("ListSmoothShow");
			if (iter != properties.end()) SetSmoothShow(utility::ParseBool(iter->second));
		}

		for (VectorWidgetPtr::iterator iter=mWidgetChildSkin.begin(); iter!=mWidgetChildSkin.end(); ++iter)
		{
			if (*(*iter)->_getInternalData<std::string>() == "Button")
			{
				DEBUG_ASSERT( ! mButton, "widget already assigned");
				mButton = (*iter)->CastType<Button>();
				mButton->eventMouseButtonPressed = NewDelegate(this, &ComboBox::NotifyButtonPressed);
			}
			else if (*(*iter)->_getInternalData<std::string>() == "List")
			{
				DEBUG_ASSERT( ! mList, "widget already assigned");
				mList = (*iter)->CastType<List>();
				mList->SetVisible(false);
				mList->eventKeyLostFocus = NewDelegate(this, &ComboBox::NotifyListLostFocus);
				mList->eventListSelectAccept = NewDelegate(this, &ComboBox::NotifyListSelectAccept);
				mList->eventListMouseItemActivate = NewDelegate(this, &ComboBox::NotifyListMouseItemActivate);
				mList->eventListChangePosition = NewDelegate(this, &ComboBox::NotifyListChangePosition);
			}
		}

		//OBSOLETE
		//ASSERT(nullptr != mButton, "Child Button not found in Skin (combobox must have Button)");

		//ASSERT(nullptr != mList, "Child List not found in Skin (combobox must have List)");
		mManualList = (mList == nullptr);
		if (mList == nullptr)
		{
			std::string list_skin;
			MapString::const_iterator iter = properties.find("ListSkin");
			if (iter != properties.end()) list_skin = iter->second;
			std::string list_layer;
			iter = properties.find("ListLayer");
			if (iter != properties.end()) list_layer = iter->second;
			mList = CreateWidget<GUI::List>(WidgetStyle::Popup, list_skin, IntCoord(), Align::Default, list_layer);
			mWidgetChild.pop_back();

			mList->SetVisible(false);
			mList->eventKeyLostFocus = NewDelegate(this, &ComboBox::NotifyListLostFocus);
			mList->eventListSelectAccept = NewDelegate(this, &ComboBox::NotifyListSelectAccept);
			mList->eventListMouseItemActivate = NewDelegate(this, &ComboBox::NotifyListMouseItemActivate);
			mList->eventListChangePosition = NewDelegate(this, &ComboBox::NotifyListChangePosition);
		}

		//if (mMaxHeight < mList->GetFontHeight()) mMaxHeight = mList->GetFontHeight();

		if (mWidgetClient != nullptr)
		{
			mWidgetClient->eventMouseWheel = NewDelegate(this, &ComboBox::NotifyMouseWheel);
			mWidgetClient->eventMouseButtonPressed = NewDelegate(this, &ComboBox::NotifyMousePressed);
		}

		eventEditTextChange = NewDelegate(this, &ComboBox::NotifyEditTextChange);
	}

	void ComboBox::ShutdownWidgetSkin()
	{
		if (mManualList)
		{
			mWidgetChild.push_back(mList);
			WidgetManager::GetInstance().DestroyWidget(mList);
		}
		mList = nullptr;
		mButton = nullptr;
	}


	void ComboBox::NotifyButtonPressed(Widget* sender, int left, int top, MouseButton id)
	{
		if (MouseButton::Left != id) return;

		mDropMouse = true;

		if (mListShow) HideList();
		else ShowList();
	}

	void ComboBox::NotifyListLostFocus(Widget* sender, Widget* _new)
	{
		if (mDropMouse)
		{
			mDropMouse = false;
			Widget* focus = InputManager::GetInstance().GetMouseFocusWidget();
			if (focus == mButton) return;
			if ( (mModeDrop) && (focus == mWidgetClient) ) return;
		}

		HideList();
	}

	void ComboBox::NotifyListSelectAccept(List* widget, size_t position)
	{
		mItemIndex = position;
		Base::SetCaption(mItemIndex != ITEM_NONE ? mList->GetItemNameAt(mItemIndex) : "");

		mDropMouse = false;
		InputManager::GetInstance().SetKeyFocusWidget(this);

		if (mModeDrop)
		{
			eventComboAccept.m_eventObsolete(this);
			eventComboAccept.m_event(this, mItemIndex);
		}
	}

	void ComboBox::NotifyListChangePosition(List* widget, size_t position)
	{
		mItemIndex = position;
		eventComboChangePosition(this, position);
	}

	void ComboBox::OnKeyButtonPressed(KeyCode key, Char _char)
	{
		Base::OnKeyButtonPressed(key, _char);

		if (key == KeyCode::ArrowDown)
		{
			if (!InputManager::GetInstance().IsCaptureMouse())
			{
				ShowList();
			}
		}
		else if ((key == KeyCode::Return) || (key == KeyCode::NumpadEnter))
		{
			eventComboAccept.m_eventObsolete(this);
			eventComboAccept.m_event(this, mItemIndex);
		}

	}

	void ComboBox::NotifyListMouseItemActivate(List* widget, size_t position)
	{
		mItemIndex = position;
		Base::SetCaption(mItemIndex != ITEM_NONE ? mList->GetItemNameAt(mItemIndex) : "");

		InputManager::GetInstance().SetKeyFocusWidget(this);

		if (mModeDrop)
		{
			eventComboAccept.m_eventObsolete(this);
			eventComboAccept.m_event(this, mItemIndex);
		}
	}

	void ComboBox::NotifyMouseWheel(Widget* sender, int rel)
	{
		if (mList->GetItemCount() == 0) return;
		if (InputManager::GetInstance().GetKeyFocusWidget() != this) return;
		if (InputManager::GetInstance().IsCaptureMouse()) return;

		if (rel > 0)
		{
			if (mItemIndex != 0)
			{
				if (mItemIndex == ITEM_NONE) mItemIndex = 0;
				else mItemIndex --;
				Base::SetCaption(mList->GetItemNameAt(mItemIndex));
				mList->SetIndexSelected(mItemIndex);
				mList->BeginToItemAt(mItemIndex);
				eventComboChangePosition(this, mItemIndex);
			}
		}
		else if (rel < 0)
		{
			if ((mItemIndex+1) < mList->GetItemCount())
			{
				if (mItemIndex == ITEM_NONE) mItemIndex = 0;
				else mItemIndex ++;
				Base::SetCaption(mList->GetItemNameAt(mItemIndex));
				mList->SetIndexSelected(mItemIndex);
				mList->BeginToItemAt(mItemIndex);
				eventComboChangePosition(this, mItemIndex);
			}
		}
	}

	void ComboBox::NotifyMousePressed(Widget* sender, int left, int top, MouseButton id)
	{
		Base::NotifyMousePressed(sender, left, top, id);

		mDropMouse = true;

		if (mModeDrop) NotifyButtonPressed(nullptr, left, top, id);
	}

	void ComboBox::NotifyEditTextChange(Edit* sender)
	{
		if (ITEM_NONE != mItemIndex)
		{
			mItemIndex = ITEM_NONE;
			mList->SetIndexSelected(mItemIndex);
			mList->BeginToItemFirst();
			eventComboChangePosition(this, mItemIndex);
		}
	}

	void ComboBox::ShowList()
	{
		if (mList->GetItemCount() == 0) return;

		mListShow = true;

		int height = mList->GetOptimalHeight();
		if (height > mMaxHeight) height = mMaxHeight;

		IntCoord coord = this->GetAbsoluteCoord();

		if ((coord.top + coord.height + height) > Gui::GetInstance().GetViewSize().height)
		{
			coord.height = height;
			coord.top -= coord.height;
		}
		else
		{
			coord.top += coord.height;
			coord.height = height;
		}
		mList->SetCoord(coord);

		if (mShowSmooth)
		{
			ControllerFadeAlpha* controller = CreateControllerFadeAlpha(COMBO_ALPHA_MAX, COMBO_ALPHA_COEF, true);
			ControllerManager::GetInstance().AddItem(mList, controller);
		}
		else
		{
			mList->SetVisible(true);
		}

		InputManager::GetInstance().SetKeyFocusWidget(mList);
	}

	void ComboBox::ActionWidgetHide(Widget* widget)
	{
		widget->SetVisible(false);
		widget->SetEnabled(true);
	}

	void ComboBox::HideList()
	{
		mListShow = false;

		if (mShowSmooth)
		{
			ControllerFadeAlpha* controller = CreateControllerFadeAlpha(COMBO_ALPHA_MIN, COMBO_ALPHA_COEF, false);
			controller->eventPostAction = NewDelegate(this, &ComboBox::ActionWidgetHide);
			ControllerManager::GetInstance().AddItem(mList, controller);
		}
		else
		{
			mList->SetVisible(false);
		}
	}

	void ComboBox::SetIndexSelected(size_t index)
	{
		ASSERT_RANGE_AND_NONE(index, mList->GetItemCount(), "ComboBox::setIndexSelected");
		mItemIndex = index;
		mList->SetIndexSelected(index);
		if (index == ITEM_NONE)
		{
			Base::SetCaption("");
			return;
		}
		Base::SetCaption(mList->GetItemNameAt(index));
		Base::UpdateView(); // hook for update
	}

	void ComboBox::SetItemNameAt(size_t index, const UString& name)
	{
		mList->SetItemNameAt(index, name);
		mItemIndex = ITEM_NONE;//FIXME
		mList->SetIndexSelected(mItemIndex);//FIXME
	}

	void ComboBox::SetItemDataAt(size_t index, Any data)
	{
		mList->SetItemDataAt(index, data);
		mItemIndex = ITEM_NONE;//FIXME
		mList->SetIndexSelected(mItemIndex);//FIXME
	}

	void ComboBox::InsertItemAt(size_t index, const UString& item, Any data)
	{
		mList->InsertItemAt(index, item, data);
		mItemIndex = ITEM_NONE;//FIXME
		mList->SetIndexSelected(mItemIndex);//FIXME
	}

	void ComboBox::RemoveItemAt(size_t index)
	{
		mList->RemoveItemAt(index);
		mItemIndex = ITEM_NONE;//FIXME
		mList->ClearIndexSelected();//FIXME
	}

	void ComboBox::RemoveAllItems()
	{
		mItemIndex = ITEM_NONE;//FIXME
		mList->RemoveAllItems();//FIXME
	}

	void ComboBox::SetComboModeDrop(bool drop)
	{
		mModeDrop = drop;
		SetEditStatic(mModeDrop);
	}

	ControllerFadeAlpha* ComboBox::CreateControllerFadeAlpha(float alpha, float coef, bool enable)
	{
		ControllerItem* item = ControllerManager::GetInstance().CreateItem(ControllerFadeAlpha::GetClassTypeName());
		ControllerFadeAlpha* controller = item->CastType<ControllerFadeAlpha>();

		controller->SetAlpha(alpha);
		controller->SetCoef(coef);
		controller->SetEnabled(enable);

		return controller;
	}

	size_t ComboBox::FindItemIndexWith(const UString& name)
	{
		return mList->FindItemIndexWith(name);
	}

	void ComboBox::SetProperty(const std::string& key, const std::string& value)
	{
		if (key == "ComboBox_ModeDrop") SetComboModeDrop(utility::ParseValue<bool>(value));
		else if (key == "ComboBox_AddItem") AddItem(value);
		else
		{
			Base::SetProperty(key, value);
			return;
		}
		eventChangeProperty(this, key, value);
	}

} // namespace GUI

