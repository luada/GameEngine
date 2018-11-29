--[[Debug.lua
主要数据结构：
	breakList = { [fileName] = {[line] = true}, }
	FunVar = { [varName] = value, }
--]]

local breakList = nil --断点信息表
local FunVar = nil --局部变量表
local step = false --标志是否单步调试
local next = false --标志是否跳过函数的单步调试
local oldDepth = 0



--打印变量的函数
function debug_print_var(varName, value)
	print(varName .. " = " .. toString(value))
end
---------------------------------------提供给游戏客户端Console的脚本命令---------------------------------
--查看变量var的值
function getValue(_var)
	--找局部变量
	local value = nil
	if type(FunVar) == "table" then
		value = FunVar[_var]
	end

	--找全局变量
	if _G[_var] ~= nil then
		value =  _G[_var]
	end
	return value
end

function Watch(var)
	local _var=var
	local temp=var
	local count=1
	local value = nil
	while true do
		local index=string.find(temp,"%.")
		local strLen=string.len(temp)
		if index then
			if count==1 then
				_var=string.sub(temp,1,index-1)
				value=getValue(_var)
			end
			local temp_=nil
			temp=string.sub(temp,index+1,strLen)
			local endIndex=string.find(temp,"%.")
			if endIndex then
				_temp=string.sub(temp,1,endIndex-1)
			else
				_temp=temp
			end
			if value and _temp then
				value=value[_temp]
			end
		else
			if count==1 then
				value=getValue(_var)
			end
			break
		end
		count=count+1
	end

	if value~=nil then
		debug_print_var(var, value)
		return
	end

	print("error.., var不存在",var,value)
end

--单步调试,跳到下一行
function Step()
	step = true
	print("已经设置为单步调试状态 step = ", step)
end

function CancelStep()
	step = false
	print("已经取消单步调试状态 step = ", step)
end

function Next()
	next = true
end

function Go()
	print("运行到下一个断点")
end

--打印所有断点的信息
function InfoBreak()
	if breakList then
		for fileName, breakLines in pairs(breakList) do
			for line, state in pairs(breakLines) do
				print("file :"..fileName..", line :"..line)
			end
		end
	end
end

--移除断点
function RemoveBreak(fileName, line)
	if not fileName then
		if not line then
			breakList = nil
		end
	else
		if not line then
			if (breakList) then breakList[fileName] = nil end
		else
			if (breakList) and breakList[fileName] then breakList[fileName][line] = nil end
		end
	end
end

--增加断点
function Break(fileName, line)
	if not (breakList) then
		breakList = {}
	end

	if (breakList[fileName]) then
		breakList[fileName][line] = true
	else
		breakList[fileName] = {[line] = true}
	end

	if g_clientEngine then
		g_clientEngine:setMode(NONE_)
	end
end

local command =
{
	["S"]=Step,
	["B"]=Break,
	["I"]=InfoBreak,
	["C"]=CancelStep,
	["N"]=Next,
	["G"]=Go,
	["W"]=Watch,
	["R"]=RemoveBreak,
}

local stopCommand =
{
	["S"] = true,
	["C"] = true,
	["G"] = true,
	["N"] = true,
}

--改变相应的luaState连接
function ChangeState(index)
	if g_clientEngine then
		if index >0 then
			g_clientEngine:setNeedRender(false)
		else
			g_clientEngine:setNeedRender(true)
		end
		g_clientEngine:getNetwork():setCurLink(index)
	end
end

--填充当前断点处环境的局部变量
function fillVarsList()
	local index = 1
	FunVar = {}
	while true do
		local name, value = debug.getlocal(4, index)
		--print("zl", name, value)
		if name then
			FunVar[name] = value
			index = index + 1
		else
			break
		end
	end
end

function ListSrc(filename,line)
	local _fname = filename
	local index = string.find(filename, ".lua")
	local modulename = string.sub(filename, 1, index-1)
	local fpath = nil

	for i, v in pairs(package.loaded) do
		index = string.find(i, modulename)
		if index then
			local t=string.sub(i,index-1,index-1)
			if t=="." then
				local temp = string.find(i,"%.",index+1)
				if not temp then
					fpath=string.sub(i, 1, index-1)
				end
			end
		end
	end

	if fpath then
		fpath=string.gsub(fpath,"%.","\\")
		_fname=fpath.."\\".._fname

	end
	local src = g_clientEngine:get_file_line(_fname, line)
	print("code: ")
	print(src)
end


--中断函数
function interupt(filename, line)
	ListSrc(filename,line)
	print("---------------------------------------------------")
	print("file:"..filename.. ",line:" .. line.." breaking now!")

	if g_clientEngine then
		g_clientEngine:setMode(DEBUG_)
		fillVarsList() --保存中断处的变量信息
		oldDepth = debug.traceback_count() - 2

		if step == true then
			step = false
		end

		if next == true then
			next = false
		end

		while true do --中断,直到从控制台获得输入command
			local count=1
			local cmd = nil
			local paramlist={}
			local cmdstr = g_clientEngine:peekCommand()
			if cmdstr then
				for w in string.gmatch(cmdstr, "%w+") do
					if count==1  then
						cmd=w
					else
						paramlist[count-1]=w
					end
					count=count+1
				end
				if (command[cmd]) then
					command[cmd](unpack(paramlist))
				else
					g_clientEngine:RunMemoryLua(cmdstr)
				end
				if stopCommand[cmd] == true then
					break
				end

			end
		end
	end
end


--对应每行的钩子函数
function trace(event, line)
	local fileName = debug.getinfo(2).short_src --返回的函数所在的文件名字
	local cmd = nil --来自控制台的命令字符串
	local tempFileName = nil
	local currentDepth = nil

	--解析文件名tempFileName
	local strLen=string.len(fileName)
	local index=string.find(fileName,"-")
	if not (index) then return end
	local substr=string.sub(fileName,index+2,strLen)
	strLen=string.len(substr)
	local temp=string.sub(substr,1,2)
	if temp=="[[" then substr=string.sub(substr,3,strLen) end
	index=string.find(substr,"\"")
	if not (index) or not(substr) then return end
	tempFileName=string.sub(substr,1,index-4)


	if not g_clientEngine then
		return
	end

	--单步调试
	if step == true then
		interupt(tempFileName, line)
		return
	end

	--跳过函数的单步调试
	if next == true then
		currentDepth = debug.traceback_count() - 1
		if currentDepth <= oldDepth then
			interupt(tempFileName, line)
		end
	end

	--断点调试
	if g_clientEngine and breakList then
		for name, breakLines in pairs(breakList) do
			for lineNum, state in pairs(breakLines) do
				if name == tempFileName and line == lineNum then
					interupt(tempFileName, lineNum)
				end
			end
		end
	end
end


--进入调试状态
function StartDebug()
	debug.sethook(trace, "l")
	print("debug start!")
end

--关闭调试状态
function StopDebug()
	debug.sethook()
	print("debug stop!")
end

--获取当前运行的代码行信息：文件名，行号，函数名
function getCurrentCodeInf(level)
	local info = debug.getinfo(level, "nSl")
	if not info then
		return "Can not fetch current code information!"
	end

	if info.what == "C" then
		return "C function"
	else
		local codeInfo = string.format("%s (%d) @ function %s",
				info.short_src, info.currentline, info.name or "")
		return codeInfo
	end
end



