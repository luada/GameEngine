#ifndef __WIDGET_USER_DATA_H__
#define __WIDGET_USER_DATA_H__

#include "Prerequest.h"
#include "WidgetDefines.h"
#include "Any.h"

namespace GUI
{
	/** UserData is parent of Widget class. Used to store any user data and strings inside widget */
	class GUI_EXPORT UserData
	{
	public:
		UserData() { }
		virtual ~UserData() { }

		/** Set user string */
		//@ExportToLua
		void SetUserString(const std::string& key, const std::string& value)
		{
			mMapUserString[key] = value;
		}

		/** Get user string or "" if not found */
		//@ExportToLua
		const std::string& GetUserString(const std::string& key)
		{
			MapString::iterator iter = mMapUserString.find(key);
			if (iter == mMapUserString.end())
			{
				static std::string empty;
				return empty;
			}
			return iter->second;
		}

		/** delete user string */
		//@ExportToLua
		bool ClearUserString(const std::string& key)
		{
			MapString::iterator iter = mMapUserString.find(key);
			if (iter != mMapUserString.end())
			{
				mMapUserString.erase(iter);
				return true;
			}
			return false;
		}

		/** Return true if user string with such key exist */
		//@ExportToLua
		bool IsUserString(const std::string& key)
		{
			return mMapUserString.find(key) != mMapUserString.end();
		}

		/** delete all user strings */
		//@ExportToLua
		void ClearUserStrings()
		{
			mMapUserString.clear();
		}

		/** Set any user data to store inside widget */
		void SetUserData(Any data) { mUserData = data; }

		/** Get user data and cast it to ValueType */
		template <typename ValueType>
		ValueType * GetUserData(bool _throw = true)
		{
			return mUserData.CastType<ValueType>(_throw);
		}

	/*internal:*/
		void _setInternalData(Any data) { mInternalData = data; }

		template <typename ValueType>
		ValueType * _getInternalData(bool _throw = true)
		{
			return mInternalData.CastType<ValueType>(_throw);
		}

	private:
		MapString mMapUserString;
		Any mUserData;

		Any mInternalData;

	};

} // namespace GUI

#endif // __WIDGET_USER_DATA_H__

