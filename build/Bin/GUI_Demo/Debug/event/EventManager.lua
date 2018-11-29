--[[EventManager.lua
提供消息监听的注册管理,消息的分发

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
--获得单例的EventManager实例
function EventManager.getInstance()
	return EventManager()
end

gEventMgr = EventManager.getInstance()

--------------------------------------------------------------------------------
--注册监听
--	listener     监听对象
--
--listener对象可以是下面类的实例
--    EventListener          用于监听某个具体的事件类型
--    ObjectEventListener    用于监听某个实例对象的事件
--    ClassEventListener     用于监听某个类的所有实例的事件
--    GroupEventListener     用于监听某个分组类别的事件
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
--移除注册的监听
--	listener     监听对象
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
--判断是否有指定分组类别的事件监听
--	group     事件组别
function EventManager:hasGroupEventListener(group)
	return self.groupListeners[group] ~= nil
end

--------------------------------------------------------------------------------
--判断是否有指定类的事件监听
--	class     类对象
function EventManager:hasClassEventListener(class)
	return self.classListeners[class] ~= nil
end

--------------------------------------------------------------------------------
--判断是否有指定对象实例的事件监听
--	object     对象实例
function EventManager:hasObjectEventListener(object)
	return self.objectListeners[object] ~= nil
end

--------------------------------------------------------------------------------
--判断是否有指定事件类型的事件监听
--	eventID     事件ID
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
--触发事件
--	event     事件对象
--
--事件触发的顺序:
--    具体事件监听-->对象事件监听-->类事件监听-->分组事件监听
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

	--触发事件源类,及其父类的监听器
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

--valueType遵循TableValueType常量定义
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
