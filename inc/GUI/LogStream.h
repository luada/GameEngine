#ifndef __LOG_STREAM_H__
#define __LOG_STREAM_H__

#include "Prerequest.h"
#include <fstream>
#include <iostream>
#include <string>

namespace GUI
{

	class GUI_EXPORT LogStream
	{
		friend class LogManager;

	public:
		struct LogStreamEnd { };

	public:
		LogStream& operator<<(const LogStreamEnd& endl);

		template <typename T>
		inline LogStream& operator<<(T value)
		{
			if (GetSTDOutputEnabled()) std::cout << value;
			if (mStream.is_open()) mStream << value;
			return *this;
		}

		const std::string& GetFileName() const { return mFileName; }

	private:
		LogStream();
		~LogStream();

		LogStream(const std::string& file);

		void Start(const std::string& section, const std::string& level);

		bool GetSTDOutputEnabled();

		void Lock() const { }
		void Release() const { }

	private:
		std::ofstream mStream;
		std::string mFileName;
	};

} // namespace GUI

#endif // __LOG_STREAM_H__
