#ifndef __DDCONTAINER_H__
#define __DDCONTAINER_H__

#include "Prerequest.h"
#include "Widget.h"
#include "DDItemInfo.h"
#include "EventPair.h"

namespace GUI
{

	typedef delegates::CDelegate3<DDContainer*, const DDItemInfo&, bool&> EventHandle_DDContainerPtrCDDItemInfoRefBoolRef;
	typedef delegates::CDelegate3<DDContainer*, const DDItemInfo&, bool> EventHandle_DDContainerPtrCDDItemInfoRefBool;
	typedef delegates::CDelegate2<DDContainer*, DDItemState> EventHandle_EventHandle_DDContainerPtrDDItemState;
	typedef delegates::CDelegate3<DDContainer*, WidgetPtr&, IntCoord&> EventHandle_EventHandle_DDContainerPtrWidgetPtrRefIntCoordRef;


	class GUI_EXPORT DDContainer :
		public Widget
	{
		RTTI_DERIVED(DDContainer)

	public:
		DDContainer();

		/** Set drag'n'drop mode flag.
			Disabled (false) by default.
		*/
		void SetNeedDragDrop(bool value) { mNeedDragDrop = value; }
		/** Get drag'n'drop mode flag */
		bool GetNeedDragDrop() { return mNeedDragDrop; }

		/** @copydoc Widget::SetProperty(const std::string& key, const std::string& value) */
		virtual void SetProperty(const std::string& key, const std::string& value);

	/*event:*/
		/** Event : request for start drag
			signature : void Method(GUI::DDContainer* sender, const GUI::DDItemInfo& info, bool& result)
			@param _sender widget that called this event
			@param _info information about DDContainers
			@param _result write here true if container can be draggedor false if it can't
		*/
		EventHandle_DDContainerPtrCDDItemInfoRefBoolRef eventStartDrag;

		/** Event : request for start Drag (moving mouse over container, but not dropped yet)
			signature : void Method(GUI::DDContainer* sender, const GUI::DDItemInfo& info, bool& result)
			@param _sender widget that called this event
			@param _info information about DDContainers
			@param _result write here true if container accept dragged widget or false if it isn't
		*/
		EventHandle_DDContainerPtrCDDItemInfoRefBoolRef eventRequestDrop;

		/** Event : end Drag (drop)
			signature : void Method(GUI::DDContainer* sender, const GUI::DDItemInfo& info, bool result)
			@param _sender widget that called this event
			@param _info information about DDContainers
			@param _result if true then drop was successfull
		*/
		EventHandle_DDContainerPtrCDDItemInfoRefBool eventDropResult;

		/** Event : drag'n'drop state changed
			signature : void Method(GUI::DDContainer* sender, GUI::DDItemState state)
			@param _sender widget that called this event
			@param _state new state
		*/
		EventHandle_EventHandle_DDContainerPtrDDItemState eventChangeDDState;

		/** Event : [not used] request widget for dragging
			signature : void Method(GUI::DDContainer* sender, GUI::Widget*& item, GUI::IntCoord& dimension)
			@param _sender widget that called this event
			@param _item write widget pointer here
			@param _dimension write widget coordinate here
		*/
		EventHandle_EventHandle_DDContainerPtrWidgetPtrRefIntCoordRef requestDragWidgetInfo;


	/*internal:*/
		virtual void _setContainerItemInfo(size_t index, bool set, bool accept) { }

		virtual void _initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name);

		/** Event :
			signature : void Method(GUI::DDContainer* sender)
			@param _sender widget that called this event
		*/
		EventPair<EventHandle_WidgetVoid, delegates::CDelegate1<DDContainer*> >
			_eventInvalideContainer;

		/** Event : 
			signature : void Method(GUI::DDContainer* sender, GUI::Widget* item, const GUI::DDWidgetState& state)
			@param _sender widget that called this event
			@param _items
			@param _state
		*/
		delegates::CDelegate3<DDContainer*, Widget*, const DDWidgetState&>
			eventUpdateDropState;

	protected:
		virtual ~DDContainer();

		void BaseChangeWidgetSkin(ResourceSkin* info);

		virtual void OnMouseButtonPressed(int left, int top, MouseButton id);
		virtual void OnMouseButtonReleased(int left, int top, MouseButton id);
		virtual void OnMouseDrag(int left, int top);

		virtual void NotifyInvalideDrop(DDContainer* sender);

		virtual void _getContainer(Widget*& container, size_t& index);

		virtual void RemoveDropItems();
		virtual void UpdateDropItems();
		virtual void UpdateDropItemsState(const DDWidgetState& state);

		void MouseDrag();
		void MouseButtonReleased(MouseButton id);
		void MouseButtonPressed(MouseButton id);

		void endDrop(bool reset);

	private:
		void InitialiseWidgetSkin(ResourceSkin* info);
		void ShutdownWidgetSkin();


	protected:
		bool mDropResult;
		bool mNeedDrop;
		bool mStartDrop;

		Widget* mOldDrop;
		Widget* mCurrentSender;

		DDItemInfo mDropInfo;

		size_t mDropSenderIndex;

		Widget* mDropItem;
		IntCoord mDropDimension;

		IntPoint mClickInWidget;

		bool mNeedDragDrop;

		DDContainer* mReseiverContainer;
	};

} // namespace GUI

#endif // __DDCONTAINER_H__

