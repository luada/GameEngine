#ifndef __TYPES_H__
#define __TYPES_H__

#include "Prerequest.h"

#include <vector>
#include <map>
#include <string>

#include "Utility.h"
#include "Align.h"
#include "TPoint.h"
#include "TSize.h"
#include "TRect.h"
#include "TCoord.h"

namespace GUI
{

	typedef types::TPoint<int> IntPoint;
	typedef types::TPoint<float> FloatPoint;

	typedef types::TSize<int> IntSize;
	typedef types::TSize<float> FloatSize;

	typedef types::TRect<int> IntRect;
	typedef types::TRect<float> FloatRect;

	typedef types::TCoord<int> IntCoord;
	typedef types::TCoord<float> FloatCoord;

	typedef std::map<std::string, std::string> MapString;
	typedef std::vector<std::string> VectorString;

	typedef char int8;
	typedef short int16;
	typedef int int32;
	typedef unsigned char uint8;
	typedef unsigned short uint16;
	typedef unsigned int uint32;
	typedef unsigned int uint;

	typedef unsigned int Char;

} // namespace GUI

#endif // __TYPES_H__

