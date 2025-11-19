#pragma once
#include <winsock2.h>
#include <windows.h>
#include "winDNS.h"
#define HEARTDLL_EXPORT_HDLUA
#ifdef HEARTDLL_EXPORT_HDLUA
#define HEARTDLL_API_HDLUA  extern "C" __declspec(dllexport) //导出
#else
#define HEARTDLL_API_HDLUA  extern "C" __declspec(dllimport) //导入
#endif
//【======================================================================Lua========================================================】
//【初始化环境才有效】
//说明:调用HCLUA_ReadFile
//函数名:执行lua文件
//参数:
//LUA标识符:当【是否需要拿到返回值】参数为真的时候,用作线程的标识符,方便主动退出线程，标识符规则:不要太大了 {0到100}以内就行
//是否执行:真表示执行并加载LUA(比如:注入一些自定义LUA接口同时还能执行LUA),反之只是加载LUA文件(比如:注入一些自定义LUA接口)
//是否需要拿到返回值:真表示堵塞直到LUA文件执行完毕并获取返回值，反之表示开启一根线程执行(无法拿到返回值,可以在LUA文件中做一些耗时的操作)
//成功返回:
//根据实际LUA接口返回字符串
//如果是标准格式:如下
//{"error":0,"ret":AAA,"data":XXX}
//XXX:根据实际LUA文件返回值而定
//其他自定义格式可自行在LUA文件中返回后自行解析(字符串就行,一般格式化为标准json字符串,字段可自定义)
HEARTDLL_API_HDLUA __int64  __stdcall  HCLUA_ReadFile(__int32 窗口序号, char*文件名路径, __int32 LUA标识符, BOOL 是否执行 = FALSE, BOOL 是否需要拿到返回值 = FALSE, BOOL 是否主线程调用 = FALSE);


//【初始化环境才有效】
//说明:调用HCLUA_CloseLua
//函数名:关闭LUA线程
//参数:
//LUA标识符:调用【HCLUA_ReadFile】接口指定的【LUA标识符】参数,一一对应,-1表示全部LUA线程退出！！！
//注意:
//1.只有当【是否需要拿到返回值】为真的时候才能创建一个线程执行,这个时候调用这个接口并指定标识符就可以退出线程
HEARTDLL_API_HDLUA __int64  __stdcall  HCLUA_CloseLua(__int32 窗口序号, __int32 LUA标识符 = -1);

//【初始化环境才有效】
//说明:调用HCLUA_ExcuteCall
//函数名:执行lua文件中注入的Function
//参数:
//参数数量:目前最大支持6个参数,一般够用了
//成功返回:
//根据实际LUA接口返回字符串
//标准返回格式:
//{"error":0,"ret":AAA,"data":XXX}
//AAA:根据实际LUA文件返回值而定
//XXX:根据实际LUA文件返回值而定
//他值自定义(返回Json字符串)
//注意:自定义json字符串中要有一个ret的key,而value可自定义,不要与上面值重复就行,如果是成功也可以用1表示
HEARTDLL_API_HDLUA __int64  __stdcall  HCLUA_ExcuteCall(__int32 窗口序号, char*函数名, __int32 参数数量 = 0, __int64 rcx = 0, __int64 rdx = 0, __int64 r8 = 0, __int64 r9 = 0, __int64 lparam5 = 0, __int64 lparam6 = 0, BOOL 是否主线程调用 = FALSE);
