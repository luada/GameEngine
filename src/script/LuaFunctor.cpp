#define LUA_FUNCTOR_IMPL
#include "LuaFunctor.h"
#include "ScriptUnit.h"
#include "common/Any.h"

#pragma warning(disable : 4102 )
#pragma warning(disable : 4244 )

TypeNull NIL;

template<class T>
bool GetLuaValue(lua_State* L, int index, T& value)
{
	int type = lua_type(L, index);
	if (type == LUA_TUSERDATA || type == LUA_TLIGHTUSERDATA)
	{
		value = (T)(tolua_tousertype(L, index, NULL));
		return true;
	} 
	else
	{
		return false; 
	}
}

template<> bool GetLuaValue( lua_State* L, int index, const char* &value )
{
	if (lua_isstring(L, index))
	{
		value = lua_tostring(L, index);
		return true;
	} 
	else
	{
		return false;
	}
}

template<> bool GetLuaValue(lua_State* L, int index, lua_Number& value)
{
	if (lua_isnumber(L, index))
	{
		value = lua_tonumber(L, index);
		return true;
	} 
	else
	{
		return false;
	}
}

template <class Value>
bool GetLuaTable(lua_State* L, short tableIndex, std::vector<Value>& result)
{
	if (!lua_istable(L, tableIndex)) 
	{
		return false;
	}
	CLuaTopStackRecover topStackRecover(L);
	lua_checkstack(L, 2);
	lua_pushnil(L);
	if (tableIndex < 0)
	{
		//because we have push a NIL value to the stack
		--tableIndex;
	}
	while (lua_next(L, tableIndex))
	{
		if(lua_isnumber(L, -2))
		{
			Value value;
			if(GetLuaValue(L, -1, value))
			{
				result.push_back(value);
			}
		}

		lua_pop(L, 1);
	}
	return true;
}

bool GetLuaString(lua_State* L, int iStackIndex, const char* & result)
{
	if (lua_isstring(L, iStackIndex))
	{
		result = lua_tostring(L, iStackIndex);
		lua_pop(L, 1);
		return true;
	} 
	else 
	{
		lua_pop(L, 1);
		return false;
	}
}

bool GetLuaNumber(lua_State* L, int iStackIndex, lua_Number& result)
{
	if (lua_isnumber(L, iStackIndex))
	{
		result = lua_tonumber(L, iStackIndex);
		lua_pop(L, 1);
		return true;
	} 
	else
	{
		lua_pop(L, 1);
		return false;
	}
}

bool GetPropValueFromLua( lua_State* L, CAny& value )
{
	static const int iParamPos = 3;
	switch (lua_type(L, iParamPos))
	{
	case LUA_TBOOLEAN:
		value = lua_toboolean(L, iParamPos);
		break;
	case LUA_TNUMBER:
		value = luaL_checknumber(L, iParamPos);
		break;
	case LUA_TSTRING:
		value = luaL_checkstring(L, iParamPos);
		break;
	case LUA_TNIL:
	case LUA_TNONE:
		{
			luaL_error(L, "Property is Null");
			return false;
		}
		break;
	case LUA_TTABLE:
		{
			luaL_error(L, "can't support table property value!");
			return false;
		}
		break;
	default:
		{
			luaL_error(L, "property type is not supported now!");
			return false;
		}
		break;
	}
	return true;
}

bool FindMethod( lua_State* L, const std::string& handlerName )
{
	//format for handlerName: global.*(table).function
	//				  Notice: *(table), none or more tables

	CLuaTopStackRecover topStackRecover(L);
	// do we have any dots in the handler name? if so we grab the function as a table field
	std::string::size_type i = handlerName.find_first_of('.');
	if (i!=std::string::npos)
	{
		// split the rest of the string up in parts seperated by '.'
		// TODO: count the dots and size the vector accordingly from the beginning.
		std::vector<std::string> parts;
		std::string::size_type start = 0;
		do
		{
			parts.push_back(handlerName.substr(start,i-start));
			start = i+1;
			i = handlerName.find_first_of('.',start);
		} while(i != std::string::npos);

		// add last part
		parts.push_back(handlerName.substr(start));

		// first part is the global
		lua_getglobal(L, parts[0].c_str());
		if (!lua_istable(L,-1))
		{
//			DebugConsole::out("Unable to get : '%s'\n", handlerName.c_str());
			return false;
		}

		// if there is more than two parts, we have more tables to go through
		std::vector<std::string>::size_type visz = parts.size();
		if (visz-- > 2) // avoid subtracting one later on
		{
			// go through all the remaining parts to (hopefully) have a valid Lua function in the end
			std::vector<std::string>::size_type vi = 1;
			while (vi<visz)
			{
				// push key, and get the next table
				lua_pushstring(L,parts[vi].c_str());
				lua_gettable(L,-2);
				if (!lua_istable(L,-1))
				{
//					DebugConsole::out("Unable to get : '%s'\n", handlerName.c_str());
					return false;
				}
				// get rid of the last table and move on
				lua_remove(L,-2);
				vi++;
			}
		}

		// now we are ready to get the function to call ... phew :)
		lua_pushstring(L,parts[visz].c_str());
		lua_gettable(L,-2);
		lua_remove(L,-2); // get rid of the table
	}
	// just a regular global function
	else
	{
		lua_getglobal(L, handlerName.c_str());
	}
	// is it a function
	if (!lua_isfunction(L,-1))
	{
//		DebugConsole::out("Unable to find the function: '%s'\n", handlerName.c_str());
		return false;
	} 
	else 
	{
		topStackRecover.DisableRecover();
		return true;
	}
}

int PushMethod(lua_State* L, const std::string& handlerName)
{
	if (FindMethod(L, handlerName))
	{
		int index = luaL_ref(L, LUA_REGISTRYINDEX);
		return index;
	} 
	else 
	{
		return LUA_NOREF;
	}
}

