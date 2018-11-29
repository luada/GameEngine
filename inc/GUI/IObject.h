#ifndef __I_OBJECT_H__
#define __I_OBJECT_H__

#include "Prerequest.h"
#include "RTTI.h"

namespace GUI
{

	class GUI_EXPORT IObject
	{
		RTTI_BASE(IObject)

	public:
		virtual ~IObject() { }

	};

} // namespace GUI

#endif // __I_OBJECT_H__
