#include "Precompiled.h"
#include <string>
#include "UIScriptObject.h"
#include "script/ILuaScriptMgr.h"


namespace GUI
{
	void UIScriptObject::OnMouseLostFocus(Widget* _new)
	{
		if (IsScriptObjValid())
		{
			std::string scriptFn = GetScriptClass() + ".OnMouseLostFocus";
			g_ILuaScriptMgr->RunLuaFunction(GetScriptObjID(), scriptFn, "r", _new ? _new->GetScriptObjID() : LUA_REFNIL);
		}
		WidgetEvent::OnMouseLostFocus(_new);
	}

	void UIScriptObject::OnMouseSetFocus(Widget* old)
	{
		if (IsScriptObjValid())
		{
			std::string scriptFn = GetScriptClass() + ".OnMouseSetFocus";
			g_ILuaScriptMgr->RunLuaFunction(GetScriptObjID(), scriptFn, "r", old ? old->GetScriptObjID() : LUA_REFNIL);
		}
		WidgetEvent::OnMouseSetFocus(old);
	}

	void UIScriptObject::OnMouseDrag(int left, int top)
	{
		if (IsScriptObjValid())
		{
			std::string scriptFn = GetScriptClass() + ".OnMouseDrag";
			g_ILuaScriptMgr->RunLuaFunction(GetScriptObjID(), scriptFn, "ii", left, top);
		}
		WidgetEvent::OnMouseDrag(left, top);
	}

	void UIScriptObject::OnMouseMove(int left, int top)
	{
		if (IsScriptObjValid())
		{
			std::string scriptFn = GetScriptClass() + ".OnMouseMove";
			g_ILuaScriptMgr->RunLuaFunction(GetScriptObjID(), scriptFn, "ii", left, top);
		}
		WidgetEvent::OnMouseMove(left, top);
	}

	void UIScriptObject::OnMouseWheel(int rel)
	{
		if (IsScriptObjValid())
		{
			std::string scriptFn = GetScriptClass() + ".OnMouseWheel";
			g_ILuaScriptMgr->RunLuaFunction(GetScriptObjID(), scriptFn, "i", rel);
		}
		WidgetEvent::OnMouseWheel(rel);
	}

	void UIScriptObject::OnMouseButtonPressed(int left, int top, MouseButton id)
	{
		if (IsScriptObjValid())
		{
			std::string scriptFn = GetScriptClass() + ".OnMouseButtonPressed";
			CLuaUserData mouseBtnID(g_ILuaScriptMgr->GetLuaState(), &id, "GUI::MouseButton");
			g_ILuaScriptMgr->RunLuaFunction(GetScriptObjID(), scriptFn, "iir", left, top, int(mouseBtnID));
		}
		WidgetEvent::OnMouseButtonPressed(left, top, id);
	}

	void UIScriptObject::OnMouseButtonReleased(int left, int top, MouseButton id)
	{
		if (IsScriptObjValid())
		{
			std::string scriptFn = GetScriptClass() + ".OnMouseButtonReleased";
			CLuaUserData mouseBtnID(g_ILuaScriptMgr->GetLuaState(), &id, "GUI::MouseButton");
			g_ILuaScriptMgr->RunLuaFunction(GetScriptObjID(), scriptFn, "iir", left, top, int(mouseBtnID));
		}
		WidgetEvent::OnMouseButtonReleased(left, top, id);
	}

	void UIScriptObject::OnMouseButtonClick()
	{
		if (IsScriptObjValid())
		{
			std::string scriptFn = GetScriptClass() + ".OnMouseButtonClick";
			g_ILuaScriptMgr->RunLuaFunction(GetScriptObjID(), scriptFn);
		}
		WidgetEvent::OnMouseButtonClick();
	}

	void UIScriptObject::OnMouseButtonDoubleClick()
	{
		if (IsScriptObjValid())
		{
			std::string scriptFn = GetScriptClass() + ".OnMouseButtonDoubleClick";
			g_ILuaScriptMgr->RunLuaFunction(GetScriptObjID(), scriptFn);
		}
		WidgetEvent::OnMouseButtonDoubleClick();
	}

	void UIScriptObject::OnKeyLostFocus(Widget* _new)
	{
		if (IsScriptObjValid())
		{
			std::string scriptFn = GetScriptClass() + ".OnKeyLostFocus";
			g_ILuaScriptMgr->RunLuaFunction(GetScriptObjID(), scriptFn, "r", _new ? _new->GetScriptObjID() : LUA_REFNIL);
		}
		WidgetEvent::OnKeyLostFocus(_new);
	}

	void UIScriptObject::OnKeySetFocus(Widget* old)
	{
		if (IsScriptObjValid())
		{
			std::string scriptFn = GetScriptClass() + ".OnKeySetFocus";
			g_ILuaScriptMgr->RunLuaFunction(GetScriptObjID(), scriptFn, "r", old ? old->GetScriptObjID() : LUA_REFNIL);
		}
		WidgetEvent::OnKeySetFocus(old);
	}

	void UIScriptObject::OnKeyButtonPressed(KeyCode key, Char _char)
	{
		if (IsScriptObjValid())
		{
			std::string scriptFn = GetScriptClass() + ".OnKeyButtonPressed";
			CLuaUserData keyCode(g_ILuaScriptMgr->GetLuaState(), &key, "GUI::KeyCode");
			Char charValue[2] = {_char, 0};
			g_ILuaScriptMgr->RunLuaFunction(GetScriptObjID(), scriptFn, "rs", int(keyCode), charValue);
		}
		WidgetEvent::OnKeyButtonPressed(key, _char);
	}

	void UIScriptObject::OnKeyButtonReleased(KeyCode key)
	{
		if (IsScriptObjValid())
		{
			std::string scriptFn = GetScriptClass() + ".OnKeyButtonReleased";
			CLuaUserData keyCode(g_ILuaScriptMgr->GetLuaState(), &key, "GUI::KeyCode");
			g_ILuaScriptMgr->RunLuaFunction(GetScriptObjID(), scriptFn, "r", int(keyCode));
		}
		WidgetEvent::OnKeyButtonReleased(key);
	}

	void UIScriptObject::OnMouseChangeRootFocus(bool focus)
	{
		if (IsScriptObjValid())
		{
			std::string scriptFn = GetScriptClass() + ".OnMouseChangeRootFocus";
			g_ILuaScriptMgr->RunLuaFunction(GetScriptObjID(), scriptFn, "b", focus);
		}
		WidgetEvent::OnMouseChangeRootFocus(focus);
	}

	void UIScriptObject::OnKeyChangeRootFocus(bool focus)
	{
		if (IsScriptObjValid())
		{
			std::string scriptFn = GetScriptClass() + ".OnKeyChangeRootFocus";
			g_ILuaScriptMgr->RunLuaFunction(GetScriptObjID(), scriptFn, "b", focus);
		}
		WidgetEvent::OnKeyChangeRootFocus(focus);
	}
}