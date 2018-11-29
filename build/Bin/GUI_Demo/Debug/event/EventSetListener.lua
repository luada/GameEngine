--[[EventSetListener.lua
多个特定事件集合监听器接口

Exported API:
	eventsID = EventSetListener.getEventsID() 返回事件监听的消息ID列表
	count = EventSetListener.getEventsCount() 返回事件监听的消息个数

Example:

--]]

require "event.ActionListener"

EventSetListener = interface(ActionListener, "getEventsID", "getEventsCount")