--[[EventSetListener.lua
����ض��¼����ϼ������ӿ�

Exported API:
	eventsID = EventSetListener.getEventsID() �����¼���������ϢID�б�
	count = EventSetListener.getEventsCount() �����¼���������Ϣ����

Example:

--]]

require "event.ActionListener"

EventSetListener = interface(ActionListener, "getEventsID", "getEventsCount")