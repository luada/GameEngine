--[[Property.lua
用于属性方法声明

Exported API:
	Property(class)

	Property:reader(propertyName)
	Property:writer(propertyName)
	Property:accessor(propertyName)
	Property(object, propertyName, propertyValue)

Example:
	local Object = class()
	local prop = Property(Object)
	prop:reader("id")
	function Object:__init(id)
		self.id = id
	end
--]]

require "base.base"

--------------------------------------------------------------------------------
local ACCESSOR = 1
local WRITER = 2
local READER = 3
--------------------------------------------------------------------------------
local observerMap = define { __mode = "k" }
--------------------------------------------------------------------------------
local classMT = {
	__call = function(prop, obj, name, value)
		obj[name] = value
	end,
	__index = function(prop, obj)
		return obj
	end
}
--------------------------------------------------------------------------------
local function prop_accessor(prop, class, name, default, mode)
	assert(class, "error Class type.")
	assert(name, "error Name attribute.")
	local _name = string.title(name)

	if mode <= WRITER then
		class["set".._name] = function(self, value)
			local old = self[name]
			self[name] = value
			local observer = rawget(observerMap[classof(self)] or prop, "__observer")
			if observer then
				observer(self, name, old, value)
			end
		end
		mode = mode + 2
	end

	if mode <= READER then
		class["get".._name] = function(self)
			local ret = self[name]
			if ret ~= nil then
				return ret
			else
				return default
			end
		end
		if type(default) == "boolean" then
			class["is".._name] = class["get".._name]
		end
	end
end
--------------------------------------------------------------------------------
local function prop_new(_, class, observer)
	assert(class, "error Class type.")

	local prop = define(classMT, {
		__class = class,
		__observer = observer,
		reader = function(self, name, default)
			prop_accessor(self, class, name, default, READER)
		end,
		writer = function(self, name, default)
			prop_accessor(self, class, name, default, WRITER)
		end,
		accessor = function(self, name, default)
			prop_accessor(self, class, name, default, ACCESSOR)
		end
	})

	if observer then
		observerMap[class] = prop
	end

	return prop
end

Property = define { __call = prop_new }
