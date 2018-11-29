#ifndef __RENDER_TARGET_INFO_H__
#define __RENDER_TARGET_INFO_H__

#include "Prerequest.h"

namespace GUI
{

	struct GUI_EXPORT RenderTargetInfo
	{
		RenderTargetInfo() :
			maximumDepth(0),
			pixScaleX(1),
			pixScaleY(1),
			hOffset(0),
			vOffset(0),
			aspectCoef(1),
			leftOffset(0),
			topOffset(0)
		{
		}

		void SetOffset(int left, int top) const
		{
			leftOffset = left;
			topOffset = top;
		}

		float maximumDepth;
		float pixScaleX;
		float pixScaleY;
		float hOffset;
		float vOffset;
		float aspectCoef;

		mutable int leftOffset;
		mutable int topOffset;
	};


} // namespace GUI

#endif // __RENDER_TARGET_INFO_H__
