require "base.class"

--------------------------------------------------------------------------------

Event = class()

function Event:__init()
	self._handlers = {}
	setmetatable(self._handlers, {__mode = "v"})
end

function Event:__release()
	self:clearHandlers()
end

function Event:fire(eventKey, ...)
	--[[
	触发本组事件
	@param	eventKey: 事件名字
	@type	eventKey: string
	@param	arg: 监听函数的参数列表
	@type	arg: 根据实际的监听函数而定
	--]]
	for _, v in ipairs(self._handlers) do
		v:onEvent(eventKey, ...)
	end
end

function Event:addHandler(handler)
	--[[
	判断此组事件中是否handler监听对象
	@param	handler: 响应事件的对象
	@type	handler: object of ScriptObject
	--]]
	table.insert(self._handlers, handler)
end

function Event:removeHandler(handler)
	--[[
	将handler对象从本组事件中删除
	@param	handler: 响应事件的监听对象
	@type	handler: object of ScriptObject
	--]]
	table.removeValue(self._handlers, handler)
end

function Event:clearHandlers()
	--[[
	清空本组事件的所有监听对象
	--]]
	table.clear(self._handlers)
	self._handlers = nil
end

function Event:hasHandlers()
	--[[
	判断本组事件中是否存在监听对象
	--]]
	return self._handlers ~= nil and table.getn(self._handlers) > 0
end

--------------------------------------------------------------------------------

ECenter = {}
ECenter.events = {}

function ECenter.registerEvent(eventKey, handler)
	--[[
	注册一个事件
	@param  eventKey: 事件名字
	@type	eventKey: string
	@param	handler: 响应事件的监听对象
	@type	handler: object of ScriptObject
	--]]
	local event = ECenter.events[eventKey]
	if event == nil then
		event = Event()
		ECenter.events[eventKey] = event
	end
	event:addHandler(handler)
end

function ECenter.deregisterEvent(eventKey, handler)
	--[[
	注销一个事件
	@param  eventKey: 事件名字
	@type	eventKey: string
	@param	handler: 响应事件的监听对象
	@type	handler: object of ScriptObject
	--]]
	local event = ECenter.events[eventKey]
	if event ~= nil then
		event:removeHandler(handler)
		if not event:hasHandlers() then
			release(event)
			ECenter.events[eventKey] = nil
		end
	end
end

function ECenter.fireEvent(eventKey, ...)
	--[[
	触发一组事件
	@param	eventKey: 事件名字
	@type	eventKey: string
	@param	arg: 触发函数的参数列表
	@type	arg: 根据实际的触发函数而定
	--]]
	local event = ECenter.events[eventKey]
	if event ~= nil then
		event:fire(eventKey, ...)
	end
end

--------------------------------------------------------------------------------