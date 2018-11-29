#include "Precompiled.h"
#include "ActionController.h"
#include "Widget.h"
#include "WidgetManager.h"

namespace GUI
{

	namespace Action
	{

		void ActionWidgetHide(Widget* widget)
		{
			widget->SetVisible(false);
		}

		void ActionWidgetShow(Widget* widget)
		{
			widget->SetVisible(true);
		}

		void ActionWidgetDestroy(Widget* widget)
		{
			WidgetManager::GetInstance().DestroyWidget(widget);
		}

		void LinearMoveFunction(const IntCoord& startRect, const IntCoord& destRect, IntCoord& result, float k)
		{
			result.Set(startRect.left   - int( float(startRect.left   - destRect.left)   * k ),
			            startRect.top    - int( float(startRect.top    - destRect.top)    * k ),
			            startRect.width  - int( float(startRect.width  - destRect.width)  * k ),
			            startRect.height - int( float(startRect.height - destRect.height) * k )
			           );
		}

		void InertionalMoveFunction(const IntCoord& startRect, const IntCoord& destRect, IntCoord& result, float current_time)
		{
#ifndef M_PI
			const float M_PI = 3.141593f;
#endif
			float k = sin(M_PI * current_time - M_PI/2.0f);
			if (k<0) k = (-pow(-k, 0.7f) + 1)/2;
			else k = (pow(k, 0.7f) + 1)/2;
			LinearMoveFunction(startRect, destRect, result, k);
		}

	} // namespace Action

} // namespace GUI
