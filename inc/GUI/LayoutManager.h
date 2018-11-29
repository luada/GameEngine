#ifndef __LAYOUT_MANAGER_H__
#define __LAYOUT_MANAGER_H__

#include "Prerequest.h"
#include "Instance.h"
#include "XmlDocument.h"
#include "WidgetDefines.h"
#include "Gui.h"

namespace GUI
{

	class GUI_EXPORT LayoutManager
	{
		INSTANCE_HEADER(LayoutManager)

	public:
		void Initialise();
		void Shutdown();

		//@ExportToLua
		static LayoutManager& Instance()
		{
			return GetInstance();
		}

		/** Load layout file
			@param _file name of layout
			@return Return vector of pointers of loaded root Widgets (root == without parents)
		*/
		//@ExportToLua
		VectorWidgetPtr& Load(const std::string& file);

		void _load(xml::ElementPtr node, const std::string& file, Version version);

		/** Load layout file
			@param _file name of layout
			@param _prefix will be added to all loaded widgets names
			@param _parent widget to load on
			@return Return vector of pointers of loaded root Widgets (root == without parents)
		*/
		//@ExportToLua
		VectorWidgetPtr& LoadLayout(const std::string& file, const std::string& prefix = "", Widget* parent = nullptr);

		/** Unload layout file */
		//@ExportToLua
		void UnloadLayout(VectorWidgetPtr& widgets);

		/** find the Widget by name */
		//@ExportToLua
		Widget* FindWidget(VectorWidgetPtr& widgets, const std::string name);

	private:
		void ParseLayout(VectorWidgetPtr& widgets, xml::ElementPtr root);
		void ParseWidget(VectorWidgetPtr& widgets, xml::ElementEnumerator& widget, Widget* parent);

	private:
		VectorWidgetPtr mVectorWidgetPtr;

		std::string layoutPrefix;
		Widget* layoutParent;

	};

} // namespace GUI

#endif // __LAYOUT_MANAGER_H__

