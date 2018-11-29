#ifndef __COMBO_BOX_H__
#define __COMBO_BOX_H__

#include "Prerequest.h"
#include "Edit.h"
#include "List.h"
#include "Any.h"
#include "EventPair.h"
#include "ControllerFadeAlpha.h"

namespace GUI
{

	typedef delegates::CDelegate2<ComboBox*, size_t> EventHandle_ComboBoxPtrSizeT;

	class GUI_EXPORT ComboBox :
		public Edit
	{
		RTTI_DERIVED(ComboBox)
		DEFINE_GET_THIS(ComboBox, BASS(Edit, END))

	public:
		ComboBox();

		//------------------------------------------------------------------------------//

		//! Get number of items
		//@ExportToLua
		size_t GetItemCount() const { return mList->GetItemCount(); }

		//! Insert an item into a array at a specified position
		void InsertItemAt(size_t index, const UString& name, Any data = Any::Null);
		//@ExportToLua
		void InsertItem(size_t index, const UString& name, Widget* value = nullptr) { InsertItemAt(index, name, value); }

		//! Add an item to the end of a array
		void AddItem(const UString& name, Any data = Any::Null) { return InsertItemAt(ITEM_NONE, name, data); }
		//@ExportToLua
		void AppendItem(const UString& name, Widget* value = nullptr) { return InsertItemAt(ITEM_NONE, name, value); }

		//! Remove item at a specified position
		void RemoveItemAt(size_t index);
		//@ExportToLua
		void RemoveItem(size_t index) { RemoveItemAt(index); }

		//! Remove all items
		//@ExportToLua
		void RemoveAllItems();


		//! Search item, returns the position of the first occurrence in array or ITEM_NONE if item not found
		//@ExportToLua
		size_t FindItemIndexWith(const UString& name);


		//------------------------------------------------------------------------------//

		//! Get index of selected Item (ITEM_NONE if none selected)
		//@ExportToLua
		size_t GetIndexSelected() { return mItemIndex; }

		//! Select specified index
		//@ExportToLua
		void SetIndexSelected(size_t index);

		//! Clear item selection
		//@ExportToLua
		void ClearIndexSelected() { SetIndexSelected(ITEM_NONE); }


		//------------------------------------------------------------------------------//

		//! Replace an item data at a specified position
		void SetItemDataAt(size_t index, Any data);
		//@ExportToLua
		void SetItemData(size_t index, Widget* value) { SetItemDataAt(index, value); }

		//! Clear an item data at a specified position
		void ClearItemDataAt(size_t index) { SetItemDataAt(index, Any::Null); }
		//@ExportToLua
		void ClearItemData(size_t index) { SetItemDataAt(index, Any::Null); }

		//! Get item data from specified position
		template <typename ValueType>
		ValueType * GetItemDataAt(size_t index, bool _throw = true)
		{
			return mList->GetItemDataAt<ValueType>(index, _throw);
		}

		//@ExportToLua
		Widget* GetItemData(size_t index) { return mList->GetItemData(index); }


		//------------------------------------------------------------------------------//

		//! Replace an item name at a specified position
		void SetItemNameAt(size_t index, const UString& name);
		//@ExportToLua
		void SetItemName(size_t index, const UString& name) { SetItemNameAt(index, name); }

		//! Get item name from specified position
		const UString& GetItemNameAt(size_t index) { return mList->GetItemNameAt(index); }
		//@ExportToLua
		const UString& GetItemName(size_t index) { return mList->GetItemNameAt(index); }


		//------------------------------------------------------------------------------//

		//! Move all elements so specified becomes visible
		void BeginToItemAt(size_t index) { mList->BeginToItemAt(index); }
		//@ExportToLua
		void BeginToItem(size_t index) { mList->BeginToItemAt(index); }

		//! Move all elements so first becomes visible
		//@ExportToLua
		void BeginToItemFirst() { if (GetItemCount()) BeginToItemAt(0); }

		//! Move all elements so last becomes visible
		//@ExportToLua
		void BeginToItemLast() { if (GetItemCount()) BeginToItemAt(GetItemCount() - 1); }

		//! Move all elements so selected becomes visible
		//@ExportToLua
		void BeginToItemSelected() { if (GetIndexSelected() != ITEM_NONE) BeginToItemAt(GetIndexSelected()); }


		//------------------------------------------------------------------------------------//

		//! Set drop list Mode (text can not be edited)
		//@ExportToLua
		void SetComboModeDrop(bool value);
		//! Get drop list mode flag
		//@ExportToLua
		bool GetComboModeDrop() { return mModeDrop; }

		//! Set smooth show of list
		//@ExportToLua
		void SetSmoothShow(bool value) { mShowSmooth = value; }
		//! Get smooth show of list flag
		//@ExportToLua
		bool GetSmoothShow() { return mShowSmooth; }

		//! Get max list height
		//@ExportToLua
		void SetMaxListHeight(int value) { mMaxHeight = value; }
		//! Set max list height
		//@ExportToLua
		int GetMaxListHeight() { return mMaxHeight; }

		/** @copydoc Widget::SetProperty(const std::string& key, const std::string& value) */
		//@ExportToLua
		virtual void SetProperty(const std::string& key, const std::string& value);

	/*event:*/
		/** Event : Enter pressed in combo mode or item selected in drop.\n
			signature : void Method(GUI::ComboBox* sender, size_t index)
			@param _sender widget that called this event
			@param index item
		*/
		EventPair<EventHandle_WidgetVoid, EventHandle_ComboBoxPtrSizeT> eventComboAccept;

		/** Event : Position changed.\n
			signature : void Method(GUI::ComboBox* sender, size_t index)
			@param _sender widget that called this event
			@param index of new position
		*/
		EventPair<EventHandle_WidgetSizeT, EventHandle_ComboBoxPtrSizeT> eventComboChangePosition;


	/*internal:*/
		virtual void _initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name);


	protected:
		virtual ~ComboBox();

		virtual void OnKeyButtonPressed(KeyCode key, Char _char);

		virtual void BaseChangeWidgetSkin(ResourceSkin* info);

	private:
		void NotifyButtonPressed(Widget* sender, int left, int top, MouseButton id);
		void NotifyListLostFocus(Widget* sender, GUI::Widget* _new);
		void NotifyListSelectAccept(List* widget, size_t position);
		void NotifyListMouseItemActivate(List* widget, size_t position);
		void NotifyListChangePosition(List* widget, size_t position);
		void NotifyMouseWheel(Widget* sender, int rel);
		void NotifyMousePressed(Widget* sender, int left, int top, MouseButton id);
		void NotifyEditTextChange(Edit* sender);

		void ShowList();
		void HideList();

		void InitialiseWidgetSkin(ResourceSkin* info);
		void ShutdownWidgetSkin();

		void ActionWidgetHide(Widget* widget);

		ControllerFadeAlpha* CreateControllerFadeAlpha(float alpha, float coef, bool enable);

	private:
		Button* mButton;
		List* mList;

		bool mListShow;
		int mMaxHeight;
		size_t mItemIndex;
		bool mModeDrop;
		bool mDropMouse;
		bool mShowSmooth;
		bool mManualList;

	};

} // namespace GUI

#endif // __COMBO_BOX_H__

