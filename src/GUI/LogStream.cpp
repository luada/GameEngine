#include "Precompiled.h"
#include "LogStream.h"
#include "LogManager.h"
#include <iomanip>
#include <time.h>

namespace GUI
{

	LogStream::LogStream() { }
	LogStream::~LogStream()
	{
		if (mStream.is_open())
		{
			mStream.close();
			Release();
		}
	}

	LogStream::LogStream(const std::string& file) : mFileName(file)
	{
		Lock();

		struct tm *current_time;
		time_t ctTime; time(&ctTime);
		current_time = localtime( &ctTime );

		mStream.open(mFileName.c_str(), std::ios_base::out);
		if (mStream.is_open())
		{
			mStream << " ---------------------------------------------------------------------------------------------------------------------------------- " << std::endl;
			mStream << "                                          loging report for : "
				<< std::setw(2) << std::setfill('0') << current_time->tm_mon + 1 << "/"
				<< std::setw(2) << std::setfill('0') << current_time->tm_mday << "/"
				<< std::setw(4) << std::setfill('0') << current_time->tm_year + 1900 << "   "
				<< std::setw(2) << std::setfill('0') << current_time->tm_hour << ":"
				<< std::setw(2) << std::setfill('0') << current_time->tm_min << ":"
				<< std::setw(2) << std::setfill('0') << current_time->tm_sec << std::endl;
			mStream << " ---------------------------------------------------------------------------------------------------------------------------------- " << std::endl << std::endl;
			mStream.close();
		}

		Release();
	}

	void LogStream::Start(const std::string& section, const std::string& level)
	{
		if (mStream.is_open())
		{
			mStream.close();
			Release();
		}

		Lock();

		struct tm *current_time;
		time_t ctTime; time(&ctTime);
		current_time = localtime( &ctTime );

		if (!mFileName.empty())
		{
			mStream.open(mFileName.c_str(), std::ios_base::app);
			if (mStream.is_open())
			{
				mStream << std::setw(2) << std::setfill('0') << current_time->tm_hour << ":"
					<< std::setw(2) << std::setfill('0') << current_time->tm_min << ":"
					<< std::setw(2) << std::setfill('0') << current_time->tm_sec << LogManager::separator
					<< section << LogManager::separator << level << LogManager::separator;
			}
		}
	}

	bool LogStream::GetSTDOutputEnabled()
	{
		return LogManager::GetSTDOutputEnabled();
	}

	LogStream& LogStream::operator<<(const LogStreamEnd& endl)
	{
		if (GetSTDOutputEnabled()) std::cout << std::endl;
		if (mStream.is_open())
		{
			mStream << std::endl;
			mStream.close();
		}
		Release();

		return *this;
	}

} // namespace GUI
