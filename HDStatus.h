#pragma once
#include <winsock2.h>
#include <windows.h>
#include "winDNS.h"
//接口
class HDStatusTask;
class HDStatus
{
public:
	//回调接口类型
	using HDSTATUSTASK_FUN_TYPE = void(*)(HDStatus *pHCStatus, HDStatusTask *pHCStatusTask);
	using HDSTATUS_FUN_TYPE = void(*)(HDStatus *pHCStatus);
public:
	//提供
	virtual __int64 Start() = 0;//开启
	virtual __int64 End() = 0;//会堵塞等待结束
	virtual __int64 SwitchStatus(__int32 type) = 0;//切换状态
	virtual __int32 IsStart() = 0;//是否开启状态机
	virtual __int32 IsEnd() = 0;//是否结束状态机
	virtual __int32 IsRunning() = 0;//是否运行 状态轮询+状态机
	virtual __int32 IsPause() = 0;//是否暂停状态机
	virtual __int32 GetCurType() = 0;//获取当前状态
	virtual __int32 GetIndex() = 0;//获取当前窗口序号
public:
	//提供
	virtual __int64 AddStatusTask(__int32 type, HDSTATUSTASK_FUN_TYPE call, LPVOID lparam) = 0;//添加状态任务
	virtual __int64 AddStatus(__int32 type, HDSTATUS_FUN_TYPE call) = 0;//添加状态任务 覆盖
};

