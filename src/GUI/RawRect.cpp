#include "Precompiled.h"
#include "RawRect.h"
#include "RenderItem.h"
#include "RenderManager.h"
#include "SkinManager.h"
#include "LanguageManager.h"
#include "CommonStateInfo.h"

namespace GUI
{

	FORCEINLINE void ConvertColour(uint32& colour, VertexColourType format)
	{
		if (format == VertexColourType::ColourABGR)
			colour = ((colour & 0x00FF0000) >> 16) | ((colour & 0x000000FF) << 16) | (colour & 0xFF00FF00);
	}

	RawRect::RawRect() :
		SubSkin(),
		mRectTextureLT(FloatPoint(0, 0)),
		mRectTextureRT(FloatPoint(1, 0)),
		mRectTextureLB(FloatPoint(0, 1)),
		mRectTextureRB(FloatPoint(1, 1)),
		mColourLT(Colour::White),
		mColourRT(Colour::White),
		mColourLB(Colour::White),
		mColourRB(Colour::White),
		mRenderColourLT(0xFFFFFFFF),
		mRenderColourRT(0xFFFFFFFF),
		mRenderColourLB(0xFFFFFFFF),
		mRenderColourRB(0xFFFFFFFF)
	{
		mVertexFormat = RenderManager::GetInstance().GetVertexFormat();
	}

	RawRect::~RawRect()
	{
	}

	void RawRect::SetAlpha(float alpha)
	{
		mCurrentColour = ((uint8)(alpha*255) << 24);

		mRenderColourLT = mCurrentColour | (mRenderColourLT & 0x00FFFFFF);
		mRenderColourRT = mCurrentColour | (mRenderColourRT & 0x00FFFFFF);
		mRenderColourLB = mCurrentColour | (mRenderColourLB & 0x00FFFFFF);
		mRenderColourRB = mCurrentColour | (mRenderColourRB & 0x00FFFFFF);

		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	void RawRect::SetRectColour(const Colour& colourLT, const Colour& colourRT, const Colour& colourLB, const Colour& colourRB)
	{
		mColourLT = colourLT;
		mRenderColourLT = texture_utility::ToColourARGB(mColourLT);
		ConvertColour(mRenderColourLT, mVertexFormat);
		mRenderColourLT = mCurrentColour | (mRenderColourLT & 0x00FFFFFF);

		mColourRT = colourRT;
		mRenderColourRT = texture_utility::ToColourARGB(mColourRT);
		ConvertColour(mRenderColourRT, mVertexFormat);
		mRenderColourRT = mCurrentColour | (mRenderColourRT & 0x00FFFFFF);

		mColourLB = colourLB;
		mRenderColourLB = texture_utility::ToColourARGB(mColourLB);
		ConvertColour(mRenderColourLB, mVertexFormat);
		mRenderColourLB = mCurrentColour | (mRenderColourLB & 0x00FFFFFF);

		mColourRB = colourRB;
		mRenderColourRB = texture_utility::ToColourARGB(mColourRB);
		ConvertColour(mRenderColourRB, mVertexFormat);
		mRenderColourRB = mCurrentColour | (mRenderColourRB & 0x00FFFFFF);

		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	void RawRect::SetRectTexture(const FloatPoint& pointLT, const FloatPoint& pointRT, const FloatPoint& pointLB, const FloatPoint& pointRB)
	{
		mRectTextureLT = pointLT;
		mRectTextureRT = pointRT;
		mRectTextureLB = pointLB;
		mRectTextureRB = pointRB;
	}

	void RawRect::DoRender()
	{
		if (!mVisible || mEmptyView) return;

		Vertex* _vertex = mRenderItem->GetCurrentVertextBuffer();

		const RenderTargetInfo& info = mRenderItem->GetRenderTarget()->GetInfo();

		float vertex_z = info.maximumDepth;

		float vertex_left = ((info.pixScaleX * (float)(mCurrentCoord.left + mCroppedParent->GetAbsoluteLeft() - info.leftOffset) + info.hOffset) * 2) - 1;
		float vertex_right = vertex_left + (info.pixScaleX * (float)mCurrentCoord.width * 2);
		float vertex_top = -(((info.pixScaleY * (float)(mCurrentCoord.top + mCroppedParent->GetAbsoluteTop() - info.topOffset) + info.vOffset) * 2) - 1);
		float vertex_bottom = vertex_top - (info.pixScaleY * (float)mCurrentCoord.height * 2);

		// first triangle - left top
		_vertex[0].x = vertex_left;
		_vertex[0].y = vertex_top;
		_vertex[0].z = vertex_z;
		_vertex[0].colour = mRenderColourLT;
		_vertex[0].u = mRectTextureLT.left;
		_vertex[0].v = mRectTextureLT.top;

		// first triangle - left bottom
		_vertex[1].x = vertex_left;
		_vertex[1].y = vertex_bottom;
		_vertex[1].z = vertex_z;
		_vertex[1].colour = mRenderColourLB;
		_vertex[1].u = mRectTextureLB.left;
		_vertex[1].v = mRectTextureLB.top;

		// first triangle - right top
		_vertex[2].x = vertex_right;
		_vertex[2].y = vertex_top;
		_vertex[2].z = vertex_z;
		_vertex[2].colour = mRenderColourRT;
		_vertex[2].u = mRectTextureRT.left;
		_vertex[2].v = mRectTextureRT.top;

		// second triangle - right top
		_vertex[3].x = vertex_right;
		_vertex[3].y = vertex_top;
		_vertex[3].z = vertex_z;
		_vertex[3].colour = mRenderColourRT;
		_vertex[3].u = mRectTextureRT.left;
		_vertex[3].v = mRectTextureRT.top;

		// second triangle = left bottom
		_vertex[4].x = vertex_left;
		_vertex[4].y = vertex_bottom;
		_vertex[4].z = vertex_z;
		_vertex[4].colour = mRenderColourLB;
		_vertex[4].u = mRectTextureLB.left;
		_vertex[4].v = mRectTextureLB.top;

		// second triangle - right botton
		_vertex[5].x = vertex_right;
		_vertex[5].y = vertex_bottom;
		_vertex[5].z = vertex_z;
		_vertex[5].colour = mRenderColourRB;
		_vertex[5].u = mRectTextureRB.left;
		_vertex[5].v = mRectTextureRB.top;

		mRenderItem->SetLastVertexCount(VertexQuad::VertexCount);
	}

	void RawRect::SetStateData(IStateInfo * data)
	{
		SubSkinStateInfo* curData = data->CastType<SubSkinStateInfo>();
		const FloatRect& rect = curData->GetRect();
		mRectTextureLT.Set(rect.left, rect.top);
		mRectTextureRT.Set(rect.right, rect.top);
		mRectTextureLB.Set(rect.left, rect.bottom);
		mRectTextureRB.Set(rect.right, rect.bottom);
	}

} // namespace GUI
