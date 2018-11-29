#include "Precompiled.h"
#include "EditText.h"
#include "RenderItem.h"
#include "FontManager.h"
#include "RenderManager.h"
#include "LanguageManager.h"
#include "TextIterator.h"
#include "IRenderTarget.h"
#include "FontData.h"
#include "CommonStateInfo.h"

namespace GUI
{

	const size_t VERTEX_IN_QUAD = 6;
	const size_t SIMPLETEXT_COUNT_VERTEX = 32 * VERTEX_IN_QUAD;

	FORCEINLINE void DrawQuad(GUI::Vertex*& buff,
		float v_left,
		float v_top,
		float v_rignt,
		float v_bottom,
		float v_z,
		GUI::uint32 colour,
		float t_left,
		float t_top,
		float t_right,
		float t_bottom,
		size_t& count)
	{
		buff[0].x = v_left;
		buff[0].y = v_top;
		buff[0].z = v_z;
		buff[0].colour = colour;
		buff[0].u = t_left;
		buff[0].v = t_top;

		buff[1].x = v_left;
		buff[1].y = v_bottom;
		buff[1].z = v_z;
		buff[1].colour = colour;
		buff[1].u = t_left;
		buff[1].v = t_bottom;

		buff[2].x = v_rignt;
		buff[2].y = v_top;
		buff[2].z = v_z;
		buff[2].colour = colour;
		buff[2].u = t_right;
		buff[2].v = t_top;

		buff[3].x = v_rignt;
		buff[3].y = v_top;
		buff[3].z = v_z;
		buff[3].colour = colour;
		buff[3].u = t_right;
		buff[3].v = t_top;

		buff[4].x = v_left;
		buff[4].y = v_bottom;
		buff[4].z = v_z;
		buff[4].colour = colour;
		buff[4].u = t_left;
		buff[4].v = t_bottom;

		buff[5].x = v_rignt;
		buff[5].y = v_bottom;
		buff[5].z = v_z;
		buff[5].colour = colour;
		buff[5].u = t_right;
		buff[5].v = t_bottom;

		buff += VERTEX_IN_QUAD;
		count += VERTEX_IN_QUAD;
	}

	EditText::EditText() :
		ISubWidgetText(),
		mEmptyView(false),
		mCurrentColour(0x00FFFFFF),
		mInverseColour(0x00000000),
		mCurrentAlpha(0xFF000000),
		mTextOutDate(false),
		mTextAlign(Align::Default),
		mColour(Colour::White),
		mAlpha(ALPHA_MAX),
		mFont(nullptr),
		mTexture(nullptr),
		mFontHeight(0),
		mBackgroundNormal(true),
		mStartSelect(0),
		mEndSelect(0),
		mCursorPosition(0),
		mVisibleCursor(false),
		mInvertSelect(true),
		mNode(nullptr),
		mRenderItem(nullptr),
		mCountVertex(SIMPLETEXT_COUNT_VERTEX),
		mIsAddCursorWidth(true),
		mShiftText(false),
		mWordWrap(false),
		mOldWidth(0)
	{
		mVertexFormat = RenderManager::GetInstance().GetVertexFormat();

		mCurrentColour = texture_utility::ToColourARGB(mColour);
		texture_utility::ConvertColour(mCurrentColour, mVertexFormat);

		mCurrentColour = (mCurrentColour & 0x00FFFFFF) | mCurrentAlpha;
		mInverseColour = mCurrentColour ^ 0x00FFFFFF;
	}

	EditText::~EditText()
	{
	}

