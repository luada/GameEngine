#include "Precompiled.h"
#include "LayerManager.h"
#include "LayerItem.h"
#include "WidgetManager.h"
#include "RenderManager.h"
#include "Widget.h"
#include "FactoryManager.h"

#include "SharedLayer.h"
#include "OverlappedLayer.h"

namespace GUI
{

	const std::string XML_TYPE("Layer");

	INSTANCE_IMPLEMENT(LayerManager)

	void LayerManager::Initialise()
	{
		ASSERT(!mIsInitialise, INSTANCE_TYPE_NAME << " initialised twice");
		LOG(Info, "* Initialise: " << INSTANCE_TYPE_NAME);

		WidgetManager::GetInstance().RegisterUnlinker(this);
		ResourceManager::GetInstance().RegisterLoadXmlDelegate(XML_TYPE) = NewDelegate(this, &LayerManager::_load);

		FactoryManager::GetInstance().RegisterFactory<SharedLayer>(XML_TYPE);
		FactoryManager::GetInstance().RegisterFactory<OverlappedLayer>(XML_TYPE);

		LOG(Info, INSTANCE_TYPE_NAME << " successfully initialized");
		mIsInitialise = true;
	}

	void LayerManager::Shutdown()
	{
		if (!mIsInitialise) return;
		LOG(Info, "* Shutdown: " << INSTANCE_TYPE_NAME);

		FactoryManager::GetInstance().UnregisterFactory<SharedLayer>(XML_TYPE);
		FactoryManager::GetInstance().UnregisterFactory<OverlappedLayer>(XML_TYPE);

		Clear();

		WidgetManager::GetInstance().UnregisterUnlinker(this);
		ResourceManager::GetInstance().UnregisterLoadXmlDelegate(XML_TYPE);

		LOG(Info, INSTANCE_TYPE_NAME << " successfully shutdown");
		mIsInitialise = false;
	}

	void LayerManager::Clear()
	{
		for (VectorLayer::iterator iter=mLayerNodes.begin(); iter!=mLayerNodes.end(); ++iter)
		{
			Destroy(*iter);
		}
		mLayerNodes.clear();
	}

	bool LayerManager::Load(const std::string& file)
	{
		return ResourceManager::GetInstance()._loadImplement(file, true, XML_TYPE, INSTANCE_TYPE_NAME);
	}

	void LayerManager::_load(xml::ElementPtr node, const std::string& file, Version version)
	{
		VectorLayer layers;
		xml::ElementEnumerator layer = node->GetElementEnumerator();
		while (layer.Next(XML_TYPE))
		{

			std::string name;

			if ( !layer->findAttribute("name", name))
			{
				LOG(warning, "Attribute 'name' not Found (curFile : " << file << ")");
				continue;
			}

			for (VectorLayer::iterator iter=layers.begin(); iter!=layers.end(); ++iter)
			{
				ASSERT((*iter)->GetName() != name, "Layer '" << name << "' already Exist (curFile : " << file << ")");
			}

			std::string type = layer->findAttribute("type");
			if (type.empty() && version <= Version(1, 0))
			{
				bool overlapped = utility::ParseBool(layer->findAttribute("overlapped"));
				type = overlapped ? "OverlappedLayer" : "SharedLayer";
			}

			IObject* object = FactoryManager::GetInstance().CreateObject(XML_TYPE, type);
			ASSERT(object != nullptr, "factory is '" << type << "' not found");

			ILayer* item = object->CastType<ILayer>();
			item->Deserialization(layer.Current(), version);

			layers.push_back(item);
		}

		Merge(layers);
	}

	void LayerManager::_unlinkWidget(Widget* widget)
	{
		DetachFromLayer(widget);
	}

	void LayerManager::AttachToLayerNode(const std::string& name, Widget* item)
	{
		ASSERT(nullptr != item, "pointer must be valid");
		ASSERT(item->IsRootWidget(), "attached widget must be root");

		item->DetachFromLayer();

		for (VectorLayer::iterator iter=mLayerNodes.begin(); iter!=mLayerNodes.end(); ++iter)
		{
			if (name == (*iter)->GetName())
			{
				ILayerNode* node = (*iter)->CreateChildItemNode();
				node->AttachLayerItem(item);

				return;
			}
		}
		LOG(Error, "Layer '" << name << "' is not found");
		//EXCEPT("Layer '" << name << "' is not found");
	}

	void LayerManager::DetachFromLayer(Widget* item)
	{
		ASSERT(nullptr != item, "pointer must be valid");
		item->DetachFromLayer();
	}

	void LayerManager::UpLayerItem(Widget* item)
	{
		ASSERT(nullptr != item, "pointer must be valid");
		item->UpLayerItem();
	}

	bool LayerManager::IsExist(const std::string& name) const
	{
		return GetByName(name, false) != nullptr;
	}

	void LayerManager::Merge(VectorLayer& layers)
	{
		for (VectorLayer::iterator iter=mLayerNodes.begin(); iter!=mLayerNodes.end(); ++iter)
		{
			if ((*iter) == nullptr) continue;
			bool find = false;
			std::string name = (*iter)->GetName();
			for (VectorLayer::iterator iter2=layers.begin(); iter2!=layers.end(); ++iter2)
			{
				if (name == (*iter2)->GetName())
				{
					delete (*iter2);
					(*iter2) = (*iter);
					(*iter) = nullptr;
					find = true;
					break;
				}
			}
			if (!find)
			{
				Destroy(*iter);
				(*iter) = nullptr;
			}
		}

		mLayerNodes = layers;
	}

	void LayerManager::Destroy(ILayer* layer)
	{
		LOG(Info, "destroy curLayer '" << layer->GetName() << "'");
		delete layer;
	}
	Widget* LayerManager::GetWidgetFromPoint(int left, int top)
	{
		VectorLayer::reverse_iterator iter = mLayerNodes.rbegin();
		while (iter != mLayerNodes.rend())
		{
			ILayerItem * item = (*iter)->GetLayerItemByPoint(left, top);
			if (item != nullptr) return static_cast<Widget*>(item);
			++iter;
		}
		return nullptr;
	}

	void LayerManager::RenderToTarget(IRenderTarget* target, bool update)
	{
		for (VectorLayer::iterator iter=mLayerNodes.begin(); iter!=mLayerNodes.end(); ++iter)
		{
			(*iter)->RenderToTarget(target, update);
		}
	}

	ILayer* LayerManager::GetByName(const std::string& name, bool _throw) const
	{
		for (VectorLayer::const_iterator iter=mLayerNodes.begin(); iter!=mLayerNodes.end(); ++iter)
		{
			if (name == (*iter)->GetName())
				return (*iter);
		}
		ASSERT(!_throw, "Layer '" << name << "' not found");
		return nullptr;
	}

	void LayerManager::DumpStatisticToLog()
	{
		static const char* spacer = "                                                                                                                        ";
		LOG(Info, spacer);
		LOG(Info, "---------- Statistic for layers start ----------" << spacer);
		for (VectorLayer::iterator iter=mLayerNodes.begin(); iter!=mLayerNodes.end(); ++iter)
		{
			(*iter)->DumpStatisticToLog();
		}
		LOG(Info, spacer);
		LOG(Info, "---------- Statistic for layers end ----------" << spacer);
		LOG(Info, spacer);
	}

} // namespace GUI

