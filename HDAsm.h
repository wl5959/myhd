#pragma once
#include <winsock2.h>
#include <windows.h>
#include "winDNS.h"
#define HEARTDLL_EXPORT_HDASM
#ifdef HEARTDLL_EXPORT_HDASM
#define HEARTDLL_API_HDASM extern "C" __declspec(dllexport) //导出
#else
#define HEARTDLL_API_HDASM extern "C"__declspec(dllimport) //导入
#endif
//【======================================================================ShellCode========================================================】

//【直接调用】
//汇编转机器码
//说明:调用HCSH_GetShellCode
//参数:
//模式:4为32位 8为64位
//返回机器码缓冲区
//返回机器码缓冲区大小
//错误1
//错误2
HEARTDLL_API_HDASM __int64  __stdcall  HCSH_GetShellCode(__int32 模式, char* 汇编文本, BYTE *机器码缓冲区, __int32 机器码缓冲区大小, __int64 返回机器码字节大小变量的地址, __int64 错误1变量的地址, __int64 错误2变量的地址);

//【需要初始化HD驱动才能调用】
//注入指定进程机器码
//说明:调用HCSH_WriteShellCode
//参数:
//pid:进程PID
//返回机器码缓冲区
//返回机器码缓冲区大小
HEARTDLL_API_HDASM __int64  __stdcall  HCSH_WriteShellCode(__int32 pid, BYTE *机器码缓冲区, __int32 机器码缓冲区大小, __int64 接受返回地址的变量的地址);
