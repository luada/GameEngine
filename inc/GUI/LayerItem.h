#ifndef __LAYER_ITEM_H__
#define __LAYER_ITEM_H__

#include "Prerequest.h"
#include "LayerManager.h"
#include "ILayer.h"
#include "ILayerNode.h"
#include "ILayerItem.h"
#include "ISubWidget.h"

namespace GUI
{

	class GUI_EXPORT LayerItem : public ILayerItem
	{
	public:
		LayerItem();
		virtual ~LayerItem() { }

	public:
		ILayer* GetLayer() { return mLayer; }

		virtual void AttachItemToNode(ILayer* layer, ILayerNode* node);
		virtual void DetachFromLayer();
		virtual void UpLayerItem();

		void SetRenderItemTexture(ITexture* texture);

		void AddChildItem(LayerItem* item);
		void RemoveChildItem(LayerItem* item);

		void AddChildNode(LayerItem* item);
		void RemoveChildNode(LayerItem* item);

		void AddRenderItem(ISubWidget* item);
		void RemoveAllRenderItems();

		void SaveLayerItem();
		void RestoreLayerItem();

	protected:
		void AttachToLayerItemNode(ILayerNode* node, bool deep);
		void DetachFromLayerItemNode(bool deep);

	private:
		ILayer* mLayer;
		ILayerNode * mLayerNode;
		ILayerNode * mSaveLayerNode;

		typedef std::vector<LayerItem*> VectorLayerItem;
		VectorLayerItem mLayerItems;
		VectorLayerItem mLayerNodes;

		VectorSubWidget mDrawItems;

		ITexture* mTexture;
	};

} // namespace GUI

#endif // __LAYER_ITEM_H__

