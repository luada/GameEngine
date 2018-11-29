#ifndef __RESOURCE_TRUE_TYPE_FONT_H__
#define __RESOURCE_TRUE_TYPE_FONT_H__

#include "Prerequest.h"
#include "ITexture.h"
#include "IFont.h"

namespace GUI
{

	class GUI_EXPORT ResourceTrueTypeFont :
		public IFont
	{
		RTTI_DERIVED(ResourceTrueTypeFont)

	public:
		typedef std::vector<PairCodePoint> VectorPairCodePoint;
		typedef std::vector<RangeInfo> VectorRangeInfo;
		typedef std::vector<PairCodeCoord> VectorPairCodeCoord;

	public:
		ResourceTrueTypeFont();
		virtual ~ResourceTrueTypeFont();

		virtual void Deserialization(xml::ElementPtr node, Version version);

		virtual GlyphInfo* GetGlyphInfo(Char id);

		virtual ITexture* GetTextureFont() { return mTexture; }

		virtual int GetDefaultHeight() { return mHeightPix; }

	private:
		void AddCodePointRange(Char first, Char second);
		void AddHideCodePointRange(Char first, Char second);

		bool CheckHidePointCode(Char id);

		/** Clear the list of code point ranges. */
		void ClearCodePointRanges();

		void Initialise();

		void AddGlyph(GlyphInfo * info, Char index, int left, int top, int right, int bottom, int finalw, int finalh, float aspect, int addHeight = 0);
		// write 2 or 4 bytes into buffer: LA or LLLA if _rgba is true
		uint8* WriteData(uint8* pDest, unsigned char luminance, unsigned char alpha, bool rgba);

	private:
		// Source of the font
		std::string mSource;
		// Size of the truetype font, in points
		float mTtfSize;
		// Resolution (dpi) of truetype font
		uint mTtfResolution;

		bool mAntialiasColour;

		int mDistance;
		int mSpaceWidth;
		int mTabWidth;
		int mCursorWidth;
		int mSelectionWidth;
		int mOffsetHeight;
		int mHeightPix;

		GlyphInfo mSpaceGlyphInfo, mTabGlyphInfo, mSelectGlyphInfo, mSelectDeactiveGlyphInfo, mCursorGlyphInfo;

		VectorPairCodePoint mVectorHideCodePoint;

		VectorRangeInfo mVectorRangeInfo;

		GUI::ITexture* mTexture;

	};

} // namespace GUI

#endif // __RESOURCE_TRUE_TYPE_FONT_H__

