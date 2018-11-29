#ifndef __MULTI_LIST_H__
#define __MULTI_LIST_H__

#include "Prerequest.h"
#include "Widget.h"
#include "List.h"
#include "Any.h"
#include "BiIndexBase.h"
#include "EventPair.h"

namespace GUI
{

	//OBSOLETE
	typedef delegates::CDelegate5<Widget*, size_t, const UString &, const UString &, bool &> EventHandle_WidgetIntUTFStringUTFStringBool;

	typedef delegates::CDelegate5<MultiList*, size_t, const UString &, const UString &, bool &> EventHandle_MultiListPtrSizeTCUTFStringRefCUTFStringRefBoolRef;
	typedef delegates::CDelegate2<MultiList*, size_t> EventHandle_MultiListPtrSizeT;

	class GUI_EXPORT MultiList :
		public Widget,
		public BiIndexBase
	{
		RTTI_DERIVED(MultiList)
		DEFINE_GET_THIS(MultiList, BASS(Widget, END))

	public:
		MultiList();

		//------------------------------------------------------------------------------//
		// Methods for work with Columns
		//------------------------------------------------------------------------------//

		//! Get number of columns
		//@ExportToLua
		size_t GetColumnCount() { return mVectorColumnInfo.size(); }

		/** Insert new column
			@param _column New column will be inserted before _column
			@param _name Name of new column
			@param _width Width of new column
		*/
		void InsertColumnAt(size_t column, const UString& name, int width, Any data = Any::Null);
		//@ExportToLua
		void InsetColumn(size_t column, const UString& name, int width, Widget* value = nullptr) { InsertColumnAt(column, name, width, value); }

		/** Add new column at last position
			@param _width Width of new column
			@param _name Name of new column
		*/
		void AddColumn(const UString& name, int width, Any data = Any::Null) { InsertColumnAt(ITEM_NONE, name, width, data); }
		//@ExportToLua
		void AppendColumn(const UString& name, int width, Widget* value = nullptr) { InsertColumnAt(ITEM_NONE, name, width, value); }

		/** delete column */
		void RemoveColumnAt(size_t column);
		//@ExportToLua
		void RemoveColumn(size_t column) { RemoveColumnAt(column); }

		/** delete all columns */
		//@ExportToLua
		void RemoveAllColumns();


		//------------------------------------------------------------------------------//

		/** Set column name
			@param _column Index of column
			@param _name New name of column
		*/
		void SetColumnNameAt(size_t column, const UString& name);
		//@ExportToLua
		void SetColumnName(size_t column, const UString& name) { SetColumnNameAt(column, name); }

		/** Set column width
			@param _column Index of column
			@param _name New width of column
		*/
		void SetColumnWidthAt(size_t column, int width);
		//@ExportToLua
		void SetColumnWidth(size_t column, int width) { SetColumnWidthAt(column, width); }

		/** Get _column name */
		const UString& GetColumnNameAt(size_t column);
		//@ExportToLua
		const UString& GetColumnName(size_t column) { return GetColumnNameAt(column); }

		/** Get _column width */
		int GetColumnWidthAt(size_t column);
		//@ExportToLua
		int GetColulmnWidth(size_t column) { return GetColumnWidthAt(column); }

		/** Sort multilist by column */
		//@ExportToLua
		void SortByColumn(size_t column, bool backward = false);

		//------------------------------------------------------------------------------//

		//! Replace an item data at a specified position
		void SetColumnDataAt(size_t index, Any data);
		//@ExportToLua
		void SetColumnData(size_t index, Widget* value) { SetColumnDataAt(index, value); }

		//! Clear an item data at a specified position
		void ClearColumnDataAt(size_t index) { SetColumnDataAt(index, Any::Null); }
		//@ExportToLua
		void ClearColumnData(size_t index) { SetColumnDataAt(index, Any::Null); }

		//! Get item data from specified position
		template <typename ValueType>
		ValueType * GetColumnDataAt(size_t index, bool _throw = true)
		{
			ASSERT_RANGE(index, mVectorColumnInfo.size(), "MultiList::getItemDataAt");
			return mVectorColumnInfo[index].data.CastType<ValueType>(_throw);
		}

		//@ExportToLua
		Widget* GetColumnData(size_t index)
		{
			if (index >= 0 && index < mVectorColumnInfo.size())
			{
				return *mVectorColumnInfo[index].data.CastType<Widget*>(false);
			}
			return nullptr;
		}

		//------------------------------------------------------------------------------//
		// Methods for work with Lines
		/** @note
		All indexes used here is indexes of unsorted Multilist. Even if you sorted
			it - all items indexes will be same as before sort.
		*/

		//------------------------------------------------------------------------------//

		/** Get number of Items (lines) */
		//@ExportToLua
		size_t GetItemCount() const;

		/** Insert new item before index line */
		void InsertItemAt(size_t index, const UString& name, Any data = Any::Null);
		//@ExportToLua
		void InsertItem(size_t index, const UString& name, Widget* value = nullptr) { InsertItemAt(index, name, value); }

		/** Add new item at the end */
		void AddItem(const UString& name, Any data = Any::Null) { InsertItemAt(ITEM_NONE, name, data); }
		//@ExportToLua
		void AppendItem(const UString& name, Widget* value = nullptr) { InsertItemAt(ITEM_NONE, name, value); }

		//! Remove item at a specified position
		void RemoveItemAt(size_t index);
		//@ExportToLua
		void RemoveItem(size_t index) { RemoveItemAt(index); }

		/** delete all items */
		//@ExportToLua
		void RemoveAllItems();

		//! Swap items at a specified positions
		void SwapItemsAt(size_t index1, size_t index2);
		//@ExportToLua
		void SwapItems(size_t index1,size_t index2) { SwapItemsAt(index1, index2); }


		//------------------------------------------------------------------------------//

		//! Replace an item name
		void SetItemNameAt(size_t index, const UString& name) { SetSubItemNameAt(0, index, name); }
		//@ExportToLua
		void SetItemName(size_t index, const UString& name)   { SetSubItemNameAt(0, index, name); }

		//! Get item name from specified position
		const UString& GetItemNameAt(size_t index) { return GetSubItemNameAt(0, index); }
		//@ExportToLua
		const UString& GetItemName(size_t index) { return GetSubItemNameAt(0, index); }


		//------------------------------------------------------------------------------//

		/** Get index of selected Item (ITEM_NONE if none selected) */
		//@ExportToLua
		size_t GetIndexSelected() { return mItemSelected; }

		/** Select specified index */
		//@ExportToLua
		void SetIndexSelected(size_t index);

		/** Clear item selection */
		//@ExportToLua
		void ClearIndexSelected() { SetIndexSelected(ITEM_NONE); }


		//------------------------------------------------------------------------------//

		//! Replace an item data at a specified position
		void SetItemDataAt(size_t index, Any data) { SetSubItemDataAt(0, index, data); }
		//@ExportToLua
		void SetItemData(size_t index, Widget* value) { SetSubItemDataAt(0, index, value); }

		//! Clear an item data at a specified position
		void ClearItemDataAt(size_t index) { SetItemDataAt(index, Any::Null); }
		//@ExportToLua
		void ClearItemData(size_t index)   { SetItemDataAt(index, Any::Null); }

		//! Get item data from specified position
		template <typename ValueType>
		ValueType * GetItemDataAt(size_t index, bool _throw = true)
		{
			return GetSubItemDataAt<ValueType>(0, index, _throw);
		}

		//@ExportToLua
		Widget* GetItemData(size_t index) { return GetSubItemData(0, index); }


		//------------------------------------------------------------------------------//
		// Methods for work with sub Lines 
		//------------------------------------------------------------------------------//

		/** Set sub item
			@param _column Index of column
			@param index Index of line
			@param _name New sub item value
		*/
		void SetSubItemNameAt(size_t column, size_t index, const UString& name);
		//@ExportToLua
		void SetSubItemName(size_t column, size_t index, const UString& name) { SetSubItemNameAt(column, index, name); }

		/** Get sub item name*/
		const UString& GetSubItemNameAt(size_t column, size_t index);
		//@ExportToLua
		const UString& GetSubItemName(size_t column, size_t index) { return GetSubItemNameAt(column, index); }

		/** Search item in specified _column, returns index of the first occurrence in column or ITEM_NONE if item not found */
		//@ExportToLua
		size_t FindSubItemWith(size_t column, const UString& name);

		//------------------------------------------------------------------------------//

		//! Replace an item data at a specified position
		void SetSubItemDataAt(size_t column, size_t index, Any data);
		//@ExportToLua
		void SetSubItemData(size_t column, size_t index, Widget* value) { SetSubItemDataAt(column, index, value); }

		//! Clear an item data at a specified position
		void ClearSubItemDataAt(size_t column, size_t index) { SetSubItemDataAt(column, index, Any::Null); }
		//@ExportToLua
		void ClearSubItemData(size_t column, size_t index ) { SetSubItemDataAt(column, index, Any::Null); }

		//! Get item data from specified position
		template <typename ValueType>
		ValueType * GetSubItemDataAt(size_t column, size_t index, bool _throw = true)
		{
			ASSERT_RANGE(column, mVectorColumnInfo.size(), "MultiList::getSubItemDataAt");
			ASSERT_RANGE(index, mVectorColumnInfo.begin()->list->GetItemCount(), "MultiList::getSubItemDataAt");

			size_t curIndex = BiIndexBase::ConvertToBack(index);
			return mVectorColumnInfo[column].list->GetItemDataAt<ValueType>(curIndex, _throw);
		}

		//@ExportToLua
		Widget* GetSubItemData(size_t column, size_t index)
		{
			if (column >= 0 && column < mVectorColumnInfo.size() &&
				index >= 0 && index < mVectorColumnInfo.begin()->list->GetItemCount())
			{
				size_t curIndex = BiIndexBase::ConvertToBack(index);
				return mVectorColumnInfo[column].list->GetItemData(curIndex);
			}
			return nullptr;
		}

	/*internal:*/
		virtual void _initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name);

