require "base.interface" 
require "base.class"
require "base.eventCenter"


--------------------------------------------------------------------------------

IScriptObject = interface(nil, 
			"__onEngineObjLost", 
			"__onEngineObjAttach", 
			"__onLoaded",
			"__registerTriggers",
			"__deregisterTriggers",
			"New", 
			"getScriptClass",
			"attachEngineObj",
			"onEvent")

--------------------------------------------------------------------------------

InvalidScriptID = -2

--------------------------------------------------------------------------------

ScriptObject = class(IScriptObject)

function ScriptObject:__init()
	--[[
	��ʼ������ʱ�Ļص�����
	--]]
	self.triggers_ = {}
end

function ScriptObject:__onLoaded()
	--[[
	��������������ݺ�Ļص�����
	--]]
end

function ScriptObject:__release()
	--[[
	�ͷŶ���ʱ�Ļص�����
	--]]
	self:deregisterTriggers_()
end

function ScriptObject:registerTriggers_()
	--[[
	���¼�������ע�᱾����¼�
	--]]
	for k, _ in pairs(self.triggers_) do
		ECenter.registerEvent(k, self)
	end
end

function ScriptObject:deregisterTriggers_()
	--[[
	���¼�������ע��������¼�
	----]]
	for k, _ in pairs(self.triggers_) do
		ECenter.deregisterEvent(k, self)
	end
	table.clear(self.triggers_)
	self.triggers_ = {}
end

function ScriptObject:__onEngineObjLost()
	--[[
	�ҽӵ��������ʧʱ���ص��ú���.
	--]]
	if self.engineObj_ ~= nil then
		self.engineObj_:SetScriptObjID(InvalidScriptID)
		self.engineObj_ = nil
	end
end

function ScriptObject:__onEngineObjAttach(engineObj)
	--[[
	����ScriptObject.attachEngineObj��CScriptObject.CreateScriptObjʱ�Ļص�����
	@param	engineObj:
	@type	engineObj: CScriptObject
	--]]
	self.engineObj_ = engineObj
end

function ScriptObject:onEvent(eventKey, ...)
	--[[
	��Ϣ�¼��ص�����
	@param	eventKey: �¼�����
	@type	eventKey: string
	@param	arg: �����¼��ص������Ĳ����б�
	@type	arg: ����ʵ�ʵĴ����¼��ص���������
	--]]
	self.triggers_[eventKey](self, ...)
end

function ScriptObject.New()
	--[[
	�������󣬸÷�����Ҫ����������
	--]]
	local obj = ScriptObject()
	return obj
end

function ScriptObject:getScriptClass()
	--[[
	��ȡ������ƣ��÷�����Ҫ����������
	--]]
	return "ScriptObject"
end

function ScriptObject:attachEngineObj(engineObj)
	--[[
	���ű�����ҽӵ��������
	@param	engineObj: �������
	@type	engineObj: CScriptObject
	--]]
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

function autoWrapEngine(scriptClassName, engineObjName, engineClass)
	--[[
	�Զ���װ�����෽�����ű�����
	@param	scriptClassName: �ű�����
	@type	scriptClassName: string
	@param	engineObj: ��װ�ӿڵ����������
	@type	engineObj: string
	@param	engineClass: ������
	@type	engineClass: engineClass
	--]]
	for k, v in pairs(engineClass) do
		if type(v) == "function" and k ~= "__index" and k ~= "__newindex" and 
		   k ~= "new" and k ~= "new_local" and
		   k ~= ".call" and k ~= "__call" and 
		   k ~= ".collector" and k ~= "__gc" then
			local strFunc = string.format("function %s:%s(...) return self.%s:%s(...) end", scriptClassName, k, engineObjName, k)
			DoBuffer(strFunc)
		end
	end
end


function autoImpScriptClassDim(driveClassName, bassClassName, ...)
	--[[
	�Զ���ɼ̳�bassClassName��driveClassName��������ʵ�֡�driveClassName.New����
	��driveClassName:getScriptClass������,���Զ���װ�������(�ɱ�����б�arg��)
	@param	driveClassName: �ű�������
	@type	driveClassName: string
	@param	bassClassName: ���̳еĻ�����
	@type	bassClassName: string
	@param	arg: �ɱ���������������
	@type	arg: table of engineClass
	--]]
	local strDimClass = string.format("%s = class(%s)", driveClassName, bassClassName)
	local strFuncNew = string.format("function %s.New() return %s() end", driveClassName, driveClassName)
	local strFuncGetClass = string.format("function %s:getScriptClass() return \"%s\" end", driveClassName, driveClassName)
	DoBuffer(strDimClass)
	DoBuffer(strFuncNew)
	DoBuffer(strFuncGetClass)
	
	for _, v in ipairs(arg) do
		autoWrapEngine(driveClassName, "engineObj_", v)
	end
end

--------------------------------------------------------------------------------