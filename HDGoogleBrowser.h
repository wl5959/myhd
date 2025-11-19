#pragma once
#include <winsock2.h>
#include <windows.h>
#include "winDNS.h"
#define HEARTDLL_EXPORT_HDGB
#ifdef HEARTDLL_EXPORT_HDGB
#define HEARTDLL_API_HDGB extern "C" __declspec(dllexport) //导出
#else
#define HEARTDLL_API_HDGB extern "C" __declspec(dllimport) //导入
#endif
//【======================================================================GoogleBrowser========================================================】
//目前仅仅支持X64游戏
//如果有X86游戏,请联系管理员兼容！！！！！！
//该模块 必须游戏进程自带内置谷歌浏览器 才会附加模块成功
//监听模式每个游戏不同而定
//如果不知道用那个可以都尝试下
//附加监听模式1
HEARTDLL_API_HDGB __int64  __stdcall  HCGB_Attach1(__int32 窗口序号);
//附加监听模式2
HEARTDLL_API_HDGB __int64  __stdcall  HCGB_Attach2(__int32 窗口序号);

//关闭监听
HEARTDLL_API_HDGB __int64  __stdcall  HCGB_Detach(__int32 窗口序号);

//注入JS
HEARTDLL_API_HDGB __int64  __stdcall  HCGB_InjectJSCode(__int32 窗口序号,char *codeBuffer, BOOL 是否主线程调用 = FALSE);

//执行JS文本
HEARTDLL_API_HDGB __int64  __stdcall  HCGB_ExcuteJSFile(__int32 窗口序号,char *fileName, BOOL 是否主线程调用 = FALSE);


