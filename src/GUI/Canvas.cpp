#include "Precompiled.h"
#include "Canvas.h"
#include "ResourceManager.h"
#include "Gui.h"
#include "RenderManager.h"
#include "Bitwise.h"

namespace GUI
{

	Canvas::Canvas() :
		mTexture(nullptr),
		mTexResizeMode(TRM_PT_CONST_SIZE),
		mTexData(0),
		mTexManaged(true),
		mFrameAdvise(false)
	{
		mGenTexName = utility::ToString( this, "_Canvas" );
	}

	void Canvas::_initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name)
	{
		Base::_initialise(style, coord, align, info, parent, croppedParent, creator, name);
	}

	Canvas::~Canvas()
	{
		_destroyTexture( false );
	}

	void Canvas::CreateTexture(TextureResizeMode resizeMode, TextureUsage usage, PixelFormat format)
	{
		CreateTexture( GetSize(), resizeMode, usage, format );
	}

	void Canvas::CreateTexture(const IntSize& size, TextureResizeMode resizeMode, TextureUsage usage, PixelFormat format)
	{
		if ( size.width <= 0 || size.height <= 0 )
		{
			ASSERT( 0, "At least one of dimensions isn't positive!" );
			return;
		}

		CreateTexture( size.width, size.height, resizeMode, usage, format );
	}

	void Canvas::CreateExactTexture(int width, int height, TextureUsage usage, PixelFormat format)
	{
		ASSERT( width >= 0 && height >= 0, "negative size" );

		DestroyTexture();

		mTexture = RenderManager::GetInstance().CreateTexture(mGenTexName);
		mTexture->SetInvalidateListener(this);
		mTexture->CreateManual( width, height, usage, format );

		mTexManaged = true;

		_setTextureName( mGenTexName );
		CorrectUV();
		requestUpdateCanvas( this, Event( true, true, false ) );
	}

	void Canvas::resize(const IntSize& size)
	{
		if ( size.width <= 0 || size.height <= 0 || ! mTexManaged )
			return;

		mReqTexSize = size;

		FrameAdvise( true );
	}

	void Canvas::CreateTexture(int width, int height, TextureResizeMode resizeMode, TextureUsage usage, PixelFormat format)
	{
		ASSERT( width >= 0 && height >= 0, "negative size" );

		if ( mReqTexSize.Empty() )
			mReqTexSize = IntSize( width, height );

		mTexResizeMode = resizeMode;

		bool create = CheckCreate( width, height );

		width = Bitwise::FirstPO2From(width);
		height = Bitwise::FirstPO2From(height);

		if ( create )
			CreateExactTexture( width, height, usage, format );
	}

	void Canvas::SetSize(const IntSize& size)
	{
		resize( size );

		Base::SetSize( size );
	}

	void Canvas::SetCoord(const IntCoord& coord)
	{
		resize( coord.Size() );

		Base::SetCoord( coord );
	}

	void Canvas::UpdateTexture()
	{
		requestUpdateCanvas( this, Event( false, false, true ) );
	}

	bool Canvas::CheckCreate(int width, int height) const
	{
		if (mTexture == nullptr)
			return true;

		if (mTexture->GetWidth() >= width && mTexture->GetHeight() >= height)
			return false;

		return true;
	}

	void Canvas::Validate(int& width, int& height, TextureUsage& usage, PixelFormat& format) const
	{
		width = Bitwise::FirstPO2From(width);
		height = Bitwise::FirstPO2From(height);

		// restore usage and format
		if (mTexture != nullptr)
		{
			if ( usage == GetDefaultTextureUsage() )
				usage = mTexture->GetUsage();

			if ( format == GetDefaultTextureFormat() )
				format = mTexture->GetFormat();
		}
	}

	void Canvas::DestroyTexture()
	{
		_destroyTexture( true );
	}

	void Canvas::_destroyTexture(bool sendEvent)
	{
		if ( mTexture != nullptr )
		{
			if ( sendEvent )
			{
				eventPreTextureChanges( this );
			}

			RenderManager::GetInstance().DestroyTexture( mTexture );
			mTexture = nullptr;
		}

	}

	void Canvas::CorrectUV()
	{
		if ( mTexResizeMode == TRM_PT_VIEW_REQUESTED )
		{
			_setUVSet( FloatRect( 0, 0,
				(float) mReqTexSize.width  / (float) GetTextureRealWidth(),
				(float) mReqTexSize.height / (float) GetTextureRealHeight()
				) );
		}

		if ( mTexResizeMode == TRM_PT_CONST_SIZE || mTexResizeMode == TRM_PT_VIEW_ALL )
		{
			_setUVSet( FloatRect( 0, 0, 1, 1 ) );
		}
	}

	void* Canvas::Lock(TextureUsage usage)
	{
		void* data = mTexture->Lock(usage);

		mTexData = reinterpret_cast< uint8* >( data );

		return data;
	}

	void Canvas::Unlock()
	{
		mTexture->Unlock();
	}

	void Canvas::BaseChangeWidgetSkin(ResourceSkin* info)
	{
		Base::BaseChangeWidgetSkin( info );
	}

	void Canvas::InitialiseWidgetSkin(ResourceSkin* info)
	{
	}

	void Canvas::ShutdownWidgetSkin()
	{
	}

	bool Canvas::IsTextureSrcSize() const
	{
		return GetTextureSrcSize() == GetTextureRealSize();
	}

	void Canvas::FrameAdvise(bool advise)
	{
		if ( advise )
		{
			if ( ! mFrameAdvise )
			{
				GUI::Gui::GetInstance().eventFrameStart += GUI::NewDelegate( this, &Canvas::FrameEntered );
				mFrameAdvise = true;
			}
		}
		else
		{
			if ( mFrameAdvise )
			{
				GUI::Gui::GetInstance().eventFrameStart -= GUI::NewDelegate( this, &Canvas::FrameEntered );
				mFrameAdvise = false;
			}
		}
	}

	void Canvas::FrameEntered(float time)
	{
		int width = mReqTexSize.width;
		int height = mReqTexSize.height;
		TextureUsage usage = GetDefaultTextureUsage();
		PixelFormat format = GetDefaultTextureFormat();

		Validate( width, height, usage, format );

		bool create = CheckCreate( width, height );

		if ( mTexResizeMode == TRM_PT_CONST_SIZE )
			create = false;

		if ( create )
		{
			CreateExactTexture( width, height, usage, format );
			CorrectUV();
		}
		else // I thought order is important
		{
			CorrectUV();
			requestUpdateCanvas( this, Event( false, true, false ) );
		}

		FrameAdvise( false );
	}

	void Canvas::TextureInvalidate(ITexture* texture)
	{
		UpdateTexture();
	}

} // namespace GUI
