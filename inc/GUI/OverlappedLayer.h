#ifndef __OVERLAPPED_LAYER_H__
#define __OVERLAPPED_LAYER_H__

#include "Prerequest.h"
#include "Types.h"
#include "ILayer.h"

namespace GUI
{

	class GUI_EXPORT OverlappedLayer :
		public ILayer
	{
		RTTI_DERIVED(OverlappedLayer)

	public:
		OverlappedLayer();
		virtual ~OverlappedLayer();

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
		VectorILayerNode mChildItems;
	};

} // namespace GUI

#endif // __OVERLAPPED_LAYER_H__

