--EventSetDoer.lua

require("event.EventSetListener")

EventSetDoer = class(nil,EventSetListener)

function EventSetDoer:__init()
	self._doer = {}
end

function EventSetDoer:getEventsID()
	local evtSet = {}
	for i,_ in pairs(self._doer) do
		table.insert(evtSet, i)
	end
	return evtSet
end

function EventSetDoer:getEventsCount()
	return table.size(self._doer)
end

function EventSetDoer:action(evt)
	local id = evt:getID()
	local doer = self._doer[id]	
	if doer then
		doer(self,evt)
	else
		Logger.warn(string.format("[EventSetDoer]: this event(%x) has not been supported yet",id))
	end
end
