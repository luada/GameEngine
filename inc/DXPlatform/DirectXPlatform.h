#ifndef __DIRECTX_PLATFORM_H__
#define __DIRECTX_PLATFORM_H__

#include "Prerequest.h"
#include "DirectXRenderManager.h"
#include "DirectXDataManager.h"
#include "DirectXTexture.h"
#include "DirectXVertexBuffer.h"
#include "DirectXDiagnostic.h"

namespace GUI
{

	class DirectXPlatform
	{
	public:
		DirectXPlatform() :
			mIsInitialise(false)
		{
			mRenderManager = new DirectXRenderManager();
			mDataManager = new DirectXDataManager();
		}

		~DirectXPlatform()
		{
			assert(!mIsInitialise);
			delete mRenderManager;
			delete mDataManager;
		}

		void Initialise(IDirect3DDevice9 *device, const std::string& logname = PLATFORM_LOG_FILENAME)
		{
			assert(!mIsInitialise);
			mIsInitialise = true;

			LogManager::RegisterSection(PLATFORM_LOG_SECTION, logname);

			mRenderManager->Initialise(device);
			mDataManager->Initialise();
		}

		void Shutdown()
		{
			assert(mIsInitialise);
			mIsInitialise = false;

			mRenderManager->Shutdown();
			mDataManager->Shutdown();

			// last platform log
			LogManager::UnregisterSection(PLATFORM_LOG_SECTION);
		}

		DirectXRenderManager* GetRenderManagerPtr()
		{
			assert(mIsInitialise);
			return mRenderManager;
		}

		DirectXDataManager* GetDataManagerPtr()
		{
			assert(mIsInitialise);
			return mDataManager;
		}

	private:
		bool mIsInitialise;
		DirectXRenderManager* mRenderManager;
		DirectXDataManager* mDataManager;

	};

} // namespace GUI

#endif // __DIRECTX_PLATFORM_H__
