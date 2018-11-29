--[[ObjectEventListener.lua
对象实例事件监听器接口

Exported API:
	object = ObjectEventListener.getEventObject() 返回事件监听的对象

Example:

--]]

require "event.ActionListener"

ObjectEventListener = interface(ActionListener, "getEventObject")