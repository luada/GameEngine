#ifndef __RENDER_OUT_H__
#define __RENDER_OUT_H__

#include "Prerequest.h"
#include "Utility.h"

namespace GUI
{
	namespace implement
	{
		void GUI_EXPORT Render_out(const std::string& value);
	}

	template<typename T> inline
	void GUI_OUT(T p) { implement::Render_out(utility::ToString(p)); }

	template<typename T1,  typename T2 > inline
	void GUI_OUT(T1 p1, T2 p2) { implement::Render_out(utility::ToString(p1, p2)); }

	template<typename T1,  typename T2,  typename T3 > inline
	void GUI_OUT(T1 p1, T2 p2, T3 p3) { implement::Render_out(utility::ToString(p1, p2, p3)); }

	template<typename T1,  typename T2,  typename T3, typename T4 > inline
	void GUI_OUT(T1 p1, T2 p2, T3 p3, T4 p4) { implement::Render_out(utility::ToString(p1, p2, p3, p4)); }

	template<typename T1,  typename T2,  typename T3, typename T4, typename T5 > inline
	void GUI_OUT(T1 p1, T2 p2, T3 p3, T4 p4, T5 p5) { implement::Render_out(utility::ToString(p1, p2, p3, p4, p5)); }

	template<typename T1,  typename T2,  typename T3, typename T4, typename T5, typename T6 > inline
	void GUI_OUT(T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6) { implement::Render_out(utility::ToString(p1, p2, p3, p4, p5, p6)); }

	template<typename T1,  typename T2,  typename T3, typename T4, typename T5, typename T6, typename T7 > inline
	void GUI_OUT(T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7) { implement::Render_out(utility::ToString(p1, p2, p3, p4, p5, p6, p7)); }

	template<typename T1,  typename T2,  typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 > inline
	void GUI_OUT(T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8) { implement::Render_out(utility::ToString(p1, p2, p3, p4, p5, p6, p7, p8)); }

	template<typename T1,  typename T2 > inline
	void GUI_OUT_SPACES (T1 p1, T2 p2) { implement::Render_out(utility::ToString(p1, " ", p2)); }

	template<typename T1,  typename T2,  typename T3 > inline
	void GUI_OUT_SPACES (T1 p1, T2 p2, T3 p3) { implement::Render_out(utility::ToString(p1, " ", p2, " ", p3)); }

	template<typename T1,  typename T2,  typename T3, typename T4 > inline
	void GUI_OUT_SPACES (T1 p1, T2 p2, T3 p3, T4 p4) { implement::Render_out(utility::ToString(p1, " ", p2, " ", p3, " ", p4 )); }

} // namespace GUI

#endif // __RENDER_OUT_H__
