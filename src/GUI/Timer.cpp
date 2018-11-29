#include "Precompiled.h"
#include "Timer.h"

#if PLATFORM == PLATFORM_WIN32
#	include <windows.h>
#	ifndef __MINGW32__
#		pragma comment(lib, "winmm.lib")
#	else
#		pragma comment(lib, "libwinmm.a")
#	endif
#else
#	include <sys/time.h>
#endif

namespace GUI
{

	Timer::Timer() :
		mTimeStart(0)
	{

	}

	void Timer::Reset()
	{
		mTimeStart = GetCurrentMilliseconds();
	}

	unsigned long Timer::GetMilliseconds()
	{
		return GetCurrentMilliseconds() - mTimeStart;
	}

	unsigned long Timer::GetCurrentMilliseconds()
	{
#if PLATFORM == PLATFORM_WIN32
		/*
		We do this because Clock() is not affected by timeBeginPeriod on Win32.
		QueryPerformanceCounter is a little overkill for the amount of precision that
		I consider acceptable. If someone submits a patch that replaces this code
		with QueryPerformanceCounter, I wouldn't complain. Until then, timeGetTime
		gets the results I'm after. -EMS

		See: http://www.geisswerks.com/ryan/FAQS/timing.html
		And: http://support.microsoft.com/default.aspx?scid=KB;EN-US;Q274323&
		*/
		return timeGetTime();
#else
		struct timeval now;
		Gettimeofday(&now, NULL);
		return (now.tv_sec)*1000+(now.tv_usec)/1000;
		//return ( unsigned long )(( double )( Clock() ) / (( double )CLOCKS_PER_SEC / 1000.0 ) );
#endif
	}


} // namespace GUI
