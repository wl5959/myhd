#pragma once
#include <winsock2.h>
#include <windows.h>
#include "winDNS.h"
#define HEARTDLL_EXPORT_HDSYS
#ifdef HEARTDLL_EXPORT_HDSYS
#define HEARTDLL_API_HDSYS  extern "C" __declspec(dllexport) //导出
#else
#define HEARTDLL_API_HDSYS  extern "C" __declspec(dllimport) //导入
#endif


HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_CheckFontSmooth();

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_CloseFontSmooth();

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_OpenFontSmooth();

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_CheckUAC();

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_SetUAC(__int32 bEnable);

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_Delay(__int32 毫秒);

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_DelayEx(__int32 最小毫秒, __int32  最大毫秒);

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_ExitSys(__int32 type);

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_CloseScreenProtect();

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_ClosePowerManager();

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_ResumeSystemModify();

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_DisableCloseDisplayAndSleep();

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_GetDir(__int32 type);

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_GetCpuType();

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_GetCpuUsage();

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_GetDiskSerial(__int32 index);

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_GetDisplayInfo();

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_GetDPI();

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_RunApp(char* path, long type);

//获取CMD命令形式的打开进程并获取返回输出
//可以控制是否显示控制器和是否等待获取返回值
//"\"J:\\HMADG\\HMad\\x64\\Release\\GoogleAuthy.exe\" DN7BNCWGVYBJHC677AYLLC3EFZEU2VIP"
//返回值:PID
HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_RunAppGetRet(char* cmdApp, BOOL bShowCrol, BOOL bWait);

//获取CMD命令形式的打开进程并获取返回输出(管理员隐藏打开)
//cmdApp:APP路径+APP 如: J:\\HMADG\\HMad\\x64\\Release\\GoogleAuthy.exe
//lparam:启动参数 如: DN7BNCWGVYBJHC677AYLLC3EFZEU2VIP
//bAs:是否管理员
//返回值:PID
HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_RunAppGetRetEx(char* cmdApp, char* lparam, BOOL bAs = TRUE);

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_RunAppEx(char* path, char* appName, char* lparam, __int32 flag, long type);

//是HCSYS_RunAppEx的扩展版本
//指定了当前路径为path
HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_RunAppExxxx(char* path, char* appName, char* lparam, __int32 flag, long type);

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_GetHDiskCode();

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_GetCpuCode();

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_GetBIOSInfo();

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_GetMachineCode();

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_GetMachineCodeNoMac();

//NTP服务器 url 请求网络北京时间 
HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_GetNetTime();

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_GetNetTimeByIp(char* ip);

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_GetSystemBuildNumber();

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_GetSystemType();

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_GetTime();

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_Is64Bit();

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_IsSurrpotVt();

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_GetScreenPixelDepth();

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_SetScreenPixelDepth(__int32 dmBitsPerPel);

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_GetScreenHeight();

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_GetScreenWidth();

HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_SetScreen(__int32 width, __int32 height);

//获取指定进程CPU使用率 返回值是整数百分比和字符串是(含小数百分比)
HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_GetCpuUsageByPid(__int32 pid);

//获取指定进程内存使用率
HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_GetMemoryUsageByPid(__int32 pid);

//获取CMD命令返回值(字符串) 会显示控制器
HEARTDLL_API_HDSYS __int64  __stdcall  HCSYS_GetCmdRet(char* cmd);

//========================================================================================================VM虚拟机======================================================================================================

