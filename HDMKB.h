#pragma once
#include <winsock2.h>
#include <windows.h>
#include "winDNS.h"
#define HEARTDLL_EXPORT_MKB
#ifdef HEARTDLL_EXPORT_MKB
#define HEARTDLL_API_MKB  extern "C" __declspec(dllexport) //导出
#else
#define HEARTDLL_API_MKB  extern "C" __declspec(dllimport) //导入
#endif

//【====================================================================通用操作==========================================================】
//不会堵住主线程的休眠
HEARTDLL_API_MKB __int64  __stdcall  HC_Sleep(__int64 mis);

//【====================================================================目标进程全局开关标志位==========================================================】
//目标进程是否使用VT驱动
//需要中控安装和开启VT驱动
//type:0不使用 1使用
//作用模块包含: 后台键鼠模块 谷歌内置浏览器模块 APIHOOK模块 自定义HOOK模块
//目的:过检测能力强
HEARTDLL_API_MKB __int64  __stdcall  HCTarget_UseVT(__int32 type);

//【====================================================================鼠标操作==========================================================】
//【初始化环境才有效】
//说明:调用HCMKB_Bind 绑定后台
//绑定属性—>字符串:"0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|"  20个值 1是选中 0未选中  为NULL表示全部选中
//dx.mouse.position.lock.api|dx.mouse.position.lock.message    1
//dx.mouse.focus.input.api|dx.mouse.focus.input.message    2
//dx.mouse.clip.lock.api    3
//dx.mouse.input.lock.api    4
//dx.mouse.state.api    5
//dx.mouse.api    6
//dx.mouse.cursor    7
//dx.mouse.raw.input      8
//dx.mouse.input.lock.api2    9
//dx.mouse.input.lock.api3    10
//dx.keypad.input.lock.api    11
//dx.keypad.state.api    12
//dx.keypad.api    13
//dx.keypad.raw.input    14
//dx.public.active.api    15
//dx.public.active.api2    16
//dx.public.input.ime    17
//dx.public.disable.window.show    18
//dx.public.down.cpu    19
//dx.public.focus.api    20

HEARTDLL_API_MKB __int64  __stdcall  HCMKB_Bind(__int32 窗口序号, __int64 hwnd, char *绑定属性 = NULL);//序号-1/0表示前台

HEARTDLL_API_MKB __int64  __stdcall  HCMKB_BindEx(__int32 窗口序号, __int64 hwnd, char *绑定属性 = NULL, __int32 bRetMove = 1);//序号-1/0表示前台

//mode->0通用模式 1加强模式(一些有保护窗口用这个尝试) 2内部流程不同于0模式(如果一些按键失效或者错乱或者小键盘失效,可以尝试这个2)
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_BindModeEx(__int32 窗口序号, __int64 hwnd, char *绑定属性 = NULL,__int32 mode = 0, __int32 bRetMove = 1);//序号-1/0表示前台

//切换绑定窗口句柄
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_SwitchBind(__int32 窗口序号, __int64 hwnd, char *绑定属性 = NULL);//序号-1/0表示前台

HEARTDLL_API_MKB __int64  __stdcall  HCMKB_SwitchBindEx(__int32 窗口序号, __int64 hwnd, char *绑定属性 = NULL, __int32 bRetMove = 1);//序号-1/0表示前台

//mode->0通用模式 1加强模式(一些有保护窗口用这个尝试)
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_SwitchBindModeEx(__int32 窗口序号, __int64 hwnd, char *绑定属性 = NULL, __int32 mode = 0, __int32 bRetMove = 1);//序号-1/0表示前台

//暂停或者恢复绑定窗口句柄
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_PauseBind(__int32 窗口序号, __int32 bPause = TRUE, __int32 bRetMove = 1);//序号-1/0表示前台

//【绑定窗口才有效】
//说明:调用HCMKB_UnBind 解绑定后台
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_UnBind(__int32 窗口序号);//序号-1/0表示前台

//【绑定窗口才有效】
//说明:调用HCMKB_MoveTo 后台移动鼠标
//轨迹类型:默认-1 或者1 表示随机轨迹 2表示直线轨迹
//capFeature: 光标特征值 默认0 表示不动态光标捕捉 不为0表示在开启轨迹的前提下 动态匹配光标特征并以字符串返回格式:“x1,y1|x2,y2|x3,y3|x4,y4|” 返回多个或单个
//bAllFind:在指定了 capFeature参数的情况下 是否全部找到符合光标特征值的坐标
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_MoveTo(__int32 窗口序号, __int32 x, __int32 y, BOOL 是否模拟鼠标轨迹 = TRUE, __int32 轨迹类型 = -1, __int32 窗口状态 = 0, __int32 capFeature = 0,__int32 bAllFind = 0);//序号-1/0表示前台


