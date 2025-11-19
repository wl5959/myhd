#pragma once
#include <winsock2.h>
#include <windows.h>
#include "winDNS.h"
#define HEARTDLL_EXPORT_HDCG
#ifdef HEARTDLL_EXPORT_HDCG
#define HEARTDLL_API_HDCG extern "C" __declspec(dllexport) //导出
#else
#define HEARTDLL_API_HDCG extern "C"__declspec(dllimport) //导入
#endif
//【======================================================================黑屏========================================================】
//【初始化环境后才能调用】
//打开黑屏CALL
//说明:调用HHIT2_OpenBS
//1.参数:minIndex->最小模型序号 maxIndex->最大模型序号 默认是6到30  根据实际情况修改 可以实现过滤模型
HEARTDLL_API_HDCG __int64  __stdcall  HC_OpenBS(__int32 窗口序号, __int32 minIndex = 0, __int32 maxIndex = 0, BOOL 是否主线程调用 = FALSE);

//【HHIT2_OpenBS打开黑屏后才有效果】
//设置模式序号
//说明:调用HHIT2_SetBs
//1.参数:minIndex->最小模型序号 maxIndex->最大模型序号 默认是6到30  根据实际情况修改 可以实现过滤模型
HEARTDLL_API_HDCG __int64  __stdcall  HC_SetBs(__int32 窗口序号, __int32 minIndex = 0, __int32 maxIndex = 0);



//【HHIT2_OpenBS打开黑屏后才有效果】
//关闭黑屏CALL
//说明:调用HHIT2_CloseBS
HEARTDLL_API_HDCG __int64  __stdcall  HC_CloseBS(__int32 窗口序号, BOOL 是否主线程调用 = FALSE);





//【======================================================================CPU========================================================】
//【初始化环境后才能调用】
//打开CPU优化
//说明:调用HHIT2_OpenCPU
HEARTDLL_API_HDCG __int64  __stdcall  HC_OpenCPU(__int32 窗口序号, BOOL 是否主线程调用 = FALSE);


//【HHIT2_OpenCPU打开黑屏后才有效果】
//设置FPS帧数
//说明:调用HHIT2_SetFPS
//1.参数:iFPS->帧数 可能和游戏的会重叠 注意可能不是实际的帧数  看实际情况设置
HEARTDLL_API_HDCG __int64  __stdcall  HC_SetFPS(__int32 窗口序号, __int32 iFPS = 0);

//1.参数:downMs->延迟 
HEARTDLL_API_HDCG __int64  __stdcall  HC_SetCpuDwonMs(__int32 窗口序号, __int32 downMs = 0);

//【HHIT2_OpenCPU才能有效】
//关闭CPU优化
//说明:调用HHIT2_CloseCPU
HEARTDLL_API_HDCG __int64  __stdcall  HC_CloseCPU(__int32 窗口序号, BOOL 是否主线程调用 = FALSE);
