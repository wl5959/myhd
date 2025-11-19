#pragma once
#include <winsock2.h>
#include <windows.h>
#include "winDNS.h"
#define HEARTDLL_EXPORT_HDVMDMA
#ifdef HEARTDLL_EXPORT_HDVMDMA
#define HEARTDLL_API_HDVMDMA  extern "C" __declspec(dllexport) //导出
#else
#define HEARTDLL_API_HDVMDMA  extern "C" __declspec(dllimport) //导入
#endif

#define HEARTDLL_EXPORT_HDVNC
#ifdef HEARTDLL_EXPORT_HDVNC
#define HEARTDLL_API_HDVNC  extern "C" __declspec(dllexport) //导出
#else
#define HEARTDLL_API_HDVNC  extern "C" __declspec(dllimport) //导入
#endif


//虚拟机DMA模块

//获取DMA服务器版本号
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_GetVersion(__int32 windowsIndex);


//判断HD插件 DMA接口和DMA服务器接口版本是否一致
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_IsVersion(__int32 windowsIndex);

//开启DMA服务器
//ip:IP 默认:127.0.0.1
//port:端口 默认:6532
//serverRootPath:服务器exe根目录 默认:中控exe目录下
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_StartServer(char* ip = "127.0.0.1", int port = 6532, char* serverRootPath = "");


//关闭服务器
//同时结束进程
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_CloseServer();


//服务器是否已经开启
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_ServerIsStart(char* ip = "127.0.0.1", int port = 6532);


//初始话并绑定虚拟机 
//支持重连 vmPid==0 属于重连 前提是已经关联过
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_Init(__int32 windowsIndex, __int32 vmPid, __int32 timeOut = 10000);


//通过进程名获取PID
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_GetPid(__int32 windowsIndex, char* processName);


//读地址
//仅支持 1 2 4 8 地址大小
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_Read(__int32 windowsIndex, __int32 targetPid, __int64 addr, __int32 addrSzie);


//读单浮点数
//值从json获取
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_ReadFloat(__int32 windowsIndex, __int32 targetPid, __int64 addr);


//读双浮点数
//值从json获取
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_ReadDouble(__int32 windowsIndex, __int32 targetPid, __int64 addr);



//读字节集
//仅最大支持1024
//buffAddr:缓冲区大小 一定要大于等于readSzie
//readSzie:读大小 限制不能超过1024可以等于
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_ReadBytes(__int32 windowsIndex, __int32 targetPid, __int64 addr, BYTE* buffAddr, __int32 readSzie);


//写字节集
//仅支持 1 2 4 8 地址大小
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_Write(__int32 windowsIndex, __int32 targetPid, __int64 value, __int64 addr, __int32 addrSzie);


//写单浮点数
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_WriteFloat(__int32 windowsIndex, __int32 targetPid, float value, __int64 addr);


//写双浮点数
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_WriteDouble(__int32 windowsIndex, __int32 targetPid, double value, __int64 addr);


//获取函数地址
//仅最大支持1024
//buffAddr:缓冲区大小 一定要大于等于writeSzie
//readSzie:写大小 限制不能超过1024可以等于
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_WriteBytes(__int32 windowsIndex, __int32 targetPid, __int64 addr, BYTE* buffAddr, __int32 writeSzie);


//获取函数地址
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_GetProcAddr(__int32 windowsIndex, __int32 targetPid, char* moduleName, char* procName);


//获取主模块地址
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_GetBaseModule(__int32 windowsIndex, __int32 targetPid);


//获取模块地址
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_GetModule(__int32 windowsIndex, __int32 targetPid, char* moduleName);


//shellcode初始化
//返回执行环境
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_ShellCodeInitX64(__int32 windowsIndex, __int32 targetPid,__int64 hookAddr, __int32 hookAddrSzie);


//执行shellcode
//excuteEnvAddr:执行环境 0为使用缓存的执行句柄 内部自动获取
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_RunShellCodeX64(__int32 windowsIndex, __int32 targetPid, __int64 excuteEnvAddr, char*shellCodeStr);


