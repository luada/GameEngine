#ifndef __CONTROLLER_EDGE_HIDE_H__
#define __CONTROLLER_EDGE_HIDE_H__

#include "Prerequest.h"
#include "WidgetDefines.h"
#include "ControllerItem.h"
#include "Types.h"

namespace GUI
{

	/** This controller used for hiding widgets near screen edges.
		Widget will start Hiding(move out of screen) if it's near
		border and it and it's childrens don't have any focus. Hiding
		till only small part of widget be visible. Widget will move
		inside screen if it have any focus.
	*/
	class GUI_EXPORT ControllerEdgeHide :
		public ControllerItem
	{
		RTTI_DERIVED(ControllerEdgeHide)

	public:
		ControllerEdgeHide();
		virtual ~ControllerEdgeHide() { }

		/**
			@param _value in which widget will be hidden or shown
		*/
		void SetTime(float value) { mTime = value; }

		/**
			@param _remainPixels how many pixels you will see afterr full hide
		*/
		void SetRemainPixels(int value) { mRemainPixels = value; }

		/**
			@param _shadowSize adds to _remainPixels when hiding left or Top (for example used for windows with shadows)
		*/
		void SetShadowSize(int value) { mShadowSize = value; }

		virtual void SetProperty(const std::string& key, const std::string& value);

	private:
		bool AddTime(Widget* widget, float time);
		void PrepareItem(Widget* widget);

		void RecalculateTime(Widget* widget);

		delegates::CDelegate1<Widget*> eventPostAction;

		float mTime;
		int mRemainPixels;
		int mShadowSize;
		float mElapsedTime;
		// for checking if widget was moved
		GUI::IntCoord mLastCoord;
	};

}

#endif // __CONTROLLER_EDGE_HIDE_H__
