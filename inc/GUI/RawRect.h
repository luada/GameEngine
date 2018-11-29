#ifndef __RAW_RECT_H__
#define __RAW_RECT_H__

#include "Prerequest.h"
#include "Colour.h"
#include "XmlDocument.h"
#include "Types.h"
#include "ICroppedRectangle.h"
#include "SubSkin.h"
#include "RenderFormat.h"

namespace GUI
{

	class GUI_EXPORT RawRect : public SubSkin
	{
		RTTI_DERIVED(RawRect)

	public:
		RawRect();
		virtual ~RawRect();

		virtual void SetAlpha(float alpha);

		void SetRectColour(const Colour& colourLT, const Colour& colourRT, const Colour& colourLB, const Colour& colourRB);

		void SetRectTexture(const FloatPoint& pointLT, const FloatPoint& pointRT, const FloatPoint& pointLB, const FloatPoint& pointRB);

		virtual void SetStateData(IStateInfo * data);

		virtual void DoRender();

	private:
		FloatPoint mRectTextureLT;
		FloatPoint mRectTextureRT;
		FloatPoint mRectTextureLB;
		FloatPoint mRectTextureRB;

		Colour mColourLT;
		Colour mColourRT;
		Colour mColourLB;
		Colour mColourRB;

		uint32 mRenderColourLT;
		uint32 mRenderColourRT;
		uint32 mRenderColourLB;
		uint32 mRenderColourRB;

		VertexColourType mVertexFormat;
	};

} // namespace GUI

#endif // __RAW_RECT_H__

