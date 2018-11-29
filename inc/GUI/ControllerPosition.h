#ifndef __CONTROLLER_POSITION_H__
#define __CONTROLLER_POSITION_H__

#include "Prerequest.h"
#include "Delegate.h"
#include "Types.h"
#include "WidgetDefines.h"
#include "ControllerItem.h"

namespace GUI
{

	/** This controller used for smooth changing position of widget in time */
	class GUI_EXPORT ControllerPosition :
		public ControllerItem
	{
		RTTI_DERIVED(ControllerPosition)

	public:
		typedef delegates::CDelegate4<const IntCoord&, const IntCoord&, IntCoord&, float> FrameAction;

		ControllerPosition();
		virtual ~ControllerPosition() { }

		void SetCoord(const IntCoord& value);

		void SetSize(const IntSize& value);

		void SetPosition(const IntPoint& value);

		void SetFunction(const std::string& value);

		/**
			@param _value seconds in which widget planned to reach destination coordinate
		*/
		void SetTime(float value) { mTime = value; }

		/**
			@param _action applied to widget every Frame (see ControllerPosition::eventFrameAction)
		*/
		void SetAction(FrameAction::IDelegate* value) { eventFrameAction = value; }

		virtual void SetProperty(const std::string& key, const std::string& value);

	private:
		bool AddTime(Widget* widget, float time);
		void PrepareItem(Widget* widget);

		float GetElapsedTime() { return mElapsedTime; }

		IntCoord mStartCoord;
		IntCoord mDestCoord;
		float mTime;
		float mElapsedTime;

		// controller changing position
		bool mCalcPosition;
		// controller changing size
		bool mCalcSize;

		/** Event : Every frame Action while controller exist.\n
			signature : void Method(const IntRect& startRect, const IntRect& destRect, IntRect& result, float current_time)\n
			@param _startRect start coordinate of widget
			@param _destRect destination coordinate
			@param _result resultRect
			@param _current_time elapsed Time (currenttime is real elapsed time divided by time(see constructor) so currenttime == 1 mean that time seconds elapsed)
		*/
		FrameAction eventFrameAction;
	};

}

#endif // __CONTROLLER_POSITION_H__
