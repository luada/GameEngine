--[[ObjectEventListener.lua
����ʵ���¼��������ӿ�

Exported API:
	object = ObjectEventListener.getEventObject() �����¼������Ķ���

Example:

--]]

require "event.ActionListener"

ObjectEventListener = interface(ActionListener, "getEventObject")