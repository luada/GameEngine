#include "Precompiled.h"
#include "LayerItem.h"
#include "OverlappedLayer.h"
#include "LayerNode.h"
#include "RenderManager.h"

namespace GUI
{

	OverlappedLayer::OverlappedLayer() :
		mIsPick(false)
	{
	}

	OverlappedLayer::~OverlappedLayer()
	{
		ASSERT(mChildItems.empty(), "Layer '" << GetName() << "' must be empty before destroy");
	}

	void OverlappedLayer::Deserialization(xml::ElementPtr node, Version version)
	{
		mName = node->findAttribute("name");
		if (version >= Version(1, 2))
		{
			GUI::xml::ElementEnumerator propert = node->GetElementEnumerator();
			while (propert.Next("Property"))
			{
				const std::string& key = propert->findAttribute("key");
				const std::string& value = propert->findAttribute("value");
				if (key == "Pick") mIsPick = utility::ParseValue<bool>(value);
			}
		}
		else
		{
			mIsPick = utility::ParseBool(version < Version(1, 0) ? node->findAttribute("peek") : node->findAttribute("pick"));
		}
	}

	ILayerNode * OverlappedLayer::CreateChildItemNode()
	{
		ILayerNode * node = new LayerNode(this);
		mChildItems.push_back(node);

		return node;
	}

	void OverlappedLayer::DestroyChildItemNode(ILayerNode* item)
	{
		ILayerNode * parent = item->GetParent();
		if (parent)
		{
			parent->DestroyChildItemNode(item);
			return;
		}

		for (VectorILayerNode::iterator iter=mChildItems.begin(); iter!=mChildItems.end(); ++iter)
		{
			if ((*iter) == item)
			{
				delete item;
				mChildItems.erase(iter);
				return;
			}
		}
		EXCEPT("item node not found");
	}

	void OverlappedLayer::UpChildItemNode(ILayerNode* item)
	{
		ILayerNode* parent = item->GetParent();
		if (parent != nullptr)
		{
			parent->UpChildItemNode(item);
			return;
		}

		if ((2 > mChildItems.size()) || (mChildItems.back() == item)) return;
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

	ILayerItem * OverlappedLayer::GetLayerItemByPoint(int left, int top)
	{
		if (!mIsPick) return nullptr;
		VectorILayerNode::reverse_iterator iter = mChildItems.rbegin();
		while (iter != mChildItems.rend())
		{
			ILayerItem * item = (*iter)->GetLayerItemByPoint(left, top);
			if (item != nullptr) return item;
			++iter;
		}
		return nullptr;
	}

	IntPoint OverlappedLayer::GetPosition(int left, int top) const
	{
		return IntPoint(left, top);
	}

	void OverlappedLayer::RenderToTarget(IRenderTarget* target, bool update)
	{
		for (VectorILayerNode::iterator iter=mChildItems.begin(); iter!=mChildItems.end(); ++iter)
		{
			(*iter)->RenderToTarget(target, update);
		}
	}

	EnumeratorILayerNode OverlappedLayer::GetEnumerator()
	{
		return EnumeratorILayerNode(mChildItems);
	}

	void OverlappedLayer::DumpStatisticToLog()
	{
		static const char* spacer = "                                                                                                                        ";
		LOG(Info, spacer);
		LOG(Info, "Layer name='" << GetName() << "'" << " type='" << GetTypeName() << "'" << spacer);
		LOG(Info, "Count root nodes : " << mChildItems.size() << spacer);

		for (VectorILayerNode::iterator iter=mChildItems.begin(); iter!=mChildItems.end(); ++iter)
		{
			(*iter)->DumpStatisticToLog(0);
		}
	}

	const IntSize& OverlappedLayer::GetSize() const
	{
		return RenderManager::GetInstance().GetViewSize();
	}

} // namespace GUI

