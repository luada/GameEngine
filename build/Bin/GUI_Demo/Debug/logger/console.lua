--[[console.lua
提供简单的控制台日志消息输出

Exported API:
	Logger.console(logPattern)

	logger.isDebug()
	logger.isInfo()
	logger.isWarn()
	logger.isError()
	logger.isFatal()
	logger.debug(message)
	logger.info(message)
	logger.warn(message)
	logger.error(message)
	logger.fatal(message)

Example:
	local log = Logger.console()
	log:setLevel(Logger.DEBUG)
	if log:isDebug() then
		log:debug("message")
	end
--]]

--require "base.logger"

local MAX_STRING_LENGTH = 512

local _print = print

--把字符串按最大长度拆分输出
function output(str)
	if str == nil then
		_print(nil)
	elseif #str > 0 then
		local idx = 1
		local substr = str
		while #substr > 0 do
			local s = string.substr(substr, 1, MAX_STRING_LENGTH)
			_print(s)
			substr = string.substr(substr, #s+1)
		end
	else
		_print()
	end
end

--替换%,避免出现Trace参数个数与格式不匹配
function print(...)
	local t = {}
	for i = 1, select("#", ...) do
		table.insert(t, tostring(select(i, ...)))
	end

	local str = string.gsub(table.concat(t, "\t"), "%%", "%%%%")
	output(str)
end

function Logger.console(logPattern)
	return Logger(function(self, level, message)
			local d = os and os.date() or ""
			print(Logger.log(logPattern, d, level, message))
			return true
		end
	)
end
