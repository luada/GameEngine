#include "Precompiled.h"
#include "ResourceManualFont.h"
#include "SkinManager.h"
#include "RenderManager.h"
#include "TextureUtility.h"

namespace GUI
{

	ResourceManualFont::ResourceManualFont() :
		mDefaultHeight(0),
		mTexture(nullptr)
	{
	}

	ResourceManualFont::~ResourceManualFont()
	{
	}

	GlyphInfo * ResourceManualFont::GetGlyphInfo(Char id)
	{
		for (VectorRangeInfo::iterator iter=mVectorRangeInfo.begin(); iter!=mVectorRangeInfo.end(); ++iter)
		{
			GlyphInfo * info = iter->GetInfo(id);
			if (info == nullptr) continue;
			return info;
		}
		return &mSpaceGlyphInfo;
	}

	void ResourceManualFont::CheckTexture()
	{
		if (mTexture == nullptr)
		{
			RenderManager& render = RenderManager::GetInstance();
			mTexture = render.GetTexture(mSource);
			if (mTexture == nullptr)
			{
				mTexture = render.CreateTexture(mSource);
				mTexture->LoadFromFile(mSource);
			}
		}
	}

	void ResourceManualFont::AddGlyph(GlyphInfo * info, Char index, int left, int top, int right, int bottom, int finalw, int finalh, float aspect, int addHeight)
	{
		info->codePoint = index;
		info->uvRect.left = (float)left / (float)finalw;  // u1
		info->uvRect.top = (float)(top + addHeight) / (float)finalh;  // v1
		info->uvRect.right = (float)( right ) / (float)finalw; // u2
		info->uvRect.bottom = ( bottom + addHeight ) / (float)finalh; // v2
		info->width = right - left;
	}

	void ResourceManualFont::AddGlyph(Char code, const IntCoord& coord)
	{
		mVectorPairCodeCoord.push_back(PairCodeCoord(code, coord));
	}

	void ResourceManualFont::Initialise()
	{
		if (mVectorPairCodeCoord.empty()) return;

		std::sort(mVectorPairCodeCoord.begin(), mVectorPairCodeCoord.end());

		const IntSize& size = texture_utility::GetTextureSize(mSource);
		float aspect = (float)size.width / (float)size.height;

		Char code = mVectorPairCodeCoord.front().code;
		size_t count = mVectorPairCodeCoord.size();
		size_t first = 0;

		for (size_t pos=1; pos<count; ++pos)
		{
			if (code + 1 != mVectorPairCodeCoord[pos].code)
			{
				AddRange(mVectorPairCodeCoord, first, pos-1, size.width, size.height, aspect);
				code = mVectorPairCodeCoord[pos].code;
				first = pos;
			}
			else
			{
				code ++;
			}
		}

		AddRange(mVectorPairCodeCoord, first, count-1, size.width, size.height, aspect);

		VectorPairCodeCoord tmp;
		std::swap(tmp, mVectorPairCodeCoord);

		CheckTexture();
	}

	void ResourceManualFont::AddRange(VectorPairCodeCoord& info, size_t first, size_t last, int width, int height, float aspect)
	{
		RangeInfo range = RangeInfo(info[first].code, info[last].code);

		for (size_t pos=first; pos<=last; ++pos)
		{
			GlyphInfo * curInfo = range.GetInfo(info[pos].code);
			const IntCoord& coord = info[pos].coord;
			AddGlyph(curInfo, info[pos].code, coord.left, coord.top, coord.Right(), coord.Bottom(), width, height, aspect);

			if (info[pos].code == FontCodeType::Space)
				mSpaceGlyphInfo = *curInfo;
		}

		mVectorRangeInfo.push_back(range);
	}

	void ResourceManualFont::Deserialization(xml::ElementPtr node, Version version)
	{
		Base::Deserialization(node, version);

		xml::ElementEnumerator curNode = node->GetElementEnumerator();
		while (curNode.Next())
		{
			if (curNode->GetName() == "Property")
			{
				const std::string& key = curNode->findAttribute("key");
				const std::string& value = curNode->findAttribute("value");
				if (key == "Source") mSource = value;
				else if (key == "DefaultHeight") mDefaultHeight = utility::ParseInt(value);
			}
			else if (curNode->GetName() == "Codes")
			{
				xml::ElementEnumerator range = curNode->GetElementEnumerator();
				while (range.Next("Code"))
				{
					std::string range_value;
					std::vector<std::string> parse_range;
					if (range->findAttribute("index", range_value))
					{
						Char id = 0;
						if (range_value == "cursor")
							id = FontCodeType::Cursor;
						else if (range_value == "selected")
							id = FontCodeType::Selected;
						else if (range_value == "selected_back")
							id = FontCodeType::SelectedBack;
						else
							id = utility::ParseUInt(range_value);

						AddGlyph(id, utility::ParseValue<IntCoord>(range->findAttribute("coord")));
					}
				}
			}
		}

		Initialise();
	}

} // namespace GUI

