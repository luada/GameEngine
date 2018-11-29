#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include "Prerequest.h"
#include <exception>
#include <string>

namespace GUI
{

	class GUI_EXPORT Exception : public std::exception
	{
	protected:
		std::string mDescription;
		std::string mSource;
		std::string mFile;
		long mLine;
		mutable std::string mFullDesc;

	public:
		Exception(const std::string& description, const std::string& source, const char* file, long line);

		Exception(const Exception& rhs);

		// Needed for  compatibility with std::exception
		~Exception() throw() { }

		Exception& operator = (const Exception& rhs);

		virtual const std::string& GetFullDescription() const;

		virtual const std::string &GetSource() const { return mSource; }

		virtual const std::string &GetFile() const { return mFile; }

		virtual long GetLine() const { return mLine; }

		virtual const std::string& GetDescription() const { return mDescription; }

		// Override std::exception::what
		const char* What() const throw() { return GetFullDescription().c_str(); }

	};

} // namespace GUI

#endif // __EXCEPTION_H__
