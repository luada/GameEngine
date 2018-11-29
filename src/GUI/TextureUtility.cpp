#include "Precompiled.h"
#include "TextureUtility.h"
#include "RenderManager.h"
#include "DataManager.h"
#include "Bitwise.h"

namespace GUI
{

	namespace texture_utility
	{

		const IntSize& GetTextureSize(const std::string& texture, bool cache)
		{
			static std::string old_texture;
			static IntSize old_size;

			if (old_texture == texture && cache)
				return old_size;
			old_texture = texture;
			old_size.Clear();

			if (texture.empty())
				return old_size;

			RenderManager& render = RenderManager::GetInstance();

			if (nullptr == render.GetTexture(texture))
			{
				if (!DataManager::GetInstance().IsDataExist(texture))
				{
					LOG(Error, "Texture '" + texture + "' not found");
					return old_size;
				}
				else
				{
					ITexture* curTexture = render.CreateTexture(texture);
					curTexture->LoadFromFile(texture);
				}
			}

			ITexture* curTexture = render.GetTexture(texture);
			if (curTexture == nullptr)
			{
				LOG(Error, "Texture '" + texture + "' not found");
				return old_size;
			}

			old_size.Set(curTexture->GetWidth(), curTexture->GetHeight());

	#if DEBUG_MODE == 1
			if (!Bitwise::IsPO2(old_size.width) || !Bitwise::IsPO2(old_size.height))
			{
				LOG(warning, "Texture '" + texture + "' have non power of two size");
			}
	#endif

			return old_size;
		}

		uint32 ToColourARGB(const Colour& colour)
		{
			uint32 val32 = uint8(colour.alpha * 255);
			val32 <<= 8;
			val32 += uint8(colour.red * 255);
			val32 <<= 8;
			val32 += uint8(colour.green * 255);
			val32 <<= 8;
			val32 += uint8(colour.blue * 255);
			return val32;
		}

	} // namespace texture_utility

} // namespace GUI

