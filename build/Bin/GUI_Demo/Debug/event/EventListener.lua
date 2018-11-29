--[[EventListener.lua
特定事件监听器接口

Exported API:
	eventID = EventListener.getEventID() 返回事件监听的消息ID

Example:

--]]

require "event.ActionListener"

EventListener = interface(ActionListener, "getEventID")