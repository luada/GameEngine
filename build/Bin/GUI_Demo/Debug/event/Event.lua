--[[Event.lua
�¼���Ϣ�Ļ���.���ڶ����¼���ID,�¼��ķ������,�¼�Դ����

Exported API:
	Event(id, group, source)

	event:getID()
	event:getGroup()
	event:getSource()

Example:

--]]

require "base.class"

Event = class()

local prop = Property(Event)
prop:reader("ID") --�¼���ID
prop:reader("group") --�¼��ķ������
prop:reader("source") --�¼�Դ����

function Event:__init(id, group, source)
	local this = prop[self]
	this.ID = id
	this.group = group
	this.source = source
end

function Event:__release()
	local this = prop[self]
	this.ID = nil
	this.group = nil
	this.source = nil
end

function Event:assign(event)
	if instanceof(event, Event) then
		local this = prop[self]
		this.id = event:getID()
		this.group = event:getGroup()
		this.source = event:getSource()

		self.getParamCount = event.getParamCount
		self.getParams = event.getParams
	end
end

function Event:assignTo(event)
	if instanceof(event, Event) then
		event:assign(self)
	end
end

function Event:writeObject()
	local data={}
	data.ID=string.format("0x%x",toString(self:getID()))
	data.params=self:getParams()
	return data
end

function Event:toString()
	return toString(self:writeObject())
end