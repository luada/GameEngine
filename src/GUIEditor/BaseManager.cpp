#include "precompiled.h"
#include "BaseManager.h"
#include "XmlDocument.h"
#include <DirectXPlatform.h>

#if PLATFORM == PLATFORM_WIN32
#	include <windows.h>
#pragma comment(lib, "Imm32.lib")
#endif


const char* WND_CLASS_NAME = "Demo_window";

TOLUA_API int  tolua_GUI_open (lua_State* tolua_S);
TOLUA_API int  tolua_script_open (lua_State* tolua_S);

int  tolua_main_open (lua_State* tolua_S)
{
	tolua_script_open(tolua_S);
	tolua_GUI_open(tolua_S);
	return 0;
}


LRESULT CALLBACK DXWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
		case WM_CREATE:
		{
			SetWindowLongPtr(hWnd, GWL_USERDATA, (LONG)((LPCREATESTRUCT)lParam)->lpCreateParams);
			break;
		}

		case WM_SIZE:
		{
			if (wParam != SIZE_MINIMIZED)
			{
				base::BaseManager *baseManager = (base::BaseManager*)GetWindowLongPtr(hWnd, GWL_USERDATA);
				if (baseManager)
					baseManager->_windowResized();
			}
			break;
		}

		case WM_CLOSE:
		{
			base::BaseManager *baseManager = (base::BaseManager*)GetWindowLongPtr(hWnd, GWL_USERDATA);
			if (baseManager)
				baseManager->Quit();
		}

		case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}

		default:
		{
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
		}
	}
	return 0;
}

namespace base
{

	BaseManager::BaseManager() :
		mGUI(nullptr),
		mPlatform(nullptr),
		mInfo(nullptr),
		mFocusInfo(nullptr),
		hWnd(0),
		mD3d(nullptr),
		mDevice(nullptr),
		mExit(false),
		mResourceFileName("core.xml"),
		mIsDeviceLost(false),
		mLuaScriptMgr(CreateLuaScriptProc(true))
	{
	}

	BaseManager::~BaseManager()
	{
		mLuaScriptMgr->Release();
		mLuaScriptMgr = NULL;
	}

	void BaseManager::_windowResized()
	{
		RECT rect = { 0, 0, 0, 0 };
		GetClientRect(hWnd, &rect);
		int width = rect.right - rect.left;
		int height = rect.bottom - rect.top;

		ResizeRender(width, height);

		if (mPlatform)
			mPlatform->GetRenderManagerPtr()->SetViewSize(width, height);

		SetInputViewSize(width, height);
	}

	bool BaseManager::Create()
	{
		WNDCLASSA wc = {
			0, (WNDPROC)DXWndProc, 0, 0, GetModuleHandle(NULL), LoadIcon(NULL, IDI_APPLICATION),
			LoadCursor(NULL, IDC_ARROW), (HBRUSH)GetStockObject(BLACK_BRUSH), NULL, (WND_CLASS_NAME),
		};
		RegisterClassA(&wc);

		hWnd = CreateWindowA(wc.lpszClassName, "", WS_POPUP,
			0, 0, 0, 0, GetDesktopWindow(), NULL, wc.hInstance, this);
		if (!hWnd)
		{
			//OutException("fatal error!", "failed create window");
			return false;
		}

		hInstance = wc.hInstance;

		const unsigned int width = 1024;
		const unsigned int height = 768;
		bool windowed = true;

		CreateRender(width, height, windowed);

		WindowAdjustSettings(hWnd, width, height, !mD3dpp.Windowed);

		CreateInput((size_t)hWnd);
		_windowResized();

		CreateGui();

		CreatePointerManager((size_t)hWnd);

		CreateScene();

		mLuaScriptMgr->LoadLuaFile("main.lua");

		return true;
	}

	void BaseManager::Run()
	{
		MSG msg;
		while (true)
		{
			while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			if (mExit)
				break;
			else if (msg.message == WM_QUIT)
				break;

			if (GetActiveWindow() == hWnd)
			{
				CaptureInput();
				UpdateFPS();
				DrawOneFrame();
			}
		}
	}

	void BaseManager::Destroy()
	{
		DestroyScene();

		DestroyPointerManager();

		DestroyGui();

		DestroyInput();

		DestroyRender();

		if (hWnd)
		{
			DestroyWindow(hWnd);
			hWnd = 0;
		}

		UnregisterClassA(WND_CLASS_NAME, hInstance);
	}

