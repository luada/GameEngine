--[[GroupEventListener.lua
分组事件监听器接口

Exported API:
	group = GroupEventListener.getEventGroup() 返回事件监听的分组类别

Example:

--]]

require "event.ActionListener"

GroupEventListener = interface(ActionListener, "getEventGroup")