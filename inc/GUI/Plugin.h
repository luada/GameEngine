#ifndef __PLUGIN_H__
#define __PLUGIN_H__

#include "Prerequest.h"
#include <string>

namespace GUI
{

	/*!	\brief Base plugin class
	*/
	class GUI_EXPORT IPlugin
	{
	public:
		IPlugin() { }

		virtual ~IPlugin() { }

		/*!	Get the name of the plugin.
			@remarks An implementation must be supplied for this method to uniquely
			identify the plugin
		*/
		virtual const std::string& GetName() const = 0;

		/*!	Perform the plugin initial installation sequence
		*/
		virtual void Install() = 0;

		/*! Perform any tasks the plugin needs to perform on full system
			initialisation.
		*/
		virtual void Initialize() = 0;

		/*!	Perform any tasks the plugin needs to perform when the system is shut down
		*/
		virtual void Shutdown() = 0;

		/*!	Perform the final plugin uninstallation sequence
		*/
		virtual void Uninstall() = 0;
	};

}

#endif // __PLUGIN_H__