	void BaseManager::SetupResources()
	{
		GUI::xml::Document doc;

		if (!doc.Open(std::string("resources.xml")))
			doc.GetLastError();

		GUI::xml::ElementPtr root = doc.GetRoot();
		if (root == nullptr || root->GetName() != "Paths")
			return;

		GUI::xml::ElementEnumerator node = root->GetElementEnumerator();
		while (node.Next())
		{
			if (node->GetName() == "Path")
			{
				bool root = false;
				if (node->findAttribute("root") != "")
				{
					root = GUI::utility::ParseBool(node->findAttribute("root"));
					if (root) mRootMedia = node->GetContent();
				}
				AddResourceLocation(node->GetContent(), false);
			}
		}
	}

	void BaseManager::CreateGui()
	{
		mPlatform = new GUI::DirectXPlatform();
		mPlatform->Initialise(mDevice);

		SetupResources();

		mGUI = new GUI::Gui();
		mGUI->Initialise(mResourceFileName);

		mInfo = new diagnostic::StatisticInfo();

	}

	void BaseManager::DestroyGui()
	{
		if (mGUI)
		{
			if (mInfo)
			{
				delete mInfo;
				mInfo = nullptr;
			}

			if (mFocusInfo)
			{
				delete mFocusInfo;
				mFocusInfo = nullptr;
			}

			mGUI->Shutdown();
			delete mGUI;
			mGUI = nullptr;
		}

		if (mPlatform)
		{
			mPlatform->Shutdown();
			delete mPlatform;
			mPlatform = nullptr;
		}
	}

	void BaseManager::SetWindowCaption(const std::string & text)
	{
		SetWindowTextA(hWnd, text.c_str());
	}

	void BaseManager::Prepare(int argc, char **argv)
	{
	}

	void BaseManager::AddResourceLocation(const std::string & name, bool recursive)
	{
		mPlatform->GetDataManagerPtr()->AddResourceLocation(name, recursive);
	}

	void BaseManager::WindowAdjustSettings(HWND hWnd, int width, int height, bool fullScreen)
	{
		HWND hwndAfter = 0;
		unsigned long style = 0;
		unsigned long style_ex = 0;

		RECT rc = { 0, 0, width, height };

		if (fullScreen)
		{
			style = WS_POPUP | WS_VISIBLE;
			style_ex = GetWindowLong(hWnd, GWL_EXSTYLE) | (WS_EX_TOPMOST);
			hwndAfter = HWND_TOPMOST;
		}
		else
		{
			style = WS_POPUP | WS_VISIBLE | WS_CAPTION | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU | WS_THICKFRAME;
			style_ex = GetWindowLong(hWnd, GWL_EXSTYLE) &(~WS_EX_TOPMOST);
			hwndAfter = HWND_NOTOPMOST;
			AdjustWindowRect(&rc, style, false);
		}

		SetWindowLong(hWnd, GWL_STYLE, style);
		SetWindowLong(hWnd, GWL_EXSTYLE, style_ex);

		int desk_width  = GetSystemMetrics(SM_CXSCREEN);
		int desk_height = GetSystemMetrics(SM_CYSCREEN);

		int w = rc.right - rc.left;
		int h = rc.bottom - rc.top;
		int x = fullScreen ? 0 : (desk_width  - w) / 2;
		int y = fullScreen ? 0 : (desk_height - h) / 2;

		SetWindowPos(hWnd, hwndAfter, x, y, w, h, SWP_FRAMECHANGED | SWP_SHOWWINDOW);
	}

	void BaseManager::UpdateFPS()
	{
		if (mInfo)
		{
			// calc FPS
			static GUI::Timer timer;
			const unsigned long interval = 1000; 
			static int count_frames = 0;
			int accumulate = timer.GetMilliseconds();
			if (accumulate > interval)
			{
				mInfo->Change("FPS", (int)((unsigned long)count_frames * 1000 / accumulate));
				mInfo->Update();

				count_frames = 0;
				timer.Reset();
			}
			count_frames ++;
		}
	}

	void BaseManager::InjectMouseMove(int absx, int absy, int absz)
	{
		if (!mGUI)
			return;

		mGUI->InjectMouseMove(absx, absy, absz);
	}

	void BaseManager::InjectMousePress(int absx, int absy, GUI::MouseButton id)
	{
		if (!mGUI)
			return;

		mGUI->InjectMousePress(absx, absy, id);
	}

	void BaseManager::InjectMouseRelease(int absx, int absy, GUI::MouseButton id)
	{
		if (!mGUI)
			return;

		mGUI->InjectMouseRelease(absx, absy, id);
	}

