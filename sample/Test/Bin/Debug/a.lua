require "base.class"

function serialize (o)
	if type(o) == "number" then
		io.write(o)
	elseif type(o) == "string" then
		io.write(string.format("%q", o))
	elseif type(o) == "table" then
		io.write("{\n")
		for k,v in pairs(o) do
			io.write(" ", k, " = ")
			serialize(v)
			io.write(",\n")
			end
		io.write("}\n")
	else
		print("cannot serialize a " .. type(o))
	end
end


function fetchFunction(srcTbl, dstTbl)
	for k, v in pairs(srcTbl) do
			print(k, v)
			if type(v) == "function" then
				dstTbl[k] = v
			end
	end
end


AA = class()

function AA:Tst()
   print(self.id)
   self:Tst1()
end




BB = class(AA)

function BB:Tst1()
    print(self.mm)
end


A = {}


function A:Tst(a, b, c)
	print(a, b, c)
end

B = class()

function B:Tst(...)
	return self.obj:Tst(...)
end

function AutoWrapEngine(scriptClass, engineClass)
	for k, v in pairs(engineClass) do
		if type(v) == "function" then
			strFunc = string.format("function %s:%s(...) return self.engineObj:%s(...) end", scriptClass, k, k)
			print(strFunc)
		end
	end
end

function AutoImpUIClass(scriptClass)
	strDimClass = string.format("UI.%s = class(UI.UIObject)", scriptClass)
	strFuncNew = string.format("function UI.%s.New() return UI.%s() end", scriptClass, scriptClass)
	strFuncGetClass = string.format("function UI.%s:getScriptClass() return \"UI.%s\" end", scriptClass, scriptClass)
	print(strDimClass)
	print(strFuncNew)
	print(strFuncGetClass)
end

AutoImpUIClass("Button")



---fetchFunction(A, BB)









