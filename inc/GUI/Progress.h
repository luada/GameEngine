#ifndef __PROGRESS_H__
#define __PROGRESS_H__

#include "Prerequest.h"
#include "Align.h"
#include "Widget.h"

namespace GUI
{

	class GUI_EXPORT Progress :
		public Widget
	{
		RTTI_DERIVED(Progress)
		DEFINE_GET_THIS(Progress, BASS(Widget, END))

	public:
		Progress();

		/** Set progress range */
		//@ExportToLua
		void SetProgressRange(size_t value);
		/** Get progress range */
		//@ExportToLua
		size_t GetProgressRange() { return mRange; }

		/** Set progress position */
		//@ExportToLua
		void SetProgressPosition(size_t value);
		/** Get progress position */
		//@ExportToLua
		size_t GetProgressPosition() { return mEndPosition; }

		/** Enable or disable progress auto tracking */
		//@ExportToLua
		void SetProgressAutoTrack(bool value);
		/** Get progress auto tracking flag */
		//@ExportToLua
		bool GetProgressAutoTrack() { return mAutoTrack; }

		/** Set progress start point
			For example with Align::Top if will be filled from top to bottom.
		*/
		//@ExportToLua
		void SetProgressStartPoint(Align value);
		/** Get progress start point */
		//@ExportToLua
		Align GetProgressStartPoint() { return mStartPoint; }

		//! @copydoc Widget::SetPosition(const IntPoint& value)
		virtual void SetPosition(const IntPoint& value);
		//! @copydoc Widget::SetSize(const IntSize& value)
		virtual void SetSize(const IntSize& value);
		//! @copydoc Widget::SetCoord(const IntCoord& value)
		virtual void SetCoord(const IntCoord& value);

		/** @copydoc Widget::SetPosition(int left, int top) */
		//@ExportToLua
		void SetPosition(int left, int top) { SetPosition(IntPoint(left, top)); }
		/** @copydoc Widget::SetSize(int width, int height) */
		//@ExportToLua
		void SetSize(int width, int height) { SetSize(IntSize(width, height)); }
		/** @copydoc Widget::SetCoord(int left, int top, int width, int height) */
		//@ExportToLua
		void SetCoord(int left, int top, int width, int height) { SetCoord(IntCoord(left, top, width, height)); }

		/** @copydoc Widget::SetProperty(const std::string& key, const std::string& value) */
		//@ExportToLua
		virtual void SetProperty(const std::string& key, const std::string& value);

	/*internal:*/
		virtual void _initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name);

	protected:
		virtual ~Progress();

		void BaseChangeWidgetSkin(ResourceSkin* info);

	private:
		void InitialiseWidgetSkin(ResourceSkin* info);
		void ShutdownWidgetSkin();

		void FrameEntered(float time);
		void UpdateTrack();

		int GetClientWidth() { return ((mStartPoint.IsLeft()) || (mStartPoint.IsRight())) ? mClient->GetWidth() : mClient->GetHeight(); }
		int GetClientHeight() { return ((mStartPoint.IsLeft()) || (mStartPoint.IsRight())) ? mClient->GetHeight() : mClient->GetWidth(); }

		void SetTrackPosition(Widget* widget, int left, int top, int width, int height);

	private:
		std::string mTrackSkin;
		int mTrackWidth;
		int mTrackStep;
		int mTrackMin;

		VectorWidgetPtr mVectorTrack;
		size_t mRange;
		size_t mStartPosition, mEndPosition;
		float mAutoPosition;
		bool mAutoTrack;
		bool mFillTrack;

		Align mStartPoint;

		Widget* mClient;

	};

} // namespace GUI

#endif // __PROGRESS_H__
