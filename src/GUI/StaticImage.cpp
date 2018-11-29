#include "Precompiled.h"
#include "StaticImage.h"
#include "CoordConverter.h"
#include "ResourceManager.h"
#include "ResourceSkin.h"
#include "RotatingSkin.h"
#include "Gui.h"
#include "TextureUtility.h"

namespace GUI
{

	const size_t IMAGE_MAX_INDEX = 256;

	StaticImage::StaticImage() :
		mIndexSelect(ITEM_NONE),
		mFrameAdvise(false),
		mCurrentTime(0),
		mCurrentFrame(0),
		mResource(nullptr)
	{
	}

	void StaticImage::_initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name)
	{
		Base::_initialise(style, coord, align, info, parent, croppedParent, creator, name);

		InitialiseWidgetSkin(info);
	}

	StaticImage::~StaticImage()
	{
		ShutdownWidgetSkin();
	}

	void StaticImage::BaseChangeWidgetSkin(ResourceSkin* info)
	{
		ShutdownWidgetSkin();
		Base::BaseChangeWidgetSkin(info);
		InitialiseWidgetSkin(info);
	}

	void StaticImage::InitialiseWidgetSkin(ResourceSkin* info)
	{
		const MapString& properties = info->GetProperties();
		if ( ! properties.empty() )
		{
			MapString::const_iterator iter = properties.end();
			if ((iter = properties.find("ImageTexture")) != properties.end()) SetImageTexture(iter->second);
			if ((iter = properties.find("ImageRect")) != properties.end()) SetImageRect(IntRect::Parse(iter->second));
			if ((iter = properties.find("ImageCoord")) != properties.end()) SetImageCoord(IntCoord::Parse(iter->second));
			if ((iter = properties.find("ImageTile")) != properties.end()) SetImageTile(IntSize::Parse(iter->second));
			if ((iter = properties.find("ImageIndex")) != properties.end()) SetImageIndex(utility::ParseInt(iter->second));
			if ((iter = properties.find("ImageResource")) != properties.end()) SetItemResource(iter->second);
			if ((iter = properties.find("ImageGroup")) != properties.end()) SetItemGroup(iter->second);
			if ((iter = properties.find("ImageName")) != properties.end()) SetItemName(iter->second);
		}
	}

	void StaticImage::ShutdownWidgetSkin()
	{
		FrameAdvise(false);
	}

	void StaticImage::SetImageInfo(const std::string& texture, const IntCoord& coord, const IntSize& tile)
	{
		mCurrentTextureName = texture;
		mSizeTexture = texture_utility::GetTextureSize(mCurrentTextureName);

		mSizeTile = tile;
		mRectImage.left = coord.left;
		mRectImage.top = coord.top;
		mRectImage.right = coord.left + coord.width;
		mRectImage.bottom = coord.top + coord.height;

		RecalcIndexes();
		UpdateSelectIndex(mIndexSelect);
	}

	void StaticImage::SetImageTile(const IntSize& tile)
	{
		mSizeTile = tile;

		if (mRectImage.Empty()) mRectImage.Set(0, 0, tile.width, tile.height);
		if (mIndexSelect == ITEM_NONE) mIndexSelect = 0;

		RecalcIndexes();
		UpdateSelectIndex(mIndexSelect);
	}

	void StaticImage::SetImageCoord(const IntCoord& coord)
	{
		mRectImage.left = coord.left;
		mRectImage.top = coord.top;
		mRectImage.right = coord.left + coord.width;
		mRectImage.bottom = coord.top + coord.height;

		if (mSizeTile.Empty()) mSizeTile = coord.Size();
		if (mIndexSelect == ITEM_NONE) mIndexSelect = 0;

		RecalcIndexes();
		UpdateSelectIndex(mIndexSelect);
	}

	void StaticImage::SetImageRect(const IntRect& rect)
	{
		mRectImage= rect;

		if (mSizeTile.Empty()) mSizeTile.Set(rect.Width(), rect.Height());
		if (mIndexSelect == ITEM_NONE) mIndexSelect = 0;

		RecalcIndexes();
		UpdateSelectIndex(mIndexSelect);
	}

	void StaticImage::SetImageTexture(const std::string& texture)
	{
		mCurrentTextureName = texture;
		mSizeTexture = texture_utility::GetTextureSize(mCurrentTextureName);

		if (mItems.empty())
		{
			_setUVSet(FloatRect(0, 0, 1, 1));
			_setTextureName(mCurrentTextureName);
		}
		else
		{
			RecalcIndexes();
			UpdateSelectIndex(mIndexSelect);
		}
	}

	void StaticImage::RecalcIndexes()
	{
		mItems.clear();

		if ((mRectImage.right <= mRectImage.left) || (mRectImage.bottom <= mRectImage.top)) return;
		if ((mSizeTile.width <= 0) || (mSizeTile.height <= 0)) return;

		size_t count_h = (size_t)(mRectImage.Width() / mSizeTile.width);
		size_t count_v = (size_t)(mRectImage.Height() / mSizeTile.height);

		if ((count_h * count_v) > IMAGE_MAX_INDEX)
		{
			LOG(warning, "Tile count very mach, rect : " << mRectImage.Print() << " tile : " << mSizeTile.Print() << " texture : " << mTextureName << " indexes : " << (count_h * count_v) << " max : " << IMAGE_MAX_INDEX);
			return;
		}

		int pos_h = mRectImage.left;
		int pos_v = mRectImage.top;

		for (size_t v=0; v<count_v; ++v)
		{
			for (size_t h=0; h<count_h; ++h)
			{
				AddItem(IntCoord(pos_h, pos_v, mSizeTile.width, mSizeTile.height));
				pos_h += mSizeTile.width;
			}
			pos_v += mSizeTile.height;
			pos_h = mRectImage.left;
		}
	}

	void StaticImage::UpdateSelectIndex(size_t index)
	{
		mIndexSelect = index;

		if ((index == ITEM_NONE) || (index >= mItems.size()))
		{
			_setTextureName("");
			return;
		}
		else
		{
			_setTextureName(mCurrentTextureName);
		}

		VectorImages::iterator iter = mItems.begin() + index;

		if (iter->images.size() < 2)
		{
			FrameAdvise(false);
		}
		else
		{
			if ( ! mFrameAdvise)
			{
				mCurrentTime = 0;
				mCurrentFrame = 0;
			}
			FrameAdvise(true);
		}

		if ( ! iter->images.empty())
		{
			_setUVSet(iter->images.front());
		}
	}

	void StaticImage::DeleteItem(size_t index)
	{
		ASSERT_RANGE(index, mItems.size(), "StaticImage::deleteItem");

		mItems.erase(mItems.begin() + index);

		if (mIndexSelect != ITEM_NONE)
		{
			if (mItems.empty()) UpdateSelectIndex(ITEM_NONE);
			else if ((index < mIndexSelect) || (mIndexSelect == mItems.size())) UpdateSelectIndex(mIndexSelect--);
		}
	}

	void StaticImage::DeleteAllItems()
	{
		UpdateSelectIndex(ITEM_NONE);
		mItems.clear();
	}

	void StaticImage::InsertItem(size_t index, const IntCoord& item)
	{
		ASSERT_RANGE_INSERT(index, mItems.size(), "StaticImage::insertItem");
		if (index == ITEM_NONE) index = mItems.size();

		VectorImages::iterator iter = mItems.insert(mItems.begin() + index, ImageItem());

		iter->images.push_back(CoordConverter::ConvertTextureCoord(item, mSizeTexture));

		if ((mIndexSelect != ITEM_NONE) && (index <= mIndexSelect)) UpdateSelectIndex(mIndexSelect++);
	}

	void StaticImage::SetItem(size_t index, const IntCoord& item)
	{
		ASSERT_RANGE(index, mItems.size(), "StaticImage::setItem");

		VectorImages::iterator iter = mItems.begin() + index;
		iter->images.clear();
		iter->images.push_back(CoordConverter::ConvertTextureCoord(item, mSizeTexture));

		if (index == mIndexSelect) UpdateSelectIndex(mIndexSelect);
	}

	void StaticImage::FrameEntered(float frame)
	{
		if (mIndexSelect == ITEM_NONE) return;

		if (mItems.empty()) return;
		VectorImages::iterator iter = mItems.begin() + mIndexSelect;
		if ((iter->images.size() < 2) || (iter->frame_rate == 0)) return;

		mCurrentTime += frame;

		while (mCurrentTime >= iter->frame_rate)
		{
			mCurrentTime -= iter->frame_rate;
			mCurrentFrame ++;
			if (mCurrentFrame >= (iter->images.size())) mCurrentFrame = 0;
		}

		_setUVSet(iter->images[mCurrentFrame]);
	}

	void StaticImage::DeleteAllItemFrames(size_t index)
	{
		ASSERT_RANGE(index, mItems.size(), "StaticImage::clearItemFrame");
		VectorImages::iterator iter = mItems.begin() + index;
		iter->images.clear();
	}

	void StaticImage::AddItemFrame(size_t index, const IntCoord& item)
	{
		ASSERT_RANGE(index, mItems.size(), "StaticImage::addItemFrame");
		VectorImages::iterator iter = mItems.begin() + index;
		iter->images.push_back(CoordConverter::ConvertTextureCoord(item, mSizeTexture));
	}

	void StaticImage::SetItemFrameRate(size_t index, float rate)
	{
		ASSERT_RANGE(index, mItems.size(), "StaticImage::setItemFrameRate");
		VectorImages::iterator iter = mItems.begin() + index;
		iter->frame_rate = rate;
	}

	float StaticImage::GetItemFrameRate(size_t index)
	{
		ASSERT_RANGE(index, mItems.size(), "StaticImage::getItemFrameRate");
		VectorImages::iterator iter = mItems.begin() + index;
		return iter->frame_rate;
	}

	void StaticImage::AddItemFrameDublicate(size_t index, size_t indexSourceFrame)
	{
		ASSERT_RANGE(index, mItems.size(), "StaticImage::addItemFrameDublicate");

		VectorImages::iterator iter = mItems.begin() + index;
		ASSERT_RANGE(indexSourceFrame, iter->images.size(), "StaticImage::addItemFrameDublicate");
		iter->images.push_back(iter->images[indexSourceFrame]);
	}

	void StaticImage::InsertItemFrame(size_t index, size_t indexFrame, const IntCoord& item)
	{
		ASSERT_RANGE(index, mItems.size(), "StaticImage::insertItemFrame");

		VectorImages::iterator iter = mItems.begin() + index;
		ASSERT_RANGE_INSERT(indexFrame, iter->images.size(), "StaticImage::insertItemFrame");
		if (indexFrame == ITEM_NONE) indexFrame = iter->images.size() - 1;

		iter->images.insert(iter->images.begin() + indexFrame,
			CoordConverter::ConvertTextureCoord(item, mSizeTexture));
	}

	void StaticImage::InsertItemFrameDublicate(size_t index, size_t indexFrame, size_t indexSourceFrame)
	{
		ASSERT_RANGE(index, mItems.size(), "StaticImage::insertItemFrameDublicate");

		VectorImages::iterator iter = mItems.begin() + index;
		ASSERT_RANGE_INSERT(indexFrame, iter->images.size(), "StaticImage::insertItemFrameDublicate");
		if (indexFrame == ITEM_NONE) indexFrame = iter->images.size() - 1;

		ASSERT_RANGE(indexSourceFrame, iter->images.size(), "StaticImage::insertItemFrameDublicate");

		iter->images.insert(iter->images.begin() + indexFrame, iter->images[indexSourceFrame]);
	}

	void StaticImage::SetItemFrame(size_t index, size_t indexFrame, const IntCoord& item)
	{
		ASSERT_RANGE(index, mItems.size(), "StaticImage::setItemFrame");

		VectorImages::iterator iter = mItems.begin() + index;
		ASSERT_RANGE(indexFrame, iter->images.size(), "StaticImage::setItemFrame");

		iter->images[indexFrame] = CoordConverter::ConvertTextureCoord(item, mSizeTexture);
	}

	void StaticImage::DeleteItemFrame(size_t index, size_t indexFrame)
	{
		ASSERT_RANGE(index, mItems.size(), "StaticImage::deleteItemFrame");

		VectorImages::iterator iter = mItems.begin() + index;
		ASSERT_RANGE_INSERT(indexFrame, iter->images.size(), "StaticImage::deleteItemFrame");
		if (indexFrame == ITEM_NONE) indexFrame = iter->images.size() - 1;

		iter->images.erase(iter->images.begin() + indexFrame);
	}

	void StaticImage::SetItemResourceInfo(const ImageIndexInfo& info)
	{
		mCurrentTextureName = info.texture;
		mSizeTexture = texture_utility::GetTextureSize(mCurrentTextureName);

		mItems.clear();

		if (info.frames.size() != 0)
		{
			std::vector<IntPoint>::const_iterator iter = info.frames.begin();

			AddItem(IntCoord(*iter, info.size));
			SetItemFrameRate(0, info.rate);

			for (++iter; iter!=info.frames.end(); ++iter)
			{
				AddItemFrame(0, GUI::IntCoord(*iter, info.size));
			}

		}

		mIndexSelect = 0;
		UpdateSelectIndex(mIndexSelect);
	}

	bool StaticImage::SetItemResource(const Guid& id)
	{
		IResourcePtr resource = id.empty() ? nullptr : ResourceManager::GetInstance().GetByID(id, false);
		SetItemResourcePtr(resource ? resource->CastType<ResourceImageSet>() : nullptr);
		return resource != nullptr;
	}

	bool StaticImage::SetItemResource(const std::string& name)
	{
		IResourcePtr resource = ResourceManager::GetInstance().GetByName(name, false);
		SetItemResourcePtr(resource ? resource->CastType<ResourceImageSet>() : nullptr);
		return resource != nullptr;
	}

	void StaticImage::SetItemResourcePtr(ResourceImageSetPtr resource)
	{
		if (mResource == resource)
			return;

		if (mResource == nullptr && resource != nullptr)
		{
			if (mItemGroup.empty())
			{
				EnumeratorGroupImage iter_group = resource->GetEnumerator();
				while (iter_group.Next())
				{
					mItemGroup = iter_group.Current().name;
					if (mItemName.empty() && !iter_group.Current().indexes.empty())
					{
						mItemName = iter_group.Current().indexes[0].name;
					}
					break;
				}
			}
			else if (mItemName.empty())
			{
				EnumeratorGroupImage iter_group = resource->GetEnumerator();
				while (iter_group.Next())
				{
					if (mItemGroup == iter_group.Current().name)
					{
						if (!iter_group.Current().indexes.empty())
						{
							mItemName = iter_group.Current().indexes[0].name;
							break;
						}
					}
				}
			}
		}

		mResource = resource;
		if (!mResource || mItemGroup.empty() || mItemName.empty()) UpdateSelectIndex(ITEM_NONE);
		else SetItemResourceInfo(mResource->GetIndexInfo(mItemGroup, mItemName));
	}

	void StaticImage::SetItemGroup(const std::string& group)
	{
		if (mItemGroup == group)
			return;

		mItemGroup = group;
		if (!mResource || mItemGroup.empty() || mItemName.empty()) UpdateSelectIndex(ITEM_NONE);
		else SetItemResourceInfo(mResource->GetIndexInfo(mItemGroup, mItemName));
	}

	void StaticImage::SetItemName(const std::string& name)
	{
		if (mItemName == name)
			return;

		mItemName = name;
		if (!mResource || mItemGroup.empty() || mItemName.empty()) UpdateSelectIndex(ITEM_NONE);
		else SetItemResourceInfo(mResource->GetIndexInfo(mItemGroup, mItemName));
	}

	void StaticImage::SetItemResourceInfo(ResourceImageSetPtr resource, const std::string& group, const std::string& name)
	{
		mResource = resource;
		mItemGroup = group;
		mItemName = name;
		if (!mResource || mItemGroup.empty() || mItemName.empty()) UpdateSelectIndex(ITEM_NONE);
		else SetItemResourceInfo(mResource->GetIndexInfo(mItemGroup, mItemName));
	}

	void StaticImage::FrameAdvise(bool advise)
	{
		if ( advise )
		{
			if ( ! mFrameAdvise )
			{
				GUI::Gui::GetInstance().eventFrameStart += GUI::NewDelegate( this, &StaticImage::FrameEntered );
				mFrameAdvise = true;
			}
		}
		else
		{
			if ( mFrameAdvise )
			{
				GUI::Gui::GetInstance().eventFrameStart -= GUI::NewDelegate( this, &StaticImage::FrameEntered );
				mFrameAdvise = false;
			}
		}
	}

	void StaticImage::SetImageIndex(size_t index)
	{
		SetItemSelect(index);
	}

	size_t StaticImage::GetImageIndex()
	{
		return GetItemSelect();
	}

	void StaticImage::SetItemSelect(size_t index)
	{
		if (mIndexSelect != index) UpdateSelectIndex(index);
	}

	void StaticImage::SetProperty(const std::string& key, const std::string& value)
	{
		if (key == "Image_Texture") SetImageTexture(value);
		else if (key == "Image_Coord") SetImageCoord(utility::ParseValue<IntCoord>(value));
		else if (key == "Image_Tile") SetImageTile(utility::ParseValue<IntSize>(value));
		else if (key == "Image_Index") SetItemSelect(utility::ParseValue<size_t>(value));
		else if (key == "Image_Resource") SetItemResource(value);
		else if (key == "Image_Group") SetItemGroup(value);
		else if (key == "Image_Name") SetItemName(value);
		else
		{
			Base::SetProperty(key, value);
			return;
		}
		eventChangeProperty(this, key, value);
	}

} // namespace GUI

