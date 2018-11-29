#ifndef __PLATFORM_H__
#define __PLATFORM_H__

// Definnition of platforms
#define PLATFORM_WIN32		1
#define PLATFORM_LINUX		2
#define PLATFORM_APPLE		3

// Definition of compilers
#define COMPILER_MSVC 1
#define COMPILER_GNUC 2


// Find platform
#if defined (__WIN32__) || defined (_WIN32)
#	define PLATFORM PLATFORM_WIN32
#elif defined (__APPLE_CC__)
#	define PLATFORM PLATFORM_APPLE
#else
#	define PLATFORM PLATFORM_LINUX
#endif

// Find compiler
#if defined( _MSC_VER )
#	define COMPILER COMPILER_MSVC
#	define COMP_VER _MSC_VER

#elif defined( __GNUC__ )
#	define COMPILER COMPILER_GNUC
#	define COMP_VER (((__GNUC__)*100) + \
        (__GNUC_MINOR__*10) + \
        __GNUC_PATCHLEVEL__)
#else
#	pragma error "Unknown compiler! Stop building!!!"
#endif

// See if we can use __forceinline or if we need to use __inline instead
#if COMPILER == COMPILER_MSVC
#	if COMP_VER >= 1200
#		define FORCEINLINE __forceinline
#	endif
#elif defined(__MINGW32__)
#	if !defined(FORCEINLINE)
#		define FORCEINLINE __inline
#	endif
#else
#	define FORCEINLINE __inline
#endif


// Windows settings
#if PLATFORM == PLATFORM_WIN32
#
#	if defined( STATIC )
#		define GUI_EXPORT
#	elif defined( BUILD )
#		define GUI_EXPORT __declspec( dllGUI_EXPORT )
#	else
#		if defined( __MINGW32__ )
#			define GUI_EXPORT
#		else
#			define GUI_EXPORT __declspec( dllimport )
#		endif
#	endif
#
#	if defined( STATIC )
#		define GUI_EXPORT_DLL
#	elif defined( BUILD_DLL )
#		define GUI_EXPORT_DLL __declspec( dllGUI_EXPORT )
#	else
#		if defined( __MINGW32__ )
#			define GUI_EXPORT_DLL
#		else
#			define GUI_EXPORT_DLL __declspec( dllimport )
#		endif
#	endif
#
#// Win32 compilers use _DEBUG for specifying debug builds.
#	ifdef _DEBUG
#		define DEBUG_MODE 1
#	else
#		define DEBUG_MODE 0
#	endif
#endif


// Linux/Apple Settings
#if PLATFORM == PLATFORM_LINUX || PLATFORM == PLATFORM_APPLE
#
// Add -fvisibility=hidden to compiler options. With -fvisibility=hidden, you are telling
// GCC that every declaration not explicitly marked with a visibility Attribute (GUI_EXPORT)
// has a hidden Visibility (like in windows).
#	if __GNUC__ >= 4
#		define GUI_EXPORT  __attribute__ ((visibility("default")))
#	else
#		define GUI_EXPORT
#	endif
#
#	if __GNUC__ >= 4
#		define GUI_EXPORT_DLL  __attribute__ ((visibility("default")))
#	else
#		define GUI_EXPORT_DLL
#	endif
#
// A quick define to overcome different names for the same function
#   define stricmp strcasecmp
#
// Unlike the Win32 compilers, Linux compilers seem to use DEBUG for when
// specifying a debug build.
// (??? this is wrong, on Linux debug builds aren't marked in any way unless
// you mark it yourself any way you like it -- zap ???)
#	ifdef DEBUG
#		define DEBUG_MODE 1
#	else
#		define DEBUG_MODE 0
#	endif

#	if PLATFORM == PLATFORM_APPLE
#		define PLATFORM_LIB "MYGUIPlatform.bundle"
#	else // if PLATFORM_LINUX
#		define PLATFORM_LIB "libMYGUIPlatform.so"
#	endif

#endif


#endif // __PLATFORM_H__
