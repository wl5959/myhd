#pragma once
#include <winsock2.h>
#include <windows.h>
#include "winDNS.h"
#define HEARTDLL_EXPORT_HDMT
#ifdef HEARTDLL_EXPORT_HDMT
#define HEARTDLL_API_HDMT  extern "C" __declspec(dllexport) //导出
#else
#define HEARTDLL_API_HDMT  extern "C" __declspec(dllimport) //导入
#endif
//【=====================================================================多线程操作=====================================================】
//typedef __int64(__stdcall *FUNTYPE)(__int32 windowsIndex);
//typedef __int64(__stdcall *UIFUNTYPE)(__int32 windowsIndex, char *stepText, BOOL m_end1, BOOL m_pause1, __int32 threadState1, BOOL m_end2, BOOL m_pause2, __int32 threadState2);
//typedef __int64(__stdcall *MSGFUNTYPE)(WPARAM wparam,, LPARAM lparam);
//说明:调用HCMT_InitProcess 初始化多线程 设置相关 流程回调
//hwnd:中控UI的窗口主句柄
//updateUICallBack: UIFUNTYPE UI回调
//loginCallBack: FUNTYPE 登录回调
//firstCallBack: FUNTYPE 第一执行回调
//secondCallBack: FUNTYPE 第二执行回调
//endCallBack: FUNTYPE 结束回调 
//restartPreCallBack: FUNTYPE 重启前回调
//注意:
//1.参数windowsIndex:代表的是窗口序号也是主序号
HEARTDLL_API_HDMT __int64  __stdcall  HCMT_InitProcess(__int64 hwnd, void* updateUICallBack, void* loginCallBack, void* firstCallBack, void* secondCallBack, void* endCallBack, void* restartPreCallBack);

HEARTDLL_API_HDMT __int64  __stdcall  HCMT_InitProcessEx(__int64 hwnd, void* updateUICallBackEx, void* loginCallBack, void* firstCallBack, void* secondCallBack, void* endCallBack, void* restartPreCallBack, void* lparam);

HEARTDLL_API_HDMT __int64  __stdcall  HCMT_InitMainThread(__int64 hwnd);
//说明:调用HCMT_InitOperate 初始化多线程结束/暂停/恢复 状态 操作回调 
//typedef __int64(__stdcall *FUNTYPE)(__int32 index);
//endBindCallBack:FUNTYPE 结束回调  当调用HCMT_SetStop/HCMT_SetAllStop 会触发
//pauseBindCallBack:FUNTYPE 暂停回调  当调用HCMT_SetPause/HCMT_SetAllPause 会触发
//recoverBindCallBack:FUNTYPE  恢复回调  当调用HCMT_SetRecover/HCMT_SetAllRecover 会触发
//注意:
//1.仅仅对于这3个回调而言 参数index:大于多开限制数量,就是副序号;小于就是主序号(也是窗口序号);计算公式:if(index >= 多开限制数*2) 主序号 = index - 多开限制数;
//2.其他接口的windowsIndex就代表的是窗口序号也是主序号
//3.多开限制数量最大常量为31,请自行在程序里面定义
HEARTDLL_API_HDMT __int64  __stdcall  HCMT_InitOperate(void* endBindCallBack, void* pauseBindCallBack, void* recoverBindCallBack);

//说明:调用HCMT_RegisterMessage 注册窗口消息
//msg:自定义消息整数值 (规定值大于等于41124) 内部自动加上41123 可以从1开始设置
//msgCallBack:MSGFUNTYPE 消息回调
HEARTDLL_API_HDMT __int64  __stdcall  HCMT_RegisterMessage(__int32 msg, void* msgCallBack);

//【HDMT_InitProcess/HCMT_InitOperate后才能调用】
//说明:发送消息 触发自己设置回调函数和HCMT_RegisterMessage 配合使用
//同步发送
//msg:自定义消息整数值 (规定值大于等于41124) 内部自动加上41123 可以从1开始设置
//wparam:自定义参数
//lparam:自定义参数
HEARTDLL_API_HDMT __int64  __stdcall  HCMT_MsgSend(__int32 msg, void* wparam, void* lparam);