//【绑定窗口才有效】
//说明:调用HCMKB_MoveR 后台相对移动鼠标
//默认-1 或者1 表示随机轨迹 2表示直线轨迹
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_MoveR(__int32 窗口序号, __int32 x, __int32 y, BOOL 是否模拟鼠标轨迹 = TRUE, __int32 轨迹类型 = -1, __int32 窗口状态 = 0);//序号-1/0表示前台

//获取后台/前台鼠标位置
//窗口序号==-1 表示前台
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_GetMousePos(__int32 窗口序号);


//如果移动开启了轨迹 可以利用这个接口设置相关参数
//
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_SetRealMouse(__int32 步长 = 30, __int32 步数 = 100, __int32 每步延迟 = 20, char *json配置 = NULL, BOOL 开启调试 = FALSE);


//【绑定窗口才有效】
//说明:调用HCMKB_LeftDown 后台鼠标左键按下
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_LeftDown(__int32 窗口序号, __int32 窗口状态 = 0);//序号-1/0表示前台

//【绑定窗口才有效】
//说明:调用HCMKB_LeftUp 后台鼠标左键弹起
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_LeftUp(__int32 窗口序号, __int32 窗口状态 = 0);//序号-1/0表示前台

//【绑定窗口才有效】
//说明:调用HCMKB_LeftClick 后台鼠标左键点击一次
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_LeftClick(__int32 窗口序号, __int32 延时毫秒 = 50, __int32 窗口状态 = 0);//序号-1/0表示前台

HEARTDLL_API_MKB __int64  __stdcall  HCMKB_LeftDoubleClick(__int32 窗口序号, __int32 延时毫秒 = 50, __int32 窗口状态 = 0);

//【绑定窗口才有效】
//说明:调用HCMKB_RightDown 后台鼠标右键按下
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_RightDown(__int32 窗口序号, __int32 窗口状态 = 0);//序号-1/0表示前台

//【绑定窗口才有效】
//说明:调用HCMKB_RightUp 后台鼠标右键弹起
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_RightUp(__int32 窗口序号, __int32 窗口状态 = 0);//序号-1/0表示前台

//【绑定窗口才有效】
//说明:调用HCMKB_RightClick 后台鼠标右键点击一次
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_RightClick(__int32 窗口序号, __int32 延时毫秒 = 50, __int32 窗口状态 = 0);//序号-1/0表示前台

HEARTDLL_API_MKB __int64  __stdcall  HCMKB_RightDoubleClick(__int32 窗口序号, __int32 延时毫秒 = 50, __int32 窗口状态 = 0);

//【绑定窗口才有效】
//说明:调用HCMKB_MiddleDown 后台鼠标中键按下
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_MiddleDown(__int32 窗口序号, __int32 窗口状态 = 0);//序号-1/0表示前台

//【绑定窗口才有效】
//说明:调用HCMKB_MiddleUp 后台鼠标中键弹起
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_MiddleUp(__int32 窗口序号, __int32 窗口状态 = 0);//序号-1/0表示前台

//【绑定窗口才有效】
//说明:调用HCMKB_MiddleClick 后台鼠标中键点击一次
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_MiddleClick(__int32 窗口序号, __int32 延时毫秒 = 50, __int32 窗口状态 = 0);//序号-1/0表示前台


HEARTDLL_API_MKB __int64  __stdcall  HCMKB_MiddleDoubleClick(__int32 窗口序号, __int32 延时毫秒 = 50, __int32 窗口状态 = 0);

//【绑定窗口才有效】
//说明:调用HCMKB_WheelDown 后台鼠标滚轮滚下
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_WheelDown(__int32 窗口序号, __int32 窗口状态 = 0);//序号-1/0表示前台

//【绑定窗口才有效】
//说明:调用HCMKB_WheelUp 后台鼠标滚轮滚上
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_WheelUp(__int32 窗口序号, __int32 窗口状态 = 0);//序号-1/0表示前台


//【====================================================================键盘操作==========================================================】

//【绑定窗口才有效】
//说明:调用HCMKB_KeyDwon 模拟人输入敲击键盘按下 传递的是虚拟键码
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_KeyDown(__int32 窗口序号,__int32 虚拟键码, __int32 窗口状态 = 0);//序号-1/0表示前台

//【绑定窗口才有效】
//说明:调用HCMKB_KeyUp 模拟人输入敲击键盘弹起 传递的是虚拟键码
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_KeyUp(__int32 窗口序号, __int32 虚拟键码, __int32 窗口状态 = 0);//序号-1/0表示前台


