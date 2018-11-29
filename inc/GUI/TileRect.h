#ifndef __TILE_RECT_H__
#define __TILE_RECT_H__

#include "Prerequest.h"
#include "XmlDocument.h"
#include "Types.h"
#include "ISubWidgetRect.h"
#include "ResourceSkin.h"

namespace GUI
{

	class RenderItem;

	class GUI_EXPORT TileRect : public ISubWidgetRect
	{
		RTTI_DERIVED(TileRect)

	public:
		TileRect();
		virtual ~TileRect();

		void SetAlpha(float alpha);

		virtual void SetVisible(bool visible);

		virtual void CreateDrawItem(ITexture* texture, ILayerNode * node);
		virtual void DestroyDrawItem();

		virtual void DoRender();

		virtual void SetStateData(IStateInfo * data);

	/*internal:*/
		void _updateView();
		void _correctView();

		void _setAlign(const IntSize& oldsize, bool update);
		void _setAlign(const IntCoord& oldcoord, bool update);

		virtual void _setUVSet(const FloatRect& rect);
		virtual void _setColour(const Colour& value);

	protected:
		FloatRect mRectTexture;
		bool mEmptyView;

		uint32 mCurrentColour;

		FloatRect mCurrentTexture;
		IntCoord mCurrentCoord;

		ILayerNode* mNode;
		RenderItem* mRenderItem;

		IntSize mTileSize;
		size_t mCountVertex;

		float mRealTileWidth;
		float mRealTileHeight;

		float mTextureHeightOne;
		float mTextureWidthOne;

		bool mTileH;
		bool mTileV;
	};

} // namespace GUI

#endif // __TILE_RECT_H__

