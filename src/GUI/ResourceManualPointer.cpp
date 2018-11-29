#include "Precompiled.h"
#include "ResourceManualPointer.h"
#include "StaticImage.h"
#include "CoordConverter.h"
#include "TextureUtility.h"

namespace GUI
{

	void ResourceManualPointer::Deserialization(xml::ElementPtr node, Version version)
	{
		Base::Deserialization(node, version);

		IntCoord coord;

		xml::ElementEnumerator info = node->GetElementEnumerator();
		while (info.Next("Property"))
		{
			const std::string& key = info->findAttribute("key");
			const std::string& value = info->findAttribute("value");

			if (key == "Point") mPoint = IntPoint::Parse(value);
			else if (key == "Size") mSize = IntSize::Parse(value);
			else if (key == "Texture") mTexture = value;
			else if (key == "Coord") coord = IntCoord::Parse(value);
		}

		mOffset = CoordConverter::ConvertTextureCoord(
			coord,
			texture_utility::GetTextureSize(mTexture));
	}

	void ResourceManualPointer::SetImage(StaticImage* image)
	{
		image->DeleteAllItems();
		image->_setTextureName(mTexture);
		image->_setUVSet(mOffset);
	}

	void ResourceManualPointer::SetPosition(StaticImage* image, const IntPoint& point)
	{
		image->SetCoord(point.left - mPoint.left, point.top - mPoint.top, mSize.width, mSize.height);
	}

} // namespace GUI

