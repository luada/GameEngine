#ifndef __DATA_STREAM_H__
#define __DATA_STREAM_H__

#include "Prerequest.h"
#include "IDataStream.h"

namespace GUI
{

	class GUI_EXPORT DataStream : public IDataStream
	{
	public:
		DataStream();
		DataStream(std::istream* stream);
		virtual ~DataStream();

		virtual bool Eof();
		virtual size_t size();
		virtual void Readline(std::string& source, Char delim);
		virtual size_t Read(void* buf, size_t count);

	protected:
		std::istream* mStream;
		size_t mSize;
	};

} // namespace GUI

#endif // __DATA_STREAM_H__
