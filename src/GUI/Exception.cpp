#include "Precompiled.h"
#include "Exception.h"
#include "Utility.h"

namespace GUI
{

	Exception::Exception(const std::string& description, const std::string& source, const char* file, long line) :
		mDescription(description),
		mSource(source),
		mFile(file),
		mLine(line)
	{
	}

	Exception::Exception(const Exception& rhs) :
		mDescription(rhs.mDescription),
		mSource(rhs.mSource),
		mFile(rhs.mFile),
		mLine(rhs.mLine)
	{
	}

	Exception& Exception::operator = (const Exception& rhs)
	{
		mDescription = rhs.mDescription;
		mSource = rhs.mSource;
		mFile = rhs.mFile;
		mLine = rhs.mLine;
		mFullDesc = rhs.mFullDesc;
		return *this;
	}


	const std::string& Exception::GetFullDescription() const
	{
		if (mFullDesc.empty())
		{
			if ( mLine > 0 )
			{
				mFullDesc = utility::ToString("GUI EXCEPTION : ", mDescription, " in ", mSource, " at ", mFile, " (line ", mLine, ")");
			}
			else
			{
				mFullDesc = utility::ToString("GUI EXCEPTION : ", mDescription, " in ", mSource);
			}
		}

		return mFullDesc;
	}

} // namespace GUI
