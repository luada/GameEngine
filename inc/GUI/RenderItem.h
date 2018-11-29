#ifndef __RENDER_ITEM_H__
#define __RENDER_ITEM_H__

#include "Prerequest.h"
#include "ISubWidget.h"
#include "IVertexBuffer.h"
#include "VertexData.h"
#include "IRenderTarget.h"

namespace GUI
{

	typedef std::pair<ISubWidget*, size_t> DrawItemInfo;
	typedef std::vector<DrawItemInfo> VectorDrawItem;

	class GUI_EXPORT RenderItem
	{
	public:
		RenderItem();
		virtual ~RenderItem();

		void RenderToTarget(IRenderTarget* target, bool update);

		void SetTexture(ITexture* value);
		ITexture* GetTexture();

		void AddDrawItem(ISubWidget* item, size_t count);
		void RemoveDrawItem(ISubWidget* item);
		void ReallockDrawItem(ISubWidget* item, size_t count);

		void OutOfDate() { mOutDate = true; }

		size_t GetNeedVertexCount() const { return mNeedVertexCount; }
		size_t GetVertexCount() const { return mCountVertex; }

		bool GetCurrentUpdate() const { return mCurrentUpdate; }
		Vertex* GetCurrentVertextBuffer() const { return mCurrentVertext; }

		void SetLastVertexCount(size_t count) { mLastVertextCount = count; }

		IRenderTarget* GetRenderTarget() { return mRenderTarget; }

		bool GetCompression();

	private:
#if DEBUG_MODE == 1
		std::string mTextureName;
#endif

		ITexture* mTexture;

		size_t mNeedVertexCount;

		bool mOutDate;
		VectorDrawItem mDrawItems;

		size_t mCountVertex;

		bool mCurrentUpdate;
		Vertex* mCurrentVertext;
		size_t mLastVertextCount;

		IVertexBuffer* mVertexBuffer;
		IRenderTarget* mRenderTarget;

		bool mCompression;
	};

} // namespace GUI

#endif // __RENDER_ITEM_H__

