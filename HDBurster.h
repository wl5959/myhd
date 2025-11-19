#pragma once
#include"windows.h"
#include"winDNS.h"
//导出类
class HDController;
class HDBurster
{
public:
	//接口类型
	using BURSTER_END_FUN_TYPE = void(*)(HDBurster *pHBurster);
	using BURSTER_BEGIN_FUN_TYPE = void(*)(HDBurster *pHBurster);
	using BURSTER_FUN_TYPE = BOOL(*)(HDBurster *pHBurster);
public:
	//休眠
	virtual int LoopSleep(int milSeconed, HDBurster * pHBurster = NULL) = 0;
public:
	//开关
	virtual BOOL Attach(HDController *pHController, BURSTER_FUN_TYPE fun, BURSTER_BEGIN_FUN_TYPE beginFun = NULL, BURSTER_END_FUN_TYPE endFun = NULL) = 0;//附加突发器
	virtual BOOL Detach() = 0;//卸载 关闭 突发器 堵塞
public:
	//暂停或恢复
	virtual void Pause() = 0;
	virtual void Revert() = 0;
public:
	//判断
	virtual BOOL IsPause() = 0;//是否暂停
	virtual BOOL IsRunning() = 0 ;//是否在运行
	virtual BOOL IsRunningSystem() = 0 ;//是否在运行 整个系统
	virtual INT  InsertPauseListener()=0;////监控的是突发器自己是否暂停 0正常 1被暂停过 2被暂停的时候发现自己循环器结束
	virtual INT  InsertPauseSystemListener() = 0 ;//监控的是整个系统是否暂停  0正常 1被暂停过 2被暂停的时候发现自己控制器结束 3被暂停的时候发现系统控制器结束
};



