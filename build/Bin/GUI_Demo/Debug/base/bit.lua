--[[bit.lua
提供位运行的类

Exported API:
	bit_and(a, b)
	bit_or(a, b)
	bit_xor(a, b)
	bit_not(a)
	bit_lshift(a, n)
	bit_rshift(a, n)
	bit_tostring(a)

Example:
	local n = bit_not(7)
	print(bit_tostring(n))

	n = bit_lshift(7, 2)
	print(bit_tostring(n))

	n = bit_rshift(7, 2)
	print(bit_tostring(n))

	local n1 = bit_and(0x08, 0x0A)
	print(bit_tostring(n1))

	local n1 = bit_or(0x08, 0x0A)
	print(bit_tostring(n1))

	local n1 = bit_xor(0x08, 0x0A)
	print(bit_tostring(n1))
--]]

local power = 32
local data = {}
for i = 1, power do data[i] = 2^(power-i) end

local function d2b(n)
	b = toNumber(b)
	local ret = {}
	for i = 1, power do
		if n >= data[i] then
			ret[i] = 1
			n = n - data[i]
		else
			ret[i] = 0
		end
	end
	return ret
end

local function b2d(b)
	local ret = 0
	for i = 1, power do
		if b[i] ==1 then
			ret = ret + 2^(power-i)
		end
	end
	return  ret
end



local function _and(a, b)
	if not a then
		return b
	elseif not b then
		return a
	end

	local b1 = d2b(a)
	local b2 = d2b(b)
	local r = {}

	for i = 1, power do
		if b1[i] == 1 and b2[i] == 1 then
			r[i] = 1
		else
			r[i] = 0
		end
	end

	return b2d(r)
end

function bit_and(...)
	local ret = select(1, ...)
	for i = 2, select("#", ...) do
		ret = _and(ret, select(i, ...))
	end
	return ret
end

local function _or(a, b)
	if not a then
		return b
	elseif not b then
		return a
	end

	local b1 = d2b(a)
	local b2 = d2b(b)
	local r = {}

	for i = 1, power do
		if b1[i] == 1 or b2[i] == 1 then
			r[i] = 1
		else
			r[i] = 0
		end
	end

	return b2d(r)
end

function bit_or(...)
	local ret = select(1, ...)
	for i = 2, select("#", ...) do
		ret = _or(ret, select(i, ...))
	end
	return ret
end

function bit_xor(a, b)
	if not a then
		return b
	elseif not b then
		return a
	end

	local b1 = d2b(a)
	local b2 = d2b(b)
	local r = {}

	for i = 1, power do
		if b1[i] ~= b2[i] then
			r[i] = 1
		else
			r[i] = 0
		end
	end

	return b2d(r)
end

function bit_not(a)
	local b = d2b(a)
	local r = {}

	for i = 1, power do
		if b[i] == 0 then
			r[i] = 1
		else
			r[i] = 0
		end
	end

	return b2d(r)
end

function bit_lshift(a, n)
	local r = d2b(0)

	if n < power and n > 0 then
		local b = d2b(a)
		for i = 1, n do
			for j = 1, power - 1 do
				b[j] = b[j+1]
			end
			b[power] = 0
		end
		r = b
	end

	return b2d(r)
end

function bit_rshift(a, n)
	local r = d2b(0)

	if n < power and n > 0 then
		local b = d2b(a)
		for i = 1, n do
			for j = power - 1, 1, -1 do
				b[j+1] = b[j]
			end
			b[1] = 0
		end
		r = b
	end

	return b2d(r)
end

function bit_tostring(a)
	local b = d2b(a)
	local s = ""
	for i = 1, power do
		s = s .. b[i]
	end
	return s
end