#ifndef __LAYER_MANAGER_H__
#define __LAYER_MANAGER_H__

#include "Prerequest.h"
#include "Instance.h"
#include "Enumerator.h"
#include "XmlDocument.h"
#include "IUnlinkWidget.h"
#include "ResourceManager.h"
#include "ILayer.h"

namespace GUI
{

	class GUI_EXPORT LayerManager :
		public IUnlinkWidget
	{
		INSTANCE_HEADER(LayerManager)

	public:
		typedef std::vector<ILayer*> VectorLayer;
		typedef Enumerator<VectorLayer> EnumeratorLayer;

	public:
		void Initialise();
		void Shutdown();

		//@ExportToLua
		static LayerManager& Instance()
		{
			return GetInstance();
		}

		/** Attach widget to specific layer
			@param _name Layer name
			@param _item Widget pointer
		*/
		//@ExportToLua
		void AttachToLayerNode(const std::string& name, Widget* item);

		/** Detach widget from layer
			@param _item Widget pointer
		*/
		//@ExportToLua
		void DetachFromLayer(Widget* item);

		/** Up widget to be on top of its layer
			@param _item Widget pointer
		*/
		//@ExportToLua
		void UpLayerItem(Widget* item);

		/** Load additional GUI *_layer.xml file */
		bool Load(const std::string& file);
		void _load(xml::ElementPtr node, const std::string& file, Version version);

		/** Check is layer exist */
		//@ExportToLua
		bool IsExist(const std::string& name) const;

		/** Get layer nodes Enumerator */
		EnumeratorLayer GetEnumerator() { return EnumeratorLayer(mLayerNodes); }

		ILayer* GetByName(const std::string& name, bool _throw = true) const;

		/** Get top visible and enabled widget at specified position */
		//@ExportToLua
		Widget* GetWidgetFromPoint(int left, int top);

		void RenderToTarget(IRenderTarget* target, bool update);

		//@ExportToLua
		virtual void DumpStatisticToLog();

	private:
		void _unlinkWidget(Widget* widget);

		void Clear();

		void Merge(VectorLayer& layers);
		void Destroy(ILayer* layer);

	private:
		VectorLayer mLayerNodes;

	};

} // namespace GUI

#endif // __LAYER_MANAGER_H__