//初始化截图环境
//返回前台截图句柄 一个虚拟机只能一个,不要多获取
//内部会自动判断是否之前已经获取了
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_InitCapture(__int32 windowsIndex);


//获取截图数据一次/截图一次
//excuteEnvAddr:前台截图句柄
//captureEnvAddr:0表示使用缓存环境
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_Capture(__int32 windowsIndex,__int64 captureEnvAddr);


//获取截图数据循环读取
//excuteEnvAddr:前台截图句柄
//内部会生成一根线程专门截图到本物理机后台截图缓存中
//captureEnvAddr:0表示使用缓存环境
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_OpenCapture(__int32 windowsIndex, __int64 captureEnvAddr);


//开启后可以关闭结束线程
//和HCVMDMA_OpenCapture是一对接口
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_CloseCapture(__int32 windowsIndex);

//初始化键鼠环境
//返回前台键鼠句柄 一个虚拟机只能一个
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_InitMouseKey(__int32 windowsIndex);


//mkbEnvAddr:前台键鼠句柄
//mkbEnvAddr:0表示使用缓存环境
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_MoveTo(__int32 windowsIndex, __int32 x, __int32 y, __int64 mkbEnvAddr);

//按下
//mkbEnvAddr:前台键鼠句柄
//mkbEnvAddr:0表示使用缓存环境
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_LeftDown(__int32 windowsIndex, __int64 mkbEnvAddr);

//弹起
//mkbEnvAddr:前台键鼠句柄
//mkbEnvAddr:0表示使用缓存环境
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_LeftUp(__int32 windowsIndex, __int64 mkbEnvAddr);

//点击
//mkbEnvAddr:前台键鼠句柄
//mkbEnvAddr:0表示使用缓存环境
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_LeftClick(__int32 windowsIndex, int mis ,__int64 mkbEnvAddr);

//双击
//mkbEnvAddr:前台键鼠句柄
//mkbEnvAddr:0表示使用缓存环境
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_LeftDoubleClick(__int32 windowsIndex, int mis, __int64 mkbEnvAddr);


//按下
//mkbEnvAddr:前台键鼠句柄
//mkbEnvAddr:0表示使用缓存环境
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_MiddleDown(__int32 windowsIndex, __int64 mkbEnvAddr);

//弹起
//mkbEnvAddr:前台键鼠句柄
//mkbEnvAddr:0表示使用缓存环境
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_MiddleUp(__int32 windowsIndex, __int64 mkbEnvAddr);

//点击
//mkbEnvAddr:前台键鼠句柄
//mkbEnvAddr:0表示使用缓存环境
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_MiddleClick(__int32 windowsIndex, int mis, __int64 mkbEnvAddr);

//双击
//mkbEnvAddr:前台键鼠句柄
//mkbEnvAddr:0表示使用缓存环境
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_MiddleDoubleClick(__int32 windowsIndex, int mis, __int64 mkbEnvAddr);

//按下
//mkbEnvAddr:前台键鼠句柄
//mkbEnvAddr:0表示使用缓存环境
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_RightDown(__int32 windowsIndex, __int64 mkbEnvAddr);

//弹起
//mkbEnvAddr:前台键鼠句柄
//mkbEnvAddr:0表示使用缓存环境
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_RightUp(__int32 windowsIndex, __int64 mkbEnvAddr);

//点击
//mkbEnvAddr:前台键鼠句柄
//mkbEnvAddr:0表示使用缓存环境
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_RightClick(__int32 windowsIndex, int mis, __int64 mkbEnvAddr);

//双击
//mkbEnvAddr:前台键鼠句柄
//mkbEnvAddr:0表示使用缓存环境
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_RightDoubleClick(__int32 windowsIndex, int mis, __int64 mkbEnvAddr);


//滚轮滚上
//mkbEnvAddr:前台键鼠句柄
//mkbEnvAddr:0表示使用缓存环境
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_WheelUp(__int32 windowsIndex,__int64 mkbEnvAddr);

