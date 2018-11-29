#ifndef __EDIT_TEXT_H__
#define __EDIT_TEXT_H__

#include "Prerequest.h"
#include "XmlDocument.h"
#include "Types.h"
#include "ISubWidgetText.h"
#include "IFont.h"
#include "ResourceSkin.h"
#include "RenderFormat.h"
#include "TextView.h"

namespace GUI
{

	class RenderItem;

	class GUI_EXPORT EditText : public ISubWidgetText
	{
		RTTI_DERIVED(EditText)

	public:
		EditText();
		virtual ~EditText();

		virtual void SetVisible(bool value);

		virtual void UpdateRawData();

		virtual void DoRender();

		void SetCaption(const UString& value);
		const UString& GetCaption();

		void SetTextColour(const Colour& value);
		const Colour& GetTextColour();

		void SetAlpha(float value);
		float GetAlpha();

		virtual void SetFontName(const std::string& value);
		virtual const std::string& GetFontName();

		virtual void SetFontHeight(int value);
		virtual int GetFontHeight();

		virtual void CreateDrawItem(ITexture* texture, ILayerNode * node);
		virtual void DestroyDrawItem();

		virtual void SetTextAlign(Align value);
		virtual Align GetTextAlign();

		virtual size_t GetTextSelectionStart();
		virtual size_t GetTextSelectionEnd();
		virtual void SetTextSelection(size_t start, size_t end);

		virtual bool GetSelectBackground();
		virtual void SetSelectBackground(bool normal);

		virtual bool IsVisibleCursor();
		virtual void SetVisibleCursor(bool value);

		/** Get invert selected text color property */
		virtual bool GetInvertSelected() { return mInvertSelect; }
		/** Enable or disable inverting color of selected text\n
			Enabled (true) by default
		*/
		virtual void SetInvertSelected(bool value);

		virtual size_t GetCursorPosition();
		virtual void SetCursorPosition(size_t index);

		virtual IntSize GetTextSize();

		virtual void SetViewOffset(const IntPoint& point);
		virtual IntPoint GetViewOffset();

		virtual size_t GetCursorPosition(const IntPoint& point);

		virtual IntCoord GetCursorCoord(size_t position);

		void SetShiftText(bool shift);

		void SetWordWrap(bool value);

		virtual void SetStateData(IStateInfo * data);

		void _updateView();
		void _correctView();

	/*internal:*/
		void _setAlign(const IntSize& oldsize, bool update);
		void _setAlign(const IntCoord& oldcoord, bool update);

	protected:
		bool mEmptyView;
		uint32 mCurrentColour;
		uint32 mInverseColour;
		uint32 mCurrentAlpha;
		IntCoord mCurrentCoord;

		UString mCaption;
		bool mTextOutDate;
		Align mTextAlign;

		Colour mColour;
		float mAlpha;
		VertexColourType mVertexFormat;

		IFont* mFont;
		ITexture* mTexture;
		int mFontHeight;

		bool mBackgroundNormal;
		size_t mStartSelect;
		size_t mEndSelect;
		size_t mCursorPosition;
		bool mVisibleCursor;
		bool mInvertSelect;

		IntPoint mViewOffset; 

		ILayerNode* mNode;
		RenderItem* mRenderItem;
		size_t mCountVertex;
		bool mIsAddCursorWidth;

		bool mShiftText;
		bool mWordWrap;
		int mOldWidth;

		TextView mTextView;
	};

} // namespace GUI

#endif // __EDIT_TEXT_H__


