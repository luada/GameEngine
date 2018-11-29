--[[EventFactory.lua
���ڶ����¼��ʹ���Event����ʵ��

Exported API:
	EventFactory()
	EventFactory.getInstance()

	eventFactory:getEvent(id, source, ...)
	eventFactory:defineEvent(id, group, ...)

Example:

--]]

require "base.class"
require "event.Event"
require "logger.console"

local logger = Logger.getLogger()

EventFactory = class(nil, Singleton)

function EventFactory:__init()
	self.events = {}
end

--------------------------------------------------------------------------------
--��õ�����EventFactoryʵ��
function EventFactory.getInstance()
	return EventFactory()
end

--------------------------------------------------------------------------------
--����¼�����
--	id         �¼���ID
--	source     �¼�Դ����
--	...        �¼��ĸ�������
function EventFactory:getEvent(id, source, ...)
	assert(id, "ID can't be null.")
	assert(source, "source can't be null.")
	assert(self.events[id], "error EventID " .. tostring(id))

	local def = self.events[id]
	local event = Event(id, def.group, source)
	local len = #(arg)
	for i = 1, len do
		if def[i] then
			event["get"..def[i]] = function() return arg[i] end
		end
	end

	event["getParamCount"] = function() return len end
	event["getParams"] = function() return arg end

	return event
end

--------------------------------------------------------------------------------
--�����¼�
--	id       �¼���ID
--	group    �¼��ķ������
--	...      �¼��ĸ�������������
function EventFactory:defineEvent(id, group, ...)
	--logger:debug("EventFactory:defineEvent(" .. id .. ", " .. group .. ", ...)")
	assert(id, "ID can't be null.")
	assert(group, "group can't be null.")

	local def = { group=group }
	for i = 1, select("#", ...) do
		def[i] = string.title(select(i, ...))
	end

	if self.events[id] then
		logger:warn(string.format("0x%X ID event already defined.", toNumber(id)))
	end

	self.events[id] = def
end
