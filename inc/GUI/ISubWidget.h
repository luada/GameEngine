#ifndef __I_SUB_WIDGET_H__
#define __I_SUB_WIDGET_H__

#include "Prerequest.h"
#include "ICroppedRectangle.h"
#include "ILayerNode.h"
#include "Types.h"
#include "IRenderTarget.h"
#include "IStateInfo.h"
#include "IObject.h"

namespace GUI
{

	class ISubWidget;
	typedef std::vector<ISubWidget*> VectorSubWidget;

	class GUI_EXPORT ISubWidget :
		public ICroppedRectangle,
		public IObject
	{
		RTTI_DERIVED(ISubWidget)

	public:
		virtual ~ISubWidget() { }

		virtual void CreateDrawItem(ITexture* texture, ILayerNode* node) = 0;
		virtual void DestroyDrawItem() = 0;

		virtual void SetAlpha(float alpha) { }

		virtual void SetStateData(IStateInfo* data) { }

		virtual void DoRender() = 0;

	};

} // namespace GUI

#endif // __I_SUB_WIDGET_H__
