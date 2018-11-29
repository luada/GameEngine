#ifndef __RESOURCE_MANUAL_FONT_H__
#define __RESOURCE_MANUAL_FONT_H__

#include "Prerequest.h"
#include "ITexture.h"
#include "IFont.h"

namespace GUI
{

	class GUI_EXPORT ResourceManualFont :
		public IFont
	{
		RTTI_DERIVED(ResourceManualFont)

	private:
		typedef std::vector<RangeInfo> VectorRangeInfo;
		typedef std::vector<PairCodeCoord> VectorPairCodeCoord;

	public:
		ResourceManualFont();
		virtual ~ResourceManualFont();

		virtual void Deserialization(xml::ElementPtr node, Version version);

		virtual GlyphInfo* GetGlyphInfo(Char id);

		virtual ITexture* GetTextureFont() { return mTexture; }

		virtual int GetDefaultHeight() { return mDefaultHeight; }

	private:
		void AddGlyph(Char index, const IntCoord& coord);

		void Initialise();

		void AddGlyph(GlyphInfo * info, Char index, int left, int top, int right, int bottom, int finalw, int finalh, float aspect, int addHeight = 0);

		void AddRange(VectorPairCodeCoord& info, size_t first, size_t last, int width, int height, float aspect);
		void CheckTexture();

	private:
		std::string mSource;
		int mDefaultHeight;

		GlyphInfo mSpaceGlyphInfo;

		VectorPairCodeCoord mVectorPairCodeCoord;

		VectorRangeInfo mVectorRangeInfo;

		GUI::ITexture* mTexture;
	};

} // namespace GUI

#endif // __RESOURCE_MANUAL_FONT_H__

