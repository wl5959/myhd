#pragma once
#include <winsock2.h>
#include <windows.h>
#include "winDNS.h"
class HDStatusTask
{
public:
	//提供接口
	virtual BOOL PauseListener() = 0;//暂停就循环等待
	virtual BOOL IsStop() = 0;//状态不一致就停止
};

