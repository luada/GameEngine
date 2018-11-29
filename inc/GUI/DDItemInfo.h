#ifndef __ITEM_DROP_INFO_H__
#define __ITEM_DROP_INFO_H__

#include "Prerequest.h"

namespace GUI
{

	struct GUI_EXPORT DDItemState
	{
		enum Enum
		{
			None,
			Start, /**< start drag */
			End, /**< end Drag (drop) */
			Miss, /**< drag DDContainer over empty space or widgets that don't have drag'n'drop */
			Accept, /**< drag DDContainer over another DDContainer that accept dropping on it */
			Refuse /**< drag DDContainer over another DDContainer that refuse dropping on it */
		};

		DDItemState(Enum value = None) : value(value) { }

		friend bool operator == (DDItemState const& a, DDItemState const& b) { return a.value == b.value; }
		friend bool operator != (DDItemState const& a, DDItemState const& b) { return a.value != b.value; }

	private:
		Enum value;
	};

	/** Inormation about drag'n'drop indexes */
	struct GUI_EXPORT DDItemInfo
	{
		DDItemInfo() :
			sender(nullptr),
			sender_index(ITEM_NONE),
			receiver(nullptr),
			receiver_index(ITEM_NONE)
		{
		}

		DDItemInfo(DDContainer* sender, size_t sender_index, DDContainer* receiver, size_t receiver_index) :
			sender(sender),
			sender_index(sender_index),
			receiver(receiver),
			receiver_index(receiver_index)
		{
		}

		void set(DDContainer* sender, size_t sender_index, DDContainer* receiver, size_t receiver_index)
		{
			this->sender = sender;
			this->sender_index = sender_index;
			this->receiver = receiver;
			this->receiver_index = receiver_index;
		}

		void Reset()
		{
			sender = nullptr;
			sender_index = ITEM_NONE;
			receiver = nullptr;
			receiver_index = ITEM_NONE;
		}

		/** DDContainer that send this Event (container from which we started drag) */
		DDContainer* sender;
		/** Index of sender container */
		size_t sender_index;

		/** DDContainer that receive dragged Widget (container to which we want to drop) */
		DDContainer* receiver;
		/** Index of receiver container */
		size_t receiver_index;
	};

	struct GUI_EXPORT DDWidgetState
	{
		DDWidgetState(size_t index) :
			index(index),
			update(true),
			accept(false),
			refuse(false)
		{ }

		/** Index of element */
		size_t index;
		/** State and internal data changed */
		bool update;
		/** Is widget accept drop */
		bool accept;
		/** Is widget refuse drop */
		bool refuse;
	};

} // namespace GUI

#endif // __ITEM_DROP_INFO_H__