	void BaseManager::InjectKeyPress(GUI::KeyCode key, GUI::Char text)
	{
		if (!mGUI)
			return;

		if(ImmIsIME(GetKeyboardLayout(0)))
		{   
			HIMC hIMC;        
			DWORD dwSize;        
			WCHAR lpWideStr[20];        
			memset(lpWideStr, 0, 20);        
			hIMC = ImmGetContext(hWnd);       
			dwSize = ImmGetCompositionStringW(hIMC, GCS_RESULTSTR, NULL, 0);       
			dwSize += sizeof(WCHAR);       
			ImmGetCompositionStringW(hIMC, GCS_RESULTSTR, lpWideStr, dwSize);

			for (INT i = 0; i < dwSize ;i++)         
			{             
				mGUI->InjectKeyPress(key, lpWideStr[i]);
			}         

			ImmReleaseContext(hWnd, hIMC);        
			return;    
		}

		if (key == GUI::KeyCode::Escape)
		{
			mExit = true;
			return;
		}
		else if (key == GUI::KeyCode::F12)
		{
			if (mFocusInfo == nullptr)
				mFocusInfo = new diagnostic::InputFocusInfo();

			bool visible = mFocusInfo->GetFocusVisible();
			mFocusInfo->SetFocusVisible(!visible);
		}

		mGUI->InjectKeyPress(key, text);
	}

	void BaseManager::InjectKeyRelease(GUI::KeyCode key)
	{
		if (!mGUI)
			return;

		mGUI->InjectKeyRelease(key);
	}

	void BaseManager::ResizeRender(int width, int height)
	{
		if (mDevice != nullptr)
		{
			if (mPlatform != nullptr)
				mPlatform->GetRenderManagerPtr()->DeviceLost();

			mD3dpp.BackBufferWidth = width;
			mD3dpp.BackBufferHeight = height;
			HRESULT hr = mDevice->Reset(&mD3dpp);

            if (hr == D3DERR_INVALIDCALL)
            {
                MessageBoxA( NULL, "Call to Reset() failed with D3DERR_INVALIDCALL! ",
                    "ERROR", MB_OK | MB_ICONEXCLAMATION );
            }

			if (mPlatform != nullptr)
				mPlatform->GetRenderManagerPtr()->DeviceRestore();
		}
	}

	bool BaseManager::CreateRender(int width, int height, bool windowed)
	{
		mD3d = Direct3DCreate9(D3D_SDK_VERSION);

		D3DDISPLAYMODE d3ddm;
		mD3d->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm);

		memset(&mD3dpp, 0, sizeof(mD3dpp));
		mD3dpp.AutoDepthStencilFormat = D3DFMT_D16;
		mD3dpp.EnableAutoDepthStencil = TRUE;
		mD3dpp.BackBufferCount  = 1;
		mD3dpp.BackBufferFormat = d3ddm.Format;
		mD3dpp.BackBufferWidth  = width;
		mD3dpp.BackBufferHeight = height;
		mD3dpp.hDeviceWindow = hWnd;
		mD3dpp.SwapEffect = D3DSWAPEFFECT_FLIP;
		mD3dpp.Windowed = windowed;

		if (FAILED(mD3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
			D3DCREATE_HARDWARE_VERTEXPROCESSING, &mD3dpp, &mDevice)))
		{
			//OutException("fatal error!", "failed create d3d9 mDevice");
			return false;
		}
		return true;
	}

	bool mIsDeviceLost = false;

	void BaseManager::DrawOneFrame()
	{
		if (mIsDeviceLost == true)
		{
			Sleep( 100 );

			HRESULT hr;
			if (FAILED(hr = mDevice->TestCooperativeLevel()))
			{
				if (hr == D3DERR_DEVICELOST)
					return;

				if (hr == D3DERR_DEVICENOTRESET)
				{
					if (mPlatform != nullptr)
						mPlatform->GetRenderManagerPtr()->DeviceLost();

					hr = mDevice->Reset( &mD3dpp );

					if (FAILED(hr))
						return;

					if (mPlatform != nullptr)
						mPlatform->GetRenderManagerPtr()->DeviceRestore();
				}

				return;
			}

			mIsDeviceLost = false;
		}

		if (SUCCEEDED(mDevice->BeginScene()))
		{
			mDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0x00000000, 1.0f, 0);
			mPlatform->GetRenderManagerPtr()->DrawOneFrame();
			mDevice->EndScene();
		}

		if (mDevice->Present(NULL, NULL, 0, NULL) == D3DERR_DEVICELOST)
			mIsDeviceLost = true;
	}

	void BaseManager::DestroyRender()
	{
		if (mDevice)
		{
			mDevice->Release();
			mDevice = 0;
		}
		if (mD3d)
		{
			mD3d->Release();
			mD3d = 0;
		}
	}

} // namespace base
