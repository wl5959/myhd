#pragma once
#include <winsock2.h>
#include <windows.h>
#include "winDNS.h"
#define HEARTDLL_EXPORT_HDHELPER
#ifdef HEARTDLL_EXPORT_HDHELPER
#define HEARTDLL_API_HDHELPER extern "C" __declspec(dllexport) //导出
#else
#define HEARTDLL_API_HDHELPER extern "C" __declspec(dllimport) //导入
#endif

// 使用固定大小的64位整数类型
typedef __int64 JSON_HANDLE;
#define INVALID_JSON_HANDLE 0

//键不支持中文
//值支持中文
//对象管理 支持多线程
HEARTDLL_API_HDHELPER JSON_HANDLE __stdcall HDJSON_Create();
HEARTDLL_API_HDHELPER BOOL __stdcall HDJSON_Parse(JSON_HANDLE hJson, const char* str);//支持中文
HEARTDLL_API_HDHELPER void __stdcall HDJSON_Free(JSON_HANDLE h);
// 值获取接口
HEARTDLL_API_HDHELPER const char* __stdcall HDJSON_GetString(JSON_HANDLE hJson, const char* key);//支持中文
HEARTDLL_API_HDHELPER int __stdcall HDJSON_GetInt(JSON_HANDLE hJson, const char* key);
HEARTDLL_API_HDHELPER __int64 __stdcall HDJSON_GetInt64(JSON_HANDLE hJson, const char* key);
HEARTDLL_API_HDHELPER float __stdcall HDJSON_GetFloat(JSON_HANDLE hJson, const char* key);
HEARTDLL_API_HDHELPER double __stdcall HDJSON_GetDouble(JSON_HANDLE hJson, const char* key);
HEARTDLL_API_HDHELPER BOOL __stdcall HDJSON_GetBool(JSON_HANDLE hJson, const char* key);
// 数组操作
HEARTDLL_API_HDHELPER JSON_HANDLE __stdcall HDJSON_GetArray(JSON_HANDLE hJson, const char* key);
HEARTDLL_API_HDHELPER JSON_HANDLE __stdcall HDJSON_CreateArray();
HEARTDLL_API_HDHELPER int __stdcall HDJSON_ArraySize(JSON_HANDLE hArray);
// 数组值操作
HEARTDLL_API_HDHELPER int __stdcall HDJSON_ArrayGetInt(JSON_HANDLE hArray, int index);
HEARTDLL_API_HDHELPER __int64 __stdcall HDJSON_ArrayGetInt64(JSON_HANDLE hArray, int index);
HEARTDLL_API_HDHELPER const char* __stdcall HDJSON_ArrayGetString(JSON_HANDLE hArray, int index);//支持中文
HEARTDLL_API_HDHELPER float __stdcall HDJSON_ArrayGetFloat(JSON_HANDLE hArray, int index);
HEARTDLL_API_HDHELPER double __stdcall HDJSON_ArrayGetDouble(JSON_HANDLE hArray, int index);
HEARTDLL_API_HDHELPER BOOL __stdcall HDJSON_ArrayGetBool(JSON_HANDLE hArray, int index);
HEARTDLL_API_HDHELPER JSON_HANDLE __stdcall HDJSON_ArrayGetObject(JSON_HANDLE hArray, int index);
// 值设置接口
HEARTDLL_API_HDHELPER BOOL __stdcall HDJSON_SetString(JSON_HANDLE hJson, const char* key, const char* value);//支持中文
HEARTDLL_API_HDHELPER BOOL __stdcall HDJSON_SetInt(JSON_HANDLE hJson, const char* key, int value);
HEARTDLL_API_HDHELPER BOOL __stdcall HDJSON_SetInt64(JSON_HANDLE hJson, const char* key, __int64 value);
HEARTDLL_API_HDHELPER BOOL __stdcall HDJSON_SetDouble(JSON_HANDLE hJson, const char* key, double value);
HEARTDLL_API_HDHELPER BOOL __stdcall HDJSON_SetBool(JSON_HANDLE hJson, const char* key, BOOL value);
HEARTDLL_API_HDHELPER BOOL __stdcall HDJSON_SetArray(JSON_HANDLE hJson, const char* key, JSON_HANDLE hArray);
// 数组元素添加
HEARTDLL_API_HDHELPER BOOL __stdcall HDJSON_ArrayAddString(JSON_HANDLE hArray, const char* value);//支持中文
HEARTDLL_API_HDHELPER BOOL __stdcall HDJSON_ArrayAddInt(JSON_HANDLE hArray, int value);
HEARTDLL_API_HDHELPER BOOL __stdcall HDJSON_ArrayAddDouble(JSON_HANDLE hArray, double value);
HEARTDLL_API_HDHELPER BOOL __stdcall HDJSON_ArrayAddFloat(JSON_HANDLE hArray, float value);
HEARTDLL_API_HDHELPER BOOL __stdcall HDJSON_ArrayAddInt64(JSON_HANDLE hArray, __int64 value);
HEARTDLL_API_HDHELPER BOOL __stdcall HDJSON_ArrayAddBool(JSON_HANDLE hArray, BOOL value);
// 工具函数
HEARTDLL_API_HDHELPER const char* __stdcall HDJSON_ToString(JSON_HANDLE hJson);//支持中文
HEARTDLL_API_HDHELPER const char* __stdcall HDJSON_GetLastError();


//=================================实时绘制窗口
//windIndex:窗口序号
//attachHwnd:附加窗口句柄
HEARTDLL_API_HDHELPER __int64 __stdcall HDDW_Open(__int32 windIndex,__int64 attachHwnd);

//windIndex:窗口序号
//需要循环间隔调用 直到关闭成功 一般在1秒就可以 关闭	
HEARTDLL_API_HDHELPER __int64 __stdcall HDDW_Close(__int32 windIndex);

//设置配置
//bRDraw:是否绘制识别信息
//bYoloDraw:是否绘制yolov信息
//bMKBDraw:是否绘制键鼠信息
//updateTime:每次更新间隔时间(毫秒)
//lparam:额外json配置信息 一般NULL 使用的内置配置
//json配置:
//{"bgc":0xFFFFFFFF} 窗口背景色包含透明度 RGBA()
HEARTDLL_API_HDHELPER __int64 __stdcall HDDW_SetSetting(BOOL bRDraw, BOOL bYoloDraw, BOOL bMKBDraw, __int32 updateTime, char* lparam = NULL);