#pragma once
#include <winsock2.h>
#include <windows.h>
#include "winDNS.h"
#define HEARTDLL_EXPORT_HDMEMORY
#ifdef HEARTDLL_EXPORT_HDMEMORY
#define HEARTDLL_API_HDMEMORY  extern "C" __declspec(dllexport) //导出
#else
#define HEARTDLL_API_HDMEMORY  extern "C" __declspec(dllimport) //导入
#endif
//【======================================================================内存(Memory)接口========================================================】

//【初始化环境后才能调用】
//说明:调用通用CALL
//1.特征码字符串地址:ascii码字符串地址可以包含?掩码  偏移:正负偏移  次数:第几次  type:1为地址 2为基地址 3为CALL 4为地址中的值(8字节的值,拿到后自己截断成自己想要的值)
HEARTDLL_API_HDMEMORY __int64  __stdcall  HCM_FindCode(__int32 窗口序号, char *特征码字符串地址, __int32 偏移, __int32 次数, __int32 type = 1, char *模块名字 = NULL);

//结束地址=开始地址+扫描范围大小
HEARTDLL_API_HDMEMORY __int64  __stdcall  HCM_FindCodeEx(__int32 窗口序号, __int64 开始地址, __int64 扫描范围大小, char *特征码字符串地址, __int32 偏移, __int32 次数, __int32 type = 1);

//【偏移表达式格式】
//尽支持十六进制格式:XXX]XXX]XXX]XXX]
//如:0x123456]+0x56]-0x44]
//加号"+"可要可不要
//减号"-"负偏移需要
//最后一个"]"不要忘了加


//【初始化环境后才能调用】
//说明:调用读内存CALL
//表达式字符串地址:ASCII码字符串
//模块名字:为NULL 表示主模块
//json:{"error":0,"ret":[{"bRet":1,"iError":2,"value":XXXX}]} 
//bRet:读取是否成功 iError:第几个偏移错误,0说明没错大于0说明第几个偏移错误了 iError等于-1表示解析表达式错误 iError等于-2表示读取大小设置不对 XXXX是读取的值
HEARTDLL_API_HDMEMORY __int64  __stdcall  HCM_Read(__int32 窗口序号, char *表达式字符串地址, __int32 读取大小, char *模块名字 = NULL, BOOL 是否主线程调用 = FALSE);


//读字节流数据
//json:{"error":0,"ret":[{"bRet":1,"iError":2]} 
HEARTDLL_API_HDMEMORY __int64  __stdcall  HCM_ReadData(__int32 窗口序号, char *表达式字符串地址, BYTE* byteBuffer, __int32 byBufferSize, __int32 读取大小, char *模块名字 = NULL, BOOL 是否主线程调用 = FALSE);


//读单/双浮点数
//读取大小: 4 float单浮点 8 double 双浮点
//返回结果
//以float举例:
//json返回字符串
//如:{\"error\":0,\"ret\":[{\"bRet\":1,\"iError\":0,\"value\":999.000}]}
HEARTDLL_API_HDMEMORY __int64  __stdcall  HCM_ReadFD(__int32 窗口序号, char *表达式字符串地址, __int32 读取大小, char *模块名字 = NULL, BOOL 是否主线程调用 = FALSE);


//addr:游戏进程中的地址
//读取大小:分别可以是1(BYTE) 2(SHORT) 4(__int32) 8(__int64)
HEARTDLL_API_HDMEMORY __int64  __stdcall  HCM_ReadAddr(__int32 窗口序号, __int64 addr, __int32 读取大小, BOOL 是否主线程调用 = FALSE);


//读字节流数据
HEARTDLL_API_HDMEMORY __int64  __stdcall  HCM_ReadDataAddr(__int32 窗口序号, __int64 addr, BYTE* byteBuffer, __int32 byBufferSize, __int32 读取大小, BOOL 是否主线程调用 = FALSE);

//读单/双浮点数
//读取大小: 4 float单浮点 8 double 双浮点
//以float举例:
//json返回字符串
//如:"999.0000"
HEARTDLL_API_HDMEMORY __int64  __stdcall  HCM_ReadFDAddr(__int32 窗口序号, __int64 addr, __int32 读取大小, BOOL 是否主线程调用 = FALSE);

//【初始化环境后才能调用】
//说明:调用写内存CALL
//表达式字符串地址:ASCII码字符串
//模块名字:为NULL 表示主模块
//value:写入的值8字节长整数
//json:{"error":0,"ret":[{"bRet":1,"iError":2}]}
//bRet:写入是否成功 iError:第几个偏移错误,0说明没错大于0说明第几个偏移错误了 iError等于-1表示解析表达式错误 iError等于-2表示读取大小设置不对
HEARTDLL_API_HDMEMORY __int64  __stdcall  HCM_Write(__int32 窗口序号, char *表达式字符串地址, __int64 value, __int32 写入大小, char *模块名字 = NULL, BOOL 是否主线程调用 = FALSE);

