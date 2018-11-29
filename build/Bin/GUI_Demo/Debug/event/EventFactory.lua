--[[EventFactory.lua
用于定义事件和创建Event对象实例

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
--获得单例的EventFactory实例
function EventFactory.getInstance()
	return EventFactory()
end

--------------------------------------------------------------------------------
--获得事件对象
--	id         事件的ID
--	source     事件源对象
--	...        事件的附带参数
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
--定义事件
--	id       事件的ID
--	group    事件的分组类别
--	...      事件的附带参数的名称
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
