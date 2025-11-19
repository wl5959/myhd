#pragma once
#include <winsock2.h>
#include <windows.h>
#include "winDNS.h"
#define HEARTDLL_EXPORT_HDSCRCPY
#ifdef HEARTDLL_EXPORT_HDSCRCPY
#define HEARTDLL_API_HDSCRCPY  extern "C" __declspec(dllexport) //导出
#else
#define HEARTDLL_API_HDSCRCPY  extern "C" __declspec(dllimport) //导入
#endif


//【=====================================================================主板机操作=====================================================】
//设置HDScrcpy投屏软件根目录
//如:J:\\hdscrcpy2.7\\
//默认C:\\hdscrcpy2.7\\

HEARTDLL_API_HDSCRCPY __int64  __stdcall  HCSC_SetPath(char* rootPath);


//ipInfo:IP端口信息 多个IP信息用"|"隔开  IP和端口用":"隔开
//如: 127.0.0.1:123|127.0.0.2:789|127.0.0.3:456|
//当传递NULL空 表示重启ABD 此时接口返回的是是否重启成功 具体看json返回
//当传递有效IP字符串信息 表示重启ADB的同时会连接对应的IP端口 此时接口返回的是成功连接数量 如果是0表示连接数为0或者重启失败 具体看json返回
HEARTDLL_API_HDSCRCPY __int64  __stdcall  HCSC_ResetAdb(char* ipInfo);

//遍历当前所有设备
//字符串信息:设备1名字|设备2名字|设备3名字|
HEARTDLL_API_HDSCRCPY __int64  __stdcall  HCSC_QueryDevices();


//连接设备并通讯窗口序号
//winIndex:窗口序号
//devicesName:设备名字
//type 1 -s 模拟器描述 2 -d USB设备号 3  -e Ip:port
//w h :宽度 高度
//timeOut:超时连接毫秒
HEARTDLL_API_HDSCRCPY __int64  __stdcall  HCSC_ConnectDevices(__int32 winIndex, char* devicesName, char* cmdLparam, __int32 type, __int32 w, __int32 h,__int32 timeOut);


//修改设备 丢弃 无法动态修改
//winIndex:窗口序号
//cmdLaram:命令行参数 如:--window-height=500 设置设备窗口高度为500
//HEARTDLL_API_HDSCRCPY __int64  __stdcall  HCSC_ModifyDevices(__int32 winIndex, char* cmdLparam);

