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
	根据组件的名字获取相应子组件的脚本对象，并强制转换为dynamicCast类
	注意：不填写参数“dynamicCast”默认为最底层派生类；类型转换失败时，返回NULL
	可变参数列表： childWidgetName，dynamicCast
	@param	childWidgetName: 子组件名字
	@type	childWidgetName: string
	@param	dynamicCast: 强制转换的类名
	@type	dynamicCast: string
	--]]
	local engineObj = ObjectDynamicCast(self:FindWidget(...))
	local childID = engineObj:GetScriptObjID()
	local scriptObj = GetRegistryObj(childID)
	return scriptObj 
end

function UI.UIObject:OnMouseLostFocus(newUIObj)
	--[[
	@param	newUIObj: 当前捕获鼠标焦点的对象
	@type	newUIObj: UI.UIObject
	--]]
end

function UI.UIObject:OnMouseSetFocus(oldUIObj)
	--[[
	@param	oldUIObj: 将要失去鼠标焦点的对象
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
	@param	newUIObj: 将要获得光标焦点的对象
	@type	newUIObj: UI.UIObject
	--]]
end

function UI.UIObject:OnKeySetFocus(oldUIObj)
	--[[
	@param	oldUIObj: 将要失去光标焦点的对象
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