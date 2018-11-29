#ifndef __I_DATA_STREAM_H__
#define __I_DATA_STREAM_H__

#include "Prerequest.h"
#include "Types.h"

namespace GUI
{

	class GUI_EXPORT IDataStream
	{
	public:
		virtual ~IDataStream() { }

		virtual bool Eof() = 0;
		virtual size_t size() = 0;
		virtual void Readline(std::string& source, Char delim = '\n') = 0;
		virtual size_t Read(void* buf, size_t count) = 0;

	};

} // namespace GUI

#endif // __I_DATA_STREAM_H__
