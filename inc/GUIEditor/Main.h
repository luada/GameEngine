#ifndef BASEMAIN_H__
#define BASEMAIN_H__

#include "precompiled.h"

#include "Main.h"

#if PLATFORM == PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif


#if PLATFORM == PLATFORM_WIN32
int main(int argc, char **argv);
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT argc) { return main(1, &strCmdLine); }
void OutException(const char * caption, const char * message) { ::MessageBoxA( NULL, message, caption, MB_OK | MB_ICONERROR | MB_TASKMODAL); }
#else
void OutException(const char * caption, const char * message) { std::cerr << caption << " : " << message; }
#endif

// simple shortcut
#define APP(cls) int main(int argc, char **argv) { return StartApp<cls>(argc, argv); }

template <class AppClass>
int StartApp(int argc, char **argv)
{
	try
	{
		AppClass * app = new AppClass();
		app->Prepare(argc, argv);
		if (app->Create())
		{
			app->Run();
			app->Destroy();
		}
		delete app;
		app = 0;
	}
	catch (GUI::Exception& _e)
	{
		OutException("An exception has occured", _e.GetFullDescription().c_str());
		return 1;
	}
	return 0;
}

#endif

