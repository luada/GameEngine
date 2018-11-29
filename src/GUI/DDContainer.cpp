#include "Precompiled.h"
#include "DDContainer.h"
#include "InputManager.h"
#include "LayerManager.h"

namespace GUI
{

	DDContainer::DDContainer() :
		mDropResult(false),
		mNeedDrop(false),
		mStartDrop(false),
		mOldDrop(nullptr),
		mCurrentSender(nullptr),
		mDropSenderIndex(ITEM_NONE),
		mDropItem(nullptr),
		mNeedDragDrop(false),
		mReseiverContainer(nullptr)
	{
	}

	void DDContainer::_initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name)
	{
		Base::_initialise(style, coord, align, info, parent, croppedParent, creator, name);

		InitialiseWidgetSkin(info);
	}

	DDContainer::~DDContainer()
	{
		ShutdownWidgetSkin();
	}

	void DDContainer::BaseChangeWidgetSkin(ResourceSkin* info)
	{
		ShutdownWidgetSkin();
		Base::BaseChangeWidgetSkin(info);
		InitialiseWidgetSkin(info);
	}

	void DDContainer::InitialiseWidgetSkin(ResourceSkin* info)
	{
	}

	void DDContainer::ShutdownWidgetSkin()
	{
	}

	void DDContainer::OnMouseButtonPressed(int left, int top, MouseButton id)
	{
		mClickInWidget = InputManager::GetInstance().GetLastLeftPressed() - GetAbsolutePosition();

		MouseButtonPressed(id);

		Base::OnMouseButtonPressed(left, top, id);
	}

	void DDContainer::OnMouseButtonReleased(int left, int top, MouseButton id)
	{
		MouseButtonReleased(id);

		Base::OnMouseButtonReleased(left, top, id);
	}

	void DDContainer::OnMouseDrag(int left, int top)
	{
		MouseDrag();

		Base::OnMouseDrag(left, top);
	}

	void DDContainer::MouseButtonPressed(MouseButton id)
	{
		if (MouseButton::Left == id)
		{
			mDropResult = false;
			mOldDrop = nullptr;
			mDropInfo.Reset();
			mReseiverContainer = nullptr;

			mCurrentSender = nullptr;
			mStartDrop = false;

		}
		else
		{
			endDrop(true);
		}
	}

	void DDContainer::MouseButtonReleased(MouseButton id)
	{
		if (MouseButton::Left == id)
		{
			endDrop(false);
		}
	}

	void DDContainer::MouseDrag()
	{
		bool update = false;

		if (!mStartDrop && mDropSenderIndex != ITEM_NONE)
		{
			mStartDrop = true;
			mNeedDrop = false;
			update = true;
			mDropInfo.set(this, mDropSenderIndex, nullptr, ITEM_NONE);
			mReseiverContainer = nullptr;

			eventStartDrag(this, mDropInfo, mNeedDrop);

			if (mNeedDrop)
			{
				eventChangeDDState(this, DDItemState::Start);
				SetEnableToolTip(false);
			}
			else
			{
				InputManager::GetInstance().ResetMouseCaptureWidget();
			}
		}

		if (!mNeedDrop)
		{
			return;
		}

		const IntPoint& point = InputManager::GetInstance().GetMousePosition();
		Widget* item = LayerManager::GetInstance().GetWidgetFromPoint(point.left, point.top);

		UpdateDropItems();

		if (mOldDrop == item) return;
		mOldDrop = item;

		if (mReseiverContainer) mReseiverContainer->_setContainerItemInfo(mDropInfo.receiver_index, false, false);

		mDropResult = false;
		mReseiverContainer = nullptr;
		Widget* receiver = nullptr;
		size_t receiver_index = ITEM_NONE;
		if (item)
		{
			item->_getContainer(receiver, receiver_index);
			if (receiver && receiver->IsType<DDContainer>())
			{
				mReseiverContainer = static_cast<DDContainer*>(receiver);
				mReseiverContainer->_eventInvalideContainer = NewDelegate(this, &DDContainer::NotifyInvalideDrop);

				mDropInfo.set(this, mDropSenderIndex, mReseiverContainer, receiver_index);

				eventRequestDrop(this, mDropInfo, mDropResult);

				mReseiverContainer->_setContainerItemInfo(mDropInfo.receiver_index, true, mDropResult);
			}
			else
			{
				mDropInfo.set(this, mDropSenderIndex, nullptr, ITEM_NONE);
			}
		}
		else
		{
			mDropInfo.set(this, mDropSenderIndex, nullptr, ITEM_NONE);
		}

		DDItemState state;

		DDWidgetState data(mDropSenderIndex);
		data.update = update;

		if (receiver == nullptr)
		{
			data.accept = false;
			data.refuse = false;
			state = DDItemState::Miss;
		}
		else if (mDropResult)
		{
			data.accept = true;
			data.refuse = false;
			state = DDItemState::Accept;
		}
		else
		{
			data.accept = false;
			data.refuse = true;
			state = DDItemState::Refuse;
		}

		UpdateDropItemsState(data);

		eventChangeDDState(this, state);
	}

	void DDContainer::endDrop(bool reset)
	{
		if (mStartDrop)
		{
			RemoveDropItems();

			if (mReseiverContainer) mReseiverContainer->_setContainerItemInfo(mDropInfo.receiver_index, false, false);

			if (reset) mDropResult = false;
			eventDropResult(this, mDropInfo, mDropResult);
			eventChangeDDState(this, DDItemState::End);
			SetEnableToolTip(true);

			mStartDrop = false;
			mDropResult = false;
			mNeedDrop = false;
			mOldDrop = nullptr;
			mDropInfo.Reset();
			mReseiverContainer = nullptr;
			mDropSenderIndex = ITEM_NONE;
		}
	}

	void DDContainer::RemoveDropItems()
	{
		mDropItem = nullptr;
	}

	void DDContainer::UpdateDropItems()
	{

		if (mDropItem == nullptr)
		{
			requestDragWidgetInfo(this, mDropItem, mDropDimension);
		}

		const IntPoint& point = InputManager::GetInstance().GetMousePositionByLayer();

		if (mDropItem)
		{
			mDropItem->SetCoord(point.left - mClickInWidget.left + mDropDimension.left, point.top - mClickInWidget.top + mDropDimension.top, mDropDimension.width, mDropDimension.height);
			mDropItem->SetVisible(true);
		}
	}

	void DDContainer::UpdateDropItemsState(const DDWidgetState& state)
	{
		eventUpdateDropState(this, mDropItem, state);
	}

	void DDContainer::NotifyInvalideDrop(DDContainer* sender)
	{
		MouseDrag();
	}

	void DDContainer::_getContainer(Widget*& container, size_t& index)
	{
		container = this;
		index = ITEM_NONE;
	}

	void DDContainer::SetProperty(const std::string& key, const std::string& value)
	{
		if (key == "DDContainer_NeedDragDrop") SetNeedDragDrop(utility::ParseValue<bool>(value));
		else
		{
			Base::SetProperty(key, value);
			return;
		}
		eventChangeProperty(this, key, value);
	}

} // namespace GUI

