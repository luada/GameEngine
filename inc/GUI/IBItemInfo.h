#ifndef __ITEM_INFO_H__
#define __ITEM_INFO_H__

#include "Prerequest.h"

namespace GUI
{

	/** Info about ItemBox item*/
	struct GUI_EXPORT IBDrawItemInfo
	{

		IBDrawItemInfo() :
			index(ITEM_NONE),
			update(false),
			select(false),
			active(false),
			drag(false),
			drop_accept(false),
			drop_refuse(false)
		{
		}

		IBDrawItemInfo(size_t index, size_t select, size_t active, size_t accept, size_t refuse, bool update, bool drag) :
			index(index),
			update(update),
			select(index == select),
			active(index == active),
			drag(drag),
			drop_accept(index == accept),
			drop_refuse(index == refuse)
		{
		}

		/** Index of element */
		size_t index;
		/** State and interdan data changed */
		bool update;
		/** Is widget selected */
		bool select;
		/** Is widget active */
		bool active;
		/** Is widget able to be dragged */
		bool drag;
		/** Is widget accepting drop */
		bool drop_accept;
		/** Is widget refuseing drop */
		bool drop_refuse;
	};

	struct GUI_EXPORT IBNotifyItemData
	{
		enum NotifyItem
		{
			MousePressed,
			MouseReleased,
			KeyPressed,
			KeyReleased
		};

		IBNotifyItemData(size_t index, NotifyItem notify, int x, int y, MouseButton id) :
			index(index), notify(notify), x(x), y(y), id(id), code(KeyCode::None), key(0) { }

		IBNotifyItemData(size_t index, NotifyItem notify, KeyCode code, Char key) :
			index(index), notify(notify), x(0), y(0), id(MouseButton::None), code(code), key(key) { }

		IBNotifyItemData(size_t index, NotifyItem notify, KeyCode code) :
			index(index), notify(notify), x(0), y(0), id(MouseButton::None), code(code), key(KeyCode::None) { }

		/** Item index */
		size_t index;
		/** Notify type */
		NotifyItem notify;
		/** If Mouse* notify type - mouse x position, else 0 */
		int x;
		/** If Mouse* notify type - mouse y position, else 0 */
		int y;
		/** If Mouse* notify type - mouse button id position, else 0 */
		MouseButton id;
		/** If Key* notify type - key code, else 0 */
		KeyCode code;
		/** If Key* notify type - mouse button id position, else 0 */
		Char key;
	};

} // namespace GUI

#endif // __ITEM_INFO_H__

