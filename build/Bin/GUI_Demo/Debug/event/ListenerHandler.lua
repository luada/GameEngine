--[[ListenerHandler.lua
一个简单的监听器处理器
--]]

require "base.class"

ListenerHandler = class()

function ListenerHandler:__init()
	self.listeners = {}
	setmetatable(self.listeners, {__mode = "k"})
end

function ListenerHandler:__release()
	table.clear(self.listeners)
	self.listeners = nil
end

function ListenerHandler:tostring()
	local sb = StringBuffer("ListenerHandler: {count=")
	sb = sb .. table.size(self.listeners) .. ", listener={"
	for k, v in pairs(self.listeners or {}) do
		sb = sb .. toString(k) .. ", "
	end
	sb = sb .. "}}"
	return tostring(sb)
end

--增加事件监听器
function ListenerHandler:addListener(listener)
	self.listeners[listener] = true
end

--删除事件监听器
function ListenerHandler:removeListener(listener)
	self.listeners[listener] = nil
end

--判断监听器是否注册
function ListenerHandler:hasListener(listener)
	return (self.listeners[listener] == true)
end

--通知监听器
function ListenerHandler:notifyListener(eventType, ...)
	for listener, _ in pairs(self.listeners or {}) do
		if type(listener[eventType]) == "function" then
			safeCall(listener[eventType], listener, unpack(arg))
		end
	end
end

--收集方式通知监听器
function ListenerHandler:collectNotifyListener(eventType, ...)
	local result = false

	for listener, _ in pairs(self.listeners or {}) do
		if type(listener[eventType]) == "function" then
			local status, ret = safeCall(listener[eventType], listener, unpack(arg))
			if status then
				result = result or ret
			end
		end
	end

	return result
end
