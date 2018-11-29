#ifndef __TEXT_CHANGE_HISTORY_H__
#define __TEXT_CHANGE_HISTORY_H__

#include "Prerequest.h"
#include "Macros.h"
#include "UString.h"
#include <deque>

namespace GUI
{

	struct TextCommandInfo
	{
		enum CommandType
		{
			COMMAND_POSITION,
			COMMAND_INSERT,
			COMMAND_ERASE
		};

		TextCommandInfo(const UString& text, size_t start, CommandType type)
			: text(text), type(type), start(start), undo(ITEM_NONE), redo(ITEM_NONE), length(ITEM_NONE) { }
		TextCommandInfo(size_t undo, size_t redo, size_t length)
			: type(COMMAND_POSITION), start(ITEM_NONE), undo(undo), redo(redo), length(length) { }

		UString text;
		CommandType type;
		size_t start;
		size_t undo, redo, length;
	};

	typedef std::vector<TextCommandInfo> VectorChangeInfo;
	typedef std::deque<VectorChangeInfo> DequeUndoRedoInfo;

} // namespace GUI

#endif // __TEXT_CHANGE_HISTORY_H__

