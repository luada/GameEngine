#include "Precompiled.h"
#include "SharedLayerNode.h"

namespace GUI
{

	SharedLayerNode::SharedLayerNode(ILayer* layer, ILayerNode* parent) :
		LayerNode(layer, parent),
		mCountUsing(0)
	{
	}

	SharedLayerNode::~SharedLayerNode()
	{
	}

} // namespace GUI
