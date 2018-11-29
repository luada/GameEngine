#include "Precompiled.h"
#include "XmlDocument.h"
#include "DataManager.h"

namespace GUI
{
	namespace xml
	{

		namespace utility
		{
			std::string Convert_from_xml(const std::string& string, bool& ok)
			{
				std::string ret;
				ok = true;

				size_t pos = string.find("&");
				if (pos == std::string::npos) return string;

				ret.reserve(string.size());
				size_t old = 0;
				while (pos != std::string::npos)
				{
					ret += string.substr(old, pos - old);

					size_t end = string.find(";", pos + 1);
					if (end == std::string::npos)
					{
						ok = false;
						return ret;
					}
					else
					{
						std::string tag = string.substr(pos, end - pos + 1);
						if (tag == "&amp;") ret += '&';
						else if (tag == "&lt;") ret += '<';
						else if (tag == "&gt;") ret += '>';
						else if (tag == "&apos;") ret += '\'';
						else if (tag == "&quot;") ret += '\"';
						else
						{
							ok = false;
							return ret;
						}
					}

					old = end + 1;
					pos = string.find("&", old);
				}
				ret += string.substr(old, std::string::npos);

				return ret;
			}

			std::string Convert_to_xml(const std::string& string)
			{
				std::string ret;

				size_t pos = string.find_first_of("&<>'\"");
				if (pos == std::string::npos) return string;

				ret.reserve(string.size() * 2);
				size_t old = 0;
				while (pos != std::string::npos)
				{
					ret += string.substr(old, pos - old);

					if (string[pos] == '&') ret += "&amp;";
					else if (string[pos] == '<') ret += "&lt;";
					else if (string[pos] == '>') ret += "&gt;";
					else if (string[pos] == '\'') ret += "&apos;";
					else if (string[pos] == '\"') ret += "&quot;";

					old = pos + 1;
					pos = string.find_first_of("&<>'\"", old);
				}
				ret += string.substr(old, std::string::npos);

				return ret;
			}

		}

		//----------------------------------------------------------------------//
		// class ElementEnumerator
		//----------------------------------------------------------------------//
		ElementEnumerator::ElementEnumerator(VectorElement::iterator begin, VectorElement::iterator end) :
			m_first(true),
			m_current(begin),
			m_end(end)
		{
		}

		bool ElementEnumerator::Next()
		{
			if (m_current == m_end) return false;
			else if (m_first)
			{
				m_first = false;
				return true;
			}
			++ m_current;
			if (m_current == m_end) return false;
			return true;
		}

		bool ElementEnumerator::Next(const std::string& name)
		{
			while (Next())
			{
				if ((*m_current)->GetName() == name) return true;
			}
			return false;
		}

		//----------------------------------------------------------------------//
		// class Element
		//----------------------------------------------------------------------//
		Element::Element(const std::string &name, ElementPtr parent, ElementType type, const std::string& content) :
			mName(name),
			mContent(content),
			mParent(parent),
			mType(type)
		{
		}

		Element::~Element()
		{
			for (VectorElement::iterator iter=mChilds.begin(); iter!=mChilds.end(); ++iter)
			{
				delete *iter;
			}
			mChilds.clear();
		}

		void Element::Save(std::ostream& stream, size_t level)
		{
			for (size_t tab=0; tab<level; ++tab) stream  << "    ";

			if (mType == ElementType::Declaration) stream << "<?";
			else stream << "<";
			stream << mName;

			for (VectorAttributes::iterator iter = mAttributes.begin(); iter != mAttributes.end(); ++iter)
			{
				stream << " " << iter->first << "=\"" << utility::Convert_to_xml(iter->second) << "\"";
			}

			bool empty = mChilds.empty();
			if (empty && mContent.empty())
			{
				if (mType == ElementType::Declaration) stream << "?>\n";
				else stream << "/>\n";
			}
			else
			{
				stream << ">";
				if (!empty) stream << "\n";
				if (!mContent.empty())
				{
					if (!empty)
					{
						for (size_t tab=0; tab<=level; ++tab) stream  << "    ";
					}
					stream << utility::Convert_to_xml(mContent);

					if (!empty) stream << "\n";
				}
				for (size_t child=0; child<mChilds.size(); child++)
				{
					mChilds[child]->Save(stream, level + 1);
				}

				if (!empty)
				{
					for (size_t tab=0; tab<level; ++tab)
						stream  << "    ";
				}
				stream << "</" << mName << ">\n";
			}

		}

