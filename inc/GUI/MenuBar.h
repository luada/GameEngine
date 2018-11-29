#ifndef __MENU_BAR_H__
#define __MENU_BAR_H__

#include "Prerequest.h"
#include "MenuCtrl.h"

namespace GUI
{

	class GUI_EXPORT MenuBar :
		public MenuCtrl
	{
		RTTI_DERIVED(MenuBar)
		DEFINE_GET_THIS(MenuBar, BASS(MenuCtrl, END))

	public:
		MenuBar();

		//@ExportToLua
		virtual void SetVisible(bool value) { Base::SetVisible(value); }

	/*internal:*/
		virtual void _initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name);

	protected:
		virtual ~MenuBar();

		void BaseChangeWidgetSkin(ResourceSkin* info);

	private:
		void InitialiseWidgetSkin(ResourceSkin* info);
		void ShutdownWidgetSkin();

	};

} // namespace GUI

#endif // __MENU_BAR_H__
