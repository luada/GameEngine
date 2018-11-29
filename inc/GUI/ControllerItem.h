#ifndef __CONTROLLER_ITEM_H__
#define __CONTROLLER_ITEM_H__

#include "Prerequest.h"
#include "WidgetDefines.h"
#include "IObject.h"
#include "Delegate.h"

namespace GUI
{

	/** Base interface for controllers */
	class GUI_EXPORT ControllerItem :
		public IObject
	{
		RTTI_DERIVED(ControllerItem)

	public:
		virtual ~ControllerItem() { }

		virtual void PrepareItem(Widget* widget) = 0;
		virtual bool AddTime(Widget* widget, float time) = 0;

		virtual void SetProperty(const std::string& key, const std::string& value) { }

		/** Event : Before controller started working.\n
			signature : void Method(GUI::Widget* sender)\n
			@param _sender widget under control
		*/
		delegates::CDelegate1<Widget*>
			eventPreAction;

		/** Event : Controller Updated (called every frame).\n
			signature : void Method(GUI::Widget* sender)\n
			@param _sender widget under control
		*/
		delegates::CDelegate1<Widget*>
			eventUpdateAction;

		/** Event : After controller finished working.\n
			signature : void Method(GUI::Widget* sender)\n
			@param _sender widget under control
		*/
		delegates::CDelegate1<Widget*>
			eventPostAction;

	};

} // namespace GUI

#endif // __CONTROLLER_ITEM_H__
