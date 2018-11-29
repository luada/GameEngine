#ifndef __RESOURCE_IMAGE_SET_H__
#define __RESOURCE_IMAGE_SET_H__

#include "Prerequest.h"
#include "Macros.h"
#include "XmlDocument.h"
#include "IResource.h"
#include "ImageInfo.h"
#include "Enumerator.h"
#include "ResourceManager.h"
#include "GenericFactory.h"

namespace GUI
{

	class ResourceImageSet;
	typedef ResourceImageSet * ResourceImageSetPtr;

	struct IndexImage
	{
		std::string name;
		float rate;
		std::vector<IntPoint> frames;
	};
	typedef std::vector<IndexImage> VectorIndexImage;

	struct GroupImage
	{
		std::string name;
		std::string texture;
		IntSize size;
		VectorIndexImage indexes;
	};
	typedef std::vector<GroupImage> VectorGroupImage;
	typedef Enumerator<VectorGroupImage> EnumeratorGroupImage;

	class GUI_EXPORT ResourceImageSet :
		public IResource
	{
		friend class GenericFactory<ResourceImageSet>;

		RTTI_DERIVED(ResourceImageSet)

	private:
		ResourceImageSet() { }
		virtual ~ResourceImageSet() { }

		virtual void Deserialization(xml::ElementPtr node, Version version);

		//-------------------------------------------------------------//
	private:
		size_t GetGroupIndex(const std::string& name)
		{
			for (size_t index=0; index<mGroups.size(); ++index)
			{
				if (mGroups[index].name == name) return index;
			}
			return ITEM_NONE;
		}

		size_t GetGroupIndex(const IntSize& size)
		{
			for (size_t index=0; index<mGroups.size(); ++index)
			{
				if (mGroups[index].size == size) return index;
			}
			return ITEM_NONE;
		}

		size_t GetImageIndex(GroupImage& group, const std::string& name)
		{
			VectorIndexImage& indexes = group.indexes;
			for (size_t index=0; index<indexes.size(); ++index)
			{
				if (indexes[index].name == name) return index;
			}
			return ITEM_NONE;
		}

		const IntSize& GetGroupSize(size_t index)
		{
			if (index >= mGroups.size()) return mSizeEmpty;
			return mGroups[index].size;
		}

		const IntSize& GetGroupSize(const std::string& group)
		{
			for (size_t index=0; index<mGroups.size(); ++index)
			{
				if (mGroups[index].name == group) return mGroups[index].size;
			}
			return mSizeEmpty;
		}

	public:
		ImageIndexInfo GetIndexInfo(const std::string& group, const std::string& index);
		ImageIndexInfo GetIndexInfo(size_t group, const std::string& index);
		ImageIndexInfo GetIndexInfo(const std::string& group, size_t index);
		ImageIndexInfo GetIndexInfo(size_t group, size_t index);
		ImageIndexInfo GetIndexInfo(const IntSize& group, size_t index);
		ImageIndexInfo GetIndexInfo(const IntSize& group, const std::string& index);

		/** Get groups Enumerator */
		EnumeratorGroupImage GetEnumerator() { return EnumeratorGroupImage(mGroups); }

	private:
		VectorGroupImage mGroups;

		static std::string mTextureEmpty;
		static IntSize mSizeEmpty;
		static std::vector<IntPoint> mFramesEmpty;

	};

} // namespace GUI

#endif // __RESOURCE_IMAGE_SET_H__
