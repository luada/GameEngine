#include "Precompiled.h"
#include "TileRect.h"
#include "RenderItem.h"
#include "SkinManager.h"
#include "LanguageManager.h"
#include "LayerNode.h"
#include "CommonStateInfo.h"
#include "RenderManager.h"
#include "TextureUtility.h"

namespace GUI
{

	const size_t TILERECT_COUNT_VERTEX = 16 * VertexQuad::VertexCount;

	TileRect::TileRect() :
		mEmptyView(false),
		mCurrentColour(0xFFFFFFFF),
		mNode(nullptr),
		mRenderItem(nullptr),
		mCountVertex(TILERECT_COUNT_VERTEX),
		mRealTileWidth(0),
		mRealTileHeight(0),
		mTextureHeightOne(0),
		mTextureWidthOne(0),
		mTileH(true),
		mTileV(true)
	{
	}

	TileRect::~TileRect()
	{
	}

	void TileRect::SetVisible(bool visible)
	{
		if (mVisible == visible) return;
		mVisible = visible;

		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	void TileRect::SetAlpha(float alpha)
	{
		uint32 curAlpha = ((uint8)(alpha*255) << 24);
		mCurrentColour = (mCurrentColour & 0x00FFFFFF) | (curAlpha & 0xFF000000);

		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	void TileRect::_correctView()
	{
		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	void TileRect::_setAlign(const IntCoord& oldcoord, bool update)
	{
		_setAlign(oldcoord.Size(), update);
	}

	void TileRect::_setAlign(const IntSize& oldsize, bool update)
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
			if (!mTileH) mTileSize.width = mCoord.width;
			if (!mTileV) mTileSize.height = mCoord.height;
			_updateView();
		}

	}

	void TileRect::_updateView()
	{
		bool margin = _checkMargin();

		mEmptyView = ((0 >= _getViewWidth()) || (0 >= _getViewHeight()));

		mCurrentCoord.left = mCoord.left + mMargin.left;
		mCurrentCoord.top = mCoord.top + mMargin.top;
		mCurrentCoord.width = _getViewWidth();
		mCurrentCoord.height = _getViewHeight();

		if (!mEmptyView)
		{
			size_t count = 0;
			if (!mTileSize.Empty())
			{
				size_t count_x = mCoord.width / mTileSize.width;
				if ((mCoord.width % mTileSize.width) > 0) count_x ++;
				size_t count_y = mCoord.height / mTileSize.height;
				if ((mCoord.height % mTileSize.height) > 0) count_y ++;
				count = count_y * count_x * VertexQuad::VertexCount;
			}

			if (count > mCountVertex)
			{
				mCountVertex = count + TILERECT_COUNT_VERTEX;
				if (nullptr != mRenderItem) mRenderItem->ReallockDrawItem(this, mCountVertex);
			}
		}

		if (margin)
		{
			if (_checkOutside())
			{
				mIsMargin = margin;

				if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
				return;
			}
		}

		mIsMargin = margin;

		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	void TileRect::_setUVSet(const FloatRect& rect)
	{
		mCurrentTexture = rect;
		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	void TileRect::DoRender()
	{
		if (!mVisible || mEmptyView || mTileSize.Empty()) return;

		VertexQuad* quad = (VertexQuad*)mRenderItem->GetCurrentVertextBuffer();

		const RenderTargetInfo& info = mRenderItem->GetRenderTarget()->GetInfo();

		mRealTileWidth = info.pixScaleX * (float)(mTileSize.width) * 2;
		mRealTileHeight = info.pixScaleY * (float)(mTileSize.height) * 2;

		mTextureHeightOne = (mCurrentTexture.bottom - mCurrentTexture.top) / mRealTileHeight;
		mTextureWidthOne = (mCurrentTexture.right - mCurrentTexture.left) / mRealTileWidth;

		float vertex_z = info.maximumDepth;

		float window_left = ((info.pixScaleX * (float)(mCoord.left + mCroppedParent->GetAbsoluteLeft() - info.leftOffset) + info.hOffset) * 2) - 1;
		float window_top = -(((info.pixScaleY * (float)(mCoord.top + mCroppedParent->GetAbsoluteTop() - info.topOffset) + info.vOffset) * 2) - 1);

		float real_left = ((info.pixScaleX * (float)(mCurrentCoord.left + mCroppedParent->GetAbsoluteLeft() - info.leftOffset) + info.hOffset) * 2) - 1;
		float real_right = real_left + (info.pixScaleX * (float)mCurrentCoord.width * 2);
		float real_top = -(((info.pixScaleY * (float)(mCurrentCoord.top + mCroppedParent->GetAbsoluteTop() - info.topOffset) + info.vOffset) * 2) - 1);
		float real_bottom = real_top - (info.pixScaleY * (float)mCurrentCoord.height * 2);

		size_t count = 0;

		float left = window_left;
		float right = window_left;
		float top = window_top;
		float bottom = window_top;

		for (int y=0; y<mCoord.height; y+=mTileSize.height)
		{
			top = bottom;
			bottom -= mRealTileHeight;
			right = window_left;

			float vertex_top = top;
			float vertex_bottom = bottom;
			bool texture_crop_height  = false;

			if (vertex_top > real_top)
			{
				if (vertex_bottom > real_top)
				{
					continue;
				}
				vertex_top = real_top;
				texture_crop_height = true;
			}
			if (vertex_bottom < real_bottom)
			{
				if (vertex_top < real_bottom)
				{
					continue;
				}
				vertex_bottom = real_bottom;
				texture_crop_height = true;
			}

			for (int x=0; x<mCoord.width; x+=mTileSize.width)
			{
				left = right;
				right += mRealTileWidth;

				float vertex_left = left;
				float vertex_right = right;
				bool texture_crop_width  = false;


				if (vertex_left < real_left)
				{
					if (vertex_right < real_left)
					{
						continue;
					}
					vertex_left = real_left;
					texture_crop_width = true;
				}

				if (vertex_right > real_right)
				{
					if (vertex_left > real_right)
					{
						continue;
					}
					vertex_right = real_right;
					texture_crop_width = true;
				}

				float texture_left = mCurrentTexture.left;
				float texture_right = mCurrentTexture.right;
				float texture_top = mCurrentTexture.top;
				float texture_bottom = mCurrentTexture.bottom;

				if (texture_crop_height)
				{
					texture_top += (top - vertex_top) * mTextureHeightOne;
					texture_bottom -= (vertex_bottom - bottom) * mTextureHeightOne;
				}

				if (texture_crop_width)
				{
					texture_left += (vertex_left - left) * mTextureWidthOne;
					texture_right -= (right - vertex_right) * mTextureWidthOne;
				}

				quad[count].set(
					vertex_left,
					vertex_top,
					vertex_right,
					vertex_bottom,
					vertex_z,
					texture_left,
					texture_top,
					texture_right,
					texture_bottom,
					mCurrentColour
					);

				count ++;
			}
		}

		mRenderItem->SetLastVertexCount(VertexQuad::VertexCount * count);
	}

	void TileRect::CreateDrawItem(ITexture* texture, ILayerNode * node)
	{
		ASSERT(!mRenderItem, "mRenderItem must be nullptr");

		mNode = node;
		mRenderItem = mNode->AddToRenderItem(texture, this);
		mRenderItem->AddDrawItem(this, mCountVertex);
	}

	void TileRect::DestroyDrawItem()
	{
		ASSERT(mRenderItem, "mRenderItem must be not nullptr");

		mNode = nullptr;
		mRenderItem->RemoveDrawItem(this);
		mRenderItem = nullptr;
	}

	void TileRect::SetStateData(IStateInfo* data)
	{
		TileRectStateInfo* curData = data->CastType<TileRectStateInfo>();

		mTileSize = curData->GetTileSize();
		mTileH = curData->GetTileH();
		mTileV = curData->GetTileV();
		_setUVSet(curData->GetRect());
	}

	void TileRect::_setColour(const Colour& value)
	{
		uint32 colour = texture_utility::ToColourARGB(value);
		texture_utility::ConvertColour(colour, RenderManager::GetInstance().GetVertexFormat());
		mCurrentColour = (colour & 0x00FFFFFF) | (mCurrentColour & 0xFF000000);

		if (nullptr != mNode)
			mNode->OutOfDate(mRenderItem);
	}

} // namespace GUI


