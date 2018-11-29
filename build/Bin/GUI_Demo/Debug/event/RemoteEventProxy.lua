--RemoteEventProxy.lua
require("base.util")
require ("event.EventFactory")

RemoteEventProxy = {}

local evtFactory = EventFactory.getInstance()
local pLua2LuaEngine	= nil

function RemoteEventProxy.send(event,valueType)
	if event then
		local eEventID		= event:getID()
		local src		= event:getSource()
		local params		= event:getParams()
		local count		= event:getParamCount()
		local hlink		= params[count]
		local hlinkContext	= tolua.cast(hlink, "_ClientLinkContext")
		local srcID		= nil
		local _params={}
		local res=false
		if not pLua2LuaEngine then
			pLua2LuaEngine=g_clientEngine:getNetwork():getLua2LuaEngine()
		end
		if eEventID then
			--client rpc event send
			if not hlinkContext then
				hlink=nil
				_params=params
			else
				for i,v in pairs( params ) do
					if (i~=count) then _params[i]=v end
				end
			end
			if (toNumber(src)~=-1) then
				Logger.warn(string.format("客户端发送事件>>>>>>>[RemoteEventProxy] A remote event(0x%x) %s,%s received #1", eEventID,toString(event),toString(event:getParams())))
			end
			if (valueType) then
				res=pLua2LuaEngine:pureCall(eEventID,toNumber(src),valueType,hlink,unpack(_params))
			else
				res=pLua2LuaEngine:call(eEventID,toNumber(src),hlink, unpack(_params))
			end
		end
		if not res then
			Logger.error(string.format("RemoteEventProxy.send() failed,because eEventID  or srcID  or target link is nil %s",debug.traceback()))
		end
	end
end

function RemoteEventProxy.receive(eEventID,srcID,hSlink,...)
	if (srcID~=-1) then
		Logger.warn(string.format("客户端接收事件>>>>>>>[RemoteEventProxy] A remote event(0x%x) fired#1", eEventID))
	end
	if eEventID then
		local tsize=table.size(arg)
		arg[tsize]=hSlink
		arg.n=arg.n+1
		local event = evtFactory:getEvent(eEventID, srcID, unpack(arg))
--		local record=GameRecorder.getInstance()
--		if record:isRecording() then		--录制时收录
--			record:recordBack(event)
--		end
--		local play=GamePlayer.getInstance()
--		if play:isPlaying() then		--播放时收录
--			play:recordBack(event)
--		end
		gEventMgr:fireEvent(event)

--		Logger.info(string.format("[RemoteEventProxy] A remote event(0x%x) fired#2", eEventID))
	end
--	Logger.info(string.format("[RemoteEventProxy] A remote event(0x%x) fired arg %s", eEventID,toString(arg)))
end



Logger.info("load RemoteEventProxy Module")

