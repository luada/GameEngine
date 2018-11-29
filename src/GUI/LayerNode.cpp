#include "Precompiled.h"
#include "LayerNode.h"
#include "ILayerItem.h"
#include "ITexture.h"
#include "ISubWidget.h"
#include "ISubWidgetText.h"

namespace GUI
{

	LayerNode::LayerNode(ILayer* layer, ILayerNode* parent) :
		mParent(parent),
		mLayer(layer),
		mOutOfDate(false)
	{
	}

	LayerNode::~LayerNode()
	{
		for (VectorRenderItem::iterator iter=mFirstRenderItems.begin(); iter!=mFirstRenderItems.end(); ++iter)
		{
			delete (*iter);
		}
		mFirstRenderItems.clear();

		for (VectorRenderItem::iterator iter=mSecondRenderItems.begin(); iter!=mSecondRenderItems.end(); ++iter)
		{
			delete (*iter);
		}
		mSecondRenderItems.clear();

		for (VectorILayerNode::iterator iter = mChildItems.begin(); iter!=mChildItems.end(); ++iter)
		{
			delete (*iter);
		}
		mChildItems.clear();
	}

	ILayerNode* LayerNode::CreateChildItemNode()
	{
		LayerNode* layer = new LayerNode(mLayer, this);
		mChildItems.push_back(layer);
		return layer;
	}

	void LayerNode::DestroyChildItemNode(ILayerNode* node)
	{
		for (VectorILayerNode::iterator iter=mChildItems.begin(); iter!=mChildItems.end(); ++iter)
		{
			if ((*iter) == node)
			{
				delete node;
				mChildItems.erase(iter);
				return;
			}
		}
		EXCEPT("item curNode not found");
	}

	void LayerNode::UpChildItemNode(ILayerNode* item)
	{
		for (VectorILayerNode::iterator iter=mChildItems.begin(); iter!=mChildItems.end(); ++iter)
		{
			if ((*iter) == item)
			{
				mChildItems.erase(iter);
				mChildItems.push_back(item);
				return;
			}
		}
		EXCEPT("item node not found");
	}

	void LayerNode::RenderToTarget(IRenderTarget* target, bool update)
	{
		bool need_compression = false;
		for (VectorRenderItem::iterator iter=mFirstRenderItems.begin(); iter!=mFirstRenderItems.end(); ++iter)
		{
			if ((*iter)->GetCompression())
			{
				need_compression = true;
				break;
			}
		}

		if (need_compression)
			UpdateCompression();

		for (VectorRenderItem::iterator iter=mFirstRenderItems.begin(); iter!=mFirstRenderItems.end(); ++iter)
		{
			(*iter)->RenderToTarget(target, update);
		}
		for (VectorRenderItem::iterator iter=mSecondRenderItems.begin(); iter!=mSecondRenderItems.end(); ++iter)
		{
			(*iter)->RenderToTarget(target, update);
		}

		for (VectorILayerNode::iterator iter = mChildItems.begin(); iter!=mChildItems.end(); ++iter)
		{
			(*iter)->RenderToTarget(target, update);
		}

		mOutOfDate = false;
	}

	ILayerItem* LayerNode::GetLayerItemByPoint(int left, int top)
	{
		for (VectorILayerNode::iterator iter = mChildItems.begin(); iter!=mChildItems.end(); ++iter)
		{
			ILayerItem * item = (*iter)->GetLayerItemByPoint(left, top);
			if (nullptr != item) return item;
		}

		for (VectorLayerItem::iterator iter=mLayerItems.begin(); iter!=mLayerItems.end(); ++iter)
		{
			ILayerItem * item = (*iter)->GetLayerItemByPoint(left, top);
			if (nullptr != item) return item;
		}

		return nullptr;
	}

