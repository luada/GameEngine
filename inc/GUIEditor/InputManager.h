#ifndef __DX_INPUT_MANAGER_H__
#define __DX_INPUT_MANAGER_H__

#include <GUI.h>
#include <OIS/OIS.h>

namespace input
{

	class InputManager :
		public OIS::MouseListener,
		public OIS::KeyListener
	{
	public:
		InputManager();
		virtual ~InputManager();

		void CreateInput(size_t handle);
		void DestroyInput();
		void CaptureInput();
		void SetInputViewSize(int width, int height);

		virtual void InjectMouseMove(int absx, int absy, int absz) { }
		virtual void InjectMousePress(int absx, int absy, GUI::MouseButton id) { }
		virtual void InjectMouseRelease(int absx, int absy, GUI::MouseButton id) { }
		virtual void InjectKeyPress(GUI::KeyCode key, GUI::Char text) { }
		virtual void InjectKeyRelease(GUI::KeyCode key) { }

		void SetMousePosition(int x, int y);
		void UpdateCursorPosition();

	private:
		virtual bool mouseMoved(const OIS::MouseEvent& arg);
		virtual bool mousePressed(const OIS::MouseEvent& arg, OIS::MouseButtonID id);
		virtual bool mouseReleased(const OIS::MouseEvent& arg, OIS::MouseButtonID id);
		virtual bool keyPressed(const OIS::KeyEvent& arg);
		virtual bool keyReleased(const OIS::KeyEvent& arg);

		void CheckPosition();

	private:
		OIS::InputManager* mInputManager;
		OIS::Keyboard* mKeyboard;
		OIS::Mouse* mMouse;

		int mCursorX;
		int mCursorY;
	};

} // namespace input

#endif // __DX_INPUT_MANAGER_H__
