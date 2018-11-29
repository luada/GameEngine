#include "Precompiled.h"
#include "ResourceTrueTypeFont.h"
#include "DataManager.h"
#include "RenderManager.h"

#ifdef USE_FREETYPE
	#include "ft2build.h"
	#include FT_FREETYPE_H
	#include FT_GLYPH_H
#endif // USE_FREETYPE

namespace GUI
{

	const unsigned char FONT_MASK_SELECT = 0x88;
	const unsigned char FONT_MASK_SELECT_DEACTIVE = 0x60;
	const unsigned char FONT_MASK_SPACE = 0x00;
	const unsigned char FONT_MASK_CHAR = 0xFF;
	const size_t MIN_FONT_TEXTURE_WIDTH = 256;

	ResourceTrueTypeFont::ResourceTrueTypeFont() :
		mTtfSize(0),
		mTtfResolution(0),
		mAntialiasColour(false),
		mDistance(0),
		mSpaceWidth(0),
		mTabWidth(0),
		mCursorWidth(2),
		mSelectionWidth(2),
		mOffsetHeight(0),
		mHeightPix(0),
		mTexture(nullptr)
	{
	}

	ResourceTrueTypeFont::~ResourceTrueTypeFont()
	{
		if (mTexture != nullptr)
		{
			RenderManager::GetInstance().DestroyTexture(mTexture);
			mTexture = nullptr;
		}
	}

	GlyphInfo* ResourceTrueTypeFont::GetGlyphInfo(Char id)
	{
		for (VectorRangeInfo::iterator iter=mVectorRangeInfo.begin(); iter!=mVectorRangeInfo.end(); ++iter)
		{
			GlyphInfo* info = iter->GetInfo(id);
			if (info == nullptr) continue;
			return info;
		}
		return &mSpaceGlyphInfo;
	}

	void ResourceTrueTypeFont::AddGlyph(GlyphInfo * info, Char index, int left, int top, int right, int bottom, int finalw, int finalh, float aspect, int addHeight)
	{
		info->codePoint = index;
		info->uvRect.left = (float)left / (float)finalw;  // u1
		info->uvRect.top = (float)(top + addHeight) / (float)finalh;  // v1
		info->uvRect.right = (float)( right ) / (float)finalw; // u2
		info->uvRect.bottom = ( bottom + addHeight ) / (float)finalh; // v2
		info->width = right - left;
	}

	uint8* ResourceTrueTypeFont::WriteData(uint8* pDest, unsigned char luminance, unsigned char alpha, bool rgba)
	{
		if (rgba)
		{
			*pDest++ = luminance; // curLuminance
			*pDest++ = luminance; // curLuminance
			*pDest++ = luminance; // curLuminance
			*pDest++ = alpha; // curAlpha
		}
		else
		{
			*pDest++ = luminance; // curLuminance
			*pDest++ = alpha; // curAlpha
		}
		return pDest;
	}

