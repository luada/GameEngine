#include "Precompiled.h"
#include "LayerItem.h"
#include "SharedLayer.h"
#include "LayerNode.h"
#include "RenderManager.h"

namespace GUI
{

	SharedLayer::SharedLayer() :
		mIsPick(false),
		mChildItem(nullptr)
	{
	}

	SharedLayer::~SharedLayer()
	{
		ASSERT(mChildItem == nullptr, "Layer '" << GetName() << "' must be empty before destroy");
	}

	void SharedLayer::Deserialization(xml::ElementPtr node, Version version)
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

	ILayerNode* SharedLayer::CreateChildItemNode()
	{
		if (mChildItem == nullptr)
		{
			mChildItem = new SharedLayerNode(this);
		}

		mChildItem->AddUsing();
		return mChildItem;
	}

	void SharedLayer::DestroyChildItemNode(ILayerNode* item)
	{
		if (mChildItem == item)
		{
			mChildItem->RemoveUsing();
			if (0 == mChildItem->CountUsing())
			{
				delete mChildItem;
				mChildItem = nullptr;
			}
			return;
		}
		//EXCEPT("item node not found");
	}

	void SharedLayer::UpChildItemNode(ILayerNode* item)
	{
		ILayerNode * parent = item->GetParent();
		if (parent != nullptr)
		{
			parent->UpChildItemNode(item);
		}
	}

	ILayerItem * SharedLayer::GetLayerItemByPoint(int left, int top)
	{
		if (!mIsPick) return nullptr;
		if (mChildItem != nullptr)
		{
			ILayerItem * item = mChildItem->GetLayerItemByPoint(left, top);
			if (item != nullptr) return item;
		}
		return nullptr;
	}

	IntPoint SharedLayer::GetPosition(int left, int top) const
	{
		return IntPoint(left, top);
	}

	void SharedLayer::RenderToTarget(IRenderTarget* target, bool update)
	{
		if (mChildItem != nullptr) mChildItem->RenderToTarget(target, update);
	}

	EnumeratorILayerNode SharedLayer::GetEnumerator()
	{
		static VectorILayerNode nodes;
		if (mChildItem == nullptr)
		{
			nodes.clear();
		}
		else
		{
			if (nodes.empty()) nodes.push_back(mChildItem);
			else nodes[0] = mChildItem;
		}

		return EnumeratorILayerNode(nodes);
	}

	void SharedLayer::DumpStatisticToLog()
	{
		static const char* spacer = "                                                                                                                        ";
		LOG(Info, spacer);
		LOG(Info, "Layer name='" << GetName() << "'" << " type='" << GetTypeName() << "'" << spacer);
		LOG(Info, "Count root nodes : " << (mChildItem == nullptr ? 0 : 1) << spacer);

		if (mChildItem != nullptr)
		{
			mChildItem->DumpStatisticToLog(0);
		}
	}

	const IntSize& SharedLayer::GetSize() const
	{
		return RenderManager::GetInstance().GetViewSize();
	}

} // namespace GUI

