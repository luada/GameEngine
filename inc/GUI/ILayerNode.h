#ifndef __I_LAYER_NODE_H__
#define __I_LAYER_NODE_H__

#include "Prerequest.h"
#include "Enumerator.h"
#include "IObject.h"
#include "IRenderTarget.h"

namespace GUI
{

	class ILayer;
	class ILayerItem;
	class ILayerNode;

	class RenderItem;
	class ISubWidget;

	typedef std::vector<ILayerNode*> VectorILayerNode;
	typedef Enumerator<VectorILayerNode> EnumeratorILayerNode;

	class GUI_EXPORT ILayerNode : public IObject
	{
		RTTI_DERIVED(ILayerNode)

	public:
		virtual ~ILayerNode() { }

		virtual ILayer* GetLayer() = 0;

		virtual ILayerNode* GetParent() = 0;

		virtual ILayerNode* CreateChildItemNode() = 0;
		virtual void DestroyChildItemNode(ILayerNode* node) = 0;

		virtual void UpChildItemNode(ILayerNode* node) = 0;

		virtual EnumeratorILayerNode GetEnumerator() = 0;


		virtual void AttachLayerItem(ILayerItem* item) = 0;
		virtual void DetachLayerItem(ILayerItem* root) = 0;

		virtual RenderItem* AddToRenderItem(ITexture* texture, ISubWidget* item) = 0;
		virtual void OutOfDate(RenderItem* item) = 0;

		virtual ILayerItem* GetLayerItemByPoint(int left, int top) = 0;

		virtual void RenderToTarget(IRenderTarget* target, bool update) = 0;

		virtual void DumpStatisticToLog(size_t level) { }

	};

} // namespace GUI

#endif // __I_LAYER_NODE_H__

