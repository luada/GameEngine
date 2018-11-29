#ifndef __STATIC_IMAGE_H__
#define __STATIC_IMAGE_H__

#include "Prerequest.h"
#include "Widget.h"
#include "ResourceImageSet.h"
#include "ImageInfo.h"
#include "Guid.h"

namespace GUI
{

	class GUI_EXPORT StaticImage :
		public Widget
	{
		RTTI_DERIVED(StaticImage)
		DEFINE_GET_THIS(StaticImage, BASS(Widget, END))

	public:
		StaticImage();

		//------------------------------------------------------------------------------//
		// The simple interface
		//------------------------------------------------------------------------------//

		/* Set texture and size of image _tile
			@param _texture file name or texture name
			@param coord - part of texture where we take tiles
			@param _tile size
		*/
		//@ExportToLua
		void SetImageInfo(const std::string& texture, const IntCoord& coord, const IntSize& tile);

		/* Set texture
			@param _texture file name or texture name
		*/
		//@ExportToLua
		void SetImageTexture(const std::string& value);

		/** Set _rect - part of texture where we take tiles */
		//@ExportToLua
		void SetImageRect(const IntRect& value);

		/** Set coord - part of texture where we take tiles */
		//@ExportToLua
		void SetImageCoord(const IntCoord& value);

		/** Set _tile size */
		//@ExportToLua
		void SetImageTile(const IntSize& value);

		/** Set current tile index
			@param index - tile index
			@remarks Tiles in file start numbering from left to right and from top to bottom.
			\n \bExample:\n
			<pre>
				+---+---+---+
				| 0 | 1 | 2 |
				+---+---+---+
				| 3 | 4 | 5 |
				+---+---+---+
			</pre>
		*/
		//@ExportToLua
		void SetImageIndex(size_t index);

		/** Get current tile index */
		//@ExportToLua
		size_t GetImageIndex();

		//------------------------------------------------------------------------------//
		// The expanded interface
		//------------------------------------------------------------------------------//

		//! Get number of items
		//@ExportToLua
		size_t GetItemCount() const { return mItems.size(); }

		//! Select specified index
		//@ExportToLua
		void SetItemSelect(size_t index);
		//! Get index of selected Item (ITEM_NONE if none selected)
		//@ExportToLua
		size_t GetItemSelect() { return mIndexSelect; }
		//! Reset item selection
		//@ExportToLua
		void ResetItemSelect() { SetItemSelect(ITEM_NONE); }

		//! Insert an item into a list at a specified position
		//@ExportToLua
		void InsertItem(size_t index, const IntCoord& item);
		//! Add an item to the end of a list
		//@ExportToLua
		void AddItem(const IntCoord& item) { InsertItem(ITEM_NONE, item); }
		//! Replace an item at a specified position
		//@ExportToLua
		void SetItem(size_t index, const IntCoord& item);

		//! delete item at a specified position
		//@ExportToLua
		void DeleteItem(size_t index);
		//! delete all items
		//@ExportToLua
		void DeleteAllItems();

		/** Add frame
			@param index Image item index
			@param _item Frame coordinates at image texture
		*/
		//@ExportToLua
		void AddItemFrame(size_t index, const IntCoord& item);

		/** Insert frame
			@param index Image item index
			@param _indexFrame Frame index where we insert frame
			@param _item Frame coordinates at image texture
		*/
		//@ExportToLua
		void InsertItemFrame(size_t index, size_t indexFrame, const IntCoord& item);

		/** Add copy of Frame (similar to StaticImage::addItemFrame but we copy frame coordinates)
			@param index Image item index
			@param _indexSourceFrame Frame index of frame that we copying
		*/
		//@ExportToLua
		void AddItemFrameDublicate(size_t index, size_t indexSourceFrame);

		/** Insert copy of Frame (similar to StaticImage::insertItemFrame but we copy frame coordinates)
			@param index Image item index
			@param _indexFrame Frame index where we insert frame
			@param _indexSourceFrame Frame index of frame that we copying
		*/
		//@ExportToLua
		void InsertItemFrameDublicate(size_t index, size_t indexFrame, size_t indexSourceFrame);

		/** Change frame
			@param index Image item index
			@param _indexFrame Frame index to change
			@param _item Frame coordinates at image texture
		*/
		//@ExportToLua
		void SetItemFrame(size_t index, size_t indexFrame, const IntCoord& item);

		/** delete frame
			@param index Image item index
			@param _indexFrame Frame index that we delete
		*/
		//@ExportToLua
		void DeleteItemFrame(size_t index, size_t indexFrame);

		/** delete all frames
			@param index Image item index
		*/
		//@ExportToLua
		void DeleteAllItemFrames(size_t index);

		/** Set item frame rate
			@param index Image item index
			@param _rate Duration of one frame in seconds
		*/
		//@ExportToLua
		void SetItemFrameRate(size_t index, float rate);

		/** Get item frame rate
			@param index Image item index
		*/
		//@ExportToLua
		float GetItemFrameRate(size_t index);

		//------------------------------------------------------------------------------//
		// The interface with support of resources
		//------------------------------------------------------------------------------//

		/** Select current items resource used in StaticImage
			@param _id Resource guid
			@return false if resource with such guid not exist
		*/
		//@ExportToLua
		bool SetItemResource(const Guid& id);

		/** Select current items resource used in StaticImage
			@param _id Resource name
			@return false if resource with such name not exist
		*/
		//@ExportToLua
		bool SetItemResource(const std::string& name);

		/** Select current item group */
		//@ExportToLua
		void SetItemGroup(const std::string& value);
		/** Select current item mane */
		//@ExportToLua
		void SetItemName(const std::string& value);

		/** Select current items resource used in StaticImage
			@param _resource Resource pointer
		*/
		void SetItemResourcePtr(ResourceImageSetPtr resource);
		/** Set current item */
		void SetItemResourceInfo(const ImageIndexInfo& info);

		/** Get current items resource used in StaticImage */
		ResourceImageSetPtr GetItemResource() { return mResource; }
		/** Select current item resource, group and name */
		//@ExportToLua
		void SetItemResourceInfo(ResourceImageSetPtr resource, const std::string& group, const std::string& name);

		/** @copydoc Widget::SetProperty(const std::string& key, const std::string& value) */
		//@ExportToLua
		virtual void SetProperty(const std::string& key, const std::string& value);

	/*internal:*/
		virtual void _initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name);

	protected:
		virtual ~StaticImage();

		void BaseChangeWidgetSkin(ResourceSkin* info);

	private:
		void InitialiseWidgetSkin(ResourceSkin* info);
		void ShutdownWidgetSkin();

		void FrameEntered(float frame);

		void RecalcIndexes();
		void UpdateSelectIndex(size_t index);

		void FrameAdvise(bool advise);

	private:
		IntRect mRectImage;
		IntSize mSizeTile;
		IntSize mSizeTexture;
		size_t mIndexSelect;

		VectorImages mItems;

		bool mFrameAdvise;
		float mCurrentTime;
		size_t mCurrentFrame;

		ResourceImageSetPtr mResource;
		std::string mItemName;
		std::string mItemGroup;
		std::string mCurrentTextureName;

	};

} // namespace GUI

#endif // __STATIC_IMAGE_H__

