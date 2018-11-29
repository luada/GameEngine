#ifndef __RESOURCE_IMAGE_SET_POINTER_H__
#define __RESOURCE_IMAGE_SET_POINTER_H__

#include "Prerequest.h"
#include "IPointer.h"
#include "ResourceImageSet.h"

namespace GUI
{

	class GUI_EXPORT ResourceImageSetPointer : public IPointer
	{
		RTTI_DERIVED(ResourceImageSetPointer)

	public:
		ResourceImageSetPointer();
		virtual ~ResourceImageSetPointer() { }

		virtual void Deserialization(xml::ElementPtr node, Version version);

		virtual void SetImage(StaticImage* image);
		virtual void SetPosition(StaticImage* image, const IntPoint& point);

	private:
		IntPoint mPoint;
		IntSize mSize;
		ResourceImageSetPtr mImageSet;
	};

} // namespace GUI

#endif // __RESOURCE_IMAGE_SET_POINTER_H__
