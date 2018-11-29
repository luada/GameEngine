#ifndef __DIRECTX_DIAGNOSTIC_H__
#define __DIRECTX_DIAGNOSTIC_H__

#include "Prerequest.h"

#define PLATFORM_LOG_SECTION "Platform"
#define PLATFORM_LOG_FILENAME "GUI.log"
#define PLATFORM_LOG(level, text) LOGGING(PLATFORM_LOG_SECTION, level, text)

#define PLATFORM_EXCEPT(dest) \
{ \
	PLATFORM_LOG(Critical, dest); \
	DBG_BREAK;\
	std::ostringstream stream; \
	stream << dest << "\n"; \
	BASE_EXCEPT(stream.str().c_str(), "GUI"); \
}

#define PLATFORM_ASSERT(exp, dest) \
{ \
	if (! (exp)) \
	{ \
		PLATFORM_LOG(Critical, dest); \
		DBG_BREAK;\
		std::ostringstream stream; \
		stream << dest << "\n"; \
		BASE_EXCEPT(stream.str().c_str(), "GUI"); \
	} \
}

#endif // __DIRECTX_DIAGNOSTIC_H__
