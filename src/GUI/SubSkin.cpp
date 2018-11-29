#include "Precompiled.h"
#include "SubSkin.h"
#include "RenderItem.h"
#include "SkinManager.h"
#include "LanguageManager.h"
#include "LayerNode.h"
#include "CommonStateInfo.h"
#include "RenderManager.h"
#include "TextureUtility.h"

namespace GUI
{

	SubSkin::SubSkin() :
		ISubWidgetRect(),
		mEmptyView(false),
		mCurrentColour(0xFFFFFFFF),
		mNode(nullptr),
		mRenderItem(nullptr)
	{
	}

	SubSkin::~SubSkin()
	{
	}

	void SubSkin::SetVisible(bool visible)
	{
		if (mVisible == visible) return;
		mVisible = visible;

		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	void SubSkin::SetAlpha(float alpha)
	{
		uint32 curAlpha = ((uint8)(alpha*255) << 24);
		mCurrentColour = (mCurrentColour & 0x00FFFFFF) | (curAlpha & 0xFF000000);

		if (nullptr != mNode)
			mNode->OutOfDate(mRenderItem);
	}

	void SubSkin::_correctView()
	{
		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	void SubSkin::_setAlign(const IntCoord& oldcoord, bool update)
	{
		_setAlign(oldcoord.Size(), update);
	}

	void SubSkin::_setAlign(const IntSize& oldsize, bool update)
	{
		bool need_update = true;//update;

		if (mAlign.IsHStretch())
		{
			mCoord.width = mCoord.width + (mCroppedParent->GetWidth() - oldsize.width);
			need_update = true;
			mIsMargin = true; 
		}
		else if (mAlign.IsRight())
		{
			mCoord.left = mCoord.left + (mCroppedParent->GetWidth() - oldsize.width);
			need_update = true;
		}
		else if (mAlign.IsHCenter())
		{
			mCoord.left = (mCroppedParent->GetWidth() - mCoord.width) / 2;
			need_update = true;
		}

		if (mAlign.IsVStretch())
		{
			mCoord.height = mCoord.height + (mCroppedParent->GetHeight() - oldsize.height);
			need_update = true;
			mIsMargin = true; 
		}
		else if (mAlign.IsBottom())
		{
			mCoord.top = mCoord.top + (mCroppedParent->GetHeight() - oldsize.height);
			need_update = true;
		}
		else if (mAlign.IsVCenter())
		{
			mCoord.top = (mCroppedParent->GetHeight() - mCoord.height) / 2;
			need_update = true;
		}

		if (need_update)
		{
			mCurrentCoord = mCoord;
			_updateView();
		}

	}

	void SubSkin::_updateView()
	{
		//mAbsolutePosition = mCroppedParent->GetAbsolutePosition() + mCoord.Point();
		bool margin = _checkMargin();

		mEmptyView = ((0 >= _getViewWidth()) || (0 >= _getViewHeight()));

		mCurrentCoord.left = mCoord.left + mMargin.left;
		mCurrentCoord.top = mCoord.top + mMargin.top;

		if (margin)
		{
			if (_checkOutside())
			{

				mIsMargin = margin;

				if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
				return;
			}
		}

		if ( mIsMargin || margin )
		{
			mCurrentCoord.width = _getViewWidth();
			mCurrentCoord.height = _getViewHeight();

			if ( (mCurrentCoord.width > 0) && (mCurrentCoord.height > 0) )
			{
				float UV_lft = mMargin.left / (float)mCoord.width;
				float UV_top = mMargin.top / (float)mCoord.height;
				float UV_rgt = (mCoord.width - mMargin.right) / (float)mCoord.width;
				float UV_btm = (mCoord.height - mMargin.bottom) / (float)mCoord.height;

				float UV_sizeX = mRectTexture.right - mRectTexture.left;
				float UV_sizeY = mRectTexture.bottom - mRectTexture.top;

				float UV_lft_total = mRectTexture.left + UV_lft * UV_sizeX;
				float UV_top_total = mRectTexture.top + UV_top * UV_sizeY;
				float UV_rgt_total = mRectTexture.right - (1-UV_rgt) * UV_sizeX;
				float UV_btm_total = mRectTexture.bottom - (1-UV_btm) * UV_sizeY;

				mCurrentTexture.Set(UV_lft_total, UV_top_total, UV_rgt_total, UV_btm_total);
			}
		}

		if (mIsMargin && !margin)
		{
			mCurrentTexture = mRectTexture;
		}

		mIsMargin = margin;

		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	void SubSkin::CreateDrawItem(ITexture* texture, ILayerNode * node)
	{
		ASSERT(!mRenderItem, "mRenderItem must be nullptr");

		mNode = node;
		mRenderItem = mNode->AddToRenderItem(texture, this);
		mRenderItem->AddDrawItem(this, VertexQuad::VertexCount);
	}

	void SubSkin::DestroyDrawItem()
	{
		ASSERT(mRenderItem, "mRenderItem must be not nullptr");

		mNode = nullptr;
		mRenderItem->RemoveDrawItem(this);
		mRenderItem = nullptr;
	}

	void SubSkin::_setUVSet(const FloatRect& rect)
	{
		if (mRectTexture == rect) return;
		mRectTexture = rect;

		if (mIsMargin)
		{
			float UV_lft = mMargin.left / (float)mCoord.width;
			float UV_top = mMargin.top / (float)mCoord.height;
			float UV_rgt = (mCoord.width - mMargin.right) / (float)mCoord.width;
			float UV_btm = (mCoord.height - mMargin.bottom) / (float)mCoord.height;

			float UV_sizeX = mRectTexture.right - mRectTexture.left;
			float UV_sizeY = mRectTexture.bottom - mRectTexture.top;

			float UV_lft_total = mRectTexture.left + UV_lft * UV_sizeX;
			float UV_top_total = mRectTexture.top + UV_top * UV_sizeY;
			float UV_rgt_total = mRectTexture.right - (1-UV_rgt) * UV_sizeX;
			float UV_btm_total = mRectTexture.bottom - (1-UV_btm) * UV_sizeY;

			mCurrentTexture.Set(UV_lft_total, UV_top_total, UV_rgt_total, UV_btm_total);
		}

		else
		{
			mCurrentTexture = mRectTexture;
		}

		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	void SubSkin::DoRender()
	{
		if (!mVisible || mEmptyView) return;

		VertexQuad* quad = (VertexQuad*)mRenderItem->GetCurrentVertextBuffer();

		const RenderTargetInfo& info = mRenderItem->GetRenderTarget()->GetInfo();

		float vertex_z = info.maximumDepth;

		float vertex_left = ((info.pixScaleX * (float)(mCurrentCoord.left + mCroppedParent->GetAbsoluteLeft() - info.leftOffset) + info.hOffset) * 2) - 1;
		float vertex_right = vertex_left + (info.pixScaleX * (float)mCurrentCoord.width * 2);
		float vertex_top = -(((info.pixScaleY * (float)(mCurrentCoord.top + mCroppedParent->GetAbsoluteTop() - info.topOffset) + info.vOffset) * 2) - 1);
		float vertex_bottom = vertex_top - (info.pixScaleY * (float)mCurrentCoord.height * 2);

		quad->set(
			vertex_left,
			vertex_top,
			vertex_right,
			vertex_bottom,
			vertex_z,
			mCurrentTexture.left,
			mCurrentTexture.top,
			mCurrentTexture.right,
			mCurrentTexture.bottom,
			mCurrentColour
			);

		mRenderItem->SetLastVertexCount(VertexQuad::VertexCount);
	}

	void SubSkin::_setColour(const Colour& value)
	{
		uint32 colour = texture_utility::ToColourARGB(value);
		texture_utility::ConvertColour(colour, RenderManager::GetInstance().GetVertexFormat());
		mCurrentColour = (colour & 0x00FFFFFF) | (mCurrentColour & 0xFF000000);

		if (nullptr != mNode)
			mNode->OutOfDate(mRenderItem);
	}

	void SubSkin::SetStateData(IStateInfo* data)
	{
		_setUVSet(data->CastType<SubSkinStateInfo>()->GetRect());
	}

} // namespace GUI


