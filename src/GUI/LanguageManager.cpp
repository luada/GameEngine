#include "Precompiled.h"
#include "ResourceManager.h"
#include "LanguageManager.h"
#include "XmlDocument.h"
#include "DataManager.h"
#include "FactoryManager.h"

namespace GUI
{

	const std::string XML_TYPE("Language");

	INSTANCE_IMPLEMENT(LanguageManager)

	void LanguageManager::Initialise()
	{
		ASSERT(!mIsInitialise, INSTANCE_TYPE_NAME << " initialised twice");
		LOG(Info, "* Initialise: " << INSTANCE_TYPE_NAME);

		ResourceManager::GetInstance().RegisterLoadXmlDelegate(XML_TYPE) = NewDelegate(this, &LanguageManager::_load);

		LOG(Info, INSTANCE_TYPE_NAME << " successfully initialized");
		mIsInitialise = true;
	}

	void LanguageManager::Shutdown()
	{
		if (!mIsInitialise) return;
		LOG(Info, "* Shutdown: " << INSTANCE_TYPE_NAME);

		ResourceManager::GetInstance().UnregisterLoadXmlDelegate(XML_TYPE);

		LOG(Info, INSTANCE_TYPE_NAME << " successfully shutdown");
		mIsInitialise = false;
	}

	bool LanguageManager::Load(const std::string& file)
	{
		return ResourceManager::GetInstance()._loadImplement(file, true, XML_TYPE, INSTANCE_TYPE_NAME);
	}

	void LanguageManager::_load(xml::ElementPtr node, const std::string& file, Version version)
	{
		std::string default_lang;
		bool event_change = false;

		xml::ElementEnumerator root = node->GetElementEnumerator();
		while (root.Next(XML_TYPE))
		{
			root->findAttribute("default", default_lang);

			xml::ElementEnumerator info = root->GetElementEnumerator();
			while (info.Next("Info"))
			{
				std::string name(info->findAttribute("name"));

				if (name.empty())
				{
					xml::ElementEnumerator source_info = info->GetElementEnumerator();
					while (source_info.Next("Source"))
					{
						LoadLanguage(source_info->GetContent(), true);
					}
				}
				else
				{
					xml::ElementEnumerator source_info = info->GetElementEnumerator();
					while (source_info.Next("Source"))
					{
						std::string file_source = source_info->GetContent();
						mMapFile[name].push_back(file_source);

						if (name == mCurrentLanguageName)
						{
							LoadLanguage(file_source, false);
							event_change = true;
						}
					}
				}

			}
		}

		if (!default_lang.empty())
			SetCurrentLanguage(default_lang);
		else if (event_change)
			eventChangeLanguage(mCurrentLanguageName);
	}

	void LanguageManager::SetCurrentLanguage(const std::string& name)
	{
		mMapLanguage.clear();

		mCurrentLanguageName = name;

		MapListString::iterator item = mMapFile.find(name);
		if (item == mMapFile.end())
		{
			LOG(Error, "Language '" << name << "' is not found");
			return;
		}

		for (VectorString::const_iterator iter=item->second.begin(); iter!=item->second.end(); ++iter)
		{
			LoadLanguage(*iter, false);
		}

		eventChangeLanguage(mCurrentLanguageName);
	}

	bool LanguageManager::LoadLanguage(const std::string& file, bool user)
	{
		IDataStream* data = DataManager::GetInstance().GetData(file);
		if (data == nullptr)
		{
			LOG(Error, "file '" << file << "' not found");
			return false;
		}

		if (file.find(".xml") != std::string::npos)
			_loadLanguageXML(data, user);
		else
			_loadLanguage(data, user);

		delete data;
		return true;
	}

	void LanguageManager::_loadLanguageXML(IDataStream* stream, bool user)
	{
		xml::Document doc;
		if (doc.Open(stream))
		{
			xml::ElementPtr root = doc.GetRoot();
			if (root)
			{
				xml::ElementEnumerator tag = root->GetElementEnumerator();
				while (tag.Next("Tag"))
				{
					if (user)
						mUserMapLanguage[tag->findAttribute("name")] = tag->GetContent();
					else
						mMapLanguage[tag->findAttribute("name")] = tag->GetContent();
				}
			}
		}
	}

	void LanguageManager::_loadLanguage(IDataStream* stream, bool user)
	{
		std::string read;
		while (!stream->Eof())
		{
			stream->Readline(read, '\n');
			if (read.empty()) continue;

			if ((uint8)read[0] == 0xEF && read.size() > 2)
			{
				read.erase(0, 3);
			}

			if (read[read.size()-1] == '\r') read.erase(read.size()-1, 1);
			if (read.empty()) continue;

			size_t pos = read.find_first_of(" \t");
			if (user)
			{
				if (pos == std::string::npos) mUserMapLanguage[read] = "";
				else mUserMapLanguage[read.substr(0, pos)] = read.substr(pos+1, std::string::npos);
			}
			else
			{
				if (pos == std::string::npos) mMapLanguage[read] = "";
				else mMapLanguage[read.substr(0, pos)] = read.substr(pos+1, std::string::npos);
			}
		}
	}

	UString LanguageManager::ReplaceTags(const UString& line)
	{
		UString curLine(line);

		if (mMapLanguage.empty() && mUserMapLanguage.empty())
			return line;

		UString::iterator end = curLine.end();
		for (UString::iterator iter=curLine.begin(); iter!=end; )
		{
			if (*iter == '#')
			{
				++iter;
				if (iter == end)
				{
					return curLine;
				}
				else
				{
					if (*iter != '{')
					{
						++iter;
						continue;
					}
					UString::iterator iter2 = iter;
					++iter2;
					while (true)
					{
						if (iter2 == end) return curLine;
						if (*iter2 == '}')
						{
							size_t start = iter - curLine.begin();
							size_t len = (iter2 - curLine.begin()) - start - 1;
							const UString& tag = curLine.substr(start + 1, len);

							bool find = true;
							MapLanguageString::iterator replace = mMapLanguage.find(tag);
							if (replace == mMapLanguage.end())
							{
								replace = mUserMapLanguage.find(tag);
								find = replace != mUserMapLanguage.end();
							}

							if (!find)
							{
								iter = curLine.insert(iter, '#') + size_t(len + 2);
								end = curLine.end();
								break;
							}

							iter = curLine.erase(iter - size_t(1), iter2 + size_t(1));
							size_t pos = iter - curLine.begin();
							curLine.insert(pos, replace->second);
							iter = curLine.begin() + pos + replace->second.length();
							end = curLine.end();
							if (iter == end) return curLine;
							break;

						}
						++iter2;
					}
				}
			}
			else
			{
				++iter;
			}
		}

		return curLine;
	}

	UString LanguageManager::GetTag(const UString& tag)
	{
		MapLanguageString::iterator iter = mMapLanguage.find(tag);
		if (iter == mMapLanguage.end())
		{
			iter = mUserMapLanguage.find(tag);
			if (iter != mUserMapLanguage.end()) return iter->second;
			return tag;
		}

		return iter->second;
	}

	const std::string& LanguageManager::GetCurrentLanguage()
	{
		return mCurrentLanguageName;
	}

	void LanguageManager::AddUserTag(const UString& tag, const UString& replace)
	{
		mUserMapLanguage[tag] = replace;
	}

	void LanguageManager::ClearUserTags()
	{
		mUserMapLanguage.clear();
	}

	bool LanguageManager::LoadUserTags(const std::string& file)
	{
		return LoadLanguage(file, true);
	}

} // namespace GUI

