require "base.class"
require "base.scriptObject"

MyObjectBase = class(ScriptObject)

function MyObjectBase:__init()
	print("MyObjectBase:__init")
end


MyObject = class(MyObjectBase)

function MyObject:__init()
	print("MyObject:__init")
end


a = MyObject()




print(a)


AA = class()

function AA:__onEngineObjLost()
	--print("AA:__onEngineObjLost")
	self.engineObj = nil
end

function AA:__onEngineObjAttach(engineObj)
	--print("AA:__onEngineAttach", self.name, type(engineObj))
	self.engineObj = engineObj
end

function AA:onTest1(val, mm)
	print("AA:onTest1", val, mm)
end

function AA.New()
	local a = AA()
	return a
end

function AA:__init()
	print("AA:__init")
end

function AA:mm()
	print("AA:mm", self.name)
end

function AA:CreateEngineObj()
	self.engineObj = T.A()
	self.engineObj:ScriptObjID(NewRegistryRef(self))
	self.engineObj:SetScriptClass("AA")
	self.engineObj:TestFn(123456789)
end

function AutoWrapEngine(scriptClass, engineClass)
	for k, v in pairs(engineClass) do
		if k ~= "__index" and k ~= "__newindex" and k ~= "new" and k ~= "new_local" and
			k ~= ".call" and k ~= "__call" and k ~= ".collector" and k ~= "__gc" and type(v) == "function" then
			strFunc = string.format("function %s:%s(...) return self.engineObj:%s(...) end", scriptClass, k, k)
			DoBuffer(strFunc)
		end
	end
end


AutoWrapEngine("AA", T.A)


---a = AA()

---a:CreateEngineObj()




--[[require "base.class"

a = {}
a.peer = NewRegistryRef(a)
ReleaseRegistryRef(a.peer)

ScriptObject = class()

function ScriptObject:__init()
	print('ScriptObject:__init')
	self.id = "hello world"
	self.mm = 987654321
	self.peer = self:createPeer()
	self.peer:SetPeer(NewRegistryRef(self))
end

function ScriptObject:createPeer()
	local peer = A()
	return peer
end

function ScriptObject:TestFn()
	self.peer:TestFn(3333888)
end

function ScriptObject:onTest(a)
	print("ScriptObject:onTest: ", a)
end

function ScriptObject:onTest1(a)
	print(self.id, a)
	return self.mm
end

function ScriptObject:__release()
end

print("obj = ScriptObj()")
local obj = ScriptObject()

obj:TestFn()

obj.id = 987654321

obj:TestFn()
]]

