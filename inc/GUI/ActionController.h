#ifndef __ACTION_CONTROLLER_H__
#define __ACTION_CONTROLLER_H__

#include "Prerequest.h"
#include "Types.h"
#include <math.h>

namespace GUI
{

	namespace Action
	{

		/** Function used for hiding widget with one of controller event */
		void GUI_EXPORT ActionWidgetHide(Widget* widget);

		/** Function used for showing widget with one of controller event */
		void GUI_EXPORT ActionWidgetShow(Widget* widget);

		/** Function used for destroying widget with one of controller event */
		void GUI_EXPORT ActionWidgetDestroy(Widget* widget);

		/** Function for ControllerPosition per frame Action : Move with constant speed */
		void GUI_EXPORT LinearMoveFunction(const IntCoord& startRect, const IntCoord& destRect, IntCoord& result, float k);

		/** Function for ControllerPosition per frame Action : Move with accelerated speed
			if N == 10 then this function is same as linearMoveFunction
			if N > 10 speed will be increasing
			if N < 10 speed will be decreasing
		*/
		template <int N>
		inline void AcceleratedMoveFunction(const IntCoord& startRect, const IntCoord& destRect, IntCoord& result, float current_time)
		{
			float k = (float)pow (current_time, N/10.f /*3 by default as Accelerated and 0.4 by default as Slowed*/);
			LinearMoveFunction(startRect, destRect, result, k);
		}

		/** Function for ControllerPosition per frame Action : Move with accelerated speed a bit farther than necessary and then return it back */
		template <int N>
		inline void JumpMoveFunction(const IntCoord& startRect, const IntCoord& destRect, IntCoord& result, float current_time)
		{
			float k = pow (current_time, 2) * (-2 - N/10.f) + current_time * (3 + N/10.f);
			LinearMoveFunction(startRect, destRect, result, k);
		}

		/** Function for ControllerPosition per frame Action : Start with zero speed increasing half time and then decreasing to zero */
		void GUI_EXPORT InertionalMoveFunction(const IntCoord& startRect, const IntCoord& destRect, IntCoord& result, float current_time);

	} // namespace Action

} // namespace GUI

#endif // __ACTION_CONTROLLER_H__
