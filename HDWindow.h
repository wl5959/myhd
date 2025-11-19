#pragma once
#include <winsock2.h>
#include <windows.h>
#include "winDNS.h"
#define HEARTDLL_EXPORT_HDWIN
#ifdef HEARTDLL_EXPORT_HDWIN
#define HEARTDLL_API_HDWIN extern "C" __declspec(dllexport) //导出
#else
#define HEARTDLL_API_HDWIN extern "C" __declspec(dllimport) //导入
#endif

//捕捉光标特征
//winIndex:窗口序号 指定窗口序号=0表示获取当前全局前台鼠标的样式 指定窗口序号>=1表示单独获取每个绑定进程自己的光标特征
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_GetCursorFeature(__int32 winIndex = 0);

//排序通讯(包含卸载的)的窗口,除非初始化了
//返回排序成功的窗口数量
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_SortWindows(__int32 offsetW, __int32 offsetH, __int32 width, __int32 height);

//进程伪装
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_CamouflageProcess(char* runName, char* targetPath, __int32 type);

//
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_SetWindowState(__int64 hwnd, __int32 type);

//设置窗口透明度
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_SetWindowTransparent(__int64 hwnd, __int32 transValue);

//
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_SetWindowSize(__int64 hwnd, __int32 width, __int32 hight, BOOL bCenter = FALSE);

//
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_MoveWindow(__int64 hwnd, __int32 x, __int32 y);

//
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_IsWow64Process(__int64 hwnd, __int32 pid = 0);

//
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_GetWindowTitle(__int64 hwnd);

//获取指定窗口所在的线程ID.
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_GetWindowThreadProcessId(__int64 hwnd);

//获取指定窗口所在的进程ID.
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_GetWindowProcessId(__int64 hwnd);

//获取指定窗口所在的进程的exe文件全路径.
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_GetWindowProcessPath(__int64 hwnd);

//获取窗口在屏幕上的位置
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_GetWindowRect(__int64 hwnd, void *pRect = NULL);

//获取窗口的类名
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_GetWindowClass(__int64 hwnd);

//获取指定窗口的一些属性
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_GetWindowState(__int64 hwnd, __int32 flag);

//获取特殊窗口 桌面 Shell_TrayWnd
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_GetSpecialWindow(__int32 flag);

//获取给定窗口相关的窗口句柄
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_GetWindow(__int64 hwnd, __int32 flag);

//获取鼠标指向的可见窗口句柄
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_GetMousePointWindow();

//获取给定坐标的可见窗口句柄
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_GetPointWindow(__int32 x, __int32 y);

//获取顶层活动窗口,可以获取到按键自带插件无法获取到的句柄
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_GetForegroundWindow();

//获取顶层活动窗口中具有输入焦点的窗口句柄 
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_GetForegroundFocus();

//设置输入焦点到窗口
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_SetForegroundFocus(__int64 hwnd);

//获取窗口客户区域的宽度和高度
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_GetClientSize(__int64 hwnd, void *pW = NULL, void *pH = NULL);

//获取窗口客户区域在屏幕上的位置
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_GetClientRectInWindow(__int64 hwnd, void *pRect = NULL);

//查找符合类名或者标题名的顶层可见窗口,如果指定了parent,则在parent的第一层子窗口中查找.
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_FindWindowEx(__int64 parentHwnd, char* className, char* title, BOOL bType = FALSE);

//查找符合类名或者标题名的顶层可见窗口
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_FindTopWindow(char* className, char* title, BOOL bType = FALSE);

//根据指定进程以及其它条件,枚举系统中符合条件的窗口
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_EnumWindowByProcess(char* processName, char* className, char* title, __int32 filter, BOOL bType = FALSE);

//根据指定进程pid以及其它条件,枚举系统中符合条件的窗口,可以枚举到按键自带的无法枚举到的窗口
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_EnumWindowByProcessId(__int32 pid, char* className, char* title, __int32 filter, BOOL bType = FALSE);

//根据指定进程名,枚举系统中符合条件的进程PID
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_EnumProcess(char* processName, BOOL bType = FALSE);

//bChild:FALSE/假 根据指定条件,枚举系统中符合条件的窗口,可以枚举到按键自带的无法枚举到的窗口
//bChild:TRUE/真 根据指定条件,枚举指定父句柄的子窗口
HEARTDLL_API_HDWIN __int64  __stdcall  HCWIN_EnumWindow(__int64 parentHwnd, char* className, char* title, __int32 filter, BOOL bType = FALSE, BOOL bChild = FALSE);

//=================================================================================NT内核版本============================================================================

//获取指定窗口所在的进程ID. NT内核版本
HEARTDLL_API_HDWIN __int64  __stdcall  HCNT_GetWindowProcessId(__int64 hwnd);