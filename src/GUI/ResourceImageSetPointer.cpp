#include "Precompiled.h"
#include "ResourceImageSetPointer.h"
#include "StaticImage.h"
#include "ResourceManager.h"

namespace GUI
{

	ResourceImageSetPointer::ResourceImageSetPointer() :
		mImageSet(nullptr)
	{
	}

	void ResourceImageSetPointer::Deserialization(xml::ElementPtr node, Version version)
	{
		Base::Deserialization(node, version);

		xml::ElementEnumerator info = node->GetElementEnumerator();
		while (info.Next("Property"))
		{
			const std::string& key = info->findAttribute("key");
			const std::string& value = info->findAttribute("value");

			if (key == "Point") mPoint = IntPoint::Parse(value);
			else if (key == "Size") mSize = IntSize::Parse(value);
			else if (key == "Resource") mImageSet = ResourceManager::GetInstance().GetByName(value)->CastType<ResourceImageSet>();
		}
	}

	void ResourceImageSetPointer::SetImage(StaticImage* image)
	{
		if (mImageSet != nullptr)
			image->SetItemResourceInfo(mImageSet->GetIndexInfo(0, 0));
	}

	void ResourceImageSetPointer::SetPosition(StaticImage* image, const IntPoint& point)
	{
		image->SetCoord(point.left - mPoint.left, point.top - mPoint.top, mSize.width, mSize.height);
	}

} // namespace GUI

