#ifndef __DX_DATA_MANAGER_H__
#define __DX_DATA_MANAGER_H__

#include "Prerequest.h"
#include "Instance.h"
#include "DataManager.h"

namespace GUI
{

	class DirectXDataManager :
		public DataManager
	{
		INSTANCE_HEADER(DirectXDataManager)

	public:
		void Initialise();
		void Shutdown();

		virtual IDataStream* GetData(const std::string& name);

		virtual bool IsDataExist(const std::string& name);

		virtual const VectorString& GetDataListNames(const std::string& pattern);

		virtual const std::string& GetDataPath(const std::string& name);

	/*internal:*/
		void AddResourceLocation(const std::string& name, bool recursive);

	private:
		struct ArhivInfo
		{
			std::string name;
			bool recursive;
		};
		typedef std::vector<ArhivInfo> VectorArhivInfo;
		VectorArhivInfo mPaths;
	};

} // namespace GUI

#endif // __DX_DATA_MANAGER_H__
