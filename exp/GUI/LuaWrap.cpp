/*
** Lua binding: GUI
** Generated automatically by tolua++-1.0.92 on 12/08/10 14:14:32.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_GUI_open (lua_State* tolua_S);

#include "Align.h"
#include "Prerequest.h"
#include "Macros.h"
#include "Diagnostic.h"
#include "Utility.h"
#include <map>
#include <vector>
#include "Button.h"
#include "StaticText.h"
#include "ClipboardManager.h"
#include "Instance.h"
#include "Types.h"
#include "UString.h"
#include "Colour.h"
#include "ComboBox.h"
#include "Edit.h"
#include "List.h"
#include "Any.h"
#include "EventPair.h"
#include "ControllerFadeAlpha.h"
#include "TextChangeHistory.h"
#include "TextIterator.h"
#include "ScrollViewBase.h"
#include "Gui.h"
#include "XmlDocument.h"
#include "IWidgetCreator.h"
#include "IUnlinkWidget.h"
#include "Widget.h"
#include "HScroll.h"
#include "VScroll.h"
#include "InputDefine.h"
#include "ItemBox.h"
#include "DDContainer.h"
#include "IBItemInfo.h"
#include "LanguageManager.h"
#include "Delegate.h"
#include "LayerManager.h"
#include "Enumerator.h"
#include "ResourceManager.h"
#include "ILayer.h"
#include "LayoutManager.h"
#include "WidgetDefines.h"
#include "ListBox.h"
#include "ListCtrl.h"
#include "MenuBar.h"
#include "MenuCtrl.h"
#include "MenuItemType.h"
#include "MenuItem.h"
#include "Message.h"
#include "Window.h"
#include "ResourceImageSet.h"
#include "MessageStyle.h"
#include "MultiList.h"
#include "BiIndexBase.h"
#include "PopupMenu.h"
#include "Progress.h"
#include "ScrollView.h"
#include "StaticImage.h"
#include "ImageInfo.h"
#include "Guid.h"
#include "Tab.h"
#include "TabItem.h"
#include "TCoord.h"
#include "TPoint.h"
#include "TSize.h"
#include "TRect.h"
#include "UIScriptObject.h"
#include "WidgetEvent.h"
#include "script/ScriptUnit.h"
#include "common/Macro.h"
#include "LogManager.h"
#include <iterator>
#include <string>
#include <stdexcept>
#include "ICroppedRectangle.h"
#include "ISubWidgetRect.h"
#include "ISubWidgetText.h"
#include "LayerItem.h"
#include "WidgetUserData.h"
#include "ResourceSkin.h"
#include "IObject.h"
#include "WidgetStyle.h"
using namespace GUI;
using namespace types;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_GUI__MouseButton (lua_State* tolua_S)
{
 GUI::MouseButton* self = (GUI::MouseButton*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_GUI__types__TPoint_float_ (lua_State* tolua_S)
{
 GUI::types::TPoint<float>* self = (GUI::types::TPoint<float>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_GUI__Align (lua_State* tolua_S)
{
 GUI::Align* self = (GUI::Align*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_GUI__Colour (lua_State* tolua_S)
{
 GUI::Colour* self = (GUI::Colour*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_GUI__types__TCoord_int_ (lua_State* tolua_S)
{
 GUI::types::TCoord<int>* self = (GUI::types::TCoord<int>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_GUI__types__TRect_int_ (lua_State* tolua_S)
{
 GUI::types::TRect<int>* self = (GUI::types::TRect<int>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_TCoord_int_ (lua_State* tolua_S)
{
 TCoord<int>* self = (TCoord<int>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_GUI__KeyCode (lua_State* tolua_S)
{
 GUI::KeyCode* self = (GUI::KeyCode*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_GUI__types__TRect_float_ (lua_State* tolua_S)
{
 GUI::types::TRect<float>* self = (GUI::types::TRect<float>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_GUI__WidgetStyle (lua_State* tolua_S)
{
 GUI::WidgetStyle* self = (GUI::WidgetStyle*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_MenuItemType (lua_State* tolua_S)
{
 MenuItemType* self = (MenuItemType*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_GUI__MessageBoxStyle (lua_State* tolua_S)
{
 GUI::MessageBoxStyle* self = (GUI::MessageBoxStyle*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_GUI__types__TCoord_float_ (lua_State* tolua_S)
{
 GUI::types::TCoord<float>* self = (GUI::types::TCoord<float>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_GUI__types__TSize_float_ (lua_State* tolua_S)
{
 GUI::types::TSize<float>* self = (GUI::types::TSize<float>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_GUI__types__TSize_int_ (lua_State* tolua_S)
{
 GUI::types::TSize<int>* self = (GUI::types::TSize<int>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_GUI__types__TPoint_int_ (lua_State* tolua_S)
{
 GUI::types::TPoint<int>* self = (GUI::types::TPoint<int>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_GUI__UString (lua_State* tolua_S)
{
 GUI::UString* self = (GUI::UString*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_TSize_int_ (lua_State* tolua_S)
{
 TSize<int>* self = (TSize<int>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"DDContainer");
 tolua_usertype(tolua_S,"GUI::types::TPoint<float>");
 tolua_usertype(tolua_S,"GUI::Align");
 tolua_usertype(tolua_S,"GUI::Colour");
 tolua_usertype(tolua_S,"GUI::types::TCoord<float>");
 tolua_usertype(tolua_S,"GUI::types::TRect<int>");
 tolua_usertype(tolua_S,"ICroppedRectangle");
 tolua_usertype(tolua_S,"GUI::VectorWidgetPtr");
 tolua_usertype(tolua_S,"GUI::Gui");
 tolua_usertype(tolua_S,"GUI::ListCtrl");
 tolua_usertype(tolua_S,"GUI::Tab");
 tolua_usertype(tolua_S,"GUI::HScroll");
 tolua_usertype(tolua_S,"GUI::MenuBar");
 tolua_usertype(tolua_S,"IWidgetCreator");
 tolua_usertype(tolua_S,"IObject");
 tolua_usertype(tolua_S,"GUI::StaticText");
 tolua_usertype(tolua_S,"GUI::types::TSize<float>");
 tolua_usertype(tolua_S,"GUI::types::TSize<int>");
 tolua_usertype(tolua_S,"delegates::IDelegateUnlink");
 tolua_usertype(tolua_S,"GUI::Progress");
 tolua_usertype(tolua_S,"ScrollViewBase");
 tolua_usertype(tolua_S,"GUI::UIScriptObject");
 tolua_usertype(tolua_S,"GUI::Message");
 tolua_usertype(tolua_S,"TSize<int>");
 tolua_usertype(tolua_S,"GUI::List");
 tolua_usertype(tolua_S,"GUI::MultiList");
 tolua_usertype(tolua_S,"TCoord<float>");
 tolua_usertype(tolua_S,"GUI::ComboBox");
 tolua_usertype(tolua_S,"GUI::Edit");
 tolua_usertype(tolua_S,"GUI::StaticImage");
 tolua_usertype(tolua_S,"BiIndexBase");
 tolua_usertype(tolua_S,"GUI::TabItem");
 tolua_usertype(tolua_S,"GUI::WidgetStyle");
 tolua_usertype(tolua_S,"GUI::Button");
 tolua_usertype(tolua_S,"GUI::Window");
 tolua_usertype(tolua_S,"IUnlinkWidget");
 tolua_usertype(tolua_S,"GUI::LayoutManager");
 tolua_usertype(tolua_S,"GUI::Widget");
 tolua_usertype(tolua_S,"GUI::MouseButton");
 tolua_usertype(tolua_S,"GUI::PopupMenu");
 tolua_usertype(tolua_S,"Guid");
 tolua_usertype(tolua_S,"std::vector<GUI::Widget*>");
 tolua_usertype(tolua_S,"GUI::types::TCoord<int>");
 tolua_usertype(tolua_S,"ResourceImageSetPtr");
 tolua_usertype(tolua_S,"LayerItem");
 tolua_usertype(tolua_S,"GUI::UserData");
 tolua_usertype(tolua_S,"TRect<int>");
 tolua_usertype(tolua_S,"GUI::types::TRect<float>");
 tolua_usertype(tolua_S,"GUI::LanguageManager");
 tolua_usertype(tolua_S,"GUI::ClipboardManager");
 tolua_usertype(tolua_S,"TCoord<int>");
 tolua_usertype(tolua_S,"GUI::KeyCode");
 tolua_usertype(tolua_S,"const");
 tolua_usertype(tolua_S,"GUI::ItemBox");
 tolua_usertype(tolua_S,"MenuItemType");
 tolua_usertype(tolua_S,"GUI::MenuItem");
 tolua_usertype(tolua_S,"GUI::LayerManager");
 tolua_usertype(tolua_S,"GUI::MenuCtrl");
 tolua_usertype(tolua_S,"GUI::ListBox");
 tolua_usertype(tolua_S,"CScriptObject");
 tolua_usertype(tolua_S,"GUI::VScroll");
 tolua_usertype(tolua_S,"WidgetEvent");
 tolua_usertype(tolua_S,"GUI::MessageBoxStyle");
 tolua_usertype(tolua_S,"GUI::ScrollView");
 tolua_usertype(tolua_S,"GUI::UString");
 tolua_usertype(tolua_S,"GUI::types::TPoint<int>");
}

/* method: new of class  GUI::Align */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Align_new00
static int tolua_GUI_GUI_Align_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::Align",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Align::Enum value = ((GUI::Align::Enum) (int)  tolua_tonumber(tolua_S,2,GUI::Align::Default));
  {
   GUI::Align* tolua_ret = (GUI::Align*)  Mtolua_new((GUI::Align)(value));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Align");
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

/* method: new_local of class  GUI::Align */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Align_new00_local
static int tolua_GUI_GUI_Align_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::Align",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Align::Enum value = ((GUI::Align::Enum) (int)  tolua_tonumber(tolua_S,2,GUI::Align::Default));
  {
   GUI::Align* tolua_ret = (GUI::Align*)  Mtolua_new((GUI::Align)(value));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Align");
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

/* method: IsHCenter of class  GUI::Align */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Align_IsHCenter00
static int tolua_GUI_GUI_Align_IsHCenter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::Align",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::Align* self = (const GUI::Align*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsHCenter'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsHCenter();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsHCenter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsVCenter of class  GUI::Align */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Align_IsVCenter00
static int tolua_GUI_GUI_Align_IsVCenter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::Align",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::Align* self = (const GUI::Align*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsVCenter'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsVCenter();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsVCenter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsCenter of class  GUI::Align */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Align_IsCenter00
static int tolua_GUI_GUI_Align_IsCenter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::Align",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::Align* self = (const GUI::Align*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsCenter'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsCenter();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsCenter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsLeft of class  GUI::Align */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Align_IsLeft00
static int tolua_GUI_GUI_Align_IsLeft00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::Align",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::Align* self = (const GUI::Align*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsLeft'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsLeft();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsLeft'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsRight of class  GUI::Align */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Align_IsRight00
static int tolua_GUI_GUI_Align_IsRight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::Align",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::Align* self = (const GUI::Align*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsRight'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsRight();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsRight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsHStretch of class  GUI::Align */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Align_IsHStretch00
static int tolua_GUI_GUI_Align_IsHStretch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::Align",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::Align* self = (const GUI::Align*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsHStretch'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsHStretch();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsHStretch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsTop of class  GUI::Align */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Align_IsTop00
static int tolua_GUI_GUI_Align_IsTop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::Align",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::Align* self = (const GUI::Align*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsTop'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsTop();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsTop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsBottom of class  GUI::Align */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Align_IsBottom00
static int tolua_GUI_GUI_Align_IsBottom00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::Align",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::Align* self = (const GUI::Align*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsBottom'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsBottom();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsBottom'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsVStretch of class  GUI::Align */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Align_IsVStretch00
static int tolua_GUI_GUI_Align_IsVStretch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::Align",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::Align* self = (const GUI::Align*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsVStretch'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsVStretch();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsVStretch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsStretch of class  GUI::Align */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Align_IsStretch00
static int tolua_GUI_GUI_Align_IsStretch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::Align",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::Align* self = (const GUI::Align*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsStretch'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsStretch();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsStretch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsDefault of class  GUI::Align */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Align_IsDefault00
static int tolua_GUI_GUI_Align_IsDefault00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::Align",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::Align* self = (const GUI::Align*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsDefault'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsDefault();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsDefault'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsHRelative of class  GUI::Align */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Align_IsHRelative00
static int tolua_GUI_GUI_Align_IsHRelative00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::Align",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::Align* self = (const GUI::Align*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsHRelative'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsHRelative();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsHRelative'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsVRelative of class  GUI::Align */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Align_IsVRelative00
static int tolua_GUI_GUI_Align_IsVRelative00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::Align",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::Align* self = (const GUI::Align*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsVRelative'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsVRelative();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsVRelative'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsRelative of class  GUI::Align */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Align_IsRelative00
static int tolua_GUI_GUI_Align_IsRelative00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::Align",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::Align* self = (const GUI::Align*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsRelative'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsRelative();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsRelative'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Parse of class  GUI::Align */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Align_Parse00
static int tolua_GUI_GUI_Align_Parse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::Align",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   GUI::Align tolua_ret = (GUI::Align)  GUI::Align::Parse(value);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::Align)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::Align");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::Align));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::Align");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Parse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Print of class  GUI::Align */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Align_Print00
static int tolua_GUI_GUI_Align_Print00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::Align",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::Align* self = (const GUI::Align*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Print'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->Print();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Print'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetButtonPressed of class  GUI::Button */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Button_SetButtonPressed00
static int tolua_GUI_GUI_Button_SetButtonPressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Button",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Button* self = (GUI::Button*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetButtonPressed'", NULL);
#endif
  {
   self->SetButtonPressed(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetButtonPressed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetButtonPressed of class  GUI::Button */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Button_GetButtonPressed00
static int tolua_GUI_GUI_Button_GetButtonPressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Button",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Button* self = (GUI::Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetButtonPressed'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetButtonPressed();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetButtonPressed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetStateCheck of class  GUI::Button */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Button_SetStateCheck00
static int tolua_GUI_GUI_Button_SetStateCheck00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Button",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Button* self = (GUI::Button*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetStateCheck'", NULL);
#endif
  {
   self->SetStateCheck(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetStateCheck'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetStateCheck of class  GUI::Button */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Button_GetStateCheck00
static int tolua_GUI_GUI_Button_GetStateCheck00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Button",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Button* self = (GUI::Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetStateCheck'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetStateCheck();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetStateCheck'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetImageIndex of class  GUI::Button */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Button_SetImageIndex00
static int tolua_GUI_GUI_Button_SetImageIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Button",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Button* self = (GUI::Button*)  tolua_tousertype(tolua_S,1,0);
    int value = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetImageIndex'", NULL);
#endif
  {
   self->SetImageIndex(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetImageIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetImageIndex of class  GUI::Button */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Button_GetImageIndex00
static int tolua_GUI_GUI_Button_GetImageIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Button",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Button* self = (GUI::Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetImageIndex'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetImageIndex();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetImageIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetModeImage of class  GUI::Button */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Button_SetModeImage00
static int tolua_GUI_GUI_Button_SetModeImage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Button",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Button* self = (GUI::Button*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetModeImage'", NULL);
#endif
  {
   self->SetModeImage(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetModeImage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetModeImage of class  GUI::Button */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Button_GetModeImage00
static int tolua_GUI_GUI_Button_GetModeImage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Button",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Button* self = (GUI::Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetModeImage'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetModeImage();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetModeImage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetStaticImage of class  GUI::Button */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Button_GetStaticImage00
static int tolua_GUI_GUI_Button_GetStaticImage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Button",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Button* self = (GUI::Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetStaticImage'", NULL);
#endif
  {
   GUI::StaticImage* tolua_ret = (GUI::StaticImage*)  self->GetStaticImage();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::StaticImage");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetStaticImage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetProperty of class  GUI::Button */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Button_SetProperty00
static int tolua_GUI_GUI_Button_SetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Button",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Button* self = (GUI::Button*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetProperty'", NULL);
#endif
  {
   self->SetProperty(key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Instance of class  GUI::ClipboardManager */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ClipboardManager_Instance00
static int tolua_GUI_GUI_ClipboardManager_Instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::ClipboardManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GUI::ClipboardManager& tolua_ret = (GUI::ClipboardManager&)  GUI::ClipboardManager::Instance();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"GUI::ClipboardManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Instance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetClipboardData of class  GUI::ClipboardManager */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ClipboardManager_SetClipboardData00
static int tolua_GUI_GUI_ClipboardManager_SetClipboardData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ClipboardManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ClipboardManager* self = (GUI::ClipboardManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string type = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string data = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetClipboardData'", NULL);
#endif
  {
   self->SetClipboardData(type,data);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetClipboardData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearClipboardData of class  GUI::ClipboardManager */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ClipboardManager_ClearClipboardData00
static int tolua_GUI_GUI_ClipboardManager_ClearClipboardData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ClipboardManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ClipboardManager* self = (GUI::ClipboardManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string type = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearClipboardData'", NULL);
#endif
  {
   self->ClearClipboardData(type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearClipboardData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetClipboardData of class  GUI::ClipboardManager */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ClipboardManager_GetClipboardData00
static int tolua_GUI_GUI_ClipboardManager_GetClipboardData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ClipboardManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ClipboardManager* self = (GUI::ClipboardManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string type = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetClipboardData'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->GetClipboardData(type);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetClipboardData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: red of class  GUI::Colour */
#ifndef TOLUA_DISABLE_tolua_get_GUI__Colour_red
static int tolua_get_GUI__Colour_red(lua_State* tolua_S)
{
  GUI::Colour* self = (GUI::Colour*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'red'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->red);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: red of class  GUI::Colour */
#ifndef TOLUA_DISABLE_tolua_set_GUI__Colour_red
static int tolua_set_GUI__Colour_red(lua_State* tolua_S)
{
  GUI::Colour* self = (GUI::Colour*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'red'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->red = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: green of class  GUI::Colour */
#ifndef TOLUA_DISABLE_tolua_get_GUI__Colour_green
static int tolua_get_GUI__Colour_green(lua_State* tolua_S)
{
  GUI::Colour* self = (GUI::Colour*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'green'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->green);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: green of class  GUI::Colour */
#ifndef TOLUA_DISABLE_tolua_set_GUI__Colour_green
static int tolua_set_GUI__Colour_green(lua_State* tolua_S)
{
  GUI::Colour* self = (GUI::Colour*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'green'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->green = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: blue of class  GUI::Colour */
#ifndef TOLUA_DISABLE_tolua_get_GUI__Colour_blue
static int tolua_get_GUI__Colour_blue(lua_State* tolua_S)
{
  GUI::Colour* self = (GUI::Colour*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'blue'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->blue);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: blue of class  GUI::Colour */
#ifndef TOLUA_DISABLE_tolua_set_GUI__Colour_blue
static int tolua_set_GUI__Colour_blue(lua_State* tolua_S)
{
  GUI::Colour* self = (GUI::Colour*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'blue'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->blue = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: alpha of class  GUI::Colour */
#ifndef TOLUA_DISABLE_tolua_get_GUI__Colour_alpha
static int tolua_get_GUI__Colour_alpha(lua_State* tolua_S)
{
  GUI::Colour* self = (GUI::Colour*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'alpha'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->alpha);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: alpha of class  GUI::Colour */
#ifndef TOLUA_DISABLE_tolua_set_GUI__Colour_alpha
static int tolua_set_GUI__Colour_alpha(lua_State* tolua_S)
{
  GUI::Colour* self = (GUI::Colour*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'alpha'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->alpha = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Zero of class  GUI::Colour */
#ifndef TOLUA_DISABLE_tolua_get_GUI__Colour_Zero
static int tolua_get_GUI__Colour_Zero(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&GUI::Colour::Zero,"const GUI::Colour");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Black of class  GUI::Colour */
#ifndef TOLUA_DISABLE_tolua_get_GUI__Colour_Black
static int tolua_get_GUI__Colour_Black(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&GUI::Colour::Black,"const GUI::Colour");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: White of class  GUI::Colour */
#ifndef TOLUA_DISABLE_tolua_get_GUI__Colour_White
static int tolua_get_GUI__Colour_White(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&GUI::Colour::White,"const GUI::Colour");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Red of class  GUI::Colour */
#ifndef TOLUA_DISABLE_tolua_get_GUI__Colour_Red
static int tolua_get_GUI__Colour_Red(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&GUI::Colour::Red,"const GUI::Colour");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Green of class  GUI::Colour */
#ifndef TOLUA_DISABLE_tolua_get_GUI__Colour_Green
static int tolua_get_GUI__Colour_Green(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&GUI::Colour::Green,"const GUI::Colour");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Blue of class  GUI::Colour */
#ifndef TOLUA_DISABLE_tolua_get_GUI__Colour_Blue
static int tolua_get_GUI__Colour_Blue(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&GUI::Colour::Blue,"const GUI::Colour");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GUI::Colour */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Colour_new00
static int tolua_GUI_GUI_Colour_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::Colour",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GUI::Colour* tolua_ret = (GUI::Colour*)  Mtolua_new((GUI::Colour)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Colour");
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

/* method: new_local of class  GUI::Colour */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Colour_new00_local
static int tolua_GUI_GUI_Colour_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::Colour",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GUI::Colour* tolua_ret = (GUI::Colour*)  Mtolua_new((GUI::Colour)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Colour");
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

/* method: new of class  GUI::Colour */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Colour_new01
static int tolua_GUI_GUI_Colour_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::Colour",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float red = ((float)  tolua_tonumber(tolua_S,2,0));
  float green = ((float)  tolua_tonumber(tolua_S,3,0));
  float blue = ((float)  tolua_tonumber(tolua_S,4,0));
  float alpha = ((float)  tolua_tonumber(tolua_S,5,1));
  {
   GUI::Colour* tolua_ret = (GUI::Colour*)  Mtolua_new((GUI::Colour)(red,green,blue,alpha));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Colour");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_Colour_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  GUI::Colour */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Colour_new01_local
static int tolua_GUI_GUI_Colour_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::Colour",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float red = ((float)  tolua_tonumber(tolua_S,2,0));
  float green = ((float)  tolua_tonumber(tolua_S,3,0));
  float blue = ((float)  tolua_tonumber(tolua_S,4,0));
  float alpha = ((float)  tolua_tonumber(tolua_S,5,1));
  {
   GUI::Colour* tolua_ret = (GUI::Colour*)  Mtolua_new((GUI::Colour)(red,green,blue,alpha));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Colour");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_Colour_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GUI::Colour */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Colour_new02
static int tolua_GUI_GUI_Colour_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::Colour",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   GUI::Colour* tolua_ret = (GUI::Colour*)  Mtolua_new((GUI::Colour)(value));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Colour");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_Colour_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  GUI::Colour */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Colour_new02_local
static int tolua_GUI_GUI_Colour_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::Colour",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   GUI::Colour* tolua_ret = (GUI::Colour*)  Mtolua_new((GUI::Colour)(value));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Colour");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_Colour_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  GUI::Colour */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Colour__eq00
static int tolua_GUI_GUI_Colour__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::Colour",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::Colour* self = (const GUI::Colour*)  tolua_tousertype(tolua_S,1,0);
  Colour const* value = ((Colour const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*value);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set of class  GUI::Colour */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Colour_Set00
static int tolua_GUI_GUI_Colour_Set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Colour",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Colour* self = (GUI::Colour*)  tolua_tousertype(tolua_S,1,0);
  float red = ((float)  tolua_tonumber(tolua_S,2,0));
  float green = ((float)  tolua_tonumber(tolua_S,3,0));
  float blue = ((float)  tolua_tonumber(tolua_S,4,0));
  float alpha = ((float)  tolua_tonumber(tolua_S,5,1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set'", NULL);
#endif
  {
   self->Set(red,green,blue,alpha);
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

/* method: Clear of class  GUI::Colour */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Colour_Clear00
static int tolua_GUI_GUI_Colour_Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Colour",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Colour* self = (GUI::Colour*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'", NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Print of class  GUI::Colour */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Colour_Print00
static int tolua_GUI_GUI_Colour_Print00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::Colour",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::Colour* self = (const GUI::Colour*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Print'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->Print();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Print'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Parse of class  GUI::Colour */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Colour_Parse00
static int tolua_GUI_GUI_Colour_Parse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::Colour",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   GUI::Colour tolua_ret = (GUI::Colour)  GUI::Colour::Parse(value);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::Colour)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::Colour");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::Colour));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::Colour");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Parse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemCount of class  GUI::ComboBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ComboBox_GetItemCount00
static int tolua_GUI_GUI_ComboBox_GetItemCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::ComboBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::ComboBox* self = (const GUI::ComboBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemCount'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetItemCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InsertItem of class  GUI::ComboBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ComboBox_InsertItem00
static int tolua_GUI_GUI_ComboBox_InsertItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ComboBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,4,"GUI::Widget",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ComboBox* self = (GUI::ComboBox*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,4,nullptr));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InsertItem'", NULL);
#endif
  {
   self->InsertItem(index,*name,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InsertItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AppendItem of class  GUI::ComboBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ComboBox_AppendItem00
static int tolua_GUI_GUI_ComboBox_AppendItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ComboBox",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"GUI::Widget",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ComboBox* self = (GUI::ComboBox*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,3,nullptr));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AppendItem'", NULL);
#endif
  {
   self->AppendItem(*name,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AppendItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveItem of class  GUI::ComboBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ComboBox_RemoveItem00
static int tolua_GUI_GUI_ComboBox_RemoveItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ComboBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ComboBox* self = (GUI::ComboBox*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveItem'", NULL);
#endif
  {
   self->RemoveItem(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAllItems of class  GUI::ComboBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ComboBox_RemoveAllItems00
static int tolua_GUI_GUI_ComboBox_RemoveAllItems00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ComboBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ComboBox* self = (GUI::ComboBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAllItems'", NULL);
#endif
  {
   self->RemoveAllItems();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAllItems'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FindItemIndexWith of class  GUI::ComboBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ComboBox_FindItemIndexWith00
static int tolua_GUI_GUI_ComboBox_FindItemIndexWith00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ComboBox",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ComboBox* self = (GUI::ComboBox*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindItemIndexWith'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->FindItemIndexWith(*name);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindItemIndexWith'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIndexSelected of class  GUI::ComboBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ComboBox_GetIndexSelected00
static int tolua_GUI_GUI_ComboBox_GetIndexSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ComboBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ComboBox* self = (GUI::ComboBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIndexSelected'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetIndexSelected();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIndexSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetIndexSelected of class  GUI::ComboBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ComboBox_SetIndexSelected00
static int tolua_GUI_GUI_ComboBox_SetIndexSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ComboBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ComboBox* self = (GUI::ComboBox*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetIndexSelected'", NULL);
#endif
  {
   self->SetIndexSelected(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetIndexSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearIndexSelected of class  GUI::ComboBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ComboBox_ClearIndexSelected00
static int tolua_GUI_GUI_ComboBox_ClearIndexSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ComboBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ComboBox* self = (GUI::ComboBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearIndexSelected'", NULL);
#endif
  {
   self->ClearIndexSelected();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearIndexSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemData of class  GUI::ComboBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ComboBox_SetItemData00
static int tolua_GUI_GUI_ComboBox_SetItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ComboBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ComboBox* self = (GUI::ComboBox*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemData'", NULL);
#endif
  {
   self->SetItemData(index,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearItemData of class  GUI::ComboBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ComboBox_ClearItemData00
static int tolua_GUI_GUI_ComboBox_ClearItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ComboBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ComboBox* self = (GUI::ComboBox*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearItemData'", NULL);
#endif
  {
   self->ClearItemData(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemData of class  GUI::ComboBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ComboBox_GetItemData00
static int tolua_GUI_GUI_ComboBox_GetItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ComboBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ComboBox* self = (GUI::ComboBox*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemData'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->GetItemData(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemName of class  GUI::ComboBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ComboBox_SetItemName00
static int tolua_GUI_GUI_ComboBox_SetItemName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ComboBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ComboBox* self = (GUI::ComboBox*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemName'", NULL);
#endif
  {
   self->SetItemName(index,*name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemName of class  GUI::ComboBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ComboBox_GetItemName00
static int tolua_GUI_GUI_ComboBox_GetItemName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ComboBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ComboBox* self = (GUI::ComboBox*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemName'", NULL);
#endif
  {
   const GUI::UString& tolua_ret = (const GUI::UString&)  self->GetItemName(index);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const GUI::UString");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BeginToItem of class  GUI::ComboBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ComboBox_BeginToItem00
static int tolua_GUI_GUI_ComboBox_BeginToItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ComboBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ComboBox* self = (GUI::ComboBox*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BeginToItem'", NULL);
#endif
  {
   self->BeginToItem(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginToItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BeginToItemFirst of class  GUI::ComboBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ComboBox_BeginToItemFirst00
static int tolua_GUI_GUI_ComboBox_BeginToItemFirst00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ComboBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ComboBox* self = (GUI::ComboBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BeginToItemFirst'", NULL);
#endif
  {
   self->BeginToItemFirst();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginToItemFirst'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BeginToItemLast of class  GUI::ComboBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ComboBox_BeginToItemLast00
static int tolua_GUI_GUI_ComboBox_BeginToItemLast00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ComboBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ComboBox* self = (GUI::ComboBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BeginToItemLast'", NULL);
#endif
  {
   self->BeginToItemLast();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginToItemLast'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BeginToItemSelected of class  GUI::ComboBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ComboBox_BeginToItemSelected00
static int tolua_GUI_GUI_ComboBox_BeginToItemSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ComboBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ComboBox* self = (GUI::ComboBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BeginToItemSelected'", NULL);
#endif
  {
   self->BeginToItemSelected();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginToItemSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetComboModeDrop of class  GUI::ComboBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ComboBox_SetComboModeDrop00
static int tolua_GUI_GUI_ComboBox_SetComboModeDrop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ComboBox",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ComboBox* self = (GUI::ComboBox*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetComboModeDrop'", NULL);
#endif
  {
   self->SetComboModeDrop(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetComboModeDrop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetComboModeDrop of class  GUI::ComboBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ComboBox_GetComboModeDrop00
static int tolua_GUI_GUI_ComboBox_GetComboModeDrop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ComboBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ComboBox* self = (GUI::ComboBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetComboModeDrop'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetComboModeDrop();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetComboModeDrop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSmoothShow of class  GUI::ComboBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ComboBox_SetSmoothShow00
static int tolua_GUI_GUI_ComboBox_SetSmoothShow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ComboBox",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ComboBox* self = (GUI::ComboBox*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSmoothShow'", NULL);
#endif
  {
   self->SetSmoothShow(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSmoothShow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSmoothShow of class  GUI::ComboBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ComboBox_GetSmoothShow00
static int tolua_GUI_GUI_ComboBox_GetSmoothShow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ComboBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ComboBox* self = (GUI::ComboBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSmoothShow'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetSmoothShow();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSmoothShow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxListHeight of class  GUI::ComboBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ComboBox_SetMaxListHeight00
static int tolua_GUI_GUI_ComboBox_SetMaxListHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ComboBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ComboBox* self = (GUI::ComboBox*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxListHeight'", NULL);
#endif
  {
   self->SetMaxListHeight(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxListHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxListHeight of class  GUI::ComboBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ComboBox_GetMaxListHeight00
static int tolua_GUI_GUI_ComboBox_GetMaxListHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ComboBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ComboBox* self = (GUI::ComboBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxListHeight'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetMaxListHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxListHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetProperty of class  GUI::ComboBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ComboBox_SetProperty00
static int tolua_GUI_GUI_ComboBox_SetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ComboBox",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ComboBox* self = (GUI::ComboBox*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetProperty'", NULL);
#endif
  {
   self->SetProperty(key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTextIntervalColour of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetTextIntervalColour00
static int tolua_GUI_GUI_Edit_SetTextIntervalColour00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const GUI::Colour",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
    int start = ((   int)  tolua_tonumber(tolua_S,2,0));
    int count = ((   int)  tolua_tonumber(tolua_S,3,0));
  const GUI::Colour* colour = ((const GUI::Colour*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTextIntervalColour'", NULL);
#endif
  {
   self->SetTextIntervalColour(start,count,*colour);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTextIntervalColour'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTextSelectionStart of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_GetTextSelectionStart00
static int tolua_GUI_GUI_Edit_GetTextSelectionStart00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTextSelectionStart'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetTextSelectionStart();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTextSelectionStart'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTextSelectionEnd of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_GetTextSelectionEnd00
static int tolua_GUI_GUI_Edit_GetTextSelectionEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTextSelectionEnd'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetTextSelectionEnd();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTextSelectionEnd'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTextSelectionLength of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_GetTextSelectionLength00
static int tolua_GUI_GUI_Edit_GetTextSelectionLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTextSelectionLength'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetTextSelectionLength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTextSelectionLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTextInterval of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_GetTextInterval00
static int tolua_GUI_GUI_Edit_GetTextInterval00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
    int start = ((   int)  tolua_tonumber(tolua_S,2,0));
    int count = ((   int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTextInterval'", NULL);
#endif
  {
   GUI::UString tolua_ret = (GUI::UString)  self->GetTextInterval(start,count);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::UString)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::UString");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::UString));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::UString");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTextInterval'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTextSelection of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetTextSelection00
static int tolua_GUI_GUI_Edit_SetTextSelection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
    int start = ((   int)  tolua_tonumber(tolua_S,2,0));
    int end = ((   int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTextSelection'", NULL);
#endif
  {
   self->SetTextSelection(start,end);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTextSelection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DeleteTextSelection of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_DeleteTextSelection00
static int tolua_GUI_GUI_Edit_DeleteTextSelection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DeleteTextSelection'", NULL);
#endif
  {
   self->DeleteTextSelection();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DeleteTextSelection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTextSelection of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_GetTextSelection00
static int tolua_GUI_GUI_Edit_GetTextSelection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTextSelection'", NULL);
#endif
  {
   GUI::UString tolua_ret = (GUI::UString)  self->GetTextSelection();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::UString)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::UString");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::UString));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::UString");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTextSelection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsTextSelection of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_IsTextSelection00
static int tolua_GUI_GUI_Edit_IsTextSelection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsTextSelection'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsTextSelection();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsTextSelection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTextSelectionColour of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetTextSelectionColour00
static int tolua_GUI_GUI_Edit_SetTextSelectionColour00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::Colour",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
  const GUI::Colour* value = ((const GUI::Colour*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTextSelectionColour'", NULL);
#endif
  {
   self->SetTextSelectionColour(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTextSelectionColour'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTextCursor of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetTextCursor00
static int tolua_GUI_GUI_Edit_SetTextCursor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTextCursor'", NULL);
#endif
  {
   self->SetTextCursor(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTextCursor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTextCursor of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_GetTextCursor00
static int tolua_GUI_GUI_Edit_GetTextCursor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTextCursor'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetTextCursor();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTextCursor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCaption of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetCaption00
static int tolua_GUI_GUI_Edit_SetCaption00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* value = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCaption'", NULL);
#endif
  {
   self->SetCaption(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCaption'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCaption of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_GetCaption00
static int tolua_GUI_GUI_Edit_GetCaption00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCaption'", NULL);
#endif
  {
   const GUI::UString& tolua_ret = (const GUI::UString&)  self->GetCaption();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const GUI::UString");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCaption'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOnlyText of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetOnlyText00
static int tolua_GUI_GUI_Edit_SetOnlyText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* value = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOnlyText'", NULL);
#endif
  {
   self->SetOnlyText(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOnlyText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOnlyText of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_GetOnlyText00
static int tolua_GUI_GUI_Edit_GetOnlyText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOnlyText'", NULL);
#endif
  {
   GUI::UString tolua_ret = (GUI::UString)  self->GetOnlyText();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::UString)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::UString");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::UString));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::UString");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOnlyText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTextLength of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_GetTextLength00
static int tolua_GUI_GUI_Edit_GetTextLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::Edit* self = (const GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTextLength'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetTextLength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTextLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOverflowToTheLeft of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetOverflowToTheLeft00
static int tolua_GUI_GUI_Edit_SetOverflowToTheLeft00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOverflowToTheLeft'", NULL);
#endif
  {
   self->SetOverflowToTheLeft(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOverflowToTheLeft'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOverflowToTheLeft of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_GetOverflowToTheLeft00
static int tolua_GUI_GUI_Edit_GetOverflowToTheLeft00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOverflowToTheLeft'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetOverflowToTheLeft();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOverflowToTheLeft'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxTextLength of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetMaxTextLength00
static int tolua_GUI_GUI_Edit_SetMaxTextLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
    int value = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxTextLength'", NULL);
#endif
  {
   self->SetMaxTextLength(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxTextLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxTextLength of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_GetMaxTextLength00
static int tolua_GUI_GUI_Edit_GetMaxTextLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxTextLength'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetMaxTextLength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxTextLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InsertText of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_InsertText00
static int tolua_GUI_GUI_Edit_InsertText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* text = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
    int index = ((   int)  tolua_tonumber(tolua_S,3,ITEM_NONE));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InsertText'", NULL);
#endif
  {
   self->InsertText(*text,index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InsertText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddText of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_AddText00
static int tolua_GUI_GUI_Edit_AddText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* text = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddText'", NULL);
#endif
  {
   self->AddText(*text);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: eraseText of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_eraseText00
static int tolua_GUI_GUI_Edit_eraseText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
    int start = ((   int)  tolua_tonumber(tolua_S,2,0));
    int count = ((   int)  tolua_tonumber(tolua_S,3,1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'eraseText'", NULL);
#endif
  {
   self->eraseText(start,count);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'eraseText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEditReadOnly of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetEditReadOnly00
static int tolua_GUI_GUI_Edit_SetEditReadOnly00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEditReadOnly'", NULL);
#endif
  {
   self->SetEditReadOnly(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEditReadOnly'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEditReadOnly of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_GetEditReadOnly00
static int tolua_GUI_GUI_Edit_GetEditReadOnly00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEditReadOnly'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetEditReadOnly();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEditReadOnly'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEditPassword of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetEditPassword00
static int tolua_GUI_GUI_Edit_SetEditPassword00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEditPassword'", NULL);
#endif
  {
   self->SetEditPassword(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEditPassword'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEditPassword of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_GetEditPassword00
static int tolua_GUI_GUI_Edit_GetEditPassword00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEditPassword'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetEditPassword();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEditPassword'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEditMultiLine of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetEditMultiLine00
static int tolua_GUI_GUI_Edit_SetEditMultiLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEditMultiLine'", NULL);
#endif
  {
   self->SetEditMultiLine(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEditMultiLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEditMultiLine of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_GetEditMultiLine00
static int tolua_GUI_GUI_Edit_GetEditMultiLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEditMultiLine'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetEditMultiLine();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEditMultiLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEditStatic of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetEditStatic00
static int tolua_GUI_GUI_Edit_SetEditStatic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEditStatic'", NULL);
#endif
  {
   self->SetEditStatic(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEditStatic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEditStatic of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_GetEditStatic00
static int tolua_GUI_GUI_Edit_GetEditStatic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEditStatic'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetEditStatic();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEditStatic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPasswordChar of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetPasswordChar00
static int tolua_GUI_GUI_Edit_SetPasswordChar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
  unsigned int value = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPasswordChar'", NULL);
#endif
  {
   self->SetPasswordChar(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPasswordChar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPasswordChar of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetPasswordChar01
static int tolua_GUI_GUI_Edit_SetPasswordChar01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* _char = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPasswordChar'", NULL);
#endif
  {
   self->SetPasswordChar(*_char);
  }
 }
 return 0;
tolua_lerror:
 return tolua_GUI_GUI_Edit_SetPasswordChar00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPasswordChar of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_GetPasswordChar00
static int tolua_GUI_GUI_Edit_GetPasswordChar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPasswordChar'", NULL);
#endif
  {
   unsigned int tolua_ret = ( unsigned int)  self->GetPasswordChar();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPasswordChar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEditWordWrap of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetEditWordWrap00
static int tolua_GUI_GUI_Edit_SetEditWordWrap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEditWordWrap'", NULL);
#endif
  {
   self->SetEditWordWrap(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEditWordWrap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEditWordWrap of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_GetEditWordWrap00
static int tolua_GUI_GUI_Edit_GetEditWordWrap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEditWordWrap'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetEditWordWrap();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEditWordWrap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTabPrinting of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetTabPrinting00
static int tolua_GUI_GUI_Edit_SetTabPrinting00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTabPrinting'", NULL);
#endif
  {
   self->SetTabPrinting(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTabPrinting'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTabPrinting of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_GetTabPrinting00
static int tolua_GUI_GUI_Edit_GetTabPrinting00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTabPrinting'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetTabPrinting();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTabPrinting'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetInvertSelected of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_GetInvertSelected00
static int tolua_GUI_GUI_Edit_GetInvertSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetInvertSelected'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetInvertSelected();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInvertSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetInvertSelected of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetInvertSelected00
static int tolua_GUI_GUI_Edit_SetInvertSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetInvertSelected'", NULL);
#endif
  {
   self->SetInvertSelected(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetInvertSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetPosition00
static int tolua_GUI_GUI_Edit_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
  int left = ((int)  tolua_tonumber(tolua_S,2,0));
  int top = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
  {
   self->SetPosition(left,top);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSize of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetSize00
static int tolua_GUI_GUI_Edit_SetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSize'", NULL);
#endif
  {
   self->SetSize(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCoord of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetCoord00
static int tolua_GUI_GUI_Edit_SetCoord00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
  int left = ((int)  tolua_tonumber(tolua_S,2,0));
  int top = ((int)  tolua_tonumber(tolua_S,3,0));
  int width = ((int)  tolua_tonumber(tolua_S,4,0));
  int height = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCoord'", NULL);
#endif
  {
   self->SetCoord(left,top,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCoord'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVisibleVScroll of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetVisibleVScroll00
static int tolua_GUI_GUI_Edit_SetVisibleVScroll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVisibleVScroll'", NULL);
#endif
  {
   self->SetVisibleVScroll(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVisibleVScroll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsVisibleVScroll of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_IsVisibleVScroll00
static int tolua_GUI_GUI_Edit_IsVisibleVScroll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsVisibleVScroll'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsVisibleVScroll();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsVisibleVScroll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVScrollRange of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_GetVScrollRange00
static int tolua_GUI_GUI_Edit_GetVScrollRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVScrollRange'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetVScrollRange();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVScrollRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVScrollPosition of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_GetVScrollPosition00
static int tolua_GUI_GUI_Edit_GetVScrollPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVScrollPosition'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetVScrollPosition();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVScrollPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVScrollPosition of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetVScrollPosition00
static int tolua_GUI_GUI_Edit_SetVScrollPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVScrollPosition'", NULL);
#endif
  {
   self->SetVScrollPosition(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVScrollPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVisibleHScroll of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetVisibleHScroll00
static int tolua_GUI_GUI_Edit_SetVisibleHScroll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVisibleHScroll'", NULL);
#endif
  {
   self->SetVisibleHScroll(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVisibleHScroll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsVisibleHScroll of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_IsVisibleHScroll00
static int tolua_GUI_GUI_Edit_IsVisibleHScroll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsVisibleHScroll'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsVisibleHScroll();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsVisibleHScroll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHScrollRange of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_GetHScrollRange00
static int tolua_GUI_GUI_Edit_GetHScrollRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHScrollRange'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetHScrollRange();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHScrollRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHScrollPosition of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_GetHScrollPosition00
static int tolua_GUI_GUI_Edit_GetHScrollPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHScrollPosition'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetHScrollPosition();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHScrollPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHScrollPosition of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetHScrollPosition00
static int tolua_GUI_GUI_Edit_SetHScrollPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHScrollPosition'", NULL);
#endif
  {
   self->SetHScrollPosition(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHScrollPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFontName of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetFontName00
static int tolua_GUI_GUI_Edit_SetFontName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFontName'", NULL);
#endif
  {
   self->SetFontName(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFontName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFontHeight of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetFontHeight00
static int tolua_GUI_GUI_Edit_SetFontHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFontHeight'", NULL);
#endif
  {
   self->SetFontHeight(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFontHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTextAlign of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetTextAlign00
static int tolua_GUI_GUI_Edit_SetTextAlign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GUI::Align",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
  GUI::Align value = *((GUI::Align*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTextAlign'", NULL);
#endif
  {
   self->SetTextAlign(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTextAlign'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetProperty of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Edit_SetProperty00
static int tolua_GUI_GUI_Edit_SetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Edit",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetProperty'", NULL);
#endif
  {
   self->SetProperty(key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __ScrollViewBase__ of class  GUI::Edit */
#ifndef TOLUA_DISABLE_tolua_get_GUI__Edit___ScrollViewBase__
static int tolua_get_GUI__Edit___ScrollViewBase__(lua_State* tolua_S)
{
  GUI::Edit* self = (GUI::Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__ScrollViewBase__'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<ScrollViewBase*>(self), "ScrollViewBase");
#else
   tolua_pushusertype(tolua_S,(void*)((ScrollViewBase*)self), "ScrollViewBase");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: Instance of class  GUI::Gui */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Gui_Instance00
static int tolua_GUI_GUI_Gui_Instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::Gui",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GUI::Gui& tolua_ret = (GUI::Gui&)  GUI::Gui::Instance();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"GUI::Gui");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Instance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateWidgetT of class  GUI::Gui */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Gui_CreateWidgetT00
static int tolua_GUI_GUI_Gui_CreateWidgetT00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Gui",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const TCoord<int>",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"GUI::Align",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Gui* self = (GUI::Gui*)  tolua_tousertype(tolua_S,1,0);
  const std::string type = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string skin = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const TCoord<int>* coord = ((const TCoord<int>*)  tolua_tousertype(tolua_S,4,0));
  GUI::Align align = *((GUI::Align*)  tolua_tousertype(tolua_S,5,0));
  const std::string layer = ((const std::string)  tolua_tocppstring(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateWidgetT'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->CreateWidgetT(type,skin,*coord,align,layer);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateWidgetT'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateWidgetT of class  GUI::Gui */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Gui_CreateWidgetT01
static int tolua_GUI_GUI_Gui_CreateWidgetT01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Gui",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const TCoord<int>",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"GUI::Align",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,6,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::Gui* self = (GUI::Gui*)  tolua_tousertype(tolua_S,1,0);
  const std::string type = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string skin = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const TCoord<int>* coord = ((const TCoord<int>*)  tolua_tousertype(tolua_S,4,0));
  GUI::Align align = *((GUI::Align*)  tolua_tousertype(tolua_S,5,0));
  const std::string layer = ((const std::string)  tolua_tocppstring(tolua_S,6,0));
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateWidgetT'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->CreateWidgetT(type,skin,*coord,align,layer,name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_Gui_CreateWidgetT00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateWidgetT of class  GUI::Gui */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Gui_CreateWidgetT02
static int tolua_GUI_GUI_Gui_CreateWidgetT02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Gui",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,8,&tolua_err) || !tolua_isusertype(tolua_S,8,"GUI::Align",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,9,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,10,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::Gui* self = (GUI::Gui*)  tolua_tousertype(tolua_S,1,0);
  const std::string type = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string skin = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  int left = ((int)  tolua_tonumber(tolua_S,4,0));
  int top = ((int)  tolua_tonumber(tolua_S,5,0));
  int width = ((int)  tolua_tonumber(tolua_S,6,0));
  int height = ((int)  tolua_tonumber(tolua_S,7,0));
  GUI::Align align = *((GUI::Align*)  tolua_tousertype(tolua_S,8,0));
  const std::string layer = ((const std::string)  tolua_tocppstring(tolua_S,9,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateWidgetT'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->CreateWidgetT(type,skin,left,top,width,height,align,layer);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_Gui_CreateWidgetT01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateWidgetT of class  GUI::Gui */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Gui_CreateWidgetT03
static int tolua_GUI_GUI_Gui_CreateWidgetT03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Gui",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,8,&tolua_err) || !tolua_isusertype(tolua_S,8,"GUI::Align",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,9,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,10,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,11,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::Gui* self = (GUI::Gui*)  tolua_tousertype(tolua_S,1,0);
  const std::string type = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string skin = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  int left = ((int)  tolua_tonumber(tolua_S,4,0));
  int top = ((int)  tolua_tonumber(tolua_S,5,0));
  int width = ((int)  tolua_tonumber(tolua_S,6,0));
  int height = ((int)  tolua_tonumber(tolua_S,7,0));
  GUI::Align align = *((GUI::Align*)  tolua_tousertype(tolua_S,8,0));
  const std::string layer = ((const std::string)  tolua_tocppstring(tolua_S,9,0));
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,10,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateWidgetT'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->CreateWidgetT(type,skin,left,top,width,height,align,layer,name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_Gui_CreateWidgetT02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateWidgetRealT of class  GUI::Gui */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Gui_CreateWidgetRealT00
static int tolua_GUI_GUI_Gui_CreateWidgetRealT00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Gui",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const TCoord<float>",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"GUI::Align",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Gui* self = (GUI::Gui*)  tolua_tousertype(tolua_S,1,0);
  const std::string type = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string skin = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const TCoord<float>* coord = ((const TCoord<float>*)  tolua_tousertype(tolua_S,4,0));
  GUI::Align align = *((GUI::Align*)  tolua_tousertype(tolua_S,5,0));
  const std::string layer = ((const std::string)  tolua_tocppstring(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateWidgetRealT'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->CreateWidgetRealT(type,skin,*coord,align,layer);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateWidgetRealT'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateWidgetRealT of class  GUI::Gui */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Gui_CreateWidgetRealT01
static int tolua_GUI_GUI_Gui_CreateWidgetRealT01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Gui",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const TCoord<float>",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"GUI::Align",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,6,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::Gui* self = (GUI::Gui*)  tolua_tousertype(tolua_S,1,0);
  const std::string type = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string skin = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const TCoord<float>* coord = ((const TCoord<float>*)  tolua_tousertype(tolua_S,4,0));
  GUI::Align align = *((GUI::Align*)  tolua_tousertype(tolua_S,5,0));
  const std::string layer = ((const std::string)  tolua_tocppstring(tolua_S,6,0));
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateWidgetRealT'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->CreateWidgetRealT(type,skin,*coord,align,layer,name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_Gui_CreateWidgetRealT00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateWidgetRealT of class  GUI::Gui */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Gui_CreateWidgetRealT02
static int tolua_GUI_GUI_Gui_CreateWidgetRealT02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Gui",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,8,&tolua_err) || !tolua_isusertype(tolua_S,8,"GUI::Align",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,9,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,10,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::Gui* self = (GUI::Gui*)  tolua_tousertype(tolua_S,1,0);
  const std::string type = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string skin = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  float left = ((float)  tolua_tonumber(tolua_S,4,0));
  float top = ((float)  tolua_tonumber(tolua_S,5,0));
  float width = ((float)  tolua_tonumber(tolua_S,6,0));
  float height = ((float)  tolua_tonumber(tolua_S,7,0));
  GUI::Align align = *((GUI::Align*)  tolua_tousertype(tolua_S,8,0));
  const std::string layer = ((const std::string)  tolua_tocppstring(tolua_S,9,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateWidgetRealT'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->CreateWidgetRealT(type,skin,left,top,width,height,align,layer);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_Gui_CreateWidgetRealT01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateWidgetRealT of class  GUI::Gui */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Gui_CreateWidgetRealT03
static int tolua_GUI_GUI_Gui_CreateWidgetRealT03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Gui",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,8,&tolua_err) || !tolua_isusertype(tolua_S,8,"GUI::Align",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,9,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,10,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,11,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::Gui* self = (GUI::Gui*)  tolua_tousertype(tolua_S,1,0);
  const std::string type = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string skin = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  float left = ((float)  tolua_tonumber(tolua_S,4,0));
  float top = ((float)  tolua_tonumber(tolua_S,5,0));
  float width = ((float)  tolua_tonumber(tolua_S,6,0));
  float height = ((float)  tolua_tonumber(tolua_S,7,0));
  GUI::Align align = *((GUI::Align*)  tolua_tousertype(tolua_S,8,0));
  const std::string layer = ((const std::string)  tolua_tocppstring(tolua_S,9,0));
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,10,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateWidgetRealT'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->CreateWidgetRealT(type,skin,left,top,width,height,align,layer,name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_Gui_CreateWidgetRealT02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetViewSize of class  GUI::Gui */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Gui_GetViewSize00
static int tolua_GUI_GUI_Gui_GetViewSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::Gui",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::Gui* self = (const GUI::Gui*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetViewSize'", NULL);
#endif
  {
    const TSize<int>& tolua_ret = (  const TSize<int>&)  self->GetViewSize();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const TSize<int>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetViewSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetViewWidth of class  GUI::Gui */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Gui_GetViewWidth00
static int tolua_GUI_GUI_Gui_GetViewWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Gui",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Gui* self = (GUI::Gui*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetViewWidth'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetViewWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetViewWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetViewHeight of class  GUI::Gui */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Gui_GetViewHeight00
static int tolua_GUI_GUI_Gui_GetViewHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Gui",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Gui* self = (GUI::Gui*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetViewHeight'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetViewHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetViewHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DestroyWidget of class  GUI::Gui */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Gui_DestroyWidget00
static int tolua_GUI_GUI_Gui_DestroyWidget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Gui",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Gui* self = (GUI::Gui*)  tolua_tousertype(tolua_S,1,0);
  GUI::Widget* widget = ((GUI::Widget*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DestroyWidget'", NULL);
#endif
  {
   self->DestroyWidget(widget);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DestroyWidget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: findWidgetT of class  GUI::Gui */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Gui_findWidgetT00
static int tolua_GUI_GUI_Gui_findWidgetT00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Gui",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Gui* self = (GUI::Gui*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  bool _throw = ((bool)  tolua_toboolean(tolua_S,3,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'findWidgetT'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->findWidgetT(name,_throw);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'findWidgetT'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVisiblePointer of class  GUI::Gui */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Gui_SetVisiblePointer00
static int tolua_GUI_GUI_Gui_SetVisiblePointer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Gui",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Gui* self = (GUI::Gui*)  tolua_tousertype(tolua_S,1,0);
  bool visible = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVisiblePointer'", NULL);
#endif
  {
   self->SetVisiblePointer(visible);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVisiblePointer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsVisiblePointer of class  GUI::Gui */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Gui_IsVisiblePointer00
static int tolua_GUI_GUI_Gui_IsVisiblePointer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Gui",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Gui* self = (GUI::Gui*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsVisiblePointer'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsVisiblePointer();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsVisiblePointer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Load of class  GUI::Gui */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Gui_Load00
static int tolua_GUI_GUI_Gui_Load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Gui",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Gui* self = (GUI::Gui*)  tolua_tousertype(tolua_S,1,0);
  const std::string file = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Load'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Load(file);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Load'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResizeWindow of class  GUI::Gui */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Gui_ResizeWindow00
static int tolua_GUI_GUI_Gui_ResizeWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Gui",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const TSize<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Gui* self = (GUI::Gui*)  tolua_tousertype(tolua_S,1,0);
  const TSize<int>* size = ((const TSize<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResizeWindow'", NULL);
#endif
  {
   self->ResizeWindow(*size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ResizeWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DestroyChildWidget of class  GUI::Gui */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Gui_DestroyChildWidget00
static int tolua_GUI_GUI_Gui_DestroyChildWidget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Gui",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Gui* self = (GUI::Gui*)  tolua_tousertype(tolua_S,1,0);
  GUI::Widget* widget = ((GUI::Widget*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DestroyChildWidget'", NULL);
#endif
  {
   self->DestroyChildWidget(widget);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DestroyChildWidget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DestroyAllChildWidget of class  GUI::Gui */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Gui_DestroyAllChildWidget00
static int tolua_GUI_GUI_Gui_DestroyAllChildWidget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Gui",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Gui* self = (GUI::Gui*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DestroyAllChildWidget'", NULL);
#endif
  {
   self->DestroyAllChildWidget();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DestroyAllChildWidget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __IUnlinkWidget__ of class  GUI::Gui */
#ifndef TOLUA_DISABLE_tolua_get_GUI__Gui___IUnlinkWidget__
static int tolua_get_GUI__Gui___IUnlinkWidget__(lua_State* tolua_S)
{
  GUI::Gui* self = (GUI::Gui*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__IUnlinkWidget__'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<IUnlinkWidget*>(self), "IUnlinkWidget");
#else
   tolua_pushusertype(tolua_S,(void*)((IUnlinkWidget*)self), "IUnlinkWidget");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLineSize of class  GUI::HScroll */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_HScroll_GetLineSize00
static int tolua_GUI_GUI_HScroll_GetLineSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::HScroll",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::HScroll* self = (GUI::HScroll*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLineSize'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetLineSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLineSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTrackSize of class  GUI::HScroll */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_HScroll_SetTrackSize00
static int tolua_GUI_GUI_HScroll_SetTrackSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::HScroll",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::HScroll* self = (GUI::HScroll*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTrackSize'", NULL);
#endif
  {
   self->SetTrackSize(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTrackSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTrackSize of class  GUI::HScroll */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_HScroll_GetTrackSize00
static int tolua_GUI_GUI_HScroll_GetTrackSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::HScroll",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::HScroll* self = (GUI::HScroll*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTrackSize'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetTrackSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTrackSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GUI::MouseButton */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MouseButton_new00
static int tolua_GUI_GUI_MouseButton_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::MouseButton",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MouseButton::Enum value = ((GUI::MouseButton::Enum) (int)  tolua_tonumber(tolua_S,2,GUI::MouseButton::None));
  {
   GUI::MouseButton* tolua_ret = (GUI::MouseButton*)  Mtolua_new((GUI::MouseButton)(value));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::MouseButton");
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

/* method: new_local of class  GUI::MouseButton */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MouseButton_new00_local
static int tolua_GUI_GUI_MouseButton_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::MouseButton",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MouseButton::Enum value = ((GUI::MouseButton::Enum) (int)  tolua_tonumber(tolua_S,2,GUI::MouseButton::None));
  {
   GUI::MouseButton* tolua_ret = (GUI::MouseButton*)  Mtolua_new((GUI::MouseButton)(value));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::MouseButton");
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

/* method: operator== of class  GUI::MouseButton */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MouseButton__eq00
static int tolua_GUI_GUI_MouseButton__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MouseButton",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MouseButton* self = (GUI::MouseButton*)  tolua_tousertype(tolua_S,1,0);
  MouseButton const* other = ((MouseButton const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToValue of class  GUI::MouseButton */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MouseButton_ToValue00
static int tolua_GUI_GUI_MouseButton_ToValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::MouseButton",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::MouseButton* self = (const GUI::MouseButton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToValue'", NULL);
#endif
  {
   int tolua_ret = (int)  self->ToValue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GUI::KeyCode */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_KeyCode_new00
static int tolua_GUI_GUI_KeyCode_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::KeyCode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::KeyCode::Enum value = ((GUI::KeyCode::Enum) (int)  tolua_tonumber(tolua_S,2,GUI::KeyCode::None));
  {
   GUI::KeyCode* tolua_ret = (GUI::KeyCode*)  Mtolua_new((GUI::KeyCode)(value));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::KeyCode");
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

/* method: new_local of class  GUI::KeyCode */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_KeyCode_new00_local
static int tolua_GUI_GUI_KeyCode_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::KeyCode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::KeyCode::Enum value = ((GUI::KeyCode::Enum) (int)  tolua_tonumber(tolua_S,2,GUI::KeyCode::None));
  {
   GUI::KeyCode* tolua_ret = (GUI::KeyCode*)  Mtolua_new((GUI::KeyCode)(value));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::KeyCode");
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

/* method: operator== of class  GUI::KeyCode */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_KeyCode__eq00
static int tolua_GUI_GUI_KeyCode__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::KeyCode",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::KeyCode* self = (GUI::KeyCode*)  tolua_tousertype(tolua_S,1,0);
  KeyCode const* other = ((KeyCode const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToValue of class  GUI::KeyCode */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_KeyCode_ToValue00
static int tolua_GUI_GUI_KeyCode_ToValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::KeyCode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::KeyCode* self = (const GUI::KeyCode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToValue'", NULL);
#endif
  {
   int tolua_ret = (int)  self->ToValue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemCount of class  GUI::ItemBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ItemBox_GetItemCount00
static int tolua_GUI_GUI_ItemBox_GetItemCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::ItemBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::ItemBox* self = (const GUI::ItemBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemCount'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetItemCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InsertItem of class  GUI::ItemBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ItemBox_InsertItem00
static int tolua_GUI_GUI_ItemBox_InsertItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ItemBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"GUI::Widget",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ItemBox* self = (GUI::ItemBox*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,3,nullptr));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InsertItem'", NULL);
#endif
  {
   self->InsertItem(index,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InsertItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AppendItem of class  GUI::ItemBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ItemBox_AppendItem00
static int tolua_GUI_GUI_ItemBox_AppendItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ItemBox",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::Widget",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ItemBox* self = (GUI::ItemBox*)  tolua_tousertype(tolua_S,1,0);
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,2,nullptr));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AppendItem'", NULL);
#endif
  {
   self->AppendItem(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AppendItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveItem of class  GUI::ItemBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ItemBox_RemoveItem00
static int tolua_GUI_GUI_ItemBox_RemoveItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ItemBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ItemBox* self = (GUI::ItemBox*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveItem'", NULL);
#endif
  {
   self->RemoveItem(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAllItems of class  GUI::ItemBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ItemBox_RemoveAllItems00
static int tolua_GUI_GUI_ItemBox_RemoveAllItems00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ItemBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ItemBox* self = (GUI::ItemBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAllItems'", NULL);
#endif
  {
   self->RemoveAllItems();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAllItems'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RedrawItem of class  GUI::ItemBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ItemBox_RedrawItem00
static int tolua_GUI_GUI_ItemBox_RedrawItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ItemBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ItemBox* self = (GUI::ItemBox*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RedrawItem'", NULL);
#endif
  {
   self->RedrawItem(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RedrawItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RedrawAllItems of class  GUI::ItemBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ItemBox_RedrawAllItems00
static int tolua_GUI_GUI_ItemBox_RedrawAllItems00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ItemBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ItemBox* self = (GUI::ItemBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RedrawAllItems'", NULL);
#endif
  {
   self->RedrawAllItems();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RedrawAllItems'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIndexSelected of class  GUI::ItemBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ItemBox_GetIndexSelected00
static int tolua_GUI_GUI_ItemBox_GetIndexSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ItemBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ItemBox* self = (GUI::ItemBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIndexSelected'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetIndexSelected();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIndexSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetIndexSelected of class  GUI::ItemBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ItemBox_SetIndexSelected00
static int tolua_GUI_GUI_ItemBox_SetIndexSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ItemBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ItemBox* self = (GUI::ItemBox*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetIndexSelected'", NULL);
#endif
  {
   self->SetIndexSelected(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetIndexSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearIndexSelected of class  GUI::ItemBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ItemBox_ClearIndexSelected00
static int tolua_GUI_GUI_ItemBox_ClearIndexSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ItemBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ItemBox* self = (GUI::ItemBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearIndexSelected'", NULL);
#endif
  {
   self->ClearIndexSelected();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearIndexSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemData of class  GUI::ItemBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ItemBox_SetItemData00
static int tolua_GUI_GUI_ItemBox_SetItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ItemBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ItemBox* self = (GUI::ItemBox*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemData'", NULL);
#endif
  {
   self->SetItemData(index,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearItemData of class  GUI::ItemBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ItemBox_ClearItemData00
static int tolua_GUI_GUI_ItemBox_ClearItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ItemBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ItemBox* self = (GUI::ItemBox*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearItemData'", NULL);
#endif
  {
   self->ClearItemData(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemData of class  GUI::ItemBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ItemBox_GetItemData00
static int tolua_GUI_GUI_ItemBox_GetItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ItemBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ItemBox* self = (GUI::ItemBox*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemData'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->GetItemData(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemBoxAlignVert of class  GUI::ItemBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ItemBox_SetItemBoxAlignVert00
static int tolua_GUI_GUI_ItemBox_SetItemBoxAlignVert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ItemBox",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ItemBox* self = (GUI::ItemBox*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemBoxAlignVert'", NULL);
#endif
  {
   self->SetItemBoxAlignVert(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemBoxAlignVert'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemBoxAlignVert of class  GUI::ItemBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ItemBox_GetItemBoxAlignVert00
static int tolua_GUI_GUI_ItemBox_GetItemBoxAlignVert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ItemBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ItemBox* self = (GUI::ItemBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemBoxAlignVert'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetItemBoxAlignVert();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemBoxAlignVert'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIndexByWidget of class  GUI::ItemBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ItemBox_GetIndexByWidget00
static int tolua_GUI_GUI_ItemBox_GetIndexByWidget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ItemBox",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ItemBox* self = (GUI::ItemBox*)  tolua_tousertype(tolua_S,1,0);
  GUI::Widget* widget = ((GUI::Widget*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIndexByWidget'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetIndexByWidget(widget);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIndexByWidget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWidgetDrag of class  GUI::ItemBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ItemBox_GetWidgetDrag00
static int tolua_GUI_GUI_ItemBox_GetWidgetDrag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ItemBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ItemBox* self = (GUI::ItemBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWidgetDrag'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->GetWidgetDrag();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWidgetDrag'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWidgetByIndex of class  GUI::ItemBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ItemBox_GetWidgetByIndex00
static int tolua_GUI_GUI_ItemBox_GetWidgetByIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ItemBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ItemBox* self = (GUI::ItemBox*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWidgetByIndex'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->GetWidgetByIndex(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWidgetByIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResetDrag of class  GUI::ItemBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ItemBox_ResetDrag00
static int tolua_GUI_GUI_ItemBox_ResetDrag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ItemBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ItemBox* self = (GUI::ItemBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResetDrag'", NULL);
#endif
  {
   self->ResetDrag();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ResetDrag'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  GUI::ItemBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ItemBox_SetPosition00
static int tolua_GUI_GUI_ItemBox_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ItemBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ItemBox* self = (GUI::ItemBox*)  tolua_tousertype(tolua_S,1,0);
  int left = ((int)  tolua_tonumber(tolua_S,2,0));
  int top = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
  {
   self->SetPosition(left,top);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSize of class  GUI::ItemBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ItemBox_SetSize00
static int tolua_GUI_GUI_ItemBox_SetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ItemBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ItemBox* self = (GUI::ItemBox*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSize'", NULL);
#endif
  {
   self->SetSize(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCoord of class  GUI::ItemBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ItemBox_SetCoord00
static int tolua_GUI_GUI_ItemBox_SetCoord00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ItemBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ItemBox* self = (GUI::ItemBox*)  tolua_tousertype(tolua_S,1,0);
  int left = ((int)  tolua_tonumber(tolua_S,2,0));
  int top = ((int)  tolua_tonumber(tolua_S,3,0));
  int width = ((int)  tolua_tonumber(tolua_S,4,0));
  int height = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCoord'", NULL);
#endif
  {
   self->SetCoord(left,top,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCoord'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Instance of class  GUI::LanguageManager */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_LanguageManager_Instance00
static int tolua_GUI_GUI_LanguageManager_Instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::LanguageManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GUI::LanguageManager& tolua_ret = (GUI::LanguageManager&)  GUI::LanguageManager::Instance();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"GUI::LanguageManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Instance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Load of class  GUI::LanguageManager */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_LanguageManager_Load00
static int tolua_GUI_GUI_LanguageManager_Load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::LanguageManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::LanguageManager* self = (GUI::LanguageManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string file = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Load'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Load(file);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Load'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCurrentLanguage of class  GUI::LanguageManager */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_LanguageManager_SetCurrentLanguage00
static int tolua_GUI_GUI_LanguageManager_SetCurrentLanguage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::LanguageManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::LanguageManager* self = (GUI::LanguageManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCurrentLanguage'", NULL);
#endif
  {
   self->SetCurrentLanguage(name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCurrentLanguage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCurrentLanguage of class  GUI::LanguageManager */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_LanguageManager_GetCurrentLanguage00
static int tolua_GUI_GUI_LanguageManager_GetCurrentLanguage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::LanguageManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::LanguageManager* self = (GUI::LanguageManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCurrentLanguage'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetCurrentLanguage();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCurrentLanguage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReplaceTags of class  GUI::LanguageManager */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_LanguageManager_ReplaceTags00
static int tolua_GUI_GUI_LanguageManager_ReplaceTags00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::LanguageManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::LanguageManager* self = (GUI::LanguageManager*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* line = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReplaceTags'", NULL);
#endif
  {
   GUI::UString tolua_ret = (GUI::UString)  self->ReplaceTags(*line);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::UString)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::UString");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::UString));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::UString");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReplaceTags'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTag of class  GUI::LanguageManager */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_LanguageManager_GetTag00
static int tolua_GUI_GUI_LanguageManager_GetTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::LanguageManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::LanguageManager* self = (GUI::LanguageManager*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* tag = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTag'", NULL);
#endif
  {
   GUI::UString tolua_ret = (GUI::UString)  self->GetTag(*tag);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::UString)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::UString");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::UString));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::UString");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTag'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddUserTag of class  GUI::LanguageManager */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_LanguageManager_AddUserTag00
static int tolua_GUI_GUI_LanguageManager_AddUserTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::LanguageManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::LanguageManager* self = (GUI::LanguageManager*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* tag = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
  const GUI::UString* replace = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddUserTag'", NULL);
#endif
  {
   self->AddUserTag(*tag,*replace);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddUserTag'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearUserTags of class  GUI::LanguageManager */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_LanguageManager_ClearUserTags00
static int tolua_GUI_GUI_LanguageManager_ClearUserTags00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::LanguageManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::LanguageManager* self = (GUI::LanguageManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearUserTags'", NULL);
#endif
  {
   self->ClearUserTags();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearUserTags'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadUserTags of class  GUI::LanguageManager */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_LanguageManager_LoadUserTags00
static int tolua_GUI_GUI_LanguageManager_LoadUserTags00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::LanguageManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::LanguageManager* self = (GUI::LanguageManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string file = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadUserTags'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->LoadUserTags(file);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadUserTags'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Instance of class  GUI::LayerManager */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_LayerManager_Instance00
static int tolua_GUI_GUI_LayerManager_Instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::LayerManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GUI::LayerManager& tolua_ret = (GUI::LayerManager&)  GUI::LayerManager::Instance();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"GUI::LayerManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Instance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AttachToLayerNode of class  GUI::LayerManager */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_LayerManager_AttachToLayerNode00
static int tolua_GUI_GUI_LayerManager_AttachToLayerNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::LayerManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::LayerManager* self = (GUI::LayerManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  GUI::Widget* item = ((GUI::Widget*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AttachToLayerNode'", NULL);
#endif
  {
   self->AttachToLayerNode(name,item);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AttachToLayerNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DetachFromLayer of class  GUI::LayerManager */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_LayerManager_DetachFromLayer00
static int tolua_GUI_GUI_LayerManager_DetachFromLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::LayerManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::LayerManager* self = (GUI::LayerManager*)  tolua_tousertype(tolua_S,1,0);
  GUI::Widget* item = ((GUI::Widget*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DetachFromLayer'", NULL);
#endif
  {
   self->DetachFromLayer(item);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DetachFromLayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: UpLayerItem of class  GUI::LayerManager */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_LayerManager_UpLayerItem00
static int tolua_GUI_GUI_LayerManager_UpLayerItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::LayerManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::LayerManager* self = (GUI::LayerManager*)  tolua_tousertype(tolua_S,1,0);
  GUI::Widget* item = ((GUI::Widget*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UpLayerItem'", NULL);
#endif
  {
   self->UpLayerItem(item);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UpLayerItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsExist of class  GUI::LayerManager */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_LayerManager_IsExist00
static int tolua_GUI_GUI_LayerManager_IsExist00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::LayerManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::LayerManager* self = (const GUI::LayerManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsExist'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsExist(name);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsExist'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWidgetFromPoint of class  GUI::LayerManager */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_LayerManager_GetWidgetFromPoint00
static int tolua_GUI_GUI_LayerManager_GetWidgetFromPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::LayerManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::LayerManager* self = (GUI::LayerManager*)  tolua_tousertype(tolua_S,1,0);
  int left = ((int)  tolua_tonumber(tolua_S,2,0));
  int top = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWidgetFromPoint'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->GetWidgetFromPoint(left,top);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWidgetFromPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DumpStatisticToLog of class  GUI::LayerManager */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_LayerManager_DumpStatisticToLog00
static int tolua_GUI_GUI_LayerManager_DumpStatisticToLog00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::LayerManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::LayerManager* self = (GUI::LayerManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DumpStatisticToLog'", NULL);
#endif
  {
   self->DumpStatisticToLog();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DumpStatisticToLog'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Instance of class  GUI::LayoutManager */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_LayoutManager_Instance00
static int tolua_GUI_GUI_LayoutManager_Instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::LayoutManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GUI::LayoutManager& tolua_ret = (GUI::LayoutManager&)  GUI::LayoutManager::Instance();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"GUI::LayoutManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Instance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Load of class  GUI::LayoutManager */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_LayoutManager_Load00
static int tolua_GUI_GUI_LayoutManager_Load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::LayoutManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::LayoutManager* self = (GUI::LayoutManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string file = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Load'", NULL);
#endif
  {
   GUI::VectorWidgetPtr& tolua_ret = (GUI::VectorWidgetPtr&)  self->Load(file);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"GUI::VectorWidgetPtr");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Load'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadLayout of class  GUI::LayoutManager */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_LayoutManager_LoadLayout00
static int tolua_GUI_GUI_LayoutManager_LoadLayout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::LayoutManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::LayoutManager* self = (GUI::LayoutManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string file = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadLayout'", NULL);
#endif
  {
   GUI::VectorWidgetPtr& tolua_ret = (GUI::VectorWidgetPtr&)  self->LoadLayout(file);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"GUI::VectorWidgetPtr");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadLayout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadLayout of class  GUI::LayoutManager */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_LayoutManager_LoadLayout01
static int tolua_GUI_GUI_LayoutManager_LoadLayout01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::LayoutManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"GUI::Widget",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::LayoutManager* self = (GUI::LayoutManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string file = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string prefix = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  GUI::Widget* parent = ((GUI::Widget*)  tolua_tousertype(tolua_S,4,nullptr));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadLayout'", NULL);
#endif
  {
   GUI::VectorWidgetPtr& tolua_ret = (GUI::VectorWidgetPtr&)  self->LoadLayout(file,prefix,parent);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"GUI::VectorWidgetPtr");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_LayoutManager_LoadLayout00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: UnloadLayout of class  GUI::LayoutManager */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_LayoutManager_UnloadLayout00
static int tolua_GUI_GUI_LayoutManager_UnloadLayout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::LayoutManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GUI::VectorWidgetPtr",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::LayoutManager* self = (GUI::LayoutManager*)  tolua_tousertype(tolua_S,1,0);
  GUI::VectorWidgetPtr* widgets = ((GUI::VectorWidgetPtr*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UnloadLayout'", NULL);
#endif
  {
   self->UnloadLayout(*widgets);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UnloadLayout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FindWidget of class  GUI::LayoutManager */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_LayoutManager_FindWidget00
static int tolua_GUI_GUI_LayoutManager_FindWidget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::LayoutManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GUI::VectorWidgetPtr",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::LayoutManager* self = (GUI::LayoutManager*)  tolua_tousertype(tolua_S,1,0);
  GUI::VectorWidgetPtr* widgets = ((GUI::VectorWidgetPtr*)  tolua_tousertype(tolua_S,2,0));
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindWidget'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->FindWidget(*widgets,name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindWidget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemCount of class  GUI::List */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_List_GetItemCount00
static int tolua_GUI_GUI_List_GetItemCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::List",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::List* self = (const GUI::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemCount'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetItemCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InsertItem of class  GUI::List */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_List_InsertItem00
static int tolua_GUI_GUI_List_InsertItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::List",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,4,"GUI::Widget",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::List* self = (GUI::List*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,4,nullptr));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InsertItem'", NULL);
#endif
  {
   self->InsertItem(index,*name,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InsertItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AppendItem of class  GUI::List */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_List_AppendItem00
static int tolua_GUI_GUI_List_AppendItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::List",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"GUI::Widget",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::List* self = (GUI::List*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,3,nullptr));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AppendItem'", NULL);
#endif
  {
   self->AppendItem(*name,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AppendItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveItem of class  GUI::List */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_List_RemoveItem00
static int tolua_GUI_GUI_List_RemoveItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::List",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::List* self = (GUI::List*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveItem'", NULL);
#endif
  {
   self->RemoveItem(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAllItems of class  GUI::List */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_List_RemoveAllItems00
static int tolua_GUI_GUI_List_RemoveAllItems00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::List",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::List* self = (GUI::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAllItems'", NULL);
#endif
  {
   self->RemoveAllItems();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAllItems'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SwapItems of class  GUI::List */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_List_SwapItems00
static int tolua_GUI_GUI_List_SwapItems00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::List",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::List* self = (GUI::List*)  tolua_tousertype(tolua_S,1,0);
    int index1 = ((   int)  tolua_tonumber(tolua_S,2,0));
    int index2 = ((   int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SwapItems'", NULL);
#endif
  {
   self->SwapItems(index1,index2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SwapItems'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FindItemIndexWith of class  GUI::List */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_List_FindItemIndexWith00
static int tolua_GUI_GUI_List_FindItemIndexWith00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::List",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::List* self = (GUI::List*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindItemIndexWith'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->FindItemIndexWith(*name);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindItemIndexWith'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIndexSelected of class  GUI::List */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_List_GetIndexSelected00
static int tolua_GUI_GUI_List_GetIndexSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::List",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::List* self = (GUI::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIndexSelected'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetIndexSelected();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIndexSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetIndexSelected of class  GUI::List */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_List_SetIndexSelected00
static int tolua_GUI_GUI_List_SetIndexSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::List",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::List* self = (GUI::List*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetIndexSelected'", NULL);
#endif
  {
   self->SetIndexSelected(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetIndexSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearIndexSelected of class  GUI::List */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_List_ClearIndexSelected00
static int tolua_GUI_GUI_List_ClearIndexSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::List",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::List* self = (GUI::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearIndexSelected'", NULL);
#endif
  {
   self->ClearIndexSelected();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearIndexSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemData of class  GUI::List */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_List_SetItemData00
static int tolua_GUI_GUI_List_SetItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::List",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::List* self = (GUI::List*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemData'", NULL);
#endif
  {
   self->SetItemData(index,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearItemData of class  GUI::List */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_List_ClearItemData00
static int tolua_GUI_GUI_List_ClearItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::List",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::List* self = (GUI::List*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearItemData'", NULL);
#endif
  {
   self->ClearItemData(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemData of class  GUI::List */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_List_GetItemData00
static int tolua_GUI_GUI_List_GetItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::List",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::List* self = (GUI::List*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemData'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->GetItemData(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemName of class  GUI::List */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_List_SetItemName00
static int tolua_GUI_GUI_List_SetItemName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::List",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::List* self = (GUI::List*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemName'", NULL);
#endif
  {
   self->SetItemName(index,*name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemName of class  GUI::List */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_List_GetItemName00
static int tolua_GUI_GUI_List_GetItemName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::List",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::List* self = (GUI::List*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemName'", NULL);
#endif
  {
   const GUI::UString& tolua_ret = (const GUI::UString&)  self->GetItemName(index);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const GUI::UString");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BeginToItem of class  GUI::List */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_List_BeginToItem00
static int tolua_GUI_GUI_List_BeginToItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::List",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::List* self = (GUI::List*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BeginToItem'", NULL);
#endif
  {
   self->BeginToItem(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginToItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BeginToItemFirst of class  GUI::List */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_List_BeginToItemFirst00
static int tolua_GUI_GUI_List_BeginToItemFirst00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::List",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::List* self = (GUI::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BeginToItemFirst'", NULL);
#endif
  {
   self->BeginToItemFirst();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginToItemFirst'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BeginToItemLast of class  GUI::List */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_List_BeginToItemLast00
static int tolua_GUI_GUI_List_BeginToItemLast00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::List",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::List* self = (GUI::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BeginToItemLast'", NULL);
#endif
  {
   self->BeginToItemLast();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginToItemLast'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BeginToItemSelected of class  GUI::List */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_List_BeginToItemSelected00
static int tolua_GUI_GUI_List_BeginToItemSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::List",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::List* self = (GUI::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BeginToItemSelected'", NULL);
#endif
  {
   self->BeginToItemSelected();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginToItemSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsItemVisible of class  GUI::List */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_List_IsItemVisible00
static int tolua_GUI_GUI_List_IsItemVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::List",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::List* self = (GUI::List*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  bool fill = ((bool)  tolua_toboolean(tolua_S,3,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsItemVisible'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsItemVisible(index,fill);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsItemVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsItemSelectedVisible of class  GUI::List */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_List_IsItemSelectedVisible00
static int tolua_GUI_GUI_List_IsItemSelectedVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::List",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::List* self = (GUI::List*)  tolua_tousertype(tolua_S,1,0);
  bool fill = ((bool)  tolua_toboolean(tolua_S,2,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsItemSelectedVisible'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsItemSelectedVisible(fill);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsItemSelectedVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScrollVisible of class  GUI::List */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_List_SetScrollVisible00
static int tolua_GUI_GUI_List_SetScrollVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::List",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::List* self = (GUI::List*)  tolua_tousertype(tolua_S,1,0);
  bool visible = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScrollVisible'", NULL);
#endif
  {
   self->SetScrollVisible(visible);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScrollVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScrollPosition of class  GUI::List */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_List_SetScrollPosition00
static int tolua_GUI_GUI_List_SetScrollPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::List",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::List* self = (GUI::List*)  tolua_tousertype(tolua_S,1,0);
    int position = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScrollPosition'", NULL);
#endif
  {
   self->SetScrollPosition(position);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScrollPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSize of class  GUI::List */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_List_SetSize00
static int tolua_GUI_GUI_List_SetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::List",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::List* self = (GUI::List*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSize'", NULL);
#endif
  {
   self->SetSize(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCoord of class  GUI::List */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_List_SetCoord00
static int tolua_GUI_GUI_List_SetCoord00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::List",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::List* self = (GUI::List*)  tolua_tousertype(tolua_S,1,0);
  int left = ((int)  tolua_tonumber(tolua_S,2,0));
  int top = ((int)  tolua_tonumber(tolua_S,3,0));
  int width = ((int)  tolua_tonumber(tolua_S,4,0));
  int height = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCoord'", NULL);
#endif
  {
   self->SetCoord(left,top,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCoord'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOptimalHeight of class  GUI::List */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_List_GetOptimalHeight00
static int tolua_GUI_GUI_List_GetOptimalHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::List",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::List* self = (GUI::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOptimalHeight'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetOptimalHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOptimalHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetProperty of class  GUI::List */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_List_SetProperty00
static int tolua_GUI_GUI_List_SetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::List",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::List* self = (GUI::List*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetProperty'", NULL);
#endif
  {
   self->SetProperty(key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemCount of class  GUI::ListBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListBox_GetItemCount00
static int tolua_GUI_GUI_ListBox_GetItemCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::ListBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::ListBox* self = (const GUI::ListBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemCount'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetItemCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InsertItem of class  GUI::ListBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListBox_InsertItem00
static int tolua_GUI_GUI_ListBox_InsertItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,4,"GUI::Widget",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListBox* self = (GUI::ListBox*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,4,nullptr));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InsertItem'", NULL);
#endif
  {
   self->InsertItem(index,*name,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InsertItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AppendItem of class  GUI::ListBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListBox_AppendItem00
static int tolua_GUI_GUI_ListBox_AppendItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListBox",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"GUI::Widget",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListBox* self = (GUI::ListBox*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,3,nullptr));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AppendItem'", NULL);
#endif
  {
   self->AppendItem(*name,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AppendItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveItem of class  GUI::ListBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListBox_RemoveItem00
static int tolua_GUI_GUI_ListBox_RemoveItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListBox* self = (GUI::ListBox*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveItem'", NULL);
#endif
  {
   self->RemoveItem(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAllItems of class  GUI::ListBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListBox_RemoveAllItems00
static int tolua_GUI_GUI_ListBox_RemoveAllItems00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListBox* self = (GUI::ListBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAllItems'", NULL);
#endif
  {
   self->RemoveAllItems();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAllItems'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SwapItems of class  GUI::ListBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListBox_SwapItems00
static int tolua_GUI_GUI_ListBox_SwapItems00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListBox* self = (GUI::ListBox*)  tolua_tousertype(tolua_S,1,0);
    int index1 = ((   int)  tolua_tonumber(tolua_S,2,0));
    int index2 = ((   int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SwapItems'", NULL);
#endif
  {
   self->SwapItems(index1,index2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SwapItems'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FindItemIndexWith of class  GUI::ListBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListBox_FindItemIndexWith00
static int tolua_GUI_GUI_ListBox_FindItemIndexWith00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListBox",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListBox* self = (GUI::ListBox*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindItemIndexWith'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->FindItemIndexWith(*name);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindItemIndexWith'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIndexSelected of class  GUI::ListBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListBox_GetIndexSelected00
static int tolua_GUI_GUI_ListBox_GetIndexSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListBox* self = (GUI::ListBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIndexSelected'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetIndexSelected();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIndexSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetIndexSelected of class  GUI::ListBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListBox_SetIndexSelected00
static int tolua_GUI_GUI_ListBox_SetIndexSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListBox* self = (GUI::ListBox*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetIndexSelected'", NULL);
#endif
  {
   self->SetIndexSelected(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetIndexSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearIndexSelected of class  GUI::ListBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListBox_ClearIndexSelected00
static int tolua_GUI_GUI_ListBox_ClearIndexSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListBox* self = (GUI::ListBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearIndexSelected'", NULL);
#endif
  {
   self->ClearIndexSelected();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearIndexSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemData of class  GUI::ListBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListBox_SetItemData00
static int tolua_GUI_GUI_ListBox_SetItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListBox* self = (GUI::ListBox*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemData'", NULL);
#endif
  {
   self->SetItemData(index,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearItemData of class  GUI::ListBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListBox_ClearItemData00
static int tolua_GUI_GUI_ListBox_ClearItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListBox* self = (GUI::ListBox*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearItemData'", NULL);
#endif
  {
   self->ClearItemData(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemData of class  GUI::ListBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListBox_GetItemData00
static int tolua_GUI_GUI_ListBox_GetItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListBox* self = (GUI::ListBox*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemData'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->GetItemData(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemName of class  GUI::ListBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListBox_SetItemName00
static int tolua_GUI_GUI_ListBox_SetItemName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListBox* self = (GUI::ListBox*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemName'", NULL);
#endif
  {
   self->SetItemName(index,*name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemName of class  GUI::ListBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListBox_GetItemName00
static int tolua_GUI_GUI_ListBox_GetItemName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListBox* self = (GUI::ListBox*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemName'", NULL);
#endif
  {
   const GUI::UString& tolua_ret = (const GUI::UString&)  self->GetItemName(index);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const GUI::UString");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BeginToItem of class  GUI::ListBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListBox_BeginToItem00
static int tolua_GUI_GUI_ListBox_BeginToItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListBox* self = (GUI::ListBox*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BeginToItem'", NULL);
#endif
  {
   self->BeginToItem(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginToItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BeginToItemFirst of class  GUI::ListBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListBox_BeginToItemFirst00
static int tolua_GUI_GUI_ListBox_BeginToItemFirst00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListBox* self = (GUI::ListBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BeginToItemFirst'", NULL);
#endif
  {
   self->BeginToItemFirst();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginToItemFirst'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BeginToItemLast of class  GUI::ListBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListBox_BeginToItemLast00
static int tolua_GUI_GUI_ListBox_BeginToItemLast00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListBox* self = (GUI::ListBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BeginToItemLast'", NULL);
#endif
  {
   self->BeginToItemLast();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginToItemLast'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BeginToItemSelected of class  GUI::ListBox */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListBox_BeginToItemSelected00
static int tolua_GUI_GUI_ListBox_BeginToItemSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListBox* self = (GUI::ListBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BeginToItemSelected'", NULL);
#endif
  {
   self->BeginToItemSelected();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginToItemSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemCount of class  GUI::ListCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListCtrl_GetItemCount00
static int tolua_GUI_GUI_ListCtrl_GetItemCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::ListCtrl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::ListCtrl* self = (const GUI::ListCtrl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemCount'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetItemCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InsertItem of class  GUI::ListCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListCtrl_InsertItem00
static int tolua_GUI_GUI_ListCtrl_InsertItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"GUI::Widget",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListCtrl* self = (GUI::ListCtrl*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,3,nullptr));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InsertItem'", NULL);
#endif
  {
   self->InsertItem(index,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InsertItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AppendItem of class  GUI::ListCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListCtrl_AppendItem00
static int tolua_GUI_GUI_ListCtrl_AppendItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListCtrl",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::Widget",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListCtrl* self = (GUI::ListCtrl*)  tolua_tousertype(tolua_S,1,0);
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,2,nullptr));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AppendItem'", NULL);
#endif
  {
   self->AppendItem(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AppendItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveItem of class  GUI::ListCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListCtrl_RemoveItem00
static int tolua_GUI_GUI_ListCtrl_RemoveItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListCtrl* self = (GUI::ListCtrl*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveItem'", NULL);
#endif
  {
   self->RemoveItem(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAllItems of class  GUI::ListCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListCtrl_RemoveAllItems00
static int tolua_GUI_GUI_ListCtrl_RemoveAllItems00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListCtrl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListCtrl* self = (GUI::ListCtrl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAllItems'", NULL);
#endif
  {
   self->RemoveAllItems();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAllItems'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RedrawItem of class  GUI::ListCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListCtrl_RedrawItem00
static int tolua_GUI_GUI_ListCtrl_RedrawItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListCtrl* self = (GUI::ListCtrl*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RedrawItem'", NULL);
#endif
  {
   self->RedrawItem(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RedrawItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RedrawAllItems of class  GUI::ListCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListCtrl_RedrawAllItems00
static int tolua_GUI_GUI_ListCtrl_RedrawAllItems00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListCtrl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListCtrl* self = (GUI::ListCtrl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RedrawAllItems'", NULL);
#endif
  {
   self->RedrawAllItems();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RedrawAllItems'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIndexSelected of class  GUI::ListCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListCtrl_GetIndexSelected00
static int tolua_GUI_GUI_ListCtrl_GetIndexSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListCtrl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListCtrl* self = (GUI::ListCtrl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIndexSelected'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetIndexSelected();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIndexSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetIndexSelected of class  GUI::ListCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListCtrl_SetIndexSelected00
static int tolua_GUI_GUI_ListCtrl_SetIndexSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListCtrl* self = (GUI::ListCtrl*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetIndexSelected'", NULL);
#endif
  {
   self->SetIndexSelected(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetIndexSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearIndexSelected of class  GUI::ListCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListCtrl_ClearIndexSelected00
static int tolua_GUI_GUI_ListCtrl_ClearIndexSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListCtrl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListCtrl* self = (GUI::ListCtrl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearIndexSelected'", NULL);
#endif
  {
   self->ClearIndexSelected();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearIndexSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemData of class  GUI::ListCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListCtrl_SetItemData00
static int tolua_GUI_GUI_ListCtrl_SetItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListCtrl* self = (GUI::ListCtrl*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemData'", NULL);
#endif
  {
   self->SetItemData(index,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearItemData of class  GUI::ListCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListCtrl_ClearItemData00
static int tolua_GUI_GUI_ListCtrl_ClearItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListCtrl* self = (GUI::ListCtrl*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearItemData'", NULL);
#endif
  {
   self->ClearItemData(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemData of class  GUI::ListCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListCtrl_GetItemData00
static int tolua_GUI_GUI_ListCtrl_GetItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListCtrl* self = (GUI::ListCtrl*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemData'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->GetItemData(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIndexByWidget of class  GUI::ListCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListCtrl_GetIndexByWidget00
static int tolua_GUI_GUI_ListCtrl_GetIndexByWidget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListCtrl",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListCtrl* self = (GUI::ListCtrl*)  tolua_tousertype(tolua_S,1,0);
  GUI::Widget* widget = ((GUI::Widget*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIndexByWidget'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetIndexByWidget(widget);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIndexByWidget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWidgetDrag of class  GUI::ListCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListCtrl_GetWidgetDrag00
static int tolua_GUI_GUI_ListCtrl_GetWidgetDrag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListCtrl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListCtrl* self = (GUI::ListCtrl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWidgetDrag'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->GetWidgetDrag();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWidgetDrag'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWidgetByIndex of class  GUI::ListCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListCtrl_GetWidgetByIndex00
static int tolua_GUI_GUI_ListCtrl_GetWidgetByIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListCtrl* self = (GUI::ListCtrl*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWidgetByIndex'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->GetWidgetByIndex(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWidgetByIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResetDrag of class  GUI::ListCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListCtrl_ResetDrag00
static int tolua_GUI_GUI_ListCtrl_ResetDrag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListCtrl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListCtrl* self = (GUI::ListCtrl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResetDrag'", NULL);
#endif
  {
   self->ResetDrag();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ResetDrag'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  GUI::ListCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListCtrl_SetPosition00
static int tolua_GUI_GUI_ListCtrl_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListCtrl* self = (GUI::ListCtrl*)  tolua_tousertype(tolua_S,1,0);
  int left = ((int)  tolua_tonumber(tolua_S,2,0));
  int top = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
  {
   self->SetPosition(left,top);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSize of class  GUI::ListCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListCtrl_SetSize00
static int tolua_GUI_GUI_ListCtrl_SetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListCtrl* self = (GUI::ListCtrl*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSize'", NULL);
#endif
  {
   self->SetSize(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCoord of class  GUI::ListCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ListCtrl_SetCoord00
static int tolua_GUI_GUI_ListCtrl_SetCoord00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ListCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ListCtrl* self = (GUI::ListCtrl*)  tolua_tousertype(tolua_S,1,0);
  int left = ((int)  tolua_tonumber(tolua_S,2,0));
  int top = ((int)  tolua_tonumber(tolua_S,3,0));
  int width = ((int)  tolua_tonumber(tolua_S,4,0));
  int height = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCoord'", NULL);
#endif
  {
   self->SetCoord(left,top,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCoord'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVisible of class  GUI::MenuBar */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuBar_SetVisible00
static int tolua_GUI_GUI_MenuBar_SetVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuBar",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuBar* self = (GUI::MenuBar*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVisible'", NULL);
#endif
  {
   self->SetVisible(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVisible of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_SetVisible00
static int tolua_GUI_GUI_MenuCtrl_SetVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVisible'", NULL);
#endif
  {
   self->SetVisible(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVisibleSmooth of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_SetVisibleSmooth00
static int tolua_GUI_GUI_MenuCtrl_SetVisibleSmooth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVisibleSmooth'", NULL);
#endif
  {
   self->SetVisibleSmooth(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVisibleSmooth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemCount of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_GetItemCount00
static int tolua_GUI_GUI_MenuCtrl_GetItemCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::MenuCtrl* self = (const GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemCount'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetItemCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InsertItem of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_InsertItem00
static int tolua_GUI_GUI_MenuCtrl_InsertItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"MenuItemType",1,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
  MenuItemType type = *((MenuItemType*)  tolua_tousertype(tolua_S,4,(void*)&(const MenuItemType)MenuItemType::Normal));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InsertItem'", NULL);
#endif
  {
   GUI::MenuItem* tolua_ret = (GUI::MenuItem*)  self->InsertItem(index,*name,type);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::MenuItem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InsertItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InsertItem of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_InsertItem01
static int tolua_GUI_GUI_MenuCtrl_InsertItem01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"MenuItemType",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,6,"GUI::Widget",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
  MenuItemType type = *((MenuItemType*)  tolua_tousertype(tolua_S,4,0));
  const std::string id = ((const std::string)  tolua_tocppstring(tolua_S,5,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,6,nullptr));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InsertItem'", NULL);
#endif
  {
   GUI::MenuItem* tolua_ret = (GUI::MenuItem*)  self->InsertItem(index,*name,type,id,value);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::MenuItem");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_MenuCtrl_InsertItem00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: InsertItemEx of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_InsertItemEx00
static int tolua_GUI_GUI_MenuCtrl_InsertItemEx00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::MenuItem",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"MenuItemType",1,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
  GUI::MenuItem* to = ((GUI::MenuItem*)  tolua_tousertype(tolua_S,2,0));
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
  MenuItemType type = *((MenuItemType*)  tolua_tousertype(tolua_S,4,(void*)&(const MenuItemType)MenuItemType::Normal));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InsertItemEx'", NULL);
#endif
  {
   GUI::MenuItem* tolua_ret = (GUI::MenuItem*)  self->InsertItemEx(to,*name,type);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::MenuItem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InsertItemEx'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InsertItemEx of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_InsertItemEx01
static int tolua_GUI_GUI_MenuCtrl_InsertItemEx01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::MenuItem",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"MenuItemType",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,6,"GUI::Widget",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
  GUI::MenuItem* to = ((GUI::MenuItem*)  tolua_tousertype(tolua_S,2,0));
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
  MenuItemType type = *((MenuItemType*)  tolua_tousertype(tolua_S,4,0));
  const std::string id = ((const std::string)  tolua_tocppstring(tolua_S,5,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,6,nullptr));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InsertItemEx'", NULL);
#endif
  {
   GUI::MenuItem* tolua_ret = (GUI::MenuItem*)  self->InsertItemEx(to,*name,type,id,value);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::MenuItem");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_MenuCtrl_InsertItemEx00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AppendItem of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_AppendItem00
static int tolua_GUI_GUI_MenuCtrl_AppendItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"MenuItemType",1,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
  MenuItemType type = *((MenuItemType*)  tolua_tousertype(tolua_S,3,(void*)&(const MenuItemType)MenuItemType::Normal));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AppendItem'", NULL);
#endif
  {
   GUI::MenuItem* tolua_ret = (GUI::MenuItem*)  self->AppendItem(*name,type);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::MenuItem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AppendItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AppendItem of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_AppendItem01
static int tolua_GUI_GUI_MenuCtrl_AppendItem01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"MenuItemType",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"GUI::Widget",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
  MenuItemType type = *((MenuItemType*)  tolua_tousertype(tolua_S,3,0));
  const std::string id = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,5,nullptr));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AppendItem'", NULL);
#endif
  {
   GUI::MenuItem* tolua_ret = (GUI::MenuItem*)  self->AppendItem(*name,type,id,value);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::MenuItem");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_MenuCtrl_AppendItem00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveItem of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_RemoveItem00
static int tolua_GUI_GUI_MenuCtrl_RemoveItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveItem'", NULL);
#endif
  {
   self->RemoveItem(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveItem of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_RemoveItem01
static int tolua_GUI_GUI_MenuCtrl_RemoveItem01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::MenuItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
  GUI::MenuItem* item = ((GUI::MenuItem*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveItem'", NULL);
#endif
  {
   self->RemoveItem(item);
  }
 }
 return 0;
tolua_lerror:
 return tolua_GUI_GUI_MenuCtrl_RemoveItem00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAllItems of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_RemoveAllItems00
static int tolua_GUI_GUI_MenuCtrl_RemoveAllItems00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAllItems'", NULL);
#endif
  {
   self->RemoveAllItems();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAllItems'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItem of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_GetItem00
static int tolua_GUI_GUI_MenuCtrl_GetItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItem'", NULL);
#endif
  {
   GUI::MenuItem* tolua_ret = (GUI::MenuItem*)  self->GetItem(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::MenuItem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemIndex of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_GetItemIndex00
static int tolua_GUI_GUI_MenuCtrl_GetItemIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::MenuItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
  GUI::MenuItem* item = ((GUI::MenuItem*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemIndex'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetItemIndex(item);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FindItemIndex of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_FindItemIndex00
static int tolua_GUI_GUI_MenuCtrl_FindItemIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::MenuItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
  GUI::MenuItem* item = ((GUI::MenuItem*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindItemIndex'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->FindItemIndex(item);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindItemIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FindItemWith of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_FindItemWith00
static int tolua_GUI_GUI_MenuCtrl_FindItemWith00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindItemWith'", NULL);
#endif
  {
   GUI::MenuItem* tolua_ret = (GUI::MenuItem*)  self->FindItemWith(*name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::MenuItem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindItemWith'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemData of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_SetItemData00
static int tolua_GUI_GUI_MenuCtrl_SetItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemData'", NULL);
#endif
  {
   self->SetItemData(index,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemData of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_SetItemData01
static int tolua_GUI_GUI_MenuCtrl_SetItemData01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::MenuItem",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
  GUI::MenuItem* item = ((GUI::MenuItem*)  tolua_tousertype(tolua_S,2,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemData'", NULL);
#endif
  {
   self->SetItemData(item,value);
  }
 }
 return 0;
tolua_lerror:
 return tolua_GUI_GUI_MenuCtrl_SetItemData00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearItemData of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_ClearItemData00
static int tolua_GUI_GUI_MenuCtrl_ClearItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearItemData'", NULL);
#endif
  {
   self->ClearItemData(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearItemData of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_ClearItemData01
static int tolua_GUI_GUI_MenuCtrl_ClearItemData01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::MenuItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
  GUI::MenuItem* item = ((GUI::MenuItem*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearItemData'", NULL);
#endif
  {
   self->ClearItemData(item);
  }
 }
 return 0;
tolua_lerror:
 return tolua_GUI_GUI_MenuCtrl_ClearItemData00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemData of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_GetItemData00
static int tolua_GUI_GUI_MenuCtrl_GetItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemData'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->GetItemData(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemDataEx of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_GetItemDataEx00
static int tolua_GUI_GUI_MenuCtrl_GetItemDataEx00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::MenuItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
  GUI::MenuItem* item = ((GUI::MenuItem*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemDataEx'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->GetItemDataEx(item);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemDataEx'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemID of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_SetItemID00
static int tolua_GUI_GUI_MenuCtrl_SetItemID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  const std::string id = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemID'", NULL);
#endif
  {
   self->SetItemID(index,id);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemId of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_SetItemId00
static int tolua_GUI_GUI_MenuCtrl_SetItemId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::MenuItem",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
  GUI::MenuItem* item = ((GUI::MenuItem*)  tolua_tousertype(tolua_S,2,0));
  const std::string id = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemId'", NULL);
#endif
  {
   self->SetItemId(item,id);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemID of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_GetItemID00
static int tolua_GUI_GUI_MenuCtrl_GetItemID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemID'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetItemID(index);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemId of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_GetItemId00
static int tolua_GUI_GUI_MenuCtrl_GetItemId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::MenuItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
  GUI::MenuItem* item = ((GUI::MenuItem*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemId'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetItemId(item);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemById of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_GetItemById00
static int tolua_GUI_GUI_MenuCtrl_GetItemById00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
  const std::string id = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemById'", NULL);
#endif
  {
   GUI::MenuItem* tolua_ret = (GUI::MenuItem*)  self->GetItemById(id);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::MenuItem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemById'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemIndexById of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_GetItemIndexById00
static int tolua_GUI_GUI_MenuCtrl_GetItemIndexById00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
  const std::string id = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemIndexById'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetItemIndexById(id);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemIndexById'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemName of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_SetItemName00
static int tolua_GUI_GUI_MenuCtrl_SetItemName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemName'", NULL);
#endif
  {
   self->SetItemName(index,*name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemName of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_SetItemName01
static int tolua_GUI_GUI_MenuCtrl_SetItemName01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::MenuItem",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
  GUI::MenuItem* item = ((GUI::MenuItem*)  tolua_tousertype(tolua_S,2,0));
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemName'", NULL);
#endif
  {
   self->SetItemName(item,*name);
  }
 }
 return 0;
tolua_lerror:
 return tolua_GUI_GUI_MenuCtrl_SetItemName00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemName of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_GetItemName00
static int tolua_GUI_GUI_MenuCtrl_GetItemName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemName'", NULL);
#endif
  {
   const GUI::UString& tolua_ret = (const GUI::UString&)  self->GetItemName(index);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const GUI::UString");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemName of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_GetItemName01
static int tolua_GUI_GUI_MenuCtrl_GetItemName01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::MenuItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
  GUI::MenuItem* item = ((GUI::MenuItem*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemName'", NULL);
#endif
  {
   const GUI::UString& tolua_ret = (const GUI::UString&)  self->GetItemName(item);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const GUI::UString");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_MenuCtrl_GetItemName00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: FindItemIndexWith of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_FindItemIndexWith00
static int tolua_GUI_GUI_MenuCtrl_FindItemIndexWith00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindItemIndexWith'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->FindItemIndexWith(*name);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindItemIndexWith'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemChildVisible of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_SetItemChildVisible00
static int tolua_GUI_GUI_MenuCtrl_SetItemChildVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  bool visible = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemChildVisible'", NULL);
#endif
  {
   self->SetItemChildVisible(index,visible);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemChildVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemChildVisible of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_SetItemChildVisible01
static int tolua_GUI_GUI_MenuCtrl_SetItemChildVisible01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::MenuItem",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
  GUI::MenuItem* item = ((GUI::MenuItem*)  tolua_tousertype(tolua_S,2,0));
  bool visible = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemChildVisible'", NULL);
#endif
  {
   self->SetItemChildVisible(item,visible);
  }
 }
 return 0;
tolua_lerror:
 return tolua_GUI_GUI_MenuCtrl_SetItemChildVisible00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemChild of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_GetItemChild00
static int tolua_GUI_GUI_MenuCtrl_GetItemChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemChild'", NULL);
#endif
  {
   GUI::MenuCtrl* tolua_ret = (GUI::MenuCtrl*)  self->GetItemChild(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::MenuCtrl");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemChild of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_GetItemChild01
static int tolua_GUI_GUI_MenuCtrl_GetItemChild01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::MenuItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
  GUI::MenuItem* item = ((GUI::MenuItem*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemChild'", NULL);
#endif
  {
   GUI::MenuCtrl* tolua_ret = (GUI::MenuCtrl*)  self->GetItemChild(item);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::MenuCtrl");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_MenuCtrl_GetItemChild00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateItemChild of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_CreateItemChild00
static int tolua_GUI_GUI_MenuCtrl_CreateItemChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateItemChild'", NULL);
#endif
  {
   GUI::MenuCtrl* tolua_ret = (GUI::MenuCtrl*)  self->CreateItemChild(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::MenuCtrl");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateItemChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateItemChild of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_CreateItemChild01
static int tolua_GUI_GUI_MenuCtrl_CreateItemChild01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::MenuItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
  GUI::MenuItem* item = ((GUI::MenuItem*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateItemChild'", NULL);
#endif
  {
   GUI::MenuCtrl* tolua_ret = (GUI::MenuCtrl*)  self->CreateItemChild(item);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::MenuCtrl");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_MenuCtrl_CreateItemChild00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveItemChild of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_RemoveItemChild00
static int tolua_GUI_GUI_MenuCtrl_RemoveItemChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveItemChild'", NULL);
#endif
  {
   self->RemoveItemChild(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveItemChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveItemChild of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_RemoveItemChild01
static int tolua_GUI_GUI_MenuCtrl_RemoveItemChild01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::MenuItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
  GUI::MenuItem* item = ((GUI::MenuItem*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveItemChild'", NULL);
#endif
  {
   self->RemoveItemChild(item);
  }
 }
 return 0;
tolua_lerror:
 return tolua_GUI_GUI_MenuCtrl_RemoveItemChild00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemType of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_GetItemType00
static int tolua_GUI_GUI_MenuCtrl_GetItemType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemType'", NULL);
#endif
  {
   MenuItemType tolua_ret = (MenuItemType)  self->GetItemType(index);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((MenuItemType)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"MenuItemType");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(MenuItemType));
     tolua_pushusertype(tolua_S,tolua_obj,"MenuItemType");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemType of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_GetItemType01
static int tolua_GUI_GUI_MenuCtrl_GetItemType01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::MenuItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
  GUI::MenuItem* item = ((GUI::MenuItem*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemType'", NULL);
#endif
  {
   MenuItemType tolua_ret = (MenuItemType)  self->GetItemType(item);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((MenuItemType)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"MenuItemType");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(MenuItemType));
     tolua_pushusertype(tolua_S,tolua_obj,"MenuItemType");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_MenuCtrl_GetItemType00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemType of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_SetItemType00
static int tolua_GUI_GUI_MenuCtrl_SetItemType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"MenuItemType",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  MenuItemType type = *((MenuItemType*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemType'", NULL);
#endif
  {
   self->SetItemType(index,type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemType of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_SetItemType01
static int tolua_GUI_GUI_MenuCtrl_SetItemType01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::MenuItem",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"MenuItemType",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
  GUI::MenuItem* item = ((GUI::MenuItem*)  tolua_tousertype(tolua_S,2,0));
  MenuItemType type = *((MenuItemType*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemType'", NULL);
#endif
  {
   self->SetItemType(item,type);
  }
 }
 return 0;
tolua_lerror:
 return tolua_GUI_GUI_MenuCtrl_SetItemType00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPopupAccept of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_SetPopupAccept00
static int tolua_GUI_GUI_MenuCtrl_SetPopupAccept00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPopupAccept'", NULL);
#endif
  {
   self->SetPopupAccept(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPopupAccept'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPopupAccept of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_GetPopupAccept00
static int tolua_GUI_GUI_MenuCtrl_GetPopupAccept00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPopupAccept'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetPopupAccept();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPopupAccept'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMenuItemParent of class  GUI::MenuCtrl */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuCtrl_GetMenuItemParent00
static int tolua_GUI_GUI_MenuCtrl_GetMenuItemParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuCtrl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuCtrl* self = (GUI::MenuCtrl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMenuItemParent'", NULL);
#endif
  {
   GUI::MenuItem* tolua_ret = (GUI::MenuItem*)  self->GetMenuItemParent();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::MenuItem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMenuItemParent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCaption of class  GUI::MenuItem */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuItem_SetCaption00
static int tolua_GUI_GUI_MenuItem_SetCaption00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuItem",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuItem* self = (GUI::MenuItem*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* value = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCaption'", NULL);
#endif
  {
   self->SetCaption(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCaption'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemName of class  GUI::MenuItem */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuItem_SetItemName00
static int tolua_GUI_GUI_MenuItem_SetItemName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuItem",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuItem* self = (GUI::MenuItem*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* value = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemName'", NULL);
#endif
  {
   self->SetItemName(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemName of class  GUI::MenuItem */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuItem_GetItemName00
static int tolua_GUI_GUI_MenuItem_GetItemName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuItem* self = (GUI::MenuItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemName'", NULL);
#endif
  {
   const GUI::UString& tolua_ret = (const GUI::UString&)  self->GetItemName();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const GUI::UString");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemData of class  GUI::MenuItem */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuItem_SetItemData00
static int tolua_GUI_GUI_MenuItem_SetItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuItem",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuItem* self = (GUI::MenuItem*)  tolua_tousertype(tolua_S,1,0);
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemData'", NULL);
#endif
  {
   self->SetItemData(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemDataEx of class  GUI::MenuItem */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuItem_GetItemDataEx00
static int tolua_GUI_GUI_MenuItem_GetItemDataEx00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuItem* self = (GUI::MenuItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemDataEx'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->GetItemDataEx();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemDataEx'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveItem of class  GUI::MenuItem */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuItem_RemoveItem00
static int tolua_GUI_GUI_MenuItem_RemoveItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuItem* self = (GUI::MenuItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveItem'", NULL);
#endif
  {
   self->RemoveItem();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemId of class  GUI::MenuItem */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuItem_SetItemId00
static int tolua_GUI_GUI_MenuItem_SetItemId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuItem",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuItem* self = (GUI::MenuItem*)  tolua_tousertype(tolua_S,1,0);
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemId'", NULL);
#endif
  {
   self->SetItemId(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemId of class  GUI::MenuItem */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuItem_GetItemId00
static int tolua_GUI_GUI_MenuItem_GetItemId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuItem* self = (GUI::MenuItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemId'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetItemId();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemIndex of class  GUI::MenuItem */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuItem_GetItemIndex00
static int tolua_GUI_GUI_MenuItem_GetItemIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuItem* self = (GUI::MenuItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemIndex'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetItemIndex();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateItemChild of class  GUI::MenuItem */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuItem_CreateItemChild00
static int tolua_GUI_GUI_MenuItem_CreateItemChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuItem* self = (GUI::MenuItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateItemChild'", NULL);
#endif
  {
   GUI::MenuCtrl* tolua_ret = (GUI::MenuCtrl*)  self->CreateItemChild();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::MenuCtrl");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateItemChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemType of class  GUI::MenuItem */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuItem_SetItemType00
static int tolua_GUI_GUI_MenuItem_SetItemType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuItem",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"MenuItemType",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuItem* self = (GUI::MenuItem*)  tolua_tousertype(tolua_S,1,0);
  MenuItemType value = *((MenuItemType*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemType'", NULL);
#endif
  {
   self->SetItemType(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemType of class  GUI::MenuItem */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuItem_GetItemType00
static int tolua_GUI_GUI_MenuItem_GetItemType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuItem* self = (GUI::MenuItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemType'", NULL);
#endif
  {
   MenuItemType tolua_ret = (MenuItemType)  self->GetItemType();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((MenuItemType)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"MenuItemType");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(MenuItemType));
     tolua_pushusertype(tolua_S,tolua_obj,"MenuItemType");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemChildVisible of class  GUI::MenuItem */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuItem_SetItemChildVisible00
static int tolua_GUI_GUI_MenuItem_SetItemChildVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuItem",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuItem* self = (GUI::MenuItem*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemChildVisible'", NULL);
#endif
  {
   self->SetItemChildVisible(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemChildVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMenuCtrlParent of class  GUI::MenuItem */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuItem_GetMenuCtrlParent00
static int tolua_GUI_GUI_MenuItem_GetMenuCtrlParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuItem* self = (GUI::MenuItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMenuCtrlParent'", NULL);
#endif
  {
   GUI::MenuCtrl* tolua_ret = (GUI::MenuCtrl*)  self->GetMenuCtrlParent();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::MenuCtrl");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMenuCtrlParent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemChild of class  GUI::MenuItem */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuItem_GetItemChild00
static int tolua_GUI_GUI_MenuItem_GetItemChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuItem* self = (GUI::MenuItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemChild'", NULL);
#endif
  {
   GUI::MenuCtrl* tolua_ret = (GUI::MenuCtrl*)  self->GetItemChild();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::MenuCtrl");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetProperty of class  GUI::MenuItem */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MenuItem_SetProperty00
static int tolua_GUI_GUI_MenuItem_SetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MenuItem",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MenuItem* self = (GUI::MenuItem*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetProperty'", NULL);
#endif
  {
   self->SetProperty(key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMessageText of class  GUI::Message */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Message_SetMessageText00
static int tolua_GUI_GUI_Message_SetMessageText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Message",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Message* self = (GUI::Message*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* value = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMessageText'", NULL);
#endif
  {
   self->SetMessageText(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMessageText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddButtonName of class  GUI::Message */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Message_AddButtonName00
static int tolua_GUI_GUI_Message_AddButtonName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Message",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Message* self = (GUI::Message*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddButtonName'", NULL);
#endif
  {
   GUI::MessageBoxStyle tolua_ret = (GUI::MessageBoxStyle)  self->AddButtonName(*name);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::MessageBoxStyle)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::MessageBoxStyle");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::MessageBoxStyle));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::MessageBoxStyle");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddButtonName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSmoothShow of class  GUI::Message */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Message_SetSmoothShow00
static int tolua_GUI_GUI_Message_SetSmoothShow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Message",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Message* self = (GUI::Message*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSmoothShow'", NULL);
#endif
  {
   self->SetSmoothShow(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSmoothShow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDefaultLayer of class  GUI::Message */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Message_GetDefaultLayer00
static int tolua_GUI_GUI_Message_GetDefaultLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Message",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Message* self = (GUI::Message*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDefaultLayer'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetDefaultLayer();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDefaultLayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMessageIcon of class  GUI::Message */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Message_SetMessageIcon00
static int tolua_GUI_GUI_Message_SetMessageIcon00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Message",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GUI::MessageBoxStyle",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Message* self = (GUI::Message*)  tolua_tousertype(tolua_S,1,0);
  GUI::MessageBoxStyle value = *((GUI::MessageBoxStyle*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMessageIcon'", NULL);
#endif
  {
   self->SetMessageIcon(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMessageIcon'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWindowFade of class  GUI::Message */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Message_SetWindowFade00
static int tolua_GUI_GUI_Message_SetWindowFade00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Message",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Message* self = (GUI::Message*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWindowFade'", NULL);
#endif
  {
   self->SetWindowFade(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWindowFade'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: endMessage of class  GUI::Message */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Message_endMessage00
static int tolua_GUI_GUI_Message_endMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Message",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GUI::MessageBoxStyle",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Message* self = (GUI::Message*)  tolua_tousertype(tolua_S,1,0);
  GUI::MessageBoxStyle result = *((GUI::MessageBoxStyle*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'endMessage'", NULL);
#endif
  {
   self->endMessage(result);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'endMessage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: endMessage of class  GUI::Message */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Message_endMessage01
static int tolua_GUI_GUI_Message_endMessage01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Message",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::Message* self = (GUI::Message*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'endMessage'", NULL);
#endif
  {
   self->endMessage();
  }
 }
 return 0;
tolua_lerror:
 return tolua_GUI_GUI_Message_endMessage00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMessageButton of class  GUI::Message */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Message_SetMessageButton00
static int tolua_GUI_GUI_Message_SetMessageButton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Message",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GUI::MessageBoxStyle",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Message* self = (GUI::Message*)  tolua_tousertype(tolua_S,1,0);
  GUI::MessageBoxStyle value = *((GUI::MessageBoxStyle*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMessageButton'", NULL);
#endif
  {
   self->SetMessageButton(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMessageButton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMessageStyle of class  GUI::Message */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Message_SetMessageStyle00
static int tolua_GUI_GUI_Message_SetMessageStyle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Message",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GUI::MessageBoxStyle",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Message* self = (GUI::Message*)  tolua_tousertype(tolua_S,1,0);
  GUI::MessageBoxStyle value = *((GUI::MessageBoxStyle*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMessageStyle'", NULL);
#endif
  {
   self->SetMessageStyle(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMessageStyle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMessageModal of class  GUI::Message */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Message_SetMessageModal00
static int tolua_GUI_GUI_Message_SetMessageModal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Message",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Message* self = (GUI::Message*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMessageModal'", NULL);
#endif
  {
   self->SetMessageModal(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMessageModal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateMessageBox of class  GUI::Message */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Message_CreateMessageBox00
static int tolua_GUI_GUI_Message_CreateMessageBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::Message",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string skin = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const GUI::UString* caption = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
  const GUI::UString* message = ((const GUI::UString*)  tolua_tousertype(tolua_S,4,0));
  {
   GUI::Message* tolua_ret = (GUI::Message*)  GUI::Message::CreateMessageBox(skin,*caption,*message);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Message");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateMessageBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateMessageBox of class  GUI::Message */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Message_CreateMessageBox01
static int tolua_GUI_GUI_Message_CreateMessageBox01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::Message",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const GUI::UString",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"GUI::MessageBoxStyle",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const std::string skin = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const GUI::UString* caption = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
  const GUI::UString* message = ((const GUI::UString*)  tolua_tousertype(tolua_S,4,0));
  GUI::MessageBoxStyle style = *((GUI::MessageBoxStyle*)  tolua_tousertype(tolua_S,5,0));
  {
   GUI::Message* tolua_ret = (GUI::Message*)  GUI::Message::CreateMessageBox(skin,*caption,*message,style);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Message");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_Message_CreateMessageBox00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateMessageBox of class  GUI::Message */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Message_CreateMessageBox02
static int tolua_GUI_GUI_Message_CreateMessageBox02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::Message",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const GUI::UString",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"GUI::MessageBoxStyle",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,6,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const std::string skin = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const GUI::UString* caption = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
  const GUI::UString* message = ((const GUI::UString*)  tolua_tousertype(tolua_S,4,0));
  GUI::MessageBoxStyle style = *((GUI::MessageBoxStyle*)  tolua_tousertype(tolua_S,5,0));
  const std::string layer = ((const std::string)  tolua_tocppstring(tolua_S,6,0));
  bool modal = ((bool)  tolua_toboolean(tolua_S,7,true));
  {
   GUI::Message* tolua_ret = (GUI::Message*)  GUI::Message::CreateMessageBox(skin,*caption,*message,style,layer,modal);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Message");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_Message_CreateMessageBox01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateMessageBox of class  GUI::Message */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Message_CreateMessageBox03
static int tolua_GUI_GUI_Message_CreateMessageBox03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::Message",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const GUI::UString",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"GUI::MessageBoxStyle",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,6,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,8,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const std::string skin = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const GUI::UString* caption = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
  const GUI::UString* message = ((const GUI::UString*)  tolua_tousertype(tolua_S,4,0));
  GUI::MessageBoxStyle style = *((GUI::MessageBoxStyle*)  tolua_tousertype(tolua_S,5,0));
  const std::string layer = ((const std::string)  tolua_tocppstring(tolua_S,6,0));
  bool modal = ((bool)  tolua_toboolean(tolua_S,7,0));
  const std::string button1 = ((const std::string)  tolua_tocppstring(tolua_S,8,0));
  {
   GUI::Message* tolua_ret = (GUI::Message*)  GUI::Message::CreateMessageBox(skin,*caption,*message,style,layer,modal,button1);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Message");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_Message_CreateMessageBox02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateMessageBox of class  GUI::Message */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Message_CreateMessageBox04
static int tolua_GUI_GUI_Message_CreateMessageBox04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::Message",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const GUI::UString",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"GUI::MessageBoxStyle",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,6,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,8,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,9,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,10,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const std::string skin = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const GUI::UString* caption = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
  const GUI::UString* message = ((const GUI::UString*)  tolua_tousertype(tolua_S,4,0));
  GUI::MessageBoxStyle style = *((GUI::MessageBoxStyle*)  tolua_tousertype(tolua_S,5,0));
  const std::string layer = ((const std::string)  tolua_tocppstring(tolua_S,6,0));
  bool modal = ((bool)  tolua_toboolean(tolua_S,7,0));
  const std::string button1 = ((const std::string)  tolua_tocppstring(tolua_S,8,0));
  const std::string button2 = ((const std::string)  tolua_tocppstring(tolua_S,9,0));
  {
   GUI::Message* tolua_ret = (GUI::Message*)  GUI::Message::CreateMessageBox(skin,*caption,*message,style,layer,modal,button1,button2);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Message");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_Message_CreateMessageBox03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateMessageBox of class  GUI::Message */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Message_CreateMessageBox05
static int tolua_GUI_GUI_Message_CreateMessageBox05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::Message",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const GUI::UString",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"GUI::MessageBoxStyle",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,6,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,8,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,9,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,10,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,11,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const std::string skin = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const GUI::UString* caption = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
  const GUI::UString* message = ((const GUI::UString*)  tolua_tousertype(tolua_S,4,0));
  GUI::MessageBoxStyle style = *((GUI::MessageBoxStyle*)  tolua_tousertype(tolua_S,5,0));
  const std::string layer = ((const std::string)  tolua_tocppstring(tolua_S,6,0));
  bool modal = ((bool)  tolua_toboolean(tolua_S,7,0));
  const std::string button1 = ((const std::string)  tolua_tocppstring(tolua_S,8,0));
  const std::string button2 = ((const std::string)  tolua_tocppstring(tolua_S,9,0));
  const std::string button3 = ((const std::string)  tolua_tocppstring(tolua_S,10,0));
  {
   GUI::Message* tolua_ret = (GUI::Message*)  GUI::Message::CreateMessageBox(skin,*caption,*message,style,layer,modal,button1,button2,button3);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Message");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_Message_CreateMessageBox04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateMessageBox of class  GUI::Message */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Message_CreateMessageBox06
static int tolua_GUI_GUI_Message_CreateMessageBox06(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::Message",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const GUI::UString",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"GUI::MessageBoxStyle",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,6,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,8,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,9,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,10,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,11,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,12,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const std::string skin = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const GUI::UString* caption = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
  const GUI::UString* message = ((const GUI::UString*)  tolua_tousertype(tolua_S,4,0));
  GUI::MessageBoxStyle style = *((GUI::MessageBoxStyle*)  tolua_tousertype(tolua_S,5,0));
  const std::string layer = ((const std::string)  tolua_tocppstring(tolua_S,6,0));
  bool modal = ((bool)  tolua_toboolean(tolua_S,7,0));
  const std::string button1 = ((const std::string)  tolua_tocppstring(tolua_S,8,0));
  const std::string button2 = ((const std::string)  tolua_tocppstring(tolua_S,9,0));
  const std::string button3 = ((const std::string)  tolua_tocppstring(tolua_S,10,0));
  const std::string button4 = ((const std::string)  tolua_tocppstring(tolua_S,11,0));
  {
   GUI::Message* tolua_ret = (GUI::Message*)  GUI::Message::CreateMessageBox(skin,*caption,*message,style,layer,modal,button1,button2,button3,button4);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Message");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_Message_CreateMessageBox05(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetProperty of class  GUI::Message */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Message_SetProperty00
static int tolua_GUI_GUI_Message_SetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Message",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Message* self = (GUI::Message*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetProperty'", NULL);
#endif
  {
   self->SetProperty(key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GUI::MessageBoxStyle */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MessageBoxStyle_new00
static int tolua_GUI_GUI_MessageBoxStyle_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::MessageBoxStyle",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MessageBoxStyle::Enum value = ((GUI::MessageBoxStyle::Enum) (int)  tolua_tonumber(tolua_S,2,GUI::MessageBoxStyle::None));
  {
   GUI::MessageBoxStyle* tolua_ret = (GUI::MessageBoxStyle*)  Mtolua_new((GUI::MessageBoxStyle)(value));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::MessageBoxStyle");
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

/* method: new_local of class  GUI::MessageBoxStyle */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MessageBoxStyle_new00_local
static int tolua_GUI_GUI_MessageBoxStyle_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::MessageBoxStyle",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MessageBoxStyle::Enum value = ((GUI::MessageBoxStyle::Enum) (int)  tolua_tonumber(tolua_S,2,GUI::MessageBoxStyle::None));
  {
   GUI::MessageBoxStyle* tolua_ret = (GUI::MessageBoxStyle*)  Mtolua_new((GUI::MessageBoxStyle)(value));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::MessageBoxStyle");
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

/* method: GetIconIndex of class  GUI::MessageBoxStyle */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MessageBoxStyle_GetIconIndex00
static int tolua_GUI_GUI_MessageBoxStyle_GetIconIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MessageBoxStyle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MessageBoxStyle* self = (GUI::MessageBoxStyle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIconIndex'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetIconIndex();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIconIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetButtonIndex of class  GUI::MessageBoxStyle */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MessageBoxStyle_GetButtonIndex00
static int tolua_GUI_GUI_MessageBoxStyle_GetButtonIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MessageBoxStyle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MessageBoxStyle* self = (GUI::MessageBoxStyle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetButtonIndex'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetButtonIndex();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetButtonIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Parse of class  GUI::MessageBoxStyle */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MessageBoxStyle_Parse00
static int tolua_GUI_GUI_MessageBoxStyle_Parse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::MessageBoxStyle",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   GUI::MessageBoxStyle tolua_ret = (GUI::MessageBoxStyle)  GUI::MessageBoxStyle::Parse(value);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::MessageBoxStyle)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::MessageBoxStyle");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::MessageBoxStyle));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::MessageBoxStyle");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Parse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetColumnCount of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_GetColumnCount00
static int tolua_GUI_GUI_MultiList_GetColumnCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetColumnCount'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetColumnCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetColumnCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InsetColumn of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_InsetColumn00
static int tolua_GUI_GUI_MultiList_InsetColumn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"GUI::Widget",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
    int column = ((   int)  tolua_tonumber(tolua_S,2,0));
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
  int width = ((int)  tolua_tonumber(tolua_S,4,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,5,nullptr));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InsetColumn'", NULL);
#endif
  {
   self->InsetColumn(column,*name,width,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InsetColumn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AppendColumn of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_AppendColumn00
static int tolua_GUI_GUI_MultiList_AppendColumn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"GUI::Widget",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
  int width = ((int)  tolua_tonumber(tolua_S,3,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,4,nullptr));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AppendColumn'", NULL);
#endif
  {
   self->AppendColumn(*name,width,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AppendColumn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveColumn of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_RemoveColumn00
static int tolua_GUI_GUI_MultiList_RemoveColumn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
    int column = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveColumn'", NULL);
#endif
  {
   self->RemoveColumn(column);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveColumn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAllColumns of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_RemoveAllColumns00
static int tolua_GUI_GUI_MultiList_RemoveAllColumns00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAllColumns'", NULL);
#endif
  {
   self->RemoveAllColumns();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAllColumns'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetColumnName of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_SetColumnName00
static int tolua_GUI_GUI_MultiList_SetColumnName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
    int column = ((   int)  tolua_tonumber(tolua_S,2,0));
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetColumnName'", NULL);
#endif
  {
   self->SetColumnName(column,*name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetColumnName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetColumnWidth of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_SetColumnWidth00
static int tolua_GUI_GUI_MultiList_SetColumnWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
    int column = ((   int)  tolua_tonumber(tolua_S,2,0));
  int width = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetColumnWidth'", NULL);
#endif
  {
   self->SetColumnWidth(column,width);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetColumnWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetColumnName of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_GetColumnName00
static int tolua_GUI_GUI_MultiList_GetColumnName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
    int column = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetColumnName'", NULL);
#endif
  {
   const GUI::UString& tolua_ret = (const GUI::UString&)  self->GetColumnName(column);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const GUI::UString");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetColumnName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetColulmnWidth of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_GetColulmnWidth00
static int tolua_GUI_GUI_MultiList_GetColulmnWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
    int column = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetColulmnWidth'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetColulmnWidth(column);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetColulmnWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SortByColumn of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_SortByColumn00
static int tolua_GUI_GUI_MultiList_SortByColumn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
    int column = ((   int)  tolua_tonumber(tolua_S,2,0));
  bool backward = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SortByColumn'", NULL);
#endif
  {
   self->SortByColumn(column,backward);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SortByColumn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetColumnData of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_SetColumnData00
static int tolua_GUI_GUI_MultiList_SetColumnData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetColumnData'", NULL);
#endif
  {
   self->SetColumnData(index,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetColumnData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearColumnData of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_ClearColumnData00
static int tolua_GUI_GUI_MultiList_ClearColumnData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearColumnData'", NULL);
#endif
  {
   self->ClearColumnData(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearColumnData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetColumnData of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_GetColumnData00
static int tolua_GUI_GUI_MultiList_GetColumnData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetColumnData'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->GetColumnData(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetColumnData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemCount of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_GetItemCount00
static int tolua_GUI_GUI_MultiList_GetItemCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::MultiList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::MultiList* self = (const GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemCount'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetItemCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InsertItem of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_InsertItem00
static int tolua_GUI_GUI_MultiList_InsertItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,4,"GUI::Widget",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,4,nullptr));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InsertItem'", NULL);
#endif
  {
   self->InsertItem(index,*name,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InsertItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AppendItem of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_AppendItem00
static int tolua_GUI_GUI_MultiList_AppendItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"GUI::Widget",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,3,nullptr));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AppendItem'", NULL);
#endif
  {
   self->AppendItem(*name,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AppendItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveItem of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_RemoveItem00
static int tolua_GUI_GUI_MultiList_RemoveItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveItem'", NULL);
#endif
  {
   self->RemoveItem(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAllItems of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_RemoveAllItems00
static int tolua_GUI_GUI_MultiList_RemoveAllItems00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAllItems'", NULL);
#endif
  {
   self->RemoveAllItems();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAllItems'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SwapItems of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_SwapItems00
static int tolua_GUI_GUI_MultiList_SwapItems00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
    int index1 = ((   int)  tolua_tonumber(tolua_S,2,0));
    int index2 = ((   int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SwapItems'", NULL);
#endif
  {
   self->SwapItems(index1,index2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SwapItems'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemName of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_SetItemName00
static int tolua_GUI_GUI_MultiList_SetItemName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemName'", NULL);
#endif
  {
   self->SetItemName(index,*name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemName of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_GetItemName00
static int tolua_GUI_GUI_MultiList_GetItemName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemName'", NULL);
#endif
  {
   const GUI::UString& tolua_ret = (const GUI::UString&)  self->GetItemName(index);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const GUI::UString");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIndexSelected of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_GetIndexSelected00
static int tolua_GUI_GUI_MultiList_GetIndexSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIndexSelected'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetIndexSelected();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIndexSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetIndexSelected of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_SetIndexSelected00
static int tolua_GUI_GUI_MultiList_SetIndexSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetIndexSelected'", NULL);
#endif
  {
   self->SetIndexSelected(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetIndexSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearIndexSelected of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_ClearIndexSelected00
static int tolua_GUI_GUI_MultiList_ClearIndexSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearIndexSelected'", NULL);
#endif
  {
   self->ClearIndexSelected();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearIndexSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemData of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_SetItemData00
static int tolua_GUI_GUI_MultiList_SetItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemData'", NULL);
#endif
  {
   self->SetItemData(index,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearItemData of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_ClearItemData00
static int tolua_GUI_GUI_MultiList_ClearItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearItemData'", NULL);
#endif
  {
   self->ClearItemData(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemData of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_GetItemData00
static int tolua_GUI_GUI_MultiList_GetItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemData'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->GetItemData(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSubItemName of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_SetSubItemName00
static int tolua_GUI_GUI_MultiList_SetSubItemName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
    int column = ((   int)  tolua_tonumber(tolua_S,2,0));
    int index = ((   int)  tolua_tonumber(tolua_S,3,0));
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSubItemName'", NULL);
#endif
  {
   self->SetSubItemName(column,index,*name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSubItemName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSubItemName of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_GetSubItemName00
static int tolua_GUI_GUI_MultiList_GetSubItemName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
    int column = ((   int)  tolua_tonumber(tolua_S,2,0));
    int index = ((   int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSubItemName'", NULL);
#endif
  {
   const GUI::UString& tolua_ret = (const GUI::UString&)  self->GetSubItemName(column,index);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const GUI::UString");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSubItemName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FindSubItemWith of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_FindSubItemWith00
static int tolua_GUI_GUI_MultiList_FindSubItemWith00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
    int column = ((   int)  tolua_tonumber(tolua_S,2,0));
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindSubItemWith'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->FindSubItemWith(column,*name);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindSubItemWith'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSubItemData of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_SetSubItemData00
static int tolua_GUI_GUI_MultiList_SetSubItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
    int column = ((   int)  tolua_tonumber(tolua_S,2,0));
    int index = ((   int)  tolua_tonumber(tolua_S,3,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSubItemData'", NULL);
#endif
  {
   self->SetSubItemData(column,index,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSubItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearSubItemData of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_ClearSubItemData00
static int tolua_GUI_GUI_MultiList_ClearSubItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
    int column = ((   int)  tolua_tonumber(tolua_S,2,0));
    int index = ((   int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearSubItemData'", NULL);
#endif
  {
   self->ClearSubItemData(column,index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearSubItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSubItemData of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_MultiList_GetSubItemData00
static int tolua_GUI_GUI_MultiList_GetSubItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::MultiList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
    int column = ((   int)  tolua_tonumber(tolua_S,2,0));
    int index = ((   int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSubItemData'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->GetSubItemData(column,index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSubItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __BiIndexBase__ of class  GUI::MultiList */
#ifndef TOLUA_DISABLE_tolua_get_GUI__MultiList___BiIndexBase__
static int tolua_get_GUI__MultiList___BiIndexBase__(lua_State* tolua_S)
{
  GUI::MultiList* self = (GUI::MultiList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__BiIndexBase__'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<BiIndexBase*>(self), "BiIndexBase");
#else
   tolua_pushusertype(tolua_S,(void*)((BiIndexBase*)self), "BiIndexBase");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVisible of class  GUI::PopupMenu */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_PopupMenu_SetVisible00
static int tolua_GUI_GUI_PopupMenu_SetVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::PopupMenu",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::PopupMenu* self = (GUI::PopupMenu*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVisible'", NULL);
#endif
  {
   self->SetVisible(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetProgressRange of class  GUI::Progress */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Progress_SetProgressRange00
static int tolua_GUI_GUI_Progress_SetProgressRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Progress",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Progress* self = (GUI::Progress*)  tolua_tousertype(tolua_S,1,0);
    int value = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetProgressRange'", NULL);
#endif
  {
   self->SetProgressRange(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetProgressRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetProgressRange of class  GUI::Progress */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Progress_GetProgressRange00
static int tolua_GUI_GUI_Progress_GetProgressRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Progress",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Progress* self = (GUI::Progress*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetProgressRange'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetProgressRange();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetProgressRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetProgressPosition of class  GUI::Progress */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Progress_SetProgressPosition00
static int tolua_GUI_GUI_Progress_SetProgressPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Progress",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Progress* self = (GUI::Progress*)  tolua_tousertype(tolua_S,1,0);
    int value = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetProgressPosition'", NULL);
#endif
  {
   self->SetProgressPosition(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetProgressPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetProgressPosition of class  GUI::Progress */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Progress_GetProgressPosition00
static int tolua_GUI_GUI_Progress_GetProgressPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Progress",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Progress* self = (GUI::Progress*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetProgressPosition'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetProgressPosition();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetProgressPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetProgressAutoTrack of class  GUI::Progress */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Progress_SetProgressAutoTrack00
static int tolua_GUI_GUI_Progress_SetProgressAutoTrack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Progress",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Progress* self = (GUI::Progress*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetProgressAutoTrack'", NULL);
#endif
  {
   self->SetProgressAutoTrack(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetProgressAutoTrack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetProgressAutoTrack of class  GUI::Progress */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Progress_GetProgressAutoTrack00
static int tolua_GUI_GUI_Progress_GetProgressAutoTrack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Progress",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Progress* self = (GUI::Progress*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetProgressAutoTrack'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetProgressAutoTrack();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetProgressAutoTrack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetProgressStartPoint of class  GUI::Progress */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Progress_SetProgressStartPoint00
static int tolua_GUI_GUI_Progress_SetProgressStartPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Progress",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GUI::Align",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Progress* self = (GUI::Progress*)  tolua_tousertype(tolua_S,1,0);
  GUI::Align value = *((GUI::Align*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetProgressStartPoint'", NULL);
#endif
  {
   self->SetProgressStartPoint(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetProgressStartPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetProgressStartPoint of class  GUI::Progress */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Progress_GetProgressStartPoint00
static int tolua_GUI_GUI_Progress_GetProgressStartPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Progress",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Progress* self = (GUI::Progress*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetProgressStartPoint'", NULL);
#endif
  {
   GUI::Align tolua_ret = (GUI::Align)  self->GetProgressStartPoint();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::Align)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::Align");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::Align));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::Align");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetProgressStartPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  GUI::Progress */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Progress_SetPosition00
static int tolua_GUI_GUI_Progress_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Progress",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Progress* self = (GUI::Progress*)  tolua_tousertype(tolua_S,1,0);
  int left = ((int)  tolua_tonumber(tolua_S,2,0));
  int top = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
  {
   self->SetPosition(left,top);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSize of class  GUI::Progress */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Progress_SetSize00
static int tolua_GUI_GUI_Progress_SetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Progress",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Progress* self = (GUI::Progress*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSize'", NULL);
#endif
  {
   self->SetSize(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCoord of class  GUI::Progress */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Progress_SetCoord00
static int tolua_GUI_GUI_Progress_SetCoord00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Progress",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Progress* self = (GUI::Progress*)  tolua_tousertype(tolua_S,1,0);
  int left = ((int)  tolua_tonumber(tolua_S,2,0));
  int top = ((int)  tolua_tonumber(tolua_S,3,0));
  int width = ((int)  tolua_tonumber(tolua_S,4,0));
  int height = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCoord'", NULL);
#endif
  {
   self->SetCoord(left,top,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCoord'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetProperty of class  GUI::Progress */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Progress_SetProperty00
static int tolua_GUI_GUI_Progress_SetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Progress",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Progress* self = (GUI::Progress*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetProperty'", NULL);
#endif
  {
   self->SetProperty(key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  GUI::ScrollView */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ScrollView_SetPosition00
static int tolua_GUI_GUI_ScrollView_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ScrollView",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ScrollView* self = (GUI::ScrollView*)  tolua_tousertype(tolua_S,1,0);
  int left = ((int)  tolua_tonumber(tolua_S,2,0));
  int top = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
  {
   self->SetPosition(left,top);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSize of class  GUI::ScrollView */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ScrollView_SetSize00
static int tolua_GUI_GUI_ScrollView_SetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ScrollView",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ScrollView* self = (GUI::ScrollView*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSize'", NULL);
#endif
  {
   self->SetSize(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCoord of class  GUI::ScrollView */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ScrollView_SetCoord00
static int tolua_GUI_GUI_ScrollView_SetCoord00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ScrollView",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ScrollView* self = (GUI::ScrollView*)  tolua_tousertype(tolua_S,1,0);
  int left = ((int)  tolua_tonumber(tolua_S,2,0));
  int top = ((int)  tolua_tonumber(tolua_S,3,0));
  int width = ((int)  tolua_tonumber(tolua_S,4,0));
  int height = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCoord'", NULL);
#endif
  {
   self->SetCoord(left,top,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCoord'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVisibleVScroll of class  GUI::ScrollView */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ScrollView_SetVisibleVScroll00
static int tolua_GUI_GUI_ScrollView_SetVisibleVScroll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ScrollView",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ScrollView* self = (GUI::ScrollView*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVisibleVScroll'", NULL);
#endif
  {
   self->SetVisibleVScroll(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVisibleVScroll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsVisibleVScroll of class  GUI::ScrollView */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ScrollView_IsVisibleVScroll00
static int tolua_GUI_GUI_ScrollView_IsVisibleVScroll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ScrollView* self = (GUI::ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsVisibleVScroll'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsVisibleVScroll();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsVisibleVScroll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVisibleHScroll of class  GUI::ScrollView */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ScrollView_SetVisibleHScroll00
static int tolua_GUI_GUI_ScrollView_SetVisibleHScroll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ScrollView",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ScrollView* self = (GUI::ScrollView*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVisibleHScroll'", NULL);
#endif
  {
   self->SetVisibleHScroll(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVisibleHScroll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsVisibleHScroll of class  GUI::ScrollView */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ScrollView_IsVisibleHScroll00
static int tolua_GUI_GUI_ScrollView_IsVisibleHScroll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ScrollView* self = (GUI::ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsVisibleHScroll'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsVisibleHScroll();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsVisibleHScroll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCanvasAlign of class  GUI::ScrollView */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ScrollView_SetCanvasAlign00
static int tolua_GUI_GUI_ScrollView_SetCanvasAlign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ScrollView",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GUI::Align",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ScrollView* self = (GUI::ScrollView*)  tolua_tousertype(tolua_S,1,0);
  GUI::Align value = *((GUI::Align*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCanvasAlign'", NULL);
#endif
  {
   self->SetCanvasAlign(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCanvasAlign'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCanvasAlign of class  GUI::ScrollView */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ScrollView_GetCanvasAlign00
static int tolua_GUI_GUI_ScrollView_GetCanvasAlign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ScrollView* self = (GUI::ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCanvasAlign'", NULL);
#endif
  {
   GUI::Align tolua_ret = (GUI::Align)  self->GetCanvasAlign();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::Align)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::Align");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::Align));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::Align");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCanvasAlign'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCanvasSize of class  GUI::ScrollView */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ScrollView_SetCanvasSize00
static int tolua_GUI_GUI_ScrollView_SetCanvasSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ScrollView",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ScrollView* self = (GUI::ScrollView*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCanvasSize'", NULL);
#endif
  {
   self->SetCanvasSize(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCanvasSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCanvasSize of class  GUI::ScrollView */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ScrollView_GetCanvasSize00
static int tolua_GUI_GUI_ScrollView_GetCanvasSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ScrollView* self = (GUI::ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCanvasSize'", NULL);
#endif
  {
    TSize<int> tolua_ret = (  TSize<int>)  self->GetCanvasSize();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((TSize<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"TSize<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TSize<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"TSize<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCanvasSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetClientCoord of class  GUI::ScrollView */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ScrollView_GetClientCoord00
static int tolua_GUI_GUI_ScrollView_GetClientCoord00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ScrollView* self = (GUI::ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetClientCoord'", NULL);
#endif
  {
    const TCoord<int>& tolua_ret = (  const TCoord<int>&)  self->GetClientCoord();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const TCoord<int>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetClientCoord'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetProperty of class  GUI::ScrollView */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_ScrollView_SetProperty00
static int tolua_GUI_GUI_ScrollView_SetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::ScrollView",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::ScrollView* self = (GUI::ScrollView*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetProperty'", NULL);
#endif
  {
   self->SetProperty(key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetImageInfo of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_SetImageInfo00
static int tolua_GUI_GUI_StaticImage_SetImageInfo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const TCoord<int>",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const TSize<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
  const std::string texture = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const TCoord<int>* coord = ((const TCoord<int>*)  tolua_tousertype(tolua_S,3,0));
  const TSize<int>* tile = ((const TSize<int>*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetImageInfo'", NULL);
#endif
  {
   self->SetImageInfo(texture,*coord,*tile);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetImageInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetImageTexture of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_SetImageTexture00
static int tolua_GUI_GUI_StaticImage_SetImageTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetImageTexture'", NULL);
#endif
  {
   self->SetImageTexture(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetImageTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetImageRect of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_SetImageRect00
static int tolua_GUI_GUI_StaticImage_SetImageRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const TRect<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
  const TRect<int>* value = ((const TRect<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetImageRect'", NULL);
#endif
  {
   self->SetImageRect(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetImageRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetImageCoord of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_SetImageCoord00
static int tolua_GUI_GUI_StaticImage_SetImageCoord00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const TCoord<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
  const TCoord<int>* value = ((const TCoord<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetImageCoord'", NULL);
#endif
  {
   self->SetImageCoord(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetImageCoord'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetImageTile of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_SetImageTile00
static int tolua_GUI_GUI_StaticImage_SetImageTile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const TSize<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
  const TSize<int>* value = ((const TSize<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetImageTile'", NULL);
#endif
  {
   self->SetImageTile(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetImageTile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetImageIndex of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_SetImageIndex00
static int tolua_GUI_GUI_StaticImage_SetImageIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetImageIndex'", NULL);
#endif
  {
   self->SetImageIndex(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetImageIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetImageIndex of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_GetImageIndex00
static int tolua_GUI_GUI_StaticImage_GetImageIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetImageIndex'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetImageIndex();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetImageIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemCount of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_GetItemCount00
static int tolua_GUI_GUI_StaticImage_GetItemCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::StaticImage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::StaticImage* self = (const GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemCount'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetItemCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemSelect of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_SetItemSelect00
static int tolua_GUI_GUI_StaticImage_SetItemSelect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemSelect'", NULL);
#endif
  {
   self->SetItemSelect(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemSelect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemSelect of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_GetItemSelect00
static int tolua_GUI_GUI_StaticImage_GetItemSelect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemSelect'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetItemSelect();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemSelect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResetItemSelect of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_ResetItemSelect00
static int tolua_GUI_GUI_StaticImage_ResetItemSelect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResetItemSelect'", NULL);
#endif
  {
   self->ResetItemSelect();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ResetItemSelect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InsertItem of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_InsertItem00
static int tolua_GUI_GUI_StaticImage_InsertItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const TCoord<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  const TCoord<int>* item = ((const TCoord<int>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InsertItem'", NULL);
#endif
  {
   self->InsertItem(index,*item);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InsertItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddItem of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_AddItem00
static int tolua_GUI_GUI_StaticImage_AddItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const TCoord<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
  const TCoord<int>* item = ((const TCoord<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddItem'", NULL);
#endif
  {
   self->AddItem(*item);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItem of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_SetItem00
static int tolua_GUI_GUI_StaticImage_SetItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const TCoord<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  const TCoord<int>* item = ((const TCoord<int>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItem'", NULL);
#endif
  {
   self->SetItem(index,*item);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DeleteItem of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_DeleteItem00
static int tolua_GUI_GUI_StaticImage_DeleteItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DeleteItem'", NULL);
#endif
  {
   self->DeleteItem(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DeleteItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DeleteAllItems of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_DeleteAllItems00
static int tolua_GUI_GUI_StaticImage_DeleteAllItems00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DeleteAllItems'", NULL);
#endif
  {
   self->DeleteAllItems();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DeleteAllItems'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddItemFrame of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_AddItemFrame00
static int tolua_GUI_GUI_StaticImage_AddItemFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const TCoord<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  const TCoord<int>* item = ((const TCoord<int>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddItemFrame'", NULL);
#endif
  {
   self->AddItemFrame(index,*item);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddItemFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InsertItemFrame of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_InsertItemFrame00
static int tolua_GUI_GUI_StaticImage_InsertItemFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const TCoord<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
    int indexFrame = ((   int)  tolua_tonumber(tolua_S,3,0));
  const TCoord<int>* item = ((const TCoord<int>*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InsertItemFrame'", NULL);
#endif
  {
   self->InsertItemFrame(index,indexFrame,*item);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InsertItemFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddItemFrameDublicate of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_AddItemFrameDublicate00
static int tolua_GUI_GUI_StaticImage_AddItemFrameDublicate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
    int indexSourceFrame = ((   int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddItemFrameDublicate'", NULL);
#endif
  {
   self->AddItemFrameDublicate(index,indexSourceFrame);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddItemFrameDublicate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InsertItemFrameDublicate of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_InsertItemFrameDublicate00
static int tolua_GUI_GUI_StaticImage_InsertItemFrameDublicate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
    int indexFrame = ((   int)  tolua_tonumber(tolua_S,3,0));
    int indexSourceFrame = ((   int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InsertItemFrameDublicate'", NULL);
#endif
  {
   self->InsertItemFrameDublicate(index,indexFrame,indexSourceFrame);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InsertItemFrameDublicate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemFrame of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_SetItemFrame00
static int tolua_GUI_GUI_StaticImage_SetItemFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const TCoord<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
    int indexFrame = ((   int)  tolua_tonumber(tolua_S,3,0));
  const TCoord<int>* item = ((const TCoord<int>*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemFrame'", NULL);
#endif
  {
   self->SetItemFrame(index,indexFrame,*item);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DeleteItemFrame of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_DeleteItemFrame00
static int tolua_GUI_GUI_StaticImage_DeleteItemFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
    int indexFrame = ((   int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DeleteItemFrame'", NULL);
#endif
  {
   self->DeleteItemFrame(index,indexFrame);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DeleteItemFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DeleteAllItemFrames of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_DeleteAllItemFrames00
static int tolua_GUI_GUI_StaticImage_DeleteAllItemFrames00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DeleteAllItemFrames'", NULL);
#endif
  {
   self->DeleteAllItemFrames(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DeleteAllItemFrames'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemFrameRate of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_SetItemFrameRate00
static int tolua_GUI_GUI_StaticImage_SetItemFrameRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  float rate = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemFrameRate'", NULL);
#endif
  {
   self->SetItemFrameRate(index,rate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemFrameRate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemFrameRate of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_GetItemFrameRate00
static int tolua_GUI_GUI_StaticImage_GetItemFrameRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemFrameRate'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetItemFrameRate(index);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemFrameRate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemResource of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_SetItemResource00
static int tolua_GUI_GUI_StaticImage_SetItemResource00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Guid",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
  const Guid* id = ((const Guid*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemResource'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->SetItemResource(*id);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemResource'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemResource of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_SetItemResource01
static int tolua_GUI_GUI_StaticImage_SetItemResource01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemResource'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->SetItemResource(name);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_StaticImage_SetItemResource00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemGroup of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_SetItemGroup00
static int tolua_GUI_GUI_StaticImage_SetItemGroup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemGroup'", NULL);
#endif
  {
   self->SetItemGroup(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemGroup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemName of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_SetItemName00
static int tolua_GUI_GUI_StaticImage_SetItemName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemName'", NULL);
#endif
  {
   self->SetItemName(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemResourceInfo of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_SetItemResourceInfo00
static int tolua_GUI_GUI_StaticImage_SetItemResourceInfo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ResourceImageSetPtr",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
  ResourceImageSetPtr resource = *((ResourceImageSetPtr*)  tolua_tousertype(tolua_S,2,0));
  const std::string group = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemResourceInfo'", NULL);
#endif
  {
   self->SetItemResourceInfo(resource,group,name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemResourceInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetProperty of class  GUI::StaticImage */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticImage_SetProperty00
static int tolua_GUI_GUI_StaticImage_SetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticImage",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticImage* self = (GUI::StaticImage*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetProperty'", NULL);
#endif
  {
   self->SetProperty(key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTextRegion of class  GUI::StaticText */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticText_GetTextRegion00
static int tolua_GUI_GUI_StaticText_GetTextRegion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticText",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticText* self = (GUI::StaticText*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTextRegion'", NULL);
#endif
  {
    TCoord<int> tolua_ret = (  TCoord<int>)  self->GetTextRegion();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((TCoord<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"TCoord<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TCoord<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"TCoord<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTextRegion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTextSize of class  GUI::StaticText */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticText_GetTextSize00
static int tolua_GUI_GUI_StaticText_GetTextSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticText",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticText* self = (GUI::StaticText*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTextSize'", NULL);
#endif
  {
    TSize<int> tolua_ret = (  TSize<int>)  self->GetTextSize();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((TSize<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"TSize<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TSize<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"TSize<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTextSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFontName of class  GUI::StaticText */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticText_SetFontName00
static int tolua_GUI_GUI_StaticText_SetFontName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticText",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticText* self = (GUI::StaticText*)  tolua_tousertype(tolua_S,1,0);
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFontName'", NULL);
#endif
  {
   self->SetFontName(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFontName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFontName of class  GUI::StaticText */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticText_GetFontName00
static int tolua_GUI_GUI_StaticText_GetFontName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticText",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticText* self = (GUI::StaticText*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFontName'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetFontName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFontName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFontHeight of class  GUI::StaticText */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticText_SetFontHeight00
static int tolua_GUI_GUI_StaticText_SetFontHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticText",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticText* self = (GUI::StaticText*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFontHeight'", NULL);
#endif
  {
   self->SetFontHeight(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFontHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFontHeight of class  GUI::StaticText */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticText_GetFontHeight00
static int tolua_GUI_GUI_StaticText_GetFontHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticText",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticText* self = (GUI::StaticText*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFontHeight'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetFontHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFontHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTextAlign of class  GUI::StaticText */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticText_SetTextAlign00
static int tolua_GUI_GUI_StaticText_SetTextAlign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticText",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GUI::Align",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticText* self = (GUI::StaticText*)  tolua_tousertype(tolua_S,1,0);
  GUI::Align value = *((GUI::Align*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTextAlign'", NULL);
#endif
  {
   self->SetTextAlign(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTextAlign'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTextAlign of class  GUI::StaticText */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticText_GetTextAlign00
static int tolua_GUI_GUI_StaticText_GetTextAlign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticText",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticText* self = (GUI::StaticText*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTextAlign'", NULL);
#endif
  {
   GUI::Align tolua_ret = (GUI::Align)  self->GetTextAlign();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::Align)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::Align");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::Align));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::Align");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTextAlign'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTextColour of class  GUI::StaticText */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticText_SetTextColour00
static int tolua_GUI_GUI_StaticText_SetTextColour00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticText",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::Colour",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticText* self = (GUI::StaticText*)  tolua_tousertype(tolua_S,1,0);
  const GUI::Colour* value = ((const GUI::Colour*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTextColour'", NULL);
#endif
  {
   self->SetTextColour(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTextColour'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTextColour of class  GUI::StaticText */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticText_GetTextColour00
static int tolua_GUI_GUI_StaticText_GetTextColour00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticText",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticText* self = (GUI::StaticText*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTextColour'", NULL);
#endif
  {
   const GUI::Colour& tolua_ret = (const GUI::Colour&)  self->GetTextColour();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const GUI::Colour");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTextColour'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetProperty of class  GUI::StaticText */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_StaticText_SetProperty00
static int tolua_GUI_GUI_StaticText_SetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::StaticText",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::StaticText* self = (GUI::StaticText*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetProperty'", NULL);
#endif
  {
   self->SetProperty(key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_SetPosition00
static int tolua_GUI_GUI_Tab_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
  int left = ((int)  tolua_tonumber(tolua_S,2,0));
  int top = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
  {
   self->SetPosition(left,top);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSize of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_SetSize00
static int tolua_GUI_GUI_Tab_SetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSize'", NULL);
#endif
  {
   self->SetSize(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCoord of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_SetCoord00
static int tolua_GUI_GUI_Tab_SetCoord00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
  int left = ((int)  tolua_tonumber(tolua_S,2,0));
  int top = ((int)  tolua_tonumber(tolua_S,3,0));
  int width = ((int)  tolua_tonumber(tolua_S,4,0));
  int height = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCoord'", NULL);
#endif
  {
   self->SetCoord(left,top,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCoord'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemCount of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_GetItemCount00
static int tolua_GUI_GUI_Tab_GetItemCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::Tab",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::Tab* self = (const GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemCount'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetItemCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InsertItem of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_InsertItem00
static int tolua_GUI_GUI_Tab_InsertItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,4,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InsertItem'", NULL);
#endif
  {
   GUI::TabItem* tolua_ret = (GUI::TabItem*)  self->InsertItem(index,*name,value);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::TabItem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InsertItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InsertItemEx of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_InsertItemEx00
static int tolua_GUI_GUI_Tab_InsertItemEx00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::TabItem",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,4,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
  GUI::TabItem* to = ((GUI::TabItem*)  tolua_tousertype(tolua_S,2,0));
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InsertItemEx'", NULL);
#endif
  {
   GUI::TabItem* tolua_ret = (GUI::TabItem*)  self->InsertItemEx(to,*name,value);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::TabItem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InsertItemEx'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AppendItem of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_AppendItem00
static int tolua_GUI_GUI_Tab_AppendItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AppendItem'", NULL);
#endif
  {
   GUI::TabItem* tolua_ret = (GUI::TabItem*)  self->AppendItem(*name,value);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::TabItem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AppendItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveItem of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_RemoveItem00
static int tolua_GUI_GUI_Tab_RemoveItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveItem'", NULL);
#endif
  {
   self->RemoveItem(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveItem of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_RemoveItem01
static int tolua_GUI_GUI_Tab_RemoveItem01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::TabItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
  GUI::TabItem* item = ((GUI::TabItem*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveItem'", NULL);
#endif
  {
   self->RemoveItem(item);
  }
 }
 return 0;
tolua_lerror:
 return tolua_GUI_GUI_Tab_RemoveItem00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAllItems of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_RemoveAllItems00
static int tolua_GUI_GUI_Tab_RemoveAllItems00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAllItems'", NULL);
#endif
  {
   self->RemoveAllItems();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAllItems'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItem of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_GetItem00
static int tolua_GUI_GUI_Tab_GetItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItem'", NULL);
#endif
  {
   GUI::TabItem* tolua_ret = (GUI::TabItem*)  self->GetItem(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::TabItem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemIndex of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_GetItemIndex00
static int tolua_GUI_GUI_Tab_GetItemIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::TabItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
  GUI::TabItem* item = ((GUI::TabItem*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemIndex'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetItemIndex(item);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FindItemIndex of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_FindItemIndex00
static int tolua_GUI_GUI_Tab_FindItemIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::TabItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
  GUI::TabItem* item = ((GUI::TabItem*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindItemIndex'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->FindItemIndex(item);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindItemIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FindItemIndexWith of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_FindItemIndexWith00
static int tolua_GUI_GUI_Tab_FindItemIndexWith00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindItemIndexWith'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->FindItemIndexWith(*name);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindItemIndexWith'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FindItemWith of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_FindItemWith00
static int tolua_GUI_GUI_Tab_FindItemWith00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindItemWith'", NULL);
#endif
  {
   GUI::TabItem* tolua_ret = (GUI::TabItem*)  self->FindItemWith(*name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::TabItem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindItemWith'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIndexSelected of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_GetIndexSelected00
static int tolua_GUI_GUI_Tab_GetIndexSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIndexSelected'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetIndexSelected();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIndexSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemSelected of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_GetItemSelected00
static int tolua_GUI_GUI_Tab_GetItemSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemSelected'", NULL);
#endif
  {
   GUI::TabItem* tolua_ret = (GUI::TabItem*)  self->GetItemSelected();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::TabItem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetIndexSelected of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_SetIndexSelected00
static int tolua_GUI_GUI_Tab_SetIndexSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetIndexSelected'", NULL);
#endif
  {
   self->SetIndexSelected(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetIndexSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemSelected of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_SetItemSelected00
static int tolua_GUI_GUI_Tab_SetItemSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::TabItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
  GUI::TabItem* item = ((GUI::TabItem*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemSelected'", NULL);
#endif
  {
   self->SetItemSelected(item);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemData of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_SetItemData00
static int tolua_GUI_GUI_Tab_SetItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemData'", NULL);
#endif
  {
   self->SetItemData(index,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemData of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_SetItemData01
static int tolua_GUI_GUI_Tab_SetItemData01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::TabItem",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
  GUI::TabItem* item = ((GUI::TabItem*)  tolua_tousertype(tolua_S,2,0));
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemData'", NULL);
#endif
  {
   self->SetItemData(item,value);
  }
 }
 return 0;
tolua_lerror:
 return tolua_GUI_GUI_Tab_SetItemData00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearItemData of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_ClearItemData00
static int tolua_GUI_GUI_Tab_ClearItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearItemData'", NULL);
#endif
  {
   self->ClearItemData(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearItemData of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_ClearItemData01
static int tolua_GUI_GUI_Tab_ClearItemData01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::TabItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
  GUI::TabItem* item = ((GUI::TabItem*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearItemData'", NULL);
#endif
  {
   self->ClearItemData(item);
  }
 }
 return 0;
tolua_lerror:
 return tolua_GUI_GUI_Tab_ClearItemData00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemData of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_GetItemData00
static int tolua_GUI_GUI_Tab_GetItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemData'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->GetItemData(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemData of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_GetItemData01
static int tolua_GUI_GUI_Tab_GetItemData01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::TabItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
  GUI::TabItem* item = ((GUI::TabItem*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemData'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->GetItemData(item);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_Tab_GetItemData00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemName of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_SetItemName00
static int tolua_GUI_GUI_Tab_SetItemName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemName'", NULL);
#endif
  {
   self->SetItemName(index,*name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemName of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_SetItemName01
static int tolua_GUI_GUI_Tab_SetItemName01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::TabItem",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
  GUI::TabItem* item = ((GUI::TabItem*)  tolua_tousertype(tolua_S,2,0));
  const GUI::UString* name = ((const GUI::UString*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemName'", NULL);
#endif
  {
   self->SetItemName(item,*name);
  }
 }
 return 0;
tolua_lerror:
 return tolua_GUI_GUI_Tab_SetItemName00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemName of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_GetItemName00
static int tolua_GUI_GUI_Tab_GetItemName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemName'", NULL);
#endif
  {
   const GUI::UString& tolua_ret = (const GUI::UString&)  self->GetItemName(index);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const GUI::UString");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemName of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_GetItemName01
static int tolua_GUI_GUI_Tab_GetItemName01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::TabItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
  GUI::TabItem* item = ((GUI::TabItem*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemName'", NULL);
#endif
  {
   const GUI::UString& tolua_ret = (const GUI::UString&)  self->GetItemName(item);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const GUI::UString");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_Tab_GetItemName00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: BeginToItem of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_BeginToItem00
static int tolua_GUI_GUI_Tab_BeginToItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BeginToItem'", NULL);
#endif
  {
   self->BeginToItem(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginToItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BeginToItem of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_BeginToItem01
static int tolua_GUI_GUI_Tab_BeginToItem01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::TabItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
  GUI::TabItem* item = ((GUI::TabItem*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BeginToItem'", NULL);
#endif
  {
   self->BeginToItem(item);
  }
 }
 return 0;
tolua_lerror:
 return tolua_GUI_GUI_Tab_BeginToItem00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: BeginToItemFirst of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_BeginToItemFirst00
static int tolua_GUI_GUI_Tab_BeginToItemFirst00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BeginToItemFirst'", NULL);
#endif
  {
   self->BeginToItemFirst();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginToItemFirst'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BeginToItemLast of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_BeginToItemLast00
static int tolua_GUI_GUI_Tab_BeginToItemLast00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BeginToItemLast'", NULL);
#endif
  {
   self->BeginToItemLast();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginToItemLast'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BeginToItemSelected of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_BeginToItemSelected00
static int tolua_GUI_GUI_Tab_BeginToItemSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BeginToItemSelected'", NULL);
#endif
  {
   self->BeginToItemSelected();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginToItemSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetButtonWidth of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_SetButtonWidth00
static int tolua_GUI_GUI_Tab_SetButtonWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
  int width = ((int)  tolua_tonumber(tolua_S,3,-1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetButtonWidth'", NULL);
#endif
  {
   self->SetButtonWidth(index,width);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetButtonWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetButtonWidth of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_SetButtonWidth01
static int tolua_GUI_GUI_Tab_SetButtonWidth01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::TabItem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
  GUI::TabItem* item = ((GUI::TabItem*)  tolua_tousertype(tolua_S,2,0));
  int width = ((int)  tolua_tonumber(tolua_S,3,-1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetButtonWidth'", NULL);
#endif
  {
   self->SetButtonWidth(item,width);
  }
 }
 return 0;
tolua_lerror:
 return tolua_GUI_GUI_Tab_SetButtonWidth00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetButtonWidth of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_GetButtonWidth00
static int tolua_GUI_GUI_Tab_GetButtonWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetButtonWidth'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetButtonWidth(index);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetButtonWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetButtonWidth of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_GetButtonWidth01
static int tolua_GUI_GUI_Tab_GetButtonWidth01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::TabItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
  GUI::TabItem* item = ((GUI::TabItem*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetButtonWidth'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetButtonWidth(item);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_Tab_GetButtonWidth00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetButtonDefaultWidth of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_SetButtonDefaultWidth00
static int tolua_GUI_GUI_Tab_SetButtonDefaultWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetButtonDefaultWidth'", NULL);
#endif
  {
   self->SetButtonDefaultWidth(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetButtonDefaultWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetButtonDefaultWidth of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_GetButtonDefaultWidth00
static int tolua_GUI_GUI_Tab_GetButtonDefaultWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetButtonDefaultWidth'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetButtonDefaultWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetButtonDefaultWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetButtonAutoWidth of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_SetButtonAutoWidth00
static int tolua_GUI_GUI_Tab_SetButtonAutoWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetButtonAutoWidth'", NULL);
#endif
  {
   self->SetButtonAutoWidth(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetButtonAutoWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetButtonAutoWidth of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_GetButtonAutoWidth00
static int tolua_GUI_GUI_Tab_GetButtonAutoWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetButtonAutoWidth'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetButtonAutoWidth();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetButtonAutoWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSmoothShow of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_SetSmoothShow00
static int tolua_GUI_GUI_Tab_SetSmoothShow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSmoothShow'", NULL);
#endif
  {
   self->SetSmoothShow(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSmoothShow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSmoothShow of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_GetSmoothShow00
static int tolua_GUI_GUI_Tab_GetSmoothShow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSmoothShow'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetSmoothShow();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSmoothShow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetProperty of class  GUI::Tab */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Tab_SetProperty00
static int tolua_GUI_GUI_Tab_SetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Tab",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Tab* self = (GUI::Tab*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetProperty'", NULL);
#endif
  {
   self->SetProperty(key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCaption of class  GUI::TabItem */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_TabItem_SetCaption00
static int tolua_GUI_GUI_TabItem_SetCaption00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::TabItem",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::TabItem* self = (GUI::TabItem*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* value = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCaption'", NULL);
#endif
  {
   self->SetCaption(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCaption'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCaption of class  GUI::TabItem */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_TabItem_GetCaption00
static int tolua_GUI_GUI_TabItem_GetCaption00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::TabItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::TabItem* self = (GUI::TabItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCaption'", NULL);
#endif
  {
   const GUI::UString& tolua_ret = (const GUI::UString&)  self->GetCaption();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const GUI::UString");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCaption'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetButtonWidth of class  GUI::TabItem */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_TabItem_SetButtonWidth00
static int tolua_GUI_GUI_TabItem_SetButtonWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::TabItem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::TabItem* self = (GUI::TabItem*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,-1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetButtonWidth'", NULL);
#endif
  {
   self->SetButtonWidth(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetButtonWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetButtonWidth of class  GUI::TabItem */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_TabItem_GetButtonWidth00
static int tolua_GUI_GUI_TabItem_GetButtonWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::TabItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::TabItem* self = (GUI::TabItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetButtonWidth'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetButtonWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetButtonWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemName of class  GUI::TabItem */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_TabItem_SetItemName00
static int tolua_GUI_GUI_TabItem_SetItemName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::TabItem",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::TabItem* self = (GUI::TabItem*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* value = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemName'", NULL);
#endif
  {
   self->SetItemName(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemName of class  GUI::TabItem */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_TabItem_GetItemName00
static int tolua_GUI_GUI_TabItem_GetItemName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::TabItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::TabItem* self = (GUI::TabItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemName'", NULL);
#endif
  {
   const GUI::UString& tolua_ret = (const GUI::UString&)  self->GetItemName();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const GUI::UString");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemData of class  GUI::TabItem */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_TabItem_SetItemData00
static int tolua_GUI_GUI_TabItem_SetItemData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::TabItem",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::TabItem* self = (GUI::TabItem*)  tolua_tousertype(tolua_S,1,0);
  GUI::Widget* value = ((GUI::Widget*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemData'", NULL);
#endif
  {
   self->SetItemData(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetItemSelected of class  GUI::TabItem */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_TabItem_SetItemSelected00
static int tolua_GUI_GUI_TabItem_SetItemSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::TabItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::TabItem* self = (GUI::TabItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetItemSelected'", NULL);
#endif
  {
   self->SetItemSelected();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveItem of class  GUI::TabItem */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_TabItem_RemoveItem00
static int tolua_GUI_GUI_TabItem_RemoveItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::TabItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::TabItem* self = (GUI::TabItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveItem'", NULL);
#endif
  {
   self->RemoveItem();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetProperty of class  GUI::TabItem */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_TabItem_SetProperty00
static int tolua_GUI_GUI_TabItem_SetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::TabItem",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::TabItem* self = (GUI::TabItem*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetProperty'", NULL);
#endif
  {
   self->SetProperty(key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: left of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_get_GUI__types__TCoord_int__left
static int tolua_get_GUI__types__TCoord_int__left(lua_State* tolua_S)
{
  GUI::types::TCoord<int>* self = (GUI::types::TCoord<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'left'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->left);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: left of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_set_GUI__types__TCoord_int__left
static int tolua_set_GUI__types__TCoord_int__left(lua_State* tolua_S)
{
  GUI::types::TCoord<int>* self = (GUI::types::TCoord<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'left'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->left = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: top of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_get_GUI__types__TCoord_int__top
static int tolua_get_GUI__types__TCoord_int__top(lua_State* tolua_S)
{
  GUI::types::TCoord<int>* self = (GUI::types::TCoord<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'top'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->top);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: top of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_set_GUI__types__TCoord_int__top
static int tolua_set_GUI__types__TCoord_int__top(lua_State* tolua_S)
{
  GUI::types::TCoord<int>* self = (GUI::types::TCoord<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'top'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->top = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: width of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_get_GUI__types__TCoord_int__width
static int tolua_get_GUI__types__TCoord_int__width(lua_State* tolua_S)
{
  GUI::types::TCoord<int>* self = (GUI::types::TCoord<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->width);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: width of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_set_GUI__types__TCoord_int__width
static int tolua_set_GUI__types__TCoord_int__width(lua_State* tolua_S)
{
  GUI::types::TCoord<int>* self = (GUI::types::TCoord<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->width = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: height of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_get_GUI__types__TCoord_int__height
static int tolua_get_GUI__types__TCoord_int__height(lua_State* tolua_S)
{
  GUI::types::TCoord<int>* self = (GUI::types::TCoord<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->height);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: height of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_set_GUI__types__TCoord_int__height
static int tolua_set_GUI__types__TCoord_int__height(lua_State* tolua_S)
{
  GUI::types::TCoord<int>* self = (GUI::types::TCoord<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->height = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_int__new00
static int tolua_GUI_GUI_types_TCoord_int__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TCoord<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GUI::types::TCoord<int>* tolua_ret = (GUI::types::TCoord<int>*)  Mtolua_new((GUI::types::TCoord<int>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TCoord<int>");
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

/* method: new_local of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_int__new00_local
static int tolua_GUI_GUI_types_TCoord_int__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TCoord<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GUI::types::TCoord<int>* tolua_ret = (GUI::types::TCoord<int>*)  Mtolua_new((GUI::types::TCoord<int>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TCoord<int>");
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

/* method: new of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_int__new01
static int tolua_GUI_GUI_types_TCoord_int__new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TCoord<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int const* left = ((int const*)  tolua_tousertype(tolua_S,2,0));
  int const* top = ((int const*)  tolua_tousertype(tolua_S,3,0));
  int const* width = ((int const*)  tolua_tousertype(tolua_S,4,0));
  int const* height = ((int const*)  tolua_tousertype(tolua_S,5,0));
  {
   GUI::types::TCoord<int>* tolua_ret = (GUI::types::TCoord<int>*)  Mtolua_new((GUI::types::TCoord<int>)(*left,*top,*width,*height));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TCoord<int>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TCoord_int__new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_int__new01_local
static int tolua_GUI_GUI_types_TCoord_int__new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TCoord<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int const* left = ((int const*)  tolua_tousertype(tolua_S,2,0));
  int const* top = ((int const*)  tolua_tousertype(tolua_S,3,0));
  int const* width = ((int const*)  tolua_tousertype(tolua_S,4,0));
  int const* height = ((int const*)  tolua_tousertype(tolua_S,5,0));
  {
   GUI::types::TCoord<int>* tolua_ret = (GUI::types::TCoord<int>*)  Mtolua_new((GUI::types::TCoord<int>)(*left,*top,*width,*height));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TCoord<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TCoord_int__new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_int__new02
static int tolua_GUI_GUI_types_TCoord_int__new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TCoord<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TCoord<int> const* obj = ((TCoord<int> const*)  tolua_tousertype(tolua_S,2,0));
  {
   GUI::types::TCoord<int>* tolua_ret = (GUI::types::TCoord<int>*)  Mtolua_new((GUI::types::TCoord<int>)(*obj));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TCoord<int>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TCoord_int__new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_int__new02_local
static int tolua_GUI_GUI_types_TCoord_int__new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TCoord<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TCoord<int> const* obj = ((TCoord<int> const*)  tolua_tousertype(tolua_S,2,0));
  {
   GUI::types::TCoord<int>* tolua_ret = (GUI::types::TCoord<int>*)  Mtolua_new((GUI::types::TCoord<int>)(*obj));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TCoord<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TCoord_int__new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_int__new03
static int tolua_GUI_GUI_types_TCoord_int__new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TCoord<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TPoint<int> const* point = ((TPoint<int> const*)  tolua_tousertype(tolua_S,2,0));
  TSize<int> const* size = ((TSize<int> const*)  tolua_tousertype(tolua_S,3,0));
  {
   GUI::types::TCoord<int>* tolua_ret = (GUI::types::TCoord<int>*)  Mtolua_new((GUI::types::TCoord<int>)(*point,*size));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TCoord<int>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TCoord_int__new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_int__new03_local
static int tolua_GUI_GUI_types_TCoord_int__new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TCoord<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TPoint<int> const* point = ((TPoint<int> const*)  tolua_tousertype(tolua_S,2,0));
  TSize<int> const* size = ((TSize<int> const*)  tolua_tousertype(tolua_S,3,0));
  {
   GUI::types::TCoord<int>* tolua_ret = (GUI::types::TCoord<int>*)  Mtolua_new((GUI::types::TCoord<int>)(*point,*size));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TCoord<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TCoord_int__new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_int___sub00
static int tolua_GUI_GUI_types_TCoord_int___sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TCoord<int>* self = (const GUI::types::TCoord<int>*)  tolua_tousertype(tolua_S,1,0);
  TCoord<int> const* obj = ((TCoord<int> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   GUI::types::TCoord<int> tolua_ret = (GUI::types::TCoord<int>)  self->operator-(*obj);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TCoord<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TCoord<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_int___sub01
static int tolua_GUI_GUI_types_TCoord_int___sub01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const GUI::types::TCoord<int>* self = (const GUI::types::TCoord<int>*)  tolua_tousertype(tolua_S,1,0);
  TPoint<int> const* obj = ((TPoint<int> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   GUI::types::TCoord<int> tolua_ret = (GUI::types::TCoord<int>)  self->operator-(*obj);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TCoord<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TCoord<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TCoord_int___sub00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_int___sub02
static int tolua_GUI_GUI_types_TCoord_int___sub02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const GUI::types::TCoord<int>* self = (const GUI::types::TCoord<int>*)  tolua_tousertype(tolua_S,1,0);
  TSize<int> const* obj = ((TSize<int> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   GUI::types::TCoord<int> tolua_ret = (GUI::types::TCoord<int>)  self->operator-(*obj);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TCoord<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TCoord<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TCoord_int___sub01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_int___add00
static int tolua_GUI_GUI_types_TCoord_int___add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TCoord<int>* self = (const GUI::types::TCoord<int>*)  tolua_tousertype(tolua_S,1,0);
  TCoord<int> const* obj = ((TCoord<int> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   GUI::types::TCoord<int> tolua_ret = (GUI::types::TCoord<int>)  self->operator+(*obj);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TCoord<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TCoord<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_int___add01
static int tolua_GUI_GUI_types_TCoord_int___add01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const GUI::types::TCoord<int>* self = (const GUI::types::TCoord<int>*)  tolua_tousertype(tolua_S,1,0);
  TPoint<int> const* obj = ((TPoint<int> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   GUI::types::TCoord<int> tolua_ret = (GUI::types::TCoord<int>)  self->operator+(*obj);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TCoord<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TCoord<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TCoord_int___add00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_int___add02
static int tolua_GUI_GUI_types_TCoord_int___add02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const GUI::types::TCoord<int>* self = (const GUI::types::TCoord<int>*)  tolua_tousertype(tolua_S,1,0);
  TSize<int> const* obj = ((TSize<int> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   GUI::types::TCoord<int> tolua_ret = (GUI::types::TCoord<int>)  self->operator+(*obj);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TCoord<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TCoord<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TCoord_int___add01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_int___eq00
static int tolua_GUI_GUI_types_TCoord_int___eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TCoord<int>* self = (const GUI::types::TCoord<int>*)  tolua_tousertype(tolua_S,1,0);
  TCoord<int> const* obj = ((TCoord<int> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*obj);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Right of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_int__Right00
static int tolua_GUI_GUI_types_TCoord_int__Right00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TCoord<int>* self = (const GUI::types::TCoord<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Right'", NULL);
#endif
  {
   int tolua_ret = (int)  self->Right();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Right'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Bottom of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_int__Bottom00
static int tolua_GUI_GUI_types_TCoord_int__Bottom00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TCoord<int>* self = (const GUI::types::TCoord<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Bottom'", NULL);
#endif
  {
   int tolua_ret = (int)  self->Bottom();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Bottom'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_int__Clear00
static int tolua_GUI_GUI_types_TCoord_int__Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::types::TCoord<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::types::TCoord<int>* self = (GUI::types::TCoord<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'", NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_int__Set00
static int tolua_GUI_GUI_types_TCoord_int__Set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::types::TCoord<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::types::TCoord<int>* self = (GUI::types::TCoord<int>*)  tolua_tousertype(tolua_S,1,0);
  int const* left = ((int const*)  tolua_tousertype(tolua_S,2,0));
  int const* top = ((int const*)  tolua_tousertype(tolua_S,3,0));
  int const* width = ((int const*)  tolua_tousertype(tolua_S,4,0));
  int const* height = ((int const*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set'", NULL);
#endif
  {
   self->Set(*left,*top,*width,*height);
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

/* method: Swap of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_int__Swap00
static int tolua_GUI_GUI_types_TCoord_int__Swap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::types::TCoord<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GUI::types::TCoord<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::types::TCoord<int>* self = (GUI::types::TCoord<int>*)  tolua_tousertype(tolua_S,1,0);
  GUI::types::TCoord<int>* value = ((GUI::types::TCoord<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Swap'", NULL);
#endif
  {
   self->Swap(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Swap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Empty of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_int__Empty00
static int tolua_GUI_GUI_types_TCoord_int__Empty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TCoord<int>* self = (const GUI::types::TCoord<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Empty'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Empty();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Empty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Point of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_int__Point00
static int tolua_GUI_GUI_types_TCoord_int__Point00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TCoord<int>* self = (const GUI::types::TCoord<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Point'", NULL);
#endif
  {
   GUI::types::TPoint<int> tolua_ret = (GUI::types::TPoint<int>)  self->Point();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TPoint<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TPoint<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TPoint<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TPoint<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Point'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Size of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_int__Size00
static int tolua_GUI_GUI_types_TCoord_int__Size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TCoord<int>* self = (const GUI::types::TCoord<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Size'", NULL);
#endif
  {
   GUI::types::TSize<int> tolua_ret = (GUI::types::TSize<int>)  self->Size();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TSize<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TSize<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TSize<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TSize<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Inside of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_int__Inside00
static int tolua_GUI_GUI_types_TCoord_int__Inside00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::types::TPoint<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TCoord<int>* self = (const GUI::types::TCoord<int>*)  tolua_tousertype(tolua_S,1,0);
  const GUI::types::TPoint<int>* value = ((const GUI::types::TPoint<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Inside'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Inside(*value);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Inside'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Print of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_int__Print00
static int tolua_GUI_GUI_types_TCoord_int__Print00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TCoord<int>* self = (const GUI::types::TCoord<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Print'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->Print();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Print'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Parse of class  GUI::types::TCoord<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_int__Parse00
static int tolua_GUI_GUI_types_TCoord_int__Parse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TCoord<int>",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   GUI::types::TCoord<int> tolua_ret = (GUI::types::TCoord<int>)  GUI::types::TCoord<int>::Parse(value);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TCoord<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TCoord<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Parse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: left of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_get_GUI__types__TCoord_float__left
static int tolua_get_GUI__types__TCoord_float__left(lua_State* tolua_S)
{
  GUI::types::TCoord<float>* self = (GUI::types::TCoord<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'left'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->left);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: left of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_set_GUI__types__TCoord_float__left
static int tolua_set_GUI__types__TCoord_float__left(lua_State* tolua_S)
{
  GUI::types::TCoord<float>* self = (GUI::types::TCoord<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'left'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->left = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: top of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_get_GUI__types__TCoord_float__top
static int tolua_get_GUI__types__TCoord_float__top(lua_State* tolua_S)
{
  GUI::types::TCoord<float>* self = (GUI::types::TCoord<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'top'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->top);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: top of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_set_GUI__types__TCoord_float__top
static int tolua_set_GUI__types__TCoord_float__top(lua_State* tolua_S)
{
  GUI::types::TCoord<float>* self = (GUI::types::TCoord<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'top'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->top = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: width of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_get_GUI__types__TCoord_float__width
static int tolua_get_GUI__types__TCoord_float__width(lua_State* tolua_S)
{
  GUI::types::TCoord<float>* self = (GUI::types::TCoord<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->width);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: width of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_set_GUI__types__TCoord_float__width
static int tolua_set_GUI__types__TCoord_float__width(lua_State* tolua_S)
{
  GUI::types::TCoord<float>* self = (GUI::types::TCoord<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->width = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: height of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_get_GUI__types__TCoord_float__height
static int tolua_get_GUI__types__TCoord_float__height(lua_State* tolua_S)
{
  GUI::types::TCoord<float>* self = (GUI::types::TCoord<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->height);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: height of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_set_GUI__types__TCoord_float__height
static int tolua_set_GUI__types__TCoord_float__height(lua_State* tolua_S)
{
  GUI::types::TCoord<float>* self = (GUI::types::TCoord<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->height = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_float__new00
static int tolua_GUI_GUI_types_TCoord_float__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TCoord<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GUI::types::TCoord<float>* tolua_ret = (GUI::types::TCoord<float>*)  Mtolua_new((GUI::types::TCoord<float>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TCoord<float>");
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

/* method: new_local of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_float__new00_local
static int tolua_GUI_GUI_types_TCoord_float__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TCoord<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GUI::types::TCoord<float>* tolua_ret = (GUI::types::TCoord<float>*)  Mtolua_new((GUI::types::TCoord<float>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TCoord<float>");
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

/* method: new of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_float__new01
static int tolua_GUI_GUI_types_TCoord_float__new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TCoord<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float const* left = ((float const*)  tolua_tousertype(tolua_S,2,0));
  float const* top = ((float const*)  tolua_tousertype(tolua_S,3,0));
  float const* width = ((float const*)  tolua_tousertype(tolua_S,4,0));
  float const* height = ((float const*)  tolua_tousertype(tolua_S,5,0));
  {
   GUI::types::TCoord<float>* tolua_ret = (GUI::types::TCoord<float>*)  Mtolua_new((GUI::types::TCoord<float>)(*left,*top,*width,*height));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TCoord<float>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TCoord_float__new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_float__new01_local
static int tolua_GUI_GUI_types_TCoord_float__new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TCoord<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float const* left = ((float const*)  tolua_tousertype(tolua_S,2,0));
  float const* top = ((float const*)  tolua_tousertype(tolua_S,3,0));
  float const* width = ((float const*)  tolua_tousertype(tolua_S,4,0));
  float const* height = ((float const*)  tolua_tousertype(tolua_S,5,0));
  {
   GUI::types::TCoord<float>* tolua_ret = (GUI::types::TCoord<float>*)  Mtolua_new((GUI::types::TCoord<float>)(*left,*top,*width,*height));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TCoord<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TCoord_float__new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_float__new02
static int tolua_GUI_GUI_types_TCoord_float__new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TCoord<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TCoord<float> const* obj = ((TCoord<float> const*)  tolua_tousertype(tolua_S,2,0));
  {
   GUI::types::TCoord<float>* tolua_ret = (GUI::types::TCoord<float>*)  Mtolua_new((GUI::types::TCoord<float>)(*obj));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TCoord<float>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TCoord_float__new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_float__new02_local
static int tolua_GUI_GUI_types_TCoord_float__new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TCoord<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TCoord<float> const* obj = ((TCoord<float> const*)  tolua_tousertype(tolua_S,2,0));
  {
   GUI::types::TCoord<float>* tolua_ret = (GUI::types::TCoord<float>*)  Mtolua_new((GUI::types::TCoord<float>)(*obj));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TCoord<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TCoord_float__new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_float__new03
static int tolua_GUI_GUI_types_TCoord_float__new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TCoord<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TPoint<float> const* point = ((TPoint<float> const*)  tolua_tousertype(tolua_S,2,0));
  TSize<float> const* size = ((TSize<float> const*)  tolua_tousertype(tolua_S,3,0));
  {
   GUI::types::TCoord<float>* tolua_ret = (GUI::types::TCoord<float>*)  Mtolua_new((GUI::types::TCoord<float>)(*point,*size));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TCoord<float>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TCoord_float__new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_float__new03_local
static int tolua_GUI_GUI_types_TCoord_float__new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TCoord<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TPoint<float> const* point = ((TPoint<float> const*)  tolua_tousertype(tolua_S,2,0));
  TSize<float> const* size = ((TSize<float> const*)  tolua_tousertype(tolua_S,3,0));
  {
   GUI::types::TCoord<float>* tolua_ret = (GUI::types::TCoord<float>*)  Mtolua_new((GUI::types::TCoord<float>)(*point,*size));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TCoord<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TCoord_float__new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_float___sub00
static int tolua_GUI_GUI_types_TCoord_float___sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TCoord<float>* self = (const GUI::types::TCoord<float>*)  tolua_tousertype(tolua_S,1,0);
  TCoord<float> const* obj = ((TCoord<float> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   GUI::types::TCoord<float> tolua_ret = (GUI::types::TCoord<float>)  self->operator-(*obj);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TCoord<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TCoord<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_float___sub01
static int tolua_GUI_GUI_types_TCoord_float___sub01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const GUI::types::TCoord<float>* self = (const GUI::types::TCoord<float>*)  tolua_tousertype(tolua_S,1,0);
  TPoint<float> const* obj = ((TPoint<float> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   GUI::types::TCoord<float> tolua_ret = (GUI::types::TCoord<float>)  self->operator-(*obj);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TCoord<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TCoord<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TCoord_float___sub00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_float___sub02
static int tolua_GUI_GUI_types_TCoord_float___sub02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const GUI::types::TCoord<float>* self = (const GUI::types::TCoord<float>*)  tolua_tousertype(tolua_S,1,0);
  TSize<float> const* obj = ((TSize<float> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   GUI::types::TCoord<float> tolua_ret = (GUI::types::TCoord<float>)  self->operator-(*obj);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TCoord<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TCoord<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TCoord_float___sub01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_float___add00
static int tolua_GUI_GUI_types_TCoord_float___add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TCoord<float>* self = (const GUI::types::TCoord<float>*)  tolua_tousertype(tolua_S,1,0);
  TCoord<float> const* obj = ((TCoord<float> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   GUI::types::TCoord<float> tolua_ret = (GUI::types::TCoord<float>)  self->operator+(*obj);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TCoord<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TCoord<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_float___add01
static int tolua_GUI_GUI_types_TCoord_float___add01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const GUI::types::TCoord<float>* self = (const GUI::types::TCoord<float>*)  tolua_tousertype(tolua_S,1,0);
  TPoint<float> const* obj = ((TPoint<float> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   GUI::types::TCoord<float> tolua_ret = (GUI::types::TCoord<float>)  self->operator+(*obj);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TCoord<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TCoord<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TCoord_float___add00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_float___add02
static int tolua_GUI_GUI_types_TCoord_float___add02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const GUI::types::TCoord<float>* self = (const GUI::types::TCoord<float>*)  tolua_tousertype(tolua_S,1,0);
  TSize<float> const* obj = ((TSize<float> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   GUI::types::TCoord<float> tolua_ret = (GUI::types::TCoord<float>)  self->operator+(*obj);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TCoord<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TCoord<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TCoord_float___add01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_float___eq00
static int tolua_GUI_GUI_types_TCoord_float___eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TCoord<float>* self = (const GUI::types::TCoord<float>*)  tolua_tousertype(tolua_S,1,0);
  TCoord<float> const* obj = ((TCoord<float> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*obj);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Right of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_float__Right00
static int tolua_GUI_GUI_types_TCoord_float__Right00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TCoord<float>* self = (const GUI::types::TCoord<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Right'", NULL);
#endif
  {
   float tolua_ret = (float)  self->Right();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Right'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Bottom of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_float__Bottom00
static int tolua_GUI_GUI_types_TCoord_float__Bottom00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TCoord<float>* self = (const GUI::types::TCoord<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Bottom'", NULL);
#endif
  {
   float tolua_ret = (float)  self->Bottom();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Bottom'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_float__Clear00
static int tolua_GUI_GUI_types_TCoord_float__Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::types::TCoord<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::types::TCoord<float>* self = (GUI::types::TCoord<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'", NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_float__Set00
static int tolua_GUI_GUI_types_TCoord_float__Set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::types::TCoord<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::types::TCoord<float>* self = (GUI::types::TCoord<float>*)  tolua_tousertype(tolua_S,1,0);
  float const* left = ((float const*)  tolua_tousertype(tolua_S,2,0));
  float const* top = ((float const*)  tolua_tousertype(tolua_S,3,0));
  float const* width = ((float const*)  tolua_tousertype(tolua_S,4,0));
  float const* height = ((float const*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set'", NULL);
#endif
  {
   self->Set(*left,*top,*width,*height);
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

/* method: Swap of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_float__Swap00
static int tolua_GUI_GUI_types_TCoord_float__Swap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::types::TCoord<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GUI::types::TCoord<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::types::TCoord<float>* self = (GUI::types::TCoord<float>*)  tolua_tousertype(tolua_S,1,0);
  GUI::types::TCoord<float>* value = ((GUI::types::TCoord<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Swap'", NULL);
#endif
  {
   self->Swap(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Swap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Empty of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_float__Empty00
static int tolua_GUI_GUI_types_TCoord_float__Empty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TCoord<float>* self = (const GUI::types::TCoord<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Empty'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Empty();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Empty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Point of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_float__Point00
static int tolua_GUI_GUI_types_TCoord_float__Point00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TCoord<float>* self = (const GUI::types::TCoord<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Point'", NULL);
#endif
  {
   GUI::types::TPoint<float> tolua_ret = (GUI::types::TPoint<float>)  self->Point();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TPoint<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TPoint<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TPoint<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TPoint<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Point'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Size of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_float__Size00
static int tolua_GUI_GUI_types_TCoord_float__Size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TCoord<float>* self = (const GUI::types::TCoord<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Size'", NULL);
#endif
  {
   GUI::types::TSize<float> tolua_ret = (GUI::types::TSize<float>)  self->Size();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TSize<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TSize<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TSize<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TSize<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Inside of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_float__Inside00
static int tolua_GUI_GUI_types_TCoord_float__Inside00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::types::TPoint<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TCoord<float>* self = (const GUI::types::TCoord<float>*)  tolua_tousertype(tolua_S,1,0);
  const GUI::types::TPoint<float>* value = ((const GUI::types::TPoint<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Inside'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Inside(*value);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Inside'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Print of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_float__Print00
static int tolua_GUI_GUI_types_TCoord_float__Print00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TCoord<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TCoord<float>* self = (const GUI::types::TCoord<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Print'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->Print();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Print'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Parse of class  GUI::types::TCoord<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TCoord_float__Parse00
static int tolua_GUI_GUI_types_TCoord_float__Parse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TCoord<float>",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   GUI::types::TCoord<float> tolua_ret = (GUI::types::TCoord<float>)  GUI::types::TCoord<float>::Parse(value);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TCoord<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TCoord<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TCoord<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Parse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: left of class  GUI::types::TPoint<int> */
#ifndef TOLUA_DISABLE_tolua_get_GUI__types__TPoint_int__left
static int tolua_get_GUI__types__TPoint_int__left(lua_State* tolua_S)
{
  GUI::types::TPoint<int>* self = (GUI::types::TPoint<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'left'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->left);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: left of class  GUI::types::TPoint<int> */
#ifndef TOLUA_DISABLE_tolua_set_GUI__types__TPoint_int__left
static int tolua_set_GUI__types__TPoint_int__left(lua_State* tolua_S)
{
  GUI::types::TPoint<int>* self = (GUI::types::TPoint<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'left'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->left = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: top of class  GUI::types::TPoint<int> */
#ifndef TOLUA_DISABLE_tolua_get_GUI__types__TPoint_int__top
static int tolua_get_GUI__types__TPoint_int__top(lua_State* tolua_S)
{
  GUI::types::TPoint<int>* self = (GUI::types::TPoint<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'top'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->top);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: top of class  GUI::types::TPoint<int> */
#ifndef TOLUA_DISABLE_tolua_set_GUI__types__TPoint_int__top
static int tolua_set_GUI__types__TPoint_int__top(lua_State* tolua_S)
{
  GUI::types::TPoint<int>* self = (GUI::types::TPoint<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'top'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->top = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GUI::types::TPoint<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_int__new00
static int tolua_GUI_GUI_types_TPoint_int__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TPoint<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GUI::types::TPoint<int>* tolua_ret = (GUI::types::TPoint<int>*)  Mtolua_new((GUI::types::TPoint<int>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TPoint<int>");
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

/* method: new_local of class  GUI::types::TPoint<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_int__new00_local
static int tolua_GUI_GUI_types_TPoint_int__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TPoint<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GUI::types::TPoint<int>* tolua_ret = (GUI::types::TPoint<int>*)  Mtolua_new((GUI::types::TPoint<int>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TPoint<int>");
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

/* method: new of class  GUI::types::TPoint<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_int__new01
static int tolua_GUI_GUI_types_TPoint_int__new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TPoint<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int const* left = ((int const*)  tolua_tousertype(tolua_S,2,0));
  int const* top = ((int const*)  tolua_tousertype(tolua_S,3,0));
  {
   GUI::types::TPoint<int>* tolua_ret = (GUI::types::TPoint<int>*)  Mtolua_new((GUI::types::TPoint<int>)(*left,*top));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TPoint<int>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TPoint_int__new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  GUI::types::TPoint<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_int__new01_local
static int tolua_GUI_GUI_types_TPoint_int__new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TPoint<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int const* left = ((int const*)  tolua_tousertype(tolua_S,2,0));
  int const* top = ((int const*)  tolua_tousertype(tolua_S,3,0));
  {
   GUI::types::TPoint<int>* tolua_ret = (GUI::types::TPoint<int>*)  Mtolua_new((GUI::types::TPoint<int>)(*left,*top));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TPoint<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TPoint_int__new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GUI::types::TPoint<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_int__new02
static int tolua_GUI_GUI_types_TPoint_int__new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TPoint<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TPoint<int> const* o = ((TPoint<int> const*)  tolua_tousertype(tolua_S,2,0));
  {
   GUI::types::TPoint<int>* tolua_ret = (GUI::types::TPoint<int>*)  Mtolua_new((GUI::types::TPoint<int>)(*o));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TPoint<int>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TPoint_int__new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  GUI::types::TPoint<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_int__new02_local
static int tolua_GUI_GUI_types_TPoint_int__new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TPoint<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TPoint<int> const* o = ((TPoint<int> const*)  tolua_tousertype(tolua_S,2,0));
  {
   GUI::types::TPoint<int>* tolua_ret = (GUI::types::TPoint<int>*)  Mtolua_new((GUI::types::TPoint<int>)(*o));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TPoint<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TPoint_int__new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  GUI::types::TPoint<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_int___sub00
static int tolua_GUI_GUI_types_TPoint_int___sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TPoint<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TPoint<int>* self = (const GUI::types::TPoint<int>*)  tolua_tousertype(tolua_S,1,0);
  TPoint<int> const* o = ((TPoint<int> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   GUI::types::TPoint<int> tolua_ret = (GUI::types::TPoint<int>)  self->operator-(*o);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TPoint<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TPoint<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TPoint<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TPoint<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  GUI::types::TPoint<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_int___add00
static int tolua_GUI_GUI_types_TPoint_int___add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TPoint<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TPoint<int>* self = (const GUI::types::TPoint<int>*)  tolua_tousertype(tolua_S,1,0);
  TPoint<int> const* o = ((TPoint<int> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   GUI::types::TPoint<int> tolua_ret = (GUI::types::TPoint<int>)  self->operator+(*o);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TPoint<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TPoint<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TPoint<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TPoint<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  GUI::types::TPoint<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_int___eq00
static int tolua_GUI_GUI_types_TPoint_int___eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TPoint<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TPoint<int>* self = (const GUI::types::TPoint<int>*)  tolua_tousertype(tolua_S,1,0);
  TPoint<int> const* o = ((TPoint<int> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*o);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  GUI::types::TPoint<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_int__Clear00
static int tolua_GUI_GUI_types_TPoint_int__Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::types::TPoint<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::types::TPoint<int>* self = (GUI::types::TPoint<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'", NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set of class  GUI::types::TPoint<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_int__Set00
static int tolua_GUI_GUI_types_TPoint_int__Set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::types::TPoint<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::types::TPoint<int>* self = (GUI::types::TPoint<int>*)  tolua_tousertype(tolua_S,1,0);
  int const* left = ((int const*)  tolua_tousertype(tolua_S,2,0));
  int const* top = ((int const*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set'", NULL);
#endif
  {
   self->Set(*left,*top);
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

/* method: Swap of class  GUI::types::TPoint<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_int__Swap00
static int tolua_GUI_GUI_types_TPoint_int__Swap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::types::TPoint<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GUI::types::TPoint<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::types::TPoint<int>* self = (GUI::types::TPoint<int>*)  tolua_tousertype(tolua_S,1,0);
  GUI::types::TPoint<int>* value = ((GUI::types::TPoint<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Swap'", NULL);
#endif
  {
   self->Swap(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Swap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Empty of class  GUI::types::TPoint<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_int__Empty00
static int tolua_GUI_GUI_types_TPoint_int__Empty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TPoint<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TPoint<int>* self = (const GUI::types::TPoint<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Empty'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Empty();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Empty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Print of class  GUI::types::TPoint<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_int__Print00
static int tolua_GUI_GUI_types_TPoint_int__Print00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TPoint<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TPoint<int>* self = (const GUI::types::TPoint<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Print'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->Print();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Print'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Parse of class  GUI::types::TPoint<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_int__Parse00
static int tolua_GUI_GUI_types_TPoint_int__Parse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TPoint<int>",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   GUI::types::TPoint<int> tolua_ret = (GUI::types::TPoint<int>)  GUI::types::TPoint<int>::Parse(value);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TPoint<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TPoint<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TPoint<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TPoint<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Parse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: left of class  GUI::types::TPoint<float> */
#ifndef TOLUA_DISABLE_tolua_get_GUI__types__TPoint_float__left
static int tolua_get_GUI__types__TPoint_float__left(lua_State* tolua_S)
{
  GUI::types::TPoint<float>* self = (GUI::types::TPoint<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'left'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->left);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: left of class  GUI::types::TPoint<float> */
#ifndef TOLUA_DISABLE_tolua_set_GUI__types__TPoint_float__left
static int tolua_set_GUI__types__TPoint_float__left(lua_State* tolua_S)
{
  GUI::types::TPoint<float>* self = (GUI::types::TPoint<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'left'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->left = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: top of class  GUI::types::TPoint<float> */
#ifndef TOLUA_DISABLE_tolua_get_GUI__types__TPoint_float__top
static int tolua_get_GUI__types__TPoint_float__top(lua_State* tolua_S)
{
  GUI::types::TPoint<float>* self = (GUI::types::TPoint<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'top'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->top);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: top of class  GUI::types::TPoint<float> */
#ifndef TOLUA_DISABLE_tolua_set_GUI__types__TPoint_float__top
static int tolua_set_GUI__types__TPoint_float__top(lua_State* tolua_S)
{
  GUI::types::TPoint<float>* self = (GUI::types::TPoint<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'top'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->top = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GUI::types::TPoint<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_float__new00
static int tolua_GUI_GUI_types_TPoint_float__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TPoint<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GUI::types::TPoint<float>* tolua_ret = (GUI::types::TPoint<float>*)  Mtolua_new((GUI::types::TPoint<float>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TPoint<float>");
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

/* method: new_local of class  GUI::types::TPoint<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_float__new00_local
static int tolua_GUI_GUI_types_TPoint_float__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TPoint<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GUI::types::TPoint<float>* tolua_ret = (GUI::types::TPoint<float>*)  Mtolua_new((GUI::types::TPoint<float>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TPoint<float>");
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

/* method: new of class  GUI::types::TPoint<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_float__new01
static int tolua_GUI_GUI_types_TPoint_float__new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TPoint<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float const* left = ((float const*)  tolua_tousertype(tolua_S,2,0));
  float const* top = ((float const*)  tolua_tousertype(tolua_S,3,0));
  {
   GUI::types::TPoint<float>* tolua_ret = (GUI::types::TPoint<float>*)  Mtolua_new((GUI::types::TPoint<float>)(*left,*top));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TPoint<float>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TPoint_float__new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  GUI::types::TPoint<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_float__new01_local
static int tolua_GUI_GUI_types_TPoint_float__new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TPoint<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float const* left = ((float const*)  tolua_tousertype(tolua_S,2,0));
  float const* top = ((float const*)  tolua_tousertype(tolua_S,3,0));
  {
   GUI::types::TPoint<float>* tolua_ret = (GUI::types::TPoint<float>*)  Mtolua_new((GUI::types::TPoint<float>)(*left,*top));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TPoint<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TPoint_float__new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GUI::types::TPoint<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_float__new02
static int tolua_GUI_GUI_types_TPoint_float__new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TPoint<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TPoint<float> const* o = ((TPoint<float> const*)  tolua_tousertype(tolua_S,2,0));
  {
   GUI::types::TPoint<float>* tolua_ret = (GUI::types::TPoint<float>*)  Mtolua_new((GUI::types::TPoint<float>)(*o));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TPoint<float>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TPoint_float__new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  GUI::types::TPoint<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_float__new02_local
static int tolua_GUI_GUI_types_TPoint_float__new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TPoint<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TPoint<float> const* o = ((TPoint<float> const*)  tolua_tousertype(tolua_S,2,0));
  {
   GUI::types::TPoint<float>* tolua_ret = (GUI::types::TPoint<float>*)  Mtolua_new((GUI::types::TPoint<float>)(*o));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TPoint<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TPoint_float__new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  GUI::types::TPoint<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_float___sub00
static int tolua_GUI_GUI_types_TPoint_float___sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TPoint<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TPoint<float>* self = (const GUI::types::TPoint<float>*)  tolua_tousertype(tolua_S,1,0);
  TPoint<float> const* o = ((TPoint<float> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   GUI::types::TPoint<float> tolua_ret = (GUI::types::TPoint<float>)  self->operator-(*o);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TPoint<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TPoint<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TPoint<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TPoint<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  GUI::types::TPoint<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_float___add00
static int tolua_GUI_GUI_types_TPoint_float___add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TPoint<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TPoint<float>* self = (const GUI::types::TPoint<float>*)  tolua_tousertype(tolua_S,1,0);
  TPoint<float> const* o = ((TPoint<float> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   GUI::types::TPoint<float> tolua_ret = (GUI::types::TPoint<float>)  self->operator+(*o);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TPoint<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TPoint<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TPoint<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TPoint<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  GUI::types::TPoint<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_float___eq00
static int tolua_GUI_GUI_types_TPoint_float___eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TPoint<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TPoint<float>* self = (const GUI::types::TPoint<float>*)  tolua_tousertype(tolua_S,1,0);
  TPoint<float> const* o = ((TPoint<float> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*o);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  GUI::types::TPoint<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_float__Clear00
static int tolua_GUI_GUI_types_TPoint_float__Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::types::TPoint<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::types::TPoint<float>* self = (GUI::types::TPoint<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'", NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set of class  GUI::types::TPoint<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_float__Set00
static int tolua_GUI_GUI_types_TPoint_float__Set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::types::TPoint<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::types::TPoint<float>* self = (GUI::types::TPoint<float>*)  tolua_tousertype(tolua_S,1,0);
  float const* left = ((float const*)  tolua_tousertype(tolua_S,2,0));
  float const* top = ((float const*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set'", NULL);
#endif
  {
   self->Set(*left,*top);
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

/* method: Swap of class  GUI::types::TPoint<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_float__Swap00
static int tolua_GUI_GUI_types_TPoint_float__Swap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::types::TPoint<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GUI::types::TPoint<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::types::TPoint<float>* self = (GUI::types::TPoint<float>*)  tolua_tousertype(tolua_S,1,0);
  GUI::types::TPoint<float>* value = ((GUI::types::TPoint<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Swap'", NULL);
#endif
  {
   self->Swap(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Swap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Empty of class  GUI::types::TPoint<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_float__Empty00
static int tolua_GUI_GUI_types_TPoint_float__Empty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TPoint<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TPoint<float>* self = (const GUI::types::TPoint<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Empty'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Empty();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Empty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Print of class  GUI::types::TPoint<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_float__Print00
static int tolua_GUI_GUI_types_TPoint_float__Print00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TPoint<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TPoint<float>* self = (const GUI::types::TPoint<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Print'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->Print();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Print'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Parse of class  GUI::types::TPoint<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TPoint_float__Parse00
static int tolua_GUI_GUI_types_TPoint_float__Parse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TPoint<float>",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   GUI::types::TPoint<float> tolua_ret = (GUI::types::TPoint<float>)  GUI::types::TPoint<float>::Parse(value);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TPoint<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TPoint<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TPoint<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TPoint<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Parse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: left of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_get_GUI__types__TRect_int__left
static int tolua_get_GUI__types__TRect_int__left(lua_State* tolua_S)
{
  GUI::types::TRect<int>* self = (GUI::types::TRect<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'left'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->left);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: left of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_set_GUI__types__TRect_int__left
static int tolua_set_GUI__types__TRect_int__left(lua_State* tolua_S)
{
  GUI::types::TRect<int>* self = (GUI::types::TRect<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'left'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->left = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: top of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_get_GUI__types__TRect_int__top
static int tolua_get_GUI__types__TRect_int__top(lua_State* tolua_S)
{
  GUI::types::TRect<int>* self = (GUI::types::TRect<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'top'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->top);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: top of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_set_GUI__types__TRect_int__top
static int tolua_set_GUI__types__TRect_int__top(lua_State* tolua_S)
{
  GUI::types::TRect<int>* self = (GUI::types::TRect<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'top'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->top = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: right of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_get_GUI__types__TRect_int__right
static int tolua_get_GUI__types__TRect_int__right(lua_State* tolua_S)
{
  GUI::types::TRect<int>* self = (GUI::types::TRect<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'right'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->right);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: right of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_set_GUI__types__TRect_int__right
static int tolua_set_GUI__types__TRect_int__right(lua_State* tolua_S)
{
  GUI::types::TRect<int>* self = (GUI::types::TRect<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'right'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->right = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: bottom of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_get_GUI__types__TRect_int__bottom
static int tolua_get_GUI__types__TRect_int__bottom(lua_State* tolua_S)
{
  GUI::types::TRect<int>* self = (GUI::types::TRect<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bottom'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->bottom);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: bottom of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_set_GUI__types__TRect_int__bottom
static int tolua_set_GUI__types__TRect_int__bottom(lua_State* tolua_S)
{
  GUI::types::TRect<int>* self = (GUI::types::TRect<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bottom'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->bottom = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_int__new00
static int tolua_GUI_GUI_types_TRect_int__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TRect<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GUI::types::TRect<int>* tolua_ret = (GUI::types::TRect<int>*)  Mtolua_new((GUI::types::TRect<int>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TRect<int>");
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

/* method: new_local of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_int__new00_local
static int tolua_GUI_GUI_types_TRect_int__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TRect<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GUI::types::TRect<int>* tolua_ret = (GUI::types::TRect<int>*)  Mtolua_new((GUI::types::TRect<int>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TRect<int>");
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

/* method: new of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_int__new01
static int tolua_GUI_GUI_types_TRect_int__new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TRect<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int const* left = ((int const*)  tolua_tousertype(tolua_S,2,0));
  int const* top = ((int const*)  tolua_tousertype(tolua_S,3,0));
  int const* right = ((int const*)  tolua_tousertype(tolua_S,4,0));
  int const* bottom = ((int const*)  tolua_tousertype(tolua_S,5,0));
  {
   GUI::types::TRect<int>* tolua_ret = (GUI::types::TRect<int>*)  Mtolua_new((GUI::types::TRect<int>)(*left,*top,*right,*bottom));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TRect<int>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TRect_int__new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_int__new01_local
static int tolua_GUI_GUI_types_TRect_int__new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TRect<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int const* left = ((int const*)  tolua_tousertype(tolua_S,2,0));
  int const* top = ((int const*)  tolua_tousertype(tolua_S,3,0));
  int const* right = ((int const*)  tolua_tousertype(tolua_S,4,0));
  int const* bottom = ((int const*)  tolua_tousertype(tolua_S,5,0));
  {
   GUI::types::TRect<int>* tolua_ret = (GUI::types::TRect<int>*)  Mtolua_new((GUI::types::TRect<int>)(*left,*top,*right,*bottom));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TRect<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TRect_int__new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_int__new02
static int tolua_GUI_GUI_types_TRect_int__new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TRect<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TRect<int> const* o = ((TRect<int> const*)  tolua_tousertype(tolua_S,2,0));
  {
   GUI::types::TRect<int>* tolua_ret = (GUI::types::TRect<int>*)  Mtolua_new((GUI::types::TRect<int>)(*o));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TRect<int>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TRect_int__new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_int__new02_local
static int tolua_GUI_GUI_types_TRect_int__new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TRect<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TRect<int> const* o = ((TRect<int> const*)  tolua_tousertype(tolua_S,2,0));
  {
   GUI::types::TRect<int>* tolua_ret = (GUI::types::TRect<int>*)  Mtolua_new((GUI::types::TRect<int>)(*o));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TRect<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TRect_int__new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_int___sub00
static int tolua_GUI_GUI_types_TRect_int___sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TRect<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TRect<int>* self = (const GUI::types::TRect<int>*)  tolua_tousertype(tolua_S,1,0);
  TRect<int> const* o = ((TRect<int> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   GUI::types::TRect<int> tolua_ret = (GUI::types::TRect<int>)  self->operator-(*o);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TRect<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TRect<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TRect<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TRect<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_int___add00
static int tolua_GUI_GUI_types_TRect_int___add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TRect<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TRect<int>* self = (const GUI::types::TRect<int>*)  tolua_tousertype(tolua_S,1,0);
  TRect<int> const* o = ((TRect<int> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   GUI::types::TRect<int> tolua_ret = (GUI::types::TRect<int>)  self->operator+(*o);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TRect<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TRect<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TRect<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TRect<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_int___eq00
static int tolua_GUI_GUI_types_TRect_int___eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TRect<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TRect<int>* self = (const GUI::types::TRect<int>*)  tolua_tousertype(tolua_S,1,0);
  TRect<int> const* o = ((TRect<int> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*o);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Width of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_int__Width00
static int tolua_GUI_GUI_types_TRect_int__Width00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TRect<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TRect<int>* self = (const GUI::types::TRect<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Width'", NULL);
#endif
  {
   int tolua_ret = (int)  self->Width();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Width'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Height of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_int__Height00
static int tolua_GUI_GUI_types_TRect_int__Height00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TRect<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TRect<int>* self = (const GUI::types::TRect<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Height'", NULL);
#endif
  {
   int tolua_ret = (int)  self->Height();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Height'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_int__Clear00
static int tolua_GUI_GUI_types_TRect_int__Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::types::TRect<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::types::TRect<int>* self = (GUI::types::TRect<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'", NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_int__Set00
static int tolua_GUI_GUI_types_TRect_int__Set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::types::TRect<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::types::TRect<int>* self = (GUI::types::TRect<int>*)  tolua_tousertype(tolua_S,1,0);
  int const* left = ((int const*)  tolua_tousertype(tolua_S,2,0));
  int const* top = ((int const*)  tolua_tousertype(tolua_S,3,0));
  int const* right = ((int const*)  tolua_tousertype(tolua_S,4,0));
  int const* bottom = ((int const*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set'", NULL);
#endif
  {
   self->Set(*left,*top,*right,*bottom);
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

/* method: Swap of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_int__Swap00
static int tolua_GUI_GUI_types_TRect_int__Swap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::types::TRect<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GUI::types::TRect<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::types::TRect<int>* self = (GUI::types::TRect<int>*)  tolua_tousertype(tolua_S,1,0);
  GUI::types::TRect<int>* value = ((GUI::types::TRect<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Swap'", NULL);
#endif
  {
   self->Swap(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Swap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Empty of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_int__Empty00
static int tolua_GUI_GUI_types_TRect_int__Empty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TRect<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TRect<int>* self = (const GUI::types::TRect<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Empty'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Empty();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Empty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Inside of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_int__Inside00
static int tolua_GUI_GUI_types_TRect_int__Inside00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TRect<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::types::TRect<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TRect<int>* self = (const GUI::types::TRect<int>*)  tolua_tousertype(tolua_S,1,0);
  const GUI::types::TRect<int>* value = ((const GUI::types::TRect<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Inside'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Inside(*value);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Inside'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Intersect of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_int__Intersect00
static int tolua_GUI_GUI_types_TRect_int__Intersect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TRect<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::types::TRect<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TRect<int>* self = (const GUI::types::TRect<int>*)  tolua_tousertype(tolua_S,1,0);
  const GUI::types::TRect<int>* value = ((const GUI::types::TRect<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Intersect'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Intersect(*value);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Intersect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Inside of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_int__Inside01
static int tolua_GUI_GUI_types_TRect_int__Inside01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TRect<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::types::TPoint<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const GUI::types::TRect<int>* self = (const GUI::types::TRect<int>*)  tolua_tousertype(tolua_S,1,0);
  const GUI::types::TPoint<int>* value = ((const GUI::types::TPoint<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Inside'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Inside(*value);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TRect_int__Inside00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Print of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_int__Print00
static int tolua_GUI_GUI_types_TRect_int__Print00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TRect<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TRect<int>* self = (const GUI::types::TRect<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Print'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->Print();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Print'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Parse of class  GUI::types::TRect<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_int__Parse00
static int tolua_GUI_GUI_types_TRect_int__Parse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TRect<int>",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   GUI::types::TRect<int> tolua_ret = (GUI::types::TRect<int>)  GUI::types::TRect<int>::Parse(value);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TRect<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TRect<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TRect<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TRect<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Parse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: left of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_get_GUI__types__TRect_float__left
static int tolua_get_GUI__types__TRect_float__left(lua_State* tolua_S)
{
  GUI::types::TRect<float>* self = (GUI::types::TRect<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'left'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->left);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: left of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_set_GUI__types__TRect_float__left
static int tolua_set_GUI__types__TRect_float__left(lua_State* tolua_S)
{
  GUI::types::TRect<float>* self = (GUI::types::TRect<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'left'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->left = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: top of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_get_GUI__types__TRect_float__top
static int tolua_get_GUI__types__TRect_float__top(lua_State* tolua_S)
{
  GUI::types::TRect<float>* self = (GUI::types::TRect<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'top'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->top);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: top of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_set_GUI__types__TRect_float__top
static int tolua_set_GUI__types__TRect_float__top(lua_State* tolua_S)
{
  GUI::types::TRect<float>* self = (GUI::types::TRect<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'top'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->top = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: right of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_get_GUI__types__TRect_float__right
static int tolua_get_GUI__types__TRect_float__right(lua_State* tolua_S)
{
  GUI::types::TRect<float>* self = (GUI::types::TRect<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'right'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->right);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: right of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_set_GUI__types__TRect_float__right
static int tolua_set_GUI__types__TRect_float__right(lua_State* tolua_S)
{
  GUI::types::TRect<float>* self = (GUI::types::TRect<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'right'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->right = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: bottom of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_get_GUI__types__TRect_float__bottom
static int tolua_get_GUI__types__TRect_float__bottom(lua_State* tolua_S)
{
  GUI::types::TRect<float>* self = (GUI::types::TRect<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bottom'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->bottom);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: bottom of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_set_GUI__types__TRect_float__bottom
static int tolua_set_GUI__types__TRect_float__bottom(lua_State* tolua_S)
{
  GUI::types::TRect<float>* self = (GUI::types::TRect<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bottom'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->bottom = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_float__new00
static int tolua_GUI_GUI_types_TRect_float__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TRect<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GUI::types::TRect<float>* tolua_ret = (GUI::types::TRect<float>*)  Mtolua_new((GUI::types::TRect<float>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TRect<float>");
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

/* method: new_local of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_float__new00_local
static int tolua_GUI_GUI_types_TRect_float__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TRect<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GUI::types::TRect<float>* tolua_ret = (GUI::types::TRect<float>*)  Mtolua_new((GUI::types::TRect<float>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TRect<float>");
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

/* method: new of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_float__new01
static int tolua_GUI_GUI_types_TRect_float__new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TRect<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float const* left = ((float const*)  tolua_tousertype(tolua_S,2,0));
  float const* top = ((float const*)  tolua_tousertype(tolua_S,3,0));
  float const* right = ((float const*)  tolua_tousertype(tolua_S,4,0));
  float const* bottom = ((float const*)  tolua_tousertype(tolua_S,5,0));
  {
   GUI::types::TRect<float>* tolua_ret = (GUI::types::TRect<float>*)  Mtolua_new((GUI::types::TRect<float>)(*left,*top,*right,*bottom));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TRect<float>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TRect_float__new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_float__new01_local
static int tolua_GUI_GUI_types_TRect_float__new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TRect<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float const* left = ((float const*)  tolua_tousertype(tolua_S,2,0));
  float const* top = ((float const*)  tolua_tousertype(tolua_S,3,0));
  float const* right = ((float const*)  tolua_tousertype(tolua_S,4,0));
  float const* bottom = ((float const*)  tolua_tousertype(tolua_S,5,0));
  {
   GUI::types::TRect<float>* tolua_ret = (GUI::types::TRect<float>*)  Mtolua_new((GUI::types::TRect<float>)(*left,*top,*right,*bottom));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TRect<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TRect_float__new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_float__new02
static int tolua_GUI_GUI_types_TRect_float__new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TRect<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TRect<float> const* o = ((TRect<float> const*)  tolua_tousertype(tolua_S,2,0));
  {
   GUI::types::TRect<float>* tolua_ret = (GUI::types::TRect<float>*)  Mtolua_new((GUI::types::TRect<float>)(*o));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TRect<float>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TRect_float__new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_float__new02_local
static int tolua_GUI_GUI_types_TRect_float__new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TRect<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TRect<float> const* o = ((TRect<float> const*)  tolua_tousertype(tolua_S,2,0));
  {
   GUI::types::TRect<float>* tolua_ret = (GUI::types::TRect<float>*)  Mtolua_new((GUI::types::TRect<float>)(*o));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TRect<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TRect_float__new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_float___sub00
static int tolua_GUI_GUI_types_TRect_float___sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TRect<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TRect<float>* self = (const GUI::types::TRect<float>*)  tolua_tousertype(tolua_S,1,0);
  TRect<float> const* o = ((TRect<float> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   GUI::types::TRect<float> tolua_ret = (GUI::types::TRect<float>)  self->operator-(*o);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TRect<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TRect<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TRect<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TRect<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_float___add00
static int tolua_GUI_GUI_types_TRect_float___add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TRect<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TRect<float>* self = (const GUI::types::TRect<float>*)  tolua_tousertype(tolua_S,1,0);
  TRect<float> const* o = ((TRect<float> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   GUI::types::TRect<float> tolua_ret = (GUI::types::TRect<float>)  self->operator+(*o);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TRect<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TRect<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TRect<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TRect<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_float___eq00
static int tolua_GUI_GUI_types_TRect_float___eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TRect<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TRect<float>* self = (const GUI::types::TRect<float>*)  tolua_tousertype(tolua_S,1,0);
  TRect<float> const* o = ((TRect<float> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*o);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Width of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_float__Width00
static int tolua_GUI_GUI_types_TRect_float__Width00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TRect<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TRect<float>* self = (const GUI::types::TRect<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Width'", NULL);
#endif
  {
   float tolua_ret = (float)  self->Width();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Width'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Height of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_float__Height00
static int tolua_GUI_GUI_types_TRect_float__Height00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TRect<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TRect<float>* self = (const GUI::types::TRect<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Height'", NULL);
#endif
  {
   float tolua_ret = (float)  self->Height();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Height'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_float__Clear00
static int tolua_GUI_GUI_types_TRect_float__Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::types::TRect<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::types::TRect<float>* self = (GUI::types::TRect<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'", NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_float__Set00
static int tolua_GUI_GUI_types_TRect_float__Set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::types::TRect<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::types::TRect<float>* self = (GUI::types::TRect<float>*)  tolua_tousertype(tolua_S,1,0);
  float const* left = ((float const*)  tolua_tousertype(tolua_S,2,0));
  float const* top = ((float const*)  tolua_tousertype(tolua_S,3,0));
  float const* right = ((float const*)  tolua_tousertype(tolua_S,4,0));
  float const* bottom = ((float const*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set'", NULL);
#endif
  {
   self->Set(*left,*top,*right,*bottom);
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

/* method: Swap of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_float__Swap00
static int tolua_GUI_GUI_types_TRect_float__Swap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::types::TRect<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GUI::types::TRect<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::types::TRect<float>* self = (GUI::types::TRect<float>*)  tolua_tousertype(tolua_S,1,0);
  GUI::types::TRect<float>* value = ((GUI::types::TRect<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Swap'", NULL);
#endif
  {
   self->Swap(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Swap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Empty of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_float__Empty00
static int tolua_GUI_GUI_types_TRect_float__Empty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TRect<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TRect<float>* self = (const GUI::types::TRect<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Empty'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Empty();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Empty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Inside of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_float__Inside00
static int tolua_GUI_GUI_types_TRect_float__Inside00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TRect<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::types::TRect<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TRect<float>* self = (const GUI::types::TRect<float>*)  tolua_tousertype(tolua_S,1,0);
  const GUI::types::TRect<float>* value = ((const GUI::types::TRect<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Inside'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Inside(*value);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Inside'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Intersect of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_float__Intersect00
static int tolua_GUI_GUI_types_TRect_float__Intersect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TRect<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::types::TRect<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TRect<float>* self = (const GUI::types::TRect<float>*)  tolua_tousertype(tolua_S,1,0);
  const GUI::types::TRect<float>* value = ((const GUI::types::TRect<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Intersect'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Intersect(*value);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Intersect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Inside of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_float__Inside01
static int tolua_GUI_GUI_types_TRect_float__Inside01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TRect<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::types::TPoint<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const GUI::types::TRect<float>* self = (const GUI::types::TRect<float>*)  tolua_tousertype(tolua_S,1,0);
  const GUI::types::TPoint<float>* value = ((const GUI::types::TPoint<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Inside'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Inside(*value);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TRect_float__Inside00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Print of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_float__Print00
static int tolua_GUI_GUI_types_TRect_float__Print00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TRect<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TRect<float>* self = (const GUI::types::TRect<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Print'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->Print();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Print'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Parse of class  GUI::types::TRect<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TRect_float__Parse00
static int tolua_GUI_GUI_types_TRect_float__Parse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TRect<float>",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   GUI::types::TRect<float> tolua_ret = (GUI::types::TRect<float>)  GUI::types::TRect<float>::Parse(value);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TRect<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TRect<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TRect<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TRect<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Parse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: width of class  GUI::types::TSize<int> */
#ifndef TOLUA_DISABLE_tolua_get_GUI__types__TSize_int__width
static int tolua_get_GUI__types__TSize_int__width(lua_State* tolua_S)
{
  GUI::types::TSize<int>* self = (GUI::types::TSize<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->width);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: width of class  GUI::types::TSize<int> */
#ifndef TOLUA_DISABLE_tolua_set_GUI__types__TSize_int__width
static int tolua_set_GUI__types__TSize_int__width(lua_State* tolua_S)
{
  GUI::types::TSize<int>* self = (GUI::types::TSize<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->width = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: height of class  GUI::types::TSize<int> */
#ifndef TOLUA_DISABLE_tolua_get_GUI__types__TSize_int__height
static int tolua_get_GUI__types__TSize_int__height(lua_State* tolua_S)
{
  GUI::types::TSize<int>* self = (GUI::types::TSize<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->height);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: height of class  GUI::types::TSize<int> */
#ifndef TOLUA_DISABLE_tolua_set_GUI__types__TSize_int__height
static int tolua_set_GUI__types__TSize_int__height(lua_State* tolua_S)
{
  GUI::types::TSize<int>* self = (GUI::types::TSize<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->height = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GUI::types::TSize<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_int__new00
static int tolua_GUI_GUI_types_TSize_int__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TSize<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GUI::types::TSize<int>* tolua_ret = (GUI::types::TSize<int>*)  Mtolua_new((GUI::types::TSize<int>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TSize<int>");
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

/* method: new_local of class  GUI::types::TSize<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_int__new00_local
static int tolua_GUI_GUI_types_TSize_int__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TSize<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GUI::types::TSize<int>* tolua_ret = (GUI::types::TSize<int>*)  Mtolua_new((GUI::types::TSize<int>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TSize<int>");
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

/* method: new of class  GUI::types::TSize<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_int__new01
static int tolua_GUI_GUI_types_TSize_int__new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TSize<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int const* w = ((int const*)  tolua_tousertype(tolua_S,2,0));
  int const* h = ((int const*)  tolua_tousertype(tolua_S,3,0));
  {
   GUI::types::TSize<int>* tolua_ret = (GUI::types::TSize<int>*)  Mtolua_new((GUI::types::TSize<int>)(*w,*h));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TSize<int>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TSize_int__new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  GUI::types::TSize<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_int__new01_local
static int tolua_GUI_GUI_types_TSize_int__new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TSize<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int const* w = ((int const*)  tolua_tousertype(tolua_S,2,0));
  int const* h = ((int const*)  tolua_tousertype(tolua_S,3,0));
  {
   GUI::types::TSize<int>* tolua_ret = (GUI::types::TSize<int>*)  Mtolua_new((GUI::types::TSize<int>)(*w,*h));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TSize<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TSize_int__new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GUI::types::TSize<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_int__new02
static int tolua_GUI_GUI_types_TSize_int__new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TSize<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TSize<int> const* o = ((TSize<int> const*)  tolua_tousertype(tolua_S,2,0));
  {
   GUI::types::TSize<int>* tolua_ret = (GUI::types::TSize<int>*)  Mtolua_new((GUI::types::TSize<int>)(*o));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TSize<int>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TSize_int__new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  GUI::types::TSize<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_int__new02_local
static int tolua_GUI_GUI_types_TSize_int__new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TSize<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TSize<int> const* o = ((TSize<int> const*)  tolua_tousertype(tolua_S,2,0));
  {
   GUI::types::TSize<int>* tolua_ret = (GUI::types::TSize<int>*)  Mtolua_new((GUI::types::TSize<int>)(*o));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TSize<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TSize_int__new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  GUI::types::TSize<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_int___sub00
static int tolua_GUI_GUI_types_TSize_int___sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TSize<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TSize<int>* self = (const GUI::types::TSize<int>*)  tolua_tousertype(tolua_S,1,0);
  TSize<int> const* o = ((TSize<int> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   GUI::types::TSize<int> tolua_ret = (GUI::types::TSize<int>)  self->operator-(*o);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TSize<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TSize<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TSize<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TSize<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  GUI::types::TSize<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_int___add00
static int tolua_GUI_GUI_types_TSize_int___add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TSize<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TSize<int>* self = (const GUI::types::TSize<int>*)  tolua_tousertype(tolua_S,1,0);
  TSize<int> const* o = ((TSize<int> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   GUI::types::TSize<int> tolua_ret = (GUI::types::TSize<int>)  self->operator+(*o);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TSize<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TSize<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TSize<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TSize<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  GUI::types::TSize<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_int___eq00
static int tolua_GUI_GUI_types_TSize_int___eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TSize<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TSize<int>* self = (const GUI::types::TSize<int>*)  tolua_tousertype(tolua_S,1,0);
  TSize<int> const* o = ((TSize<int> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*o);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  GUI::types::TSize<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_int__Clear00
static int tolua_GUI_GUI_types_TSize_int__Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::types::TSize<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::types::TSize<int>* self = (GUI::types::TSize<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'", NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set of class  GUI::types::TSize<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_int__Set00
static int tolua_GUI_GUI_types_TSize_int__Set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::types::TSize<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::types::TSize<int>* self = (GUI::types::TSize<int>*)  tolua_tousertype(tolua_S,1,0);
  int const* w = ((int const*)  tolua_tousertype(tolua_S,2,0));
  int const* h = ((int const*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set'", NULL);
#endif
  {
   self->Set(*w,*h);
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

/* method: Swap of class  GUI::types::TSize<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_int__Swap00
static int tolua_GUI_GUI_types_TSize_int__Swap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::types::TSize<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GUI::types::TSize<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::types::TSize<int>* self = (GUI::types::TSize<int>*)  tolua_tousertype(tolua_S,1,0);
  GUI::types::TSize<int>* value = ((GUI::types::TSize<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Swap'", NULL);
#endif
  {
   self->Swap(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Swap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Empty of class  GUI::types::TSize<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_int__Empty00
static int tolua_GUI_GUI_types_TSize_int__Empty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TSize<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TSize<int>* self = (const GUI::types::TSize<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Empty'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Empty();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Empty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Print of class  GUI::types::TSize<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_int__Print00
static int tolua_GUI_GUI_types_TSize_int__Print00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TSize<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TSize<int>* self = (const GUI::types::TSize<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Print'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->Print();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Print'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Parse of class  GUI::types::TSize<int> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_int__Parse00
static int tolua_GUI_GUI_types_TSize_int__Parse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TSize<int>",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   GUI::types::TSize<int> tolua_ret = (GUI::types::TSize<int>)  GUI::types::TSize<int>::Parse(value);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TSize<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TSize<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TSize<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TSize<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Parse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: width of class  GUI::types::TSize<float> */
#ifndef TOLUA_DISABLE_tolua_get_GUI__types__TSize_float__width
static int tolua_get_GUI__types__TSize_float__width(lua_State* tolua_S)
{
  GUI::types::TSize<float>* self = (GUI::types::TSize<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->width);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: width of class  GUI::types::TSize<float> */
#ifndef TOLUA_DISABLE_tolua_set_GUI__types__TSize_float__width
static int tolua_set_GUI__types__TSize_float__width(lua_State* tolua_S)
{
  GUI::types::TSize<float>* self = (GUI::types::TSize<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->width = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: height of class  GUI::types::TSize<float> */
#ifndef TOLUA_DISABLE_tolua_get_GUI__types__TSize_float__height
static int tolua_get_GUI__types__TSize_float__height(lua_State* tolua_S)
{
  GUI::types::TSize<float>* self = (GUI::types::TSize<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->height);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: height of class  GUI::types::TSize<float> */
#ifndef TOLUA_DISABLE_tolua_set_GUI__types__TSize_float__height
static int tolua_set_GUI__types__TSize_float__height(lua_State* tolua_S)
{
  GUI::types::TSize<float>* self = (GUI::types::TSize<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->height = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GUI::types::TSize<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_float__new00
static int tolua_GUI_GUI_types_TSize_float__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TSize<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GUI::types::TSize<float>* tolua_ret = (GUI::types::TSize<float>*)  Mtolua_new((GUI::types::TSize<float>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TSize<float>");
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

/* method: new_local of class  GUI::types::TSize<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_float__new00_local
static int tolua_GUI_GUI_types_TSize_float__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TSize<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GUI::types::TSize<float>* tolua_ret = (GUI::types::TSize<float>*)  Mtolua_new((GUI::types::TSize<float>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TSize<float>");
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

/* method: new of class  GUI::types::TSize<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_float__new01
static int tolua_GUI_GUI_types_TSize_float__new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TSize<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float const* w = ((float const*)  tolua_tousertype(tolua_S,2,0));
  float const* h = ((float const*)  tolua_tousertype(tolua_S,3,0));
  {
   GUI::types::TSize<float>* tolua_ret = (GUI::types::TSize<float>*)  Mtolua_new((GUI::types::TSize<float>)(*w,*h));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TSize<float>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TSize_float__new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  GUI::types::TSize<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_float__new01_local
static int tolua_GUI_GUI_types_TSize_float__new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TSize<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float const* w = ((float const*)  tolua_tousertype(tolua_S,2,0));
  float const* h = ((float const*)  tolua_tousertype(tolua_S,3,0));
  {
   GUI::types::TSize<float>* tolua_ret = (GUI::types::TSize<float>*)  Mtolua_new((GUI::types::TSize<float>)(*w,*h));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TSize<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TSize_float__new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GUI::types::TSize<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_float__new02
static int tolua_GUI_GUI_types_TSize_float__new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TSize<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TSize<float> const* o = ((TSize<float> const*)  tolua_tousertype(tolua_S,2,0));
  {
   GUI::types::TSize<float>* tolua_ret = (GUI::types::TSize<float>*)  Mtolua_new((GUI::types::TSize<float>)(*o));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TSize<float>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TSize_float__new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  GUI::types::TSize<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_float__new02_local
static int tolua_GUI_GUI_types_TSize_float__new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TSize<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TSize<float> const* o = ((TSize<float> const*)  tolua_tousertype(tolua_S,2,0));
  {
   GUI::types::TSize<float>* tolua_ret = (GUI::types::TSize<float>*)  Mtolua_new((GUI::types::TSize<float>)(*o));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::types::TSize<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_types_TSize_float__new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  GUI::types::TSize<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_float___sub00
static int tolua_GUI_GUI_types_TSize_float___sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TSize<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TSize<float>* self = (const GUI::types::TSize<float>*)  tolua_tousertype(tolua_S,1,0);
  TSize<float> const* o = ((TSize<float> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   GUI::types::TSize<float> tolua_ret = (GUI::types::TSize<float>)  self->operator-(*o);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TSize<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TSize<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TSize<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TSize<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  GUI::types::TSize<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_float___add00
static int tolua_GUI_GUI_types_TSize_float___add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TSize<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TSize<float>* self = (const GUI::types::TSize<float>*)  tolua_tousertype(tolua_S,1,0);
  TSize<float> const* o = ((TSize<float> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   GUI::types::TSize<float> tolua_ret = (GUI::types::TSize<float>)  self->operator+(*o);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TSize<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TSize<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TSize<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TSize<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  GUI::types::TSize<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_float___eq00
static int tolua_GUI_GUI_types_TSize_float___eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TSize<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TSize<float>* self = (const GUI::types::TSize<float>*)  tolua_tousertype(tolua_S,1,0);
  TSize<float> const* o = ((TSize<float> const*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*o);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  GUI::types::TSize<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_float__Clear00
static int tolua_GUI_GUI_types_TSize_float__Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::types::TSize<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::types::TSize<float>* self = (GUI::types::TSize<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'", NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set of class  GUI::types::TSize<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_float__Set00
static int tolua_GUI_GUI_types_TSize_float__Set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::types::TSize<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::types::TSize<float>* self = (GUI::types::TSize<float>*)  tolua_tousertype(tolua_S,1,0);
  float const* w = ((float const*)  tolua_tousertype(tolua_S,2,0));
  float const* h = ((float const*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set'", NULL);
#endif
  {
   self->Set(*w,*h);
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

/* method: Swap of class  GUI::types::TSize<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_float__Swap00
static int tolua_GUI_GUI_types_TSize_float__Swap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::types::TSize<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GUI::types::TSize<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::types::TSize<float>* self = (GUI::types::TSize<float>*)  tolua_tousertype(tolua_S,1,0);
  GUI::types::TSize<float>* value = ((GUI::types::TSize<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Swap'", NULL);
#endif
  {
   self->Swap(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Swap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Empty of class  GUI::types::TSize<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_float__Empty00
static int tolua_GUI_GUI_types_TSize_float__Empty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TSize<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TSize<float>* self = (const GUI::types::TSize<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Empty'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Empty();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Empty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Print of class  GUI::types::TSize<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_float__Print00
static int tolua_GUI_GUI_types_TSize_float__Print00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::types::TSize<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::types::TSize<float>* self = (const GUI::types::TSize<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Print'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->Print();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Print'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Parse of class  GUI::types::TSize<float> */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_types_TSize_float__Parse00
static int tolua_GUI_GUI_types_TSize_float__Parse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::types::TSize<float>",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   GUI::types::TSize<float> tolua_ret = (GUI::types::TSize<float>)  GUI::types::TSize<float>::Parse(value);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::types::TSize<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TSize<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::types::TSize<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::types::TSize<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Parse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsScriptObjValid of class  GUI::UIScriptObject */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UIScriptObject_IsScriptObjValid00
static int tolua_GUI_GUI_UIScriptObject_IsScriptObjValid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::UIScriptObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::UIScriptObject* self = (GUI::UIScriptObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsScriptObjValid'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsScriptObjValid();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsScriptObjValid'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScriptObjID of class  GUI::UIScriptObject */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UIScriptObject_GetScriptObjID00
static int tolua_GUI_GUI_UIScriptObject_GetScriptObjID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::UIScriptObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::UIScriptObject* self = (const GUI::UIScriptObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScriptObjID'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetScriptObjID();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScriptObjID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScriptObjID of class  GUI::UIScriptObject */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UIScriptObject_SetScriptObjID00
static int tolua_GUI_GUI_UIScriptObject_SetScriptObjID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::UIScriptObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::UIScriptObject* self = (GUI::UIScriptObject*)  tolua_tousertype(tolua_S,1,0);
  int objID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScriptObjID'", NULL);
#endif
  {
   self->SetScriptObjID(objID);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScriptObjID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateScriptObj of class  GUI::UIScriptObject */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UIScriptObject_CreateScriptObj00
static int tolua_GUI_GUI_UIScriptObject_CreateScriptObj00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::UIScriptObject",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::UIScriptObject* self = (GUI::UIScriptObject*)  tolua_tousertype(tolua_S,1,0);
  std::string scriptClass = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateScriptObj'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->CreateScriptObj(scriptClass);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateScriptObj'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScriptClass of class  GUI::UIScriptObject */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UIScriptObject_SetScriptClass00
static int tolua_GUI_GUI_UIScriptObject_SetScriptClass00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::UIScriptObject",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::UIScriptObject* self = (GUI::UIScriptObject*)  tolua_tousertype(tolua_S,1,0);
  std::string scriptClass = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScriptClass'", NULL);
#endif
  {
   self->SetScriptClass(scriptClass);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScriptClass'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScriptClass of class  GUI::UIScriptObject */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UIScriptObject_GetScriptClass00
static int tolua_GUI_GUI_UIScriptObject_GetScriptClass00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::UIScriptObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::UIScriptObject* self = (GUI::UIScriptObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScriptClass'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetScriptClass();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScriptClass'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __WidgetEvent__ of class  GUI::UIScriptObject */
#ifndef TOLUA_DISABLE_tolua_get_GUI__UIScriptObject___WidgetEvent__
static int tolua_get_GUI__UIScriptObject___WidgetEvent__(lua_State* tolua_S)
{
  GUI::UIScriptObject* self = (GUI::UIScriptObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__WidgetEvent__'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<WidgetEvent*>(self), "WidgetEvent");
#else
   tolua_pushusertype(tolua_S,(void*)((WidgetEvent*)self), "WidgetEvent");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GUI::UString */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UString_new00
static int tolua_GUI_GUI_UString_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::UString",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* c_str = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   GUI::UString* tolua_ret = (GUI::UString*)  Mtolua_new((GUI::UString)(c_str));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::UString");
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

/* method: new_local of class  GUI::UString */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UString_new00_local
static int tolua_GUI_GUI_UString_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::UString",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* c_str = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   GUI::UString* tolua_ret = (GUI::UString*)  Mtolua_new((GUI::UString)(c_str));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::UString");
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

/* method: new of class  GUI::UString */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UString_new01
static int tolua_GUI_GUI_UString_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::UString",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* c_str = ((const char*)  tolua_tostring(tolua_S,2,0));
   int length = ((  int)  tolua_tonumber(tolua_S,3,0));
  {
   GUI::UString* tolua_ret = (GUI::UString*)  Mtolua_new((GUI::UString)(c_str,length));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::UString");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_UString_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  GUI::UString */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UString_new01_local
static int tolua_GUI_GUI_UString_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::UString",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* c_str = ((const char*)  tolua_tostring(tolua_S,2,0));
   int length = ((  int)  tolua_tonumber(tolua_S,3,0));
  {
   GUI::UString* tolua_ret = (GUI::UString*)  Mtolua_new((GUI::UString)(c_str,length));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::UString");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_UString_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  GUI::UString */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UString_delete00
static int tolua_GUI_GUI_UString_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::UString",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::UString* self = (GUI::UString*)  tolua_tousertype(tolua_S,1,0);
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

/* method: size of class  GUI::UString */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UString_size00
static int tolua_GUI_GUI_UString_size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::UString",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::UString* self = (const GUI::UString*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'size'", NULL);
#endif
  {
    int tolua_ret = (  int)  self->size();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: max_size of class  GUI::UString */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UString_max_size00
static int tolua_GUI_GUI_UString_max_size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::UString",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::UString* self = (const GUI::UString*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'max_size'", NULL);
#endif
  {
    int tolua_ret = (  int)  self->max_size();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'max_size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: reserve of class  GUI::UString */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UString_reserve00
static int tolua_GUI_GUI_UString_reserve00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::UString",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::UString* self = (GUI::UString*)  tolua_tousertype(tolua_S,1,0);
   int size = ((  int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reserve'", NULL);
#endif
  {
   self->reserve(size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reserve'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resize of class  GUI::UString */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UString_resize00
static int tolua_GUI_GUI_UString_resize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::UString",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::UString* self = (GUI::UString*)  tolua_tousertype(tolua_S,1,0);
   int num = ((  int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resize'", NULL);
#endif
  {
   self->resize(num);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resize of class  GUI::UString */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UString_resize01
static int tolua_GUI_GUI_UString_resize01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::UString",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::UString* self = (GUI::UString*)  tolua_tousertype(tolua_S,1,0);
   int num = ((  int)  tolua_tonumber(tolua_S,2,0));
  const char val = ((const char)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resize'", NULL);
#endif
  {
   self->resize(num,val);
   tolua_pushnumber(tolua_S,(lua_Number)val);
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_UString_resize00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: swap of class  GUI::UString */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UString_swap00
static int tolua_GUI_GUI_UString_swap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::UString",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::UString* self = (GUI::UString*)  tolua_tousertype(tolua_S,1,0);
  GUI::UString* from = ((GUI::UString*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'swap'", NULL);
#endif
  {
   self->swap(*from);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'swap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: empty of class  GUI::UString */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UString_empty00
static int tolua_GUI_GUI_UString_empty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::UString",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::UString* self = (const GUI::UString*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'empty'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->empty();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'empty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clear of class  GUI::UString */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UString_clear00
static int tolua_GUI_GUI_UString_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::UString",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::UString* self = (GUI::UString*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clear'", NULL);
#endif
  {
   self->clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: substr of class  GUI::UString */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UString_substr00
static int tolua_GUI_GUI_UString_substr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::UString",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::UString* self = (const GUI::UString*)  tolua_tousertype(tolua_S,1,0);
   int index = ((  int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'substr'", NULL);
#endif
  {
   GUI::UString tolua_ret = (GUI::UString)  self->substr(index);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::UString)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::UString");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::UString));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::UString");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'substr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: substr of class  GUI::UString */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UString_substr01
static int tolua_GUI_GUI_UString_substr01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::UString",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const GUI::UString* self = (const GUI::UString*)  tolua_tousertype(tolua_S,1,0);
   int index = ((  int)  tolua_tonumber(tolua_S,2,0));
   int num = ((  int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'substr'", NULL);
#endif
  {
   GUI::UString tolua_ret = (GUI::UString)  self->substr(index,num);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::UString)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::UString");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::UString));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::UString");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_UString_substr00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: push_back of class  GUI::UString */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UString_push_back00
static int tolua_GUI_GUI_UString_push_back00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::UString",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::UString* self = (GUI::UString*)  tolua_tousertype(tolua_S,1,0);
  char val = ((char)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'push_back'", NULL);
#endif
  {
   self->push_back(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'push_back'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AsUTF8_c_str of class  GUI::UString */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UString_AsUTF8_c_str00
static int tolua_GUI_GUI_UString_AsUTF8_c_str00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::UString",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::UString* self = (const GUI::UString*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AsUTF8_c_str'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->AsUTF8_c_str();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AsUTF8_c_str'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: append of class  GUI::UString */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UString_append00
static int tolua_GUI_GUI_UString_append00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::UString",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::UString* self = (GUI::UString*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* str = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'append'", NULL);
#endif
  {
   GUI::UString& tolua_ret = (GUI::UString&)  self->append(*str);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"GUI::UString");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'append'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: append of class  GUI::UString */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UString_append01
static int tolua_GUI_GUI_UString_append01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::UString",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::UString* self = (GUI::UString*)  tolua_tousertype(tolua_S,1,0);
  const char* c_str = ((const char*)  tolua_tostring(tolua_S,2,0));
   int num = ((  int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'append'", NULL);
#endif
  {
   GUI::UString& tolua_ret = (GUI::UString&)  self->append(c_str,num);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"GUI::UString");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_UString_append00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: compare of class  GUI::UString */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UString_compare00
static int tolua_GUI_GUI_UString_compare00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::UString",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::UString* self = (const GUI::UString*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* str = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'compare'", NULL);
#endif
  {
   int tolua_ret = (int)  self->compare(*str);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'compare'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: compare of class  GUI::UString */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UString_compare01
static int tolua_GUI_GUI_UString_compare01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::UString",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const GUI::UString* self = (const GUI::UString*)  tolua_tousertype(tolua_S,1,0);
   int index = ((  int)  tolua_tonumber(tolua_S,2,0));
   int length = ((  int)  tolua_tonumber(tolua_S,3,0));
  const GUI::UString* str = ((const GUI::UString*)  tolua_tousertype(tolua_S,4,0));
   int index2 = ((  int)  tolua_tonumber(tolua_S,5,0));
   int length2 = ((  int)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'compare'", NULL);
#endif
  {
   int tolua_ret = (int)  self->compare(index,length,*str,index2,length2);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_UString_compare00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: find of class  GUI::UString */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UString_find00
static int tolua_GUI_GUI_UString_find00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::UString",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::UString* self = (const GUI::UString*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* str = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
   int index = ((  int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'find'", NULL);
#endif
  {
    int tolua_ret = (  int)  self->find(*str,index);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'find'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rfind of class  GUI::UString */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UString_rfind00
static int tolua_GUI_GUI_UString_rfind00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::UString",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::UString* self = (const GUI::UString*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* str = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
   int index = ((  int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rfind'", NULL);
#endif
  {
    int tolua_ret = (  int)  self->rfind(*str,index);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rfind'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator&[] of class  GUI::UString */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UString__seti00
static int tolua_GUI_GUI_UString__seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::UString",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::UString* self = (GUI::UString*)  tolua_tousertype(tolua_S,1,0);
   int index = ((  int)  tolua_tonumber(tolua_S,2,0));
   char tolua_value = ((  char)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'", NULL);
#endif
  self->operator[](index) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator[] of class  GUI::UString */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UString__geti00
static int tolua_GUI_GUI_UString__geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::UString",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::UString* self = (GUI::UString*)  tolua_tousertype(tolua_S,1,0);
   int index = ((  int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'", NULL);
#endif
  {
    char tolua_ret = (  char)  self->operator[](index);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScrollRange of class  GUI::VScroll */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_VScroll_SetScrollRange00
static int tolua_GUI_GUI_VScroll_SetScrollRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::VScroll",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::VScroll* self = (GUI::VScroll*)  tolua_tousertype(tolua_S,1,0);
    int value = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScrollRange'", NULL);
#endif
  {
   self->SetScrollRange(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScrollRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScrollRange of class  GUI::VScroll */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_VScroll_GetScrollRange00
static int tolua_GUI_GUI_VScroll_GetScrollRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::VScroll",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::VScroll* self = (GUI::VScroll*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScrollRange'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetScrollRange();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScrollRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScrollPosition of class  GUI::VScroll */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_VScroll_SetScrollPosition00
static int tolua_GUI_GUI_VScroll_SetScrollPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::VScroll",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::VScroll* self = (GUI::VScroll*)  tolua_tousertype(tolua_S,1,0);
    int value = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScrollPosition'", NULL);
#endif
  {
   self->SetScrollPosition(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScrollPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScrollPosition of class  GUI::VScroll */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_VScroll_GetScrollPosition00
static int tolua_GUI_GUI_VScroll_GetScrollPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::VScroll",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::VScroll* self = (GUI::VScroll*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScrollPosition'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetScrollPosition();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScrollPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScrollPage of class  GUI::VScroll */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_VScroll_SetScrollPage00
static int tolua_GUI_GUI_VScroll_SetScrollPage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::VScroll",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::VScroll* self = (GUI::VScroll*)  tolua_tousertype(tolua_S,1,0);
    int value = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScrollPage'", NULL);
#endif
  {
   self->SetScrollPage(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScrollPage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScrollPage of class  GUI::VScroll */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_VScroll_GetScrollPage00
static int tolua_GUI_GUI_VScroll_GetScrollPage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::VScroll",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::VScroll* self = (GUI::VScroll*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScrollPage'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetScrollPage();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScrollPage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScrollViewPage of class  GUI::VScroll */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_VScroll_SetScrollViewPage00
static int tolua_GUI_GUI_VScroll_SetScrollViewPage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::VScroll",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::VScroll* self = (GUI::VScroll*)  tolua_tousertype(tolua_S,1,0);
    int value = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScrollViewPage'", NULL);
#endif
  {
   self->SetScrollViewPage(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScrollViewPage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScrollViewPage of class  GUI::VScroll */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_VScroll_GetScrollViewPage00
static int tolua_GUI_GUI_VScroll_GetScrollViewPage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::VScroll",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::VScroll* self = (GUI::VScroll*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScrollViewPage'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetScrollViewPage();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScrollViewPage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLineSize of class  GUI::VScroll */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_VScroll_GetLineSize00
static int tolua_GUI_GUI_VScroll_GetLineSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::VScroll",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::VScroll* self = (GUI::VScroll*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLineSize'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetLineSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLineSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTrackSize of class  GUI::VScroll */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_VScroll_SetTrackSize00
static int tolua_GUI_GUI_VScroll_SetTrackSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::VScroll",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::VScroll* self = (GUI::VScroll*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTrackSize'", NULL);
#endif
  {
   self->SetTrackSize(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTrackSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTrackSize of class  GUI::VScroll */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_VScroll_GetTrackSize00
static int tolua_GUI_GUI_VScroll_GetTrackSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::VScroll",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::VScroll* self = (GUI::VScroll*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTrackSize'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetTrackSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTrackSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMinTrackSize of class  GUI::VScroll */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_VScroll_SetMinTrackSize00
static int tolua_GUI_GUI_VScroll_SetMinTrackSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::VScroll",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::VScroll* self = (GUI::VScroll*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMinTrackSize'", NULL);
#endif
  {
   self->SetMinTrackSize(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMinTrackSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMinTrackSize of class  GUI::VScroll */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_VScroll_GetMinTrackSize00
static int tolua_GUI_GUI_VScroll_GetMinTrackSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::VScroll",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::VScroll* self = (GUI::VScroll*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMinTrackSize'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetMinTrackSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMinTrackSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMoveToClick of class  GUI::VScroll */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_VScroll_SetMoveToClick00
static int tolua_GUI_GUI_VScroll_SetMoveToClick00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::VScroll",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::VScroll* self = (GUI::VScroll*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMoveToClick'", NULL);
#endif
  {
   self->SetMoveToClick(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMoveToClick'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMoveToClick of class  GUI::VScroll */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_VScroll_GetMoveToClick00
static int tolua_GUI_GUI_VScroll_GetMoveToClick00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::VScroll",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::VScroll* self = (GUI::VScroll*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMoveToClick'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetMoveToClick();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMoveToClick'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  GUI::VScroll */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_VScroll_SetPosition00
static int tolua_GUI_GUI_VScroll_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::VScroll",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::VScroll* self = (GUI::VScroll*)  tolua_tousertype(tolua_S,1,0);
  int left = ((int)  tolua_tonumber(tolua_S,2,0));
  int top = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
  {
   self->SetPosition(left,top);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSize of class  GUI::VScroll */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_VScroll_SetSize00
static int tolua_GUI_GUI_VScroll_SetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::VScroll",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::VScroll* self = (GUI::VScroll*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSize'", NULL);
#endif
  {
   self->SetSize(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCoord of class  GUI::VScroll */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_VScroll_SetCoord00
static int tolua_GUI_GUI_VScroll_SetCoord00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::VScroll",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::VScroll* self = (GUI::VScroll*)  tolua_tousertype(tolua_S,1,0);
  int left = ((int)  tolua_tonumber(tolua_S,2,0));
  int top = ((int)  tolua_tonumber(tolua_S,3,0));
  int width = ((int)  tolua_tonumber(tolua_S,4,0));
  int height = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCoord'", NULL);
#endif
  {
   self->SetCoord(left,top,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCoord'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetProperty of class  GUI::VScroll */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_VScroll_SetProperty00
static int tolua_GUI_GUI_VScroll_SetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::VScroll",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::VScroll* self = (GUI::VScroll*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetProperty'", NULL);
#endif
  {
   self->SetProperty(key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateWidgetT of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_CreateWidgetT00
static int tolua_GUI_GUI_Widget_CreateWidgetT00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,8,&tolua_err) || !tolua_isusertype(tolua_S,8,"GUI::Align",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  const std::string type = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string skin = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  int left = ((int)  tolua_tonumber(tolua_S,4,0));
  int top = ((int)  tolua_tonumber(tolua_S,5,0));
  int width = ((int)  tolua_tonumber(tolua_S,6,0));
  int height = ((int)  tolua_tonumber(tolua_S,7,0));
  GUI::Align align = *((GUI::Align*)  tolua_tousertype(tolua_S,8,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateWidgetT'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->CreateWidgetT(type,skin,left,top,width,height,align);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateWidgetT'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateWidgetT of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_CreateWidgetT01
static int tolua_GUI_GUI_Widget_CreateWidgetT01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,8,&tolua_err) || !tolua_isusertype(tolua_S,8,"GUI::Align",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,9,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,10,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  const std::string type = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string skin = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  int left = ((int)  tolua_tonumber(tolua_S,4,0));
  int top = ((int)  tolua_tonumber(tolua_S,5,0));
  int width = ((int)  tolua_tonumber(tolua_S,6,0));
  int height = ((int)  tolua_tonumber(tolua_S,7,0));
  GUI::Align align = *((GUI::Align*)  tolua_tousertype(tolua_S,8,0));
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,9,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateWidgetT'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->CreateWidgetT(type,skin,left,top,width,height,align,name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_Widget_CreateWidgetT00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateWidgetRealT of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_CreateWidgetRealT00
static int tolua_GUI_GUI_Widget_CreateWidgetRealT00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,8,&tolua_err) || !tolua_isusertype(tolua_S,8,"GUI::Align",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  const std::string type = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string skin = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  float left = ((float)  tolua_tonumber(tolua_S,4,0));
  float top = ((float)  tolua_tonumber(tolua_S,5,0));
  float width = ((float)  tolua_tonumber(tolua_S,6,0));
  float height = ((float)  tolua_tonumber(tolua_S,7,0));
  GUI::Align align = *((GUI::Align*)  tolua_tousertype(tolua_S,8,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateWidgetRealT'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->CreateWidgetRealT(type,skin,left,top,width,height,align);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateWidgetRealT'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateWidgetRealT of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_CreateWidgetRealT01
static int tolua_GUI_GUI_Widget_CreateWidgetRealT01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,8,&tolua_err) || !tolua_isusertype(tolua_S,8,"GUI::Align",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,9,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,10,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  const std::string type = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string skin = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  float left = ((float)  tolua_tonumber(tolua_S,4,0));
  float top = ((float)  tolua_tonumber(tolua_S,5,0));
  float width = ((float)  tolua_tonumber(tolua_S,6,0));
  float height = ((float)  tolua_tonumber(tolua_S,7,0));
  GUI::Align align = *((GUI::Align*)  tolua_tousertype(tolua_S,8,0));
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,9,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateWidgetRealT'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->CreateWidgetRealT(type,skin,left,top,width,height,align,name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_Widget_CreateWidgetRealT00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetName of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_GetName00
static int tolua_GUI_GUI_Widget_GetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::Widget* self = (const GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetName'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetPosition00
static int tolua_GUI_GUI_Widget_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  int left = ((int)  tolua_tonumber(tolua_S,2,0));
  int top = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
  {
   self->SetPosition(left,top);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSize of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetSize00
static int tolua_GUI_GUI_Widget_SetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSize'", NULL);
#endif
  {
   self->SetSize(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCoord of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetCoord00
static int tolua_GUI_GUI_Widget_SetCoord00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  int left = ((int)  tolua_tonumber(tolua_S,2,0));
  int top = ((int)  tolua_tonumber(tolua_S,3,0));
  int width = ((int)  tolua_tonumber(tolua_S,4,0));
  int height = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCoord'", NULL);
#endif
  {
   self->SetCoord(left,top,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCoord'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRealPosition of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetRealPosition00
static int tolua_GUI_GUI_Widget_SetRealPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  float left = ((float)  tolua_tonumber(tolua_S,2,0));
  float top = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRealPosition'", NULL);
#endif
  {
   self->SetRealPosition(left,top);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRealPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRealSize of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetRealSize00
static int tolua_GUI_GUI_Widget_SetRealSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRealSize'", NULL);
#endif
  {
   self->SetRealSize(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRealSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRealCoord of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetRealCoord00
static int tolua_GUI_GUI_Widget_SetRealCoord00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  float left = ((float)  tolua_tonumber(tolua_S,2,0));
  float top = ((float)  tolua_tonumber(tolua_S,3,0));
  float width = ((float)  tolua_tonumber(tolua_S,4,0));
  float height = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRealCoord'", NULL);
#endif
  {
   self->SetRealCoord(left,top,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRealCoord'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVisible of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetVisible00
static int tolua_GUI_GUI_Widget_SetVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVisible'", NULL);
#endif
  {
   self->SetVisible(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAlign of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetAlign00
static int tolua_GUI_GUI_Widget_SetAlign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GUI::Align",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  GUI::Align value = *((GUI::Align*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAlign'", NULL);
#endif
  {
   self->SetAlign(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAlign'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCaption of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetCaption00
static int tolua_GUI_GUI_Widget_SetCaption00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* value = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCaption'", NULL);
#endif
  {
   self->SetCaption(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCaption'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCaption of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_GetCaption00
static int tolua_GUI_GUI_Widget_GetCaption00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCaption'", NULL);
#endif
  {
   const GUI::UString& tolua_ret = (const GUI::UString&)  self->GetCaption();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const GUI::UString");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCaption'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAlpha of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetAlpha00
static int tolua_GUI_GUI_Widget_SetAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAlpha'", NULL);
#endif
  {
   self->SetAlpha(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAlpha'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAlpha of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_GetAlpha00
static int tolua_GUI_GUI_Widget_GetAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAlpha'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetAlpha();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAlpha'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetInheritsAlpha of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetInheritsAlpha00
static int tolua_GUI_GUI_Widget_SetInheritsAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetInheritsAlpha'", NULL);
#endif
  {
   self->SetInheritsAlpha(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetInheritsAlpha'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInheritsAlpha of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_IsInheritsAlpha00
static int tolua_GUI_GUI_Widget_IsInheritsAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsInheritsAlpha'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsInheritsAlpha();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsInheritsAlpha'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetState of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetState00
static int tolua_GUI_GUI_Widget_SetState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetState'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->SetState(value);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetColour of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetColour00
static int tolua_GUI_GUI_Widget_SetColour00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::Colour",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  const GUI::Colour* value = ((const GUI::Colour*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetColour'", NULL);
#endif
  {
   self->SetColour(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetColour'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsRootWidget of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_IsRootWidget00
static int tolua_GUI_GUI_Widget_IsRootWidget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsRootWidget'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsRootWidget();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsRootWidget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetParent of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_GetParent00
static int tolua_GUI_GUI_Widget_GetParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetParent'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->GetParent();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetParent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetChildCount of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_GetChildCount00
static int tolua_GUI_GUI_Widget_GetChildCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetChildCount'", NULL);
#endif
  {
     int tolua_ret = (   int)  self->GetChildCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetChildCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetChildAt of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_GetChildAt00
static int tolua_GUI_GUI_Widget_GetChildAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
    int index = ((   int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetChildAt'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->GetChildAt(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetChildAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FindWidget of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_FindWidget00
static int tolua_GUI_GUI_Widget_FindWidget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindWidget'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->FindWidget(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindWidget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetNeedKeyFocus of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetNeedKeyFocus00
static int tolua_GUI_GUI_Widget_SetNeedKeyFocus00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetNeedKeyFocus'", NULL);
#endif
  {
   self->SetNeedKeyFocus(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetNeedKeyFocus'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsNeedKeyFocus of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_IsNeedKeyFocus00
static int tolua_GUI_GUI_Widget_IsNeedKeyFocus00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsNeedKeyFocus'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsNeedKeyFocus();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsNeedKeyFocus'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetNeedMouseFocus of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetNeedMouseFocus00
static int tolua_GUI_GUI_Widget_SetNeedMouseFocus00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetNeedMouseFocus'", NULL);
#endif
  {
   self->SetNeedMouseFocus(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetNeedMouseFocus'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsNeedMouseFocus of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_IsNeedMouseFocus00
static int tolua_GUI_GUI_Widget_IsNeedMouseFocus00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsNeedMouseFocus'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsNeedMouseFocus();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsNeedMouseFocus'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetInheritsPick of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetInheritsPick00
static int tolua_GUI_GUI_Widget_SetInheritsPick00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetInheritsPick'", NULL);
#endif
  {
   self->SetInheritsPick(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetInheritsPick'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInheritsPick of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_IsInheritsPick00
static int tolua_GUI_GUI_Widget_IsInheritsPick00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsInheritsPick'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsInheritsPick();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsInheritsPick'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaskPick of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetMaskPick00
static int tolua_GUI_GUI_Widget_SetMaskPick00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  const std::string filename = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaskPick'", NULL);
#endif
  {
   self->SetMaskPick(filename);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaskPick'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEnabled of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetEnabled00
static int tolua_GUI_GUI_Widget_SetEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEnabled'", NULL);
#endif
  {
   self->SetEnabled(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEnabledSilent of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetEnabledSilent00
static int tolua_GUI_GUI_Widget_SetEnabledSilent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEnabledSilent'", NULL);
#endif
  {
   self->SetEnabledSilent(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEnabledSilent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsEnabled of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_IsEnabled00
static int tolua_GUI_GUI_Widget_IsEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsEnabled'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsEnabled();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPointer of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetPointer00
static int tolua_GUI_GUI_Widget_SetPointer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPointer'", NULL);
#endif
  {
   self->SetPointer(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPointer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPointer of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_GetPointer00
static int tolua_GUI_GUI_Widget_GetPointer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPointer'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetPointer();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPointer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLayerName of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_GetLayerName00
static int tolua_GUI_GUI_Widget_GetLayerName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLayerName'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetLayerName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLayerName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetClientWidget of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_GetClientWidget00
static int tolua_GUI_GUI_Widget_GetClientWidget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetClientWidget'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->GetClientWidget();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetClientWidget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetNeedToolTip of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetNeedToolTip00
static int tolua_GUI_GUI_Widget_SetNeedToolTip00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetNeedToolTip'", NULL);
#endif
  {
   self->SetNeedToolTip(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetNeedToolTip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNeedToolTip of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_GetNeedToolTip00
static int tolua_GUI_GUI_Widget_GetNeedToolTip00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNeedToolTip'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetNeedToolTip();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNeedToolTip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEnableToolTip of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetEnableToolTip00
static int tolua_GUI_GUI_Widget_SetEnableToolTip00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEnableToolTip'", NULL);
#endif
  {
   self->SetEnableToolTip(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEnableToolTip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEnableToolTip of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_GetEnableToolTip00
static int tolua_GUI_GUI_Widget_GetEnableToolTip00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEnableToolTip'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetEnableToolTip();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEnableToolTip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DetachFromWidget of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_DetachFromWidget00
static int tolua_GUI_GUI_Widget_DetachFromWidget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DetachFromWidget'", NULL);
#endif
  {
   self->DetachFromWidget();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DetachFromWidget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DetachFromWidget of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_DetachFromWidget01
static int tolua_GUI_GUI_Widget_DetachFromWidget01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  const std::string layer = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DetachFromWidget'", NULL);
#endif
  {
   self->DetachFromWidget(layer);
  }
 }
 return 0;
tolua_lerror:
 return tolua_GUI_GUI_Widget_DetachFromWidget00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AttachToWidget of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_AttachToWidget00
static int tolua_GUI_GUI_Widget_AttachToWidget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::Widget",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GUI::WidgetStyle",1,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  GUI::Widget* parent = ((GUI::Widget*)  tolua_tousertype(tolua_S,2,0));
  GUI::WidgetStyle style = *((GUI::WidgetStyle*)  tolua_tousertype(tolua_S,3,(void*)&(const GUI::WidgetStyle)WidgetStyle::Child));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AttachToWidget'", NULL);
#endif
  {
   self->AttachToWidget(parent,style);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AttachToWidget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AttachToWidget of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_AttachToWidget01
static int tolua_GUI_GUI_Widget_AttachToWidget01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GUI::Widget",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GUI::WidgetStyle",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  GUI::Widget* parent = ((GUI::Widget*)  tolua_tousertype(tolua_S,2,0));
  GUI::WidgetStyle style = *((GUI::WidgetStyle*)  tolua_tousertype(tolua_S,3,0));
  const std::string layer = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AttachToWidget'", NULL);
#endif
  {
   self->AttachToWidget(parent,style,layer);
  }
 }
 return 0;
tolua_lerror:
 return tolua_GUI_GUI_Widget_AttachToWidget00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: ChangeWidgetSkin of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_ChangeWidgetSkin00
static int tolua_GUI_GUI_Widget_ChangeWidgetSkin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  const std::string skinname = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ChangeWidgetSkin'", NULL);
#endif
  {
   self->ChangeWidgetSkin(skinname);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ChangeWidgetSkin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWidgetStyle of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetWidgetStyle00
static int tolua_GUI_GUI_Widget_SetWidgetStyle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GUI::WidgetStyle",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  GUI::WidgetStyle style = *((GUI::WidgetStyle*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWidgetStyle'", NULL);
#endif
  {
   self->SetWidgetStyle(style);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWidgetStyle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWidgetStyle of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetWidgetStyle01
static int tolua_GUI_GUI_Widget_SetWidgetStyle01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GUI::WidgetStyle",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  GUI::WidgetStyle style = *((GUI::WidgetStyle*)  tolua_tousertype(tolua_S,2,0));
  const std::string layer = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWidgetStyle'", NULL);
#endif
  {
   self->SetWidgetStyle(style,layer);
  }
 }
 return 0;
tolua_lerror:
 return tolua_GUI_GUI_Widget_SetWidgetStyle00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWidgetStyle of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_GetWidgetStyle00
static int tolua_GUI_GUI_Widget_GetWidgetStyle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWidgetStyle'", NULL);
#endif
  {
   GUI::WidgetStyle tolua_ret = (GUI::WidgetStyle)  self->GetWidgetStyle();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::WidgetStyle)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::WidgetStyle");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::WidgetStyle));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::WidgetStyle");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWidgetStyle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetProperty of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetProperty00
static int tolua_GUI_GUI_Widget_SetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetProperty'", NULL);
#endif
  {
   self->SetProperty(key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCaptionWithNewLine of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetCaptionWithNewLine00
static int tolua_GUI_GUI_Widget_SetCaptionWithNewLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCaptionWithNewLine'", NULL);
#endif
  {
   self->SetCaptionWithNewLine(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCaptionWithNewLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTextCoord of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_GetTextCoord00
static int tolua_GUI_GUI_Widget_GetTextCoord00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTextCoord'", NULL);
#endif
  {
    TCoord<int> tolua_ret = (  TCoord<int>)  self->GetTextCoord();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((TCoord<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"TCoord<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TCoord<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"TCoord<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTextCoord'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTextSize of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_GetTextSize00
static int tolua_GUI_GUI_Widget_GetTextSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTextSize'", NULL);
#endif
  {
    TSize<int> tolua_ret = (  TSize<int>)  self->GetTextSize();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((TSize<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"TSize<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TSize<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"TSize<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTextSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFontName of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetFontName00
static int tolua_GUI_GUI_Widget_SetFontName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  const std::string font = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFontName'", NULL);
#endif
  {
   self->SetFontName(font);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFontName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFontName of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_GetFontName00
static int tolua_GUI_GUI_Widget_GetFontName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFontName'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetFontName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFontName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFontHeight of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetFontHeight00
static int tolua_GUI_GUI_Widget_SetFontHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  int height = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFontHeight'", NULL);
#endif
  {
   self->SetFontHeight(height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFontHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFontHeight of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_GetFontHeight00
static int tolua_GUI_GUI_Widget_GetFontHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFontHeight'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetFontHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFontHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTextAlign of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetTextAlign00
static int tolua_GUI_GUI_Widget_SetTextAlign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GUI::Align",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  GUI::Align align = *((GUI::Align*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTextAlign'", NULL);
#endif
  {
   self->SetTextAlign(align);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTextAlign'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTextAlign of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_GetTextAlign00
static int tolua_GUI_GUI_Widget_GetTextAlign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTextAlign'", NULL);
#endif
  {
   GUI::Align tolua_ret = (GUI::Align)  self->GetTextAlign();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::Align)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::Align");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::Align));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::Align");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTextAlign'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTextColour of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_SetTextColour00
static int tolua_GUI_GUI_Widget_SetTextColour00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::Colour",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
  const GUI::Colour* colour = ((const GUI::Colour*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTextColour'", NULL);
#endif
  {
   self->SetTextColour(*colour);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTextColour'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTextColour of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Widget_GetTextColour00
static int tolua_GUI_GUI_Widget_GetTextColour00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTextColour'", NULL);
#endif
  {
   const GUI::Colour& tolua_ret = (const GUI::Colour&)  self->GetTextColour();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const GUI::Colour");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTextColour'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __IObject__ of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_get_GUI__Widget___IObject__
static int tolua_get_GUI__Widget___IObject__(lua_State* tolua_S)
{
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__IObject__'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<IObject*>(self), "IObject");
#else
   tolua_pushusertype(tolua_S,(void*)((IObject*)self), "IObject");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __ICroppedRectangle__ of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_get_GUI__Widget___ICroppedRectangle__
static int tolua_get_GUI__Widget___ICroppedRectangle__(lua_State* tolua_S)
{
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__ICroppedRectangle__'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<ICroppedRectangle*>(self), "ICroppedRectangle");
#else
   tolua_pushusertype(tolua_S,(void*)((ICroppedRectangle*)self), "ICroppedRectangle");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __LayerItem__ of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_get_GUI__Widget___LayerItem__
static int tolua_get_GUI__Widget___LayerItem__(lua_State* tolua_S)
{
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__LayerItem__'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<LayerItem*>(self), "LayerItem");
#else
   tolua_pushusertype(tolua_S,(void*)((LayerItem*)self), "LayerItem");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __UserData__ of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_get_GUI__Widget___UserData__
static int tolua_get_GUI__Widget___UserData__(lua_State* tolua_S)
{
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__UserData__'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<GUI::UserData*>(self), "GUI::UserData");
#else
   tolua_pushusertype(tolua_S,(void*)((GUI::UserData*)self), "GUI::UserData");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __IWidgetCreator__ of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_get_GUI__Widget___IWidgetCreator__
static int tolua_get_GUI__Widget___IWidgetCreator__(lua_State* tolua_S)
{
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__IWidgetCreator__'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<IWidgetCreator*>(self), "IWidgetCreator");
#else
   tolua_pushusertype(tolua_S,(void*)((IWidgetCreator*)self), "IWidgetCreator");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __delegates of class  GUI::Widget */
#ifndef TOLUA_DISABLE_tolua_get_GUI__Widget___delegates__IDelegateUnlink__
static int tolua_get_GUI__Widget___delegates__IDelegateUnlink__(lua_State* tolua_S)
{
  GUI::Widget* self = (GUI::Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__delegates'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<delegates::IDelegateUnlink*>(self), "delegates::IDelegateUnlink");
#else
   tolua_pushusertype(tolua_S,(void*)((delegates::IDelegateUnlink*)self), "delegates::IDelegateUnlink");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: Size of class  GUI::VectorWidgetPtr */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_VectorWidgetPtr_Size00
static int tolua_GUI_GUI_VectorWidgetPtr_Size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::VectorWidgetPtr",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::VectorWidgetPtr* self = (const GUI::VectorWidgetPtr*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Size'", NULL);
#endif
  {
    int tolua_ret = (  int)  self->Size();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator&[] of class  GUI::VectorWidgetPtr */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_VectorWidgetPtr__seti00
static int tolua_GUI_GUI_VectorWidgetPtr__seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::VectorWidgetPtr",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"GUI::Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::VectorWidgetPtr* self = (GUI::VectorWidgetPtr*)  tolua_tousertype(tolua_S,1,0);
   int Pos = ((  int)  tolua_tonumber(tolua_S,2,0));
  GUI::Widget* tolua_value = ((GUI::Widget*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'", NULL);
#endif
  self->operator[](Pos) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator[] of class  GUI::VectorWidgetPtr */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_VectorWidgetPtr__geti00
static int tolua_GUI_GUI_VectorWidgetPtr__geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::VectorWidgetPtr",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::VectorWidgetPtr* self = (GUI::VectorWidgetPtr*)  tolua_tousertype(tolua_S,1,0);
   int Pos = ((  int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->operator[](Pos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Resize of class  GUI::VectorWidgetPtr */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_VectorWidgetPtr_Resize00
static int tolua_GUI_GUI_VectorWidgetPtr_Resize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::VectorWidgetPtr",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::VectorWidgetPtr* self = (GUI::VectorWidgetPtr*)  tolua_tousertype(tolua_S,1,0);
   int Newsize = ((  int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Resize'", NULL);
#endif
  {
   self->Resize(Newsize);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Resize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Reserve of class  GUI::VectorWidgetPtr */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_VectorWidgetPtr_Reserve00
static int tolua_GUI_GUI_VectorWidgetPtr_Reserve00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::VectorWidgetPtr",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::VectorWidgetPtr* self = (GUI::VectorWidgetPtr*)  tolua_tousertype(tolua_S,1,0);
   int Count = ((  int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Reserve'", NULL);
#endif
  {
   self->Reserve(Count);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Reserve'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  GUI::VectorWidgetPtr */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_VectorWidgetPtr_Clear00
static int tolua_GUI_GUI_VectorWidgetPtr_Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::VectorWidgetPtr",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::VectorWidgetPtr* self = (GUI::VectorWidgetPtr*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'", NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Parse of class  GUI::WidgetStyle */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_WidgetStyle_Parse00
static int tolua_GUI_GUI_WidgetStyle_Parse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::WidgetStyle",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   GUI::WidgetStyle tolua_ret = (GUI::WidgetStyle)  GUI::WidgetStyle::Parse(value);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GUI::WidgetStyle)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::WidgetStyle");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GUI::WidgetStyle));
     tolua_pushusertype(tolua_S,tolua_obj,"GUI::WidgetStyle");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Parse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GUI::WidgetStyle */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_WidgetStyle_new00
static int tolua_GUI_GUI_WidgetStyle_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::WidgetStyle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GUI::WidgetStyle* tolua_ret = (GUI::WidgetStyle*)  Mtolua_new((GUI::WidgetStyle)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::WidgetStyle");
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

/* method: new_local of class  GUI::WidgetStyle */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_WidgetStyle_new00_local
static int tolua_GUI_GUI_WidgetStyle_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::WidgetStyle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GUI::WidgetStyle* tolua_ret = (GUI::WidgetStyle*)  Mtolua_new((GUI::WidgetStyle)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::WidgetStyle");
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

/* method: new of class  GUI::WidgetStyle */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_WidgetStyle_new01
static int tolua_GUI_GUI_WidgetStyle_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::WidgetStyle",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::WidgetStyle::Enum value = ((GUI::WidgetStyle::Enum) (int)  tolua_tonumber(tolua_S,2,0));
  {
   GUI::WidgetStyle* tolua_ret = (GUI::WidgetStyle*)  Mtolua_new((GUI::WidgetStyle)(value));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::WidgetStyle");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_WidgetStyle_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  GUI::WidgetStyle */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_WidgetStyle_new01_local
static int tolua_GUI_GUI_WidgetStyle_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GUI::WidgetStyle",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GUI::WidgetStyle::Enum value = ((GUI::WidgetStyle::Enum) (int)  tolua_tonumber(tolua_S,2,0));
  {
   GUI::WidgetStyle* tolua_ret = (GUI::WidgetStyle*)  Mtolua_new((GUI::WidgetStyle)(value));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::WidgetStyle");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_GUI_GUI_WidgetStyle_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Print of class  GUI::WidgetStyle */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_WidgetStyle_Print00
static int tolua_GUI_GUI_WidgetStyle_Print00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GUI::WidgetStyle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GUI::WidgetStyle* self = (const GUI::WidgetStyle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Print'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->Print();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Print'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUserString of class  GUI::UserData */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UserData_SetUserString00
static int tolua_GUI_GUI_UserData_SetUserString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::UserData",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::UserData* self = (GUI::UserData*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUserString'", NULL);
#endif
  {
   self->SetUserString(key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUserString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUserString of class  GUI::UserData */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UserData_GetUserString00
static int tolua_GUI_GUI_UserData_GetUserString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::UserData",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::UserData* self = (GUI::UserData*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUserString'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetUserString(key);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUserString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearUserString of class  GUI::UserData */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UserData_ClearUserString00
static int tolua_GUI_GUI_UserData_ClearUserString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::UserData",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::UserData* self = (GUI::UserData*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearUserString'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->ClearUserString(key);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearUserString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsUserString of class  GUI::UserData */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UserData_IsUserString00
static int tolua_GUI_GUI_UserData_IsUserString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::UserData",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::UserData* self = (GUI::UserData*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsUserString'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsUserString(key);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsUserString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearUserStrings of class  GUI::UserData */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_UserData_ClearUserStrings00
static int tolua_GUI_GUI_UserData_ClearUserStrings00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::UserData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::UserData* self = (GUI::UserData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearUserStrings'", NULL);
#endif
  {
   self->ClearUserStrings();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearUserStrings'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVisible of class  GUI::Window */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Window_SetVisible00
static int tolua_GUI_GUI_Window_SetVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Window",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Window* self = (GUI::Window*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVisible'", NULL);
#endif
  {
   self->SetVisible(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVisibleSmooth of class  GUI::Window */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Window_SetVisibleSmooth00
static int tolua_GUI_GUI_Window_SetVisibleSmooth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Window",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Window* self = (GUI::Window*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVisibleSmooth'", NULL);
#endif
  {
   self->SetVisibleSmooth(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVisibleSmooth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DestroySmooth of class  GUI::Window */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Window_DestroySmooth00
static int tolua_GUI_GUI_Window_DestroySmooth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Window* self = (GUI::Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DestroySmooth'", NULL);
#endif
  {
   self->DestroySmooth();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DestroySmooth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAutoAlpha of class  GUI::Window */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Window_SetAutoAlpha00
static int tolua_GUI_GUI_Window_SetAutoAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Window",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Window* self = (GUI::Window*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAutoAlpha'", NULL);
#endif
  {
   self->SetAutoAlpha(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAutoAlpha'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAutoAlpha of class  GUI::Window */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Window_GetAutoAlpha00
static int tolua_GUI_GUI_Window_GetAutoAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Window* self = (GUI::Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAutoAlpha'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetAutoAlpha();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAutoAlpha'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCaption of class  GUI::Window */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Window_SetCaption00
static int tolua_GUI_GUI_Window_SetCaption00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Window",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const GUI::UString",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Window* self = (GUI::Window*)  tolua_tousertype(tolua_S,1,0);
  const GUI::UString* value = ((const GUI::UString*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCaption'", NULL);
#endif
  {
   self->SetCaption(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCaption'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCaption of class  GUI::Window */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Window_GetCaption00
static int tolua_GUI_GUI_Window_GetCaption00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Window* self = (GUI::Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCaption'", NULL);
#endif
  {
   const GUI::UString& tolua_ret = (const GUI::UString&)  self->GetCaption();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const GUI::UString");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCaption'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCaptionWidget of class  GUI::Window */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Window_GetCaptionWidget00
static int tolua_GUI_GUI_Window_GetCaptionWidget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Window* self = (GUI::Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCaptionWidget'", NULL);
#endif
  {
   GUI::Widget* tolua_ret = (GUI::Widget*)  self->GetCaptionWidget();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GUI::Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCaptionWidget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMinSize of class  GUI::Window */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Window_SetMinSize00
static int tolua_GUI_GUI_Window_SetMinSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Window",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Window* self = (GUI::Window*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMinSize'", NULL);
#endif
  {
   self->SetMinSize(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMinSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMinSize of class  GUI::Window */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Window_GetMinSize00
static int tolua_GUI_GUI_Window_GetMinSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Window* self = (GUI::Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMinSize'", NULL);
#endif
  {
    TSize<int> tolua_ret = (  TSize<int>)  self->GetMinSize();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((TSize<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"TSize<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TSize<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"TSize<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMinSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxSize of class  GUI::Window */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Window_SetMaxSize00
static int tolua_GUI_GUI_Window_SetMaxSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Window",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Window* self = (GUI::Window*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxSize'", NULL);
#endif
  {
   self->SetMaxSize(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxSize of class  GUI::Window */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Window_GetMaxSize00
static int tolua_GUI_GUI_Window_GetMaxSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Window* self = (GUI::Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxSize'", NULL);
#endif
  {
    TSize<int> tolua_ret = (  TSize<int>)  self->GetMaxSize();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((TSize<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"TSize<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TSize<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"TSize<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  GUI::Window */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Window_SetPosition00
static int tolua_GUI_GUI_Window_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Window",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Window* self = (GUI::Window*)  tolua_tousertype(tolua_S,1,0);
  int left = ((int)  tolua_tonumber(tolua_S,2,0));
  int top = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
  {
   self->SetPosition(left,top);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSize of class  GUI::Window */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Window_SetSize00
static int tolua_GUI_GUI_Window_SetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Window",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Window* self = (GUI::Window*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSize'", NULL);
#endif
  {
   self->SetSize(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCoord of class  GUI::Window */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Window_SetCoord00
static int tolua_GUI_GUI_Window_SetCoord00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Window",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Window* self = (GUI::Window*)  tolua_tousertype(tolua_S,1,0);
  int left = ((int)  tolua_tonumber(tolua_S,2,0));
  int top = ((int)  tolua_tonumber(tolua_S,3,0));
  int width = ((int)  tolua_tonumber(tolua_S,4,0));
  int height = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCoord'", NULL);
#endif
  {
   self->SetCoord(left,top,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCoord'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSnap of class  GUI::Window */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Window_GetSnap00
static int tolua_GUI_GUI_Window_GetSnap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Window* self = (GUI::Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSnap'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetSnap();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSnap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSnap of class  GUI::Window */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Window_SetSnap00
static int tolua_GUI_GUI_Window_SetSnap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Window",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Window* self = (GUI::Window*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSnap'", NULL);
#endif
  {
   self->SetSnap(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSnap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetProperty of class  GUI::Window */
#ifndef TOLUA_DISABLE_tolua_GUI_GUI_Window_SetProperty00
static int tolua_GUI_GUI_Window_SetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GUI::Window",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GUI::Window* self = (GUI::Window*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetProperty'", NULL);
#endif
  {
   self->SetProperty(key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_GUI_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Align","GUI::Align","",tolua_collect_GUI__Align);
   #else
   tolua_cclass(tolua_S,"Align","GUI::Align","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Align");
    tolua_constant(tolua_S,"HCenter",GUI::Align::HCenter);
    tolua_constant(tolua_S,"VCenter",GUI::Align::VCenter);
    tolua_constant(tolua_S,"Center",GUI::Align::Center);
    tolua_constant(tolua_S,"Left",GUI::Align::Left);
    tolua_constant(tolua_S,"Right",GUI::Align::Right);
    tolua_constant(tolua_S,"HStretch",GUI::Align::HStretch);
    tolua_constant(tolua_S,"Top",GUI::Align::Top);
    tolua_constant(tolua_S,"Bottom",GUI::Align::Bottom);
    tolua_constant(tolua_S,"VStretch",GUI::Align::VStretch);
    tolua_constant(tolua_S,"Stretch",GUI::Align::Stretch);
    tolua_constant(tolua_S,"Default",GUI::Align::Default);
    tolua_constant(tolua_S,"HRelative",GUI::Align::HRelative);
    tolua_constant(tolua_S,"VRelative",GUI::Align::VRelative);
    tolua_constant(tolua_S,"Relative",GUI::Align::Relative);
    tolua_function(tolua_S,"new",tolua_GUI_GUI_Align_new00);
    tolua_function(tolua_S,"new_local",tolua_GUI_GUI_Align_new00_local);
    tolua_function(tolua_S,".call",tolua_GUI_GUI_Align_new00_local);
    tolua_function(tolua_S,"IsHCenter",tolua_GUI_GUI_Align_IsHCenter00);
    tolua_function(tolua_S,"IsVCenter",tolua_GUI_GUI_Align_IsVCenter00);
    tolua_function(tolua_S,"IsCenter",tolua_GUI_GUI_Align_IsCenter00);
    tolua_function(tolua_S,"IsLeft",tolua_GUI_GUI_Align_IsLeft00);
    tolua_function(tolua_S,"IsRight",tolua_GUI_GUI_Align_IsRight00);
    tolua_function(tolua_S,"IsHStretch",tolua_GUI_GUI_Align_IsHStretch00);
    tolua_function(tolua_S,"IsTop",tolua_GUI_GUI_Align_IsTop00);
    tolua_function(tolua_S,"IsBottom",tolua_GUI_GUI_Align_IsBottom00);
    tolua_function(tolua_S,"IsVStretch",tolua_GUI_GUI_Align_IsVStretch00);
    tolua_function(tolua_S,"IsStretch",tolua_GUI_GUI_Align_IsStretch00);
    tolua_function(tolua_S,"IsDefault",tolua_GUI_GUI_Align_IsDefault00);
    tolua_function(tolua_S,"IsHRelative",tolua_GUI_GUI_Align_IsHRelative00);
    tolua_function(tolua_S,"IsVRelative",tolua_GUI_GUI_Align_IsVRelative00);
    tolua_function(tolua_S,"IsRelative",tolua_GUI_GUI_Align_IsRelative00);
    tolua_function(tolua_S,"Parse",tolua_GUI_GUI_Align_Parse00);
    tolua_function(tolua_S,"Print",tolua_GUI_GUI_Align_Print00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"Button","GUI::Button","GUI::StaticText",NULL);
   tolua_beginmodule(tolua_S,"Button");
    tolua_function(tolua_S,"SetButtonPressed",tolua_GUI_GUI_Button_SetButtonPressed00);
    tolua_function(tolua_S,"GetButtonPressed",tolua_GUI_GUI_Button_GetButtonPressed00);
    tolua_function(tolua_S,"SetStateCheck",tolua_GUI_GUI_Button_SetStateCheck00);
    tolua_function(tolua_S,"GetStateCheck",tolua_GUI_GUI_Button_GetStateCheck00);
    tolua_function(tolua_S,"SetImageIndex",tolua_GUI_GUI_Button_SetImageIndex00);
    tolua_function(tolua_S,"GetImageIndex",tolua_GUI_GUI_Button_GetImageIndex00);
    tolua_function(tolua_S,"SetModeImage",tolua_GUI_GUI_Button_SetModeImage00);
    tolua_function(tolua_S,"GetModeImage",tolua_GUI_GUI_Button_GetModeImage00);
    tolua_function(tolua_S,"GetStaticImage",tolua_GUI_GUI_Button_GetStaticImage00);
    tolua_function(tolua_S,"SetProperty",tolua_GUI_GUI_Button_SetProperty00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"ClipboardManager","GUI::ClipboardManager","",NULL);
   tolua_beginmodule(tolua_S,"ClipboardManager");
    tolua_function(tolua_S,"Instance",tolua_GUI_GUI_ClipboardManager_Instance00);
    tolua_function(tolua_S,"SetClipboardData",tolua_GUI_GUI_ClipboardManager_SetClipboardData00);
    tolua_function(tolua_S,"ClearClipboardData",tolua_GUI_GUI_ClipboardManager_ClearClipboardData00);
    tolua_function(tolua_S,"GetClipboardData",tolua_GUI_GUI_ClipboardManager_GetClipboardData00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Colour","GUI::Colour","",tolua_collect_GUI__Colour);
   #else
   tolua_cclass(tolua_S,"Colour","GUI::Colour","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Colour");
    tolua_variable(tolua_S,"red",tolua_get_GUI__Colour_red,tolua_set_GUI__Colour_red);
    tolua_variable(tolua_S,"green",tolua_get_GUI__Colour_green,tolua_set_GUI__Colour_green);
    tolua_variable(tolua_S,"blue",tolua_get_GUI__Colour_blue,tolua_set_GUI__Colour_blue);
    tolua_variable(tolua_S,"alpha",tolua_get_GUI__Colour_alpha,tolua_set_GUI__Colour_alpha);
    tolua_variable(tolua_S,"Zero",tolua_get_GUI__Colour_Zero,NULL);
    tolua_variable(tolua_S,"Black",tolua_get_GUI__Colour_Black,NULL);
    tolua_variable(tolua_S,"White",tolua_get_GUI__Colour_White,NULL);
    tolua_variable(tolua_S,"Red",tolua_get_GUI__Colour_Red,NULL);
    tolua_variable(tolua_S,"Green",tolua_get_GUI__Colour_Green,NULL);
    tolua_variable(tolua_S,"Blue",tolua_get_GUI__Colour_Blue,NULL);
    tolua_function(tolua_S,"new",tolua_GUI_GUI_Colour_new00);
    tolua_function(tolua_S,"new_local",tolua_GUI_GUI_Colour_new00_local);
    tolua_function(tolua_S,".call",tolua_GUI_GUI_Colour_new00_local);
    tolua_function(tolua_S,"new",tolua_GUI_GUI_Colour_new01);
    tolua_function(tolua_S,"new_local",tolua_GUI_GUI_Colour_new01_local);
    tolua_function(tolua_S,".call",tolua_GUI_GUI_Colour_new01_local);
    tolua_function(tolua_S,"new",tolua_GUI_GUI_Colour_new02);
    tolua_function(tolua_S,"new_local",tolua_GUI_GUI_Colour_new02_local);
    tolua_function(tolua_S,".call",tolua_GUI_GUI_Colour_new02_local);
    tolua_function(tolua_S,".eq",tolua_GUI_GUI_Colour__eq00);
    tolua_function(tolua_S,"Set",tolua_GUI_GUI_Colour_Set00);
    tolua_function(tolua_S,"Clear",tolua_GUI_GUI_Colour_Clear00);
    tolua_function(tolua_S,"Print",tolua_GUI_GUI_Colour_Print00);
    tolua_function(tolua_S,"Parse",tolua_GUI_GUI_Colour_Parse00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"ComboBox","GUI::ComboBox","GUI::Edit",NULL);
   tolua_beginmodule(tolua_S,"ComboBox");
    tolua_function(tolua_S,"GetItemCount",tolua_GUI_GUI_ComboBox_GetItemCount00);
    tolua_function(tolua_S,"InsertItem",tolua_GUI_GUI_ComboBox_InsertItem00);
    tolua_function(tolua_S,"AppendItem",tolua_GUI_GUI_ComboBox_AppendItem00);
    tolua_function(tolua_S,"RemoveItem",tolua_GUI_GUI_ComboBox_RemoveItem00);
    tolua_function(tolua_S,"RemoveAllItems",tolua_GUI_GUI_ComboBox_RemoveAllItems00);
    tolua_function(tolua_S,"FindItemIndexWith",tolua_GUI_GUI_ComboBox_FindItemIndexWith00);
    tolua_function(tolua_S,"GetIndexSelected",tolua_GUI_GUI_ComboBox_GetIndexSelected00);
    tolua_function(tolua_S,"SetIndexSelected",tolua_GUI_GUI_ComboBox_SetIndexSelected00);
    tolua_function(tolua_S,"ClearIndexSelected",tolua_GUI_GUI_ComboBox_ClearIndexSelected00);
    tolua_function(tolua_S,"SetItemData",tolua_GUI_GUI_ComboBox_SetItemData00);
    tolua_function(tolua_S,"ClearItemData",tolua_GUI_GUI_ComboBox_ClearItemData00);
    tolua_function(tolua_S,"GetItemData",tolua_GUI_GUI_ComboBox_GetItemData00);
    tolua_function(tolua_S,"SetItemName",tolua_GUI_GUI_ComboBox_SetItemName00);
    tolua_function(tolua_S,"GetItemName",tolua_GUI_GUI_ComboBox_GetItemName00);
    tolua_function(tolua_S,"BeginToItem",tolua_GUI_GUI_ComboBox_BeginToItem00);
    tolua_function(tolua_S,"BeginToItemFirst",tolua_GUI_GUI_ComboBox_BeginToItemFirst00);
    tolua_function(tolua_S,"BeginToItemLast",tolua_GUI_GUI_ComboBox_BeginToItemLast00);
    tolua_function(tolua_S,"BeginToItemSelected",tolua_GUI_GUI_ComboBox_BeginToItemSelected00);
    tolua_function(tolua_S,"SetComboModeDrop",tolua_GUI_GUI_ComboBox_SetComboModeDrop00);
    tolua_function(tolua_S,"GetComboModeDrop",tolua_GUI_GUI_ComboBox_GetComboModeDrop00);
    tolua_function(tolua_S,"SetSmoothShow",tolua_GUI_GUI_ComboBox_SetSmoothShow00);
    tolua_function(tolua_S,"GetSmoothShow",tolua_GUI_GUI_ComboBox_GetSmoothShow00);
    tolua_function(tolua_S,"SetMaxListHeight",tolua_GUI_GUI_ComboBox_SetMaxListHeight00);
    tolua_function(tolua_S,"GetMaxListHeight",tolua_GUI_GUI_ComboBox_GetMaxListHeight00);
    tolua_function(tolua_S,"SetProperty",tolua_GUI_GUI_ComboBox_SetProperty00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"Edit","GUI::Edit","GUI::StaticText",NULL);
   tolua_beginmodule(tolua_S,"Edit");
    tolua_function(tolua_S,"SetTextIntervalColour",tolua_GUI_GUI_Edit_SetTextIntervalColour00);
    tolua_function(tolua_S,"GetTextSelectionStart",tolua_GUI_GUI_Edit_GetTextSelectionStart00);
    tolua_function(tolua_S,"GetTextSelectionEnd",tolua_GUI_GUI_Edit_GetTextSelectionEnd00);
    tolua_function(tolua_S,"GetTextSelectionLength",tolua_GUI_GUI_Edit_GetTextSelectionLength00);
    tolua_function(tolua_S,"GetTextInterval",tolua_GUI_GUI_Edit_GetTextInterval00);
    tolua_function(tolua_S,"SetTextSelection",tolua_GUI_GUI_Edit_SetTextSelection00);
    tolua_function(tolua_S,"DeleteTextSelection",tolua_GUI_GUI_Edit_DeleteTextSelection00);
    tolua_function(tolua_S,"GetTextSelection",tolua_GUI_GUI_Edit_GetTextSelection00);
    tolua_function(tolua_S,"IsTextSelection",tolua_GUI_GUI_Edit_IsTextSelection00);
    tolua_function(tolua_S,"SetTextSelectionColour",tolua_GUI_GUI_Edit_SetTextSelectionColour00);
    tolua_function(tolua_S,"SetTextCursor",tolua_GUI_GUI_Edit_SetTextCursor00);
    tolua_function(tolua_S,"GetTextCursor",tolua_GUI_GUI_Edit_GetTextCursor00);
    tolua_function(tolua_S,"SetCaption",tolua_GUI_GUI_Edit_SetCaption00);
    tolua_function(tolua_S,"GetCaption",tolua_GUI_GUI_Edit_GetCaption00);
    tolua_function(tolua_S,"SetOnlyText",tolua_GUI_GUI_Edit_SetOnlyText00);
    tolua_function(tolua_S,"GetOnlyText",tolua_GUI_GUI_Edit_GetOnlyText00);
    tolua_function(tolua_S,"GetTextLength",tolua_GUI_GUI_Edit_GetTextLength00);
    tolua_function(tolua_S,"SetOverflowToTheLeft",tolua_GUI_GUI_Edit_SetOverflowToTheLeft00);
    tolua_function(tolua_S,"GetOverflowToTheLeft",tolua_GUI_GUI_Edit_GetOverflowToTheLeft00);
    tolua_function(tolua_S,"SetMaxTextLength",tolua_GUI_GUI_Edit_SetMaxTextLength00);
    tolua_function(tolua_S,"GetMaxTextLength",tolua_GUI_GUI_Edit_GetMaxTextLength00);
    tolua_function(tolua_S,"InsertText",tolua_GUI_GUI_Edit_InsertText00);
    tolua_function(tolua_S,"AddText",tolua_GUI_GUI_Edit_AddText00);
    tolua_function(tolua_S,"eraseText",tolua_GUI_GUI_Edit_eraseText00);
    tolua_function(tolua_S,"SetEditReadOnly",tolua_GUI_GUI_Edit_SetEditReadOnly00);
    tolua_function(tolua_S,"GetEditReadOnly",tolua_GUI_GUI_Edit_GetEditReadOnly00);
    tolua_function(tolua_S,"SetEditPassword",tolua_GUI_GUI_Edit_SetEditPassword00);
    tolua_function(tolua_S,"GetEditPassword",tolua_GUI_GUI_Edit_GetEditPassword00);
    tolua_function(tolua_S,"SetEditMultiLine",tolua_GUI_GUI_Edit_SetEditMultiLine00);
    tolua_function(tolua_S,"GetEditMultiLine",tolua_GUI_GUI_Edit_GetEditMultiLine00);
    tolua_function(tolua_S,"SetEditStatic",tolua_GUI_GUI_Edit_SetEditStatic00);
    tolua_function(tolua_S,"GetEditStatic",tolua_GUI_GUI_Edit_GetEditStatic00);
    tolua_function(tolua_S,"SetPasswordChar",tolua_GUI_GUI_Edit_SetPasswordChar00);
    tolua_function(tolua_S,"SetPasswordChar",tolua_GUI_GUI_Edit_SetPasswordChar01);
    tolua_function(tolua_S,"GetPasswordChar",tolua_GUI_GUI_Edit_GetPasswordChar00);
    tolua_function(tolua_S,"SetEditWordWrap",tolua_GUI_GUI_Edit_SetEditWordWrap00);
    tolua_function(tolua_S,"GetEditWordWrap",tolua_GUI_GUI_Edit_GetEditWordWrap00);
    tolua_function(tolua_S,"SetTabPrinting",tolua_GUI_GUI_Edit_SetTabPrinting00);
    tolua_function(tolua_S,"GetTabPrinting",tolua_GUI_GUI_Edit_GetTabPrinting00);
    tolua_function(tolua_S,"GetInvertSelected",tolua_GUI_GUI_Edit_GetInvertSelected00);
    tolua_function(tolua_S,"SetInvertSelected",tolua_GUI_GUI_Edit_SetInvertSelected00);
    tolua_function(tolua_S,"SetPosition",tolua_GUI_GUI_Edit_SetPosition00);
    tolua_function(tolua_S,"SetSize",tolua_GUI_GUI_Edit_SetSize00);
    tolua_function(tolua_S,"SetCoord",tolua_GUI_GUI_Edit_SetCoord00);
    tolua_function(tolua_S,"SetVisibleVScroll",tolua_GUI_GUI_Edit_SetVisibleVScroll00);
    tolua_function(tolua_S,"IsVisibleVScroll",tolua_GUI_GUI_Edit_IsVisibleVScroll00);
    tolua_function(tolua_S,"GetVScrollRange",tolua_GUI_GUI_Edit_GetVScrollRange00);
    tolua_function(tolua_S,"GetVScrollPosition",tolua_GUI_GUI_Edit_GetVScrollPosition00);
    tolua_function(tolua_S,"SetVScrollPosition",tolua_GUI_GUI_Edit_SetVScrollPosition00);
    tolua_function(tolua_S,"SetVisibleHScroll",tolua_GUI_GUI_Edit_SetVisibleHScroll00);
    tolua_function(tolua_S,"IsVisibleHScroll",tolua_GUI_GUI_Edit_IsVisibleHScroll00);
    tolua_function(tolua_S,"GetHScrollRange",tolua_GUI_GUI_Edit_GetHScrollRange00);
    tolua_function(tolua_S,"GetHScrollPosition",tolua_GUI_GUI_Edit_GetHScrollPosition00);
    tolua_function(tolua_S,"SetHScrollPosition",tolua_GUI_GUI_Edit_SetHScrollPosition00);
    tolua_function(tolua_S,"SetFontName",tolua_GUI_GUI_Edit_SetFontName00);
    tolua_function(tolua_S,"SetFontHeight",tolua_GUI_GUI_Edit_SetFontHeight00);
    tolua_function(tolua_S,"SetTextAlign",tolua_GUI_GUI_Edit_SetTextAlign00);
    tolua_function(tolua_S,"SetProperty",tolua_GUI_GUI_Edit_SetProperty00);
    tolua_variable(tolua_S,"__ScrollViewBase__",tolua_get_GUI__Edit___ScrollViewBase__,NULL);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"Gui","GUI::Gui","IWidgetCreator",NULL);
   tolua_beginmodule(tolua_S,"Gui");
    tolua_function(tolua_S,"Instance",tolua_GUI_GUI_Gui_Instance00);
    tolua_function(tolua_S,"CreateWidgetT",tolua_GUI_GUI_Gui_CreateWidgetT00);
    tolua_function(tolua_S,"CreateWidgetT",tolua_GUI_GUI_Gui_CreateWidgetT01);
    tolua_function(tolua_S,"CreateWidgetT",tolua_GUI_GUI_Gui_CreateWidgetT02);
    tolua_function(tolua_S,"CreateWidgetT",tolua_GUI_GUI_Gui_CreateWidgetT03);
    tolua_function(tolua_S,"CreateWidgetRealT",tolua_GUI_GUI_Gui_CreateWidgetRealT00);
    tolua_function(tolua_S,"CreateWidgetRealT",tolua_GUI_GUI_Gui_CreateWidgetRealT01);
    tolua_function(tolua_S,"CreateWidgetRealT",tolua_GUI_GUI_Gui_CreateWidgetRealT02);
    tolua_function(tolua_S,"CreateWidgetRealT",tolua_GUI_GUI_Gui_CreateWidgetRealT03);
    tolua_function(tolua_S,"GetViewSize",tolua_GUI_GUI_Gui_GetViewSize00);
    tolua_function(tolua_S,"GetViewWidth",tolua_GUI_GUI_Gui_GetViewWidth00);
    tolua_function(tolua_S,"GetViewHeight",tolua_GUI_GUI_Gui_GetViewHeight00);
    tolua_function(tolua_S,"DestroyWidget",tolua_GUI_GUI_Gui_DestroyWidget00);
    tolua_function(tolua_S,"findWidgetT",tolua_GUI_GUI_Gui_findWidgetT00);
    tolua_function(tolua_S,"SetVisiblePointer",tolua_GUI_GUI_Gui_SetVisiblePointer00);
    tolua_function(tolua_S,"IsVisiblePointer",tolua_GUI_GUI_Gui_IsVisiblePointer00);
    tolua_function(tolua_S,"Load",tolua_GUI_GUI_Gui_Load00);
    tolua_function(tolua_S,"ResizeWindow",tolua_GUI_GUI_Gui_ResizeWindow00);
    tolua_function(tolua_S,"DestroyChildWidget",tolua_GUI_GUI_Gui_DestroyChildWidget00);
    tolua_function(tolua_S,"DestroyAllChildWidget",tolua_GUI_GUI_Gui_DestroyAllChildWidget00);
    tolua_variable(tolua_S,"__IUnlinkWidget__",tolua_get_GUI__Gui___IUnlinkWidget__,NULL);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"HScroll","GUI::HScroll","GUI::VScroll",NULL);
   tolua_beginmodule(tolua_S,"HScroll");
    tolua_function(tolua_S,"GetLineSize",tolua_GUI_GUI_HScroll_GetLineSize00);
    tolua_function(tolua_S,"SetTrackSize",tolua_GUI_GUI_HScroll_SetTrackSize00);
    tolua_function(tolua_S,"GetTrackSize",tolua_GUI_GUI_HScroll_GetTrackSize00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"MouseButton","GUI::MouseButton","",tolua_collect_GUI__MouseButton);
   #else
   tolua_cclass(tolua_S,"MouseButton","GUI::MouseButton","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"MouseButton");
    tolua_constant(tolua_S,"Left",GUI::MouseButton::Left);
    tolua_constant(tolua_S,"Right",GUI::MouseButton::Right);
    tolua_constant(tolua_S,"Middle",GUI::MouseButton::Middle);
    tolua_constant(tolua_S,"Button0",GUI::MouseButton::Button0);
    tolua_constant(tolua_S,"Button1",GUI::MouseButton::Button1);
    tolua_constant(tolua_S,"Button2",GUI::MouseButton::Button2);
    tolua_constant(tolua_S,"Button3",GUI::MouseButton::Button3);
    tolua_constant(tolua_S,"Button4",GUI::MouseButton::Button4);
    tolua_constant(tolua_S,"Button5",GUI::MouseButton::Button5);
    tolua_constant(tolua_S,"Button6",GUI::MouseButton::Button6);
    tolua_constant(tolua_S,"Button7",GUI::MouseButton::Button7);
    tolua_constant(tolua_S,"None",GUI::MouseButton::None);
    tolua_function(tolua_S,"new",tolua_GUI_GUI_MouseButton_new00);
    tolua_function(tolua_S,"new_local",tolua_GUI_GUI_MouseButton_new00_local);
    tolua_function(tolua_S,".call",tolua_GUI_GUI_MouseButton_new00_local);
    tolua_function(tolua_S,".eq",tolua_GUI_GUI_MouseButton__eq00);
    tolua_function(tolua_S,"ToValue",tolua_GUI_GUI_MouseButton_ToValue00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"KeyCode","GUI::KeyCode","",tolua_collect_GUI__KeyCode);
   #else
   tolua_cclass(tolua_S,"KeyCode","GUI::KeyCode","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"KeyCode");
    tolua_constant(tolua_S,"None",GUI::KeyCode::None);
    tolua_constant(tolua_S,"Escape",GUI::KeyCode::Escape);
    tolua_constant(tolua_S,"One",GUI::KeyCode::One);
    tolua_constant(tolua_S,"Two",GUI::KeyCode::Two);
    tolua_constant(tolua_S,"Three",GUI::KeyCode::Three);
    tolua_constant(tolua_S,"Four",GUI::KeyCode::Four);
    tolua_constant(tolua_S,"Five",GUI::KeyCode::Five);
    tolua_constant(tolua_S,"Six",GUI::KeyCode::Six);
    tolua_constant(tolua_S,"Seven",GUI::KeyCode::Seven);
    tolua_constant(tolua_S,"Eight",GUI::KeyCode::Eight);
    tolua_constant(tolua_S,"Nine",GUI::KeyCode::Nine);
    tolua_constant(tolua_S,"Zero",GUI::KeyCode::Zero);
    tolua_constant(tolua_S,"Minus",GUI::KeyCode::Minus);
    tolua_constant(tolua_S,"Equals",GUI::KeyCode::Equals);
    tolua_constant(tolua_S,"Backspace",GUI::KeyCode::Backspace);
    tolua_constant(tolua_S,"Tab",GUI::KeyCode::Tab);
    tolua_constant(tolua_S,"Q",GUI::KeyCode::Q);
    tolua_constant(tolua_S,"W",GUI::KeyCode::W);
    tolua_constant(tolua_S,"E",GUI::KeyCode::E);
    tolua_constant(tolua_S,"R",GUI::KeyCode::R);
    tolua_constant(tolua_S,"T",GUI::KeyCode::T);
    tolua_constant(tolua_S,"Y",GUI::KeyCode::Y);
    tolua_constant(tolua_S,"U",GUI::KeyCode::U);
    tolua_constant(tolua_S,"I",GUI::KeyCode::I);
    tolua_constant(tolua_S,"O",GUI::KeyCode::O);
    tolua_constant(tolua_S,"P",GUI::KeyCode::P);
    tolua_constant(tolua_S,"LeftBracket",GUI::KeyCode::LeftBracket);
    tolua_constant(tolua_S,"RightBracket",GUI::KeyCode::RightBracket);
    tolua_constant(tolua_S,"Return",GUI::KeyCode::Return);
    tolua_constant(tolua_S,"LeftControl",GUI::KeyCode::LeftControl);
    tolua_constant(tolua_S,"A",GUI::KeyCode::A);
    tolua_constant(tolua_S,"S",GUI::KeyCode::S);
    tolua_constant(tolua_S,"D",GUI::KeyCode::D);
    tolua_constant(tolua_S,"F",GUI::KeyCode::F);
    tolua_constant(tolua_S,"G",GUI::KeyCode::G);
    tolua_constant(tolua_S,"H",GUI::KeyCode::H);
    tolua_constant(tolua_S,"J",GUI::KeyCode::J);
    tolua_constant(tolua_S,"K",GUI::KeyCode::K);
    tolua_constant(tolua_S,"L",GUI::KeyCode::L);
    tolua_constant(tolua_S,"Semicolon",GUI::KeyCode::Semicolon);
    tolua_constant(tolua_S,"Apostrophe",GUI::KeyCode::Apostrophe);
    tolua_constant(tolua_S,"Grave",GUI::KeyCode::Grave);
    tolua_constant(tolua_S,"LeftShift",GUI::KeyCode::LeftShift);
    tolua_constant(tolua_S,"Backslash",GUI::KeyCode::Backslash);
    tolua_constant(tolua_S,"Z",GUI::KeyCode::Z);
    tolua_constant(tolua_S,"X",GUI::KeyCode::X);
    tolua_constant(tolua_S,"C",GUI::KeyCode::C);
    tolua_constant(tolua_S,"V",GUI::KeyCode::V);
    tolua_constant(tolua_S,"B",GUI::KeyCode::B);
    tolua_constant(tolua_S,"N",GUI::KeyCode::N);
    tolua_constant(tolua_S,"M",GUI::KeyCode::M);
    tolua_constant(tolua_S,"Comma",GUI::KeyCode::Comma);
    tolua_constant(tolua_S,"Period",GUI::KeyCode::Period);
    tolua_constant(tolua_S,"Slash",GUI::KeyCode::Slash);
    tolua_constant(tolua_S,"RightShift",GUI::KeyCode::RightShift);
    tolua_constant(tolua_S,"Multiply",GUI::KeyCode::Multiply);
    tolua_constant(tolua_S,"LeftAlt",GUI::KeyCode::LeftAlt);
    tolua_constant(tolua_S,"Space",GUI::KeyCode::Space);
    tolua_constant(tolua_S,"Capital",GUI::KeyCode::Capital);
    tolua_constant(tolua_S,"F1",GUI::KeyCode::F1);
    tolua_constant(tolua_S,"F2",GUI::KeyCode::F2);
    tolua_constant(tolua_S,"F3",GUI::KeyCode::F3);
    tolua_constant(tolua_S,"F4",GUI::KeyCode::F4);
    tolua_constant(tolua_S,"F5",GUI::KeyCode::F5);
    tolua_constant(tolua_S,"F6",GUI::KeyCode::F6);
    tolua_constant(tolua_S,"F7",GUI::KeyCode::F7);
    tolua_constant(tolua_S,"F8",GUI::KeyCode::F8);
    tolua_constant(tolua_S,"F9",GUI::KeyCode::F9);
    tolua_constant(tolua_S,"F10",GUI::KeyCode::F10);
    tolua_constant(tolua_S,"NumLock",GUI::KeyCode::NumLock);
    tolua_constant(tolua_S,"ScrollLock",GUI::KeyCode::ScrollLock);
    tolua_constant(tolua_S,"Numpad7",GUI::KeyCode::Numpad7);
    tolua_constant(tolua_S,"Numpad8",GUI::KeyCode::Numpad8);
    tolua_constant(tolua_S,"Numpad9",GUI::KeyCode::Numpad9);
    tolua_constant(tolua_S,"Subtract",GUI::KeyCode::Subtract);
    tolua_constant(tolua_S,"Numpad4",GUI::KeyCode::Numpad4);
    tolua_constant(tolua_S,"Numpad5",GUI::KeyCode::Numpad5);
    tolua_constant(tolua_S,"Numpad6",GUI::KeyCode::Numpad6);
    tolua_constant(tolua_S,"Add",GUI::KeyCode::Add);
    tolua_constant(tolua_S,"Numpad1",GUI::KeyCode::Numpad1);
    tolua_constant(tolua_S,"Numpad2",GUI::KeyCode::Numpad2);
    tolua_constant(tolua_S,"Numpad3",GUI::KeyCode::Numpad3);
    tolua_constant(tolua_S,"Numpad0",GUI::KeyCode::Numpad0);
    tolua_constant(tolua_S,"Decimal",GUI::KeyCode::Decimal);
    tolua_constant(tolua_S,"OEM_102",GUI::KeyCode::OEM_102);
    tolua_constant(tolua_S,"F11",GUI::KeyCode::F11);
    tolua_constant(tolua_S,"F12",GUI::KeyCode::F12);
    tolua_constant(tolua_S,"F13",GUI::KeyCode::F13);
    tolua_constant(tolua_S,"F14",GUI::KeyCode::F14);
    tolua_constant(tolua_S,"F15",GUI::KeyCode::F15);
    tolua_constant(tolua_S,"Kana",GUI::KeyCode::Kana);
    tolua_constant(tolua_S,"ABNT_C1",GUI::KeyCode::ABNT_C1);
    tolua_constant(tolua_S,"Convert",GUI::KeyCode::Convert);
    tolua_constant(tolua_S,"NoConvert",GUI::KeyCode::NoConvert);
    tolua_constant(tolua_S,"Yen",GUI::KeyCode::Yen);
    tolua_constant(tolua_S,"ABNT_C2",GUI::KeyCode::ABNT_C2);
    tolua_constant(tolua_S,"NumpadEquals",GUI::KeyCode::NumpadEquals);
    tolua_constant(tolua_S,"PrevTrack",GUI::KeyCode::PrevTrack);
    tolua_constant(tolua_S,"At",GUI::KeyCode::At);
    tolua_constant(tolua_S,"Colon",GUI::KeyCode::Colon);
    tolua_constant(tolua_S,"Underline",GUI::KeyCode::Underline);
    tolua_constant(tolua_S,"Kanji",GUI::KeyCode::Kanji);
    tolua_constant(tolua_S,"Stop",GUI::KeyCode::Stop);
    tolua_constant(tolua_S,"AX",GUI::KeyCode::AX);
    tolua_constant(tolua_S,"Unlabeled",GUI::KeyCode::Unlabeled);
    tolua_constant(tolua_S,"NextTrack",GUI::KeyCode::NextTrack);
    tolua_constant(tolua_S,"NumpadEnter",GUI::KeyCode::NumpadEnter);
    tolua_constant(tolua_S,"RightControl",GUI::KeyCode::RightControl);
    tolua_constant(tolua_S,"Mute",GUI::KeyCode::Mute);
    tolua_constant(tolua_S,"Calculator",GUI::KeyCode::Calculator);
    tolua_constant(tolua_S,"PlayPause",GUI::KeyCode::PlayPause);
    tolua_constant(tolua_S,"MediaStop",GUI::KeyCode::MediaStop);
    tolua_constant(tolua_S,"VolumeDown",GUI::KeyCode::VolumeDown);
    tolua_constant(tolua_S,"VolumeUp",GUI::KeyCode::VolumeUp);
    tolua_constant(tolua_S,"WebHome",GUI::KeyCode::WebHome);
    tolua_constant(tolua_S,"NumpadComma",GUI::KeyCode::NumpadComma);
    tolua_constant(tolua_S,"Divide",GUI::KeyCode::Divide);
    tolua_constant(tolua_S,"SysRq",GUI::KeyCode::SysRq);
    tolua_constant(tolua_S,"RightAlt",GUI::KeyCode::RightAlt);
    tolua_constant(tolua_S,"Pause",GUI::KeyCode::Pause);
    tolua_constant(tolua_S,"Home",GUI::KeyCode::Home);
    tolua_constant(tolua_S,"ArrowUp",GUI::KeyCode::ArrowUp);
    tolua_constant(tolua_S,"PageUp",GUI::KeyCode::PageUp);
    tolua_constant(tolua_S,"ArrowLeft",GUI::KeyCode::ArrowLeft);
    tolua_constant(tolua_S,"ArrowRight",GUI::KeyCode::ArrowRight);
    tolua_constant(tolua_S,"End",GUI::KeyCode::End);
    tolua_constant(tolua_S,"ArrowDown",GUI::KeyCode::ArrowDown);
    tolua_constant(tolua_S,"PageDown",GUI::KeyCode::PageDown);
    tolua_constant(tolua_S,"Insert",GUI::KeyCode::Insert);
    tolua_constant(tolua_S,"Delete",GUI::KeyCode::Delete);
    tolua_constant(tolua_S,"LeftWindows",GUI::KeyCode::LeftWindows);
    tolua_constant(tolua_S,"RightWindow",GUI::KeyCode::RightWindow);
    tolua_constant(tolua_S,"RightWindows",GUI::KeyCode::RightWindows);
    tolua_constant(tolua_S,"AppMenu",GUI::KeyCode::AppMenu);
    tolua_constant(tolua_S,"Power",GUI::KeyCode::Power);
    tolua_constant(tolua_S,"Sleep",GUI::KeyCode::Sleep);
    tolua_constant(tolua_S,"Wake",GUI::KeyCode::Wake);
    tolua_constant(tolua_S,"WebSearch",GUI::KeyCode::WebSearch);
    tolua_constant(tolua_S,"WebFavorites",GUI::KeyCode::WebFavorites);
    tolua_constant(tolua_S,"WebRefresh",GUI::KeyCode::WebRefresh);
    tolua_constant(tolua_S,"WebStop",GUI::KeyCode::WebStop);
    tolua_constant(tolua_S,"WebForward",GUI::KeyCode::WebForward);
    tolua_constant(tolua_S,"WebBack",GUI::KeyCode::WebBack);
    tolua_constant(tolua_S,"MyComputer",GUI::KeyCode::MyComputer);
    tolua_constant(tolua_S,"Mail",GUI::KeyCode::Mail);
    tolua_constant(tolua_S,"MediaSelect",GUI::KeyCode::MediaSelect);
    tolua_function(tolua_S,"new",tolua_GUI_GUI_KeyCode_new00);
    tolua_function(tolua_S,"new_local",tolua_GUI_GUI_KeyCode_new00_local);
    tolua_function(tolua_S,".call",tolua_GUI_GUI_KeyCode_new00_local);
    tolua_function(tolua_S,".eq",tolua_GUI_GUI_KeyCode__eq00);
    tolua_function(tolua_S,"ToValue",tolua_GUI_GUI_KeyCode_ToValue00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"ItemBox","GUI::ItemBox","DDContainer",NULL);
   tolua_beginmodule(tolua_S,"ItemBox");
    tolua_function(tolua_S,"GetItemCount",tolua_GUI_GUI_ItemBox_GetItemCount00);
    tolua_function(tolua_S,"InsertItem",tolua_GUI_GUI_ItemBox_InsertItem00);
    tolua_function(tolua_S,"AppendItem",tolua_GUI_GUI_ItemBox_AppendItem00);
    tolua_function(tolua_S,"RemoveItem",tolua_GUI_GUI_ItemBox_RemoveItem00);
    tolua_function(tolua_S,"RemoveAllItems",tolua_GUI_GUI_ItemBox_RemoveAllItems00);
    tolua_function(tolua_S,"RedrawItem",tolua_GUI_GUI_ItemBox_RedrawItem00);
    tolua_function(tolua_S,"RedrawAllItems",tolua_GUI_GUI_ItemBox_RedrawAllItems00);
    tolua_function(tolua_S,"GetIndexSelected",tolua_GUI_GUI_ItemBox_GetIndexSelected00);
    tolua_function(tolua_S,"SetIndexSelected",tolua_GUI_GUI_ItemBox_SetIndexSelected00);
    tolua_function(tolua_S,"ClearIndexSelected",tolua_GUI_GUI_ItemBox_ClearIndexSelected00);
    tolua_function(tolua_S,"SetItemData",tolua_GUI_GUI_ItemBox_SetItemData00);
    tolua_function(tolua_S,"ClearItemData",tolua_GUI_GUI_ItemBox_ClearItemData00);
    tolua_function(tolua_S,"GetItemData",tolua_GUI_GUI_ItemBox_GetItemData00);
    tolua_function(tolua_S,"SetItemBoxAlignVert",tolua_GUI_GUI_ItemBox_SetItemBoxAlignVert00);
    tolua_function(tolua_S,"GetItemBoxAlignVert",tolua_GUI_GUI_ItemBox_GetItemBoxAlignVert00);
    tolua_function(tolua_S,"GetIndexByWidget",tolua_GUI_GUI_ItemBox_GetIndexByWidget00);
    tolua_function(tolua_S,"GetWidgetDrag",tolua_GUI_GUI_ItemBox_GetWidgetDrag00);
    tolua_function(tolua_S,"GetWidgetByIndex",tolua_GUI_GUI_ItemBox_GetWidgetByIndex00);
    tolua_function(tolua_S,"ResetDrag",tolua_GUI_GUI_ItemBox_ResetDrag00);
    tolua_function(tolua_S,"SetPosition",tolua_GUI_GUI_ItemBox_SetPosition00);
    tolua_function(tolua_S,"SetSize",tolua_GUI_GUI_ItemBox_SetSize00);
    tolua_function(tolua_S,"SetCoord",tolua_GUI_GUI_ItemBox_SetCoord00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"LanguageManager","GUI::LanguageManager","",NULL);
   tolua_beginmodule(tolua_S,"LanguageManager");
    tolua_function(tolua_S,"Instance",tolua_GUI_GUI_LanguageManager_Instance00);
    tolua_function(tolua_S,"Load",tolua_GUI_GUI_LanguageManager_Load00);
    tolua_function(tolua_S,"SetCurrentLanguage",tolua_GUI_GUI_LanguageManager_SetCurrentLanguage00);
    tolua_function(tolua_S,"GetCurrentLanguage",tolua_GUI_GUI_LanguageManager_GetCurrentLanguage00);
    tolua_function(tolua_S,"ReplaceTags",tolua_GUI_GUI_LanguageManager_ReplaceTags00);
    tolua_function(tolua_S,"GetTag",tolua_GUI_GUI_LanguageManager_GetTag00);
    tolua_function(tolua_S,"AddUserTag",tolua_GUI_GUI_LanguageManager_AddUserTag00);
    tolua_function(tolua_S,"ClearUserTags",tolua_GUI_GUI_LanguageManager_ClearUserTags00);
    tolua_function(tolua_S,"LoadUserTags",tolua_GUI_GUI_LanguageManager_LoadUserTags00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"LayerManager","GUI::LayerManager","IUnlinkWidget",NULL);
   tolua_beginmodule(tolua_S,"LayerManager");
    tolua_function(tolua_S,"Instance",tolua_GUI_GUI_LayerManager_Instance00);
    tolua_function(tolua_S,"AttachToLayerNode",tolua_GUI_GUI_LayerManager_AttachToLayerNode00);
    tolua_function(tolua_S,"DetachFromLayer",tolua_GUI_GUI_LayerManager_DetachFromLayer00);
    tolua_function(tolua_S,"UpLayerItem",tolua_GUI_GUI_LayerManager_UpLayerItem00);
    tolua_function(tolua_S,"IsExist",tolua_GUI_GUI_LayerManager_IsExist00);
    tolua_function(tolua_S,"GetWidgetFromPoint",tolua_GUI_GUI_LayerManager_GetWidgetFromPoint00);
    tolua_function(tolua_S,"DumpStatisticToLog",tolua_GUI_GUI_LayerManager_DumpStatisticToLog00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"LayoutManager","GUI::LayoutManager","",NULL);
   tolua_beginmodule(tolua_S,"LayoutManager");
    tolua_function(tolua_S,"Instance",tolua_GUI_GUI_LayoutManager_Instance00);
    tolua_function(tolua_S,"Load",tolua_GUI_GUI_LayoutManager_Load00);
    tolua_function(tolua_S,"LoadLayout",tolua_GUI_GUI_LayoutManager_LoadLayout00);
    tolua_function(tolua_S,"LoadLayout",tolua_GUI_GUI_LayoutManager_LoadLayout01);
    tolua_function(tolua_S,"UnloadLayout",tolua_GUI_GUI_LayoutManager_UnloadLayout00);
    tolua_function(tolua_S,"FindWidget",tolua_GUI_GUI_LayoutManager_FindWidget00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"List","GUI::List","GUI::Widget",NULL);
   tolua_beginmodule(tolua_S,"List");
    tolua_function(tolua_S,"GetItemCount",tolua_GUI_GUI_List_GetItemCount00);
    tolua_function(tolua_S,"InsertItem",tolua_GUI_GUI_List_InsertItem00);
    tolua_function(tolua_S,"AppendItem",tolua_GUI_GUI_List_AppendItem00);
    tolua_function(tolua_S,"RemoveItem",tolua_GUI_GUI_List_RemoveItem00);
    tolua_function(tolua_S,"RemoveAllItems",tolua_GUI_GUI_List_RemoveAllItems00);
    tolua_function(tolua_S,"SwapItems",tolua_GUI_GUI_List_SwapItems00);
    tolua_function(tolua_S,"FindItemIndexWith",tolua_GUI_GUI_List_FindItemIndexWith00);
    tolua_function(tolua_S,"GetIndexSelected",tolua_GUI_GUI_List_GetIndexSelected00);
    tolua_function(tolua_S,"SetIndexSelected",tolua_GUI_GUI_List_SetIndexSelected00);
    tolua_function(tolua_S,"ClearIndexSelected",tolua_GUI_GUI_List_ClearIndexSelected00);
    tolua_function(tolua_S,"SetItemData",tolua_GUI_GUI_List_SetItemData00);
    tolua_function(tolua_S,"ClearItemData",tolua_GUI_GUI_List_ClearItemData00);
    tolua_function(tolua_S,"GetItemData",tolua_GUI_GUI_List_GetItemData00);
    tolua_function(tolua_S,"SetItemName",tolua_GUI_GUI_List_SetItemName00);
    tolua_function(tolua_S,"GetItemName",tolua_GUI_GUI_List_GetItemName00);
    tolua_function(tolua_S,"BeginToItem",tolua_GUI_GUI_List_BeginToItem00);
    tolua_function(tolua_S,"BeginToItemFirst",tolua_GUI_GUI_List_BeginToItemFirst00);
    tolua_function(tolua_S,"BeginToItemLast",tolua_GUI_GUI_List_BeginToItemLast00);
    tolua_function(tolua_S,"BeginToItemSelected",tolua_GUI_GUI_List_BeginToItemSelected00);
    tolua_function(tolua_S,"IsItemVisible",tolua_GUI_GUI_List_IsItemVisible00);
    tolua_function(tolua_S,"IsItemSelectedVisible",tolua_GUI_GUI_List_IsItemSelectedVisible00);
    tolua_function(tolua_S,"SetScrollVisible",tolua_GUI_GUI_List_SetScrollVisible00);
    tolua_function(tolua_S,"SetScrollPosition",tolua_GUI_GUI_List_SetScrollPosition00);
    tolua_function(tolua_S,"SetSize",tolua_GUI_GUI_List_SetSize00);
    tolua_function(tolua_S,"SetCoord",tolua_GUI_GUI_List_SetCoord00);
    tolua_function(tolua_S,"GetOptimalHeight",tolua_GUI_GUI_List_GetOptimalHeight00);
    tolua_function(tolua_S,"SetProperty",tolua_GUI_GUI_List_SetProperty00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"ListBox","GUI::ListBox","GUI::ListCtrl",NULL);
   tolua_beginmodule(tolua_S,"ListBox");
    tolua_function(tolua_S,"GetItemCount",tolua_GUI_GUI_ListBox_GetItemCount00);
    tolua_function(tolua_S,"InsertItem",tolua_GUI_GUI_ListBox_InsertItem00);
    tolua_function(tolua_S,"AppendItem",tolua_GUI_GUI_ListBox_AppendItem00);
    tolua_function(tolua_S,"RemoveItem",tolua_GUI_GUI_ListBox_RemoveItem00);
    tolua_function(tolua_S,"RemoveAllItems",tolua_GUI_GUI_ListBox_RemoveAllItems00);
    tolua_function(tolua_S,"SwapItems",tolua_GUI_GUI_ListBox_SwapItems00);
    tolua_function(tolua_S,"FindItemIndexWith",tolua_GUI_GUI_ListBox_FindItemIndexWith00);
    tolua_function(tolua_S,"GetIndexSelected",tolua_GUI_GUI_ListBox_GetIndexSelected00);
    tolua_function(tolua_S,"SetIndexSelected",tolua_GUI_GUI_ListBox_SetIndexSelected00);
    tolua_function(tolua_S,"ClearIndexSelected",tolua_GUI_GUI_ListBox_ClearIndexSelected00);
    tolua_function(tolua_S,"SetItemData",tolua_GUI_GUI_ListBox_SetItemData00);
    tolua_function(tolua_S,"ClearItemData",tolua_GUI_GUI_ListBox_ClearItemData00);
    tolua_function(tolua_S,"GetItemData",tolua_GUI_GUI_ListBox_GetItemData00);
    tolua_function(tolua_S,"SetItemName",tolua_GUI_GUI_ListBox_SetItemName00);
    tolua_function(tolua_S,"GetItemName",tolua_GUI_GUI_ListBox_GetItemName00);
    tolua_function(tolua_S,"BeginToItem",tolua_GUI_GUI_ListBox_BeginToItem00);
    tolua_function(tolua_S,"BeginToItemFirst",tolua_GUI_GUI_ListBox_BeginToItemFirst00);
    tolua_function(tolua_S,"BeginToItemLast",tolua_GUI_GUI_ListBox_BeginToItemLast00);
    tolua_function(tolua_S,"BeginToItemSelected",tolua_GUI_GUI_ListBox_BeginToItemSelected00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"ListCtrl","GUI::ListCtrl","DDContainer",NULL);
   tolua_beginmodule(tolua_S,"ListCtrl");
    tolua_function(tolua_S,"GetItemCount",tolua_GUI_GUI_ListCtrl_GetItemCount00);
    tolua_function(tolua_S,"InsertItem",tolua_GUI_GUI_ListCtrl_InsertItem00);
    tolua_function(tolua_S,"AppendItem",tolua_GUI_GUI_ListCtrl_AppendItem00);
    tolua_function(tolua_S,"RemoveItem",tolua_GUI_GUI_ListCtrl_RemoveItem00);
    tolua_function(tolua_S,"RemoveAllItems",tolua_GUI_GUI_ListCtrl_RemoveAllItems00);
    tolua_function(tolua_S,"RedrawItem",tolua_GUI_GUI_ListCtrl_RedrawItem00);
    tolua_function(tolua_S,"RedrawAllItems",tolua_GUI_GUI_ListCtrl_RedrawAllItems00);
    tolua_function(tolua_S,"GetIndexSelected",tolua_GUI_GUI_ListCtrl_GetIndexSelected00);
    tolua_function(tolua_S,"SetIndexSelected",tolua_GUI_GUI_ListCtrl_SetIndexSelected00);
    tolua_function(tolua_S,"ClearIndexSelected",tolua_GUI_GUI_ListCtrl_ClearIndexSelected00);
    tolua_function(tolua_S,"SetItemData",tolua_GUI_GUI_ListCtrl_SetItemData00);
    tolua_function(tolua_S,"ClearItemData",tolua_GUI_GUI_ListCtrl_ClearItemData00);
    tolua_function(tolua_S,"GetItemData",tolua_GUI_GUI_ListCtrl_GetItemData00);
    tolua_function(tolua_S,"GetIndexByWidget",tolua_GUI_GUI_ListCtrl_GetIndexByWidget00);
    tolua_function(tolua_S,"GetWidgetDrag",tolua_GUI_GUI_ListCtrl_GetWidgetDrag00);
    tolua_function(tolua_S,"GetWidgetByIndex",tolua_GUI_GUI_ListCtrl_GetWidgetByIndex00);
    tolua_function(tolua_S,"ResetDrag",tolua_GUI_GUI_ListCtrl_ResetDrag00);
    tolua_function(tolua_S,"SetPosition",tolua_GUI_GUI_ListCtrl_SetPosition00);
    tolua_function(tolua_S,"SetSize",tolua_GUI_GUI_ListCtrl_SetSize00);
    tolua_function(tolua_S,"SetCoord",tolua_GUI_GUI_ListCtrl_SetCoord00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"MenuBar","GUI::MenuBar","GUI::MenuCtrl",NULL);
   tolua_beginmodule(tolua_S,"MenuBar");
    tolua_function(tolua_S,"SetVisible",tolua_GUI_GUI_MenuBar_SetVisible00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"MenuCtrl","GUI::MenuCtrl","GUI::Widget",NULL);
   tolua_beginmodule(tolua_S,"MenuCtrl");
    tolua_constant(tolua_S,"ItemImageNone",GUI::MenuCtrl::ItemImageNone);
    tolua_constant(tolua_S,"ItemImagePopup",GUI::MenuCtrl::ItemImagePopup);
    tolua_function(tolua_S,"SetVisible",tolua_GUI_GUI_MenuCtrl_SetVisible00);
    tolua_function(tolua_S,"SetVisibleSmooth",tolua_GUI_GUI_MenuCtrl_SetVisibleSmooth00);
    tolua_function(tolua_S,"GetItemCount",tolua_GUI_GUI_MenuCtrl_GetItemCount00);
    tolua_function(tolua_S,"InsertItem",tolua_GUI_GUI_MenuCtrl_InsertItem00);
    tolua_function(tolua_S,"InsertItem",tolua_GUI_GUI_MenuCtrl_InsertItem01);
    tolua_function(tolua_S,"InsertItemEx",tolua_GUI_GUI_MenuCtrl_InsertItemEx00);
    tolua_function(tolua_S,"InsertItemEx",tolua_GUI_GUI_MenuCtrl_InsertItemEx01);
    tolua_function(tolua_S,"AppendItem",tolua_GUI_GUI_MenuCtrl_AppendItem00);
    tolua_function(tolua_S,"AppendItem",tolua_GUI_GUI_MenuCtrl_AppendItem01);
    tolua_function(tolua_S,"RemoveItem",tolua_GUI_GUI_MenuCtrl_RemoveItem00);
    tolua_function(tolua_S,"RemoveItem",tolua_GUI_GUI_MenuCtrl_RemoveItem01);
    tolua_function(tolua_S,"RemoveAllItems",tolua_GUI_GUI_MenuCtrl_RemoveAllItems00);
    tolua_function(tolua_S,"GetItem",tolua_GUI_GUI_MenuCtrl_GetItem00);
    tolua_function(tolua_S,"GetItemIndex",tolua_GUI_GUI_MenuCtrl_GetItemIndex00);
    tolua_function(tolua_S,"FindItemIndex",tolua_GUI_GUI_MenuCtrl_FindItemIndex00);
    tolua_function(tolua_S,"FindItemWith",tolua_GUI_GUI_MenuCtrl_FindItemWith00);
    tolua_function(tolua_S,"SetItemData",tolua_GUI_GUI_MenuCtrl_SetItemData00);
    tolua_function(tolua_S,"SetItemData",tolua_GUI_GUI_MenuCtrl_SetItemData01);
    tolua_function(tolua_S,"ClearItemData",tolua_GUI_GUI_MenuCtrl_ClearItemData00);
    tolua_function(tolua_S,"ClearItemData",tolua_GUI_GUI_MenuCtrl_ClearItemData01);
    tolua_function(tolua_S,"GetItemData",tolua_GUI_GUI_MenuCtrl_GetItemData00);
    tolua_function(tolua_S,"GetItemDataEx",tolua_GUI_GUI_MenuCtrl_GetItemDataEx00);
    tolua_function(tolua_S,"SetItemID",tolua_GUI_GUI_MenuCtrl_SetItemID00);
    tolua_function(tolua_S,"SetItemId",tolua_GUI_GUI_MenuCtrl_SetItemId00);
    tolua_function(tolua_S,"GetItemID",tolua_GUI_GUI_MenuCtrl_GetItemID00);
    tolua_function(tolua_S,"GetItemId",tolua_GUI_GUI_MenuCtrl_GetItemId00);
    tolua_function(tolua_S,"GetItemById",tolua_GUI_GUI_MenuCtrl_GetItemById00);
    tolua_function(tolua_S,"GetItemIndexById",tolua_GUI_GUI_MenuCtrl_GetItemIndexById00);
    tolua_function(tolua_S,"SetItemName",tolua_GUI_GUI_MenuCtrl_SetItemName00);
    tolua_function(tolua_S,"SetItemName",tolua_GUI_GUI_MenuCtrl_SetItemName01);
    tolua_function(tolua_S,"GetItemName",tolua_GUI_GUI_MenuCtrl_GetItemName00);
    tolua_function(tolua_S,"GetItemName",tolua_GUI_GUI_MenuCtrl_GetItemName01);
    tolua_function(tolua_S,"FindItemIndexWith",tolua_GUI_GUI_MenuCtrl_FindItemIndexWith00);
    tolua_function(tolua_S,"SetItemChildVisible",tolua_GUI_GUI_MenuCtrl_SetItemChildVisible00);
    tolua_function(tolua_S,"SetItemChildVisible",tolua_GUI_GUI_MenuCtrl_SetItemChildVisible01);
    tolua_function(tolua_S,"GetItemChild",tolua_GUI_GUI_MenuCtrl_GetItemChild00);
    tolua_function(tolua_S,"GetItemChild",tolua_GUI_GUI_MenuCtrl_GetItemChild01);
    tolua_function(tolua_S,"CreateItemChild",tolua_GUI_GUI_MenuCtrl_CreateItemChild00);
    tolua_function(tolua_S,"CreateItemChild",tolua_GUI_GUI_MenuCtrl_CreateItemChild01);
    tolua_function(tolua_S,"RemoveItemChild",tolua_GUI_GUI_MenuCtrl_RemoveItemChild00);
    tolua_function(tolua_S,"RemoveItemChild",tolua_GUI_GUI_MenuCtrl_RemoveItemChild01);
    tolua_function(tolua_S,"GetItemType",tolua_GUI_GUI_MenuCtrl_GetItemType00);
    tolua_function(tolua_S,"GetItemType",tolua_GUI_GUI_MenuCtrl_GetItemType01);
    tolua_function(tolua_S,"SetItemType",tolua_GUI_GUI_MenuCtrl_SetItemType00);
    tolua_function(tolua_S,"SetItemType",tolua_GUI_GUI_MenuCtrl_SetItemType01);
    tolua_function(tolua_S,"SetPopupAccept",tolua_GUI_GUI_MenuCtrl_SetPopupAccept00);
    tolua_function(tolua_S,"GetPopupAccept",tolua_GUI_GUI_MenuCtrl_GetPopupAccept00);
    tolua_function(tolua_S,"GetMenuItemParent",tolua_GUI_GUI_MenuCtrl_GetMenuItemParent00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"MenuItem","GUI::MenuItem","GUI::Button",NULL);
   tolua_beginmodule(tolua_S,"MenuItem");
    tolua_function(tolua_S,"SetCaption",tolua_GUI_GUI_MenuItem_SetCaption00);
    tolua_function(tolua_S,"SetItemName",tolua_GUI_GUI_MenuItem_SetItemName00);
    tolua_function(tolua_S,"GetItemName",tolua_GUI_GUI_MenuItem_GetItemName00);
    tolua_function(tolua_S,"SetItemData",tolua_GUI_GUI_MenuItem_SetItemData00);
    tolua_function(tolua_S,"GetItemDataEx",tolua_GUI_GUI_MenuItem_GetItemDataEx00);
    tolua_function(tolua_S,"RemoveItem",tolua_GUI_GUI_MenuItem_RemoveItem00);
    tolua_function(tolua_S,"SetItemId",tolua_GUI_GUI_MenuItem_SetItemId00);
    tolua_function(tolua_S,"GetItemId",tolua_GUI_GUI_MenuItem_GetItemId00);
    tolua_function(tolua_S,"GetItemIndex",tolua_GUI_GUI_MenuItem_GetItemIndex00);
    tolua_function(tolua_S,"CreateItemChild",tolua_GUI_GUI_MenuItem_CreateItemChild00);
    tolua_function(tolua_S,"SetItemType",tolua_GUI_GUI_MenuItem_SetItemType00);
    tolua_function(tolua_S,"GetItemType",tolua_GUI_GUI_MenuItem_GetItemType00);
    tolua_function(tolua_S,"SetItemChildVisible",tolua_GUI_GUI_MenuItem_SetItemChildVisible00);
    tolua_function(tolua_S,"GetMenuCtrlParent",tolua_GUI_GUI_MenuItem_GetMenuCtrlParent00);
    tolua_function(tolua_S,"GetItemChild",tolua_GUI_GUI_MenuItem_GetItemChild00);
    tolua_function(tolua_S,"SetProperty",tolua_GUI_GUI_MenuItem_SetProperty00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"Message","GUI::Message","GUI::Window",NULL);
   tolua_beginmodule(tolua_S,"Message");
    tolua_function(tolua_S,"SetMessageText",tolua_GUI_GUI_Message_SetMessageText00);
    tolua_function(tolua_S,"AddButtonName",tolua_GUI_GUI_Message_AddButtonName00);
    tolua_function(tolua_S,"SetSmoothShow",tolua_GUI_GUI_Message_SetSmoothShow00);
    tolua_function(tolua_S,"GetDefaultLayer",tolua_GUI_GUI_Message_GetDefaultLayer00);
    tolua_function(tolua_S,"SetMessageIcon",tolua_GUI_GUI_Message_SetMessageIcon00);
    tolua_function(tolua_S,"SetWindowFade",tolua_GUI_GUI_Message_SetWindowFade00);
    tolua_function(tolua_S,"endMessage",tolua_GUI_GUI_Message_endMessage00);
    tolua_function(tolua_S,"endMessage",tolua_GUI_GUI_Message_endMessage01);
    tolua_function(tolua_S,"SetMessageButton",tolua_GUI_GUI_Message_SetMessageButton00);
    tolua_function(tolua_S,"SetMessageStyle",tolua_GUI_GUI_Message_SetMessageStyle00);
    tolua_function(tolua_S,"SetMessageModal",tolua_GUI_GUI_Message_SetMessageModal00);
    tolua_function(tolua_S,"CreateMessageBox",tolua_GUI_GUI_Message_CreateMessageBox00);
    tolua_function(tolua_S,"CreateMessageBox",tolua_GUI_GUI_Message_CreateMessageBox01);
    tolua_function(tolua_S,"CreateMessageBox",tolua_GUI_GUI_Message_CreateMessageBox02);
    tolua_function(tolua_S,"CreateMessageBox",tolua_GUI_GUI_Message_CreateMessageBox03);
    tolua_function(tolua_S,"CreateMessageBox",tolua_GUI_GUI_Message_CreateMessageBox04);
    tolua_function(tolua_S,"CreateMessageBox",tolua_GUI_GUI_Message_CreateMessageBox05);
    tolua_function(tolua_S,"CreateMessageBox",tolua_GUI_GUI_Message_CreateMessageBox06);
    tolua_function(tolua_S,"SetProperty",tolua_GUI_GUI_Message_SetProperty00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"MessageBoxStyle","GUI::MessageBoxStyle","",tolua_collect_GUI__MessageBoxStyle);
   #else
   tolua_cclass(tolua_S,"MessageBoxStyle","GUI::MessageBoxStyle","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"MessageBoxStyle");
    tolua_constant(tolua_S,"None",GUI::MessageBoxStyle::None);
    tolua_constant(tolua_S,"Ok",GUI::MessageBoxStyle::Ok);
    tolua_constant(tolua_S,"Yes",GUI::MessageBoxStyle::Yes);
    tolua_constant(tolua_S,"No",GUI::MessageBoxStyle::No);
    tolua_constant(tolua_S,"Abort",GUI::MessageBoxStyle::Abort);
    tolua_constant(tolua_S,"Retry",GUI::MessageBoxStyle::Retry);
    tolua_constant(tolua_S,"Ignore",GUI::MessageBoxStyle::Ignore);
    tolua_constant(tolua_S,"Cancel",GUI::MessageBoxStyle::Cancel);
    tolua_constant(tolua_S,"Try",GUI::MessageBoxStyle::Try);
    tolua_constant(tolua_S,"Continue",GUI::MessageBoxStyle::Continue);
    tolua_constant(tolua_S,"_IndexUserButton1",GUI::MessageBoxStyle::_IndexUserButton1);
    tolua_constant(tolua_S,"Button1",GUI::MessageBoxStyle::Button1);
    tolua_constant(tolua_S,"Button2",GUI::MessageBoxStyle::Button2);
    tolua_constant(tolua_S,"Button3",GUI::MessageBoxStyle::Button3);
    tolua_constant(tolua_S,"Button4",GUI::MessageBoxStyle::Button4);
    tolua_constant(tolua_S,"_CountUserButtons",GUI::MessageBoxStyle::_CountUserButtons);
    tolua_constant(tolua_S,"_IndexIcon1",GUI::MessageBoxStyle::_IndexIcon1);
    tolua_constant(tolua_S,"IconDefault",GUI::MessageBoxStyle::IconDefault);
    tolua_constant(tolua_S,"IconInfo",GUI::MessageBoxStyle::IconInfo);
    tolua_constant(tolua_S,"IconQuest",GUI::MessageBoxStyle::IconQuest);
    tolua_constant(tolua_S,"IconError",GUI::MessageBoxStyle::IconError);
    tolua_constant(tolua_S,"IconWarning",GUI::MessageBoxStyle::IconWarning);
    tolua_constant(tolua_S,"Icon1",GUI::MessageBoxStyle::Icon1);
    tolua_constant(tolua_S,"Icon2",GUI::MessageBoxStyle::Icon2);
    tolua_constant(tolua_S,"Icon3",GUI::MessageBoxStyle::Icon3);
    tolua_constant(tolua_S,"Icon4",GUI::MessageBoxStyle::Icon4);
    tolua_constant(tolua_S,"Icon5",GUI::MessageBoxStyle::Icon5);
    tolua_constant(tolua_S,"Icon6",GUI::MessageBoxStyle::Icon6);
    tolua_constant(tolua_S,"Icon7",GUI::MessageBoxStyle::Icon7);
    tolua_constant(tolua_S,"Icon8",GUI::MessageBoxStyle::Icon8);
    tolua_function(tolua_S,"new",tolua_GUI_GUI_MessageBoxStyle_new00);
    tolua_function(tolua_S,"new_local",tolua_GUI_GUI_MessageBoxStyle_new00_local);
    tolua_function(tolua_S,".call",tolua_GUI_GUI_MessageBoxStyle_new00_local);
    tolua_function(tolua_S,"GetIconIndex",tolua_GUI_GUI_MessageBoxStyle_GetIconIndex00);
    tolua_function(tolua_S,"GetButtonIndex",tolua_GUI_GUI_MessageBoxStyle_GetButtonIndex00);
    tolua_function(tolua_S,"Parse",tolua_GUI_GUI_MessageBoxStyle_Parse00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"MultiList","GUI::MultiList","GUI::Widget",NULL);
   tolua_beginmodule(tolua_S,"MultiList");
    tolua_function(tolua_S,"GetColumnCount",tolua_GUI_GUI_MultiList_GetColumnCount00);
    tolua_function(tolua_S,"InsetColumn",tolua_GUI_GUI_MultiList_InsetColumn00);
    tolua_function(tolua_S,"AppendColumn",tolua_GUI_GUI_MultiList_AppendColumn00);
    tolua_function(tolua_S,"RemoveColumn",tolua_GUI_GUI_MultiList_RemoveColumn00);
    tolua_function(tolua_S,"RemoveAllColumns",tolua_GUI_GUI_MultiList_RemoveAllColumns00);
    tolua_function(tolua_S,"SetColumnName",tolua_GUI_GUI_MultiList_SetColumnName00);
    tolua_function(tolua_S,"SetColumnWidth",tolua_GUI_GUI_MultiList_SetColumnWidth00);
    tolua_function(tolua_S,"GetColumnName",tolua_GUI_GUI_MultiList_GetColumnName00);
    tolua_function(tolua_S,"GetColulmnWidth",tolua_GUI_GUI_MultiList_GetColulmnWidth00);
    tolua_function(tolua_S,"SortByColumn",tolua_GUI_GUI_MultiList_SortByColumn00);
    tolua_function(tolua_S,"SetColumnData",tolua_GUI_GUI_MultiList_SetColumnData00);
    tolua_function(tolua_S,"ClearColumnData",tolua_GUI_GUI_MultiList_ClearColumnData00);
    tolua_function(tolua_S,"GetColumnData",tolua_GUI_GUI_MultiList_GetColumnData00);
    tolua_function(tolua_S,"GetItemCount",tolua_GUI_GUI_MultiList_GetItemCount00);
    tolua_function(tolua_S,"InsertItem",tolua_GUI_GUI_MultiList_InsertItem00);
    tolua_function(tolua_S,"AppendItem",tolua_GUI_GUI_MultiList_AppendItem00);
    tolua_function(tolua_S,"RemoveItem",tolua_GUI_GUI_MultiList_RemoveItem00);
    tolua_function(tolua_S,"RemoveAllItems",tolua_GUI_GUI_MultiList_RemoveAllItems00);
    tolua_function(tolua_S,"SwapItems",tolua_GUI_GUI_MultiList_SwapItems00);
    tolua_function(tolua_S,"SetItemName",tolua_GUI_GUI_MultiList_SetItemName00);
    tolua_function(tolua_S,"GetItemName",tolua_GUI_GUI_MultiList_GetItemName00);
    tolua_function(tolua_S,"GetIndexSelected",tolua_GUI_GUI_MultiList_GetIndexSelected00);
    tolua_function(tolua_S,"SetIndexSelected",tolua_GUI_GUI_MultiList_SetIndexSelected00);
    tolua_function(tolua_S,"ClearIndexSelected",tolua_GUI_GUI_MultiList_ClearIndexSelected00);
    tolua_function(tolua_S,"SetItemData",tolua_GUI_GUI_MultiList_SetItemData00);
    tolua_function(tolua_S,"ClearItemData",tolua_GUI_GUI_MultiList_ClearItemData00);
    tolua_function(tolua_S,"GetItemData",tolua_GUI_GUI_MultiList_GetItemData00);
    tolua_function(tolua_S,"SetSubItemName",tolua_GUI_GUI_MultiList_SetSubItemName00);
    tolua_function(tolua_S,"GetSubItemName",tolua_GUI_GUI_MultiList_GetSubItemName00);
    tolua_function(tolua_S,"FindSubItemWith",tolua_GUI_GUI_MultiList_FindSubItemWith00);
    tolua_function(tolua_S,"SetSubItemData",tolua_GUI_GUI_MultiList_SetSubItemData00);
    tolua_function(tolua_S,"ClearSubItemData",tolua_GUI_GUI_MultiList_ClearSubItemData00);
    tolua_function(tolua_S,"GetSubItemData",tolua_GUI_GUI_MultiList_GetSubItemData00);
    tolua_variable(tolua_S,"__BiIndexBase__",tolua_get_GUI__MultiList___BiIndexBase__,NULL);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"PopupMenu","GUI::PopupMenu","GUI::MenuCtrl",NULL);
   tolua_beginmodule(tolua_S,"PopupMenu");
    tolua_function(tolua_S,"SetVisible",tolua_GUI_GUI_PopupMenu_SetVisible00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"Progress","GUI::Progress","GUI::Widget",NULL);
   tolua_beginmodule(tolua_S,"Progress");
    tolua_function(tolua_S,"SetProgressRange",tolua_GUI_GUI_Progress_SetProgressRange00);
    tolua_function(tolua_S,"GetProgressRange",tolua_GUI_GUI_Progress_GetProgressRange00);
    tolua_function(tolua_S,"SetProgressPosition",tolua_GUI_GUI_Progress_SetProgressPosition00);
    tolua_function(tolua_S,"GetProgressPosition",tolua_GUI_GUI_Progress_GetProgressPosition00);
    tolua_function(tolua_S,"SetProgressAutoTrack",tolua_GUI_GUI_Progress_SetProgressAutoTrack00);
    tolua_function(tolua_S,"GetProgressAutoTrack",tolua_GUI_GUI_Progress_GetProgressAutoTrack00);
    tolua_function(tolua_S,"SetProgressStartPoint",tolua_GUI_GUI_Progress_SetProgressStartPoint00);
    tolua_function(tolua_S,"GetProgressStartPoint",tolua_GUI_GUI_Progress_GetProgressStartPoint00);
    tolua_function(tolua_S,"SetPosition",tolua_GUI_GUI_Progress_SetPosition00);
    tolua_function(tolua_S,"SetSize",tolua_GUI_GUI_Progress_SetSize00);
    tolua_function(tolua_S,"SetCoord",tolua_GUI_GUI_Progress_SetCoord00);
    tolua_function(tolua_S,"SetProperty",tolua_GUI_GUI_Progress_SetProperty00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"ScrollView","GUI::ScrollView","GUI::Widget",NULL);
   tolua_beginmodule(tolua_S,"ScrollView");
    tolua_function(tolua_S,"SetPosition",tolua_GUI_GUI_ScrollView_SetPosition00);
    tolua_function(tolua_S,"SetSize",tolua_GUI_GUI_ScrollView_SetSize00);
    tolua_function(tolua_S,"SetCoord",tolua_GUI_GUI_ScrollView_SetCoord00);
    tolua_function(tolua_S,"SetVisibleVScroll",tolua_GUI_GUI_ScrollView_SetVisibleVScroll00);
    tolua_function(tolua_S,"IsVisibleVScroll",tolua_GUI_GUI_ScrollView_IsVisibleVScroll00);
    tolua_function(tolua_S,"SetVisibleHScroll",tolua_GUI_GUI_ScrollView_SetVisibleHScroll00);
    tolua_function(tolua_S,"IsVisibleHScroll",tolua_GUI_GUI_ScrollView_IsVisibleHScroll00);
    tolua_function(tolua_S,"SetCanvasAlign",tolua_GUI_GUI_ScrollView_SetCanvasAlign00);
    tolua_function(tolua_S,"GetCanvasAlign",tolua_GUI_GUI_ScrollView_GetCanvasAlign00);
    tolua_function(tolua_S,"SetCanvasSize",tolua_GUI_GUI_ScrollView_SetCanvasSize00);
    tolua_function(tolua_S,"GetCanvasSize",tolua_GUI_GUI_ScrollView_GetCanvasSize00);
    tolua_function(tolua_S,"GetClientCoord",tolua_GUI_GUI_ScrollView_GetClientCoord00);
    tolua_function(tolua_S,"SetProperty",tolua_GUI_GUI_ScrollView_SetProperty00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"StaticImage","GUI::StaticImage","GUI::Widget",NULL);
   tolua_beginmodule(tolua_S,"StaticImage");
    tolua_function(tolua_S,"SetImageInfo",tolua_GUI_GUI_StaticImage_SetImageInfo00);
    tolua_function(tolua_S,"SetImageTexture",tolua_GUI_GUI_StaticImage_SetImageTexture00);
    tolua_function(tolua_S,"SetImageRect",tolua_GUI_GUI_StaticImage_SetImageRect00);
    tolua_function(tolua_S,"SetImageCoord",tolua_GUI_GUI_StaticImage_SetImageCoord00);
    tolua_function(tolua_S,"SetImageTile",tolua_GUI_GUI_StaticImage_SetImageTile00);
    tolua_function(tolua_S,"SetImageIndex",tolua_GUI_GUI_StaticImage_SetImageIndex00);
    tolua_function(tolua_S,"GetImageIndex",tolua_GUI_GUI_StaticImage_GetImageIndex00);
    tolua_function(tolua_S,"GetItemCount",tolua_GUI_GUI_StaticImage_GetItemCount00);
    tolua_function(tolua_S,"SetItemSelect",tolua_GUI_GUI_StaticImage_SetItemSelect00);
    tolua_function(tolua_S,"GetItemSelect",tolua_GUI_GUI_StaticImage_GetItemSelect00);
    tolua_function(tolua_S,"ResetItemSelect",tolua_GUI_GUI_StaticImage_ResetItemSelect00);
    tolua_function(tolua_S,"InsertItem",tolua_GUI_GUI_StaticImage_InsertItem00);
    tolua_function(tolua_S,"AddItem",tolua_GUI_GUI_StaticImage_AddItem00);
    tolua_function(tolua_S,"SetItem",tolua_GUI_GUI_StaticImage_SetItem00);
    tolua_function(tolua_S,"DeleteItem",tolua_GUI_GUI_StaticImage_DeleteItem00);
    tolua_function(tolua_S,"DeleteAllItems",tolua_GUI_GUI_StaticImage_DeleteAllItems00);
    tolua_function(tolua_S,"AddItemFrame",tolua_GUI_GUI_StaticImage_AddItemFrame00);
    tolua_function(tolua_S,"InsertItemFrame",tolua_GUI_GUI_StaticImage_InsertItemFrame00);
    tolua_function(tolua_S,"AddItemFrameDublicate",tolua_GUI_GUI_StaticImage_AddItemFrameDublicate00);
    tolua_function(tolua_S,"InsertItemFrameDublicate",tolua_GUI_GUI_StaticImage_InsertItemFrameDublicate00);
    tolua_function(tolua_S,"SetItemFrame",tolua_GUI_GUI_StaticImage_SetItemFrame00);
    tolua_function(tolua_S,"DeleteItemFrame",tolua_GUI_GUI_StaticImage_DeleteItemFrame00);
    tolua_function(tolua_S,"DeleteAllItemFrames",tolua_GUI_GUI_StaticImage_DeleteAllItemFrames00);
    tolua_function(tolua_S,"SetItemFrameRate",tolua_GUI_GUI_StaticImage_SetItemFrameRate00);
    tolua_function(tolua_S,"GetItemFrameRate",tolua_GUI_GUI_StaticImage_GetItemFrameRate00);
    tolua_function(tolua_S,"SetItemResource",tolua_GUI_GUI_StaticImage_SetItemResource00);
    tolua_function(tolua_S,"SetItemResource",tolua_GUI_GUI_StaticImage_SetItemResource01);
    tolua_function(tolua_S,"SetItemGroup",tolua_GUI_GUI_StaticImage_SetItemGroup00);
    tolua_function(tolua_S,"SetItemName",tolua_GUI_GUI_StaticImage_SetItemName00);
    tolua_function(tolua_S,"SetItemResourceInfo",tolua_GUI_GUI_StaticImage_SetItemResourceInfo00);
    tolua_function(tolua_S,"SetProperty",tolua_GUI_GUI_StaticImage_SetProperty00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"StaticText","GUI::StaticText","GUI::Widget",NULL);
   tolua_beginmodule(tolua_S,"StaticText");
    tolua_function(tolua_S,"GetTextRegion",tolua_GUI_GUI_StaticText_GetTextRegion00);
    tolua_function(tolua_S,"GetTextSize",tolua_GUI_GUI_StaticText_GetTextSize00);
    tolua_function(tolua_S,"SetFontName",tolua_GUI_GUI_StaticText_SetFontName00);
    tolua_function(tolua_S,"GetFontName",tolua_GUI_GUI_StaticText_GetFontName00);
    tolua_function(tolua_S,"SetFontHeight",tolua_GUI_GUI_StaticText_SetFontHeight00);
    tolua_function(tolua_S,"GetFontHeight",tolua_GUI_GUI_StaticText_GetFontHeight00);
    tolua_function(tolua_S,"SetTextAlign",tolua_GUI_GUI_StaticText_SetTextAlign00);
    tolua_function(tolua_S,"GetTextAlign",tolua_GUI_GUI_StaticText_GetTextAlign00);
    tolua_function(tolua_S,"SetTextColour",tolua_GUI_GUI_StaticText_SetTextColour00);
    tolua_function(tolua_S,"GetTextColour",tolua_GUI_GUI_StaticText_GetTextColour00);
    tolua_function(tolua_S,"SetProperty",tolua_GUI_GUI_StaticText_SetProperty00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"Tab","GUI::Tab","GUI::Widget",NULL);
   tolua_beginmodule(tolua_S,"Tab");
    tolua_function(tolua_S,"SetPosition",tolua_GUI_GUI_Tab_SetPosition00);
    tolua_function(tolua_S,"SetSize",tolua_GUI_GUI_Tab_SetSize00);
    tolua_function(tolua_S,"SetCoord",tolua_GUI_GUI_Tab_SetCoord00);
    tolua_function(tolua_S,"GetItemCount",tolua_GUI_GUI_Tab_GetItemCount00);
    tolua_function(tolua_S,"InsertItem",tolua_GUI_GUI_Tab_InsertItem00);
    tolua_function(tolua_S,"InsertItemEx",tolua_GUI_GUI_Tab_InsertItemEx00);
    tolua_function(tolua_S,"AppendItem",tolua_GUI_GUI_Tab_AppendItem00);
    tolua_function(tolua_S,"RemoveItem",tolua_GUI_GUI_Tab_RemoveItem00);
    tolua_function(tolua_S,"RemoveItem",tolua_GUI_GUI_Tab_RemoveItem01);
    tolua_function(tolua_S,"RemoveAllItems",tolua_GUI_GUI_Tab_RemoveAllItems00);
    tolua_function(tolua_S,"GetItem",tolua_GUI_GUI_Tab_GetItem00);
    tolua_function(tolua_S,"GetItemIndex",tolua_GUI_GUI_Tab_GetItemIndex00);
    tolua_function(tolua_S,"FindItemIndex",tolua_GUI_GUI_Tab_FindItemIndex00);
    tolua_function(tolua_S,"FindItemIndexWith",tolua_GUI_GUI_Tab_FindItemIndexWith00);
    tolua_function(tolua_S,"FindItemWith",tolua_GUI_GUI_Tab_FindItemWith00);
    tolua_function(tolua_S,"GetIndexSelected",tolua_GUI_GUI_Tab_GetIndexSelected00);
    tolua_function(tolua_S,"GetItemSelected",tolua_GUI_GUI_Tab_GetItemSelected00);
    tolua_function(tolua_S,"SetIndexSelected",tolua_GUI_GUI_Tab_SetIndexSelected00);
    tolua_function(tolua_S,"SetItemSelected",tolua_GUI_GUI_Tab_SetItemSelected00);
    tolua_function(tolua_S,"SetItemData",tolua_GUI_GUI_Tab_SetItemData00);
    tolua_function(tolua_S,"SetItemData",tolua_GUI_GUI_Tab_SetItemData01);
    tolua_function(tolua_S,"ClearItemData",tolua_GUI_GUI_Tab_ClearItemData00);
    tolua_function(tolua_S,"ClearItemData",tolua_GUI_GUI_Tab_ClearItemData01);
    tolua_function(tolua_S,"GetItemData",tolua_GUI_GUI_Tab_GetItemData00);
    tolua_function(tolua_S,"GetItemData",tolua_GUI_GUI_Tab_GetItemData01);
    tolua_function(tolua_S,"SetItemName",tolua_GUI_GUI_Tab_SetItemName00);
    tolua_function(tolua_S,"SetItemName",tolua_GUI_GUI_Tab_SetItemName01);
    tolua_function(tolua_S,"GetItemName",tolua_GUI_GUI_Tab_GetItemName00);
    tolua_function(tolua_S,"GetItemName",tolua_GUI_GUI_Tab_GetItemName01);
    tolua_function(tolua_S,"BeginToItem",tolua_GUI_GUI_Tab_BeginToItem00);
    tolua_function(tolua_S,"BeginToItem",tolua_GUI_GUI_Tab_BeginToItem01);
    tolua_function(tolua_S,"BeginToItemFirst",tolua_GUI_GUI_Tab_BeginToItemFirst00);
    tolua_function(tolua_S,"BeginToItemLast",tolua_GUI_GUI_Tab_BeginToItemLast00);
    tolua_function(tolua_S,"BeginToItemSelected",tolua_GUI_GUI_Tab_BeginToItemSelected00);
    tolua_function(tolua_S,"SetButtonWidth",tolua_GUI_GUI_Tab_SetButtonWidth00);
    tolua_function(tolua_S,"SetButtonWidth",tolua_GUI_GUI_Tab_SetButtonWidth01);
    tolua_function(tolua_S,"GetButtonWidth",tolua_GUI_GUI_Tab_GetButtonWidth00);
    tolua_function(tolua_S,"GetButtonWidth",tolua_GUI_GUI_Tab_GetButtonWidth01);
    tolua_function(tolua_S,"SetButtonDefaultWidth",tolua_GUI_GUI_Tab_SetButtonDefaultWidth00);
    tolua_function(tolua_S,"GetButtonDefaultWidth",tolua_GUI_GUI_Tab_GetButtonDefaultWidth00);
    tolua_function(tolua_S,"SetButtonAutoWidth",tolua_GUI_GUI_Tab_SetButtonAutoWidth00);
    tolua_function(tolua_S,"GetButtonAutoWidth",tolua_GUI_GUI_Tab_GetButtonAutoWidth00);
    tolua_function(tolua_S,"SetSmoothShow",tolua_GUI_GUI_Tab_SetSmoothShow00);
    tolua_function(tolua_S,"GetSmoothShow",tolua_GUI_GUI_Tab_GetSmoothShow00);
    tolua_function(tolua_S,"SetProperty",tolua_GUI_GUI_Tab_SetProperty00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"TabItem","GUI::TabItem","GUI::Widget",NULL);
   tolua_beginmodule(tolua_S,"TabItem");
    tolua_function(tolua_S,"SetCaption",tolua_GUI_GUI_TabItem_SetCaption00);
    tolua_function(tolua_S,"GetCaption",tolua_GUI_GUI_TabItem_GetCaption00);
    tolua_function(tolua_S,"SetButtonWidth",tolua_GUI_GUI_TabItem_SetButtonWidth00);
    tolua_function(tolua_S,"GetButtonWidth",tolua_GUI_GUI_TabItem_GetButtonWidth00);
    tolua_function(tolua_S,"SetItemName",tolua_GUI_GUI_TabItem_SetItemName00);
    tolua_function(tolua_S,"GetItemName",tolua_GUI_GUI_TabItem_GetItemName00);
    tolua_function(tolua_S,"SetItemData",tolua_GUI_GUI_TabItem_SetItemData00);
    tolua_function(tolua_S,"SetItemSelected",tolua_GUI_GUI_TabItem_SetItemSelected00);
    tolua_function(tolua_S,"RemoveItem",tolua_GUI_GUI_TabItem_RemoveItem00);
    tolua_function(tolua_S,"SetProperty",tolua_GUI_GUI_TabItem_SetProperty00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_module(tolua_S,"types",0);
   tolua_beginmodule(tolua_S,"types");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"TCoord_int_","GUI::types::TCoord<int>","",tolua_collect_GUI__types__TCoord_int_);
    #else
    tolua_cclass(tolua_S,"TCoord_int_","GUI::types::TCoord<int>","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"TCoord_int_");
     tolua_variable(tolua_S,"left",tolua_get_GUI__types__TCoord_int__left,tolua_set_GUI__types__TCoord_int__left);
     tolua_variable(tolua_S,"top",tolua_get_GUI__types__TCoord_int__top,tolua_set_GUI__types__TCoord_int__top);
     tolua_variable(tolua_S,"width",tolua_get_GUI__types__TCoord_int__width,tolua_set_GUI__types__TCoord_int__width);
     tolua_variable(tolua_S,"height",tolua_get_GUI__types__TCoord_int__height,tolua_set_GUI__types__TCoord_int__height);
     tolua_function(tolua_S,"new",tolua_GUI_GUI_types_TCoord_int__new00);
     tolua_function(tolua_S,"new_local",tolua_GUI_GUI_types_TCoord_int__new00_local);
     tolua_function(tolua_S,".call",tolua_GUI_GUI_types_TCoord_int__new00_local);
     tolua_function(tolua_S,"new",tolua_GUI_GUI_types_TCoord_int__new01);
     tolua_function(tolua_S,"new_local",tolua_GUI_GUI_types_TCoord_int__new01_local);
     tolua_function(tolua_S,".call",tolua_GUI_GUI_types_TCoord_int__new01_local);
     tolua_function(tolua_S,"new",tolua_GUI_GUI_types_TCoord_int__new02);
     tolua_function(tolua_S,"new_local",tolua_GUI_GUI_types_TCoord_int__new02_local);
     tolua_function(tolua_S,".call",tolua_GUI_GUI_types_TCoord_int__new02_local);
     tolua_function(tolua_S,"new",tolua_GUI_GUI_types_TCoord_int__new03);
     tolua_function(tolua_S,"new_local",tolua_GUI_GUI_types_TCoord_int__new03_local);
     tolua_function(tolua_S,".call",tolua_GUI_GUI_types_TCoord_int__new03_local);
     tolua_function(tolua_S,".sub",tolua_GUI_GUI_types_TCoord_int___sub00);
     tolua_function(tolua_S,".sub",tolua_GUI_GUI_types_TCoord_int___sub01);
     tolua_function(tolua_S,".sub",tolua_GUI_GUI_types_TCoord_int___sub02);
     tolua_function(tolua_S,".add",tolua_GUI_GUI_types_TCoord_int___add00);
     tolua_function(tolua_S,".add",tolua_GUI_GUI_types_TCoord_int___add01);
     tolua_function(tolua_S,".add",tolua_GUI_GUI_types_TCoord_int___add02);
     tolua_function(tolua_S,".eq",tolua_GUI_GUI_types_TCoord_int___eq00);
     tolua_function(tolua_S,"Right",tolua_GUI_GUI_types_TCoord_int__Right00);
     tolua_function(tolua_S,"Bottom",tolua_GUI_GUI_types_TCoord_int__Bottom00);
     tolua_function(tolua_S,"Clear",tolua_GUI_GUI_types_TCoord_int__Clear00);
     tolua_function(tolua_S,"Set",tolua_GUI_GUI_types_TCoord_int__Set00);
     tolua_function(tolua_S,"Swap",tolua_GUI_GUI_types_TCoord_int__Swap00);
     tolua_function(tolua_S,"Empty",tolua_GUI_GUI_types_TCoord_int__Empty00);
     tolua_function(tolua_S,"Point",tolua_GUI_GUI_types_TCoord_int__Point00);
     tolua_function(tolua_S,"Size",tolua_GUI_GUI_types_TCoord_int__Size00);
     tolua_function(tolua_S,"Inside",tolua_GUI_GUI_types_TCoord_int__Inside00);
     tolua_function(tolua_S,"Print",tolua_GUI_GUI_types_TCoord_int__Print00);
     tolua_function(tolua_S,"Parse",tolua_GUI_GUI_types_TCoord_int__Parse00);
    tolua_endmodule(tolua_S);
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"TCoord_float_","GUI::types::TCoord<float>","",tolua_collect_GUI__types__TCoord_float_);
    #else
    tolua_cclass(tolua_S,"TCoord_float_","GUI::types::TCoord<float>","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"TCoord_float_");
     tolua_variable(tolua_S,"left",tolua_get_GUI__types__TCoord_float__left,tolua_set_GUI__types__TCoord_float__left);
     tolua_variable(tolua_S,"top",tolua_get_GUI__types__TCoord_float__top,tolua_set_GUI__types__TCoord_float__top);
     tolua_variable(tolua_S,"width",tolua_get_GUI__types__TCoord_float__width,tolua_set_GUI__types__TCoord_float__width);
     tolua_variable(tolua_S,"height",tolua_get_GUI__types__TCoord_float__height,tolua_set_GUI__types__TCoord_float__height);
     tolua_function(tolua_S,"new",tolua_GUI_GUI_types_TCoord_float__new00);
     tolua_function(tolua_S,"new_local",tolua_GUI_GUI_types_TCoord_float__new00_local);
     tolua_function(tolua_S,".call",tolua_GUI_GUI_types_TCoord_float__new00_local);
     tolua_function(tolua_S,"new",tolua_GUI_GUI_types_TCoord_float__new01);
     tolua_function(tolua_S,"new_local",tolua_GUI_GUI_types_TCoord_float__new01_local);
     tolua_function(tolua_S,".call",tolua_GUI_GUI_types_TCoord_float__new01_local);
     tolua_function(tolua_S,"new",tolua_GUI_GUI_types_TCoord_float__new02);
     tolua_function(tolua_S,"new_local",tolua_GUI_GUI_types_TCoord_float__new02_local);
     tolua_function(tolua_S,".call",tolua_GUI_GUI_types_TCoord_float__new02_local);
     tolua_function(tolua_S,"new",tolua_GUI_GUI_types_TCoord_float__new03);
     tolua_function(tolua_S,"new_local",tolua_GUI_GUI_types_TCoord_float__new03_local);
     tolua_function(tolua_S,".call",tolua_GUI_GUI_types_TCoord_float__new03_local);
     tolua_function(tolua_S,".sub",tolua_GUI_GUI_types_TCoord_float___sub00);
     tolua_function(tolua_S,".sub",tolua_GUI_GUI_types_TCoord_float___sub01);
     tolua_function(tolua_S,".sub",tolua_GUI_GUI_types_TCoord_float___sub02);
     tolua_function(tolua_S,".add",tolua_GUI_GUI_types_TCoord_float___add00);
     tolua_function(tolua_S,".add",tolua_GUI_GUI_types_TCoord_float___add01);
     tolua_function(tolua_S,".add",tolua_GUI_GUI_types_TCoord_float___add02);
     tolua_function(tolua_S,".eq",tolua_GUI_GUI_types_TCoord_float___eq00);
     tolua_function(tolua_S,"Right",tolua_GUI_GUI_types_TCoord_float__Right00);
     tolua_function(tolua_S,"Bottom",tolua_GUI_GUI_types_TCoord_float__Bottom00);
     tolua_function(tolua_S,"Clear",tolua_GUI_GUI_types_TCoord_float__Clear00);
     tolua_function(tolua_S,"Set",tolua_GUI_GUI_types_TCoord_float__Set00);
     tolua_function(tolua_S,"Swap",tolua_GUI_GUI_types_TCoord_float__Swap00);
     tolua_function(tolua_S,"Empty",tolua_GUI_GUI_types_TCoord_float__Empty00);
     tolua_function(tolua_S,"Point",tolua_GUI_GUI_types_TCoord_float__Point00);
     tolua_function(tolua_S,"Size",tolua_GUI_GUI_types_TCoord_float__Size00);
     tolua_function(tolua_S,"Inside",tolua_GUI_GUI_types_TCoord_float__Inside00);
     tolua_function(tolua_S,"Print",tolua_GUI_GUI_types_TCoord_float__Print00);
     tolua_function(tolua_S,"Parse",tolua_GUI_GUI_types_TCoord_float__Parse00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_module(tolua_S,"types",0);
   tolua_beginmodule(tolua_S,"types");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"TPoint_int_","GUI::types::TPoint<int>","",tolua_collect_GUI__types__TPoint_int_);
    #else
    tolua_cclass(tolua_S,"TPoint_int_","GUI::types::TPoint<int>","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"TPoint_int_");
     tolua_variable(tolua_S,"left",tolua_get_GUI__types__TPoint_int__left,tolua_set_GUI__types__TPoint_int__left);
     tolua_variable(tolua_S,"top",tolua_get_GUI__types__TPoint_int__top,tolua_set_GUI__types__TPoint_int__top);
     tolua_function(tolua_S,"new",tolua_GUI_GUI_types_TPoint_int__new00);
     tolua_function(tolua_S,"new_local",tolua_GUI_GUI_types_TPoint_int__new00_local);
     tolua_function(tolua_S,".call",tolua_GUI_GUI_types_TPoint_int__new00_local);
     tolua_function(tolua_S,"new",tolua_GUI_GUI_types_TPoint_int__new01);
     tolua_function(tolua_S,"new_local",tolua_GUI_GUI_types_TPoint_int__new01_local);
     tolua_function(tolua_S,".call",tolua_GUI_GUI_types_TPoint_int__new01_local);
     tolua_function(tolua_S,"new",tolua_GUI_GUI_types_TPoint_int__new02);
     tolua_function(tolua_S,"new_local",tolua_GUI_GUI_types_TPoint_int__new02_local);
     tolua_function(tolua_S,".call",tolua_GUI_GUI_types_TPoint_int__new02_local);
     tolua_function(tolua_S,".sub",tolua_GUI_GUI_types_TPoint_int___sub00);
     tolua_function(tolua_S,".add",tolua_GUI_GUI_types_TPoint_int___add00);
     tolua_function(tolua_S,".eq",tolua_GUI_GUI_types_TPoint_int___eq00);
     tolua_function(tolua_S,"Clear",tolua_GUI_GUI_types_TPoint_int__Clear00);
     tolua_function(tolua_S,"Set",tolua_GUI_GUI_types_TPoint_int__Set00);
     tolua_function(tolua_S,"Swap",tolua_GUI_GUI_types_TPoint_int__Swap00);
     tolua_function(tolua_S,"Empty",tolua_GUI_GUI_types_TPoint_int__Empty00);
     tolua_function(tolua_S,"Print",tolua_GUI_GUI_types_TPoint_int__Print00);
     tolua_function(tolua_S,"Parse",tolua_GUI_GUI_types_TPoint_int__Parse00);
    tolua_endmodule(tolua_S);
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"TPoint_float_","GUI::types::TPoint<float>","",tolua_collect_GUI__types__TPoint_float_);
    #else
    tolua_cclass(tolua_S,"TPoint_float_","GUI::types::TPoint<float>","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"TPoint_float_");
     tolua_variable(tolua_S,"left",tolua_get_GUI__types__TPoint_float__left,tolua_set_GUI__types__TPoint_float__left);
     tolua_variable(tolua_S,"top",tolua_get_GUI__types__TPoint_float__top,tolua_set_GUI__types__TPoint_float__top);
     tolua_function(tolua_S,"new",tolua_GUI_GUI_types_TPoint_float__new00);
     tolua_function(tolua_S,"new_local",tolua_GUI_GUI_types_TPoint_float__new00_local);
     tolua_function(tolua_S,".call",tolua_GUI_GUI_types_TPoint_float__new00_local);
     tolua_function(tolua_S,"new",tolua_GUI_GUI_types_TPoint_float__new01);
     tolua_function(tolua_S,"new_local",tolua_GUI_GUI_types_TPoint_float__new01_local);
     tolua_function(tolua_S,".call",tolua_GUI_GUI_types_TPoint_float__new01_local);
     tolua_function(tolua_S,"new",tolua_GUI_GUI_types_TPoint_float__new02);
     tolua_function(tolua_S,"new_local",tolua_GUI_GUI_types_TPoint_float__new02_local);
     tolua_function(tolua_S,".call",tolua_GUI_GUI_types_TPoint_float__new02_local);
     tolua_function(tolua_S,".sub",tolua_GUI_GUI_types_TPoint_float___sub00);
     tolua_function(tolua_S,".add",tolua_GUI_GUI_types_TPoint_float___add00);
     tolua_function(tolua_S,".eq",tolua_GUI_GUI_types_TPoint_float___eq00);
     tolua_function(tolua_S,"Clear",tolua_GUI_GUI_types_TPoint_float__Clear00);
     tolua_function(tolua_S,"Set",tolua_GUI_GUI_types_TPoint_float__Set00);
     tolua_function(tolua_S,"Swap",tolua_GUI_GUI_types_TPoint_float__Swap00);
     tolua_function(tolua_S,"Empty",tolua_GUI_GUI_types_TPoint_float__Empty00);
     tolua_function(tolua_S,"Print",tolua_GUI_GUI_types_TPoint_float__Print00);
     tolua_function(tolua_S,"Parse",tolua_GUI_GUI_types_TPoint_float__Parse00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_module(tolua_S,"types",0);
   tolua_beginmodule(tolua_S,"types");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"TRect_int_","GUI::types::TRect<int>","",tolua_collect_GUI__types__TRect_int_);
    #else
    tolua_cclass(tolua_S,"TRect_int_","GUI::types::TRect<int>","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"TRect_int_");
     tolua_variable(tolua_S,"left",tolua_get_GUI__types__TRect_int__left,tolua_set_GUI__types__TRect_int__left);
     tolua_variable(tolua_S,"top",tolua_get_GUI__types__TRect_int__top,tolua_set_GUI__types__TRect_int__top);
     tolua_variable(tolua_S,"right",tolua_get_GUI__types__TRect_int__right,tolua_set_GUI__types__TRect_int__right);
     tolua_variable(tolua_S,"bottom",tolua_get_GUI__types__TRect_int__bottom,tolua_set_GUI__types__TRect_int__bottom);
     tolua_function(tolua_S,"new",tolua_GUI_GUI_types_TRect_int__new00);
     tolua_function(tolua_S,"new_local",tolua_GUI_GUI_types_TRect_int__new00_local);
     tolua_function(tolua_S,".call",tolua_GUI_GUI_types_TRect_int__new00_local);
     tolua_function(tolua_S,"new",tolua_GUI_GUI_types_TRect_int__new01);
     tolua_function(tolua_S,"new_local",tolua_GUI_GUI_types_TRect_int__new01_local);
     tolua_function(tolua_S,".call",tolua_GUI_GUI_types_TRect_int__new01_local);
     tolua_function(tolua_S,"new",tolua_GUI_GUI_types_TRect_int__new02);
     tolua_function(tolua_S,"new_local",tolua_GUI_GUI_types_TRect_int__new02_local);
     tolua_function(tolua_S,".call",tolua_GUI_GUI_types_TRect_int__new02_local);
     tolua_function(tolua_S,".sub",tolua_GUI_GUI_types_TRect_int___sub00);
     tolua_function(tolua_S,".add",tolua_GUI_GUI_types_TRect_int___add00);
     tolua_function(tolua_S,".eq",tolua_GUI_GUI_types_TRect_int___eq00);
     tolua_function(tolua_S,"Width",tolua_GUI_GUI_types_TRect_int__Width00);
     tolua_function(tolua_S,"Height",tolua_GUI_GUI_types_TRect_int__Height00);
     tolua_function(tolua_S,"Clear",tolua_GUI_GUI_types_TRect_int__Clear00);
     tolua_function(tolua_S,"Set",tolua_GUI_GUI_types_TRect_int__Set00);
     tolua_function(tolua_S,"Swap",tolua_GUI_GUI_types_TRect_int__Swap00);
     tolua_function(tolua_S,"Empty",tolua_GUI_GUI_types_TRect_int__Empty00);
     tolua_function(tolua_S,"Inside",tolua_GUI_GUI_types_TRect_int__Inside00);
     tolua_function(tolua_S,"Intersect",tolua_GUI_GUI_types_TRect_int__Intersect00);
     tolua_function(tolua_S,"Inside",tolua_GUI_GUI_types_TRect_int__Inside01);
     tolua_function(tolua_S,"Print",tolua_GUI_GUI_types_TRect_int__Print00);
     tolua_function(tolua_S,"Parse",tolua_GUI_GUI_types_TRect_int__Parse00);
    tolua_endmodule(tolua_S);
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"TRect_float_","GUI::types::TRect<float>","",tolua_collect_GUI__types__TRect_float_);
    #else
    tolua_cclass(tolua_S,"TRect_float_","GUI::types::TRect<float>","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"TRect_float_");
     tolua_variable(tolua_S,"left",tolua_get_GUI__types__TRect_float__left,tolua_set_GUI__types__TRect_float__left);
     tolua_variable(tolua_S,"top",tolua_get_GUI__types__TRect_float__top,tolua_set_GUI__types__TRect_float__top);
     tolua_variable(tolua_S,"right",tolua_get_GUI__types__TRect_float__right,tolua_set_GUI__types__TRect_float__right);
     tolua_variable(tolua_S,"bottom",tolua_get_GUI__types__TRect_float__bottom,tolua_set_GUI__types__TRect_float__bottom);
     tolua_function(tolua_S,"new",tolua_GUI_GUI_types_TRect_float__new00);
     tolua_function(tolua_S,"new_local",tolua_GUI_GUI_types_TRect_float__new00_local);
     tolua_function(tolua_S,".call",tolua_GUI_GUI_types_TRect_float__new00_local);
     tolua_function(tolua_S,"new",tolua_GUI_GUI_types_TRect_float__new01);
     tolua_function(tolua_S,"new_local",tolua_GUI_GUI_types_TRect_float__new01_local);
     tolua_function(tolua_S,".call",tolua_GUI_GUI_types_TRect_float__new01_local);
     tolua_function(tolua_S,"new",tolua_GUI_GUI_types_TRect_float__new02);
     tolua_function(tolua_S,"new_local",tolua_GUI_GUI_types_TRect_float__new02_local);
     tolua_function(tolua_S,".call",tolua_GUI_GUI_types_TRect_float__new02_local);
     tolua_function(tolua_S,".sub",tolua_GUI_GUI_types_TRect_float___sub00);
     tolua_function(tolua_S,".add",tolua_GUI_GUI_types_TRect_float___add00);
     tolua_function(tolua_S,".eq",tolua_GUI_GUI_types_TRect_float___eq00);
     tolua_function(tolua_S,"Width",tolua_GUI_GUI_types_TRect_float__Width00);
     tolua_function(tolua_S,"Height",tolua_GUI_GUI_types_TRect_float__Height00);
     tolua_function(tolua_S,"Clear",tolua_GUI_GUI_types_TRect_float__Clear00);
     tolua_function(tolua_S,"Set",tolua_GUI_GUI_types_TRect_float__Set00);
     tolua_function(tolua_S,"Swap",tolua_GUI_GUI_types_TRect_float__Swap00);
     tolua_function(tolua_S,"Empty",tolua_GUI_GUI_types_TRect_float__Empty00);
     tolua_function(tolua_S,"Inside",tolua_GUI_GUI_types_TRect_float__Inside00);
     tolua_function(tolua_S,"Intersect",tolua_GUI_GUI_types_TRect_float__Intersect00);
     tolua_function(tolua_S,"Inside",tolua_GUI_GUI_types_TRect_float__Inside01);
     tolua_function(tolua_S,"Print",tolua_GUI_GUI_types_TRect_float__Print00);
     tolua_function(tolua_S,"Parse",tolua_GUI_GUI_types_TRect_float__Parse00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_module(tolua_S,"types",0);
   tolua_beginmodule(tolua_S,"types");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"TSize_int_","GUI::types::TSize<int>","",tolua_collect_GUI__types__TSize_int_);
    #else
    tolua_cclass(tolua_S,"TSize_int_","GUI::types::TSize<int>","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"TSize_int_");
     tolua_variable(tolua_S,"width",tolua_get_GUI__types__TSize_int__width,tolua_set_GUI__types__TSize_int__width);
     tolua_variable(tolua_S,"height",tolua_get_GUI__types__TSize_int__height,tolua_set_GUI__types__TSize_int__height);
     tolua_function(tolua_S,"new",tolua_GUI_GUI_types_TSize_int__new00);
     tolua_function(tolua_S,"new_local",tolua_GUI_GUI_types_TSize_int__new00_local);
     tolua_function(tolua_S,".call",tolua_GUI_GUI_types_TSize_int__new00_local);
     tolua_function(tolua_S,"new",tolua_GUI_GUI_types_TSize_int__new01);
     tolua_function(tolua_S,"new_local",tolua_GUI_GUI_types_TSize_int__new01_local);
     tolua_function(tolua_S,".call",tolua_GUI_GUI_types_TSize_int__new01_local);
     tolua_function(tolua_S,"new",tolua_GUI_GUI_types_TSize_int__new02);
     tolua_function(tolua_S,"new_local",tolua_GUI_GUI_types_TSize_int__new02_local);
     tolua_function(tolua_S,".call",tolua_GUI_GUI_types_TSize_int__new02_local);
     tolua_function(tolua_S,".sub",tolua_GUI_GUI_types_TSize_int___sub00);
     tolua_function(tolua_S,".add",tolua_GUI_GUI_types_TSize_int___add00);
     tolua_function(tolua_S,".eq",tolua_GUI_GUI_types_TSize_int___eq00);
     tolua_function(tolua_S,"Clear",tolua_GUI_GUI_types_TSize_int__Clear00);
     tolua_function(tolua_S,"Set",tolua_GUI_GUI_types_TSize_int__Set00);
     tolua_function(tolua_S,"Swap",tolua_GUI_GUI_types_TSize_int__Swap00);
     tolua_function(tolua_S,"Empty",tolua_GUI_GUI_types_TSize_int__Empty00);
     tolua_function(tolua_S,"Print",tolua_GUI_GUI_types_TSize_int__Print00);
     tolua_function(tolua_S,"Parse",tolua_GUI_GUI_types_TSize_int__Parse00);
    tolua_endmodule(tolua_S);
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"TSize_float_","GUI::types::TSize<float>","",tolua_collect_GUI__types__TSize_float_);
    #else
    tolua_cclass(tolua_S,"TSize_float_","GUI::types::TSize<float>","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"TSize_float_");
     tolua_variable(tolua_S,"width",tolua_get_GUI__types__TSize_float__width,tolua_set_GUI__types__TSize_float__width);
     tolua_variable(tolua_S,"height",tolua_get_GUI__types__TSize_float__height,tolua_set_GUI__types__TSize_float__height);
     tolua_function(tolua_S,"new",tolua_GUI_GUI_types_TSize_float__new00);
     tolua_function(tolua_S,"new_local",tolua_GUI_GUI_types_TSize_float__new00_local);
     tolua_function(tolua_S,".call",tolua_GUI_GUI_types_TSize_float__new00_local);
     tolua_function(tolua_S,"new",tolua_GUI_GUI_types_TSize_float__new01);
     tolua_function(tolua_S,"new_local",tolua_GUI_GUI_types_TSize_float__new01_local);
     tolua_function(tolua_S,".call",tolua_GUI_GUI_types_TSize_float__new01_local);
     tolua_function(tolua_S,"new",tolua_GUI_GUI_types_TSize_float__new02);
     tolua_function(tolua_S,"new_local",tolua_GUI_GUI_types_TSize_float__new02_local);
     tolua_function(tolua_S,".call",tolua_GUI_GUI_types_TSize_float__new02_local);
     tolua_function(tolua_S,".sub",tolua_GUI_GUI_types_TSize_float___sub00);
     tolua_function(tolua_S,".add",tolua_GUI_GUI_types_TSize_float___add00);
     tolua_function(tolua_S,".eq",tolua_GUI_GUI_types_TSize_float___eq00);
     tolua_function(tolua_S,"Clear",tolua_GUI_GUI_types_TSize_float__Clear00);
     tolua_function(tolua_S,"Set",tolua_GUI_GUI_types_TSize_float__Set00);
     tolua_function(tolua_S,"Swap",tolua_GUI_GUI_types_TSize_float__Swap00);
     tolua_function(tolua_S,"Empty",tolua_GUI_GUI_types_TSize_float__Empty00);
     tolua_function(tolua_S,"Print",tolua_GUI_GUI_types_TSize_float__Print00);
     tolua_function(tolua_S,"Parse",tolua_GUI_GUI_types_TSize_float__Parse00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"UIScriptObject","GUI::UIScriptObject","CScriptObject",NULL);
   tolua_beginmodule(tolua_S,"UIScriptObject");
    tolua_function(tolua_S,"IsScriptObjValid",tolua_GUI_GUI_UIScriptObject_IsScriptObjValid00);
    tolua_function(tolua_S,"GetScriptObjID",tolua_GUI_GUI_UIScriptObject_GetScriptObjID00);
    tolua_function(tolua_S,"SetScriptObjID",tolua_GUI_GUI_UIScriptObject_SetScriptObjID00);
    tolua_function(tolua_S,"CreateScriptObj",tolua_GUI_GUI_UIScriptObject_CreateScriptObj00);
    tolua_function(tolua_S,"SetScriptClass",tolua_GUI_GUI_UIScriptObject_SetScriptClass00);
    tolua_function(tolua_S,"GetScriptClass",tolua_GUI_GUI_UIScriptObject_GetScriptClass00);
    tolua_variable(tolua_S,"__WidgetEvent__",tolua_get_GUI__UIScriptObject___WidgetEvent__,NULL);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"UString","GUI::UString","",tolua_collect_GUI__UString);
   #else
   tolua_cclass(tolua_S,"UString","GUI::UString","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"UString");
    tolua_function(tolua_S,"new",tolua_GUI_GUI_UString_new00);
    tolua_function(tolua_S,"new_local",tolua_GUI_GUI_UString_new00_local);
    tolua_function(tolua_S,".call",tolua_GUI_GUI_UString_new00_local);
    tolua_function(tolua_S,"new",tolua_GUI_GUI_UString_new01);
    tolua_function(tolua_S,"new_local",tolua_GUI_GUI_UString_new01_local);
    tolua_function(tolua_S,".call",tolua_GUI_GUI_UString_new01_local);
    tolua_function(tolua_S,"delete",tolua_GUI_GUI_UString_delete00);
    tolua_function(tolua_S,"size",tolua_GUI_GUI_UString_size00);
    tolua_function(tolua_S,"max_size",tolua_GUI_GUI_UString_max_size00);
    tolua_function(tolua_S,"reserve",tolua_GUI_GUI_UString_reserve00);
    tolua_function(tolua_S,"resize",tolua_GUI_GUI_UString_resize00);
    tolua_function(tolua_S,"resize",tolua_GUI_GUI_UString_resize01);
    tolua_function(tolua_S,"swap",tolua_GUI_GUI_UString_swap00);
    tolua_function(tolua_S,"empty",tolua_GUI_GUI_UString_empty00);
    tolua_function(tolua_S,"clear",tolua_GUI_GUI_UString_clear00);
    tolua_function(tolua_S,"substr",tolua_GUI_GUI_UString_substr00);
    tolua_function(tolua_S,"substr",tolua_GUI_GUI_UString_substr01);
    tolua_function(tolua_S,"push_back",tolua_GUI_GUI_UString_push_back00);
    tolua_function(tolua_S,"AsUTF8_c_str",tolua_GUI_GUI_UString_AsUTF8_c_str00);
    tolua_function(tolua_S,"append",tolua_GUI_GUI_UString_append00);
    tolua_function(tolua_S,"append",tolua_GUI_GUI_UString_append01);
    tolua_function(tolua_S,"compare",tolua_GUI_GUI_UString_compare00);
    tolua_function(tolua_S,"compare",tolua_GUI_GUI_UString_compare01);
    tolua_function(tolua_S,"find",tolua_GUI_GUI_UString_find00);
    tolua_function(tolua_S,"rfind",tolua_GUI_GUI_UString_rfind00);
    tolua_function(tolua_S,".seti",tolua_GUI_GUI_UString__seti00);
    tolua_function(tolua_S,".geti",tolua_GUI_GUI_UString__geti00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"VScroll","GUI::VScroll","GUI::Widget",NULL);
   tolua_beginmodule(tolua_S,"VScroll");
    tolua_function(tolua_S,"SetScrollRange",tolua_GUI_GUI_VScroll_SetScrollRange00);
    tolua_function(tolua_S,"GetScrollRange",tolua_GUI_GUI_VScroll_GetScrollRange00);
    tolua_function(tolua_S,"SetScrollPosition",tolua_GUI_GUI_VScroll_SetScrollPosition00);
    tolua_function(tolua_S,"GetScrollPosition",tolua_GUI_GUI_VScroll_GetScrollPosition00);
    tolua_function(tolua_S,"SetScrollPage",tolua_GUI_GUI_VScroll_SetScrollPage00);
    tolua_function(tolua_S,"GetScrollPage",tolua_GUI_GUI_VScroll_GetScrollPage00);
    tolua_function(tolua_S,"SetScrollViewPage",tolua_GUI_GUI_VScroll_SetScrollViewPage00);
    tolua_function(tolua_S,"GetScrollViewPage",tolua_GUI_GUI_VScroll_GetScrollViewPage00);
    tolua_function(tolua_S,"GetLineSize",tolua_GUI_GUI_VScroll_GetLineSize00);
    tolua_function(tolua_S,"SetTrackSize",tolua_GUI_GUI_VScroll_SetTrackSize00);
    tolua_function(tolua_S,"GetTrackSize",tolua_GUI_GUI_VScroll_GetTrackSize00);
    tolua_function(tolua_S,"SetMinTrackSize",tolua_GUI_GUI_VScroll_SetMinTrackSize00);
    tolua_function(tolua_S,"GetMinTrackSize",tolua_GUI_GUI_VScroll_GetMinTrackSize00);
    tolua_function(tolua_S,"SetMoveToClick",tolua_GUI_GUI_VScroll_SetMoveToClick00);
    tolua_function(tolua_S,"GetMoveToClick",tolua_GUI_GUI_VScroll_GetMoveToClick00);
    tolua_function(tolua_S,"SetPosition",tolua_GUI_GUI_VScroll_SetPosition00);
    tolua_function(tolua_S,"SetSize",tolua_GUI_GUI_VScroll_SetSize00);
    tolua_function(tolua_S,"SetCoord",tolua_GUI_GUI_VScroll_SetCoord00);
    tolua_function(tolua_S,"SetProperty",tolua_GUI_GUI_VScroll_SetProperty00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"Widget","GUI::Widget","GUI::UIScriptObject",NULL);
   tolua_beginmodule(tolua_S,"Widget");
    tolua_function(tolua_S,"CreateWidgetT",tolua_GUI_GUI_Widget_CreateWidgetT00);
    tolua_function(tolua_S,"CreateWidgetT",tolua_GUI_GUI_Widget_CreateWidgetT01);
    tolua_function(tolua_S,"CreateWidgetRealT",tolua_GUI_GUI_Widget_CreateWidgetRealT00);
    tolua_function(tolua_S,"CreateWidgetRealT",tolua_GUI_GUI_Widget_CreateWidgetRealT01);
    tolua_function(tolua_S,"GetName",tolua_GUI_GUI_Widget_GetName00);
    tolua_function(tolua_S,"SetPosition",tolua_GUI_GUI_Widget_SetPosition00);
    tolua_function(tolua_S,"SetSize",tolua_GUI_GUI_Widget_SetSize00);
    tolua_function(tolua_S,"SetCoord",tolua_GUI_GUI_Widget_SetCoord00);
    tolua_function(tolua_S,"SetRealPosition",tolua_GUI_GUI_Widget_SetRealPosition00);
    tolua_function(tolua_S,"SetRealSize",tolua_GUI_GUI_Widget_SetRealSize00);
    tolua_function(tolua_S,"SetRealCoord",tolua_GUI_GUI_Widget_SetRealCoord00);
    tolua_function(tolua_S,"SetVisible",tolua_GUI_GUI_Widget_SetVisible00);
    tolua_function(tolua_S,"SetAlign",tolua_GUI_GUI_Widget_SetAlign00);
    tolua_function(tolua_S,"SetCaption",tolua_GUI_GUI_Widget_SetCaption00);
    tolua_function(tolua_S,"GetCaption",tolua_GUI_GUI_Widget_GetCaption00);
    tolua_function(tolua_S,"SetAlpha",tolua_GUI_GUI_Widget_SetAlpha00);
    tolua_function(tolua_S,"GetAlpha",tolua_GUI_GUI_Widget_GetAlpha00);
    tolua_function(tolua_S,"SetInheritsAlpha",tolua_GUI_GUI_Widget_SetInheritsAlpha00);
    tolua_function(tolua_S,"IsInheritsAlpha",tolua_GUI_GUI_Widget_IsInheritsAlpha00);
    tolua_function(tolua_S,"SetState",tolua_GUI_GUI_Widget_SetState00);
    tolua_function(tolua_S,"SetColour",tolua_GUI_GUI_Widget_SetColour00);
    tolua_function(tolua_S,"IsRootWidget",tolua_GUI_GUI_Widget_IsRootWidget00);
    tolua_function(tolua_S,"GetParent",tolua_GUI_GUI_Widget_GetParent00);
    tolua_function(tolua_S,"GetChildCount",tolua_GUI_GUI_Widget_GetChildCount00);
    tolua_function(tolua_S,"GetChildAt",tolua_GUI_GUI_Widget_GetChildAt00);
    tolua_function(tolua_S,"FindWidget",tolua_GUI_GUI_Widget_FindWidget00);
    tolua_function(tolua_S,"SetNeedKeyFocus",tolua_GUI_GUI_Widget_SetNeedKeyFocus00);
    tolua_function(tolua_S,"IsNeedKeyFocus",tolua_GUI_GUI_Widget_IsNeedKeyFocus00);
    tolua_function(tolua_S,"SetNeedMouseFocus",tolua_GUI_GUI_Widget_SetNeedMouseFocus00);
    tolua_function(tolua_S,"IsNeedMouseFocus",tolua_GUI_GUI_Widget_IsNeedMouseFocus00);
    tolua_function(tolua_S,"SetInheritsPick",tolua_GUI_GUI_Widget_SetInheritsPick00);
    tolua_function(tolua_S,"IsInheritsPick",tolua_GUI_GUI_Widget_IsInheritsPick00);
    tolua_function(tolua_S,"SetMaskPick",tolua_GUI_GUI_Widget_SetMaskPick00);
    tolua_function(tolua_S,"SetEnabled",tolua_GUI_GUI_Widget_SetEnabled00);
    tolua_function(tolua_S,"SetEnabledSilent",tolua_GUI_GUI_Widget_SetEnabledSilent00);
    tolua_function(tolua_S,"IsEnabled",tolua_GUI_GUI_Widget_IsEnabled00);
    tolua_function(tolua_S,"SetPointer",tolua_GUI_GUI_Widget_SetPointer00);
    tolua_function(tolua_S,"GetPointer",tolua_GUI_GUI_Widget_GetPointer00);
    tolua_function(tolua_S,"GetLayerName",tolua_GUI_GUI_Widget_GetLayerName00);
    tolua_function(tolua_S,"GetClientWidget",tolua_GUI_GUI_Widget_GetClientWidget00);
    tolua_function(tolua_S,"SetNeedToolTip",tolua_GUI_GUI_Widget_SetNeedToolTip00);
    tolua_function(tolua_S,"GetNeedToolTip",tolua_GUI_GUI_Widget_GetNeedToolTip00);
    tolua_function(tolua_S,"SetEnableToolTip",tolua_GUI_GUI_Widget_SetEnableToolTip00);
    tolua_function(tolua_S,"GetEnableToolTip",tolua_GUI_GUI_Widget_GetEnableToolTip00);
    tolua_function(tolua_S,"DetachFromWidget",tolua_GUI_GUI_Widget_DetachFromWidget00);
    tolua_function(tolua_S,"DetachFromWidget",tolua_GUI_GUI_Widget_DetachFromWidget01);
    tolua_function(tolua_S,"AttachToWidget",tolua_GUI_GUI_Widget_AttachToWidget00);
    tolua_function(tolua_S,"AttachToWidget",tolua_GUI_GUI_Widget_AttachToWidget01);
    tolua_function(tolua_S,"ChangeWidgetSkin",tolua_GUI_GUI_Widget_ChangeWidgetSkin00);
    tolua_function(tolua_S,"SetWidgetStyle",tolua_GUI_GUI_Widget_SetWidgetStyle00);
    tolua_function(tolua_S,"SetWidgetStyle",tolua_GUI_GUI_Widget_SetWidgetStyle01);
    tolua_function(tolua_S,"GetWidgetStyle",tolua_GUI_GUI_Widget_GetWidgetStyle00);
    tolua_function(tolua_S,"SetProperty",tolua_GUI_GUI_Widget_SetProperty00);
    tolua_function(tolua_S,"SetCaptionWithNewLine",tolua_GUI_GUI_Widget_SetCaptionWithNewLine00);
    tolua_function(tolua_S,"GetTextCoord",tolua_GUI_GUI_Widget_GetTextCoord00);
    tolua_function(tolua_S,"GetTextSize",tolua_GUI_GUI_Widget_GetTextSize00);
    tolua_function(tolua_S,"SetFontName",tolua_GUI_GUI_Widget_SetFontName00);
    tolua_function(tolua_S,"GetFontName",tolua_GUI_GUI_Widget_GetFontName00);
    tolua_function(tolua_S,"SetFontHeight",tolua_GUI_GUI_Widget_SetFontHeight00);
    tolua_function(tolua_S,"GetFontHeight",tolua_GUI_GUI_Widget_GetFontHeight00);
    tolua_function(tolua_S,"SetTextAlign",tolua_GUI_GUI_Widget_SetTextAlign00);
    tolua_function(tolua_S,"GetTextAlign",tolua_GUI_GUI_Widget_GetTextAlign00);
    tolua_function(tolua_S,"SetTextColour",tolua_GUI_GUI_Widget_SetTextColour00);
    tolua_function(tolua_S,"GetTextColour",tolua_GUI_GUI_Widget_GetTextColour00);
    tolua_variable(tolua_S,"__IObject__",tolua_get_GUI__Widget___IObject__,NULL);
    tolua_variable(tolua_S,"__ICroppedRectangle__",tolua_get_GUI__Widget___ICroppedRectangle__,NULL);
    tolua_variable(tolua_S,"__LayerItem__",tolua_get_GUI__Widget___LayerItem__,NULL);
    tolua_variable(tolua_S,"__UserData__",tolua_get_GUI__Widget___UserData__,NULL);
    tolua_variable(tolua_S,"__IWidgetCreator__",tolua_get_GUI__Widget___IWidgetCreator__,NULL);
    tolua_variable(tolua_S,"__delegates__IDelegateUnlink__",tolua_get_GUI__Widget___delegates__IDelegateUnlink__,NULL);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"VectorWidgetPtr","GUI::VectorWidgetPtr","std::vector<GUI::Widget*>",NULL);
   tolua_beginmodule(tolua_S,"VectorWidgetPtr");
    tolua_function(tolua_S,"Size",tolua_GUI_GUI_VectorWidgetPtr_Size00);
    tolua_function(tolua_S,".seti",tolua_GUI_GUI_VectorWidgetPtr__seti00);
    tolua_function(tolua_S,".geti",tolua_GUI_GUI_VectorWidgetPtr__geti00);
    tolua_function(tolua_S,"Resize",tolua_GUI_GUI_VectorWidgetPtr_Resize00);
    tolua_function(tolua_S,"Reserve",tolua_GUI_GUI_VectorWidgetPtr_Reserve00);
    tolua_function(tolua_S,"Clear",tolua_GUI_GUI_VectorWidgetPtr_Clear00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"WidgetStyle","GUI::WidgetStyle","",tolua_collect_GUI__WidgetStyle);
   #else
   tolua_cclass(tolua_S,"WidgetStyle","GUI::WidgetStyle","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"WidgetStyle");
    tolua_constant(tolua_S,"Child",GUI::WidgetStyle::Child);
    tolua_constant(tolua_S,"Popup",GUI::WidgetStyle::Popup);
    tolua_constant(tolua_S,"Overlapped",GUI::WidgetStyle::Overlapped);
    tolua_constant(tolua_S,"MAX",GUI::WidgetStyle::MAX);
    tolua_function(tolua_S,"Parse",tolua_GUI_GUI_WidgetStyle_Parse00);
    tolua_function(tolua_S,"new",tolua_GUI_GUI_WidgetStyle_new00);
    tolua_function(tolua_S,"new_local",tolua_GUI_GUI_WidgetStyle_new00_local);
    tolua_function(tolua_S,".call",tolua_GUI_GUI_WidgetStyle_new00_local);
    tolua_function(tolua_S,"new",tolua_GUI_GUI_WidgetStyle_new01);
    tolua_function(tolua_S,"new_local",tolua_GUI_GUI_WidgetStyle_new01_local);
    tolua_function(tolua_S,".call",tolua_GUI_GUI_WidgetStyle_new01_local);
    tolua_function(tolua_S,"Print",tolua_GUI_GUI_WidgetStyle_Print00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"UserData","GUI::UserData","",NULL);
   tolua_beginmodule(tolua_S,"UserData");
    tolua_function(tolua_S,"SetUserString",tolua_GUI_GUI_UserData_SetUserString00);
    tolua_function(tolua_S,"GetUserString",tolua_GUI_GUI_UserData_GetUserString00);
    tolua_function(tolua_S,"ClearUserString",tolua_GUI_GUI_UserData_ClearUserString00);
    tolua_function(tolua_S,"IsUserString",tolua_GUI_GUI_UserData_IsUserString00);
    tolua_function(tolua_S,"ClearUserStrings",tolua_GUI_GUI_UserData_ClearUserStrings00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"GUI",0);
  tolua_beginmodule(tolua_S,"GUI");
   tolua_cclass(tolua_S,"Window","GUI::Window","GUI::Widget",NULL);
   tolua_beginmodule(tolua_S,"Window");
    tolua_function(tolua_S,"SetVisible",tolua_GUI_GUI_Window_SetVisible00);
    tolua_function(tolua_S,"SetVisibleSmooth",tolua_GUI_GUI_Window_SetVisibleSmooth00);
    tolua_function(tolua_S,"DestroySmooth",tolua_GUI_GUI_Window_DestroySmooth00);
    tolua_function(tolua_S,"SetAutoAlpha",tolua_GUI_GUI_Window_SetAutoAlpha00);
    tolua_function(tolua_S,"GetAutoAlpha",tolua_GUI_GUI_Window_GetAutoAlpha00);
    tolua_function(tolua_S,"SetCaption",tolua_GUI_GUI_Window_SetCaption00);
    tolua_function(tolua_S,"GetCaption",tolua_GUI_GUI_Window_GetCaption00);
    tolua_function(tolua_S,"GetCaptionWidget",tolua_GUI_GUI_Window_GetCaptionWidget00);
    tolua_function(tolua_S,"SetMinSize",tolua_GUI_GUI_Window_SetMinSize00);
    tolua_function(tolua_S,"GetMinSize",tolua_GUI_GUI_Window_GetMinSize00);
    tolua_function(tolua_S,"SetMaxSize",tolua_GUI_GUI_Window_SetMaxSize00);
    tolua_function(tolua_S,"GetMaxSize",tolua_GUI_GUI_Window_GetMaxSize00);
    tolua_function(tolua_S,"SetPosition",tolua_GUI_GUI_Window_SetPosition00);
    tolua_function(tolua_S,"SetSize",tolua_GUI_GUI_Window_SetSize00);
    tolua_function(tolua_S,"SetCoord",tolua_GUI_GUI_Window_SetCoord00);
    tolua_function(tolua_S,"GetSnap",tolua_GUI_GUI_Window_GetSnap00);
    tolua_function(tolua_S,"SetSnap",tolua_GUI_GUI_Window_SetSnap00);
    tolua_function(tolua_S,"SetProperty",tolua_GUI_GUI_Window_SetProperty00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_GUI (lua_State* tolua_S) {
 return tolua_GUI_open(tolua_S);
};
#endif

