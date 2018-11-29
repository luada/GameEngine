#ifndef __CANVAS_H__
#define __CANVAS_H__

#include "Prerequest.h"
#include "Widget.h"
#include "ITexture.h"

namespace GUI
{

	/**
	 * Widget wrapper over Texture - shows the texture.
	 * Implemented: resizing of Texture (see TextureResizeMode); recovery after lossing device;
	 */
	class GUI_EXPORT Canvas :
		public Widget,
		public ITextureInvalidateListener
	{
		RTTI_DERIVED(Canvas)

	public:
		Canvas();

		struct Event
		{
			Event(bool textureChanged, bool widgetResized, bool requested) :
				textureChanged(textureChanged),
				widgetResized(widgetResized),
				requested(requested)
			{
			}

			bool textureChanged;
			bool widgetResized;

			/// This update was caused by calling UpdateTexture();
			bool requested;
		};

		typedef delegates::CDelegate1<Canvas*> EventInfo_Canvas;
		typedef delegates::CDelegate2<Canvas*, Event> EventInfo_CanvasEvent;

		//FIXME
		/**
			Available resize and view modes of texture
			@remarks PT - Power of Two (size)
		*/
		enum TextureResizeMode
		{
			TRM_PT_CONST_SIZE, /// Texture doesn't resizes and fills all widget space
			TRM_PT_VIEW_REQUESTED, /// You can view all pixels of texture, texture cropped by sizes of widget
			TRM_PT_VIEW_ALL /// Texture resizes and fills all widget space
		};

	public:

		/// Creates texture
		void CreateTexture(TextureResizeMode resizeMode, TextureUsage usage = GetDefaultTextureUsage(), PixelFormat format = GetDefaultTextureFormat());

		/// Creates texture
		void CreateTexture(int width, int height, TextureResizeMode resizeMode, TextureUsage usage = GetDefaultTextureUsage(), PixelFormat format = GetDefaultTextureFormat());

		/// Creates texture
		void CreateTexture(const IntSize& size, TextureResizeMode resizeMode, TextureUsage usage = GetDefaultTextureUsage(), PixelFormat format = GetDefaultTextureFormat());

		/// Destroys texture
		void DestroyTexture();

		/// Call user delegate update and removes old texture if it isn't original.
		void UpdateTexture();

		/// Locks hardware pixel buffer.
		void* Lock(TextureUsage usage = TextureUsage::Write);

		/// Unlocks hardware pixel buffer.
		void Unlock();

		/// Checks lockness of hardware _pixel buffer.
		bool IsLocked() const { return mTexture->IsLocked(); }

		/// Returns real width of texture.
		int GetTextureRealWidth() const { return (int) mTexture->GetWidth(); }

		/// Returns real height of texture.
		int GetTextureRealHeight() const { return (int) mTexture->GetHeight(); }

		/// Returns real _size of texture.
		IntSize GetTextureRealSize() const { return IntSize(GetTextureRealWidth(), GetTextureRealHeight()); }

		/// Returns needed width while creating texture.
		int GetTextureSrcWidth() const { return mReqTexSize.width; }

		/// Returns needed height while creating texture.
		int GetTextureSrcHeight() const { return mReqTexSize.height; }

		/// Returns needed sizes while creating texture.
		IntSize GetTextureSrcSize() const { return mReqTexSize; }

		/// Returns needed sizes while creating texture.
		PixelFormat GetTextureFormat() const { return mTexture->GetFormat(); }

		/// Returns name of the current texture.
		const std::string& GetTextureName() const { return mTexture->GetName(); }

		//! @copydoc Widget::SetSize(const IntSize& value)
		virtual void SetSize(const IntSize& value);
		//! @copydoc Widget::SetCoord(const IntCoord& value)
		virtual void SetCoord(const IntCoord& value);

		/** @copydoc Widget::SetSize(int width, int height) */
		void SetSize(int width, int height) { SetSize(IntSize(width, height)); }
		/** @copydoc Widget::SetCoord(int left, int top, int width, int height) */
		void SetCoord(int left, int top, int width, int height) { SetCoord(IntCoord(left, top, width, height)); }

		/// Returns resize mode
		TextureResizeMode GetResizeMode() const { return mTexResizeMode; }

		/// Sets resize mode of texture \sa TextureResizeMode
		void SetResizeMode(TextureResizeMode set) { mTexResizeMode = set; }

		/// Checks if the texture has the Source (required by user) size, otherwise real texture size are bigger.
		bool IsTextureSrcSize() const;

		/// Returns true if the texture was Created (and exists), otherwise false
		bool IsTextureCreated() const { return mTexture != nullptr; }

		/// Returns true if we own the texture, otherwise false. \sa mManaged
		bool IsTextureManaged() const { return mTexManaged; }

		/// Reurns interface texture.
		ITexture* GetTexture() { return mTexture; }

		/// Sets the texture managed @remarks Be careful with assigning managed status to texture, which wasn't created in Canvas! \sa mManaged
		void SetTextureManaged(bool value) { mTexManaged = value; }

		/// Returns default GUI texture usage
		static TextureUsage GetDefaultTextureUsage() { return TextureUsage::Stream | TextureUsage::Write; }

		/// Returns default GUI texture format
		static PixelFormat GetDefaultTextureFormat() { return PixelFormat::R8G8B8A8; }

	/*event:*/
		/** Event : Notify user texture instance will be changed \sa requestUpdateCanvas\n
			signature : void Method(GUI::Canvas* canvas)\n
			@param _canvas, which will be updated
		 */
		EventInfo_Canvas eventPreTextureChanges;

		/** Event : Texture instance was Changed (May be caused by resizing texture or lossing device). User have to update all references to new instance of texture.\n
			signature : void Method(GUI::Canvas* canvas, GUI::Canvas::Event event)\n
			@param _canvas, which needs to update
			@param _event
		 */
		EventInfo_CanvasEvent requestUpdateCanvas;

	/*internal:*/
		virtual void _initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name);

