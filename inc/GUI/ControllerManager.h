#ifndef __CONTROLLER_MANAGER_H__
#define __CONTROLLER_MANAGER_H__

#include "Prerequest.h"
#include "Instance.h"
#include "ControllerItem.h"
#include "IUnlinkWidget.h"
#include "WidgetDefines.h"
#include "ActionController.h"

namespace GUI
{

	class GUI_EXPORT ControllerManager : public IUnlinkWidget
	{
		INSTANCE_HEADER(ControllerManager)

	public:
		void Initialise();
		void Shutdown();

		ControllerItem* CreateItem(const std::string& type);

		/** Add controlled widget
			@param _widget to be controlled
			@param _item controller with some Actions (for example ControllerFadeAlpha or your own)
			@note _item will be deleted automatically at end of controller lifetime
				(if not removed by RemoveItem(Widget* widget) before)
		*/
		void AddItem(Widget* widget, ControllerItem * item);

		/** Stop the control over a widget
			@param _widget to be removed
		*/
		void RemoveItem(Widget* widget);

	private:
		void _unlinkWidget(Widget* widget);
		void FrameEntered(float time);
		void Clear();

	private:
		typedef std::pair<Widget*, ControllerItem *> PairControllerItem;
		typedef std::list<PairControllerItem> ListControllerItem;
		ListControllerItem mListItem;

	};

} // namespace GUI

#endif // __CONTROLLER_MANAGER_H__

