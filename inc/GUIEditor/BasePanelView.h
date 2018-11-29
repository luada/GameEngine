#ifndef __BASE_PANEL_VIEW_H__
#define __BASE_PANEL_VIEW_H__

#include <GUI.h>
#include "BaseLayout.h"
#include "BasePanelViewItem.h"

namespace wraps
{

	template <typename TypeCell>
	class BasePanelView : public BaseLayout
	{
	public:
		typedef std::vector<BasePanelViewItem*> VectorCell;

	public:
		BasePanelView(const std::string& layout, GUI::WidgetPtr parent) :
	  		BaseLayout(layout, parent)
		{
			mScrollView = mMainWidget->CastType<GUI::ScrollView>();

			
			mScrollView->SetCanvasAlign(GUI::Align::HCenter | GUI::Align::Top);
			mScrollView->SetVisibleHScroll(false);
			mNeedUpdate = false;

			mOldClientWidth = mScrollView->GetClientCoord().width;
		}

		virtual ~BasePanelView()
		{
			RemoveAllItems();
		}

		//! Get number of items
		size_t GetItemCount() { return mItems.Size(); }

		//! Insert an item into a list at a specified position
		void InsertItem(size_t index, BasePanelViewItem * item)
		{
			ASSERT_RANGE_INSERT(index, mItems.size(), "BasePanelView::insertItem");
			if (index == GUI::ITEM_NONE) index = mItems.size();
			ASSERT(FindItem(item) == GUI::ITEM_NONE, "panel allready exist");

			
			BasePanelViewCell * cell = new TypeCell(mScrollView);
			cell->eventUpdatePanel = GUI::NewDelegate(this, &BasePanelView::NotifyUpdatePanel);

			
			item->_initialise(cell);

			mItems.insert(mItems.begin() + index, item);
			SetNeedUpdate();
		}

		//! Add an item to the end of a list
		void AddItem(BasePanelViewItem * item) { InsertItem(GUI::ITEM_NONE, item); }

		//! Get item from specified position
		BasePanelViewItem * GetItem(size_t index)
		{
			ASSERT_RANGE(index, mItems.Size(), "BasePanelView::getItem");
			return mItems[index];
		}

		//! Search item, returns the position of the first occurrence in list or ITEM_NONE if item not found
		size_t FindItem(BasePanelViewItem * item)
		{
			for (VectorCell::iterator iter=mItems.begin(); iter!=mItems.end(); ++iter) {
				if ((*iter) == item) return iter - mItems.begin();
			}
			return GUI::ITEM_NONE;
		}

		bool GetItemShow(BasePanelViewItem * item) { return item->GetPanelCell()->IsVisible(); }
		void SetItemShow(BasePanelViewItem * item, bool show)
		{
			item->GetPanelCell()->SetVisible(show);
			SetNeedUpdate();
		}

		//! Remove item at a specified position
		void RemoveItemAt(size_t index)
		{
			ASSERT_RANGE(index, mItems.Size(), "BasePanelView::removeItemAt");

			BasePanelViewCell * cell = mItems[index]->GetPanelCell();
			mItems[index]->_shutdown();
			delete cell;

			mItems.erase(mItems.begin() + index);
			SetNeedUpdate();
		}

		//! Remove item at a specified position
		void RemoveItem(BasePanelViewItem * item)
		{
			size_t index = FindItem(item);
			ASSERT(index != GUI::ITEM_NONE, "item is not found");
			RemoveItemAt(index);
		}

		//! Remove all items
		void RemoveAllItems()
		{
			for (VectorCell::iterator iter=mItems.begin(); iter!=mItems.end(); ++iter) {
				BasePanelViewCell * cell = (*iter)->GetPanelCell();
				(*iter)->_shutdown();
				delete cell;
			}
			mItems.clear();
			SetNeedUpdate();
		}

		void UpdateView()
		{
			
			int height = 0;
			for (VectorCell::iterator iter=mItems.begin(); iter!=mItems.end(); ++iter) {
				GUI::WidgetPtr widget = (*iter)->GetPanelCell()->GetMainWidget();
				if (widget->IsVisible()) {
					height += widget->GetHeight();
				}
			}
			
			mScrollView->SetCanvasSize(0, height);
			
			const GUI::IntSize & size = mScrollView->GetClientCoord().Size();
			mScrollView->SetCanvasSize(size.width, height);

			bool change = false;
			if (mOldClientWidth != size.width) {
				mOldClientWidth = size.width;
				change = true;
			}

			
			int pos = 0;
			for (VectorCell::iterator iter=mItems.begin(); iter!=mItems.end(); ++iter) {
				GUI::WidgetPtr widget = (*iter)->GetPanelCell()->GetMainWidget();
				if (widget->IsVisible()) {

					height = widget->GetHeight();
					widget->SetCoord(GUI::IntCoord(0, pos, size.width, height));

					
					if (change) (*iter)->NotifyChangeWidth(size.width);

					pos += height;
				}
			}

			mNeedUpdate = false;
			GUI::Gui::GetInstance().eventFrameStart -= GUI::NewDelegate(this, &BasePanelView::FrameEntered);
		}

		
		
		void SetNeedUpdate()
		{
			if (!mNeedUpdate) {
				mNeedUpdate = true;
				GUI::Gui::GetInstance().eventFrameStart += GUI::NewDelegate(this, &BasePanelView::FrameEntered);
			}
		}

	private:
		void NotifyUpdatePanel(BasePanelViewCell * panel)
		{
			SetNeedUpdate();
		}

		void FrameEntered(float time) { UpdateView(); }

	protected:
		GUI::ScrollViewPtr mScrollView;

	private:
		VectorCell mItems;
		bool mNeedUpdate;
		int mOldClientWidth;
	};

} // namespace wraps

#endif // __BASE_PANEL_VIEW_H__