	protected:
		virtual ~Canvas();

		/// Destroys texture
		void _destroyTexture(bool sendEvent);

		/// Update entered parameters according to current texture resize Mode(size) and Restore (if can) parameters of usage and format from texture
		void Validate(int& width, int& height, TextureUsage& usage, PixelFormat& format) const;

		/// Creates the texture itself
		void CreateExactTexture(int width, int height, TextureUsage usage, PixelFormat format);

		/// Checks if we need to create a texture with such sizes.
		bool CheckCreate(int width, int height) const;

		/// Calls when resize widget
		void resize(const IntSize& size);

		/// Correct texture uv-coordinates
		void CorrectUV();

		//! @copydoc Widget::BaseChangeWidgetSkin(ResourceSkin* info)
		void BaseChangeWidgetSkin(ResourceSkin* info);

		//! @copydoc Widget::InitialiseWidgetSkin(ResourceSkin* info)
		void InitialiseWidgetSkin(ResourceSkin* info);

		//! @copydoc Widget::ShutdownWidgetSkin()
		void ShutdownWidgetSkin();

		/// For updating once per frame.
		void FrameAdvise(bool advise);

		/// For updating once per frame.
		void FrameEntered(float time);

		virtual void TextureInvalidate(ITexture* texture);

	protected:
		/// Current texture
		ITexture* mTexture;

		/// Requested bu user sizes
		IntSize mReqTexSize;

		/// Generated texture name
		std::string mGenTexName;

		/// Texture resize mode \sa TextureResizeMode
		TextureResizeMode mTexResizeMode;

		/// Saved pointer from last calling lock. \sa lock
		uint8* mTexData;

		/// true if we own the Texture (can delete it or replace by another instance), otherwise false
		bool mTexManaged;

		/// For updating once per frame. True state means updating before next frame starts.
		bool mFrameAdvise;

	};

} // namespace GUI

#endif // __CANVAS_H__

