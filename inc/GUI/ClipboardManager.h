#ifndef __CLIPBOARD_MANAGER_H__
#define __CLIPBOARD_MANAGER_H__

#include "Prerequest.h"
#include "Instance.h"
#include "Types.h"
#include "UString.h"

namespace GUI
{

	class GUI_EXPORT ClipboardManager
	{
		INSTANCE_HEADER(ClipboardManager)

	public:
		void Initialise();
		void Shutdown();

		//@ExportToLua
		static ClipboardManager& Instance()
		{
			return GetInstance();
		}

		/** Set current data in clipboard
			@param _type of Data (for example "Text")
			@param _data
		*/
		//@ExportToLua
		void SetClipboardData(const std::string& type, const std::string& data);

		/** Clear specific type data
			@param _type of data to delete (for example "Text")
		*/
		//@ExportToLua
		void ClearClipboardData(const std::string& type);

		/** Get specific type data
			@param _type of data to Get (for example "Text")
		*/
		//@ExportToLua
		std::string GetClipboardData(const std::string& type);

	private:
		MapString mClipboardData;

#if PLATFORM == PLATFORM_WIN32
	size_t mHwnd;
	UString mPutTextInClipboard;
#endif

	};

}

#endif // __CLIPBOARD_MANAGER_H__

