--[[Debug.lua
��Ҫ���ݽṹ��
	breakList = { [fileName] = {[line] = true}, }
	FunVar = { [varName] = value, }
--]]

local breakList = nil --�ϵ���Ϣ��
local FunVar = nil --�ֲ�������
local step = false --��־�Ƿ񵥲�����
local next = false --��־�Ƿ����������ĵ�������
local oldDepth = 0



--��ӡ�����ĺ���
function debug_print_var(varName, value)
	print(varName .. " = " .. toString(value))
end
---------------------------------------�ṩ����Ϸ�ͻ���Console�Ľű�����---------------------------------
--�鿴����var��ֵ
function getValue(_var)
	--�Ҿֲ�����
	local value = nil
	if type(FunVar) == "table" then
		value = FunVar[_var]
	end

	--��ȫ�ֱ���
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

	print("error.., var������",var,value)
end

--��������,������һ��
function Step()
	step = true
	print("�Ѿ�����Ϊ��������״̬ step = ", step)
end

function CancelStep()
	step = false
	print("�Ѿ�ȡ����������״̬ step = ", step)
end

function Next()
	next = true
end

function Go()
	print("���е���һ���ϵ�")
end

--��ӡ���жϵ����Ϣ
function InfoBreak()
	if breakList then
		for fileName, breakLines in pairs(breakList) do
			for line, state in pairs(breakLines) do
				print("file :"..fileName..", line :"..line)
			end
		end
	end
end

--�Ƴ��ϵ�
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

--���Ӷϵ�
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

--�ı���Ӧ��luaState����
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

--��䵱ǰ�ϵ㴦�����ľֲ�����
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


--�жϺ���
function interupt(filename, line)
	ListSrc(filename,line)
	print("---------------------------------------------------")
	print("file:"..filename.. ",line:" .. line.." breaking now!")

	if g_clientEngine then
		g_clientEngine:setMode(DEBUG_)
		fillVarsList() --�����жϴ��ı�����Ϣ
		oldDepth = debug.traceback_count() - 2

		if step == true then
			step = false
		end

		if next == true then
			next = false
		end

		while true do --�ж�,ֱ���ӿ���̨�������command
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


--��Ӧÿ�еĹ��Ӻ���
function trace(event, line)
	local fileName = debug.getinfo(2).short_src --���صĺ������ڵ��ļ�����
	local cmd = nil --���Կ���̨�������ַ���
	local tempFileName = nil
	local currentDepth = nil

	--�����ļ���tempFileName
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

	--��������
	if step == true then
		interupt(tempFileName, line)
		return
	end

	--���������ĵ�������
	if next == true then
		currentDepth = debug.traceback_count() - 1
		if currentDepth <= oldDepth then
			interupt(tempFileName, line)
		end
	end

	--�ϵ����
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


--�������״̬
function StartDebug()
	debug.sethook(trace, "l")
	print("debug start!")
end

--�رյ���״̬
function StopDebug()
	debug.sethook()
	print("debug stop!")
end

--��ȡ��ǰ���еĴ�������Ϣ���ļ������кţ�������
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



