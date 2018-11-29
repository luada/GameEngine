#ifndef __LIST_BOX_H__
#define __LIST_BOX_H__

#include "Prerequest.h"
#include "ListCtrl.h"

namespace GUI
{

	class GUI_EXPORT ListBox :
		public ListCtrl
	{
		RTTI_DERIVED(ListBox)
		DEFINE_GET_THIS(ListBox, BASS(ListCtrl, END))

	public:
		ListBox();

		//------------------------------------------------------------------------------//

		//! Get number of items
		//@ExportToLua
		size_t GetItemCount() const { return mItemsInfo.size(); }

		//! Insert an item into a array at a specified position
		void InsertItemAt(size_t index, const UString& name, Any data = Any::Null);
		//@ExportToLua
		void InsertItem(size_t index, const UString& name, Widget* value = nullptr) { InsertItemAt(index, name, value); }

		//! Add an item to the end of a array
		void AddItem(const UString& name, Any data = Any::Null) { InsertItemAt(ITEM_NONE, name, data); }
		//@ExportToLua
		void AppendItem(const UString& name, Widget* value = nullptr) { InsertItemAt(ITEM_NONE, name, value); }

		//! Remove item at a specified position
		void RemoveItemAt(size_t index);
		//@ExportToLua
		void RemoveItem(size_t index) { RemoveItemAt(index); }

		//! Remove all items
		//@ExportToLua
		void RemoveAllItems();

		//! Swap items at a specified positions
		void SwapItemsAt(size_t index1, size_t index2);
		//@ExportToLua
		void SwapItems(size_t index1, size_t index2) { SwapItemsAt(index1, index2); }

		//! Search item, returns the position of the first occurrence in array or ITEM_NONE if item not found
		//@ExportToLua
		size_t FindItemIndexWith(const UString& name);


		//------------------------------------------------------------------------------//

		/** Get index of selected Item (ITEM_NONE if none selected) */
		//@ExportToLua
		size_t GetIndexSelected() { return Base::GetIndexSelected(); }

		/** Select specified index */
		//@ExportToLua
		void SetIndexSelected(size_t index) { Base::SetIndexSelected(index); }

		/** Clear item selection */
		//@ExportToLua
		void ClearIndexSelected() { Base::ClearIndexSelected(); }


		//------------------------------------------------------------------------------//

		//! Replace an item data at a specified position
		void SetItemDataAt(size_t index, Any data) { Base::SetItemDataAt(index, data); }
		//@ExportToLua
		void SetItemData(size_t index, Widget* value) { Base::SetItemDataAt(index, value); }

		//! Clear an item data at a specified position
		void ClearItemDataAt(size_t index) { Base::ClearItemDataAt(index); }
		//@ExportToLua
		void ClearItemData(size_t index) { Base::ClearItemDataAt(index); }

		//! Get item data from specified position
		template <typename ValueType>
		ValueType * GetItemDataAt(size_t index, bool _throw = true)
		{
			return Base::GetItemDataAt<ValueType>(index, _throw);
		}

		//@ExportToLua
		Widget* GetItemData(size_t index) { return Base::GetItemData(index); }


		//------------------------------------------------------------------------------//

		//! Replace an item name at a specified position
		void SetItemNameAt(size_t index, const UString& name);
		//@ExportToLua
		void SetItemName(size_t index, const UString& name) { SetItemNameAt(index, name); }

		//! Get item name from specified position
		const UString& GetItemNameAt(size_t index);
		//@ExportToLua
		const UString& GetItemName(size_t index) { return GetItemNameAt(index); }


		//------------------------------------------------------------------------------//

		//! Move all elements so specified becomes visible
		void BeginToItemAt(size_t index);
		//@ExportToLua
		void BeginToItem(size_t index)
		{
			BeginToItemAt(index);
		}

		//! Move all elements so first becomes visible
		//@ExportToLua
		void BeginToItemFirst() { if (GetItemCount()) BeginToItemAt(0); }

		//! Move all elements so last becomes visible
		//@ExportToLua
		void BeginToItemLast() { if (GetItemCount()) BeginToItemAt(GetItemCount() - 1); }

		//! Move all elements so selected becomes visible
		//@ExportToLua
		void BeginToItemSelected() { if (GetIndexSelected() != ITEM_NONE) BeginToItemAt(GetIndexSelected()); }


	/*internal:*/
		virtual void _initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name);

	protected:
		virtual ~ListBox();

		void BaseChangeWidgetSkin(ResourceSkin* info);

	private:
		void InitialiseWidgetSkin(ResourceSkin* info);
		void ShutdownWidgetSkin();

		void NotifyCreateWidgetItem(GUI::ListCtrl* sender, GUI::Widget* item);
		void NotifyDrawItem(GUI::ListCtrl* sender, GUI::Widget* item, const GUI::IBDrawItemInfo& info, GUI::IntCoord& coord);

	private:
		std::string mSkinLine;
		int mHeightLine;

		typedef std::vector<UString> VectorUTFString;
		VectorUTFString mItemsInfo;

	};

} // namespace GUI

#endif // __LIST_BOX_H__

