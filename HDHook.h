#pragma once
#include <winsock2.h>
#include <windows.h>
#include "winDNS.h"
#define HEARTDLL_EXPORT_HOOK
#ifdef HEARTDLL_EXPORT_HOOK
#define HEARTDLL_API_HOOK extern "C" __declspec(dllexport) //导出
#else
#define HEARTDLL_API_HOOK extern "C" __declspec(dllimport) //导入
#endif

//【======================================================================HOOK API模块X64X86========================================================】
//x64
//拦截接口名字:send sendto recv recvfrom
//开启拦截API
HEARTDLL_API_HOOK __int64 __stdcall HDHK_InterceptApi(__int32 窗口序号, char* 模块名字, char* 拦截接口名字, __int32 破坏字节数, __int64 回调地址, __int64 附加参数, BOOL 是否主线程调用 = FALSE);

//暂停拦截API
HEARTDLL_API_HOOK __int64 __stdcall HDHK_PauseInterceptApi(__int32 窗口序号, char* 模块名字, char* 拦截接口名字, BOOL 是否主线程调用 = FALSE);

//恢复拦截API
HEARTDLL_API_HOOK __int64 __stdcall HDHK_RecoverInterceptApi(__int32 窗口序号, char* 模块名字, char* 拦截接口名字, BOOL 是否主线程调用 = FALSE);

//卸载拦截API
HEARTDLL_API_HOOK __int64 __stdcall HDHK_UnInterceptApi(__int32 窗口序号, char* 模块名字, char* 拦截接口名字, BOOL 是否主线程调用 = FALSE);

//主动发送
HEARTDLL_API_HOOK __int64 __stdcall HDHK_SendApi(__int32 窗口序号, __int32 socket, BYTE *buffer, __int32 bufferSize, __int32 flag, BOOL 是否主线程调用 = FALSE);

//ip是网络字节序 整数型
HEARTDLL_API_HOOK __int64 __stdcall HDHK_SendToApi(__int32 窗口序号, __int32 socket, BYTE *buffer, __int32 bufferSize, __int32 flag, __int32 port, __int32 ip, BOOL 是否主线程调用 = FALSE);


//【======================================================================HOOK API模块修改返回========================================================】
//在回调函数里面需要调用下面函数来实现修改寄存器和其他参数值
HEARTDLL_API_HOOK __int64 __stdcall HDHK_SetProcessCallBackLparamSendX64(__int32 窗口序号, __int64 rcx, __int64 rdx, __int64 r8, __int64 r9, __int64 rbp, __int64 rsp, __int64 rip, __int32 mark);//设置回调函数返回值 给目标进程

HEARTDLL_API_HOOK __int64 __stdcall HDHK_SetProcessCallBackLparamRecvX64(__int32 窗口序号, __int64 rcx, __int64 rdx, __int64 r8, __int64 r9, __int64 rbp, __int64 rsp, __int64 rip, __int32 mark);//设置回调函数返回值 给目标进程

HEARTDLL_API_HOOK __int64 __stdcall HDHK_SetProcessCallBackLparamSendToX64(__int32 窗口序号, __int64 rcx, __int64 rdx, __int64 r8, __int64 r9, __int64 l5, __int64 l6, __int64 rbp, __int64 rsp, __int64 rip, __int32 mark);//设置回调函数返回值 给目标进程 l5端口 l6地址

HEARTDLL_API_HOOK __int64 __stdcall HDHK_SetProcessCallBackLparamRecvFromX64(__int32 窗口序号, __int64 rcx, __int64 rdx, __int64 r8, __int64 r9, __int64 l5, __int64 l6, __int64 rbp, __int64 rsp, __int64 rip, __int32 mark);//设置回调函数返回值 给目标进程 l5端口 l6地址


HEARTDLL_API_HOOK __int64 __stdcall HDHK_SetProcessCallBackLparamSendX86(__int32 窗口序号, __int32 l1, __int32 l2, __int32 l3, __int32 l4, __int32 ebp, __int32 esp, __int32 eip, __int32 mark);//设置回调函数返回值 给目标进程