//运行虚拟机(管理员运行)
//D:\vmwin10>D:\vm16\vmrun -T ws start "D:/vmwin10/Windows10x64.vmx" gui lparam
//D:\vmwin10>D:\vm16\vmrun -T ws start "D:/vmwin10/Windows10x64.vmx" nogui lparam
//windowsIndex:0 表示只是打开虚拟机 大于0表示重置对应窗口序号下的DMA环境
//vmPath:VM安装路径 如:"D:\vm16\"
//vmxSysPath:虚拟机vmx路径 如:"D:/vmwin10/Windows10x64.vmx"
//bGui:是否界面GUI显示启动虚拟机
//lparam:额外命令参数
//vmType:
//0 VMware Workstation -T ws
//1 VMware Player -T player
//返回值:0 1
//1.当windowsInde>0 对于使用了HDEX_InstallPluginVM安装插件到虚拟机 调用关闭后开启内部会重置环境 防止初始化截图或键鼠或执行句柄失效导致虚拟机崩溃 
HEARTDLL_API_HDSYS __int64  __stdcall  HCVM_Run(__int32 windowsIndex, char* vmPath, char* vmxSysPath, BOOL bGui = FALSE, char* lparam = NULL, long vmType = 0, long type = 0);


//重启运行虚拟机(管理员运行)
//D:\vmwin10>D:\vm16\vmrun -T ws restart "D:/vmwin10/Windows10x64.vmx" gui lparam
//D:\vmwin10>D:\vm16\vmrun -T ws restart "D:/vmwin10/Windows10x64.vmx" nogui lparam
//vmPath:VM安装路径 如:"D:\vm16\"
//vmxSysPath:虚拟机vmx路径 如:"D:/vmwin10/Windows10x64.vmx"
//bForceRoot:是否强制重启（类似断电） 反之表示正常重启（需 VMware Tools 支持）
//bGui:是否界面GUI显示启动虚拟机
//lparam:额外命令参数
//vmType:
//0 VMware Workstation -T ws
//1 VMware Player -T player
//返回值:0 1
//注意:
//1.当windowsInde>0 对于使用了HDEX_InstallPluginVM安装插件过的虚拟机 调用重启后内部会重置环境 防止初始化截图或键鼠或执行句柄失效导致虚拟机崩溃 
HEARTDLL_API_HDSYS __int64  __stdcall  HCVM_Rerun(__int32 windowsIndex, char* vmPath, char* vmxSysPath, BOOL bForceRoot = TRUE, BOOL bGui = FALSE, char* lparam = NULL, long vmType = 0, long type = 0);


//关闭运行虚拟机(管理员运行)
//D:\vmwin10>D:\vm16\vmrun -T ws stop "D:/vmwin10/Windows10x64.vmx" 
//D:\vmwin10>D:\vm16\vmrun -T ws stop "D:/vmwin10/Windows10x64.vmx" 
//vmPath:VM安装路径 如:"D:\vm16\"
//vmxSysPath:虚拟机vmx路径 如:"D:/vmwin10/Windows10x64.vmx"
//bForceRoot:是否强制关闭（类似断电） 反之表示正常关闭（需 VMware Tools 支持）
//bGui:是否界面GUI显示启动虚拟机
//lparam:额外命令参数
//vmType:
//0 VMware Workstation -T ws
//1 VMware Player -T player
//返回值:0 1
//1.当windowsInde>0 对于使用了HDEX_InstallPluginVM安装插件的虚拟机 调用重启后内部会重置环境 防止初始化截图或键鼠或执行句柄失效导致虚拟机崩溃 
HEARTDLL_API_HDSYS __int64  __stdcall  HCVM_Close(__int32 windowsIndex, char* vmPath, char* vmxSysPath, BOOL bForceRoot = TRUE, long vmType = 0, long type = 0);



//获取当前正在运行的虚拟机路径 和 总数(管理员运行)
//vmPath:VM安装路径 如:"D:\vm16\"
//返回值:数量
//返回的json: "|"隔开
//如:"D:/vmwin10/Windows10x64_1.vmx|D:/vmwin10/Windows10x64_2.vmx|D:/vmwin10/Windows10x64_3.vmx"
HEARTDLL_API_HDSYS __int64  __stdcall  HCVM_List(char* vmPath);


//指定虚拟机是否已经开启(管理员运行)
//vmPath:VM安装路径 如:"D:\vm16\"
//vmxSysPath:虚拟机vmx路径 如:"D:/vmwin10/Windows10x64_1.vmx"
//返回值:0 1
HEARTDLL_API_HDSYS __int64  __stdcall  HCVM_IsStart(char* vmPath, char* vmxSysPath);