		ElementPtr Element::CreateChild(const std::string& name, const std::string& content)
		{
			ElementPtr node = new Element(name, this, ElementType::Normal, content);
			mChilds.push_back(node);
			return node;
		}

		void Element::Clear()
		{
			for (VectorElement::iterator iter = mChilds.begin(); iter != mChilds.end(); ++iter) delete *iter;
			mChilds.clear();
			mContent.clear();
			mAttributes.clear();
		}

		bool Element::findAttribute(const std::string& name, std::string& value)
		{
			for (VectorAttributes::iterator iter=mAttributes.begin(); iter!=mAttributes.end(); ++iter)
			{
				if ( (*iter).first == name)
				{
					value = (*iter).second;
					return true;
				}
			}
			return false;
		}

		std::string Element::findAttribute(const std::string& name)
		{
			for (VectorAttributes::iterator iter=mAttributes.begin(); iter!=mAttributes.end(); ++iter)
			{
				if ( (*iter).first == name) return (*iter).second;
			}
			return "";
		}

		void Element::AddAttribute(const std::string& key, const std::string& value)
		{
			mAttributes.push_back(PairAttribute(key, value));
		}

		void Element::RemoveAttribute(const std::string& key)
		{
			for (size_t index=0; index<mAttributes.size(); ++index)
			{
				if (mAttributes[index].first == key)
				{
					mAttributes.erase(mAttributes.begin() + index);
					return;
				}
			}
		}

		ElementPtr Element::CreateCopy()
		{
			Element* elem = new Element(mName, nullptr, mType, mContent);
			elem->mAttributes = mAttributes;

			for (VectorElement::iterator iter=mChilds.begin(); iter!=mChilds.end(); ++iter)
			{
				Element* child = (*iter)->CreateCopy();
				child->mParent = elem;
				elem->mChilds.push_back(child);
			}

			return elem;
		}

		void Element::SetAttribute(const std::string& key, const std::string& value)
		{
			for (size_t index=0; index<mAttributes.size(); ++index)
			{
				if (mAttributes[index].first == key)
				{
					mAttributes[index].second = value;
					return;
				}
			}
			mAttributes.push_back(PairAttribute(key, value));
		}

		void Element::AddContent(const std::string& content)
		{
			if (mContent.empty()) mContent = content;
			else
			{
				mContent += " ";
				mContent += content;
			}
		}

#if COMPILER == COMPILER_MSVC && !defined(STLPORT)
		inline void Open_stream(std::ofstream& stream, const std::wstring& wide) { stream.open(wide.c_str()); }
		inline void Open_stream(std::ifstream& stream, const std::wstring& wide) { stream.open(wide.c_str()); }
#else
		inline void Open_stream(std::ofstream& stream, const std::wstring& wide) { stream.open(UString(wide).AsUTF8_c_str()); }
		inline void Open_stream(std::ifstream& stream, const std::wstring& wide) { stream.open(UString(wide).AsUTF8_c_str()); }
#endif

		//----------------------------------------------------------------------//
		// class Document
		//----------------------------------------------------------------------//
		Document::Document():
			mRoot(0),
			mDeclaration(0),
			mLastErrorFile(""),
			mLine(0),
			mCol(0)
		{
		}

		Document::~Document()
		{
			Clear();
		}

		bool Document::Open(const std::string& filename)
		{
			std::ifstream stream;
			stream.open(filename.c_str());

			if (!stream.is_open())
			{
				mLastError = ErrorType::OpenFileFail;
				SetLastFileError(filename);
				return false;
			}

			bool result = Open(stream);

			stream.close();
			return result;
		}

		bool Document::Open(const std::wstring& filename)
		{
			std::ifstream stream;
			Open_stream(stream, filename);

			if (!stream.is_open())
			{
				mLastError = ErrorType::OpenFileFail;
				SetLastFileError(filename);
				return false;
			}

			bool result = Open(stream);

			stream.close();
			return result;
		}

		bool Document::Open(std::istream& stream)
		{
			DataStream* data = new DataStream(&stream);

			bool result = Open(data);
			delete data;

			return result;
		}

