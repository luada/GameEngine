#include "Precompiled.h"
#include "DataStream.h"

namespace GUI
{

	DataStream::DataStream() :
		mStream(nullptr),
		mSize((size_t)-1)
	{
	}

	DataStream::DataStream(std::istream* stream) :
		mStream(stream),
		mSize((size_t)-1)
	{
	}

	DataStream::~DataStream()
	{
	}

	size_t DataStream::size()
	{
		if (mStream == nullptr) return 0;
		if (mSize == (size_t)-1)
		{
			mStream->seekg (0, std::ios::end);
			mSize = mStream->tellg();
			mStream->seekg (0, std::ios::beg);
		}
		return mSize;
	}

	bool DataStream::Eof()
	{
		return mStream == nullptr ? true : mStream->eof();
	}

	void DataStream::Readline(std::string& source, Char delim)
	{
		if (mStream == nullptr) return;
		std::getline(*mStream, source, (char)delim);
	}

	size_t DataStream::Read(void* buf, size_t count)
	{
		if (mStream == nullptr) return 0;
		size_t curCount = std::min(size(), count);
		mStream->read((char*)buf, curCount);
		return curCount;
	}

} // namespace GUI