	void EditText::SetVisible(bool visible)
	{
		if (mVisible == visible) return;
		mVisible = visible;

		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	void EditText::_correctView()
	{
		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	void EditText::_setAlign(const IntCoord& oldcoord, bool update)
	{
		_setAlign(oldcoord.Size(), update);
	}

	void EditText::_setAlign(const IntSize& oldsize, bool update)
	{

		if (mWordWrap)
		{
			int width = mCroppedParent->GetWidth();
			if (mOldWidth != width)
			{
				mOldWidth = width;
				mTextOutDate = true;
			}
		}

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

	void EditText::_updateView()
	{
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

		if ((mIsMargin) || (margin))
		{
			mCurrentCoord.width = _getViewWidth();
			mCurrentCoord.height = _getViewHeight();
		}

		mIsMargin = margin;

		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	void EditText::SetCaption(const UString& value)
	{
		mCaption = value;
		mTextOutDate = true;

		size_t need = (mCaption.size() * 2 + 2) * VERTEX_IN_QUAD;
		if (mCountVertex < need)
		{
			mCountVertex = need + SIMPLETEXT_COUNT_VERTEX;
			if (nullptr != mRenderItem) mRenderItem->ReallockDrawItem(this, mCountVertex);
		}
		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	const UString& EditText::GetCaption()
	{
		return mCaption;
	}

	void EditText::SetTextColour(const Colour& value)
	{
		if (mColour == value) return;
		mColour = value;
		mCurrentColour = texture_utility::ToColourARGB(mColour);

		texture_utility::ConvertColour(mCurrentColour, mVertexFormat);

		mCurrentColour = (mCurrentColour & 0x00FFFFFF) | mCurrentAlpha;
		mInverseColour = mCurrentColour ^ 0x00FFFFFF;

		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	const Colour& EditText::GetTextColour()
	{
		return mColour;
	}

	void EditText::SetAlpha(float value)
	{
		if (mAlpha == value) return;
		mAlpha = value;
		mCurrentAlpha = ((uint8)(mAlpha*255) << 24);
		mCurrentColour = (mCurrentColour & 0x00FFFFFF) | mCurrentAlpha;
		mInverseColour = mCurrentColour ^ 0x00FFFFFF;

		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	float EditText::GetAlpha()
	{
		return mAlpha;
	}

	void EditText::SetFontName(const std::string& value)
	{
		mTexture = 0;
		mFont = FontManager::GetInstance().GetByName(value);
		if (mFont != nullptr)
		{
			mTexture = mFont->GetTextureFont();

			if (mFont->GetDefaultHeight() != 0)
			{
				mFontHeight = mFont->GetDefaultHeight();
			}
		}

		mTextOutDate = true;

		if (nullptr != mRenderItem)
		{
			mRenderItem->RemoveDrawItem(this);
			mRenderItem = nullptr;
		}

		if (nullptr != mTexture && nullptr != mNode)
		{
			mRenderItem = mNode->AddToRenderItem(mTexture, this);
			mRenderItem->AddDrawItem(this, mCountVertex);
		}

		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	const std::string& EditText::GetFontName()
	{
		return mFont->GetResourceName();
	}

	void EditText::SetFontHeight(int value)
	{
		mFontHeight = value;
		mTextOutDate = true;
		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	int EditText::GetFontHeight()
	{
		return mFontHeight;
	}

	void EditText::CreateDrawItem(ITexture* texture, ILayerNode * node)
	{
		mNode = node;
		if (nullptr != mTexture)
		{
			ASSERT(!mRenderItem, "mRenderItem must be nullptr");

			mRenderItem = mNode->AddToRenderItem(mTexture, this);
			mRenderItem->AddDrawItem(this, mCountVertex);
		}
	}

	void EditText::DestroyDrawItem()
	{
		if (nullptr != mRenderItem)
		{
			mRenderItem->RemoveDrawItem(this);
			mRenderItem = nullptr;
		}
		mNode = nullptr;
	}

	size_t EditText::GetTextSelectionStart()
	{
		return mStartSelect;
	}

	size_t EditText::GetTextSelectionEnd()
	{
		return mEndSelect;
	}

	void EditText::SetTextSelection(size_t start, size_t end)
	{
		mStartSelect=start;
		mEndSelect=end;
		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	bool EditText::GetSelectBackground()
	{
		return mBackgroundNormal;
	}

	void EditText::SetSelectBackground(bool normal)
	{
		if (mBackgroundNormal == normal) return;
		mBackgroundNormal = normal;
		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	bool EditText::IsVisibleCursor()
	{
		return mVisibleCursor;
	}

	void EditText::SetVisibleCursor(bool value)
	{
		if (mVisibleCursor == value) return;
		mVisibleCursor = value;
		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	size_t EditText::GetCursorPosition()
	{
		return mCursorPosition;
	}

	void EditText::SetCursorPosition(size_t index)
	{
		if (mCursorPosition == index) return;
		mCursorPosition = index;
		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	void EditText::SetTextAlign(Align value)
	{
		mTextAlign = value;
		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	Align EditText::GetTextAlign()
	{
		return mTextAlign;
	}

	IntSize EditText::GetTextSize()
	{
		if (mTextOutDate) UpdateRawData();

		IntSize size = mTextView.GetViewSize();
		if (mIsAddCursorWidth)
			size.width += 2;
		return size;
	}

	void EditText::SetViewOffset(const IntPoint& point)
	{
		mViewOffset = point;
		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	IntPoint EditText::GetViewOffset()
	{
		return mViewOffset;
	}

	size_t EditText::GetCursorPosition(const IntPoint& point)
	{
		if (nullptr == mFont) return 0;
		if (mTextOutDate) UpdateRawData();

		IntPoint curPoint = point;
		curPoint -= mCroppedParent->GetAbsolutePosition();
		curPoint += mViewOffset;
		curPoint -= mCoord.Point();

		return mTextView.GetCursorPosition(curPoint);
	}

	IntCoord EditText::GetCursorCoord(size_t position)
	{
		if (nullptr == mFont) return IntCoord();
		if (mTextOutDate) UpdateRawData();

		IntPoint point = mTextView.GetCursorPoint(position);
		point += mCroppedParent->GetAbsolutePosition();
		point -= mViewOffset;
		point += mCoord.Point();

		return IntCoord(point.left, point.top, 2, mFontHeight);
	}

	void EditText::SetShiftText(bool value)
	{
		if (mShiftText == value) return;
		mShiftText = value;
		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	void EditText::SetWordWrap(bool value)
	{
		mWordWrap = value;
		mTextOutDate = true;
		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

	void EditText::UpdateRawData()
	{
		if (nullptr == mFont) return;
		mTextOutDate = false;

		int width = -1;
		if (mWordWrap)
		{
			width = mCoord.width;
			if (mIsAddCursorWidth)
				width -= 2;
		}

		mTextView.Update(mCaption, mFont, mFontHeight, mTextAlign, mVertexFormat, width);
	}

	void EditText::SetStateData(IStateInfo* data)
	{
		EditTextStateInfo* curData = data->CastType<EditTextStateInfo>();
		if (curData->GetColour() != Colour::Zero) SetTextColour(curData->GetColour());
		SetShiftText(curData->GetShift());
	}

	void EditText::DoRender()
	{
		if (nullptr == mFont) return;
		if (!mVisible || mEmptyView) return;

		bool _update = mRenderItem->GetCurrentUpdate();
		if (_update) mTextOutDate = true;

		if (mTextOutDate) UpdateRawData();

		Vertex* _vertex = mRenderItem->GetCurrentVertextBuffer();

		const RenderTargetInfo& info = mRenderItem->GetRenderTarget()->GetInfo();

		size_t vertex_count = 0;

		uint32 colour_current = mCurrentColour;
		uint32 colour = mCurrentColour;
		uint32 colour_inverse = mInverseColour;

		GlyphInfo* back_glyph = mFont->GetGlyphInfo(mBackgroundNormal ? FontCodeType::Selected : FontCodeType::SelectedBack);

		float vertex_z = info.maximumDepth;

		const VectorLineInfo& data = mTextView.GetData();

		int left = - mViewOffset.left + mCoord.left;
		int top = - mViewOffset.top + mCoord.top;
		int width = 0;
		const int height = mFontHeight;

		size_t index = 0;
		for (VectorLineInfo::const_iterator line=data.begin(); line!=data.end(); ++line)
		{
			left = line->offset - mViewOffset.left + mCoord.left;
			for (VectorCharInfo::const_iterator sim=line->simbols.begin(); sim!=line->simbols.end(); ++sim)
			{
				if (sim->IsColour())
				{
					colour = sim->GetColour() | (colour & 0xFF000000);
					colour_inverse = colour ^ 0x00FFFFFF;
					continue;
				}

				bool select = !((index >= mEndSelect) || (index < mStartSelect));

				uint32 back_colour = 0;

				if (!select || !mInvertSelect)
				{
					colour_current = colour;
					back_colour = colour | 0x00FFFFFF;
				}
				else
				{
					colour_current = colour_inverse;
					back_colour = colour_inverse;
				}

				bool draw = true;

				GUI::FloatRect texture_rect = sim->GetUVRect();
				width = sim->GetWidth();

				int result_left = left;
				int result_top = top;
				int result_right = left + width;
				int result_bottom = top + height;

				float texture_width = texture_rect.right - texture_rect.left;
				float texture_height = texture_rect.bottom - texture_rect.top;

				if (left < mCurrentCoord.left)
				{
					if (left + width <= mCurrentCoord.left)
					{
						draw = false;
					}
					else
					{
						result_left = mCurrentCoord.left;
						texture_rect.left += (texture_width * (float)(result_left - left) / (float)width);
					}
				}

				if (left + width > mCurrentCoord.Right())
				{
					if (left >= mCurrentCoord.Right())
					{
						draw = false;
					}
					else
					{
						result_right = mCurrentCoord.Right();
						texture_rect.right -= (texture_width * (float)((left + width) - result_right) / (float)width);
					}
				}

				if (top < mCurrentCoord.top)
				{
					if (top + height <= mCurrentCoord.top)
					{
						draw = false;
					}
					else
					{
						result_top = mCurrentCoord.top;
						texture_rect.top += (texture_height * (float)(result_top - top) / (float)height);
					}
				}

				if (top + height > mCurrentCoord.Bottom())
				{
					if (top >= mCurrentCoord.Bottom())
					{
						draw = false;
					}
					else
					{
						result_bottom = mCurrentCoord.Bottom();
						texture_rect.bottom -= (texture_height * (float)((top + height) - result_bottom) / (float)height);
					}
				}

				if (draw)
				{
					int pix_left = mCroppedParent->GetAbsoluteLeft() - info.leftOffset + result_left;
					int pix_top = mCroppedParent->GetAbsoluteTop() - info.topOffset + (mShiftText ? 1 : 0) + result_top;

					float real_left = ((info.pixScaleX * (float)(pix_left) + info.hOffset) * 2) - 1;
					float real_top = - (((info.pixScaleY * (float)(pix_top) + info.vOffset) * 2) - 1);
					float real_right = ((info.pixScaleX * (float)(pix_left + result_right - result_left) + info.hOffset) * 2) - 1;
					float real_bottom = - (((info.pixScaleY * (float)(pix_top + result_bottom - result_top) + info.vOffset) * 2) - 1);

					if (select)
					{
						const FloatRect& background_current = back_glyph->uvRect;
						DrawQuad(_vertex, real_left, real_top, real_right, real_bottom, vertex_z, back_colour,
							background_current.left, background_current.top, background_current.left, background_current.top, vertex_count);
					}

					DrawQuad(_vertex, real_left, real_top, real_right, real_bottom, vertex_z, colour_current,
						texture_rect.left, texture_rect.top, texture_rect.right, texture_rect.bottom, vertex_count);
				}

				left += width;
				index++;
			}

			top += height;
			index++;
		}

		if (mVisibleCursor)
		{
			GUI::IntPoint point = mTextView.GetCursorPoint(mCursorPosition);
			point -= mViewOffset;
			point += mCoord.Point();

			bool draw = true;

			GlyphInfo* cursor_glyph = mFont->GetGlyphInfo(FontCodeType::Cursor);
			GUI::FloatRect texture_rect = cursor_glyph->uvRect;
			left = point.left;
			top = point.top;
			width = 2;//cursor_glyph->width;

			int result_left = left;
			int result_top = top;
			int result_width = width;
			int result_height = height;

			if (left < mCurrentCoord.left)
			{
				if (left + width <= mCurrentCoord.left)
				{
					draw = false;
				}
				else
				{
					result_left = mCurrentCoord.left;
					result_width = width - (mCurrentCoord.left - left);

					float texture_width = texture_rect.right - texture_rect.left;
					texture_rect.left = texture_rect.right - (texture_width * (float)result_width / (float)width);
				}
			}

			if (left + width > mCurrentCoord.Right())
			{
				if (left >= mCurrentCoord.Right())
				{
					draw = false;
				}
				else
				{
					result_width = mCurrentCoord.Right() - left;

					float texture_width = texture_rect.right - texture_rect.left;
					texture_rect.right = texture_rect.left + (texture_width * (float)result_width / (float)width);
				}
			}

			if (top < mCurrentCoord.top)
			{
				if (top + height <= mCurrentCoord.top)
				{
					draw = false;
				}
				else
				{
					result_top = mCurrentCoord.top;
					result_height = height - (mCurrentCoord.top - top);

					float texture_height = texture_rect.bottom - texture_rect.top;
					texture_rect.top = texture_rect.bottom - (texture_height * (float)result_height / (float)height);
				}
			}

			if (top + height > mCurrentCoord.Bottom())
			{
				if (top >= mCurrentCoord.Bottom())
				{
					draw = false;
				}
				else
				{
					result_height = mCurrentCoord.Bottom() - top;

					float texture_height = texture_rect.bottom - texture_rect.top;
					texture_rect.bottom = texture_rect.top + (texture_height * (float)result_height / (float)height);
				}
			}

			if (draw)
			{
				int pix_left = mCroppedParent->GetAbsoluteLeft() - info.leftOffset + result_left;
				int pix_top = mCroppedParent->GetAbsoluteTop() - info.topOffset + (mShiftText ? 1 : 0) + result_top;

				float real_left = ((info.pixScaleX * (float)(pix_left) + info.hOffset) * 2) - 1;
				float real_top = - (((info.pixScaleY * (float)(pix_top) + info.vOffset) * 2) - 1);
				float real_right = ((info.pixScaleX * (float)(pix_left + result_width) + info.hOffset) * 2) - 1;
				float real_bottom = - (((info.pixScaleY * (float)(pix_top + result_height) + info.vOffset) * 2) - 1);

				DrawQuad(_vertex, real_left, real_top, real_right, real_bottom, vertex_z, colour_current | 0x00FFFFFF,
					texture_rect.left, texture_rect.top, texture_rect.right, texture_rect.bottom, vertex_count);
			}
		}

		mRenderItem->SetLastVertexCount(vertex_count);
	}

	void EditText::SetInvertSelected(bool value)
	{
		if (mInvertSelect == value) return;
		mInvertSelect = value;
		if (nullptr != mNode) mNode->OutOfDate(mRenderItem);
	}

} // namespace GUI


