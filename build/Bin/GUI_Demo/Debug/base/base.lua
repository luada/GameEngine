--[[base.lua
为指定对象定义元表

Exported API:
	define(class, table)
	getGlobalName(object)
	getObjectKey(object)
	getObjectsKey(...)
	string.startsWith(value, prefix, toffset)
	string.endsWith(value, suffix)
	string.title(value)
	string.charAt(value, position)
	string.isWhitespace(value)
	string.toArray(value)
	string.bytecode(value)
	string.substr(value, index, length)
	table.copy(source, destiny, overlay)
	table.deepCopy(source, destiny)
	table.copyTable(source, destiny)
	table.join(...)
	table.clear(tab)
	table.removeValue(value)
	table.removeKey(key)
	table.hasValue(value)
	table.hasKey(key)
	table.size(tab)
	table.iterator(tab)
	table.sortIterator(tab, comparator)
	table.contains(tab, object)
	table.isArray(tab)
	table.isMap(tab)
	table.unpack(tab)
	table.getKeyName(tab, value)
	math.rand(n1, n2)
	math.round(n)

Example:
	local classMap = define { __mode = "k" }

	for k,v in table.iterator(t) do
		print(k,v)
	end
--]]

--------------------------------------------------------------------------------
function define(class, object)
	return setmetatable(object or {}, class)
end
--------------------------------------------------------------------------------
function getGlobalName(object)
	if object then
		for k, v in pairs(_G) do
			if v == object then
				return k
			end
		end
	end
	return tostring(nil)
end
--------------------------------------------------------------------------------
function getObjectKey(object)
	local _, _, key = string.find(tostring(object), ":%s*(%w+)")
	return key or (object or tostring(object) and "")
end
--------------------------------------------------------------------------------
function getObjectsKey(...)
	local ret = ""
	table.foreach(arg,
		function(k, v)
			ret = string.format("%s_%s", ret, getObjectKey(v))
		end)
	return ret
end
--------------------------------------------------------------------------------
function toNumber(value, default)
	local ret = tonumber(value)
	return ret and ret or (default or 0)
end
--------------------------------------------------------------------------------
function toBool(value)
	if type(value) == "boolean" then
		return value
	elseif type(value) == "string" then
		local str = string.lower(value)
		if str == "true" or str == "yes" or str == "y" then
			return true
		else
			return false
		end
	elseif type(value) == "number" then
		if value > 0 then
			return true
		else
			return false
		end
	else
		return false
	end
