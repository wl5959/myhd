#pragma once
#include"windows.h"
#include"winDNS.h"
class HDActuator;
//导出类
class HDTask
{
public:
	//回调接口类型
	using ACTION_FUN_TYPE = BOOL(*)(HDActuator * pAttachActuator, HDTask *pAttachTask);
public:
	//检查判断
	virtual BOOL IsRunning()= 0;
public:
	//参数构建
	virtual LPARAM GetLparam() = 0;
	virtual LPARAM LparamBuilder(DWORD sizeByte) = 0;
public:
	//设置或获取
	virtual TCHAR *GetName() = 0;
};

