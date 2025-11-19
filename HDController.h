#pragma once
#include"windows.h"
#include"winDNS.h"
#define HEARTDLL_EXPORT_HDCN
#ifdef HEARTDLL_EXPORT_HDCN
#define HEARTDLL_API_HDCN __declspec(dllexport) //导出
#else
#define HEARTDLL_API_HDCN __declspec(dllimport) //导入
#endif
//导出类
class HDBurster;
class HDActuator;
class HDController
{
public:
	//回调接口类型
	using ACTUATOR_END_FUN_TYPE = void(*)(HDActuator *pHActuator);
	using ACTUATOR_BEGIN_FUN_TYPE = void(*)(HDActuator *pHActuator);
public:
	//添加执行器
	virtual HDActuator *AddActuator(TCHAR *actuatorName, DWORD priorityLevel, ACTUATOR_BEGIN_FUN_TYPE beginCallBack, ACTUATOR_END_FUN_TYPE endCallBack) = 0;//创建普通执行器
public:
	//获取突发器 有且只有一个
	virtual HDBurster * GetBurster() = 0;
	virtual HDActuator* GetCurrentActuator() = 0;//获取当前执行器
public:
	//检查判断
	virtual BOOL IsStart() = 0;//整个系统
	virtual BOOL IsPause() = 0;//整个系统
	virtual BOOL IsRunning() = 0;//整个系统
	virtual BOOL IsActuatorsSystemPause() = 0;//整个执行器
	virtual INT InsertPauseActuatorsSystemListener() = 0;//循环堵塞 整个执行器 0未被暂停 1所有执行器暂停过 2所有执行器暂停的时候发现控制器系统结束了
public:
	//开关
	virtual BOOL Start() = 0;//1.开始创建线程
	virtual void Pause() = 0;//暂停整个 包含了突发器
	virtual void PauseActuators() = 0;//暂停所有执行器 不会修改整个系统的暂停
	virtual void Revert() = 0;//恢复整个 包含了突发器
	virtual void RevertActuators() = 0;//恢复所有执行器 不会修改整个系统的暂停
	virtual BOOL End() = 0;  //1.所有执行器关闭 2.关闭自己 线程退出 堵塞
};
//获取控制器有且只有一个
extern "C" HEARTDLL_EXPORT_HDCN HDController* _stdcall HCHD_GetHDController();

