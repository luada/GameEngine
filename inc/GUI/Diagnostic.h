#ifndef __DIAGNOSTIC_H__
#define __DIAGNOSTIC_H__

#include "Prerequest.h"
#include "Exception.h"
#include "LogManager.h"
#include <sstream>

// for debugging
#if COMPILER == COMPILER_MSVC
	#include <crtdbg.h>
#endif

#define LOG_SECTION "Core"
#define LOG_FILENAME "GUI.log"
#define LOG(level, text) LOGGING(LOG_SECTION, level, text)

#define BASE_EXCEPT(desc, src)	 throw GUI::Exception(desc, src, __FILE__, __LINE__);

// MSVC specific: sets the breakpoint
#if COMPILER == COMPILER_MSVC
	#define DBG_BREAK _CrtDbgBreak();
#else
	#define DBG_BREAK
#endif

#define EXCEPT(dest) \
{ \
	LOG(Critical, dest); \
	DBG_BREAK;\
	std::ostringstream stream; \
	stream << dest << "\n"; \
	BASE_EXCEPT(stream.str().c_str(), "GUI"); \
}

#define ASSERT(exp, dest) \
{ \
	if (! (exp)) \
	{ \
		LOG(Critical, dest); \
		DBG_BREAK;\
		std::ostringstream stream; \
		stream << dest << "\n"; \
		BASE_EXCEPT(stream.str().c_str(), "GUI"); \
	} \
}

#define ASSERT_RANGE(index, size, owner) ASSERT(index < size, owner << " : index number " << index << " out of range [" << size << "]");
#define ASSERT_RANGE_AND_NONE(index, size, owner) ASSERT(index < size || index == ITEM_NONE, owner << " : index number " << index << " out of range [" << size << "]");
#define ASSERT_RANGE_INSERT(index, size, owner) ASSERT((index <= size) || (index == GUI::ITEM_NONE), owner << " : insert index number " << index << " out of range [" << size << "] or not ITEM_NONE");

#if DEBUG_MODE == 1
	#define REGISTER_VALUE(map, value) \
	{ \
		LOG(Info, "Register value : '" << #value << "' = " << (int)value); \
		map[#value] = value; \
	}
	#define DEBUG_ASSERT(exp, dest) ASSERT(exp, dest)
#else
	#define REGISTER_VALUE(map, value) map[#value] = value;
	#define DEBUG_ASSERT(exp, dest) ((void)0)
#endif


// for more info see: http://mdf-i.blogspot.com/2008/09/deprecated-gcc-vs-vs-vs-vs.html
#if COMPILER == COMPILER_MSVC
	#if COMP_VER == 1310 	// VC++ 7.1
		#define OBSOLETE_START(text)
	    #define OBSOLETE_END
	#else
		#define OBSOLETE_START(text) __declspec(deprecated(text))
	    #define OBSOLETE_END
	#endif

#elif COMPILER == COMPILER_GNUC
	#if PLATFORM == PLATFORM_LINUX && COMP_VER == 412
		#define OBSOLETE_START(text)
        #define OBSOLETE_END
	#else
        #define OBSOLETE_START(text)
		#define OBSOLETE_END __attribute__((deprecated))
	#endif

#else
	#define OBSOLETE_START(text)
	#define OBSOLETE_END

#endif

#define OBSOLETE(text) /*! \deprecated text */ OBSOLETE_START(text)OBSOLETE_END

#endif // __DIAGNOSTIC_H__