//异步发送
//msg:自定义消息整数值 (规定值大于等于41124) 内部自动加上41123 可以从1开始设置
//wparam:自定义参数
//lparam:自定义参数
HEARTDLL_API_HDMT __int64  __stdcall  HCMT_MsgPost(__int32 msg, void* wparam, void* lparam);

//【HDMT_InitProcess/HCMT_InitOperate后才能调用】
//说明:调用HCMT_MsgStart 通过消息开启窗口操作
//windowsIndex:窗口序号
//bAsyn:是否异步发送
HEARTDLL_API_HDMT __int64  __stdcall  HCMT_MsgStart(__int32 windowsIndex, BOOL bAsyn = FALSE);

//【HDMT_InitProcess/HCMT_InitOperate后才能调用】
//说明:调用HCMT_MsgStop 通过消息结束窗口操作
//windowsIndex:窗口序号
//bAsyn:是否异步发送
HEARTDLL_API_HDMT __int64  __stdcall  HCMT_MsgStop(__int32 windowsIndex, BOOL bAsyn = FALSE);

//【HDMT_InitProcess/HCMT_InitOperate后才能调用】
//说明:调用HCMT_MsgReStart 通过消息重启窗口操作
//windowsIndex:窗口序号
//bAsyn:是否异步发送
HEARTDLL_API_HDMT __int64  __stdcall  HCMT_MsgReStart(__int32 windowsIndex, BOOL bAsyn = FALSE);

//内置了卸载环境
//bUnload:是否需要卸载环境
//bReCon:在卸载环境的前提下 是否还需要重连 如果不需要重连 则彻底卸载环境
HEARTDLL_API_HDMT __int64  __stdcall  HCMT_MsgReStartEx(__int32 windowsIndex, BOOL bUnload = TRUE, BOOL bReCon = TRUE, BOOL bAsyn = FALSE);



//【HDMT_InitProcess/HCMT_InitOperate后才能调用】
//说明:调用HCMT_MsgUpdateUI 通过消息触发UI回调 并传递线程状态信息给UI回调
//windowsIndex:窗口序号
//bAsyn:是否异步发送
HEARTDLL_API_HDMT __int64  __stdcall  HCMT_MsgUpdateUI(__int32 windowsIndex, BOOL bAsyn = FALSE);

//【HDMT_InitProcess/HCMT_InitOperate后才能调用】
//说明:调用HCMT_MsgStepText  通过消息触发UI回调 并传递线程状态信息给UI回调和文本步骤信息
//windowsIndex:窗口序号
//text:步骤信息/日志信息
//bAsyn:是否异步发送
HEARTDLL_API_HDMT __int64  __stdcall  HCMT_MsgStepText(__int32 windowsIndex, char* text, BOOL bAsyn = FALSE);

//说明:调用HCMT_GetStateString 获取状态整数值对应的字符串
//threadState:状态值
HEARTDLL_API_HDMT char*  __stdcall  HCMT_GetStateString(__int32 threadState);

//【HDMT_InitProcess/HCMT_InitOperate后才能调用】
//说明:调用HCMT_Start 直接开启窗口操作
//windowsIndex:窗口序号
HEARTDLL_API_HDMT __int64  __stdcall  HCMT_Start(__int32 windowsIndex);

//【HDMT_InitProcess/HCMT_InitOperate后才能调用】
//说明:调用HCMT_SetAllPause/HCMT_SetAllRecover/HCMT_SetAllStop 设置所有窗口暂停/恢复/结束
//
HEARTDLL_API_HDMT __int64  __stdcall  HCMT_SetAllPause();

HEARTDLL_API_HDMT __int64  __stdcall  HCMT_SetAllRecover();

HEARTDLL_API_HDMT __int64  __stdcall  HCMT_SetAllStop();

//【HDMT_InitProcess/HCMT_InitOperate后才能调用】
//说明:调用HCMT_SetPause/HCMT_SetRecover/HCMT_SetStop 单个设置窗口暂停/恢复/结束
//windowsIndex:窗口序号
HEARTDLL_API_HDMT __int64  __stdcall  HCMT_SetPause(__int32 windowsIndex);
//index:主副序号
HEARTDLL_API_HDMT __int64  __stdcall  HCMT_SetPauseEx(__int32 index);

