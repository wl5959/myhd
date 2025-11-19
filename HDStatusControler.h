#pragma once
#include <winsock2.h>
#include <windows.h>
#include "winDNS.h"
#define HEARTDLL_EXPORT_HDSTATUS
#ifdef HEARTDLL_EXPORT_HDSTATUS
#define HEARTDLL_API_HDSTATUS __declspec(dllexport) //导出
#else
#define HEARTDLL_API_HDSTATUS __declspec(dllimport) //导入
#endif
//接口
class HDStatus;
class HDStatusControler
{
public:
	//提供
	virtual LPVOID BuilderLparam(__int32 bSize) = 0;//申请内存 构建参数
public:
	//提供
	virtual HDStatus* AddStatus(__int32 index) = 0;//添加状态机
	virtual HDStatus* GetStatus(__int32 index) = 0;//获取状态机
	virtual __int64 StartStatus(__int32 index) = 0;//知道窗口序号 开启会检查后不会再开启
	virtual __int64 StartStatus(__int32 beginIndex, __int32 endIndex) = 0;//多少开 开启会检查后不会再开启
	virtual __int64 AttachStatusCopy(__int32 index, HDStatus*pHCStatus) = 0;//附加状态机到某个窗口 会拷贝一份 参数不会拷贝 如果是同窗口序号直接返回
	virtual __int64 AttachStatusCopyAll(HDStatus*pHCStatus) = 0;//附加状态机到所有窗口  会拷贝一份 参数不会拷贝
	virtual __int64 PauseStatus(__int32 index) = 0;//暂停
	virtual __int64 RecoverStatus(__int32 index) = 0;//恢复
	virtual __int64 EndStatus(__int32 index) = 0;//会堵塞
};
//获取状态机控制器有且只有一个
extern "C" HEARTDLL_API_HDSTATUS HDStatusControler* _stdcall HCHD_GetHDStatusControler();

