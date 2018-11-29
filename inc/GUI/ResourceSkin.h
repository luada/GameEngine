#ifndef __RESOURCE_SKIN_H__
#define __RESOURCE_SKIN_H__

#include "Prerequest.h"
#include "SubWidgetBinding.h"
#include "ChildSkinInfo.h"
#include "MaskPickInfo.h"
#include "IResource.h"
#include "SubWidgetInfo.h"

namespace GUI
{

	class GUI_EXPORT ResourceSkin :
		public IResource
	{
		RTTI_DERIVED(ResourceSkin)

	public:
		ResourceSkin();

		virtual void Deserialization(xml::ElementPtr node, Version version);

		const IntSize& GetSize() const { return mSize; }
		const std::string& GetTextureName() const { return mTexture; }
		const VectorSubWidgetInfo& GetBasisInfo() const { return mBasis; }
		const MapWidgetStateInfo& GetStateInfo() const { return mStates; }
		const MapString& GetProperties() const { return mProperties; }
		const VectorChildSkinInfo& GetChild() const { return mChilds; }
		MaskPickInfo const * GetMask() const { return &mMaskPeek; }
		const std::string& GetSkinName() { return mSkinName; }

	private:
		void SetInfo(const IntSize& size, const std::string &_texture);
		void AddInfo(const SubWidgetBinding& bind);
		void AddProperty(const std::string &_key, const std::string &_value);
		void AddChild(const ChildSkinInfo& child);
		bool LoadMask(const std::string& file);
		void Clear();

		void CheckState(const MapStateInfo& states);
		void CheckState(const std::string& name);
		void CheckBasis();
		void FillState(const MapStateInfo& states, size_t index);

	private:
		IntSize mSize;
		std::string mTexture;
		VectorSubWidgetInfo mBasis;
		MapWidgetStateInfo mStates;
		MapString mProperties;
		VectorChildSkinInfo mChilds;
		MaskPickInfo mMaskPeek;
		std::string mSkinName;

	};

} // namespace GUI

#endif // __RESOURCE_SKIN_H__

