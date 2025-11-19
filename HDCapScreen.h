#pragma once
#include <winsock2.h>
#include <windows.h>
#include "winDNS.h"
#define HEARTDLL_EXPORT_HDCS
#ifdef HEARTDLL_EXPORT_HDCS
#define HEARTDLL_API_HDCS extern "C" __declspec(dllexport) //导出
#else
#define HEARTDLL_API_HDCS extern "C" __declspec(dllimport) //导入
#endif
//【======================================================================后台截图=================================================】

//设置识别模式
//type:
//0或者-1:普通识别模式 默认
//1:高频后台截图识别模式 
HEARTDLL_API_HDCS __int64  __stdcall  HCCS_SetType(__int32 type = 0);

//【初始化环境后才能调用】
//打开截图CALL
//说明:调用HCS_OpenCS
HEARTDLL_API_HDCS __int64  __stdcall  HCCS_OpenCS(__int32 窗口序号);

//窗口序号指定为0 表示全局全屏截图
HEARTDLL_API_HDCS __int64  __stdcall  HCCS_OpenCSEx(__int32 窗口序号, BOOL bNormal, __int32 capType = 0, __int64 hwnd = 0);
//【初始化环境后才能调用】
//获取截图数据
//说明:调用HCCS_GetCSData
//图片数据结构
//1字节对齐
//#pragma  pack(1)
//单个数据
//typedef struct MYA8R8G8B8
//{
//	BYTE m_a;//透明通道
//	BYTE m_r;//红色通道
//	BYTE m_g;//绿色通道
//	BYTE m_b;//蓝色通道
//}MYA8R8G8B8;
//#pragma  pack()
//json:{"error":0,"ret":[{"bRet":AAA,"addr":XXX,"eleSize":YYY,"len":ZZZ,"w":1222,"h":699}]} 
//AAA:调用接口返回值 XXX:图片二进制数据首地址 YYY:MYA8R8G8B8结构体数量 ZZZ:字节大小(图片数据) w:宽度 h:高度
//注意:拿到图片地址数据XXX使用后 记得释放(HCCS_FreeArray)
HEARTDLL_API_HDCS __int64  __stdcall  HCCS_GetCSData(__int32 窗口序号);

//【初始化环境后才能调用】
//释放内存 改内存是使用 new[] 申请的内存
//说明:调用HCCS_FreeArray
HEARTDLL_API_HDCS __int64  __stdcall  HCCS_FreeArray(void* addr);

//释放内存 内存池操作释放内存
//说明:调用HCCS_FreeMemPool
//那个窗口序号返回申请的地址 就用那个窗口序号释放
//注意:该接口是释放【使用内存池申请的内存地址】的地址,与HCCS_FreeArray不一样
HEARTDLL_API_HDCS __int64  __stdcall  HCCS_FreeMemPool(__int32 窗口序号,void* addr);



//【初始化环境后才能调用】
//截图生成BMP图片
//说明:调用HCCS_CaptureBmp
//注意:可能失败 因为数据可能被占用了
//json:{"error":0,"ret":[{"bRet":AAA,"w":1222,"h":699}]} 
HEARTDLL_API_HDCS __int64  __stdcall  HCCS_CaptureBmp(__int32 窗口序号, char*BMP文件路径, BOOL 是否打开 = FALSE);


//【初始化环境后才能调用】
//获取截图BMP格式数据 方便用于第三方图色
//说明:调用HCCS_GetCaptureBmpData
//json:{"error":0,"ret":[{"bRet":1,"addr":XXX,"eleSize":YYY,"allLen":ZZZ,"w":1222,"h":699}]} 
//XXX是图片二进制数据首地址 YYY是MYA8R8G8B8结构体数量 ZZZ:总字节大小等于(54+YYY*sizeof(MYA8R8G8B8))
//注意:拿到BMP地址数据使用后 记得释放(HCCS_FreeArray)
HEARTDLL_API_HDCS __int64  __stdcall  HCCS_GetCaptureBmpData(__int32 窗口序号);


//【初始化环境后才能调用】
//获取截图BMP格式数据 方便用于第三方图色 可以指定一个范围
//说明:调用HCCS_GetCaptureBmpData
//json:{"error":0,"ret":[{"bRet":1,"addr":XXX,"eleSize":YYY,"allLen":ZZZ,"w":1222,"h":699}]} 
//XXX是图片二进制数据首地址 YYY是MYA8R8G8B8结构体数量 ZZZ:总字节大小等于(54+YYY*sizeof(MYA8R8G8B8))
//注意:拿到BMP地址数据使用后 记得释放(HCCS_FreeArray)
HEARTDLL_API_HDCS __int64  __stdcall  HCCS_GetCaptureBmpRangeData(__int32 窗口序号, __int32 X, __int32 Y, __int32 宽度, __int32 高度);


//【初始化环境后才能调用】
//打开后台截图查看器
//说明:调用HCCS_OpenCSFinder
//内部使用命令行参数打开查看器
//C:\\Debug\\csfinder.exe" -窗口索引 -x -y -w -h 
//查看器回读取图片数据
//X:左上角X  Y:左上角Y 
//json:{"error":0,"ret":[{"bRet":XX,"pid":111}]}
//等待打开后才会返回 有稍微的堵塞
HEARTDLL_API_HDCS __int64  __stdcall  HCCS_OpenCSFinder(__int32 窗口序号, __int32 X, __int32 Y, __int32 宽度, __int32 高度);



//【初始化环境后才能调用】
//关闭后台截图查看器
//说明:调用HCCS_CloseCSFinder
//其他值是GetLastError()的返回值
HEARTDLL_API_HDCS __int64  __stdcall  HCCS_CloseCSFinder(__int32 窗口序号, __int32 pid);



//【初始化环境后才能调用】
//关闭截图CALL
//说明:调用HCCS_CloseCS
HEARTDLL_API_HDCS __int64  __stdcall  HCCS_CloseCS(__int32 窗口序号);

HEARTDLL_API_HDCS __int64  __stdcall  HCCS_CloseCSEx(__int32 窗口序号);

//后台截图缓存获取失败判断接口
//传递的返回值 必须是识别截图相关的接口返回的
HEARTDLL_API_HDCS __int64  __stdcall  HCCS_IsCaptureValid(__int64 ret);

