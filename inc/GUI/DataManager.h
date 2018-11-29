#ifndef __DATA_MANAGER_H__
#define __DATA_MANAGER_H__

#include "Prerequest.h"
#include "IDataStream.h"

namespace GUI
{

	class GUI_EXPORT DataManager
	{
	public:
		DataManager();
		virtual ~DataManager() = 0;

		static DataManager& GetInstance();
		static DataManager* GetInstancePtr();

		virtual IDataStream* GetData(const std::string& name) = 0;

		virtual bool IsDataExist(const std::string& name) = 0;

		virtual const VectorString& GetDataListNames(const std::string& pattern) = 0;

		virtual const std::string& GetDataPath(const std::string& name) = 0;

	private:
		static DataManager* msInstance;
		bool mIsInitialise;
	};

} // namespace GUI

#endif // __DATA_MANAGER_H__
