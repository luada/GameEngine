--[[prototype.lua
提供基于原型/模板数据操作机制

--]]

require "base.base"

--------------------------------------------------------------------------------
local ACCESSOR = 1
local WRITER = 2
local READER = 3
--------------------------------------------------------------------------------
local classMT = {}
--------------------------------------------------------------------------------
local function prototype_accessor(prototype, class, name, default, mode)
	assert(class, "error Class type.")
	assert(name, "error Name attribute.")
	local _name = string.title(name)

	local prop = rawget(prototype, "__prop")
	local method = rawget(prototype, "__method")

	if mode <= WRITER then
		prop:writer(name, default)
		mode = mode + 2
	end

	if mode <= READER then
		class["get".._name] = function(self)
			local this = prop[self]
			local ret = this[name]

			if not ret then
				local object = method(self)
				if object then
					if type(object["get".._name]) == "function" then
						ret = object["get".._name](object, self)
					else
						ret = object:__getValue(name, self, default)
					end
				end
			end

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
local function prototype_new(_, class, prop, method)
	assert(class, "error Class type.")

	local prototype = define(classMT, {
		__prop = prop,
		__method = method,
		reader = function(self, name, default)
			prototype_accessor(self, class, name, default, READER)
		end,
		writer = function(self, name, default)
			prototype_accessor(self, class, name, default, WRITER)
		end,
		accessor = function(self, name, default)
			prototype_accessor(self, class, name, default, ACCESSOR)
		end
	})

	return prototype
end
--------------------------------------------------------------------------------
Prototype = define { __call = prototype_new }
