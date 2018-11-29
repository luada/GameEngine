--[[ClassEventListener.lua
类事件监听器接口

Exported API:
	class = ClassEventListener.getEventClass() 返回事件监听的类

Example:

--]]

require "event.ActionListener"

ClassEventListener = interface(ActionListener, "getEventClass")