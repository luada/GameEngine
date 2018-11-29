#ifndef __SHARED_LAYER_NODE_H__
#define __SHARED_LAYER_NODE_H__

#include "Prerequest.h"
#include "LayerNode.h"

namespace GUI
{

	class GUI_EXPORT SharedLayerNode : public LayerNode
	{
		RTTI_DERIVED(SharedLayerNode)

	public:
		explicit SharedLayerNode(ILayer* layer, ILayerNode* parent = nullptr);
		virtual ~SharedLayerNode();

		void AddUsing() { mCountUsing++; }
		void RemoveUsing() { mCountUsing--; }
		size_t CountUsing() { return mCountUsing; }

	private:
		size_t mCountUsing;
	};

} // namespace GUI

#endif // __SHARED_LAYER_NODE_H__
