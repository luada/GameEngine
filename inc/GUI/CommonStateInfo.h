#ifndef __COMMON_STATE_INFO_H__
#define __COMMON_STATE_INFO_H__

#include "Prerequest.h"
#include "IStateInfo.h"
#include "CoordConverter.h"
#include "LanguageManager.h"
#include "TextureUtility.h"

namespace GUI
{

	class GUI_EXPORT SubSkinStateInfo :
		public IStateInfo
	{
		RTTI_DERIVED(SubSkinStateInfo)

	public:
		virtual ~SubSkinStateInfo() { }

		const FloatRect& GetRect() { return mRect; }

	private:
		virtual void Deserialization(xml::ElementPtr node, Version version)
		{
			std::string texture = node->GetParent()->GetParent()->findAttribute("texture");

			if (version >= Version(1, 1))
			{
				texture = LanguageManager::GetInstance().ReplaceTags(texture);
			}

			const IntSize& size = texture_utility::GetTextureSize(texture);
			const IntCoord& coord = IntCoord::Parse(node->findAttribute("offset"));
			mRect = CoordConverter::ConvertTextureCoord(coord, size);
		}

	private:
		FloatRect mRect;
	};

	class GUI_EXPORT TileRectStateInfo :
		public IStateInfo
	{
		RTTI_DERIVED(TileRectStateInfo)

	public:
		TileRectStateInfo() : mTileH(true), mTileV(true) { }
		virtual ~TileRectStateInfo() { }

		const FloatRect& GetRect() { return mRect; }
		const IntSize& GetTileSize() { return mTileSize; }
		bool GetTileH() { return mTileH; }
		bool GetTileV() { return mTileV; }

	private:
		virtual void Deserialization(xml::ElementPtr node, Version version)
		{
			std::string texture = node->GetParent()->GetParent()->findAttribute("texture");

			if (version >= Version(1, 1))
			{
				texture = LanguageManager::GetInstance().ReplaceTags(texture);
			}

			const IntSize& size = texture_utility::GetTextureSize(texture);
			const IntCoord& coord = IntCoord::Parse(node->findAttribute("offset"));
			mRect = CoordConverter::ConvertTextureCoord(coord, size);

			xml::ElementEnumerator prop = node->GetElementEnumerator();
			while (prop.Next("Property"))
			{
				const std::string& key = prop->findAttribute("key");
				const std::string& value = prop->findAttribute("value");
				if (key == "TileH") mTileH = utility::ParseBool(value);
				else if (key == "TileV") mTileV = utility::ParseBool(value);
				else if (key == "TileSize") mTileSize = IntSize::Parse(value);
			}
		}

	private:
		FloatRect mRect;
		IntSize mTileSize;
		bool mTileH;
		bool mTileV;
	};

	class GUI_EXPORT EditTextStateInfo :
		public IStateInfo
	{
		RTTI_DERIVED(EditTextStateInfo)

	public:
		EditTextStateInfo() : mColour(Colour::White), mShift(false) { }
		virtual ~EditTextStateInfo() { }

		const Colour& GetColour() { return mColour; }
		bool GetShift() { return mShift; }

	private:
		virtual void Deserialization(xml::ElementPtr node, Version version)
		{
			mShift = utility::ParseBool(node->findAttribute("shift"));

			std::string colour = node->findAttribute("colour");
			if (version >= Version(1, 1))
			{
				colour = LanguageManager::GetInstance().ReplaceTags(colour);
			}

			mColour = Colour::Parse(colour);
		}

	private:
		Colour mColour;
		bool mShift;
	};

} // namespace GUI

#endif // __COMMON_STATE_INFO_H__

