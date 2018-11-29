#ifndef __I_LAYER_ITEM_H__
#define __I_LAYER_ITEM_H__

#include "Prerequest.h"

namespace GUI
{

	class ILayer;
	class ILayerNode;

	class GUI_EXPORT ILayerItem
	{
	public:
		virtual ~ILayerItem() { }

		virtual ILayerItem * GetLayerItemByPoint(int left, int top) = 0;
		virtual const IntCoord& GetLayerItemCoord() = 0;

		virtual void AttachItemToNode(ILayer* layer, ILayerNode* node) = 0;
		virtual void DetachFromLayer() = 0;
		virtual void UpLayerItem() = 0;

	};

} // namespace GUI

#endif // __I_LAYER_ITEM_H__