//【绑定窗口才有效】
//说明:调用HCMKB_KeyPress 模拟人输入敲击键盘一次 传递的是虚拟键码
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_KeyPress(__int32 窗口序号, __int32 虚拟键码, __int32 延时毫秒 = 20, __int32 窗口状态 = 0);//序号-1/0表示前台


//【绑定窗口才有效】
//说明:调用HCMKB_KeyPressA 模拟人输入敲击键盘字母 传递的是ascii
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_KeyPressA(__int32 窗口序号, char * 文本, __int32 延时毫秒 = 20, __int32 窗口状态 = 0);
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_KeyPressW(__int32 窗口序号, wchar_t * 文本, __int32 延时毫秒 = 20, __int32 窗口状态 = 0);

HEARTDLL_API_MKB __int64  __stdcall  HCMKB_SendStringA(__int32 窗口序号, char * 文本A, __int32 延时毫秒 = 20, __int32 窗口状态 = 0);//序号-1/0表示前台
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_SendStringW(__int32 窗口序号, wchar_t * 文本W, __int32 延时毫秒 = 20, __int32 窗口状态 = 0);//序号-1/0表示前台
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_SendStringExW(__int32 窗口序号, char * 文本A, __int32 延时毫秒 = 20, __int32 窗口状态 = 0);

//【绑定窗口才有效】
//说明:调用HCMKB_SendString HCMKB_SendString2 发送字符串 一个一个字节发送
//参数:文本类型->1:ascii 2:unicode 3:utf-8
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_SendString(__int32 窗口序号, char * 文本A, __int32 延时毫秒 = 20, __int32 窗口状态 = 0);//!!
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_SendString2(__int32 窗口序号, char * 文本A, __int32 延时毫秒 = 20, __int32 窗口状态 = 0);

//指定句柄 游戏是unicode编码
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_SendStringF(__int64 hwnd, char * 文本A, __int32 延时毫秒 = 20, __int32 窗口状态 = 0);//!!

//指定句柄 游戏是utf编码
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_SendStringFU(__int64 hwnd, char * 文本A, __int32 延时毫秒 = 20, __int32 窗口状态 = 0);//!!

//指定句柄
//窗口序号可以为-1或者当前绑定的序号 hwnd参数为指定窗口句柄
//如果绑定了窗口 窗口句柄不能属于当前绑定的进程PID
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_SendDeleteTextF(__int32 窗口序号, __int64 hwnd, __int32 窗口状态 = 0);//!! 内部自动判断是否绑定过
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_SendKeyDownF(__int32 窗口序号, __int64 hwnd, __int32 虚拟键码, __int32 窗口状态 = 0);//!!  内部自动判断是否绑定过
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_SendKeyUpF(__int32 窗口序号, __int64 hwnd, __int32 虚拟键码, __int32 窗口状态 = 0);//!!  内部自动判断是否绑定过
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_SendKeyPressF(__int32 窗口序号, __int64 hwnd, __int32 虚拟键码, __int32 延时毫秒 = 20, __int32 窗口状态 = 0);//!!  内部自动判断是否绑定过
//
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_SendPaste(__int32 窗口序号, void* 发送字节缓冲区, __int32 发送字节大小, __int32 文本类型, __int32 mis = 20, __int32 窗口状态 = 0);//序号-1/0表示前台
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_SendPasteEx(__int32 窗口序号, void* 发送字节缓冲区, __int32 发送字节大小, __int32 文本类型, __int32 bSend = 0, __int32 mis = 20, __int32 窗口状态 = 0);
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_SendPasteExx(__int32 窗口序号, void* 发送字节缓冲区, __int32 发送字节大小, __int32 文本类型, __int32 bPause = 0, __int32 mis = 20, __int32 窗口状态 = 0);
//hd.dll/HDDebug.dll 同目录下hf.txt he.txt 
//文件编码为utf-8 
//随机获取一个姓和一个名组成一个词
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_SendRoundNamePaste(__int32 窗口序号,__int32 bSend = 0, __int32 mis = 20, __int32 窗口状态 = 0);
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_SendRoundNamePasteExx(__int32 窗口序号, __int32 bPause = 0, __int32 mis = 20, __int32 窗口状态 = 0);
//【====================================================================剪切板操作==========================================================】
//【直接调用就行】
//说明:调用HCMKB_GetClipboard 得到剪切板字符串文本
//参数:文本类型->1:ascii 2:unicode
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_GetClipboard(__int32 文本类型);

//说明:调用HCMKB_SetClipboard 设置剪切板字符串文本
//参数:文本类型->1:ascii 2:unicode
HEARTDLL_API_MKB __int64  __stdcall  HCMKB_SetClipboard(void* 发送字节缓冲区, __int32 发送字节大小, __int32 文本类型);
