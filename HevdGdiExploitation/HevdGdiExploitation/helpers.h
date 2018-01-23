#pragma once
#include <Windows.h>

typedef struct _EPROCESS {
	unsigned long UniqueProcessId;
	_LIST_ENTRY ActiveProcessLinks;
	void* Token;
};

typedef struct WRITE_WHAT_WHERE {
	unsigned long long What;
	unsigned long long Where;
};


typedef struct _LARGE_UNICODE_STRING
{
	ULONG Length;           // 000
	ULONG MaximumLength : 31; // 004
	ULONG bAnsi : 1;          // 004
	PWSTR Buffer;           // 008
} LARGE_UNICODE_STRING, *PLARGE_UNICODE_STRING;


typedef struct _THRDESKHEAD {
	HWND h;
	unsigned long cLockObj;
	void* pti;
	void* rpdesk;
	_THRDESKHEAD* pSelf;
} THRDESKHEAD;


typedef struct tagCLS {
	tagCLS*       pclsNext;
	ATOM          atomClassName;
	WORD          fnid;
	void*		  rpdeskParent;
	void*         pdce;
	WORD          hTaskWow;
	WORD          CSF_flags;
	LPSTR         lpszClientAnsiMenuName;
	LPWSTR        lpszClientUnicodeMenuName;
	void*		  spcpdFirst;
	tagCLS*       pclsBase;
	tagCLS*       pclsClone;
	int           cWndReferenceCount;
	UINT          style;
	WNDPROC       lpfnWndProc;
	int           cbclsExtra;
	int           cbwndExtra;
	HMODULE       hModule;
	void*		   spicn;
	void*	       spcur;
	// RS3: Uncomment buffer2.
	// RS2: Comment buffer2.
	void* buffer;
	void* buffer2;
	HBRUSH        hbrBackground;
	LPWSTR        lpszMenuName;
	LPSTR         lpszAnsiClassName;
	void*         spicnSm;
} CLS, *PCLS;


typedef struct tagWND {
	THRDESKHEAD          head;
	DWORD                dwState;
	DWORD                dwState2;
	DWORD                dwExStyle;
	DWORD                dwStyle;
	HMODULE              hModule;
	WORD                 hMod16;
	WORD                 fnid;
	tagWND*               spwndNext;
	tagWND*               spwndParent;
	tagWND*               spwndChild;
	tagWND*               spwndOwner;
	RECT                 rcWindow;
	RECT                 rcClient;
	WNDPROC              lpfnWndProc;
	void* buffer;
	void* buffer2;
	void* buffer3;
	PCLS                 pcls;
	HRGN                 hrgnUpdate;
	void*                ppropList;
	void*                pSBInfo;
	void*                spmenuSys;
	void*                spmenu;
	HRGN                 hrgnClip;
	LARGE_UNICODE_STRING strName;
	int                  cbwndExtra;
	tagWND*              spwndLastActive;
	HIMC                 hImc;
	ULONG_PTR            dwUserData;
	DWORD                field1;
	DWORD                field2;
} WND, *PWND;

const unsigned long WRITE_WHAT_WHERE_IOCTL_CODE = 0x22200B;

typedef __kernel_entry NTSTATUS (NTAPI* NTQUERYINFORMATIONPROCESS)(IN HANDLE ProcessHandle, IN PROCESSINFOCLASS ProcessInformationClass, OUT PVOID ProcessInformation, IN ULONG ProcessInformationLength, OUT PULONG ReturnLength OPTIONAL);
typedef void* (NTAPI* HMVALIDATEHANDLE)(HWND h, int type);