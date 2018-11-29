#ifndef __XML_DOCUMENT_H__
#define __XML_DOCUMENT_H__

#include "Prerequest.h"
#include "UString.h"
#include "Diagnostic.h"
#include "DataStream.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <assert.h>

namespace GUI
{
	namespace xml
	{

		struct ElementType
		{
			enum Enum
			{
				Comment,
				Declaration,
				Normal,
				MAX
			};

			ElementType(Enum value = MAX) : value(value) { }
			friend bool operator == (ElementType const& a, ElementType const& b) { return a.value == b.value; }
			friend bool operator != (ElementType const& a, ElementType const& b) { return a.value != b.value; }

		private:
			Enum value;
		};

		struct ErrorType
		{
			enum Enum
			{
				OpenFileFail,
				CreateFileFail,
				IncorrectContent,
				NotClosedElements,
				NoXMLDeclaration,
				CloseNotOpenedElement,
				InconsistentOpenCloseElements,
				MoreThanOneXMLDeclaration,
				MoreThanOneRootElement,
				IncorrectAttribute,
				MAX
			};

			ErrorType(Enum value = MAX) : value(value) { }

			std::string Print() const { return GetValueName(value); }

		private:
			const char * GetValueName(int index) const
			{
				static const char * values[MAX + 1] =
				{
					"Failed to open XML file",
					"Failed to ceate XML file",
					"XML file contain incorrect content",
					"XML file contain not closed elements",
					"XML file without declaration",
					"XML file contain closed but not opened element",
					"XML file contain inconsistent elements",
					"XML file contain more than one declaration",
					"XML file contain more than one root element",
					"XML file contain incorrect attribute",
					""
				};
				return values[(index < MAX && index >= 0) ? index : MAX];
			}
		private:
			Enum value;
		};

		class Element;
		class Document;

		typedef Element * ElementPtr;
		typedef std::pair<std::string, std::string> PairAttribute;
		typedef std::vector<PairAttribute> VectorAttributes;
		typedef std::vector<ElementPtr> VectorElement;

		//----------------------------------------------------------------------//
		// class ElementEnumerator
		//----------------------------------------------------------------------//
		class GUI_EXPORT ElementEnumerator
		{
			friend class Element;

		private:
			ElementEnumerator(VectorElement::iterator begin, VectorElement::iterator end);

		public:
			bool Next();
			bool Next(const std::string& name);

			ElementPtr operator->() const { assert(m_current != m_end); return (*m_current); }
			ElementPtr Current() { assert(m_current != m_end); return (*m_current); }

	/*obsolete:*/
#ifndef DONT_USE_OBSOLETE

			OBSOLETE("use : bool ElementEnumerator::Next()")
			bool NextNode() { return Next(); }
			OBSOLETE("use : bool ElementEnumerator::Next(const std::string& name)")
			bool NextNode(const std::string& name) { return Next(name); }
			OBSOLETE("use : ElementPtr ElementEnumerator::Current()")
			ElementPtr CurrentNode() { return Current(); }

#endif // DONT_USE_OBSOLETE

		private:
			bool m_first;
			VectorElement::iterator m_current, m_end;
		};


		//----------------------------------------------------------------------//
		// class Element
		//----------------------------------------------------------------------//
		class GUI_EXPORT Element
		{
			friend class Document;

		public:
			~Element();

		private:
			Element(const std::string &_name, ElementPtr parent, ElementType type = ElementType::Normal, const std::string& content = "");
			void Save(std::ostream& stream, size_t level);

		public:
			ElementPtr CreateChild(const std::string& name, const std::string& content = "");

			template <typename T>
			void AddAttribute(const std::string &_key, const T& value)
			{
				mAttributes.push_back(PairAttribute(_key, utility::ToString(value)));
			}

			void AddAttribute(const std::string& key, const std::string& value);

			void RemoveAttribute(const std::string& key);

			void SetAttribute(const std::string& key, const std::string& value);

			template <typename T>
			void AddContent(const T& content)
			{
				mContent.empty() ? mContent = utility::ToString(content) : mContent += utility::ToString(" ", content);
			}

			void AddContent(const std::string& content);

			template <typename T>
			void SetContent(const T& content)
			{
				mContent = utility::ToString(content);
			}

			void SetContent(const std::string& content) { mContent = content; }

			void Clear();

			bool findAttribute(const std::string& name, std::string& value);
			std::string findAttribute(const std::string& name);

			const std::string& GetName() const { return mName; }
			const std::string& GetContent() const { return mContent; }
			const VectorAttributes& GetAttributes() const { return mAttributes; }
			ElementPtr GetParent() const { return mParent; }

			ElementEnumerator GetElementEnumerator() { return ElementEnumerator(mChilds.begin(), mChilds.end()); }

			ElementType GetType() const { return mType; }

			ElementPtr CreateCopy();

		private:
			std::string mName;
			std::string mContent;
			VectorAttributes mAttributes;
			VectorElement mChilds;
			ElementPtr mParent;
			ElementType mType;
		};

		//----------------------------------------------------------------------//
		// class Document
		//----------------------------------------------------------------------//
		class GUI_EXPORT Document
		{
		public:
			Document();
			~Document();

			bool Open(const std::string& filename);

			bool Open(const std::wstring& filename);

			bool Open(std::istream& stream);

			bool Open(const UString& filename) { return Open(filename.AsWStr()); }

			bool Open(IDataStream* data);

			bool Save(const std::string& filename);

			bool Save(const std::wstring& filename);

			bool Save(std::ostream& stream);

			bool Save(const UString& filename) { return Save(filename.AsWStr()); }

			void Clear();

			std::string GetLastError();

			void ClearLastError() { mLastError = ErrorType::MAX; }

			ElementPtr CreateDeclaration(const std::string& version = "1.0", const std::string& encoding = "UTF-8");
			ElementPtr CreateRoot(const std::string& name);

			ElementPtr GetRoot() const { return mRoot; }

		/*obsolete:*/
#ifndef DONT_USE_OBSOLETE

			OBSOLETE("use : ElementPtr Document::CreateDeclaration(const std::string& version, const std::string& encoding)")
			ElementPtr CreateInfo(const std::string& version = "1.0", const std::string& encoding = "UTF-8") { return CreateDeclaration(version, encoding); }

#endif // DONT_USE_OBSOLETE

		private:
			void SetLastFileError(const std::string& filename) { mLastErrorFile = filename; }

			void SetLastFileError(const std::wstring& filename) { mLastErrorFile = UString(filename).AsUTF8(); }

			bool ParseTag(ElementPtr &_currentNode, std::string content);

			bool CheckPair(std::string &_key, std::string &_value);

			bool ParseLine(std::string& line, ElementPtr& element);

			size_t find(const std::string& text, char _char, size_t start = 0);

			void ClearDeclaration();
			void ClearRoot();

		private:
			ElementPtr mRoot;
			ElementPtr mDeclaration;
			ErrorType mLastError;
			std::string mLastErrorFile;
			size_t mLine;
			size_t mCol;

		}; // class Document

		OBSOLETE("use : class GUI::xml::ElementEnumerator")
		typedef ElementEnumerator xmlNodeIterator;
		OBSOLETE("use : class GUI::xml::ElementPtr")
		typedef ElementPtr xmlNodePtr;
		OBSOLETE("use : class GUI::xml::Document")
		typedef Document xmlDocument;

	} // namespace xml

} // namespace GUI

#endif // __XML_DOCUMENT_H__