	/*event:*/
		/** Event : Enter pressed or double click.\n
			signature : void Method(GUI::MultiList* sender, size_t index)\n
			@param _sender widget that called this event
			@param index of selected item
		*/
		EventPair<EventHandle_WidgetSizeT, EventHandle_MultiListPtrSizeT> eventListSelectAccept;

		/** Event : Selected item position changed.\n
			signature : void Method(GUI::MultiList* sender, size_t index)\n
			@param _sender widget that called this event
			@param index of new item
		*/
		EventPair<EventHandle_WidgetSizeT, EventHandle_MultiListPtrSizeT> eventListChangePosition;

		/** Event : Less than operator for sort multilist by columns.\n
			signature : void Method(GUI::MultiList* sender, size_t column, const UString& firstItem, const UString& secondItem, bool& less)\n
			@param _sender widget that called this event
			@param _column Index of column
			@param _firstItem Strings for compare
			@param _secondItem Strings for compare
			@param _less Comparsion Result (write your value here)
		*/
		EventHandle_MultiListPtrSizeTCUTFStringRefCUTFStringRefBoolRef requestOperatorLess;

	protected:
		virtual ~MultiList();

		void BaseChangeWidgetSkin(ResourceSkin* info);

		void NotifyListChangePosition(List* sender, size_t position);
		void NotifyListChangeFocus(List* sender, size_t position);
		void NotifyListChangeScrollPosition(List* sender, size_t position);
		void NotifyButtonClick(Widget* sender);
		void NotifyListSelectAccept(List* sender, size_t position);

