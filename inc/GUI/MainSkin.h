#ifndef __MAIN_SKIN_H__
#define __MAIN_SKIN_H__

#include "Prerequest.h"
#include "SubSkin.h"

namespace GUI
{

	class GUI_EXPORT MainSkin : public SubSkin
	{
		RTTI_DERIVED(MainSkin)

	public:
		MainSkin();
		virtual ~MainSkin();

	/*internal:*/
		void _setAlign(const IntSize& oldsize, bool update);
		void _setAlign(const IntCoord& oldsize, bool update) { SubSkin::_setAlign(oldsize, update); }
	};

} // namespace GUI

#endif // __SUB_SKIN_H__
