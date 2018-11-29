--[[EventManager.lua
�ṩ��Ϣ������ע�����,��Ϣ�ķַ�

Exported API:
	EventManager.getInstance()

	eventMgr:addEventListener(listener)
	eventMgr:removeEventListener(listener)
	eventMgr:hasEventListener(eventID)
	eventMgr:hasObjectListener(object)
	eventMgr:hasClassListener(class)
	eventMgr:hasGroupEventListener(group)
	eventMgr:fireEvent(event)

Example:

--]]

require "base.class"
require "event.EventListener"
require "event.EventSetListener"
require "event.GroupEventListener"
require "event.ClassEventListener"
require "event.ObjectEventListener"
require "event.RemoteEventProxy"

local logger = Logger.getLogger()

EventManager = class(nil, Singleton)

function EventManager:__init()
	self.groupListeners = {}
	self.classListeners = {}
	self.objectListeners = {}
	self.eventListeners = {}
end

--------------------------------------------------------------------------------
--��õ�����EventManagerʵ��
function EventManager.getInstance()
	return EventManager()
end

gEventMgr = EventManager.getInstance()

--------------------------------------------------------------------------------
--ע�����
--	listener     ��������
--
--listener����������������ʵ��
--    EventListener          ���ڼ���ĳ��������¼�����
--    ObjectEventListener    ���ڼ���ĳ��ʵ��������¼�
--    ClassEventListener     ���ڼ���ĳ���������ʵ�����¼�
--    GroupEventListener     ���ڼ���ĳ�����������¼�
function EventManager:addEventListener(listener)
	logger:info("EventManager:addEventListener()")

	if not instanceof(listener, ActionListener) then
		logger:warn("error ActionListener interface type " .. tostring(listener))
		return false
	end

	if instanceof(listener, EventListener) then
		local id = listener:getEventID()
		assert(id, "EventID attribute of EventListener object can't be null.")
		if not self.eventListeners[id] then self.eventListeners[id] = {} end
		table.insert(self.eventListeners[id], listener)
		logger:debug("add EventListener " .. tostring(id))
	end

	if instanceof(listener, EventSetListener) then
		local ids = listener:getEventsID()
		local count = listener:getEventsCount()
		assert(ids, "EventSetID attribute of EventSetListener object can't be null.")
		assert(count > 0, "EventsCount attribute of EventSetListener object must greater than zero.")
		for i, id in pairs(ids) do
			if not self.eventListeners[id] then self.eventListeners[id] = {} end
			table.insert(self.eventListeners[id], listener)
		end
		logger:debug("add EventSetListener " .. toString(ids))
	end

	if instanceof(listener, ObjectEventListener) then
		local object = listener:getEventObject()
		assert(object, "EventObject attribute of ObjectEventListener object can't be null.")
		if not self.objectListeners[object] then self.objectListeners[object] = {} end
		table.insert(self.objectListeners[object], listener)
		logger:debug("add ObjectEventListener " .. tostring(object))
	end

	if instanceof(listener, ClassEventListener) then
		local class = listener:getEventClass()
		assert(class, "EventClass attribute of ClasssEventListener object can't be null.")
		if not self.classListeners[class] then self.classListeners[class] = {} end
		table.insert(self.classListeners[class], listener)
		logger:debug("add ClassEventListener " .. tostring(class))
	end

	if instanceof(listener, GroupEventListener) then
		local group = listener:getEventGroup()
		assert(group, "EventGroup attribute of GroupEventListener object can't be null.")
		if not self.groupListeners[group] then self.groupListeners[group] = {} end
		table.insert(self.groupListeners[group], listener)
		logger:debug("add GroupEventListener " .. tostring(group))
	end

	return true
end

