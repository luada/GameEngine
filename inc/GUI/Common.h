#ifndef __COMMON_H__
#define __COMMON_H__

#include "Prerequest.h"

#include <string>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <deque>
#include <exception>
#include <math.h>

#ifdef CUSTOM_ALLOCATOR
#    include "CustomAllocator.h"
#else // CUSTOM_ALLOCATOR
#    include "Allocator.h"
#endif // CUSTOM_ALLOCATOR

#include "Macros.h"
#include "Diagnostic.h"
#include "LogManager.h"
#include "Instance.h"
#include "Types.h"
#include "RenderOut.h"
#include "Utility.h"
#include "InputDefine.h"
#include "Version.h"
#include "WidgetStyle.h"
#include "UString.h"
#include "Delegate.h"

#endif // __COMMON_H__
