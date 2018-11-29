#ifndef __TIMER_H__
#define __TIMER_H__

#include "Prerequest.h"

namespace GUI
{

	class GUI_EXPORT Timer
	{
	public:
		Timer();

		void Reset();
		unsigned long GetMilliseconds();

	private:
		unsigned long GetCurrentMilliseconds();

	private:
		unsigned long mTimeStart;
	};

} // namespace GUI

#endif // __TIMER_H__
