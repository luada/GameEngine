#include "Precompiled.h"
#include "LogManager.h"
#include <sstream>
#include <assert.h> // REMOVEME

namespace GUI
{

	const std::string LogManager::LevelsName[EndLogLevel] =
	{
		"Info",
		"warning",
		"Error",
		"Critical"
	};

	const std::string LogManager::General = "General";
	const std::string LogManager::separator = "  |  ";

	LogStream::LogStreamEnd LogManager::endl;
	LogManager* LogManager::msInstance = 0;

	LogManager::LogManager()
	{
		msInstance = this;
		mSTDOut = true;
	}

	LogManager::~LogManager()
	{
		MapLogStream& mapStream = msInstance->mMapSectionFileName;
		for (MapLogStream::iterator iter=mapStream.begin(); iter!=mapStream.end(); ++iter)
		{
			LogStream * stream = iter->second;
			if (stream == 0) continue;

			for (MapLogStream::iterator iter2=iter; iter2!=mapStream.end(); ++iter2)
			{
				if (iter2->second == stream) iter2->second = 0;
			}
			delete stream;
		}
		mapStream.clear();
		msInstance = nullptr;
	}

	void LogManager::Shutdown()
	{
		if (msInstance != nullptr)
		{
			delete msInstance;
			msInstance = nullptr;
		}
	}

	void LogManager::Initialise()
	{
		if (msInstance == nullptr)
		{
			msInstance = new LogManager();
		}
	}

	LogStream& LogManager::Out(const std::string& section, LogLevel level)
	{
		static LogStream empty;

		if (msInstance == nullptr)
			return empty;

		MapLogStream& mapStream = msInstance->mMapSectionFileName;
		MapLogStream::iterator iter = mapStream.find(section);
		if (iter == mapStream.end())
			return empty;

		if (level >= EndLogLevel)
			level = Info;

		iter->second->Start(section, LevelsName[level]);

		return *(iter->second);
	}

	void LogManager::RegisterSection(const std::string& section, const std::string& file)
	{
		if (0 == msInstance) new LogManager();

		MapLogStream& mapStream = msInstance->mMapSectionFileName;
		/*MapLogStream::iterator iter = mapStream.find(section);
		if (iter != mapStream.end())
		{
			delete iter->second;
			mapStream.erase(iter);
		}*/

		LogStream * stream = 0;
		for (MapLogStream::iterator iter=mapStream.begin(); iter!=mapStream.end(); ++iter)
		{
			if (iter->second->GetFileName() == file)
			{
				stream = iter->second;
				break;
			}
		}
		if (0 == stream)
			stream = new LogStream(file);

		mapStream[section] = stream;
	}

	void LogManager::UnregisterSection(const std::string& section)
	{
		MapLogStream& mapStream = msInstance->mMapSectionFileName;
		MapLogStream::iterator iter = mapStream.find(section);
		if (iter == mapStream.end()) return;

		LogStream * stream = iter->second;
		mapStream.erase(iter);

		for (iter=mapStream.begin(); iter!=mapStream.end(); ++iter)
		{
			if (iter->second == stream)
				return;
		}

		delete stream;

		if (mapStream.size() == 0) Shutdown();
	}

	const std::string& LogManager::InfoMsg(const char * file /* = __FILE__*/, int line /* = __LINE__*/)
	{
		std::ostringstream stream;
		stream << separator << file << separator << line;

		static std::string ret;
		ret = stream.str();
		return ret;
	}

	const LogStream::LogStreamEnd& LogManager::end()
	{
		return endl;
	}

	void LogManager::SetSTDOutputEnabled(bool enable)
	{
		assert(msInstance);
		msInstance->mSTDOut = enable;
	}

	bool LogManager::GetSTDOutputEnabled()
	{
		assert(msInstance);
		return msInstance->mSTDOut;
	}

} // namespace GUI

