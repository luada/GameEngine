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
	初始化对象时的回调函数
	--]]
	self.triggers_ = {}
end

function ScriptObject:__onLoaded()
	--[[
	对象被引擎加载数据后的回调函数
	--]]
end

function ScriptObject:__release()
	--[[
	释放对象时的回调函数
	--]]
	self:deregisterTriggers_()
end

function ScriptObject:registerTriggers_()
	--[[
	向事件管理器注册本类的事件
	--]]
	for k, _ in pairs(self.triggers_) do
		ECenter.registerEvent(k, self)
	end
end

function ScriptObject:deregisterTriggers_()
	--[[
	向事件管理器注销本类的事件
	----]]
	for k, _ in pairs(self.triggers_) do
		ECenter.deregisterEvent(k, self)
	end
	table.clear(self.triggers_)
	self.triggers_ = {}
end

function ScriptObject:__onEngineObjLost()
	--[[
	挂接的引擎对象丢失时，回调该函数.
	--]]
	if self.engineObj_ ~= nil then
		self.engineObj_:SetScriptObjID(InvalidScriptID)
		self.engineObj_ = nil
	end
end

function ScriptObject:__onEngineObjAttach(engineObj)
	--[[
	调用ScriptObject.attachEngineObj或CScriptObject.CreateScriptObj时的回调函数
	@param	engineObj:
	@type	engineObj: CScriptObject
	--]]
	self.engineObj_ = engineObj
end

function ScriptObject:onEvent(eventKey, ...)
	--[[
	消息事件回调处理
	@param	eventKey: 事件名字
	@type	eventKey: string
	@param	arg: 触发事件回调函数的参数列表
	@type	arg: 根据实际的触发事件回调函数而定
	--]]
	self.triggers_[eventKey](self, ...)
end

function ScriptObject.New()
	--[[
	创建对象，该方法需要被子类重载
	--]]
	local obj = ScriptObject()
	return obj
end

function ScriptObject:getScriptClass()
	--[[
	获取类的名称，该方法需要被子类重载
	--]]
	return "ScriptObject"
end

function ScriptObject:attachEngineObj(engineObj)
	--[[
	将脚本对象挂接到引擎对象
	@param	engineObj: 引擎对象
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
	自动封装引擎类方法到脚本类上
	@param	scriptClassName: 脚本类名
	@type	scriptClassName: string
	@param	engineObj: 封装接口的引擎对象名
	@type	engineObj: string
	@param	engineClass: 引擎类
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
	自动完成继承bassClassName的driveClassName的声明，实现“driveClassName.New”和
	“driveClassName:getScriptClass”方法,并自动封装引擎对象(可变参数列表arg中)
	@param	driveClassName: 脚本子类名
	@type	driveClassName: string
	@param	bassClassName: 被继承的基类名
	@type	bassClassName: string
	@param	arg: 可变参数表，存放引擎类
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