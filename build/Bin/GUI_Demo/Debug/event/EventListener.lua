--[[EventListener.lua
�ض��¼��������ӿ�

Exported API:
	eventID = EventListener.getEventID() �����¼���������ϢID

Example:

--]]

require "event.ActionListener"

EventListener = interface(ActionListener, "getEventID")