		void UpdateColumns();
		void RedrawButtons();
		void UpdateOnlyEmpty();

		bool Compare(List* list, size_t left, size_t right);
		void SortList();
		void FlipList();

		Widget* GetSeparator(size_t index);

		void SetButtonImageIndex(Button* button, size_t index);

		void UpdateBackSelected(size_t index);

	private:
		void InitialiseWidgetSkin(ResourceSkin* info);
		void ShutdownWidgetSkin();

		void FrameEntered(float frame);

		void FrameAdvise(bool advise);

	private:
		struct ColumnInfo
		{
			List* list;
			Button* button;
			int width;
			UString name;
			Any data;
		};

		typedef std::vector<ColumnInfo> VectorColumnInfo;

		enum ImageSort
		{
			SORT_NONE,
			SORT_UP,
			SORT_DOWN
		};

	private:
		int mHeightButton;
		int mWidthBar;
		std::string mSkinButton, mSkinList;
		Button* mButtonMain;

		VectorColumnInfo mVectorColumnInfo;

		VectorWidgetPtr mSeparators;

		size_t mLastMouseFocusIndex;

		bool mSortUp;
		size_t mSortColumnIndex;

		int mWidthSeparator;
		std::string mSkinSeparator;
		int mOffsetButtonSeparator;

		size_t mItemSelected;

		bool mFrameAdvise;
		Widget* mClient;
	};

} // namespace GUI

#endif // __MULTI_LIST_H__

