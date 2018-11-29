--//Util.lua
require("base.logger")

Enum = {};
function new(self, nBase)
	local ret = {};
	local _base = nBase or 0;
	local _count = _base;
	setmetatable(ret, Enum)
	Enum.__call = function(self) local nRet = _count;_count = _count + 1; return nRet; end
	ret.check = function(self,nNum)
		return type(nNum) == "number" and nNum >= _base and nNum < _count;
	end
	return ret;
end
setmetatable(Enum, {__call = new })


--add by joss
---------------------------------------------------------
local gDefLoger = Logger.getLogger()
function Logger.debug(message)
	gDefLoger:debug(message)
end

function Logger.info(message)
	gDefLoger:info(message)
end

function Logger.warn(message)
	gDefLoger:warn(message)
end

function Logger.error(message)
	gDefLoger:error(message)
end

function Logger.fatal(message)
	gDefLoger:fatal(message)
end


--{金,银,铜}转数字
function numberMoney(moneys)
	local mm=0
    for k,v in pairs(moneys) do
	    if (k==1) then		--金币
		    mm=mm+v*10000
	    elseif (k==2) then		--银币
		    mm=mm+v*100
	    elseif (k==3) then		--铜币
		    mm=mm+v
	    end
    end
    return mm
end

--数字转金银铜
function gameMoney(money)
	local g=math.floor(money/10000)
	local fg=math.fmod(money,10000)
	local s=math.floor(fg/100)
	local b=math.fmod(fg,100)
	return {g,s,b}
end
--颜色转换成数字
function Color2Num(color)
	if not color then return 0xFFFFFF end
	local b = (color.b or 0xFF) * 0x10000
	local g = (color.g or 0xFF) * 0x100
	local r = color.r or 0xFF
	return r + g + b
end

function getGUIColor(colorName)
	if colorName then
		colorName=string.lower(colorName)
	end
	local color
	if colorName=="blue" then
		color="tl:FF0000FF tr:FF0000FF bl:FF0000FF br:FF0000FF"
	elseif colorName=="red" then
		color="tl:FFFF0000 tr:FFFF0000 bl:FFFF0000 br:FFFF0000"
	elseif colorName=="pink" then
		color="tl:FF0000FF tr:FF0000FF bl:FF0000FF br:FF0000FF"
	elseif colorName=="green" then
		color="tl:FF00FF66 tr:FF00FF66 bl:FF00FF66 br:FF00FF66"
	elseif colorName=="yellow" then
		color="tl:FFFFFF00 tr:FFFFFF00 bl:FFFFFF00 br:FFFFFF00"
	elseif colorName=="white" then
		color="tl:FFFFFFFF tr:FFFFFFFF bl:FFFFFFFF br:FFFFFFFF"
	elseif not colorName or colorName=="black" then
		color="tl:FF000000 tr:FF000000 bl:FF000000 br:FF000000"
	end
	return color
end

function SetPos(tar, src)
	--print("AciontPlayer:_copyPos(tar, src) ", toString(tar), toString(src));
	if tar and src then			
		tar.x = src.x
		tar.y = src.y
	end	
end