//windowsIndex:窗口序号
HEARTDLL_API_HDMT __int64  __stdcall  HCMT_SetRecover(__int32 windowsIndex);
//index:主副序号
HEARTDLL_API_HDMT __int64  __stdcall  HCMT_SetRecoverEx(__int32 index);

//windowsIndex:窗口序号
HEARTDLL_API_HDMT __int64  __stdcall  HCMT_SetStop(__int32 windowsIndex);

//【HDMT_InitProcess/HCMT_InitOperate后才能调用】
//说明:调用HCMT_Sleep 延迟函数 自带暂停/结束/恢复 检查随后触发HCMT_InitOperate设置的3个回调;所以不能在HCMT_InitOperate设置的3个回调中调用,因为会导致无限调用自己(但是内部做了检测所以不会无限调用);其他回调均可以(无影响)
//mis:延迟毫秒
//这个接口不会检测状态机状态
//如果在状态机回调延迟 建议使用HCMT_StatusSleep
HEARTDLL_API_HDMT __int64  __stdcall  HCMT_Sleep(int mis);


//【HDMT_InitProcess/HCMT_InitOperate后才能调用】
//说明:调用HCMT_IsRunning 回调里面调用 检查当前线程是否结束
//在firstCallBack/secondCallBack 中调用
HEARTDLL_API_HDMT __int64  __stdcall  HCMT_IsRunning();

HEARTDLL_API_HDMT  __int64 __stdcall HCMT_IsPause(__int32 index);//主副线程是否已经暂停

HEARTDLL_API_HDMT  __int64 __stdcall HCMT_IsStop(__int32 index);//主副线程是否已经结束

HEARTDLL_API_HDMT __int64 __stdcall HCMT_GetState(__int32 index);//获取主 副线程状态

HEARTDLL_API_HDMT __int64 __stdcall HCMT_IsCanStart(__int32 windowsIndex);//判断是否能开启新的(主副线程) 传递的只能是主序号
//是否是当前状态
//在设置的状态回调函数中循环调用检查当前窗口序号的状态类型是否是当前的映射的回调状态类型
//支持多线程
HEARTDLL_API_HDMT __int64  __stdcall  HCMT_IsStatus();


//全局(全部窗口序号)禁用或者开启 状态
//开启:TRUE表示设置的状态类型才会被检索并触发映射的回调接口
//关闭:FALSE表示状态和回调不会被检索和调用
//支持多线程
HEARTDLL_API_HDMT  __int64 __stdcall HCMT_EnableStatus(__int32 statusType, BOOL bEnable);//主副线程是否已经暂停

//开启状态机
//一般在执行回调或者检查回调 调用就行 不需要都开启
HEARTDLL_API_HDMT  __int64 __stdcall HCMT_StartStatus();//主副线程是否已经结束

//改变状态机状态
//支持多线程
//状态机中调用这个接口 只负责改变为现有状态优先级高的状态
HEARTDLL_API_HDMT __int64 __stdcall HCMT_ChangeStatus(__int32 statusType);//获取主 副线程状态


//改变状态机状态
//支持多线程
//回溯状态
//bClear:真表示清除之前的栈缓存同时改变当前状态位-1(空)
//bClear:假表示清除当前栈顶的状态,相同的全部删除,同时改变当前状态为清除后的栈顶的那个状态
HEARTDLL_API_HDMT __int64 __stdcall HCMT_RetraceStatus(BOOL bClear = FALSE);


//添加状态
//必须在初始化的时候就添加全部可用的状态值
//这个接口不能再多线程调用
//如果需要多线程调用就自己加锁
//不支持多线程
//回调中如果有循环流程 
//要自身检查是否结束
HEARTDLL_API_HDMT __int64 __stdcall HCMT_AddStatus(__int64 funCallBack, __int64 lparam, BOOL bEnable, __int32 statusType);


//获取状态机的状态
HEARTDLL_API_HDMT __int64 __stdcall HCMT_GetStatus(__int32 windowsIndex);


//扩展版本
//延迟函数
//自带暂停/结束/恢复/状态机
HEARTDLL_API_HDMT __int64  __stdcall  HCMT_StatusSleep(int mis);


//扩展版本
//延迟函数
//自带暂停/结束/恢复/状态机(可选)
HEARTDLL_API_HDMT __int64  __stdcall  HCMT_SleepEx(int mis,BOOL bStatus = FALSE);


