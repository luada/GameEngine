require "base.class"

--------------------------------------------------------------------------------

Event = class()

function Event:__init()
	self._handlers = {}
	setmetatable(self._handlers, {__mode = "v"})
end

function Event:__release()
	self:clearHandlers()
end

function Event:fire(eventKey, ...)
	--[[
	���������¼�
	@param	eventKey: �¼�����
	@type	eventKey: string
	@param	arg: ���������Ĳ����б�
	@type	arg: ����ʵ�ʵļ�����������
	--]]
	for _, v in ipairs(self._handlers) do
		v:onEvent(eventKey, ...)
	end
end

function Event:addHandler(handler)
	--[[
	�жϴ����¼����Ƿ�handler��������
	@param	handler: ��Ӧ�¼��Ķ���
	@type	handler: object of ScriptObject
	--]]
	table.insert(self._handlers, handler)
end

function Event:removeHandler(handler)
	--[[
	��handler����ӱ����¼���ɾ��
	@param	handler: ��Ӧ�¼��ļ�������
	@type	handler: object of ScriptObject
	--]]
	table.removeValue(self._handlers, handler)
end

function Event:clearHandlers()
	--[[
	��ձ����¼������м�������
	--]]
	table.clear(self._handlers)
	self._handlers = nil
end

function Event:hasHandlers()
	--[[
	�жϱ����¼����Ƿ���ڼ�������
	--]]
	return self._handlers ~= nil and table.getn(self._handlers) > 0
end

--------------------------------------------------------------------------------

ECenter = {}
ECenter.events = {}

function ECenter.registerEvent(eventKey, handler)
	--[[
	ע��һ���¼�
	@param  eventKey: �¼�����
	@type	eventKey: string
	@param	handler: ��Ӧ�¼��ļ�������
	@type	handler: object of ScriptObject
	--]]
	local event = ECenter.events[eventKey]
	if event == nil then
		event = Event()
		ECenter.events[eventKey] = event
	end
	event:addHandler(handler)
end

function ECenter.deregisterEvent(eventKey, handler)
	--[[
	ע��һ���¼�
	@param  eventKey: �¼�����
	@type	eventKey: string
	@param	handler: ��Ӧ�¼��ļ�������
	@type	handler: object of ScriptObject
	--]]
	local event = ECenter.events[eventKey]
	if event ~= nil then
		event:removeHandler(handler)
		if not event:hasHandlers() then
			release(event)
			ECenter.events[eventKey] = nil
		end
	end
end

function ECenter.fireEvent(eventKey, ...)
	--[[
	����һ���¼�
	@param	eventKey: �¼�����
	@type	eventKey: string
	@param	arg: ���������Ĳ����б�
	@type	arg: ����ʵ�ʵĴ�����������
	--]]
	local event = ECenter.events[eventKey]
	if event ~= nil then
		event:fire(eventKey, ...)
	end
end

--------------------------------------------------------------------------------