#ifndef __DYNLIB_H__
#define __DYNLIB_H__

#include "Prerequest.h"
#include <string>


#if PLATFORM == PLATFORM_WIN32
#    define DYNLIB_HANDLE hInstance
#    define DYNLIB_LOAD(a) LoadLibraryA(a)
#    define DYNLIB_GETSYM(a, b) GetProcAddress(a, b)
#    define DYNLIB_UNLOAD(a) !FreeLibrary(a)

struct HINSTANCE__;
typedef struct HINSTANCE__* hInstance;

#elif PLATFORM == PLATFORM_LINUX
#    define DYNLIB_HANDLE void*
#    define DYNLIB_LOAD(a) Dlopen(a, RTLD_LAZY | RTLD_GLOBAL)
#    define DYNLIB_GETSYM(a, b) Dlsym(a, b)
#    define DYNLIB_UNLOAD(a) Dlclose(a)

#elif PLATFORM == PLATFORM_APPLE
#    include <CoreFoundation/CFBundle.h>
#    define DYNLIB_HANDLE CFBundleRef
#    define DYNLIB_LOAD(a) Mac_loadExeBundle(a)
#    define DYNLIB_GETSYM(a, b) Mac_getBundleSym(a, b)
#    define DYNLIB_UNLOAD(a) Mac_unloadExeBundle(a)
#endif

namespace GUI
{

	/*! @brief Resource holding data about a dynamic library.

		@remarks
		This class holds the data required to get symbols from
		libraries loaded at run-time (i.e. from DLL's for so's)
	*/
	class GUI_EXPORT DynLib
	{
		friend class DynLibManager;

	protected:
		DynLib(const std::string &name);

		~DynLib();

	public:

		/*! Load the library
		*/
		bool Load();

		/*! Unload the library
		*/
		void Unload();

		//! Get the name of the library
		std::string GetName(void) const { return mName; }

		/**
			Returns the address of the given symbol from the loaded library.
			@param
				strName The name of the symbol to search for
			@returns
				If the function succeeds, the returned value is a handle to the symbol.
				If the function fails, the returned value is <b>nullptr</b>.
		*/
		void* GetSymbol(const std::string& strName) const throw();

	protected:
		//! Gets the last loading error
		std::string DynlibError(void);


	protected:
		//!	Name of library
		std::string mName;

		//! Handle to the loaded library.
		DYNLIB_HANDLE mInstance;
	};

}

#endif // __DYNLIB_H__