	RenderItem* LayerNode::AddToRenderItem(ITexture* texture, ISubWidget* item)
	{
		bool first = item->CastType<ISubWidgetText>(false) == nullptr;
		if (first)
		{
			if (mFirstRenderItems.empty())
			{
				RenderItem * curItem = new RenderItem();
				curItem->SetTexture(texture);
				mFirstRenderItems.push_back(curItem);

				return curItem;
			}

			if (mFirstRenderItems.back()->GetNeedVertexCount() == 0)
			{
				for (VectorRenderItem::iterator iter=mFirstRenderItems.begin(); iter!=mFirstRenderItems.end(); ++iter)
				{
					if ((*iter)->GetNeedVertexCount() == 0)
					{
						if (iter != mFirstRenderItems.begin())
						{
							VectorRenderItem::iterator prev = iter - 1;
							if ((*prev)->GetTexture() == texture)
							{
								return (*prev);
							}
						}
						(*iter)->SetTexture(texture);
						return (*iter);
					}
				}
			}

			if (mFirstRenderItems.back()->GetTexture() == texture)
			{
				return mFirstRenderItems.back();
			}

			RenderItem * curItem = new RenderItem();
			curItem->SetTexture(texture);
			mFirstRenderItems.push_back(curItem);

			return curItem;
		}

		for (VectorRenderItem::iterator iter=mSecondRenderItems.begin(); iter!=mSecondRenderItems.end(); ++iter)
		{
			if ((*iter)->GetTexture() == texture)
			{
				return (*iter);
			}
			else if ((*iter)->GetNeedVertexCount() == 0)
			{
				(*iter)->SetTexture(texture);
				return (*iter);
			}

		}
		RenderItem * curItem = new RenderItem();
		curItem->SetTexture(texture);

		mSecondRenderItems.push_back(curItem);
		return mSecondRenderItems.back();
	}

	void LayerNode::AttachLayerItem(ILayerItem* item)
	{
		mLayerItems.push_back(item);
		item->AttachItemToNode(mLayer, this);
	}

	void LayerNode::DetachLayerItem(ILayerItem* item)
	{
		for (VectorLayerItem::iterator iter=mLayerItems.begin(); iter!=mLayerItems.end(); ++iter)
		{
			if ((*iter) == item)
			{
				(*iter) = mLayerItems.back();
				mLayerItems.pop_back();
				return;
			}
		}
		EXCEPT("layer curItem not found");
	}

	void LayerNode::OutOfDate(RenderItem* item)
	{
		mOutOfDate = true;
		if (item)
			item->OutOfDate();
	}

	EnumeratorILayerNode LayerNode::GetEnumerator()
	{
		return EnumeratorILayerNode(mChildItems);
	}

	void LayerNode::UpdateCompression()
	{
		if (mFirstRenderItems.size() > 1)
		{
			VectorRenderItem::iterator iter1 = mFirstRenderItems.begin();
			VectorRenderItem::iterator iter2 = iter1 + 1;
			while (iter2 != mFirstRenderItems.end())
			{
				if ((*iter1)->GetNeedVertexCount() == 0)
				{
					RenderItem * tmp = (*iter1);
					(*iter1) = (*iter2);
					(*iter2) = tmp;
				}
				iter1 = iter2;
				++iter2;
			}
		}
	}

	void LayerNode::DumpStatisticToLog(size_t level)
	{
		static const char* spacer = "                                                                                                                        ";
		std::string offset(" ", level);
		LOG(Info, offset << " - Node batch_count='" << mFirstRenderItems.size() + mSecondRenderItems.size() << spacer);

		for (VectorRenderItem::iterator iter=mFirstRenderItems.begin(); iter!=mFirstRenderItems.end(); ++iter)
		{
			LOG(Info, offset << "  * Batch texture='" << ((*iter)->GetTexture() == nullptr ? "nullptr" : (*iter)->GetTexture()->GetName()) << "' vertex_count='" << (*iter)->GetVertexCount() << "'" << spacer);
		}
		for (VectorRenderItem::iterator iter=mSecondRenderItems.begin(); iter!=mSecondRenderItems.end(); ++iter)
		{
			LOG(Info, offset << "  * Batch texture='" << ((*iter)->GetTexture() == nullptr ? "nullptr" : (*iter)->GetTexture()->GetName()) << "' vertex_count='" << (*iter)->GetVertexCount() << "'" << spacer);
		}

		for (VectorILayerNode::iterator iter = mChildItems.begin(); iter!=mChildItems.end(); ++iter)
		{
			(*iter)->DumpStatisticToLog(level + 1);
		}
	}

} // namespace GUI

