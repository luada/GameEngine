#ifndef __I_LAYER_H__
#define __I_LAYER_H__

#include "Prerequest.h"
#include "Types.h"
#include "IRenderTarget.h"
#include "ILayerNode.h"
#include "ISerializable.h"

namespace GUI
{

	class ILayerItem;

	class GUI_EXPORT ILayer : public ISerializable
	{
		RTTI_DERIVED(ILayer)

	public:
		ILayer() { }
		virtual ~ILayer() { }

		const std::string& GetName() const { return mName; }

		virtual ILayerNode* CreateChildItemNode() = 0;
		virtual void DestroyChildItemNode(ILayerNode* node) = 0;

		virtual void UpChildItemNode(ILayerNode* node) = 0;

		virtual EnumeratorILayerNode GetEnumerator() = 0;

		virtual ILayerItem* GetLayerItemByPoint(int left, int top) = 0;

		virtual IntPoint GetPosition(int left, int top) const = 0;

		virtual const IntSize& GetSize() const = 0;

		virtual void RenderToTarget(IRenderTarget* target, bool update) = 0;

		virtual void DumpStatisticToLog() { }

	protected:
		std::string mName;
	};

} // namespace GUI

#endif // __I_LAYER_H__

