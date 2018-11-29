#include "Precompiled.h"
#include "DataFileStream.h"

namespace GUI
{

	DataFileStream::DataFileStream() :
		DataStream(),
		mFileStream(nullptr)
	{
	}

	DataFileStream::DataFileStream(std::ifstream* stream) :
		DataStream(stream),
		mFileStream(stream)
	{
	}

	DataFileStream::~DataFileStream()
	{
		if (mFileStream != nullptr)
		{
			mFileStream->close();
			mFileStream = nullptr;
		}
	}

} // namespace GUI