//滚轮滚下
//mkbEnvAddr:前台键鼠句柄
//mkbEnvAddr:0表示使用缓存环境
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_WheelDown(__int32 windowsIndex,__int64 mkbEnvAddr);

//键盘按下
//mkbEnvAddr:前台键鼠句柄
//mkbEnvAddr:0表示使用缓存环境
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_KeyDown(__int32 windowsIndex, int keyCode, __int64 mkbEnvAddr);

//键盘弹起
//mkbEnvAddr:前台键鼠句柄
//mkbEnvAddr:0表示使用缓存环境
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_KeyUp(__int32 windowsIndex, int keyCode, __int64 mkbEnvAddr);

//键盘敲击
//mkbEnvAddr:前台键鼠句柄
//mkbEnvAddr:0表示使用缓存环境
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_KeyClick(__int32 windowsIndex, int keyCode, int mis, __int64 mkbEnvAddr);


//输入Unicode字符串 限制:最大100(共200字节)长度
//mkbEnvAddr:前台键鼠句柄
//mkbEnvAddr:0表示使用缓存环境
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_SendUnicode(__int32 windowsIndex, wchar_t* strUnicode, __int64 mkbEnvAddr);


//输入Ascii字符串  限制:最大200(共200字节)长度
//mkbEnvAddr:前台键鼠句柄
//mkbEnvAddr:0表示使用缓存环境
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_SendAscii(__int32 windowsIndex, char* strAscii, __int64 mkbEnvAddr);


//shellcode初始化
//返回执行环境
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_ShellCodeInitX86(__int32 windowsIndex, __int32 targetPid, __int32 hookAddr, __int32 hookAddrSzie);

//执行shellcode
//excuteEnvAddr:执行环境
HEARTDLL_API_HDVMDMA __int64  __stdcall HCVMDMA_RunShellCodeX86(__int32 windowsIndex, __int32 targetPid, __int32 excuteEnvAddr, char*shellCodeStr);

//特征码搜索(指定模块名)
//1为地址 2为基地址 3为CALL 4为地址中的值
HEARTDLL_API_HDVMDMA __int64 __stdcall  HCVMDMA_FindCodeX86(__int32 windowsIndex, __int32 targetPid,CHAR*code, __int32 offset, __int32 num, __int32 type = 1, CHAR*moduleName = NULL);

//特征码搜索(指定开始地址和搜索大小)
//1为地址 2为基地址 3为CALL 4为地址中的值
HEARTDLL_API_HDVMDMA __int64 __stdcall  HCVMDMA_FindCodeX86Ex(__int32 windowsIndex, __int32 targetPid, __int64 beginAddr, __int32 addrSize, CHAR*code, __int32 offset, __int32 num, __int32 type = 1);

//特征码搜索(指定模块名)
//1为地址 2为基地址 3为CALL 4为地址中的值
HEARTDLL_API_HDVMDMA __int64 __stdcall  HCVMDMA_FindCodeX64(__int32 windowsIndex, __int32 targetPid, CHAR*code, __int32 offset, __int32 num, __int32 type = 1, CHAR*moduleName = NULL);


//特征码搜索(指定开始地址和搜索大小)
//1为地址 2为基地址 3为CALL 4为地址中的值
HEARTDLL_API_HDVMDMA __int64 __stdcall  HCVMDMA_FindCodeX64Ex(__int32 windowsIndex, __int32 targetPid, __int64 beginAddr, __int32 addrSize,  CHAR*code, __int32 offset, __int32 num, __int32 type = 1);

//获取PID列表
//返回值:PID数量 小于等于0为错误 大于0为数量
//返回JSON:具体进程PID从最近json获取字符串 pid1,name1|pid2,name2|pid3,name3|  "|"分隔符 每个进程信息
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_GetPidList(__int32 windowsIndex);

//PID是否存在
//返回值:0 1
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_IsExistPid(__int32 windowsIndex,__int32 pid);

