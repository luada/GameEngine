#include "Precompiled.h"
#include "MaskPickInfo.h"
#include "ResourceManager.h"
#include "RenderManager.h"
#include "DataManager.h"

namespace GUI
{

	bool MaskPickInfo::Load(const std::string& file)
	{
		if (!DataManager::GetInstance().IsDataExist(file))
			return false;

		RenderManager& render = RenderManager::GetInstance();
		ITexture* texture = render.CreateTexture(file);
		texture->LoadFromFile(file);

		uint8 * buffer = (uint8*)texture->Lock(TextureUsage::Read);
		if (buffer == 0)
		{
			render.DestroyTexture(texture);
			return false;
		}

		size_t pixel_size = texture->GetNumElemBytes();

		width = texture->GetWidth();
		height = texture->GetHeight();
		size_t size = width * height;
		data.resize(size);

		size_t pos = 0;
		for (size_t pos_pix=0; pos_pix<size; pos_pix++)
		{
			uint8 white = 0;
			for (size_t in_pix=0; in_pix<pixel_size; in_pix++)
			{
				if (0xFF != buffer[pos])
				{
					white = 1;
				}
				pos++;
			}

			data[pos_pix] = white;
		}

		texture->Unlock();
		render.DestroyTexture(texture);

		return true;
	}

} // namespace GUI
