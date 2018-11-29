#ifndef __SHARED_LAYER_H__
#define __SHARED_LAYER_H__

#include "Prerequest.h"
#include "Types.h"
#include "ILayer.h"
#include "SharedLayerNode.h"

namespace GUI
{

	class GUI_EXPORT SharedLayer :
		public ILayer
	{
		RTTI_DERIVED(SharedLayer)

	public:
		SharedLayer();
		virtual ~SharedLayer();

		virtual void Deserialization(xml::ElementPtr node, Version version);

		virtual ILayerNode* CreateChildItemNode();
		virtual void DestroyChildItemNode(ILayerNode* node);

		virtual void UpChildItemNode(ILayerNode* node);

		virtual EnumeratorILayerNode GetEnumerator();

		virtual ILayerItem* GetLayerItemByPoint(int left, int top);

		virtual IntPoint GetPosition(int left, int top) const;

		virtual const IntSize& GetSize() const;

		virtual void RenderToTarget(IRenderTarget* target, bool update);

		virtual void DumpStatisticToLog();

	protected:
		bool mIsPick;
		SharedLayerNode* mChildItem;
	};

} // namespace GUI

#endif // __SHARED_LAYER_H__

