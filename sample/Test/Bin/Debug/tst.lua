--[[

require "base.logger"
require "base.class"


local logger = Logger.getLogger()



local Object = class()

function Object:__init(id)
	logger:info("object.init id = %d", id)
	self.id = id
	self.mm = "hello"
end

function Object:getId()
	return self.id
end

function Object:printInfo()
	print(self.mm)
end

o = Object(44)

print(o:getId())

o:printInfo()




require "base.serialize"


function traceback()
	local level = 1
	while true do
		local info = debug.getinfo(level, "nfSlu")
		if not info then break end
		if info.what == "C" then -- is a C function?
			print(level, "C function")
		else -- a Lua function
			local strInfo = string.format("file:%s line:%d function:%s",
							info.source, info.currentline, info.name or "")
			print(info.name)
		end
		level = level + 1
	end
end






function foo()
    for i,v in pairs(debug.getinfo(1)) do
        print(i,v)
    end
end



traceback()

--]]

require "base.serialize"


function MyPackLoader( moduleName )

	return loadstring( G_GetPackData( moduleName ) );

end



print(package.loaders[1])


