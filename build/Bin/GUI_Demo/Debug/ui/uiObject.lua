require "base.scriptObject"

--------------------------------------------------------------------------------

UI = {}

--------------------------------------------------------------------------------

autoImpScriptClassDim("UI.UIObject", "ScriptObject", GUI.Widget)

function UI.UIObject:__init()
end

function UI.UIObject:__onLoaded()
end

function UI.UIObject:__release()
end

function UI.UIObject:findChild(...)
	--[[
	������������ֻ�ȡ��Ӧ������Ľű����󣬲�ǿ��ת��ΪdynamicCast��
	ע�⣺����д������dynamicCast��Ĭ��Ϊ��ײ������ࣻ����ת��ʧ��ʱ������NULL
	�ɱ�����б� childWidgetName��dynamicCast
	@param	childWidgetName: ���������
	@type	childWidgetName: string
	@param	dynamicCast: ǿ��ת��������
	@type	dynamicCast: string
	--]]
	local engineObj = ObjectDynamicCast(self:FindWidget(...))
	local childID = engineObj:GetScriptObjID()
	local scriptObj = GetRegistryObj(childID)
	return scriptObj 
end

function UI.UIObject:OnMouseLostFocus(newUIObj)
	--[[
	@param	newUIObj: ��ǰ������꽹��Ķ���
	@type	newUIObj: UI.UIObject
	--]]
end

function UI.UIObject:OnMouseSetFocus(oldUIObj)
	--[[
	@param	oldUIObj: ��Ҫʧȥ��꽹��Ķ���
	@type	oldUIObj: UI.UIObject
	--]]
end

function UI.UIObject:OnMouseDrag(left, top)
	--[[
	@param	left: 
	@type	left: int
	@param	top: 
	@type	top: int
	--]]
end

function UI.UIObject:OnMouseMove(left, top)
	--[[
	@param	left: 
	@type	left: int
	@param	top: 
	@type	top: int
	--]]
end

function UI.UIObject:OnMouseWheel(rel)
end

function UI.UIObject:OnMouseButtonPressed(left, top, mouseBtnID)
	--[[
	@param	left: 
	@type	left: int
	@param	top: 
	@type	top: int
	@param	mouseBtnID:
	@type	mouseBtnID: GUI.MouseButton
	--]]
end

function UI.UIObject:OnMouseButtonReleased(left, top, mouseBtnID)
	--[[
	@param	left: 
	@type	left: int
	@param	top: 
	@type	top: int
	@param	mouseBtnID:
	@type	mouseBtnID: GUI.MouseButton
	--]]
end

function UI.UIObject:OnMouseButtonClick()
end

function UI.UIObject:OnMouseButtonDoubleClick()
end

function UI.UIObject:OnKeyLostFocus(newUIObj)
	--[[
	@param	newUIObj: ��Ҫ��ù�꽹��Ķ���
	@type	newUIObj: UI.UIObject
	--]]
end

function UI.UIObject:OnKeySetFocus(oldUIObj)
	--[[
	@param	oldUIObj: ��Ҫʧȥ��꽹��Ķ���
	@type	oldUIObj: UI.UIObject
	--]]
end

function UI.UIObject:OnKeyButtonPressed(keyCode, charValue)
	--[[
	@param	keyCode:
	@type	keyCode: GUI.KeyCode
	@param	charValue:
	@type	charValue: Char
	--]]
end

function UI.UIObject:OnKeyButtonReleased(keyCode)
	--[[
	@param	keyCode:
	@type	keyCode: GUI.KeyCode
	--]]
end

function UI.UIObject:OnMouseChangeRootFocus(focus)
	--[[
	@param	focus:
	@type	focus: bool
	--]]
end

function UI.UIObject:OnKeyChangeRootFocus(focus)
	--[[
	@param	focus:
	@type	focus: bool
	--]]
end

--------------------------------------------------------------------------------

autoImpScriptClassDim("UI.Button",		"UI.UIObject",	GUI.Button)
autoImpScriptClassDim("UI.Edit",		"UI.UIObject",	GUI.Edit)
autoImpScriptClassDim("UI.HScroll",		"UI.UIObject",	GUI.HScroll)
autoImpScriptClassDim("UI.ItemBox",		"UI.UIObject",	GUI.ItemBox)
autoImpScriptClassDim("UI.List",		"UI.UIObject",	GUI.List)
autoImpScriptClassDim("UI.ListBox",		"UI.UIObject",	GUI.ListBox)
autoImpScriptClassDim("UI.ListCtrl",	"UI.UIObject",	GUI.ListCtrl)
autoImpScriptClassDim("UI.MenuBar",		"UI.UIObject",	GUI.MenuBar)
autoImpScriptClassDim("UI.MenuCtrl",	"UI.UIObject",	GUI.MenuCtrl)
autoImpScriptClassDim("UI.MenuItem",	"UI.UIObject",	GUI.MenuItem)
autoImpScriptClassDim("UI.Message",		"UI.UIObject",	GUI.Message)
autoImpScriptClassDim("UI.MultiList",	"UI.UIObject",	GUI.MultiList)
autoImpScriptClassDim("UI.PopupMenu",	"UI.UIObject",	GUI.PopupMenu)
autoImpScriptClassDim("UI.Progress",	"UI.UIObject",	GUI.Progress)
autoImpScriptClassDim("UI.ScrollView",	"UI.UIObject",	GUI.ScrollView)
autoImpScriptClassDim("UI.StaticImage",	"UI.UIObject",	GUI.StaticImage)
autoImpScriptClassDim("UI.StaticText",	"UI.UIObject",	GUI.StaticText)
autoImpScriptClassDim("UI.Tab",			"UI.UIObject",	GUI.Tab)
autoImpScriptClassDim("UI.TabItem",		"UI.UIObject",	GUI.TabItem)
autoImpScriptClassDim("UI.VScroll",		"UI.UIObject",	GUI.VScroll)
autoImpScriptClassDim("UI.Window",		"UI.UIObject",	GUI.Window)

--------------------------------------------------------------------------------