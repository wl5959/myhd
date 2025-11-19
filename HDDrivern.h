#pragma once
#include <winsock2.h>
#include <windows.h>
#include "winDNS.h"
#define HEARTDLL_EXPORT_HN
#ifdef HEARTDLL_EXPORT_HN
#define HEARTDLL_API_HN  extern "C" __declspec(dllexport) //导出
#else
#define HEARTDLL_API_HN  extern "C" __declspec(dllimport) //导入
#endif
//【《HDDrv.sys》======================================================================N模式驱动加载===========================================================】
//说明
//1.加载的驱动文件名为《HDDrv.sys》N模式->支持卸载(卸载不会蓝屏)
//2.调用接口进行驱动的加载和卸载
//3.注入进程名通过接口传递
//4.目前为内制进程名支持:b2.exe B2.exe Game.exe game.exe Mad-Win64-Shipping.exe 需要其他请联系heart
//5.可卸载,更稳定

//【打开游戏前调用】
//说明:加载驱动
HEARTDLL_API_HN __int64  __stdcall  HCN_LoadDrv();

//【加载驱动后调用】
//说明:注入DLL
HEARTDLL_API_HN __int64  __stdcall  HCN_InjectDllWX64(wchar_t *DLL路径W);
HEARTDLL_API_HN __int64  __stdcall  HCN_InjectDllAX64(char *DLL路径A);

HEARTDLL_API_HN __int64  __stdcall  HCN_InjectDllWX86(wchar_t *DLL路径W);
HEARTDLL_API_HN __int64  __stdcall  HCN_InjectDllAX86(char *DLL路径A);
//安装HD插件 64
HEARTDLL_API_HN __int64  __stdcall  HCN_InstallPlugX64();
//安装HD插件 86
HEARTDLL_API_HN __int64  __stdcall  HCN_InstallPlugX86();

//支持32/64位的
//普通注入插件DLL 参数->进程PID,进程位数(32)
//可以在打开进程的经常下安装插件DLL
//初始化进程环境后调用这个安装插件 然后循环等待拿到PID
//32位
//不是驱动级别
HEARTDLL_API_HN __int64  __stdcall  HCN_NormalInstallPlugX86(__int32 pid);

//用法和HCN_NormalInstallPlugX86一样 这个接口只是参数是句柄 防止一些进程一次性打开多个 这个句柄可以用来指定某个窗口
//不是驱动级别
HEARTDLL_API_HN __int64  __stdcall  HCN_NormalInstallPlugX86Ex(__int64 topHwnd);

//64位
HEARTDLL_API_HN __int64  __stdcall  HCN_NormalInstallPlugX64(__int32 pid);

//用法和HCN_NormalInstallPlugX64一样 这个接口只是参数是句柄 防止一些进程一次性打开多个 这个句柄可以用来指定某个窗口
//不是驱动级别
HEARTDLL_API_HN __int64  __stdcall  HCN_NormalInstallPlugX64Ex(__int64 topHwnd);

//【加载驱动后调用】
//说明:加载驱动(N模式可以卸载(不会蓝屏)
HEARTDLL_API_HN __int64  __stdcall  HCN_UnLoadDrv();
