#ifndef __PLUGIN_MANAGER_H__
#define __PLUGIN_MANAGER_H__

#include "Prerequest.h"
#include "Instance.h"
#include "Plugin.h"
#include "XmlDocument.h"
#include "Version.h"
#include <set>

namespace GUI
{

	/*!	\brief Plugin manager. Load/unload and register plugins.
	*/
	class GUI_EXPORT PluginManager
	{
		INSTANCE_HEADER(PluginManager)

	public:
		typedef void (*DLL_START_PLUGIN)(void);
		typedef void (*DLL_STOP_PLUGIN)(void);

	public:
		void Initialise();
		void Shutdown();

	public:
		//!	Load plugin
		bool LoadPlugin(const std::string& file);

		//!	Unload plugin
		void UnloadPlugin(const std::string& file);

		/** Load additional GUI *_plugin.xml file */
		bool Load(const std::string& file);
		void _load(xml::ElementPtr node, const std::string& file, Version version);

		/*!	Install plugin
			@remarks Calls from plugin
		*/
		void InstallPlugin(IPlugin* plugin);

		/*!	Uninstall plugin
			@remarks Calls from plugin
		*/
		void UninstallPlugin(IPlugin* plugin);

		//!	Unload all plugins
		void UnloadAllPlugins();

	private:
		//!	List of dynamic libraries
		typedef std::map <std::string, DynLib*> DynLibList;

		//!	List of plugins
		typedef std::set <IPlugin*> PluginList;

		//!	Loaded libraries
		DynLibList mLibs;

		//!	Installed plugins
		PluginList mPlugins;

	};

}

#endif // __PLUGIN_MANAGER_H__
