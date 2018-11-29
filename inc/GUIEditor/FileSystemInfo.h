#ifndef __FILE_SYSTEM_INFO_H__
#define __FILE_SYSTEM_INFO_H__

#include <GUI.h>
#if PLATFORM == PLATFORM_WIN32
#include <windows.h>
#include <io.h>
#else
#include <unistd.h>
#include <dirent.h>
#endif

#include <string>
#include <vector>

namespace common
{

	struct FileInfo
	{
		FileInfo(const std::wstring& name, bool folder) : name(name), folder(folder) { }
		std::wstring name;
		bool folder;
	};
	typedef std::vector<FileInfo> VectorFileInfo;

	inline bool IsAbsolutePath(const wchar_t* path)
	{
	#if PLATFORM == PLATFORM_WIN32
		if (isalpha(path[0]) && path[1] == ':')
			return true;
	#endif
		return path[0] == '/' || path[0] == '\\';
	}

	inline std::wstring ConcatenatePath(const std::wstring& base, const std::wstring& name)
	{
		if (base.empty() || IsAbsolutePath(name.c_str()))
			return name;
		else
#if PLATFORM == PLATFORM_WIN32
			return base + L'\\' + name;
#else
			return base + L'/' + name;
#endif
	}

	inline bool isReservedDir (const wchar_t *_fn)
	{
		// if "." /*or ".."*/
		return (_fn [0] == '.' && (_fn [1] == 0 /*|| (_fn [1] == '.' && _fn [2] == 0)*/));
	}

	inline void GetSystemFileList(VectorFileInfo& result, const std::wstring& folder, const std::wstring& mask)
	{
#if PLATFORM == PLATFORM_WIN32
		//FIXME add optional parameter?
		bool ms_IgnoreHidden = true;

		long lHandle, res;
		struct _wfinddata_t tagData;

		// pattern can contain a directory name, separate it from curMask
		size_t pos1 = mask.rfind ('/');
		size_t pos2 = mask.rfind ('\\');
		if (pos1 == mask.npos || ((pos2 != mask.npos) && (pos1 < pos2)))
			pos1 = pos2;
		std::wstring directory;
		if (pos1 != mask.npos)
			directory = mask.substr (0, pos1 + 1);

		std::wstring full_mask = ConcatenatePath(folder, mask);

		lHandle = _wfindfirst(full_mask.c_str(), &tagData);
		res = 0;
		while (lHandle != -1 && res != -1)
		{
			if (( !ms_IgnoreHidden || (tagData.attrib & _A_HIDDEN) == 0 ) &&
				(!isReservedDir (tagData.name)))
			{
				result.push_back(FileInfo(directory + tagData.name, (tagData.attrib & _A_SUBDIR) != 0));
			}
			res = _wfindnext( lHandle, &tagData );
		}
		// Close if we found any files
		if(lHandle != -1)
			_findclose(lHandle);
#else
		DIR *dir = opendir(GUI::UString(folder).AsUTF8_c_str());
		struct dirent *dp;

		if (dir == NULL) {
			/* Opendir() failed */
		}

		rewinddir (dir);

		while ((dp = readdir (dir)) != NULL)
		{
			if (!isReservedDir (GUI::UString(dp->d_name).AsWStr_c_str()))
				result.push_back(FileInfo(GUI::UString(dp->d_name).AsWStr(), (dp->d_type == DT_DIR)));
		}
#endif
	}

	inline std::wstring GetSystemCurrentFolder()
	{
#if PLATFORM == PLATFORM_WIN32
		wchar_t buff[MAX_PATH+1];
		::GetCurrentDirectoryW(MAX_PATH, buff);
		return buff;
#else
		char buff[PATH_MAX+1];
		getcwd(buff, PATH_MAX);
		return GUI::UString(buff).AsWStr();
#endif
	}

	typedef std::vector<std::wstring> VectorWString;
	inline void ScanFolder(VectorWString& result, const std::wstring& folder, bool recursive, const std::wstring& mask, bool fullpath)
	{
		std::wstring curFolder = folder;
		if (!curFolder.empty()) curFolder += L"/";

		VectorFileInfo curResult;
		GetSystemFileList(curResult, curFolder, mask);

		for (VectorFileInfo::const_iterator item=curResult.begin(); item!=curResult.end(); ++item)
		{
			if (item->folder) continue;

			if (fullpath)
				result.push_back(curFolder + item->name);
			else
				result.push_back(item->name);
		}

		if (recursive)
		{
			GetSystemFileList(curResult, curFolder, L"*");

			for (VectorFileInfo::const_iterator item=curResult.begin(); item!=curResult.end(); ++item)
			{
				if (!item->folder
					|| item->name == L".."
					|| item->name == L".") continue;
				ScanFolder(result, curFolder + item->name, recursive, mask, fullpath);
			}

		}
	}

}

#endif // __FILE_SYSTEM_INFO_H__
