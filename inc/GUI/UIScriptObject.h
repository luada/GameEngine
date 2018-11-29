#ifndef __UI_SCRIPT_OBJECT_H__
#define __UI_SCRIPT_OBJECT_H__

#include "WidgetEvent.h"
#include "script/ScriptUnit.h"
#include "common/Macro.h"

namespace GUI
{
	class GUI_EXPORT UIScriptObject: 
		public CScriptObject,
		public WidgetEvent
	{
		friend class InputManager;
	public:
		virtual ~UIScriptObject() {}
		UIScriptObject(){}

		//@ExportToLua
		bool IsScriptObjValid(){ return CScriptObject::IsScriptObjValid(); }

		//@ExportToLua
		int  GetScriptObjID() const {  return CScriptObject::GetScriptObjID(); }

		//@ExportToLua
		void SetScriptObjID(int objID) { CScriptObject::SetScriptObjID(objID); }

		//@ExportToLua
		bool CreateScriptObj(std::string scriptClass) { return CScriptObject::CreateScriptObj(scriptClass); }

		//@ExportToLua
		void SetScriptClass(std::string scriptClass) { CScriptObject::SetScriptClass(scriptClass); }

		//@ExportToLua
		const std::string& GetScriptClass() { return CScriptObject::GetScriptClass(); }

	protected:
		virtual void OnMouseLostFocus(Widget* _new);
		virtual void OnMouseSetFocus(Widget* old);
		virtual void OnMouseDrag(int left, int top);
		virtual void OnMouseMove(int left, int top);
		virtual void OnMouseWheel(int rel);
		virtual void OnMouseButtonPressed(int left, int top, MouseButton id);
		virtual void OnMouseButtonReleased(int left, int top, MouseButton id);
		virtual void OnMouseButtonClick();
		virtual void OnMouseButtonDoubleClick();

		virtual void OnKeyLostFocus(Widget* _new);
		virtual void OnKeySetFocus(Widget* old);
		virtual void OnKeyButtonPressed(KeyCode key, Char _char);
		virtual void OnKeyButtonReleased(KeyCode key);

		virtual void OnMouseChangeRootFocus(bool focus);
		virtual void OnKeyChangeRootFocus(bool focus);
	};
} //namespace GUI

#endif //__UI_SCRIPT_OBJECT_H__