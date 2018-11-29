#include "Precompiled.h"
#include "ResourceImageSet.h"
#include "ResourceManager.h"
#include "LanguageManager.h"

namespace GUI
{

	std::string ResourceImageSet::mTextureEmpty;
	IntSize ResourceImageSet::mSizeEmpty;
	std::vector<IntPoint> ResourceImageSet::mFramesEmpty;

	void ResourceImageSet::Deserialization(xml::ElementPtr node, Version version)
	{
		Base::Deserialization(node, version);

		xml::ElementEnumerator group_node = node->GetElementEnumerator();
		while (group_node.Next("Group"))
		{
			GroupImage group;
			group.name = group_node->findAttribute("name");

			group.texture = group_node->findAttribute("texture");
			if (version >= Version(1, 1))
			{
				group.texture = LanguageManager::GetInstance().ReplaceTags(group.texture);
			}

			group.size = IntSize::Parse(group_node->findAttribute("size"));

			xml::ElementEnumerator index_node = group_node->GetElementEnumerator();
			while (index_node.Next("Index"))
			{
				IndexImage index;
				index.name = index_node->findAttribute("name");
				index.rate = utility::ParseFloat(index_node->findAttribute("rate"));

				xml::ElementEnumerator frame_node = index_node->GetElementEnumerator();
				while (frame_node.Next("Frame"))
				{
					size_t count = utility::ParseSizeT(frame_node->findAttribute("count"));
					const IntPoint& point = IntPoint::Parse(frame_node->findAttribute("point"));
					if ((count < 1) || (count > 256)) count = 1;
					while (count > 0)
					{
						index.frames.push_back(point);
						-- count;
					}
				}

				group.indexes.push_back(index);
			}

			mGroups.push_back(group);
		}
	}

	ImageIndexInfo ResourceImageSet::GetIndexInfo(const std::string& group, const std::string& index)
	{
		size_t index_group = GetGroupIndex(group);
		if (index_group != ITEM_NONE)
		{
			GroupImage& curGroup = mGroups[index_group];
			size_t index_image = GetImageIndex(curGroup, index);
			if (index_image != ITEM_NONE)
			{
				IndexImage& curIndex = curGroup.indexes[index_image];
				return ImageIndexInfo(curGroup.texture, curGroup.size, curIndex.rate, curIndex.frames);
			}
		}
		return ImageIndexInfo(mTextureEmpty, mSizeEmpty, 0, mFramesEmpty);
	}

	ImageIndexInfo ResourceImageSet::GetIndexInfo(size_t group, const std::string& index)
	{
		if (group < mGroups.size())
		{
			GroupImage& curGroup = mGroups[group];
			size_t index_image = GetImageIndex(curGroup, index);
			if (index_image != ITEM_NONE)
			{
				IndexImage& curIndex = curGroup.indexes[index_image];
				return ImageIndexInfo(curGroup.texture, curGroup.size, curIndex.rate, curIndex.frames);
			}
		}
		return ImageIndexInfo(mTextureEmpty, mSizeEmpty, 0, mFramesEmpty);
	}

	ImageIndexInfo ResourceImageSet::GetIndexInfo(const std::string& group, size_t index)
	{
		size_t index_group = GetGroupIndex(group);
		if (index_group != ITEM_NONE)
		{
			GroupImage& curGroup = mGroups[index_group];
			if (index < curGroup.indexes.size())
			{
				IndexImage& curIndex = curGroup.indexes[index];
				return ImageIndexInfo(curGroup.texture, curGroup.size, curIndex.rate, curIndex.frames);
			}
		}
		return ImageIndexInfo(mTextureEmpty, mSizeEmpty, 0, mFramesEmpty);
	}

	ImageIndexInfo ResourceImageSet::GetIndexInfo(size_t group, size_t index)
	{
		if (group < mGroups.size())
		{
			GroupImage& curGroup = mGroups[group];
			if (index < curGroup.indexes.size())
			{
				IndexImage& curIndex = curGroup.indexes[index];
				return ImageIndexInfo(curGroup.texture, curGroup.size, curIndex.rate, curIndex.frames);
			}
		}
		return ImageIndexInfo(mTextureEmpty, mSizeEmpty, 0, mFramesEmpty);
	}

	ImageIndexInfo ResourceImageSet::GetIndexInfo(const IntSize& group, size_t index)
	{
		size_t index_group = GetGroupIndex(group);
		if (index_group != ITEM_NONE)
		{
			GroupImage& curGroup = mGroups[index_group];
			if (index < curGroup.indexes.size())
			{
				IndexImage& curIndex = curGroup.indexes[index];
				return ImageIndexInfo(curGroup.texture, curGroup.size, curIndex.rate, curIndex.frames);
			}
		}
		return ImageIndexInfo(mTextureEmpty, mSizeEmpty, 0, mFramesEmpty);
	}

	ImageIndexInfo ResourceImageSet::GetIndexInfo(const IntSize& group, const std::string& index)
	{
		size_t index_group = GetGroupIndex(group);
		if (index_group != ITEM_NONE)
		{
			GroupImage& curGroup = mGroups[index_group];
			size_t index_image = GetImageIndex(curGroup, index);
			if (index_image != ITEM_NONE)
			{
				IndexImage& curIndex = curGroup.indexes[index_image];
				return ImageIndexInfo(curGroup.texture, curGroup.size, curIndex.rate, curIndex.frames);
			}
		}
		return ImageIndexInfo(mTextureEmpty, mSizeEmpty, 0, mFramesEmpty);
	}

} // namespace GUI

