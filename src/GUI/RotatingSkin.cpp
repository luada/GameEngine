#include "Precompiled.h"
#include "RotatingSkin.h"
#include "RenderItem.h"
#include "CommonStateInfo.h"

namespace GUI
{

	RotatingSkin::RotatingSkin() :
		SubSkin(),
		mAngle(0.0f),
		mLocalCenter(false)
	{
		for (int i = 0; i<4; ++i)
		{
			mBaseAngles[i] = 0.0f;
			mBaseDistances[i] = 0.0f;
		}
	}

	RotatingSkin::~RotatingSkin()
	{
	}

	void RotatingSkin::SetAngle(float angle)
	{
		mAngle = angle;
		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	void RotatingSkin::SetCenter(const IntPoint &_center, bool local)
	{
		mCenterPos = _center;
		mLocalCenter = local;
		RecalculateAngles();
		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	IntPoint RotatingSkin::GetCenter(bool local) const
	{
		return mCenterPos + (local ? IntPoint() : mCroppedParent->GetAbsolutePosition());
	}

	void RotatingSkin::DoRender()
	{
		if ((!mVisible) || mEmptyView) return;

		VertexQuad* quad = (VertexQuad*)mRenderItem->GetCurrentVertextBuffer();

		const RenderTargetInfo& info = mRenderItem->GetRenderTarget()->GetInfo();

		float vertex_z = info.maximumDepth;

		float vertex_left_base = ((info.pixScaleX * (float)(mCurrentCoord.left + mCroppedParent->GetAbsoluteLeft() + mCenterPos.left) + info.hOffset) * 2) - 1;
		float vertex_top_base = -(((info.pixScaleY * (float)(mCurrentCoord.top + mCroppedParent->GetAbsoluteTop() + mCenterPos.top) + info.vOffset) * 2) - 1);

		// FIXME: do it only when size changes
		RecalculateAngles();

		quad->set(
			vertex_left_base + cos(-mAngle + mBaseAngles[0]) * mBaseDistances[0] * info.pixScaleX * -2,
			vertex_top_base + sin(-mAngle + mBaseAngles[0]) * mBaseDistances[0] * info.pixScaleY * -2,
			vertex_left_base + cos(-mAngle + mBaseAngles[3]) * mBaseDistances[3] * info.pixScaleX * -2,
			vertex_top_base + sin(-mAngle + mBaseAngles[3]) * mBaseDistances[3] * info.pixScaleY * -2,
			vertex_left_base + cos(-mAngle + mBaseAngles[2]) * mBaseDistances[2] * info.pixScaleX * -2,
			vertex_top_base + sin(-mAngle + mBaseAngles[2]) * mBaseDistances[2] * info.pixScaleY * -2,
			vertex_left_base + cos(-mAngle + mBaseAngles[1]) * mBaseDistances[1] * info.pixScaleX * -2,
			vertex_top_base + sin(-mAngle + mBaseAngles[1]) * mBaseDistances[1] * info.pixScaleY * -2,
			vertex_z,
			mCurrentTexture.left,
			mCurrentTexture.top,
			mCurrentTexture.right,
			mCurrentTexture.bottom,
			mCurrentColour
			);

		mRenderItem->SetLastVertexCount(VertexQuad::VertexCount);
	}

	inline float Len(float x, float y) { return sqrt(x*x + y*y); }

	void RotatingSkin::RecalculateAngles()
	{
#ifndef M_PI
		const float M_PI = 3.141593f;
#endif
		// FIXME mLocalCenter ignored
		float left_base = 0;
		float top_base = 0;

		if (!mLocalCenter)
		{
			left_base = (float)mCurrentCoord.width;
			top_base = (float)mCurrentCoord.height;
		}

		float width_base = (float)mCurrentCoord.width;
		float height_base = (float)mCurrentCoord.height;

		mBaseAngles[0] = atan2((float)           - mCenterPos.left,             - mCenterPos.top) + M_PI/2;
		mBaseAngles[1] = atan2((float)           - mCenterPos.left, height_base - mCenterPos.top) + M_PI/2;
		mBaseAngles[2] = atan2((float)width_base - mCenterPos.left, height_base - mCenterPos.top) + M_PI/2;
		mBaseAngles[3] = atan2((float)width_base - mCenterPos.left,             - mCenterPos.top) + M_PI/2;

		mBaseDistances[0] = Len((float)           - mCenterPos.left,             - mCenterPos.top);
		mBaseDistances[1] = Len((float)           - mCenterPos.left, height_base - mCenterPos.top);
		mBaseDistances[2] = Len((float)width_base - mCenterPos.left, height_base - mCenterPos.top);
		mBaseDistances[3] = Len((float)width_base - mCenterPos.left,             - mCenterPos.top);

	}

} // namespace GUI
