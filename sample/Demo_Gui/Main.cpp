#include "precompiled.h"
#include "DemoKeeper.h"

#if WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif
#ifdef __cplusplus
extern "C" {
#endif

#if WIN32
	int Main(int argc, char **argv);
	INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT argc) { return Main(1, &strCmdLine); }
	void OutException(const char * caption, const char * message) { ::MessageBoxA( NULL, message, caption, MB_OK | MB_ICONERROR | MB_TASKMODAL); }
#else
	void OutException(const char * caption, const char * message) { std::cerr << caption << " : " << message; }
#endif

int Main(int argc, char **argv)
{

	try
	{
		demo::DemoKeeper * app = new demo::DemoKeeper();
		app->Prepare(argc, argv);
		if (app->Create())
		{
			app->Run();
			app->Destroy();
		}
		delete app;
		app = 0;
	}
	Catch (GUI::Exception& _e)
	{
		OutException("An exception has occured", _e.GetFullDescription().C_str());
    }

    return 0;
}

#ifdef __cplusplus
}
#endif