	void ResourceTrueTypeFont::Initialise()
	{

#ifndef USE_FREETYPE

		LOG(Error, "ResourceTrueTypeFont '" << GetResourceName() << "' - Ttf font disabled. Define USE_FREETYE if you need ttf fonts.");

#else // USE_FREETYPE

		mTexture = RenderManager::GetInstance().CreateTexture(GUI::utility::ToString((size_t)this, "_TrueTypeFont"));

		// ManualResourceLoader implementation - load the texture
		FT_Library ftLibrary;
		// Init freetype
		if ( FT_Init_FreeType( &ftLibrary ) ) EXCEPT("Could not init FreeType library!");

		// Load font
		FT_Face face;

		//FIXME
		IDataStream* datastream = DataManager::GetInstance().GetData(mSource);
		ASSERT(datastream, "Could not open font face!");

		size_t datasize = datastream->size();
		uint8* data = new uint8[datasize];
		datastream->Read(data, datasize);
		delete datastream;

		if ( FT_New_Memory_Face( ftLibrary, data, (FT_Long)datasize, 0, &face ) )
		{
			EXCEPT("Could not open font face!");
		}

		// Convert our point size to freetype 26.6 fixed point format
		FT_F26Dot6 ftSize = (FT_F26Dot6)(mTtfSize * (1 << 6));
		if ( FT_Set_Char_Size( face, ftSize, 0, mTtfResolution, mTtfResolution ) )
		{
			EXCEPT("Could not set char size!");
		}

		int max_height = 0, max_bear = 0;

		int spec_len = mCursorWidth + mSelectionWidth + mSelectionWidth + mSpaceWidth + mTabWidth + (mDistance * 5);
		int len = mDistance + spec_len;
		int height = 0; 

		size_t finalWidth = MIN_FONT_TEXTURE_WIDTH;
		// trying to guess necessary width for texture
		while (mTtfSize*mTtfResolution > finalWidth*6) finalWidth *= 2;

		for (VectorRangeInfo::iterator iter=mVectorRangeInfo.begin(); iter!=mVectorRangeInfo.end(); ++iter)
		{
			for (Char index=iter->first; index<=iter->last; ++index)
			{

				if (CheckHidePointCode(index)) 
					continue;

				if (FT_Load_Char( face, index, FT_LOAD_RENDER )) 
					continue;

				if (nullptr == face->glyph->bitmap.buffer) 
					continue;

				FT_Int advance = (face->glyph->advance.x >> 6 ) + ( face->glyph->metrics.horiBearingX >> 6 );

				if ( ( 2 * ( face->glyph->bitmap.rows << 6 ) - face->glyph->metrics.horiBearingY ) > max_height )
				{
					max_height = ( 2 * ( face->glyph->bitmap.rows << 6 ) - face->glyph->metrics.horiBearingY );
				}

				if ( face->glyph->metrics.horiBearingY > max_bear )
				{
					max_bear = face->glyph->metrics.horiBearingY;
				}

				len += (advance + mDistance);
				if ( int(finalWidth - 1) < (len + advance + mDistance) ) 
				{ 
					height ++; 
					len = mDistance;
				}
			}
		}

		max_height >>= 6;
		max_bear >>= 6;

		size_t finalHeight = (height+1) * (max_height + mDistance) + mDistance;

		//make it more squared
		while (finalHeight > finalWidth)
		{
			finalHeight /= 2;
			finalWidth *= 2;
		}

		size_t needHeight = 1;
		while (needHeight < finalHeight) needHeight <<= 1;
		finalHeight = needHeight;

		float textureAspect = (float)finalWidth / (float)finalHeight;

		// if L8A8 (2 bytes per pixel) not supported use 4 bytes per pixel R8G8B8A8
		// where R == G == B == L
		bool rgbaMode = ! GUI::RenderManager::GetInstance().IsFormatSupported(PixelFormat::L8A8, TextureUsage::Static | TextureUsage::Write);

		const size_t pixel_bytes = rgbaMode ? 4 : 2;
		size_t data_width = finalWidth * pixel_bytes;
		size_t data_size = finalWidth * finalHeight * pixel_bytes;

		LOG(Info, "ResourceTrueTypeFont '" << GetResourceName() << "' using texture size " << finalWidth << " x " << finalHeight);
		LOG(Info, "ResourceTrueTypeFont '" << GetResourceName() << "' using real height " << max_height << " pixels");
		mHeightPix = max_height;

		uint8* imageData = new uint8[data_size];

		uint8* dest = imageData;
		// Reset Content (White, transparent)
		for (size_t i = 0; i < data_size; i += pixel_bytes)
		{
			dest = WriteData(dest, 0xFF, 0x00, rgbaMode);
		}

		len = mDistance;
		height = mDistance; 
		FT_Int advance = 0;

		//------------------------------------------------------------------
		//------------------------------------------------------------------
		advance = mSpaceWidth;

		if ( int(finalWidth - 1) < (len + advance + mDistance) ) { height += max_height + mDistance; len = mDistance; }

		for (int j = 0; j < max_height; j++ )
		{
			int row = j + (int)height;
			uint8* pDest = &imageData[(row * data_width) + len * pixel_bytes];
			for (int k = 0; k < advance; k++ )
			{
				pDest = WriteData(pDest, FONT_MASK_CHAR, FONT_MASK_SPACE, rgbaMode);
			}
		}

		AddGlyph(&mSpaceGlyphInfo, FontCodeType::Space, len, height, len + advance, height + max_height, finalWidth, finalHeight, textureAspect, mOffsetHeight);
		len += (advance + mDistance);

		//------------------------------------------------------------------
		//------------------------------------------------------------------
		advance = mTabWidth;

		if ( int(finalWidth - 1) < (len + advance + mDistance) ) { height += max_height + mDistance; len = mDistance; }

		for (int j = 0; j < max_height; j++ )
		{
			int row = j + (int)height;
			uint8* pDest = &imageData[(row * data_width) + len * pixel_bytes];
			for (int k = 0; k < advance; k++ )
			{
				pDest = WriteData(pDest, FONT_MASK_CHAR, FONT_MASK_SPACE, rgbaMode);
			}
		}

		AddGlyph(&mTabGlyphInfo, FontCodeType::Tab, len, height, len + advance, height + max_height, finalWidth, finalHeight, textureAspect, mOffsetHeight);
		len += (advance + mDistance);

		//------------------------------------------------------------------
		//------------------------------------------------------------------
		advance = mSelectionWidth;
		for (int j = 0; j < max_height; j++ )
		{
			int row = j + (int)height;
			uint8* pDest = &imageData[(row * data_width) + len * pixel_bytes];
			for (int k = 0; k < advance; k++ )
			{
				pDest = WriteData(pDest, FONT_MASK_CHAR, FONT_MASK_SELECT, rgbaMode);
			}
		}

		if ( int(finalWidth - 1) < (len + advance + mDistance) ) { height += max_height + mDistance; len = mDistance; }

		AddGlyph(&mSelectGlyphInfo, FontCodeType::Selected, len, height, len + advance, height + max_height, finalWidth, finalHeight, textureAspect, mOffsetHeight);
		len += (advance + mDistance);

		//------------------------------------------------------------------
		//------------------------------------------------------------------
		advance = mSelectionWidth;

		if ( int(finalWidth - 1) < (len + advance + mDistance) ) { height += max_height + mDistance; len = mDistance; }

		for (int j = 0; j < max_height; j++ )
		{
			int row = j + (int)height;
			uint8* pDest = &imageData[(row * data_width) + len * pixel_bytes];
			for (int k = 0; k < advance; k++ )
			{
				pDest = WriteData(pDest, FONT_MASK_CHAR, FONT_MASK_SELECT_DEACTIVE, rgbaMode);
			}
		}

		AddGlyph(&mSelectDeactiveGlyphInfo, FontCodeType::SelectedBack, len, height, len + advance, height + max_height, finalWidth, finalHeight, textureAspect, mOffsetHeight);
		len += (advance + mDistance);

		//------------------------------------------------------------------
		//------------------------------------------------------------------
		advance = mCursorWidth;

		if ( int(finalWidth - 1) < (len + advance + mDistance) ) { height += max_height + mDistance; len = mDistance; }

		for (int j = 0; j < max_height; j++ )
		{
			int row = j + (int)height;
			uint8* pDest = &imageData[(row * data_width) + len * pixel_bytes];
			for (int k = 0; k < advance; k++ )
			{
				pDest = WriteData(pDest, (k&1) ? 0 : 0xFF, FONT_MASK_CHAR, rgbaMode);
			}
		}

		AddGlyph(&mCursorGlyphInfo, FontCodeType::Cursor, len, height, len + advance, height + max_height, finalWidth, finalHeight, textureAspect, mOffsetHeight);
		len += (advance + mDistance);

		//------------------------------------------------------------------
		//------------------------------------------------------------------
		FT_Error ftResult;
		for (VectorRangeInfo::iterator iter=mVectorRangeInfo.begin(); iter!=mVectorRangeInfo.end(); ++iter)
		{
			size_t pos = 0;
			for (Char index=iter->first; index<=iter->last; ++index, ++pos)
			{
				if (CheckHidePointCode(index)) continue;

				GlyphInfo& info = iter->range.at(pos);

				ftResult = FT_Load_Char( face, index, FT_LOAD_RENDER );
				if (ftResult)
				{
					// problem loading this glyph, continue
					LOG(warning, "cannot load character " << index << " in font " << GetResourceName());
					continue;
				}

				FT_Int glyph_advance = (face->glyph->advance.x >> 6 );
				unsigned char* buffer = face->glyph->bitmap.buffer;

				if (nullptr == buffer)
				{
					// Yuck, FT didn't detect this but generated a nullptr pointer!
					LOG(warning, "Freetype returned nullptr for character " << index << " in font " << GetResourceName());
					continue;
				}

				int y_bearnig = max_bear - ( face->glyph->metrics.horiBearingY >> 6 );

				if ( int(finalWidth - 1) < (len + face->glyph->bitmap.width + mDistance) ) { height += max_height + mDistance; len = mDistance; }

				for (int j = 0; j < face->glyph->bitmap.rows; j++ )
				{
					int row = j + (int)height + y_bearnig;
					uint8* pDest = &imageData[(row * data_width) + (len + ( face->glyph->metrics.horiBearingX >> 6 )) * pixel_bytes];
					for (int k = 0; k < face->glyph->bitmap.width; k++ )
					{
						if (mAntialiasColour) pDest = WriteData(pDest, *buffer, *buffer, rgbaMode);
						else pDest = WriteData(pDest, FONT_MASK_CHAR, *buffer, rgbaMode);
						buffer++;
					}
				}

				AddGlyph(&info, index, len, height, len + glyph_advance, height + max_height, finalWidth, finalHeight, textureAspect, mOffsetHeight);
				len += (glyph_advance + mDistance);

			}
		}

		RangeInfo info(FontCodeType::Selected, FontCodeType::Tab);
		info.SetInfo(FontCodeType::Selected, &mSelectGlyphInfo);
		info.SetInfo(FontCodeType::SelectedBack, &mSelectDeactiveGlyphInfo);
		info.SetInfo(FontCodeType::Cursor, &mCursorGlyphInfo);
		info.SetInfo(FontCodeType::Tab, &mTabGlyphInfo);

		mVectorRangeInfo.push_back(info);


		mTexture->CreateManual(finalWidth, finalHeight, TextureUsage::Static | TextureUsage::Write, rgbaMode ? PixelFormat::R8G8B8A8 : PixelFormat::L8A8);

		void* buffer_ptr = mTexture->Lock(TextureUsage::Write);
		memcpy(buffer_ptr, imageData, data_size);
		mTexture->Unlock();

		delete [] imageData;
		delete [] data;

		FT_Done_FreeType(ftLibrary);

#endif // USE_FREETYPE

	}

