#include "Precompiled.h"
#include "RenderItem.h"
#include "LayerNode.h"
#include "LayerManager.h"
#include "Gui.h"
#include "RenderManager.h"
#include "DataManager.h"
#include "RenderManager.h"

namespace GUI
{

	RenderItem::RenderItem() :
		mTexture(nullptr),
		mNeedVertexCount(0),
		mOutDate(false),
		mCountVertex(0),
		mCurrentUpdate(true),
		mCurrentVertext(nullptr),
		mLastVertextCount(0),
		mVertexBuffer(nullptr),
		mRenderTarget(nullptr),
		mCompression(false)
	{
		mVertexBuffer = RenderManager::GetInstance().CreateVertexBuffer();
	}

	RenderItem::~RenderItem()
	{
		RenderManager::GetInstance().DestroyVertexBuffer(mVertexBuffer);
		mVertexBuffer = nullptr;
	}

	void RenderItem::RenderToTarget(IRenderTarget* target, bool update)
	{
		if (mTexture == nullptr)
			return;

		mRenderTarget = target;

		mCurrentUpdate = update;

		if (mOutDate || update)
		{
			mCountVertex = 0;
			Vertex * buffer = (Vertex*)mVertexBuffer->Lock();

			for (VectorDrawItem::iterator iter=mDrawItems.begin(); iter!=mDrawItems.end(); ++iter)
			{
				mCurrentVertext = buffer;
				mLastVertextCount = 0;

				(*iter).first->DoRender();

				DEBUG_ASSERT(mLastVertextCount <= (*iter).second, "It is too much vertexes");
				buffer += mLastVertextCount;
				mCountVertex += mLastVertextCount;
			}

			mVertexBuffer->Unlock();

			mOutDate = false;
		}

		if (0 != mCountVertex)
		{
#if DEBUG_MODE == 1
			if (!RenderManager::GetInstance().CheckTexture(mTexture))
			{
				mTexture = nullptr;
				EXCEPT("texture pointer is not valid, texture name '" << mTextureName << "'");
				return;
			}
#endif
			target->DoRender(mVertexBuffer, mTexture, mCountVertex);
		}
	}

	void RenderItem::RemoveDrawItem(ISubWidget* item)
	{
		for (VectorDrawItem::iterator iter=mDrawItems.begin(); iter!=mDrawItems.end(); ++iter)
		{
			if ((*iter).first == item)
			{
				mNeedVertexCount -= (*iter).second;
				mDrawItems.erase(iter);
				mOutDate = true;

				mVertexBuffer->SetVertextCount(mNeedVertexCount);

				if (mDrawItems.empty())
				{
					mTexture = nullptr;
					mCompression = true;
				}

				return;
			}
		}
		EXCEPT("DrawItem not found");
	}

	void RenderItem::AddDrawItem(ISubWidget* item, size_t count)
	{

#if DEBUG_MODE == 1
		for (VectorDrawItem::iterator iter=mDrawItems.begin(); iter!=mDrawItems.end(); ++iter)
		{
			ASSERT((*iter).first != item, "DrawItem exist");
		}
#endif

		mDrawItems.push_back(DrawItemInfo(item, count));
		mNeedVertexCount += count;
		mOutDate = true;

		mVertexBuffer->SetVertextCount(mNeedVertexCount);
	}

	void RenderItem::ReallockDrawItem(ISubWidget* item, size_t count)
	{
		for (VectorDrawItem::iterator iter=mDrawItems.begin(); iter!=mDrawItems.end(); ++iter)
		{
			if ((*iter).first == item)
			{
				if ((*iter).second < count)
				{
					mNeedVertexCount -= (*iter).second;
					mNeedVertexCount += count;
					(*iter).second = count;
					mOutDate = true;

					mVertexBuffer->SetVertextCount(mNeedVertexCount);
				}
				return;
			}
		}
		EXCEPT("DrawItem not found");
	}

	void RenderItem::SetTexture(ITexture* value)
	{
		DEBUG_ASSERT(mVertexBuffer->GetVertextCount() == 0, "change texture only empty buffer");
		DEBUG_ASSERT(mNeedVertexCount == 0, "change texture only empty buffer");

		mTexture = value;

#if DEBUG_MODE == 1
		mTextureName = mTexture == nullptr ? "" : mTexture->GetName();
#endif
	}

	ITexture* RenderItem::GetTexture()
	{
		return mTexture;
	}

	bool RenderItem::GetCompression()
	{
		bool result = mCompression;
		mCompression = false;
		return result;
	}

} // namespace GUI

