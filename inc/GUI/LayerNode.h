#ifndef __LAYER_NODE_H__
#define __LAYER_NODE_H__

#include "Prerequest.h"
#include "ILayer.h"
#include "ILayerNode.h"
#include "RenderItem.h"

namespace GUI
{

	class LayerItem;
	typedef std::vector<RenderItem*> VectorRenderItem;
	typedef std::vector<ILayerItem*> VectorLayerItem;

	class GUI_EXPORT LayerNode : public ILayerNode
	{
		RTTI_DERIVED(LayerNode)

	public:
		explicit LayerNode(ILayer* layer, ILayerNode * parent = nullptr);
		virtual ~LayerNode();

		virtual ILayer* GetLayer() { return mLayer; }

		virtual ILayerNode* GetParent() { return mParent; }

		virtual ILayerNode* CreateChildItemNode();
		virtual void DestroyChildItemNode(ILayerNode* node);

		virtual void UpChildItemNode(ILayerNode* node);

		virtual EnumeratorILayerNode GetEnumerator();

		virtual void AttachLayerItem(ILayerItem* item);
		virtual void DetachLayerItem(ILayerItem* item);

		virtual RenderItem* AddToRenderItem(ITexture* texture, ISubWidget* item);
		virtual void OutOfDate(RenderItem* item);

		virtual ILayerItem* GetLayerItemByPoint(int left, int top);

		virtual void RenderToTarget(IRenderTarget* target, bool update);

		virtual void DumpStatisticToLog(size_t level);

		bool IsOutOfDate() { return mOutOfDate; }

	protected:
		void UpdateCompression();

	protected:
		VectorRenderItem mFirstRenderItems;
		VectorRenderItem mSecondRenderItems;

		VectorLayerItem mLayerItems;

		VectorILayerNode mChildItems;

		ILayerNode * mParent;
		ILayer* mLayer;
		bool mOutOfDate;
	};

} // namespace GUI

#endif // __LAYER_NODE_H__

