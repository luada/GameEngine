#include "Precompiled.h"
#include "PluginManager.h"
#include "DynLibManager.h"

namespace GUI
{
	const std::string XML_TYPE("Plugin");

	INSTANCE_IMPLEMENT(PluginManager)

	void PluginManager::Initialise()
	{
		ASSERT(!mIsInitialise, INSTANCE_TYPE_NAME << " initialised twice");
		LOG(Info, "* Initialise: " << INSTANCE_TYPE_NAME);

		ResourceManager::GetInstance().RegisterLoadXmlDelegate(XML_TYPE) = NewDelegate(this, &PluginManager::_load);

		LOG(Info, INSTANCE_TYPE_NAME << " successfully initialized");
		mIsInitialise = true;
	}

	void PluginManager::Shutdown()
	{
		if (!mIsInitialise) return;
		LOG(Info, "* Shutdown: " << INSTANCE_TYPE_NAME);

		UnloadAllPlugins();
		ResourceManager::GetInstance().UnregisterLoadXmlDelegate(XML_TYPE);

		LOG(Info, INSTANCE_TYPE_NAME << " successfully shutdown");
		mIsInitialise = false;
	}

	bool PluginManager::LoadPlugin(const std::string& file)
	{
		// check initialise
		ASSERT(mIsInitialise, INSTANCE_TYPE_NAME << "used but not initialised");

		// Load plugin library
		DynLib* lib = DynLibManager::GetInstance().Load(file);
		if (!lib)
		{
			LOG(Error, "Plugin '" << file << "' not found");
			return false;
		}

		// Call startup function
		DLL_START_PLUGIN pFunc = (DLL_START_PLUGIN)lib->GetSymbol("dllStartPlugin");
		if (!pFunc)
		{
			LOG(Error, "Cannot find symbol 'dllStartPlugin' in library " << file);
			return false;
		}

		// Store for later unload
		mLibs[file] = lib;

		// This must call installPlugin
		pFunc();

		return true;
	}

	void PluginManager::UnloadPlugin(const std::string& file)
	{
		// check initialise
		ASSERT(mIsInitialise, INSTANCE_TYPE_NAME << "used but not initialised");

		DynLibList::iterator it = mLibs.find(file);
		if (it != mLibs.end())
		{
			// Call plugin shutdown
			DLL_STOP_PLUGIN pFunc = (DLL_STOP_PLUGIN)(*it).second->GetSymbol("dllStopPlugin");

			ASSERT(nullptr != pFunc, INSTANCE_TYPE_NAME << "Cannot find symbol 'dllStopPlugin' in library " << file);

			// this must call uninstallPlugin
			pFunc();
			// Unload Library (destroyed by DynLibManager)
			DynLibManager::GetInstance().Unload((*it).second);
			mLibs.erase(it);
		}
	}

	bool PluginManager::Load(const std::string& file)
	{
		return ResourceManager::GetInstance()._loadImplement(file, true, XML_TYPE, INSTANCE_TYPE_NAME);
	}

	void PluginManager::_load(xml::ElementPtr node, const std::string& file, Version version)
	{
		xml::ElementEnumerator curNode = node->GetElementEnumerator();
		while (curNode.Next())
		{
			if (curNode->GetName() == "path")
			{
				std::string source;
				if (curNode->findAttribute("source", source))
					LoadPlugin(source);
			}
			else if (curNode->GetName() == "Plugin")
			{
				std::string source, source_debug;

				xml::ElementEnumerator source_node = curNode->GetElementEnumerator();
				while (source_node.Next("Source"))
				{
					std::string build = source_node->findAttribute("build");
					if (build == "Debug")
						source_debug = source_node->GetContent();
					else
						source = source_node->GetContent();
				}
#if DEBUG_MODE == 0
				if (!source.empty())
					LoadPlugin(source);
#else
				if (!source_debug.empty())
					LoadPlugin(source_debug);
#endif
			}
		}
	}

	void PluginManager::InstallPlugin(IPlugin* plugin)
	{
		// check initialise
		ASSERT(mIsInitialise, INSTANCE_TYPE_NAME << "used but not initialised");

		LOG(Info, "Installing curPlugin: " << plugin->GetName());

		mPlugins.insert(plugin);
		plugin->Install();

		plugin->Initialize();

		LOG(Info, "Plugin successfully installed");
	}

	void PluginManager::UninstallPlugin(IPlugin* plugin)
	{
		// check initialise
		ASSERT(mIsInitialise, INSTANCE_TYPE_NAME << "used but not initialised");

		LOG(Info, "Uninstalling curPlugin: " << plugin->GetName());
		PluginList::iterator it = mPlugins.find(plugin);
		if (it != mPlugins.end())
		{
			plugin->Shutdown();
			plugin->Uninstall();
			mPlugins.erase(it);
		}
		LOG(Info, "Plugin successfully uninstalled");
	}

	void PluginManager::UnloadAllPlugins()
	{
		while (!mLibs.empty())
			UnloadPlugin((*mLibs.begin()).first);
	}

} // namespace GUI
