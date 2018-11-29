#ifndef __MACROS_H__
#define __MACROS_H__

namespace GUI
{

	const size_t ITEM_NONE = ~(size_t)0;
	const int DEFAULT ((int)-1);
	const float ALPHA_MAX = 1.0f;
	const float ALPHA_MIN = 0.0f;

	//FIXME
	#define FLAG_NONE  0
	#define FLAG(num)  (1<<(num))

} // namespace GUI


#endif // __MACROS_H__
