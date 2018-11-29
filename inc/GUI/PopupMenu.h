#ifndef __POPUP_MENU_H__
#define __POPUP_MENU_H__

#include "Prerequest.h"
#include "MenuCtrl.h"

namespace GUI
{

	class GUI_EXPORT PopupMenu :
		public MenuCtrl
	{
		RTTI_DERIVED(PopupMenu)
		DEFINE_GET_THIS(PopupMenu, BASS(MenuCtrl, END))

	public:
		PopupMenu();

		//@ExportToLua
		virtual void SetVisible(bool value) { Base::SetVisible(value); }

	/*internal:*/
		virtual void _initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name);

	protected:
		virtual ~PopupMenu();

		void BaseChangeWidgetSkin(ResourceSkin* info);

	private:
		void InitialiseWidgetSkin(ResourceSkin* info);
		void ShutdownWidgetSkin();

	};

} // namespace GUI

#endif // __POPUP_MENU_H__
