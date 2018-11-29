--[[ActionListener.lua
动作监听接口

Exported API:
	ActionListener.action(event) 执行监听动作

Example:

--]]

require "base.class"

ActionListener = interface(nil, "action")