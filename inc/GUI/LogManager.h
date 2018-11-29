#ifndef __LOG_MANAGER_H__
#define __LOG_MANAGER_H__

#include "Prerequest.h"
#include "LogStream.h"
#include <map>

namespace GUI
{

	#define LOGGING(section, level, text) \
		GUI::LogManager::Out(section, GUI::LogManager::level) \
		<< text \
		<< GUI::LogManager::InfoMsg(__FILE__, __LINE__) \
		<< GUI::LogManager::end()

	class GUI_EXPORT LogManager
	{

	public:
		enum LogLevel
		{
			Info,
			warning,
			Error,
			Critical,
			EndLogLevel
		};

	public:
		static void Shutdown();
		static void Initialise();

		static void RegisterSection(const std::string& section, const std::string& file);
		static void UnregisterSection(const std::string& section);

		static LogStream& Out(const std::string& section, LogLevel level);
		static const std::string& InfoMsg(const char * file /* = __FILE__*/, int line /* = __LINE__*/);

		static const LogStream::LogStreamEnd& end();

		// set logging enabled on std output device
		static void SetSTDOutputEnabled(bool enable);
		static bool GetSTDOutputEnabled();

	private:
		LogManager();
		~LogManager();

	public:
		static const std::string General;
		static const std::string separator;

		static LogStream::LogStreamEnd endl;
		static const std::string LevelsName[EndLogLevel];

	private:
		static LogManager * msInstance;
		typedef std::map<std::string, LogStream*>  MapLogStream;
		MapLogStream mMapSectionFileName;
		bool mSTDOut;
	};

} // namespace GUI

#endif // __LOG_MANAGER_H__
