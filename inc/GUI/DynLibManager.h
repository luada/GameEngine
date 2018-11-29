#ifndef __DYN_LIB_MANAGER_H__
#define __DYN_LIB_MANAGER_H__

#include "Prerequest.h"
#include "Instance.h"
#include "DynLib.h"
#include <map>

namespace GUI
{

	/*!	\brief Manager of dynamic libraries
	*/
	class GUI_EXPORT DynLibManager
	{
		INSTANCE_HEADER(DynLibManager)

	public:
		void Initialise();
		void Shutdown();

		//!	Load library
		DynLib* Load(const std::string &fileName);
		//!	Unload library
		void Unload(DynLib *library);

	private:
		//! Dynamic libraries map
		typedef std::map <std::string, DynLib*> StringDynLibMap;
		//!	Loaded libraries
		StringDynLibMap mLibsMap;
	};

}

#endif // __DYN_LIB_MANAGER_H__
