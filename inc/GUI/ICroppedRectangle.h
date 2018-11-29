#ifndef __I_CROPPED_RECTANGLE_H__
#define __I_CROPPED_RECTANGLE_H__

#include "Prerequest.h"
#include "Types.h"

namespace GUI
{

	class GUI_EXPORT ICroppedRectangle
	{
	public:
		ICroppedRectangle() :
			mIsMargin(false),
			mCroppedParent(nullptr),
			mVisible(true),
			mAlign(Align::Default)
		{ }

		virtual ~ICroppedRectangle() { }

		/** Get parent ICroppedRectangle */
		ICroppedRectangle * GetCroppedParent() { return mCroppedParent; }

		/** Set Coordinates (position and size) */
		virtual void SetCoord(const IntCoord& value) { mCoord = value; }
		/** Get Coordinates (position and size) */
		const IntCoord& GetCoord() const { return mCoord; }

		/** Set position */
		virtual void SetPosition(const IntPoint& value) { mCoord.left = value.left; mCoord.top = value.top; }
		/** Get position */
		IntPoint GetPosition() const { return mCoord.Point(); }

		/** Set size */
		virtual void SetSize(const IntSize& value) { mCoord.width = value.width; mCoord.height = value.height; }
		/** Get size */
		IntSize GetSize() const { return mCoord.Size(); }

		/** Hide or show */
		virtual void SetVisible(bool value) { mVisible = value; }
		/** Return true if visible */
		bool IsVisible() const { return mVisible; }

		/** Get position in screen coordinates */
		const IntPoint& GetAbsolutePosition() const { return mAbsolutePosition; }
		/** Get rectangle in screen coordinates */
		IntRect GetAbsoluteRect() const { return IntRect(mAbsolutePosition.left, mAbsolutePosition.top, mAbsolutePosition.left+mCoord.width, mAbsolutePosition.top+mCoord.height); }
		/** Get coordinate in screen coordinates */
		IntCoord GetAbsoluteCoord() const { return IntCoord(mAbsolutePosition.left, mAbsolutePosition.top, mCoord.width, mCoord.height); }

		/** Get X in screen coordinates */
		int GetAbsoluteLeft() const { return mAbsolutePosition.left; }
		/** Get Y in screen coordinates */
		int GetAbsoluteTop() const { return mAbsolutePosition.top; }

		/** Set align */
		virtual void SetAlign(Align value) { mAlign = value; }
		/** Get align */
		Align GetAlign() const { return mAlign; }

		/** Get left x-coordinate */
		int GetLeft() const { return mCoord.left; }
		/** Get right x-coordinate */
		int GetRight() const { return mCoord.Right(); }
		/** Get top y-coordinate */
		int GetTop() const { return mCoord.top; }
		/** Get bottom y-coordinate */
		int GetBottom() const { return mCoord.Bottom(); }
		/** Get width */
		int GetWidth() const { return mCoord.width; }
		/** Get height */
		int GetHeight() const { return mCoord.height; }


	/*internal:*/
		/** True if rectangle is cropped by parent rectangle */
		bool _isMargin() const { return mIsMargin; }

		// Get cropped by parent rectangle coordinates
		int _getViewLeft() const { return mCoord.left + mMargin.left; }
		int _getViewRight() const { return mCoord.Right() - mMargin.right; }
		int _getViewTop() const { return mCoord.top + mMargin.top; }
		int _getViewBottom() const { return mCoord.Bottom() - mMargin.bottom; }
		int _getViewWidth() const { return mCoord.width - mMargin.left - mMargin.right; }
		int _getViewHeight() const { return mCoord.height - mMargin.top - mMargin.bottom; }

		virtual void _updateView() { }
		virtual void _correctView() { }
		virtual void _setAlign(const IntSize& oldsize, bool update)  { }
		virtual void _setAlign(const IntCoord& oldcoord, bool update) { }

		void _setCroppedParent(ICroppedRectangle* parent) { mCroppedParent = parent; }

		const IntRect& _getMargin() const { return mMargin; }
		int _getMarginLeft() const { return mMargin.left; }
		int _getMarginRight() const { return mMargin.right; }
		int _getMarginTop() const { return mMargin.top; }
		int _getMarginBottom() const { return mMargin.bottom; }

	protected:
		bool _checkPoint(int left, int top)
		{
			return ! ((_getViewLeft() > left) || (_getViewTop() > top) || (_getViewRight() < left) || (_getViewBottom() < top));
		}

		bool _checkMargin()
		{
			bool margin = false;
			if(GetLeft() < mCroppedParent->mMargin.left)
			{
				mMargin.left = mCroppedParent->mMargin.left - GetLeft();
				margin = true;
			}
			else
			{
				mMargin.left = 0;
			}

			if (GetRight() > mCroppedParent->GetWidth() - mCroppedParent->mMargin.right)
			{
				mMargin.right = GetRight() - (mCroppedParent->GetWidth() - mCroppedParent->mMargin.right);
				margin = true;
			}
			else
			{
				mMargin.right = 0;
			}

			if (GetTop() < mCroppedParent->mMargin.top)
			{
				mMargin.top = mCroppedParent->mMargin.top - GetTop();
				margin = true;
			}
			else
			{
				mMargin.top = 0;
			}

			if (GetBottom() > mCroppedParent->GetHeight() - mCroppedParent->mMargin.bottom)
			{
				mMargin.bottom = GetBottom() - (mCroppedParent->GetHeight() - mCroppedParent->mMargin.bottom);
				margin = true;
			}
			else
			{
				mMargin.bottom = 0;
			}

			return margin;
		}

		bool _checkOutside() 
		{
			return ( (GetRight() < mCroppedParent->mMargin.left ) || 
				(GetLeft() > mCroppedParent->GetWidth() - mCroppedParent->mMargin.right ) || 
				(GetBottom() < mCroppedParent->mMargin.top  ) || 
				(GetTop() > mCroppedParent->GetHeight() - mCroppedParent->mMargin.bottom ) );  
		}

	protected:
		bool mIsMargin;
		IntRect mMargin; 
		IntCoord mCoord; 
		IntPoint mAbsolutePosition; 

		ICroppedRectangle * mCroppedParent;
		bool mVisible;
		Align mAlign;

	};

} // namespace GUI

#endif // __I_CROPPED_RECTANGLE_H__


