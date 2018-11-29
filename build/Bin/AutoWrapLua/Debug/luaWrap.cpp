/*
** Lua binding: main
** Generated automatically by tolua++-1.0.92 on 11/19/10 20:35:13.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_main_open (lua_State* tolua_S);

#include "a.h"
#include "b.h"
#include "c\C.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_A (lua_State* tolua_S)
{
 A* self = (A*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_C (lua_State* tolua_S)
{
 C* self = (C*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_B (lua_State* tolua_S)
{
 B* self = (B*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"A");
 tolua_usertype(tolua_S,"C");
 tolua_usertype(tolua_S,"B");
}

/* method: new of class  A */
#ifndef TOLUA_DISABLE_tolua_main_A_new00
static int tolua_main_A_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"A",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   A* tolua_ret = (A*)  Mtolua_new((A)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"A");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  A */
#ifndef TOLUA_DISABLE_tolua_main_A_new00_local
static int tolua_main_A_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"A",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   A* tolua_ret = (A*)  Mtolua_new((A)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"A");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  A */
#ifndef TOLUA_DISABLE_tolua_main_A_delete00
static int tolua_main_A_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"A",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  A* self = (A*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setA of class  A */
#ifndef TOLUA_DISABLE_tolua_main_A_setA00
static int tolua_main_A_setA00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"A",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  A* self = (A*)  tolua_tousertype(tolua_S,1,0);
  int v = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setA'", NULL);
#endif
  {
   self->setA(v);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setA'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getA of class  A */
#ifndef TOLUA_DISABLE_tolua_main_A_getA00
static int tolua_main_A_getA00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"A",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  A* self = (A*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getA'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getA();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getA'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Set */
#ifndef TOLUA_DISABLE_tolua_main_Set00
static int tolua_main_Set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int v = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   Set(v);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  B */
#ifndef TOLUA_DISABLE_tolua_main_B_new00
static int tolua_main_B_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"B",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   B* tolua_ret = (B*)  Mtolua_new((B)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"B");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  B */
#ifndef TOLUA_DISABLE_tolua_main_B_new00_local
static int tolua_main_B_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"B",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   B* tolua_ret = (B*)  Mtolua_new((B)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"B");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  B */
#ifndef TOLUA_DISABLE_tolua_main_B_delete00
static int tolua_main_B_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"B",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  B* self = (B*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setB of class  B */
#ifndef TOLUA_DISABLE_tolua_main_B_setB00
static int tolua_main_B_setB00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"B",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  B* self = (B*)  tolua_tousertype(tolua_S,1,0);
  int v = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setB'", NULL);
#endif
  {
   self->setB(v);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setB'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getB of class  B */
#ifndef TOLUA_DISABLE_tolua_main_B_getB00
static int tolua_main_B_getB00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"B",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  B* self = (B*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getB'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getB();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getB'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  C */
#ifndef TOLUA_DISABLE_tolua_main_C_new00
static int tolua_main_C_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"C",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   C* tolua_ret = (C*)  Mtolua_new((C)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"C");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  C */
#ifndef TOLUA_DISABLE_tolua_main_C_new00_local
static int tolua_main_C_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"C",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   C* tolua_ret = (C*)  Mtolua_new((C)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"C");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  C */
#ifndef TOLUA_DISABLE_tolua_main_C_delete00
static int tolua_main_C_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"C",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  C* self = (C*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setC of class  C */
#ifndef TOLUA_DISABLE_tolua_main_C_setC00
static int tolua_main_C_setC00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"C",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  C* self = (C*)  tolua_tousertype(tolua_S,1,0);
  int v = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setC'", NULL);
#endif
  {
   self->setC(v);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setC'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getC of class  C */
#ifndef TOLUA_DISABLE_tolua_main_C_getC00
static int tolua_main_C_getC00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"C",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  C* self = (C*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getC'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getC();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getC'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_main_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"A","A","",tolua_collect_A);
  #else
  tolua_cclass(tolua_S,"A","A","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"A");
   tolua_function(tolua_S,"new",tolua_main_A_new00);
   tolua_function(tolua_S,"new_local",tolua_main_A_new00_local);
   tolua_function(tolua_S,".call",tolua_main_A_new00_local);
   tolua_function(tolua_S,"delete",tolua_main_A_delete00);
   tolua_function(tolua_S,"setA",tolua_main_A_setA00);
   tolua_function(tolua_S,"getA",tolua_main_A_getA00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"Set",tolua_main_Set00);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"B","B","A",tolua_collect_B);
  #else
  tolua_cclass(tolua_S,"B","B","A",NULL);
  #endif
  tolua_beginmodule(tolua_S,"B");
   tolua_function(tolua_S,"new",tolua_main_B_new00);
   tolua_function(tolua_S,"new_local",tolua_main_B_new00_local);
   tolua_function(tolua_S,".call",tolua_main_B_new00_local);
   tolua_function(tolua_S,"delete",tolua_main_B_delete00);
   tolua_function(tolua_S,"setB",tolua_main_B_setB00);
   tolua_function(tolua_S,"getB",tolua_main_B_getB00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"C","C","B",tolua_collect_C);
  #else
  tolua_cclass(tolua_S,"C","C","B",NULL);
  #endif
  tolua_beginmodule(tolua_S,"C");
   tolua_function(tolua_S,"new",tolua_main_C_new00);
   tolua_function(tolua_S,"new_local",tolua_main_C_new00_local);
   tolua_function(tolua_S,".call",tolua_main_C_new00_local);
   tolua_function(tolua_S,"delete",tolua_main_C_delete00);
   tolua_function(tolua_S,"setC",tolua_main_C_setC00);
   tolua_function(tolua_S,"getC",tolua_main_C_getC00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_main (lua_State* tolua_S) {
 return tolua_main_open(tolua_S);
};
#endif

