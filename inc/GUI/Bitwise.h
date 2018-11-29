#ifndef __BITWISE_H__
#define __BITWISE_H__

#include "Prerequest.h"

namespace GUI
{

	class Bitwise
	{
	public:
		/** Returns the closest power-of-two number greater or equal to value.
		*/
		template<typename Type>
		static FORCEINLINE Type FirstPO2From(Type value)
		{
			--value;
			value |= value >> 16;
			value |= value >> 8;
			value |= value >> 4;
			value |= value >> 2;
			value |= value >> 1;
			++value;
			return value;
		}

		/** Determines whether the number is power-of-two or not. */
		template<typename Type>
		static FORCEINLINE bool IsPO2(Type value)
		{
			return (value & (value-1)) == 0;
		}

		/** Returns the number of bits a pattern must be shifted right by to
		remove right-hand zeros.
		*/
		template<typename Type>
		static FORCEINLINE size_t GetBitShift(Type mask)
		{
			if (mask == 0)
				return 0;

			size_t result = 0;
			while ((mask & 1) == 0)
			{
				++result;
				mask >>= 1;
			}
			return result;
		}

	};

} // namespace GUI

#endif // __BITWISE_H__
