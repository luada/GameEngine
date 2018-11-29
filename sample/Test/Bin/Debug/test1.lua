require "test"

--a = AA()

--a:CreateEngineObj()

a = T.GetObj()
scriptObjID = a:GetScriptObjID()
a = ObjectDynamicCast(a)
scriptObj = GetRegistryObj(scriptObjID)
print(scriptObj, a.scriptObj)
scriptObj:DDDD(123456)
a:DDDD(987653)
a.scriptObj:mm()