//写字节流数据
//最大写入100KB字节大小,注意这个限制,否则会报错
//json返回值
//{\"error\":0,\"ret\":[{\"bRet\":1,\"iError\":0}]}
HEARTDLL_API_HDMEMORY __int64  __stdcall  HCM_WriteData(__int32 窗口序号, char *表达式字符串地址, char* byteBuffer, __int32 写入大小, char *模块名字 = NULL, BOOL 是否主线程调用 = FALSE);


//写单浮点数 4字节
//json返回值
//{\"error\":0,\"ret\":[{\"bRet\":1,\"iError\":0}]}
HEARTDLL_API_HDMEMORY __int64  __stdcall  HCM_WriteF(__int32 窗口序号, char *表达式字符串地址, float value, char *模块名字 = NULL, BOOL 是否主线程调用 = FALSE);

//写双浮点数 8字节
//json返回值
//{\"error\":0,\"ret\":[{\"bRet\":1,\"iError\":0}]}
HEARTDLL_API_HDMEMORY __int64  __stdcall  HCM_WriteD(__int32 窗口序号, char *表达式字符串地址, double value, char *模块名字 = NULL, BOOL 是否主线程调用 = FALSE);


//addr:游戏进程中的地址
//value:写入的值8字节长整数
//写入大小:分别可以是1(BYTE) 2(SHORT) 4(__int32) 8(__int64)
HEARTDLL_API_HDMEMORY __int64  __stdcall  HCM_WriteAddr(__int32 窗口序号, __int64 addr, __int64 value, __int32 写入大小, BOOL 是否主线程调用 = FALSE);

//写字节流数据
//json返回字节流
//最大写入100KB字节大小,注意这个限制,否则会报错
HEARTDLL_API_HDMEMORY __int64  __stdcall  HCM_WriteDataAddr(__int32 窗口序号, __int64 addr, char* byteBuffer, __int32 写入大小, BOOL 是否主线程调用 = FALSE);


//写单浮点数 4字节
//返回值同上HCM_WriteAddrF
HEARTDLL_API_HDMEMORY __int64  __stdcall  HCM_WriteAddrF(__int32 窗口序号, __int64 addr, float value,BOOL 是否主线程调用 = FALSE);

//写双浮点数 8字节
//返回值同上HCM_WriteAddrD
HEARTDLL_API_HDMEMORY __int64  __stdcall  HCM_WriteAddrD(__int32 窗口序号, __int64 addr, double value, BOOL 是否主线程调用 = FALSE);

//获取模块地址
//模块名字:NULL默认获取主模块首地址
HEARTDLL_API_HDMEMORY __int64  __stdcall  HCM_GetModuleBase(__int32 窗口序号, char* 模块名字 = NULL, BOOL 是否主线程调用 = FALSE);

//获取模块接口地址
//模块名字:NULL默认获取主模块首地址
//导出接口名字:函数名字
HEARTDLL_API_HDMEMORY __int64  __stdcall  HCM_GetModuleFunAddr(__int32 窗口序号, char* 模块名字 = NULL, char* 函数名字 = NULL, BOOL 是否主线程调用 = FALSE);

//地址是否可读
HEARTDLL_API_HDMEMORY __int64  __stdcall  HCM_IsBadReadAddr(__int32 窗口序号, __int64 addr, __int32 size, BOOL 是否主线程调用 = FALSE);

//浮点数转整数形式的浮点数表达
HEARTDLL_API_HDMEMORY __int64  __stdcall  HCM_FloatTakeInt(float value);

//整数形式的浮点数表达转浮点数
HEARTDLL_API_HDMEMORY float  __stdcall  HCM_FloatIntTakeFloat(int value);

//长整数形式的浮点数表达转双浮点数
HEARTDLL_API_HDMEMORY double  __stdcall  HCM_DoubleIntTakeDouble(__int64 value);

//执行汇编CALLX86 传递汇编代码
//excuteCallAddr:执行CALL的内存地址 
//汇编文本A:汇编文本 汇编文本不宜过大 内部转换为汇编最大2048字节
//返回汇编在目标进程中的执行CALL内存地址(excuteCallAddr),以便下一次使用
HEARTDLL_API_HDMEMORY __int64  __stdcall  HCM_AsmCallX86(__int32 窗口序号, __int64 excuteCallAddr, char* 汇编文本A = NULL, BOOL bFreeAddr = FALSE, BOOL 是否主线程调用 = FALSE);

//执行汇编CALLX64 传递汇编代码
//excuteCallAddr:执行CALL的内存地址 
//汇编文本A:汇编文本 汇编文本不宜过大 内部转换为汇编最大2048字节
//返回汇编在目标进程中的执行CALL内存地址(excuteCallAddr),以便下一次使用
HEARTDLL_API_HDMEMORY __int64  __stdcall  HCM_AsmCallX64(__int32 窗口序号, __int64 excuteCallAddr, char* 汇编文本A = NULL, BOOL bFreeAddr = FALSE, BOOL 是否主线程调用 = FALSE);


