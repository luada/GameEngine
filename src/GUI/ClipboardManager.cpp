#include "Precompiled.h"
#include "ClipboardManager.h"
#include "Gui.h"
#include "TextIterator.h"

#if PLATFORM == PLATFORM_WIN32
#include <windows.h>
#endif

namespace GUI
{

#if PLATFORM == PLATFORM_WIN32

	HWND g_hWnd = NULL;

	BOOL CALLBACK EnumWindowProc(HWND hWnd, LPARAM lParam)
	{
		DWORD dwProcessID = 0;
		::GetWindowThreadProcessId(hWnd, &dwProcessID);

		if (dwProcessID != (DWORD)lParam)
			return TRUE;

		if (::GetParent(hWnd) == NULL)
		{
			g_hWnd = hWnd;
			return FALSE;
		}

		return TRUE;
	}

	BOOL CALLBACK EnumChildWindowProc(HWND hWnd, LPARAM lParam)
	{
		DWORD dwProcessID = 0;
		::GetWindowThreadProcessId(hWnd, &dwProcessID);

		if (dwProcessID != ::GetCurrentProcessId())
			return TRUE;

		if (::GetWindowLong(hWnd, GWL_HINSTANCE) == lParam)
		{
			g_hWnd = hWnd;
			return FALSE;
		}

		return TRUE;
	}

#endif

	INSTANCE_IMPLEMENT(ClipboardManager)

	void ClipboardManager::Initialise()
	{
		ASSERT(!mIsInitialise, INSTANCE_TYPE_NAME << " initialised twice");
		LOG(Info, "* Initialise: " << INSTANCE_TYPE_NAME);

#if PLATFORM == PLATFORM_WIN32
		char buf[MAX_PATH];
		::GetModuleFileNameA(0, (LPCH)&buf, MAX_PATH);
		HINSTANCE instance = ::GetModuleHandleA(buf);

		::EnumChildWindows(::GetDesktopWindow(), (WNDENUMPROC)EnumWindowProc, (LPARAM)instance);
		mHwnd = (size_t)g_hWnd;

#endif

		LOG(Info, INSTANCE_TYPE_NAME << " successfully initialized");
		mIsInitialise = true;
	}

	void ClipboardManager::Shutdown()
	{
		if (!mIsInitialise) return;
		LOG(Info, "* Shutdown: " << INSTANCE_TYPE_NAME);

		LOG(Info, INSTANCE_TYPE_NAME << " successfully shutdown");
		mIsInitialise = false;
	}

	void ClipboardManager::SetClipboardData(const std::string& type, const std::string& data)
	{
		mClipboardData[type] = data;

#if PLATFORM == PLATFORM_WIN32
		if (type == "Text")
		{
			mPutTextInClipboard = TextIterator::GetOnlyText(UString(data));
			size_t size = (mPutTextInClipboard.size() + 1) * 2;
			if (::OpenClipboard((HWND)mHwnd))
			{
				::EmptyClipboard(); 
				HGLOBAL hgBuffer = ::GlobalAlloc(GMEM_DDESHARE, size);
				wchar_t * chBuffer = NULL;
				if ((hgBuffer) && (chBuffer = (wchar_t*)GlobalLock(hgBuffer)))
				{
					::memcpy(chBuffer, mPutTextInClipboard.AsWStr_c_str(), size);
					::GlobalUnlock(hgBuffer);
					::SetClipboardData(CF_UNICODETEXT, hgBuffer);
				}
				::CloseClipboard(); 
			}
		}
#endif
	}

	void ClipboardManager::ClearClipboardData(const std::string& type)
	{
		MapString::iterator iter = mClipboardData.find(type);
		if (iter != mClipboardData.end()) mClipboardData.erase(iter);
	}

	std::string ClipboardManager::GetClipboardData(const std::string& type)
	{
#if PLATFORM == PLATFORM_WIN32
		if (type == "Text")
		{
			UString buff;
			if ( ::OpenClipboard((HWND)mHwnd) )
			{
				HANDLE hData = ::GetClipboardData(CF_UNICODETEXT);
				wchar_t * chBuffer = NULL;
				if ((hData) && (chBuffer = (wchar_t*)::GlobalLock(hData)))
				{
					buff = chBuffer;
					::GlobalUnlock(hData);
				}
				::CloseClipboard();
			}
			if (mPutTextInClipboard != buff)
			{
				const UString& text = TextIterator::ToTagsString(buff);
				return text.AsUTF8();
			}

			MapString::iterator iter = mClipboardData.find(type);
			if (iter != mClipboardData.end()) return (*iter).second;
			return "";
		}
#endif

		MapString::iterator iter = mClipboardData.find(type);
		if (iter != mClipboardData.end()) return (*iter).second;
		return "";
	}

} // namespace GUI