	void ResourceTrueTypeFont::AddCodePointRange(Char first, Char second)
	{
		mVectorRangeInfo.push_back(RangeInfo(first, second));
	}

	void ResourceTrueTypeFont::AddHideCodePointRange(Char first, Char second)
	{
		mVectorHideCodePoint.push_back(PairCodePoint(first, second));
	}

	bool ResourceTrueTypeFont::CheckHidePointCode(Char id)
	{
		for (VectorPairCodePoint::iterator iter=mVectorHideCodePoint.begin(); iter!=mVectorHideCodePoint.end(); ++iter)
		{
			if (iter->IsExist(id)) return true;
		}
		return false;
	}

	void ResourceTrueTypeFont::ClearCodePointRanges()
	{
		mVectorRangeInfo.clear();
		mVectorHideCodePoint.clear();
	}

	void ResourceTrueTypeFont::Deserialization(xml::ElementPtr node, Version version)
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
				else if (key == "Size") mTtfSize = utility::ParseFloat(value);
				else if (key == "Resolution") mTtfResolution = utility::ParseUInt(value);
				else if (key == "Antialias") mAntialiasColour = utility::ParseBool(value);
				else if (key == "SpaceWidth") mSpaceWidth = utility::ParseInt(value);
				else if (key == "TabWidth") mTabWidth = utility::ParseInt(value);
				//else if (key == "CursorWidth") mCursorWidth = utility::ParseInt(value);
				else if (key == "Distance") mDistance = utility::ParseInt(value);
				else if (key == "OffsetHeight") mOffsetHeight = utility::ParseInt(value);
			}
			else if (curNode->GetName() == "Codes")
			{
				xml::ElementEnumerator range = curNode->GetElementEnumerator();
				while (range.Next("Code"))
				{
					std::string range_value;
					std::vector<std::string> parse_range;
					if (range->findAttribute("range", range_value))
					{
						parse_range = utility::Split(range_value);
						if (!parse_range.empty())
						{
							int first = utility::ParseInt(parse_range[0]);
							int last = parse_range.size() > 1 ? utility::ParseInt(parse_range[1]) : first;
							AddCodePointRange(first, last);
						}
					}
					else if (range->findAttribute("hide", range_value))
					{
						parse_range = utility::Split(range_value);
						if (!parse_range.empty())
						{
							int first = utility::ParseInt(parse_range[0]);
							int last = parse_range.size() > 1 ? utility::ParseInt(parse_range[1]) : first;
							AddHideCodePointRange(first, last);
						}
					}
				}
			}
		}

		Initialise();
	}

} // namespace GUI