end
--------------------------------------------------------------------------------
function string.startsWith(value, prefix, toffset)
	if value and prefix then
		toffset = (toffset or 1) > 0 and toffset or 1
		return string.sub(value, toffset, toffset + #prefix - 1) == prefix
	end
	return false
end
--------------------------------------------------------------------------------
function string.endsWith(value, suffix)
	if value and suffix then
		return string.sub(value, -#suffix) == suffix
	end
	return false
end
--------------------------------------------------------------------------------
function string.title(value)
	return string.upper(string.sub(value, 1, 1)) .. string.sub(value, 2, #value)
end
--------------------------------------------------------------------------------
function string.charAt(value, position)
	if value and position and position > 0 then
		local b = string.byte(value, position, position + 1)
		return b and string.char(b) or b
	end
end
--------------------------------------------------------------------------------
function string.isWhitespace(value)
	if value then
		local len = #value
		for i = 1, len do
			local char = string.charAt(value, i)
			if char ~= " " and char ~= "\t" then
				return false
			end
		end
		return true
	end
	return false
end
--------------------------------------------------------------------------------
function string.toArray(value)
	local ret = {}
	if value then
		local idx = 1
		local count = #value
		while idx <= count do
			local b = string.byte(value, idx, idx + 1)
			if b > 127 then
				table.insert(ret, string.sub(value, idx, idx + 1))
				idx = idx + 2
			else
				table.insert(ret, string.char(b))
				idx = idx + 1
			end
		end
	end
	return ret
end
--------------------------------------------------------------------------------
function string.bytecode(value)
	if value then
		local bytes = {}
		local idx = 1
		local count = #value
		while idx <= count do
			local b = string.byte(value, idx, idx + 1)
			if b > 100 then
				table.insert(bytes, '\\'..b)
			else
				table.insert(bytes, '\\0'..b)
			end
			idx = idx + 1
		end
		local code, ret = pcall(loadstring(string.format("do local _='%s' return _ end", table.concat(bytes))))
		if code then
			return ret
		end
	end
	return ""
end
-------------colen:根据某个符合拆分字符串为数组(缺省为&,字符串形式:"a=v1&b-v2&c=v3", -------------------
function string.split(str,split)
	local strTab={}
	local sp=split or "&"
	while type(str)=="string" and string.len(str)>0 do
		local f=string.find(str,sp)
		local ele
		if f then
			ele=string.sub(str,1,f-1)
			str=string.sub(str,f+1)
		else
			ele=str
		end
		if ele then
			local sp2=string.find(ele,"=")
			if sp2 then
				local b=string.sub(ele,sp2+1)
				local s,b2=pcall(loadstring("local bb="..b..";return bb"))
				strTab[string.sub(ele,1,sp2-1)]=b2
			end
		end
		if not f then break	end
	end
	return strTab
end
--------------------------------------------------------------------------------
function string.substr(value, index, length)
	if value then
		local ret = {}
		local idx = index
		local count = length or #value
		while idx <= count do
			local b = string.byte(value, idx, idx + 1)
			if not b then
				break
			end
			if b > 127 then
				table.insert(ret, string.sub(value, idx, idx + 1))
				idx = idx + 2
			else
				table.insert(ret, string.char(b))
				idx = idx + 1
			end
		end
		return table.concat(ret)
	end
end
--------------------------------------------------------------------------------
table.empty = define({ __newindex = function(s, f, v) print("This is a read-only table") end }, {})
--------------------------------------------------------------------------------
function table.copy(source, destiny, overlay)
	if source then
		overlay = overlay ~= false
		if not destiny then destiny = {} end
		for field, value in pairs(source) do
			if overlay then
				destiny[field] = value
			elseif not destiny[field] then
				destiny[field] = value
			end
		end
	end
	return destiny
end
--------------------------------------------------------------------------------
--深度copy（注意：源table key,value与目标重复时，使用table.insert,源key不再保留,copy数据
function table.deepCopy(source, destiny)
	local destiny = destiny or {}
	for key, value in pairs(source or table.empty) do
		if destiny[key] then
			table.insert(destiny,value)
		else
			if type(value) == "table" then
				destiny[key] = table.deepCopy(value)
			else
				destiny[key] = value
			end
		end
	end
	return destiny
end
--------------------------------------------------------------------------------
--把一个table复制到另一个, 不会保留key值，但目标table不会收到影响
function table.copyTable(source, destiny)
	local destiny = destiny or {}
	for _, value in pairs(source or table.empty) do
		if type(value) == "table" then
			table.insert(destiny, table.copyTable(value))
		else
			table.insert(destiny, value)
		end
	end
	return destiny
end
--------------------------------------------------------------------------------
function table.join(...)
	local ret = {}
	for i = 1, select("#", ...) do
		local tb = select(i, ...)
		for _, value in pairs(tb or table.empty) do
			table.insert(ret, value)
		end
	end
	return ret
end
--------------------------------------------------------------------------------
function table.clear(tab)
	if tab then
		local field = next(tab)
		while field do
			tab[field] = nil
			field = next(tab)
		end
	end
	return tab
end
--------------------------------------------------------------------------------
function table.removeValue(tab, value)
	if tab then
		if table.isArray(tab) then
			local idx = 1
			for k, v in pairs(tab) do
				if v == value then
					table.remove(tab, idx)
					break
				end
				idx = idx + 1
			end
		else
			for k, v in pairs(tab) do
				if v == value then
					tab[k] = nil
					break
				end
			end
		end
	end
	return tab
end
--------------------------------------------------------------------------------
function table.removeKey(tab, key)
	if tab then
		for k, v in pairs(tab) do
			if k == key then
				tab[k] = nil
				break
			end
		end
	end
	return tab
end
--------------------------------------------------------------------------------
function table.hasValue(tab, value)
	for k, v in pairs(tab) do
		if v == value then
			return true
		end
	end
	return false
end
--------------------------------------------------------------------------------
function table.hasKey(tab, key)
	for k, v in pairs(tab, key) do
		if k == key then
			return true
		end
	end
	return false
end
--------------------------------------------------------------------------------
function table.size(tab)
	local size = 0
	if tab then
		table.foreach(tab, function()
			size = size + 1
		end)
	end
	return size
end
--------------------------------------------------------------------------------
local empty_fun = function() end
function table.iterator(tab)
	if tab then
		local index = 0
		local auxTable = {}
		table.foreach(tab, function(i, v)
			if type(i) == "number" then
				table.insert(auxTable, i)
			else
				table.insert(auxTable, tostring(i))
			end
		end)

		return function()
			if index < #auxTable then
				index = index + 1
				local field = auxTable[index]
				return field, tab[field]
			end
		end
	else
		return empty_fun
	end
end
--------------------------------------------------------------------------------
function table.sortIterator(tab, comparator)
	if tab then
		local index = 0
		local auxTable = {}
		table.foreach(tab, function(i, v)
			table.insert(auxTable, i)
		end)

		table.sort(auxTable, comparator)

		return function()
			if index < #auxTable then
				index = index + 1
				local field = auxTable[index]
				return field, tab[field]
			end
		end
	else
		return empty_fun
	end
end
--------------------------------------------------------------------------------
function table.contains(tab, object)
	if tab and object then
		for field, value in pairs(tab) do
			if object == value then return true end
		end
	end
	return false
end
-----------colen,是否包含某个元素,支持数组(必须k,v同时相等)-------------
function table.include(tab,element)
	for k,v in pairs(tab or table.empty) do
		local done=false
		if type(v)=="table" and type(element)=="table" then
			done=true
			if table.size(element)~=table.size(v) then
				done=false
			end
			for k2,v2 in pairs(element) do
				if not v[k2] or v[k2]~=v2 then
					done=false
					break
				end
			end
		elseif v==element then
			done=true
		end
		if done then
			return true
		end
	end
	return false
end
------------包含一组元素-------------------------------------------------------------------
function table.includes(tab,elements)
	for k,v in pairs(elements or table.empty) do
		if not table.include(tab,v) then
			return false
		end
	end
	return true
end
--------------------------------------------------------------------------------
function table.isArray(tab)
	if not tab then
		return false
	end

	local ret = true
	local idx = 1
	for f, v in pairs(tab) do
		if type(f) == "number" then
			if f ~= idx then
				ret = false
			end
		else
			ret = false
		end
		if not ret then break end
		idx = idx + 1
	end
	return ret
end
--------------------------------------------------------------------------------
function table.isMap(tab)
	if not tab then
		return false
	end
	return table.isArray(tab) ~= true
end
--------------------------------------------------------------------------------
function table.unpack(tab)
	local ret
	if table.isArray(tab) then
		ret = tab
	else
		ret = {}
		local idx = 1
		for f, v in pairs(tab or table.empty) do
			if type(f) == "number" and f == idx then
				ret[f] = v
				idx = idx + 1
			else
				table.insert(ret, {[f]=v})
			end
		end
	end
	return unpack(ret)
end
--------------------------------------------------------------------------------
function table.getKeyName(tab, value)
	for k, v in pairs(tab or table.empty) do
		if v == value then
			return tostring(k)
		end
	end
	return ""
end
--------------------------------------------------------------------------------
--Kirk's modi: to save a table to a file
function table.save(tab,fname,name)
	if type(tab) == "table" then
		local f = io.open(fname, "w")
		if f then
			if type(name) == "string" then
				f:write(name.." = ")
			end
			f:write(serialize(tab))
			f:close()
			return true
		end
	end
	return false
end
--------------------------------------------------------------------------------
function math.rand(n1, n2)
	return math.random(n1*10000, n2*10000)/10000
end
--------------------------------------------------------------------------------
function math.round(n)
	return math.floor(0.5 + n)
end