		bool Document::Save(const std::string& filename)
		{
			std::ofstream stream;
			stream.open(filename.c_str());

			if (!stream.is_open())
			{
				mLastError = ErrorType::CreateFileFail;
				SetLastFileError(filename);
				return false;
			}

			bool result = Save(stream);

			if (!result)
			{
				SetLastFileError(filename);
			}

			stream.close();
			return result;
		}

		bool Document::Save(const std::wstring& filename)
		{
			std::ofstream stream;
			Open_stream(stream, filename);

			if (!stream.is_open())
			{
				mLastError = ErrorType::CreateFileFail;
				SetLastFileError(filename);
				return false;
			}

			bool result = Save(stream);

			if (!result)
			{
				SetLastFileError(filename);
			}

			stream.close();
			return result;
		}

		bool Document::Open(IDataStream* stream)
		{
			Clear();

			std::string line;
			std::string read;
			ElementPtr currentNode = 0;

			while (!stream->Eof())
			{
				stream->Readline(read, '\n');
				if (read.empty()) continue;
				if (read[read.size()-1] == '\r') read.erase(read.size()-1, 1);
				if (read.empty()) continue;

				mLine ++;
				mCol = 0; 
				if (read.empty()) continue;
				line += read;

				if (!ParseLine(line, currentNode))
				{
					return false;
				}

			} // while (!curStream.eof())

			if (currentNode)
			{
				mLastError = ErrorType::NotClosedElements;
				return false;
			}

			return true;
		}

		bool Document::Save(std::ostream& stream)
		{
			if (!mDeclaration)
			{
				mLastError = ErrorType::NoXMLDeclaration;
				return false;
			}

			stream << (char)0xEFu;
			stream << (char)0xBBu;
			stream << (char)0xBFu;

			mDeclaration->Save(stream, 0);
			if (mRoot) mRoot->Save(stream, 0);

			return true;
		}

		void Document::Clear()
		{
			ClearDeclaration();
			ClearRoot();
			mLine = 0;
			mCol = 0;
		}

		bool Document::ParseTag(ElementPtr &_currentNode, std::string content)
		{

			GUI::utility::Trim(content);

			if (content.empty())
			{
				if (_currentNode) _currentNode = _currentNode->CreateChild("");
				else
				{
					_currentNode = new Element("", 0);
					if (!mRoot) mRoot = _currentNode;
				}
				return true;
			}

			char simbol = content[0];
			bool tag_info = false;

			if (simbol == '!') return true; 

			if (simbol == '?')
			{
				tag_info = true;
				content.erase(0, 1); 
			}

			size_t start, end;
			if (simbol == '/')
			{
				if (_currentNode == 0)
				{
					if (!mRoot)
					{
						mLastError = ErrorType::CloseNotOpenedElement;
						return false;
					}
				}
				start = content.find_first_not_of(" \t", 1);
				if (start == content.npos)
				{
					content.clear();
				}
				else
				{
					end = content.find_last_not_of(" \t");
					content = content.substr(start, end - start+1);
				}
				if (_currentNode->GetName() != content)
				{
					mLastError = ErrorType::InconsistentOpenCloseElements;
					return false;
				}
				_currentNode = _currentNode->GetParent();
			}
			else
			{
				std::string cut = content;
				start = content.find_first_of(" \t/?", 1); // << превед
				if (start != content.npos)
				{
					cut = content.substr(0, start);
					content = content.substr(start);
				}
				else
				{
					content.clear();
				}

				if (_currentNode) _currentNode = _currentNode->CreateChild(cut);
				else
				{
					if (tag_info)
					{
						if (mDeclaration)
						{
							mLastError = ErrorType::MoreThanOneXMLDeclaration;
							return false;
						}
						_currentNode = new Element(cut, 0, ElementType::Comment);
						mDeclaration = _currentNode;
					}
					else
					{
						if (mRoot)
						{
							mLastError = ErrorType::MoreThanOneRootElement;
							return false;
						}
						_currentNode = new Element(cut, 0, ElementType::Normal);
						mRoot = _currentNode;
					}
				}

				start = content.find_last_not_of(" \t");
				if (start == content.npos) return true;

				bool close = false;
				if ((content[start] == '/') || (content[start] == '?'))
				{
					close = true;
					content[start] = ' ';
					start = content.find_last_not_of(" \t");
					if (start == content.npos)
					{
						_currentNode = _currentNode->GetParent();
						return true;
					}
				}

				while (true)
				{
					start = content.find('=');
					if (start == content.npos)
					{
						mLastError = ErrorType::IncorrectAttribute;
						return false;
					}
					end = content.find_first_of("\"\'", start+1);
					if (end == content.npos)
					{
						mLastError = ErrorType::IncorrectAttribute;
						return false;
					}
					end = content.find_first_of("\"\'", end+1);
					if (end == content.npos)
					{
						mLastError = ErrorType::IncorrectAttribute;
						return false;
					}

					std::string key = content.substr(0, start);
					std::string value = content.substr(start+1, end-start);

					if (! CheckPair(key, value))
					{
						mLastError = ErrorType::IncorrectAttribute;
						return false;
					}

					_currentNode->AddAttribute(key, value);

					content = content.substr(end+1);

					start = content.find_first_not_of(" \t");
					if (start == content.npos) break;

					mCol += start;
				}

				if (close)
				{
					_currentNode = _currentNode->GetParent();
				}

			}
			return true;
		}

