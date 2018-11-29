#include "DataFileStream.h"
#include "DirectXDataManager.h"
#include "DirectXDiagnostic.h"

#include <windows.h>

namespace GUI
{

	void ScanFolder(VectorString& result, const std::string& folder, bool recursive, const std::string& mask, bool fullpath)
	{
		std::string curFolder = folder;
		if (!curFolder.empty()) curFolder += "\\";
		std::vector<std::string> dir;

		WIN32_FIND_DATAA FindData;
		HANDLE file = FindFirstFileA((curFolder + mask).c_str(), &FindData);
		if (file != INVALID_HANDLE_VALUE)
		{
			do
			{
				std::string name = FindData.cFileName;
				if ((name == ".") || (name == "..")) continue;

				if (FindData.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN) continue;

				if (FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				{
					dir.push_back(curFolder + name);
				}
				else
				{
					if (fullpath)
						result.push_back(curFolder + name);
					else
						result.push_back(name);
				}

			}
			while (FindNextFileA(file, &FindData));
		}
		FindClose(file);

		if (recursive)
		{
			for (std::vector<std::string>::iterator iter = dir.begin(); iter!=dir.end(); ++iter)
			{
				ScanFolder(result, *iter, recursive, mask, fullpath);
			}
		}
	}

	INSTANCE_IMPLEMENT(DirectXDataManager)

	void DirectXDataManager::Initialise()
	{
		PLATFORM_ASSERT(false == mIsInitialise, INSTANCE_TYPE_NAME << " initialised twice");
		PLATFORM_LOG(Info, "* Initialise: " << INSTANCE_TYPE_NAME);

		PLATFORM_LOG(Info, INSTANCE_TYPE_NAME << " successfully initialized");
		mIsInitialise = true;
	}

	void DirectXDataManager::Shutdown()
	{
		if (false == mIsInitialise) return;
		PLATFORM_LOG(Info, "* Shutdown: " << INSTANCE_TYPE_NAME);

		PLATFORM_LOG(Info, INSTANCE_TYPE_NAME << " successfully shutdown");
		mIsInitialise = false;
	}

	IDataStream* DirectXDataManager::GetData(const std::string& name)
	{
		std::string filepath = GetDataPath(name);
		if (filepath.empty())
			return nullptr;

		std::ifstream* stream = new std::ifstream();
		stream->open(filepath.c_str(), std::ios_base::binary);

		if (!stream->is_open())
		{
			delete stream;
			return nullptr;
		}

		DataFileStream* data = new DataFileStream(stream);

		return data;
	}

	bool DirectXDataManager::IsDataExist(const std::string& name)
	{
		const VectorString& files = GetDataListNames(name);
		return (files.size() == 1);
	}

	const VectorString& DirectXDataManager::GetDataListNames(const std::string& pattern)
	{
		static VectorString result;
		result.clear();

		for (VectorArhivInfo::iterator item=mPaths.begin(); item!=mPaths.end(); ++item)
		{
			ScanFolder(result, (*item).name, (*item).recursive, pattern, false);
		}

		return result;
	}

	const std::string& DirectXDataManager::GetDataPath(const std::string& name)
	{
		static std::string path;
		VectorString result;

		for (VectorArhivInfo::iterator item=mPaths.begin(); item!=mPaths.end(); ++item)
		{
			ScanFolder(result, (*item).name, (*item).recursive, name, true);
		}

		path = result.size() == 1 ? result[0] : "";
		return path;
	}

	void DirectXDataManager::AddResourceLocation(const std::string& name, bool recursive)
	{
		ArhivInfo info;
		info.name = name;
		info.recursive = recursive;
		mPaths.push_back(info);
	}

} // namespace GUI
