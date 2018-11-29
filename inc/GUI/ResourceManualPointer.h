#ifndef __RESOURCE_MANUAL_POINTER_H__
#define __RESOURCE_MANUAL_POINTER_H__

#include "Prerequest.h"
#include "IPointer.h"

namespace GUI
{

	class GUI_EXPORT ResourceManualPointer :
		public IPointer
	{
		RTTI_DERIVED(ResourceManualPointer)

	public:
		ResourceManualPointer() { }
		virtual ~ResourceManualPointer() { }

		virtual void Deserialization(xml::ElementPtr node, Version version);

		virtual void SetImage(StaticImage* image);
		virtual void SetPosition(StaticImage* image, const IntPoint& point);

	private:
		IntPoint mPoint;
		IntSize mSize;
		FloatRect mOffset;
		std::string mTexture;
	};

} // namespace GUI

#endif // __RESOURCE_MANUAL_POINTER_H__
