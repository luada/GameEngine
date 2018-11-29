#ifndef __SUB_SKIN_H__
#define __SUB_SKIN_H__

#include "Prerequest.h"
#include "Types.h"
#include "XmlDocument.h"
#include "ISubWidgetRect.h"
#include "ResourceSkin.h"
#include "IStateInfo.h"

namespace GUI
{

	class RenderItem;

	class GUI_EXPORT SubSkin :
		public ISubWidgetRect
	{
		RTTI_DERIVED(SubSkin)

	public:
		SubSkin();
		virtual ~SubSkin();

		void SetAlpha(float alpha);

		virtual void SetVisible(bool visible);

		virtual void SetStateData(IStateInfo* data);

		virtual void CreateDrawItem(ITexture* texture, ILayerNode * node);
		virtual void DestroyDrawItem();

		virtual void DoRender();

	/*internal:*/
		void _updateView();
		void _correctView();

		void _setAlign(const IntSize& oldsize, bool update);
		void _setAlign(const IntCoord& oldcoord, bool update);

		virtual void _setUVSet(const FloatRect& rect);
		virtual void _setColour(const Colour& value);

	protected:
		FloatRect mRectTexture;
		bool mEmptyView;

		uint32 mCurrentColour;

		FloatRect mCurrentTexture;
		IntCoord mCurrentCoord;

		ILayerNode* mNode;
		RenderItem* mRenderItem;
	};

} // namespace GUI

#endif // __SUB_SKIN_H__

