#ifndef __BASE_ITEM_BOX_H__
#define __BASE_ITEM_BOX_H__

#include <GUI.h>
#include "BaseLayout.h"
#include "ItemDropInfo.h"

namespace wraps
{

	template<typename CellType>
	class BaseItemBox : public BaseLayout
	{
	public:
		typedef typename CellType::Type DataType;

	public:
		BaseItemBox(const std::string& layout, GUI::WidgetPtr parent) : BaseLayout(layout, parent)
		{
			mBoxItems = mMainWidget->CastType<GUI::ItemBox>();
			mBoxItems->SetUserData(static_cast<BaseLayout*>(this));

			mBoxItems->requestCreateWidgetItem = GUI::NewDelegate(this, &BaseItemBox::RequestCreateWidgetItem);
			mBoxItems->requestCoordItem = GUI::NewDelegate(this, &BaseItemBox::RequestCoordWidgetItem);
			mBoxItems->requestDrawItem = GUI::NewDelegate(this, &BaseItemBox::RequestUpdateWidgetItem);

			mBoxItems->eventStartDrag = GUI::NewDelegate(this, &BaseItemBox::NotifyStartDrop);
			mBoxItems->eventRequestDrop = GUI::NewDelegate(this, &BaseItemBox::NotifyRequestDrop);
			mBoxItems->eventDropResult = GUI::NewDelegate(this, &BaseItemBox::NotifyEndDrop);
			mBoxItems->eventChangeDDState = GUI::NewDelegate(this, &BaseItemBox::NotifyDropState);
			mBoxItems->eventNotifyItem = GUI::NewDelegate(this, &BaseItemBox::NotifyNotifyItem);

			mBoxItems->eventToolTip = GUI::NewDelegate(this, &BaseItemBox::NotifyToolTip);
		}

		virtual ~BaseItemBox()
		{
			mBoxItems->requestCreateWidgetItem = nullptr;
			mBoxItems->requestCoordItem = nullptr;
			mBoxItems->requestDrawItem = nullptr;

			mBoxItems->eventStartDrag = nullptr;
			mBoxItems->eventRequestDrop = nullptr;
			mBoxItems->eventDropResult = nullptr;
			mBoxItems->eventChangeDDState = nullptr;
			mBoxItems->eventNotifyItem = nullptr;

			mBoxItems->eventToolTip = nullptr;

			for (typename VectorCellView::iterator iter=mListCellView.begin(); iter!=mListCellView.end(); ++iter)
			{
				delete *iter;
			}
			mListCellView.clear();
		}

		void AddItem(DataType * data)
		{
			mBoxItems->AddItem(data);
		}

		void RemoveItem(size_t index)
		{
			mBoxItems->DeleteItem(index);
		}

		void SetItemData(size_t index, DataType * data)
		{
			mBoxItems->SetItemDataAt(index, data);
		}

		template <typename ValueType>
		ValueType * GetItemDataAt(size_t index, bool _throw = true)
		{
			return mBoxItems->GetItemDataAt<ValueType>(index, _throw);
		}

	private:
		void RequestCreateWidgetItem(GUI::ItemBoxPtr sender, GUI::WidgetPtr item)
		{
			CellType * cell = new CellType(item);
			item->SetUserData(cell);
			mListCellView.push_back(cell);
		}

		void RequestCoordWidgetItem(GUI::ItemBoxPtr sender, GUI::IntCoord & coord, bool drop)
		{
			CellType::GetCellDimension(sender, coord, drop);
		}

		void RequestUpdateWidgetItem(GUI::ItemBoxPtr sender, GUI::WidgetPtr item, const GUI::IBDrawItemInfo & data)
		{
			CellType * cell = *item->GetUserData<CellType*>();
			cell->Update(data, *mBoxItems->GetItemDataAt<DataType*>(data.index));
		}

		void NotifyStartDrop(GUI::DDContainerPtr sender, const GUI::DDItemInfo & info, bool & result)
		{
			eventStartDrag(this, GUI::DDItemInfo(info), result);
		}

		void NotifyRequestDrop(GUI::DDContainerPtr sender, const GUI::DDItemInfo & info, bool & result)
		{
			eventRequestDrop(this, GUI::DDItemInfo(info), result);
		}

		void NotifyEndDrop(GUI::DDContainerPtr sender, const GUI::DDItemInfo & info, bool result)
		{
			eventDropResult(this, GUI::DDItemInfo(info), result);
		}

		void NotifyDropState(GUI::DDContainerPtr sender, GUI::DDItemState state)
		{
			eventChangeDDState(this, state);
		}

		void NotifyNotifyItem(GUI::ItemBoxPtr sender, const GUI::IBNotifyItemData & info)
		{
			eventNotifyItem(this, info);
		}

		void NotifyToolTip(GUI::WidgetPtr sender, const GUI::ToolTipInfo & info)
		{
			DataType * data = nullptr;
			if (info.type == GUI::ToolTipInfo::Show)
			{
				if (info.index == GUI::ITEM_NONE) return;
				data = *mBoxItems->GetItemDataAt<DataType*>(info.index);
			}
			eventToolTip(this, info, data);
 		}

	public:
		GUI::delegates::CDelegate3<BaseLayout *, GUI::DDItemInfo, bool &> eventStartDrag;
		GUI::delegates::CDelegate3<BaseLayout *, GUI::DDItemInfo, bool &> eventRequestDrop;
		GUI::delegates::CDelegate3<BaseLayout *, GUI::DDItemInfo, bool> eventDropResult;
		GUI::delegates::CDelegate2<BaseLayout *, GUI::DDItemState> eventChangeDDState;
		GUI::delegates::CDelegate2<BaseLayout *, const GUI::IBNotifyItemData & > eventNotifyItem;

		GUI::delegates::CDelegate3<BaseLayout *, const GUI::ToolTipInfo &, DataType *> eventToolTip;

		GUI::ItemBoxPtr GetItemBox() { return mBoxItems; }


	private:
		typedef std::vector<CellType*> VectorCellView;
		VectorCellView mListCellView;
		GUI::ItemBoxPtr mBoxItems;
	};

} // namespace wraps

#endif // __BASE_ITEM_BOX_H__
