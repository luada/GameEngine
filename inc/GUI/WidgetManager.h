#ifndef __WIDGET_MANAGER_H__
#define __WIDGET_MANAGER_H__

#include "Prerequest.h"
#include "Instance.h"
#include "IWidgetCreator.h"
#include "IUnlinkWidget.h"
#include "ICroppedRectangle.h"
#include "Widget.h"
#include <set>

namespace GUI
{

	//OBSOLETE
	typedef delegates::CDelegate3<Widget*,  const std::string &, const std::string &> ParseDelegate;

	class GUI_EXPORT WidgetManager
	{
		INSTANCE_HEADER(WidgetManager)

	public:
		//OBSOLETE
		typedef std::map<std::string, ParseDelegate> MapDelegate;
		//OBSOLETE
		typedef std::set<IWidgetFactory*> SetWidgetFactory;

	public:
		void Initialise();
		void Shutdown();

		Widget* CreateWidget(WidgetStyle style, const std::string& type, const std::string& skin, const IntCoord& coord, Align align, Widget* parent, ICroppedRectangle * cropeedParent, IWidgetCreator * creator, const std::string& name);

		/** Destroy _widget */
		void DestroyWidget(Widget* widget);
		/** Destroy vector of widgets */
		void DestroyWidgets(const VectorWidgetPtr &_widgets);
		/** Destroy Enumerator of widgets */
		void DestroyWidgets(EnumeratorWidgetPtr widgets);

		/** Register Unlinker (call unlink if for any destroyed widget)*/
		void RegisterUnlinker(IUnlinkWidget * unlink);
		/** Unregister Unlinker (call unlink if for any destroyed widget)*/
		void UnregisterUnlinker(IUnlinkWidget * unlink);
		/** Unlink widget */
		void UnlinkFromUnlinkers(Widget* widget);

		void AddWidgetToUnlink(Widget* widget);

		void RemoveWidgetFromUnlink(Widget*& widget);

		bool IsFactoryExist(const std::string& type);

	protected:
		SetWidgetFactory mFactoryList;
		//MapWidgetPtr mWidgets;
		MapDelegate mDelegates;

		VectorIUnlinkWidget mVectorIUnlinkWidget;

		VectorWidgetPtr mUnlinkWidgets;
	};

} // namespace GUI

#endif // __WIDGET_MANAGER_H__

