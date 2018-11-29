#include "Precompiled.h"
#include "ResourceSkin.h"
#include "FactoryManager.h"
#include "LanguageManager.h"

namespace GUI
{

	ResourceSkin::ResourceSkin()
	{
	}

	void ResourceSkin::Deserialization(xml::ElementPtr node, Version version)
	{
		Base::Deserialization(node, version);

		std::string name, texture, tmp;
		IntSize size;
		node->findAttribute("name", name);
		node->findAttribute("texture", texture);
		if (node->findAttribute("size", tmp)) size = IntSize::Parse(tmp);

		LanguageManager& localizator = LanguageManager::GetInstance();

		SubWidgetBinding bind;

		if (version >= Version(1, 1))
		{
			texture = localizator.ReplaceTags(texture);
		}

		SetInfo(size, texture);

		if (node->findAttribute("mask", tmp))
		{
			if (!LoadMask(tmp))
			{
				LOG(Error, "Skin: mask not load '" << tmp << "'");
			}
		}

		xml::ElementEnumerator basis = node->GetElementEnumerator();
		while (basis.Next())
		{
			if (basis->GetName() == "Property")
			{
				std::string key, value;
				if (!basis->findAttribute("key", key)) continue;
				if (!basis->findAttribute("value", value)) continue;

				if (version >= Version(1, 1))
				{
					value = localizator.ReplaceTags(value);
				}

				AddProperty(key, value);
			}
			else if (basis->GetName() == "Child")
			{
				ChildSkinInfo child(
					basis->findAttribute("type"),
					WidgetStyle::Parse(basis->findAttribute("style")),
					basis->findAttribute("skin"),
					IntCoord::Parse(basis->findAttribute("offset")),
					Align::Parse(basis->findAttribute("align")),
					basis->findAttribute("layer"),
					basis->findAttribute("name")
					);

				xml::ElementEnumerator child_params = basis->GetElementEnumerator();
				while (child_params.Next("Property"))
					child.AddParam(child_params->findAttribute("key"), child_params->findAttribute("value"));

				AddChild(child);
				//continue;
			}
			else if (basis->GetName() == "BasisSkin")
			{
				std::string basisSkinType, tmp_str;
				IntCoord offset;
				Align align = Align::Default;
				basis->findAttribute("type", basisSkinType);
				if (basis->findAttribute("offset", tmp_str)) offset = IntCoord::Parse(tmp_str);
				if (basis->findAttribute("align", tmp_str)) align = Align::Parse(tmp_str);

				bind.Create(offset, align, basisSkinType);

				xml::ElementEnumerator state = basis->GetElementEnumerator();

				bool new_format = false;
				if (version < Version(1, 0))
				{
					while (state.Next())
					{
						if (state->GetName() == "State")
						{
							const std::string& name_state = state->findAttribute("name");
							if ((name_state == "normal_checked") || (state->findAttribute("name") == "normal_check"))
							{
								new_format = true;
								break;
							}
						}
					}
					state = basis->GetElementEnumerator();
				}

				while (state.Next())
				{
					if (state->GetName() == "State")
					{
						std::string basisStateName;
						state->findAttribute("name", basisStateName);

						if (version < Version(1, 0))
						{
							if (basisStateName == "disable_check") basisStateName = "disabled_checked";
							else if (basisStateName == "normal_check") basisStateName = "normal_checked";
							else if (basisStateName == "active_check") basisStateName = "highlighted_checked";
							else if (basisStateName == "pressed_check") basisStateName = "pushed_checked";
							else if (basisStateName == "disable") basisStateName = "disabled";
							else if (basisStateName == "active") basisStateName = "highlighted";
							else if (basisStateName == "select") basisStateName = "pushed";
							else if (basisStateName == "pressed")
							{
								if (new_format) basisStateName = "pushed";
								else basisStateName = "normal_checked";
							}
						}

						IStateInfo* data = nullptr;
						IObject* object = FactoryManager::GetInstance().CreateObject("BasisSkin/State", basisSkinType);
						if (object != nullptr)
						{
							data = object->CastType<IStateInfo>();
							data->Deserialization(state.Current(), version);
						}

						bind.Add(basisStateName, data, name);
					}
				}

				AddInfo(bind);
			}

		}
	}

	void ResourceSkin::SetInfo(const IntSize& size, const std::string &_texture)
	{
		mSize = size;
		mTexture = _texture;
	}

	void ResourceSkin::AddInfo(const SubWidgetBinding& bind)
	{
		CheckState(bind.mStates);
		mBasis.push_back(SubWidgetInfo(bind.mType, bind.mOffset, bind.mAlign));
		CheckBasis();
		FillState(bind.mStates, mBasis.size()-1);
	}

	void ResourceSkin::AddProperty(const std::string &_key, const std::string &_value)
	{
		mProperties[_key] = _value;
	}

	void ResourceSkin::AddChild(const ChildSkinInfo& child)
	{
		mChilds.push_back(child);
	}

	bool ResourceSkin::LoadMask(const std::string& file)
	{
		return mMaskPeek.Load(file);
	}

	void ResourceSkin::Clear()
	{
		for (MapWidgetStateInfo::iterator iter = mStates.begin(); iter!=mStates.end(); ++iter)
		{
			for (VectorStateInfo::iterator iter2=iter->second.begin(); iter2!=iter->second.end(); ++iter2)
			{
				delete *iter2;
			}
		}
	}

	void ResourceSkin::CheckState(const MapStateInfo& states)
	{
		for (MapStateInfo::const_iterator iter = states.begin(); iter != states.end(); ++iter)
		{
			CheckState(iter->first);
		}
	}

	void ResourceSkin::CheckState(const std::string& name)
	{
		MapWidgetStateInfo::const_iterator iter = mStates.find(name);
		if (iter == mStates.end())
		{
			mStates[name] = VectorStateInfo();
		}
	}

	void ResourceSkin::CheckBasis()
	{
		for (MapWidgetStateInfo::iterator iter = mStates.begin(); iter!=mStates.end(); ++iter)
		{
			iter->second.resize(mBasis.size());
		}
	}

	void ResourceSkin::FillState(const MapStateInfo& states, size_t index)
	{
		for (MapStateInfo::const_iterator iter = states.begin(); iter != states.end(); ++iter)
		{
			mStates[iter->first][index] = iter->second;
		}
	}

} // namespace GUI

