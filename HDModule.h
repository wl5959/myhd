#pragma once
#include <winsock2.h>
#include <windows.h>
#include "winDNS.h"
#define HEARTDLL_EXPORT_HDMODULE
#ifdef HEARTDLL_EXPORT_HDMODULE
#define HEARTDLL_API_HDMODULE  extern "C" __declspec(dllexport) //导出
#else
#define HEARTDLL_API_HDMODULE  extern "C" __declspec(dllimport) //导入
#endif
//【=====================================================================组件操作=====================================================】

//【初始化环境后才能调用】
//说明:调用HCModule_AddComponent 添加组件(比如:游戏组件)
//addType:添加方式 -1默认或者0或者1无痕 2普通加载
HEARTDLL_API_HDMODULE __int64  __stdcall  HCModule_AddComponent(__int32 窗口序号, char*账号, char*密码, char * 组件绝对路径, __int64 rcx, __int64 rdx, __int64 r8, __int64 r9, __int64 l5, __int64 l6, __int64 addType = -1, BOOL 是否自动初始化 = TRUE, BOOL 是否主线程调用 = FALSE);

//如果添加组件的方式不是无痕加载 可以调用这个接口卸载
HEARTDLL_API_HDMODULE __int64  __stdcall  HCModule_DeleteComponent(__int32 窗口序号, char * 组件名, BOOL 是否主线程调用 = FALSE);

//【初始化环境后才能调用】
//说明:调用HCModule_CALL 调用组件CALL
HEARTDLL_API_HDMODULE __int64  __stdcall  HCModule_CALL(__int32 窗口序号, char * 组件名, char *函数名字, __int64 rcx, __int64 rdx, __int64 r8, __int64 r9, __int64 l5, __int64 l6, BOOL 是否主线程调用 = FALSE);

//指定文本参数 最大支持3个
//文本参数缓冲区大小最大为266(包含0)
//如果需要更多参数 可以使用HCModule_CALLByJson
//HEARTDLL_API_HDMODULE __int64  __stdcall  HCModule_CALLEx(__int32 窗口序号, char * 组件名, char *函数名字, __int64 rcx, __int64 rdx, __int64 r8, __int64 r9, __int64 l5, __int64 l6, char* textBuffer1, char* textBuffer2, BOOL 是否主线程调用 = FALSE);

//传递一个jsonBuffer文本Buffer缓冲区,json缓冲区大小最大大小为1024*100 大小0.1M
//当我们需要传递文本的时候就可以存在一个缓冲区中
//直接传递一个json字符串或者一个合并文本或者字节集
//buffer:缓冲区地址
//bufferSize:指定的缓冲区中有效字节大小(最大不可超过1024*100),如果是字符串不能超过(1024*100-1),统一规定不能超过(1024*100-1)
HEARTDLL_API_HDMODULE __int64  __stdcall  HCModule_CALLEx(__int32 窗口序号, char * 组件名, char *函数名字, __int64 rcx, __int64 rdx, __int64 r8, __int64 r9, __int64 l5, __int64 l6, char* buffer, int bufferSize, BOOL 是否主线程调用 = FALSE);



