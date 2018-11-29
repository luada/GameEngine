#include "Precompiled.h"
#include "DynLib.h"

#if PLATFORM == PLATFORM_WIN32
#	include <Windows.h>
#elif PLATFORM == PLATFORM_LINUX
#       include <dlfcn.h>
#endif

namespace GUI
{
	DynLib::DynLib(const std::string& name)
	{
		mName = name;
		mInstance = nullptr;
	}


	DynLib::~DynLib()
	{
	}


	bool DynLib::Load()
	{
		// Log library load
		LOG(Info, "Loading library " << mName);

		#if PLATFORM == PLATFORM_APPLE
			//APPLE SPECIFIC CODE HERE
		#else
			mInstance = (DYNLIB_HANDLE)DYNLIB_LOAD( mName.c_str() );
		#endif

		return mInstance != 0;
	}


	void DynLib::Unload()
	{
		// Log library unload
		LOG(Info, "Unloading library " << mName);
		#if PLATFORM == PLATFORM_APPLE
			//APPLE SPECIFIC CODE HERE
		#else
			if (DYNLIB_UNLOAD(mInstance))
			{
				EXCEPT("Could not unload dynamic library '" << mName << "'. System Error: " << DynlibError());
			}
		#endif
	}

	void* DynLib::GetSymbol(const std::string& strName) const throw()
	{
		#if PLATFORM == PLATFORM_APPLE
			//APPLE SPECIFIC CODE HERE
			return nullptr;
		#else
			return (void*)DYNLIB_GETSYM(mInstance, strName.c_str());
		#endif
	}

	std::string DynLib::DynlibError(void)
	{
#if PLATFORM == PLATFORM_WIN32
		LPVOID lpMsgBuf;
		FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER |
			FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			GetLastError(),
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPTSTR) &lpMsgBuf,
			0,
			NULL
			);
		std::string ret = (char*)lpMsgBuf;
		// Free the buffer.
		LocalFree( lpMsgBuf );
		return ret;
#else
		return "no unix error function defined yet";
#endif
	}

} // namespace GUI
