require "base.eventCenter"
require "base.class"
require "base.interface"

Object = class()

function Object:__init(name)
	print("Object", name)
	self._name = name
	--self._triggers = {}
	--self._triggers["Test_Event"] = Object.Test_Event
end

function Object:__release()
	ECenter.deregisterEvent("Test_Event", self)
	print("Object:__release")
end

function Object:registerEvent()
	for k, _ in pairs(self.triggers_) do
		ECenter.registerEvent(k, self)
	end
end

function Object:onEvent(eventKey, ...)
	self.triggers_[eventKey](self, ...)
end

function Object:Test_Event(msg)
	print("Object:Test_Event--->", msg, self._name)
end

ECenter.fireEvent("Test_Event", "Hello")

A = class()
function A:__init(...)
	print("A:__init", ...)
end

function A:__release(...)
	print("A:__release", ...)
end

function A:AT()
	print("A:AT")
end

B = class()
function B:__init(...)
	print("B:__init", ...)
end

function B:__release(...)
	print("B:__release", ...)
end

function B:BT()
	print("B:BT")
end

C = class(A)
function C:__init(...)
	print("C:__init", ...)
end

function C:__release(...)
	print("C:__release", ...)
end

function C:CT()
	print("C:CT")
end

function C:AT()
	print("C:AT")
end

D = class(C, B)

function D:__init(...)
	print("D:__init", ...)
end

function D:__release(...)
	print("D:__release", ...)
end

function D:DT()
	print("D:DT")
end


a = {}
a["x"] = 234
print(a.x)

--[[
require "base.file"
f = openFile("F:/LuaTool/build/Bin/GUI_Demo/Debug/mm.txt", "w")
writeFile(f, d)
closeFile(f)
--]]





------------------------------------------------------------------------------------------------------------------------
-- look up for `k' in list of tables 'plist'
--[[
local function search (k, plist)
	print(k)
    for i=1, table.getn(plist) do
       local v = plist[i][k]    -- try 'i'-th superclass
       if v then return v end
    end
end

function createClass (...)
    local c = {}      -- new class
    -- class will search for each method in the list of its
    -- parents (`arg' is the list of parents)
	mt = {__index = function (t, k) print(t) local v = search(k, arg) t[k] = v return v end}
	print("mt = ", mt)
    setmetatable(c, mt)
	-- prepare `c' to be the metatable of its instances
	c.__index = c
	-- define a new constructor for this new class

	function c:new (o)
		o = o or {}
		setmetatable(o, c)
		return o
	end
	-- return new class
	return c
end


Named = {}
function Named:getname ()
    return self.name
end

function Named:setname (n)
    self.name = n
end

--]]







