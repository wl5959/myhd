#pragma once
#include <winsock2.h>
#include <windows.h>
#include "winDNS.h"
#define HEARTDLL_EXPORT_HDIP
#ifdef HEARTDLL_EXPORT_HDIP
#define HEARTDLL_API_HDIP extern "C" __declspec(dllexport) //导出
#else
#define HEARTDLL_API_HDIP extern "C" __declspec(dllimport) //导入
#endif

//【=====================================================================有米软件兼容=====================================================】
//调用流程:
//1.先设置路径
//2.添加IP和添加进程
//3.打开YM

//设置软件根目录 EXE所在目录
//如:E:\youmi\
//
HEARTDLL_API_HDIP __int64 __stdcall HCIP_YMSetRootPath(char * path);

//添加IP
//type:1 socket  2 ss
HEARTDLL_API_HDIP __int64 __stdcall HCIP_YMAddIP(char *ip, int port, char *account, char *password, int type, int kfp = 1, char* proName = NULL);


HEARTDLL_API_HDIP __int64 __stdcall HCIP_YMAddProcess(char *proName);

HEARTDLL_API_HDIP __int64 __stdcall HCIP_YMOpen(int type);//0国内 1国外

HEARTDLL_API_HDIP __int64 __stdcall HCIP_YMIsOpen(int type);//0国内 1国外

HEARTDLL_API_HDIP __int64 __stdcall HCIP_YMClose(int type);//0国内 1国外