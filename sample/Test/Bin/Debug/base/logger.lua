--[[logger.lua
提供日志消息输出

Exported API:
	Logger(append)

	logger.isDebug()
	logger.isInfo()
	logger.isWarn()
	logger.isError()
	logger.isFatal()
	logger.debug(message, ...)
	logger.info(message, ...)
	logger.warn(message, ...)
	logger.error(message, ...)
	logger.fatal(message, ...)

Example:
	function Logger.console(logPattern)
		return Logger(function(self, level, message)
				print(Logger.log(logPattern, os.date(), level, message))
				return true
			end
		)
	end
--]]

require "base.string"
require "base.try"
require "base.Debug"

--------------------------------------------------------------------------------
-- 关闭所有消息输出
local OFF = "OFF"

-- 允许所有等级消息输出
local ALL = "ALL"

-- 用于调试消息的输出
local DEBUG = "DEBUG"

-- 用于跟踪程序运行进度
local INFO = "INFO"

-- 程序运行时发生异常
local WARN = "WARN"

-- 程序运行时发生可预料的错误,此时通过错误处理,可以让程序恢复正常运行
local ERROR = "ERROR"

-- 程序运行时发生不可预料的严重错误,一般将终止程序运行
local FATAL = "FATAL"
--------------------------------------------------------------------------------
local LEVEL = {
	[OFF]   = 100,
	[DEBUG] = 1,
	[INFO]  = 2,
	[WARN]  = 3,
	[ERROR] = 4,
	[FATAL] = 5,
	[ALL]   = 0,
}
--------------------------------------------------------------------------------
local function log_setLevel(logger, level)
	assert(LEVEL[level], string.format("undefined level `%s'", tostring(level)))
	logger.level = level
end
--------------------------------------------------------------------------------
local function log_output(logger, level, message, ...)
	local status, result =  safeCall(function()
			assert(LEVEL[level], string.format("undefined level `%s'", tostring(level)))

			if LEVEL[level] < LEVEL[logger.level] then
				return false
			end

			local codeInfo = "\n"..getCurrentCodeInf(9)

			return logger:append(level, string.format(tostring(message), unpack(arg)) .. codeInfo)
		end)

	if status ~= true then
		print("----------------------logger error---------------------")
		print("message:", tostring(message))
		print("parameter:", unpack(arg))
		print(debug.traceback())
		print("----------------------logger error---------------------")
	end

	return status
end
--------------------------------------------------------------------------------
function log_new(_, append)
	if type(append) ~= "function" then
		return nil, "Appender must be a function."
	end

	local logger = {
		level = DEBUG,
		setLevel = log_setLevel,
		append = append
	}

	logger.isDebug = function(logger) return LEVEL[DEBUG] >= LEVEL[logger.level] end
	logger.isInfo = function(logger) return LEVEL[INFO] >= LEVEL[logger.level] end
	logger.isWarn = function(logger) return LEVEL[WARN] >= LEVEL[logger.level] end
	logger.isError = function(logger) return LEVEL[ERROR] >= LEVEL[logger.level] end
	logger.isFatal = function(logger) return LEVEL[FATAL] >= LEVEL[logger.level] end

	logger.debug = function(logger, message, ...) return log_output(logger, DEBUG, message, ...) end
	logger.info = function(logger, message, ...) return log_output(logger, INFO, message, ...) end
	logger.warn = function(logger, message, ...) return log_output(logger, WARN, message, ...) end
	logger.error = function(logger, message, ...) return log_output(logger, ERROR, message, ...) end
	logger.fatal = function(logger, message, ...) return log_output(logger, FATAL, message, ...) end

	return logger
end
--------------------------------------------------------------------------------
Logger = define({ __call = log_new }, {
	OFF   = OFF,
	ALL   = ALL,
	DEBUG = DEBUG,
	INFO  = INFO,
	WARN  = WARN,
	ERROR = ERROR,
	FATAL = FATAL,

	--[[
		%d 输出日期
		%p 输出优先级等级
		%m 输出消息
	--]]
	log = function(pattern, dt, level, message)
		local logMsg = pattern or "%d %p %m"
		message = string.gsub(message, "%%", "%%%%")
		logMsg = string.gsub(logMsg, "%%d", dt)
		logMsg = string.gsub(logMsg, "%%p", level)
		logMsg = string.gsub(logMsg, "%%m", message)
		return logMsg
	end
})

--------------------------------------------------------------------------------
local logger
function Logger.getLogger()
	if not logger then
		require "logger.console"
		logger = Logger.console()
	end
	return logger
end