--------------------------------------------------------------------------------
--�Ƴ�ע��ļ���
--	listener     ��������
function EventManager:removeEventListener(listener)
	logger:info("EventManager:removeEventListener()")

	if not instanceof(listener, ActionListener) then
		logger:warn("error ActionListener interface type " .. tostring(listener))
		return false
	end

	if instanceof(listener, EventListener) then
		local id = listener:getEventID()
		assert(id, "EventID attribute of EventListener object can't be null.")
		table.removeValue(self.eventListeners[id], listener)
		logger:info("remove EventListener " .. tostring(id))
	end

	if instanceof(listener, EventSetListener) then
		local ids = listener:getEventsID()
		local count = listener:getEventsCount()
		assert(ids, "EventSetID attribute of EventSetListener object can't be null.")
		assert(count > 0, "EventsCount attribute of EventSetListener object must greater than zero.")
		for i, id in pairs(ids) do
			table.removeValue(self.eventListeners[id], listener)
		end
		logger:debug("add EventSetListener " .. toString(ids))
	end

	if instanceof(listener, ObjectEventListener) then
		local object = listener:getEventObject()
		assert(object, "EventObject attribute of ObjectEventListener object can't be null.")
		table.removeValue(self.objectListeners[object], listener)
		logger:info("remove ObjectEventListener " .. tostring(object))
	end

	if instanceof(listener, ClassEventListener) then
		local class = listener:getEventClass()
		assert(class, "EventClass attribute of ClasssEventListener object can't be null.")
		table.removeValue(self.classListeners[class], listener)
		logger:info("remove ClasssEventListener " .. tostring(class))
	end

	if instanceof(listener, GroupEventListener) then
		local group = listener:getEventGroup()
		assert(group, "EventGroup attribute of GroupEventListener object can't be null.")
		table.removeValue(self.groupListeners[group], listener)
		logger:info("remove GroupEventListener " .. tostring(group))
	end

	return true
end

--------------------------------------------------------------------------------
--�ж��Ƿ���ָ�����������¼�����
--	group     �¼����
function EventManager:hasGroupEventListener(group)
	return self.groupListeners[group] ~= nil
end

--------------------------------------------------------------------------------
--�ж��Ƿ���ָ������¼�����
--	class     �����
function EventManager:hasClassEventListener(class)
	return self.classListeners[class] ~= nil
end

--------------------------------------------------------------------------------
--�ж��Ƿ���ָ������ʵ�����¼�����
--	object     ����ʵ��
function EventManager:hasObjectEventListener(object)
	return self.objectListeners[object] ~= nil
end

--------------------------------------------------------------------------------
--�ж��Ƿ���ָ���¼����͵��¼�����
--	eventID     �¼�ID
function EventManager:hasEventListener(eventID)
	return self.eventListeners[eventID] ~= nil
end

--------------------------------------------------------------------------------
local function fire(list, event)
	if type(list) == "table" then
		for _, v in pairs(list) do
			try{
				function()
					v:action(event)
				end
			,catch = {
				{RuntimeException,
					function(ex)
						logger:error(string.format("fireEvent() : %s", ex:getMessage()))
					end
				},
			}}
		end
	end
end

--------------------------------------------------------------------------------
--�����¼�
--	event     �¼�����
--
--�¼�������˳��:
--    �����¼�����-->�����¼�����-->���¼�����-->�����¼�����
function EventManager:fireEvent(event, bHold)
--	logger:info("EventManager:fireEvent()")

	assert(instanceof(event, Event), "event must be a Event object.")

	local id = event:getID()
	local group = event:getGroup()
	local source = event:getSource()

	assert(id, "ID attribute of Event object can not be null.")
	assert(group, "Group attribute of Event object can not be null.")
	assert(source, "Source attribute of Event object can not be null.")

	fire(self.eventListeners[id], event)
	fire(self.objectListeners[source], event)

	--�����¼�Դ��,���丸��ļ�����
	local class = classof(source)
	while class do
		fire(self.classListeners[class], event)
		class = superclass(class)
	end

	fire(self.groupListeners[group], event)

	if bHold ~= true then
		release(event)
	end
end

--valueType��ѭTableValueType��������
function EventManager:fireRemoteEvent(event,valueType, bHold)
--	local record=GameRecorder.getInstance()
--	if record:isRecording() then
--		record:record(event)
--	end
	RemoteEventProxy.send(event,valueType)

	if bHold ~= true then
		release(event)
	end
end
