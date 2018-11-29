#ifndef __ITEM_DROP_INFO_H__
#define __ITEM_DROP_INFO_H__

#include <GUI.h>
#include "BaseLayout/BaseLayout.h"

namespace wraps
{

	struct DDItemInfo
	{

		DDItemInfo(const GUI::DDItemInfo & info) :
			Sender(*_info.sender->getUserData<wraps::BaseLayout*>()),
			Sender_index(info.sender_index),
			Receiver(info.receiver ? *info.receiver->getUserData<wraps::BaseLayout*>() : nullptr),
			Receiver_index(info.receiver_index)
		{
		}

		wraps::BaseLayout * sender;
		size_t sender_index;

		wraps::BaseLayout * receiver;
		size_t receiver_index;
	};

} // namespace wraps

#endif // __ITEM_DROP_INFO_H__
