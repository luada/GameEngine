#ifndef __BASE_MANAGER_H__
#define __BASE_MANAGER_H__

#include <GUI.h>
#include "LayerManager.h"
#include "SkinManager.h"
#include "StatisticInfo.h"
#include "InputFocusInfo.h"
#include "script/ILuaScriptMgr.h"

#include <d3dx9.h>

#include "InputManager.h"
#include "PointerManager.h"

namespace GUI { class DirectXPlatform; }

namespace base
{

	class BaseManager :
		public input::InputManager,
		public input::PointerManager
	{
	public:
		BaseManager();
		virtual ~BaseManager();

		virtual void Prepare(int argc, char **argv); 
		bool Create(); 
		void Destroy(); 
		void Run();
		void Quit() { mExit = true; }

		void SetWindowCaption(const std::string& text);
		void CreateDefaultScene() { }

		GUI::Gui* GetGUI() { return mGUI; }
		const std::string& GetRootMedia() { return mRootMedia; }
		void SetResourceFilename(const std::string& flename) { mResourceFileName = flename; }
		void AddResourceLocation(const std::string& name, bool recursive = false);
		diagnostic::StatisticInfo * GetStatisticInfo() { return mInfo; }

	/*internal:*/
		void _windowResized();

	protected:
		virtual void CreateScene() { }
		virtual void DestroyScene() { }

		virtual void SetupResources();

		virtual void InjectMouseMove(int absx, int absy, int absz);
		virtual void InjectMousePress(int absx, int absy, GUI::MouseButton id);
		virtual void InjectMouseRelease(int absx, int absy, GUI::MouseButton id);
		virtual void InjectKeyPress(GUI::KeyCode key, GUI::Char text);
		virtual void InjectKeyRelease(GUI::KeyCode key);

	private:
		void CreateGui();
		void DestroyGui();

		void WindowAdjustSettings(HWND hWnd, int width, int height, bool fullScreen);
		void UpdateFPS();

		void ResizeRender(int width, int height);
		bool CreateRender(int width, int height, bool windowed);
		void DrawOneFrame();
		void DestroyRender();

	private:
		GUI::Gui* mGUI;
		ILuaScriptMgr* mLuaScriptMgr;
		GUI::DirectXPlatform* mPlatform;
		diagnostic::StatisticInfo* mInfo;
		diagnostic::InputFocusInfo* mFocusInfo;

		HWND hWnd;
	    IDirect3D9 *mD3d;
		IDirect3DDevice9 *mDevice;
	    D3DPRESENT_PARAMETERS mD3dpp;
		HINSTANCE hInstance;

		bool mExit;

		std::string mRootMedia;
		std::string mResourceFileName;
		bool mIsDeviceLost;
	};

} // namespace base

#endif // __BASE_MANAGER_H__