//卸载(HCEnv_UnLoadEx)和关闭
//一旦调用,则虚拟机需要被关闭后开启 而不是重启 PID不能一样
HEARTDLL_API_HDVMDMA __int64  __stdcall  HCVMDMA_Close(__int32 windowsIndex);


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////vnc组件//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//安装插件(HDEX_InstallPluginVM)的形式连接VNC:支持重连 port==0 属于重连 会检查安装插件时候的PID 同时 自动获取之前连接过的端口  前提是已经连接过
//未安装插件(HCVnc_Connect)的形式连接VNC:重连一直都可以 不能port==0 因为会检查PID 未安装插件的PID为0
HEARTDLL_API_HDVNC __int64  __stdcall  HCVnc_Connect(__int32 windowsIndex,__int32 port);									//连接本地VNC和会先断开之前的 不会卸载环境 支持重连 可以多次重复调用

HEARTDLL_API_HDVNC __int64  __stdcall  HCVnc_Close(__int32 windowsIndex);													//断开VNC 卸载(HCEnv_UnLoad)和关闭 对于单纯使用VNC的是可以重连

HEARTDLL_API_HDVNC __int64  __stdcall  HCVnc_MoveTo(__int32 windowsIndex, __int32 x, __int32 y);							//鼠标移动

HEARTDLL_API_HDVNC __int64  __stdcall  HCVnc_MoveToOffset(__int32 windowsIndex, __int32 rx, __int32 ry);					//鼠标偏移

HEARTDLL_API_HDVNC __int64  __stdcall  HCVnc_LeftClick(__int32 windowsIndex);												//鼠标左键单击

HEARTDLL_API_HDVNC __int64  __stdcall  HCVnc_LeftDown(__int32 windowsIndex);												//鼠标左键按下

HEARTDLL_API_HDVNC __int64  __stdcall  HCVnc_LeftUp(__int32 windowsIndex);													//鼠标左键弹起

HEARTDLL_API_HDVNC __int64  __stdcall  HCVnc_LeftDoubleClick(__int32 windowsIndex);											//鼠标左键双击

HEARTDLL_API_HDVNC __int64  __stdcall  HCVnc_RightClick(__int32 windowsIndex);												//鼠标右键点击

HEARTDLL_API_HDVNC __int64  __stdcall  HCVnc_RightDown(__int32 windowsIndex);												//鼠标右键按下

HEARTDLL_API_HDVNC __int64  __stdcall  HCVnc_RightUp(__int32 windowsIndex);													//鼠标右键弹起

HEARTDLL_API_HDVNC __int64  __stdcall  HCVnc_WheelDown(__int32 windowsIndex);												//滚轮上下

HEARTDLL_API_HDVNC __int64  __stdcall  HCVnc_WheelUp(__int32 windowsIndex);													//滚轮向上

HEARTDLL_API_HDVNC __int64  __stdcall  HCVnc_KeyPress(__int32 windowsIndex, int keycode, BOOL isKeypad = false);			//键盘单击

HEARTDLL_API_HDVNC __int64  __stdcall  HCVnc_KeyDown(__int32 windowsIndex, int keycode);									//键盘按住

HEARTDLL_API_HDVNC __int64  __stdcall  HCVnc_KeyUp(__int32 windowsIndex, int keycode);										//键盘弹起

HEARTDLL_API_HDVNC __int64  __stdcall  HCVnc_KeyPressStr(__int32 windowsIndex, char* strText, BOOL isKeypad = false);		//输入字母和数字字串

HEARTDLL_API_HDVNC __int64  __stdcall  HCVnc_SendString(__int32 windowsIndex, char* strText);							    //输入汉字

HEARTDLL_API_HDVNC __int64  __stdcall  HCVnc_OpenCapture(__int32 windowsIndex);											    //开启截图

HEARTDLL_API_HDVNC __int64  __stdcall  HCVnc_CloseCapture(__int32 windowsIndex);											//关闭截图