HEARTDLL_API_HOOK __int64 __stdcall HDHK_SetProcessCallBackLparamRecvX86(__int32 窗口序号, __int32 l1, __int32 l2, __int32 l3, __int32 l4, __int32 ebp, __int32 esp, __int32 eip, __int32 mark);//设置回调函数返回值 给目标进程

HEARTDLL_API_HOOK __int64 __stdcall HDHK_SetProcessCallBackLparamSendToX86(__int32 窗口序号, __int32 l1, __int32 l2, __int32 l3, __int32 l4, __int32 l5, __int32 l6, __int32 ebp, __int32 esp, __int32 eip, __int32 mark);//设置回调函数返回值 给目标进程 l5端口 l6地址

HEARTDLL_API_HOOK __int64 __stdcall HDHK_SetProcessCallBackLparamRecvFromX86(__int32 窗口序号, __int32 l1, __int32 l2, __int32 l3, __int32 l4, __int32 l5, __int32 l6, __int32 ebp, __int32 esp, __int32 eip, __int32 mark);//设置回调函数返回值 给目标进程 l5端口 l6地址


//【======================================================================任意HOOK模块X86X64========================================================】
//不是无痕HOOK
//回调函数类型:
//typedef __int64(__stdcall *HandleCallBackFunType)(
//__int32 窗口序号, __int32 插件序号, 
//__int64 raxOreax, __int64 rbxOrebx, 
//__int64 rcxOrecx, __int64 rdxOredx,
//__int64 rbpOrebp, __int64 rspOresp,
//__int64 rsiOresi, __int64 rdiOredi,
//__int64 r8, __int64 r9, __int64 r10, __int64 r11, __int64 r12, __int64 r13, __int64 r14, __int64 r15, 
//__int32 lparam);
//返回值: 0 忽视HOOK语句 直接跳到原来 1 走原有流程 2 需要修改值+直接跳到原来 3 需要修改值+走原有流程
//【======================================================================任意HOOK模块X64========================================================】
//暂时没用
HEARTDLL_API_HOOK __int64 __stdcall HDHK_HookX64(__int32 窗口序号, char* 模块名字, __int64 hook地址,  __int32 回调地址, __int32 附加参数, BOOL 是否主线程调用 = FALSE);

HEARTDLL_API_HOOK __int64 __stdcall HDHK_PauseHookX64(__int32 窗口序号, char* 模块名字, __int64 hook地址, BOOL 是否主线程调用 = FALSE);

HEARTDLL_API_HOOK __int64 __stdcall HDHK_RecoverHookX64(__int32 窗口序号, char* 模块名字, __int64 hook地址, BOOL 是否主线程调用 = FALSE);

HEARTDLL_API_HOOK __int64 __stdcall HDHK_UnHookX64(__int32 窗口序号, char* 模块名字, __int64 hook地址, BOOL 是否主线程调用 = FALSE);

//【======================================================================任意HOOK模块X86X64========================================================】

//x64
//1.hook地址=XX 所属模块名=0 模块首地址=0 模块大小=0 jmp13空白地址=0 保存原始汇编地址=0 全自动搜索模块名字和空白地址和模块地址和大小 模块遍历 hook
//2.hook地址=XX 所属模块名=XX 模块首地址=0 模块大小=0 jmp13空白地址=0 保存原始汇编地址=0 全自动搜索模块名字和空白地址和模块地址和大小 GetModuleInformation hookx
//3.hook地址=XX 所属模块名=XX 模块首地址=XX 模块大小=XX jmp13空白地址=0 保存原始汇编地址=0 手动指定模块首地址和大小 来搜索获取空白地址和保存原始汇编地址用的 这种情况模块名字只是为了标志管理使用 hookexx
//4.hook地址=XX 所属模块名=可有可无 模块首地址=可有可无 模块大小=可有可无 jmp13空白地址=XX 保存原始汇编地址=XX 手动指定空白地址 可以实现无模块HOOK 模块名 主要为了获取模块首地址和大小来搜索获取空白地址和保存原始汇编地址用的 hookexxx

