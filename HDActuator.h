#pragma once
#include"windows.h"
#include"winDNS.h"
//导出类
class HDTask;
class HLoopController;
class HDActuator
{
public:
	//回调接口类型
	using ACTUATOR_END_FUN_TYPE = void(*)(HDActuator *pHActuator);
	using ACTUATOR_BEGIN_FUN_TYPE = void(*)(HDActuator *pHActuator);
	using ACTION_FUN_TYPE = BOOL(*)(HDActuator * pAttachActuator, HDTask *pAttachTask);
public:
	//添加任务
	virtual HDTask* AddTask(TCHAR *taskName, ACTION_FUN_TYPE fun, LPARAM lparam) = 0;
public:
	//开关
	virtual BOOL  Start() = 0;
	virtual DWORD Quit() = 0;
public:
	//权限
	virtual BOOL  NotifyManualQuit() = 0;
	virtual INT   InsertPauseListener() = 0;
	virtual BOOL  RequestPermission() = 0;
	virtual BOOL  RequestPermissionTime(DWORD milliSecond) = 0;
	virtual BOOL  OutPermission() = 0;
public:
	//设置或获取
	virtual TCHAR *GetName() = 0;
	virtual void SetPriorityLevel(DWORD priorityLevel) = 0;
	virtual DWORD GetPriorityLevel() = 0;
	virtual HDTask* GetCurrentTask() = 0;
public:
	//检查
	virtual BOOL IsRunning() = 0;
	virtual BOOL IsPause() = 0;
	virtual INT  InsertPauseActuatorsSystemListener() = 0;
public:
	//休眠
	virtual int LoopSleep(int milSeconed, HDActuator * pActuator = NULL) = 0;
};
