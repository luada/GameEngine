--[[class.lua
提供类的继承机制

Exported API:
	class(super, ...)
	new(class, ...)
	release(object)
	classof(object)
	islass(class)
	instanceof(object, class)
	superclass(class)
	subclassof(class, supe)
	getInterfaces(class)
	isClassInstance(object)

Example:
	local Object = class()
	function Object:__init(id)
		print("object.init", id)
		self.id = id
	end
	function Object:getId()
		return self.id
	end
--]]

require "base.try"
require "base.base"
require "base.interface"
require "base.singleton"
require "base.serialize"
require "base.property"
require "base.prototype"
require "base.string"
require "base.logger"

local logger = Logger.getLogger()
--------------------------------------------------------------------------------
local advance = true
local classMap = define { __mode = "k" }
--------------------------------------------------------------------------------
local function rawnew(class, object, ...)
	if isclass(class.__super) then
		rawnew(class.__super, object, ...)
	end
	if type(class.__init) == "function" then
		class.__init(object, ...)
	end
	return object
end
--------------------------------------------------------------------------------
function new(class, ...)
	if not class.__implemented then
		local interfaces = getInterfaces(class)
		if interfaces then
			advance = false
			local ret, method = implemented(class, unpack(interfaces))
			advance = true
			if not ret then
				error(string.format("The %q not implemented.", method))
			end
		end
		class.__implemented = true
	end
	if table.contains(getInterfaces(class), Singleton) then
		local inst = rawget(class, "__instance")
		if not inst then
			local object = define(class.__vtbl)
			inst = rawnew(class, object, ...)
			rawset(class, "__instance", inst)
		end
		return inst
	else
		local object = define(class.__vtbl)
		return rawnew(class, object, ...)
	end
end
--------------------------------------------------------------------------------
local function rawrelease(class, object)
	if type(class.__release) == "function" then
		class.__release(object)
	end
	if isclass(class.__super) then
		rawrelease(class.__super, object)
	end
end
--------------------------------------------------------------------------------
function release(object)
	local class = classof(object)
	if class then
		rawrelease(class, object)
	end
end
--------------------------------------------------------------------------------
local classMT = {
	__call = new,
	__index = function(class, field)
		local value = class.__vtbl[field]
		if advance and value and not string.startsWith(field, "_") then
			rawset(class, field, value)
		end
		return value
	end,
	__newindex = function(class, field, value)
		class.__vtbl[field] = value
	end,
	__tostring = function(class)
		local members = {}
		local super = class
		local separator = ""
		local ret = StringBuffer("<<class>> = {")
		while super do
			local vtbl = super.__vtbl
			for f,v in pairs(vtbl) do
				if not members[f] and not string.startsWith(f, "_") then
					if type(v) == "string" then
						ret = ret .. separator .. f .. " = " .. string.format("%q", v)
					else
						ret = ret .. separator .. f .. " = " .. tostring(v)
					end
					separator = ", "
				end
				members[f] = true
			end
			super = super.__super
		end
		ret = ret .. "}"
		return tostring(ret)
	end
}
--------------------------------------------------------------------------------
local function object_tostring(object)
	if type(object.tostring) == "function" then
		return object:tostring()
	end

	local separator = ""
	local ret = StringBuffer("<<object>> = {")
	for f,v in pairs(object) do
		if not string.startsWith(f, "_") then
			if type(v) == "string" then
				ret = ret .. separator .. f .. " = " .. string.format("%q", v)
			else
				ret = ret .. separator .. f .. " = " .. tostring(v)
			end
			separator = ", "
		end
	end
	ret = ret .. "}"
	return tostring(ret)
end
--------------------------------------------------------------------------------
function class(super, ...)
	local interfaces = {}
	for i = 1, select("#", ...) do
		local interface = select(i, ...)
		if isInterface(interface) then
			interfaces[#interfaces + 1] = interface
		end
	end

	local vtbl = {
		__tostring = object_tostring,
		release = release,
	}

	vtbl.__index = vtbl

	local class = define(classMT, {
		__super = super,
		__interfaces = #interfaces > 0 and interfaces or nil,
		__vtbl = vtbl,
		__init = false,
		__release = false,
	})

	classMap[vtbl] = class

	if super then
		define({
			__index = class.__super
		}, vtbl)
	end

	return class
end
--------------------------------------------------------------------------------
function isclass(class)
	local mt = getmetatable(class)
	if mt == classMT then return true end
	if classMap[mt] then return true end
	return false
end
--------------------------------------------------------------------------------
function classof(object)
	local mt = getmetatable(object)
	return classMap[mt]
end
--------------------------------------------------------------------------------
function isClassInstance(object)
	return classof(object) ~= nil
end
--------------------------------------------------------------------------------
function getInterfaces(class)
	class = isclass(class) and class or classof(class)
	return class.__interfaces
end
--------------------------------------------------------------------------------
function superclass(class)
	return rawget(class, "__super")
end
--------------------------------------------------------------------------------
function subclassof(class, super)
	while class do
		if class == super then return true end
		class = superclass(class)
	end
	return false
end
--------------------------------------------------------------------------------
function instanceof(object, class)
	if object then
		if isInterfaceInstance(object) then
			return subinterfaceof(object.__interface, class)
		elseif isClassInstance(object) then
			if isclass(class) then
				return subclassof(classof(object), class)
			elseif isInterface(class) then
				local interface = class
				local class = classof(object)
				while class do
					local interfaces = getInterfaces(class) or {}
					for i = 1, #interfaces do
						if subinterfaceof(interfaces[i], interface) then
							return implemented(class, interface)
						end
					end
					class = superclass(class)
				end
			end
		elseif isclass(object) then
			if isclass(class) then
				return subclassof(object, class)
			elseif isInterface(class) then
				return implemented(object, class)
			end
		end
	end
	return false
end
--------------------------------------------------------------------------------
local _toString = toString
function toString(value)
	local sb = StringBuffer()
	if isclass(value) or isInterface(value) or classof(value) then
		sb:append(tostring(value))
	else
		sb:append(_toString(value))
	end
	return tostring(sb)
end

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------
--所有异常的基类
Exception = class()

function Exception:__init(msg, ex)
	self.msg = msg
	self.trace = debug.traceback()
	if instanceof(ex, Exception) then
		self.cause = ex:getCause()
	else
		self.cause = debug.getinfo(4, "Sl")
	end
end

function Exception:getMessage()
	return tostring(self.msg and self.msg or "")
end

function Exception:getCauseMessage()
	local cause = self:getCause()
	if cause then
		return string.format("[%s]:%d ->%s", tostring(cause.short_src), toNumber(cause.currentline, -1), self:getMessage())
	end
	return ""
end

function Exception:getCause()
	return self.cause
end

function Exception:getCause()
	return self.cause
end

function Exception:printStackTrace()
	logger:error("--------------------------------")
	logger:error(self.trace)
	logger:error("--------------------------------")
end

function Exception:tostring()
	return string.format("Exception: %s", self:getCauseMessage())
end

--------------------------------------------------------------------------------
--运行时异常
RuntimeException = class(Exception)

function RuntimeException:__init()
	self.cause = debug.getinfo(5, "Sl")
end

function RuntimeException:tostring()
	return string.format("RuntimeException: %s", self:getCauseMessage())
end

--------------------------------------------------------------------------------
--assert判断条件不成立异常
AssertException = class(RuntimeException)

function RuntimeException:__init()
	self.cause = debug.getinfo(6, "Sl")
end

function AssertException:tostring()
	return string.format("AssertException: %s", self:getCauseMessage())
end