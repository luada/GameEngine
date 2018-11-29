#pragma once

// ¿‡–Õ
typedef char				CHAR;
typedef short				SHORT;
typedef int					INT;
typedef long				LONG;
typedef float				FLOAT;
typedef double				DOUBLE;
typedef unsigned char		BYTE;
typedef unsigned short		WORD;
typedef unsigned long		DWORD;
typedef unsigned short		USHORT;
typedef unsigned int		UINT;
typedef unsigned long		ULONG;
typedef unsigned short		WCHAR;
typedef int					BOOL;
typedef long long			LONGLONG;
typedef unsigned long long	ULONGLONG;
#ifdef UNICODE
typedef unsigned short		TCHAR;
#else
typedef char				TCHAR;
#endif
typedef void*				HANDLE;
typedef long				HRESULT;
typedef HANDLE				HWND;
typedef void*				HMODULE;
typedef const TCHAR*		const char*;
typedef TCHAR*				LPSTR;