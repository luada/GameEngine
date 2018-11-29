#ifndef __DATA_FILE_STREAM_H__
#define __DATA_FILE_STREAM_H__

#include "Prerequest.h"
#include "DataStream.h"

namespace GUI
{

	class GUI_EXPORT DataFileStream : public DataStream
	{
	public:
		DataFileStream();
		DataFileStream(std::ifstream* stream);
		~DataFileStream();

	private:
		std::ifstream* mFileStream;
	};

} // namespace GUI

#endif // __DATA_STREAM_H__
