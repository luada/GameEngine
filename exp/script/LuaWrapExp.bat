echo off
rem set AutoWrapLuaApp=E:\GameDev\LuaTool\build\Bin\AutoWrapLua\Debug\AutoWrapLua.exe
set PrjName=script

set PrjHome=%PrjName%\
set SrcPath=inc\%PrjName%
set PkgOutPath=pkg\%PrjName%
set ExpCfgFilename=%PkgOutPath%\exportConfig.pkg
set LuaWrapFilename=exp\%PrjName%\LuaWrap.cpp
set MainPkgFilename=exp\%PrjName%\main.pkg
cd../..

%AutoWrapLuaApp% -SRC %SrcPath%  -HOME %PrjHome% -PKG_PATH  %PkgOutPath% -CFG %ExpCfgFilename% -TOLUA -n %PrjName% -o %LuaWrapFilename% %MainPkgFilename%
