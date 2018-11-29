require "base.interface" 
require "base.class"


--------------------------------------------------------------------------------

IScriptObject = interface(nil, 
			"__onEngineObjLost", 
			"__onEngineObjAttach", 
			"New", 
			"getScriptClass",
			"attachEngineObj")

--------------------------------------------------------------------------------

InvalidScriptID = -2

--------------------------------------------------------------------------------

ScriptObject = class(IScriptObject)

function ScriptObject:__init()
end

function ScriptObject:__release()
end

function ScriptObject:__onEngineObjLost()
	if self.engineObj ~= nil then
		self.engineObj:SetScriptObjID(InvalidScriptID)
		self.engineObj = nil
	end
end

function ScriptObject:__onEngineObjAttach(engineObj)
	--[[
	调用ScriptObject.attachEngineObj或CScriptObject.CreateScriptObj时的回调函数
	@param	engineObj:
	@type	engineObj: CScriptObject
	]]
	self.engineObj = engineObj
end

function ScriptObject.New()
	--[[
	创建对象，该方法需要被子类重载
	]]
	local obj = ScriptObject()
	return obj
end

function ScriptObject:getScriptClass()
	--[[
	获取类的名称，该方法需要被子类重载
	]]
	return "ScriptObject"
end

function ScriptObject:attachEngineObj(engineObj)
	--[[
	@param	engineObj:
	@type	engineObj: CScriptObject
	]]
	if engineObj:IsScriptObjValid() then
		local scriptObjID = engineObj:GetScriptObjID()
		local scriptObj = GetRegistryObj(scriptObjID)
		scriptObj:__onEngineObjLost()
	end
	engineObj:SetScriptObjID(NewRegistryRef(self))
	engineObj:SetScriptClass(getScriptClass())
	self:__onEngineObjAttach(engineObj)
end
--------------------------------------------------------------------------------