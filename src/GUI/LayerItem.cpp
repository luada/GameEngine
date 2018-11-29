#include "Precompiled.h"
#include "LayerItem.h"
#include <algorithm>

namespace GUI
{

	LayerItem::LayerItem() :
		mLayer(nullptr),
		mLayerNode(nullptr),
		mSaveLayerNode(nullptr),
		mTexture(nullptr)
	{
	}

	void LayerItem::AddChildItem(LayerItem* item)
	{
		mLayerItems.push_back(item);
		if (mLayerNode != nullptr)
		{
			item->AttachToLayerItemNode(mLayerNode, false);
		}
	}

	void LayerItem::RemoveChildItem(LayerItem* item)
	{
		VectorLayerItem::iterator curItem = std::remove(mLayerItems.begin(), mLayerItems.end(), item);
		ASSERT(curItem != mLayerItems.end(), "item not found");
		mLayerItems.erase(curItem);
	}

	void LayerItem::AddChildNode(LayerItem* item)
	{
		mLayerNodes.push_back(item);
		if (mLayerNode != nullptr)
		{
			ILayerNode* child_node = mLayerNode->CreateChildItemNode();
			item->AttachToLayerItemNode(child_node, true);
		}
	}

	void LayerItem::RemoveChildNode(LayerItem* item)
	{
		VectorLayerItem::iterator curItem = std::remove(mLayerNodes.begin(), mLayerNodes.end(), item);
		ASSERT(curItem != mLayerNodes.end(), "item not found");
		mLayerNodes.erase(curItem);
	}

	void LayerItem::AddRenderItem(ISubWidget* item)
	{
		mDrawItems.push_back(item);
	}

	void LayerItem::RemoveAllRenderItems()
	{
		DetachFromLayerItemNode(false);
		mDrawItems.clear();
	}

	void LayerItem::SetRenderItemTexture(ITexture* texture)
	{
		mTexture = texture;
		if (mLayerNode)
		{
			ILayerNode* node = mLayerNode;
			DetachFromLayerItemNode(false);
			AttachToLayerItemNode(node, false);
		}
	}

	void LayerItem::SaveLayerItem()
	{
		mSaveLayerNode = mLayerNode;
	}

	void LayerItem::RestoreLayerItem()
	{
		mLayerNode = mSaveLayerNode;
		if (mLayerNode)
		{
			AttachToLayerItemNode(mLayerNode, false);
		}
	}

	void LayerItem::AttachItemToNode(ILayer* layer, ILayerNode* node)
	{
		mLayer = layer;
		mLayerNode = node;

		AttachToLayerItemNode(node, true);
	}

	void LayerItem::DetachFromLayer()
	{
		if (nullptr == mLayer) return;

		ASSERT(mLayerNode, "_item->mLayerNode == nullptr");

		mLayerNode->DetachLayerItem(this);

		ILayerNode * save = mLayerNode;

		DetachFromLayerItemNode(true);

		mLayer->DestroyChildItemNode(save);
		mLayerNode = nullptr;
		mLayer = nullptr;
	}

	void LayerItem::UpLayerItem()
	{
		if (mLayerNode) mLayerNode->GetLayer()->UpChildItemNode(mLayerNode);
	}

	void LayerItem::AttachToLayerItemNode(ILayerNode* item, bool deep)
	{
		DEBUG_ASSERT(nullptr != item, "attached curItem must be valid");

		mLayerNode = item;

		for (VectorSubWidget::iterator skin = mDrawItems.begin(); skin != mDrawItems.end(); ++skin)
		{
			(*skin)->CreateDrawItem(mTexture, item);
		}

		for (VectorLayerItem::iterator curItem = mLayerItems.begin(); curItem != mLayerItems.end(); ++curItem)
		{
			(*curItem)->AttachToLayerItemNode(item, deep);
		}

		for (VectorLayerItem::iterator curItem = mLayerNodes.begin(); curItem != mLayerNodes.end(); ++curItem)
		{
			if (deep)
			{
				ILayerNode* child_node = item->CreateChildItemNode();
				(*curItem)->AttachToLayerItemNode(child_node, deep);
			}
		}
	}

	void LayerItem::DetachFromLayerItemNode(bool deep)
	{
		for (VectorLayerItem::iterator item = mLayerItems.begin(); item != mLayerItems.end(); ++item)
		{
			(*item)->DetachFromLayerItemNode(deep);
		}

		for (VectorLayerItem::iterator item = mLayerNodes.begin(); item != mLayerNodes.end(); ++item)
		{
			if (deep)
			{
				ILayerNode* node = (*item)->mLayerNode;
				(*item)->DetachFromLayerItemNode(deep);
				if (node)
				{
					node->GetLayer()->DestroyChildItemNode(node);
				}
			}
		}

		ILayerNode* node = mLayerNode;
		if (node)
		{
			//for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget) (*widget)->_detachFromLayerItemKeeperByStyle(deep);
			for (VectorSubWidget::iterator skin = mDrawItems.begin(); skin != mDrawItems.end(); ++skin)
			{
				(*skin)->DestroyDrawItem();
			}

			/*if (deep && !this->IsRootWidget() && mWidgetStyle == WidgetStyle::Overlapped)
			{
				node->DestroyItemNode();
			}*/
			mLayerNode = nullptr;
		}
	}

} // namespace GUI