		bool Document::CheckPair(std::string &_key, std::string &_value)
		{
			GUI::utility::Trim(_key);
			if (_key.empty()) return false;
			size_t start = _key.find_first_of(" \t\"\'&");
			if (start != _key.npos) return false;

			GUI::utility::Trim(_value);
			if (_value.size() < 2) return false;
			if (((_value[0] != '"') || (_value[_value.length()-1] != '"')) &&
				((_value[0] != '\'') || (_value[_value.length()-1] != '\''))) return false;
			bool ok = true;
			_value = utility::Convert_from_xml(_value.substr(1, _value.length() - 2), ok);
			return ok;
		}

		size_t Document::find(const std::string& text, char _char, size_t start)
		{
			bool kov = false;

			char buff[16] = "\"_\0";
			buff[1] = _char;

			size_t pos = start;

			while (true)
			{
				pos = text.find_first_of(buff, pos);

				if (pos == text.npos) break;

				else if (text[pos] == '"')
				{
					kov = !kov;
					pos ++;
				}
				else if (kov) pos ++;

				else break;

			}

			return pos;
		}

		void Document::ClearDeclaration()
		{
			if (mDeclaration)
			{
				delete mDeclaration;
				mDeclaration = 0;
			}
		}

		void Document::ClearRoot()
		{
			if (mRoot)
			{
				delete mRoot;
				mRoot = 0;
			}
		}

		ElementPtr Document::CreateDeclaration(const std::string& version, const std::string& encoding)
		{
			ClearDeclaration();
			mDeclaration = new Element("xml", 0, ElementType::Declaration);
			mDeclaration->AddAttribute("version", version);
			mDeclaration->AddAttribute("encoding", encoding);
			return mDeclaration;
		}

		ElementPtr Document::CreateRoot(const std::string& name)
		{
			ClearRoot();
			mRoot = new Element(name, 0, ElementType::Normal);
			return mRoot;
		}

		bool Document::ParseLine(std::string& line, ElementPtr& element)
		{
			while (true)
			{
				size_t start = find(line, '<');
				if (start == line.npos) break;
				size_t end = line.npos;

				if ((start + 3 < line.size()) && (line[start + 1] == '!') && (line[start + 2] == '-') && (line[start + 3] == '-'))
				{
					end = line.find("-->", start + 4);
					if (end == line.npos) break;
					end += 2;
				}
				else
				{
					end = find(line, '>', start+1);
					if (end == line.npos) break;
				}
				size_t body = line.find_first_not_of(" \t<");
				if (body < start)
				{
					std::string body_str = line.substr(0, start);
					mCol = 0;

					if (element != 0)
					{
						bool ok = true;
						element->SetContent(utility::Convert_from_xml(body_str, ok));
						if (!ok)
						{
							mLastError = ErrorType::IncorrectContent;
							return false;
						}
					}
				}
				if (!ParseTag(element, line.substr(start+1, end-start-1)))
				{
					return false;
				}
				line = line.substr(end+1);
			}
			return true;
		}

		std::string Document::GetLastError()
		{
			const std::string& error = mLastError.Print();
			if (error.empty()) return error;
			return GUI::utility::ToString("'", error, "' ,  file='", mLastErrorFile, "' ,  line=", mLine, " ,  col=", mCol);
		}

		/*Document Document::CreateCopyFromElement(ElementPtr node)
		{
			Document doc;
			doc.mRoot = node->CreateCopy();
			return doc;
		}*/

	} // namespace xml

} // namespace GUI


