#ifndef __I_POINTER_H__
#define __I_POINTER_H__

#include "Prerequest.h"
#include "IResource.h"

namespace GUI
{

	class GUI_EXPORT IPointer : public IResource
	{
		RTTI_DERIVED(IPointer)

	public:
		IPointer() { }
		virtual ~IPointer() { }

		virtual void SetImage(StaticImage* image) = 0;
		virtual void SetPosition(StaticImage* image, const IntPoint& point) = 0;

	};

} // namespace GUI

#endif // __I_POINTER_H__