//自动判断所属模块名字
//X86X64
//1.hook地址=XX 所属模块名=0 模块首地址=0 模块大小=0 jmp13空白地址=0 保存原始汇编地址=0 全自动搜索模块名字和空白地址和模块地址和大小 模块遍历 hook
HEARTDLL_API_HOOK __int64 __stdcall HDHK_Hook(__int32 窗口序号, __int64 hook地址, __int32 破坏字节 , __int64 回调地址, __int64 附加参数, BOOL 是否主线程调用 = FALSE);

//指定模块名字
//X64
//2.hook地址=XX 所属模块名=XX 模块首地址=0 模块大小=0 jmp13空白地址=0 保存原始汇编地址=0 全自动搜索模块名字和空白地址和模块地址和大小 GetModuleInformation hookx
//X86
//无效
HEARTDLL_API_HOOK __int64 __stdcall HDHK_HookEx(__int32 窗口序号, char *所属模块名字, __int64 hook地址, __int32 破坏字节, __int64 回调地址, __int64 附加参数, BOOL 是否主线程调用 = FALSE);

//指定模块名字
//X64
//3.hook地址=XX 所属模块名=XX 模块首地址=XX 模块大小=XX jmp13空白地址=0 保存原始汇编地址=0 手动指定模块首地址和大小 来搜索获取空白地址和保存原始汇编地址用的 这种情况模块名字只是为了标志管理使用 hookexx
//X86
//无效
HEARTDLL_API_HOOK __int64 __stdcall HDHK_HookExx(__int32 窗口序号, char *所属模块名字, __int64 模块首地址, __int32 模块大小, __int64 hook地址, __int32 破坏字节, __int64 回调地址, __int64 附加参数, BOOL 是否主线程调用 = FALSE);

//可以无模块HOOK
//X64
//4.hook地址=XX 所属模块名=可有可无 模块首地址=可有可无 模块大小=可有可无 jmp13空白地址=XX 保存原始汇编地址=XX 手动指定空白地址 可以实现无模块HOOK 模块名 主要为了获取模块首地址和大小来搜索获取空白地址和保存原始汇编地址用的 hookexxx
//X86
//无效
HEARTDLL_API_HOOK __int64 __stdcall HDHK_HookExxx(__int32 窗口序号, __int64 hook地址, char *所属模块名字, __int64 jmp13空白地址, __int64 保留汇编地址, __int32 破坏字节, __int64 回调地址, __int64 附加参数, BOOL 是否主线程调用 = FALSE);


HEARTDLL_API_HOOK __int64 __stdcall HDHK_PauseHook(__int32 窗口序号, __int64 hook地址, BOOL 是否主线程调用 = FALSE);

HEARTDLL_API_HOOK __int64 __stdcall HDHK_RecoverHook(__int32 窗口序号, __int64 hook地址, BOOL 是否主线程调用 = FALSE);

HEARTDLL_API_HOOK __int64 __stdcall HDHK_UnHook(__int32 窗口序号, __int64 hook地址, BOOL 是否主线程调用 = FALSE);

//X86X64通用
//mark:       1        2        4        8       16        32       64      128      256   512   1024   2048   4096   8192   16384   32768   65536
//是否修改:raxOreax rbxOrebx rcxOrecx rdxOredx rbpOrebp rspOresp rsiOresi rdiOredi    r8    r9     r10    r11   r12    r13     r14     r15    rip
HEARTDLL_API_HOOK __int64 __stdcall HDHK_SetProcessHookCallBackLparam(__int32 窗口序号, __int32 插件序号,
__int64 raxOreax, __int64 rbxOrebx, 
__int64 rcxOrecx, __int64 rdxOredx,
__int64 rbpOrebp, __int64 rspOresp,
__int64 rsiOresi, __int64 rdiOredi,
__int64 r8, __int64 r9, __int64 r10, 
__int64 r11, __int64 r12, __int64 r13,
__int64 r14, __int64 r15, 
__int64 rip, 
__int32 mark);//设置回调函数返回值



