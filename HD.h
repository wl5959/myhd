#pragma once
#include "HDAi.h"//AI识别模块
#include "HDAsm.h"//汇编模块
#include "HDCapScreen.h"//截图接口
#include "HDCpuGpu.h"//优化黑屏CPU模块
#include "HDDriverhd.h"//HD驱动模块
#include "HDDrivern.h"//HN驱动模块
#include "HDGame.h"//游戏模块
#include "HDLua.h"//LUA模块
#include "HDMemory.h"//内存模块
#include "HDMKB.h"//后台图色键鼠模块
#include "HDModule.h"//模块组件模块
#include "HDEnDe.h"//加密解密模块
#include "HDFindPic.h"//像素找图模块
#include "HDSystem.h"//系统模块
#include "HDWindow.h"//窗口模块
#include "HDController.h"//控制器模块
#include "HDStatusTask.h"//状态机任务模块
#include "HDStatus.h"//状态机模块
#include "HDStatusControler.h"//状态控制器模块
#include "HDFindStr.h"//识字模块
#include "HDGoogleBrowser.h"//谷歌浏览器模块
#include "HDHook.h"//HOOK模块
#include "HDIP.h"//IP模块
#include "HDMutilThread.h"//多线程模块
#include "HDScrcpy.h"//主板机 模拟器安卓手机投屏模块
#include "HDVmDma.h"//虚拟机DMA模块
#include "HDHelper.h"//帮助类 比如:json
//本CPP接口为环境接口
//【======================================================================验证========================================================】
HEARTDLL_API __int64  __stdcall  HCHD_Login(char* account, char * password, char*appName, char*appLparam, BOOL bAutoUpdate = FALSE, BOOL bShowMsgBox=FALSE);

HEARTDLL_API __int64  __stdcall  HCHD_GetLastLoginFYI();

HEARTDLL_API __int64  __stdcall  HCHD_GetExpiredTimeStamp();

HEARTDLL_API __int64  __stdcall  HCHD_GetFYI();

HEARTDLL_API __int64  __stdcall  HCHD_GetOpenMaxNum();

HEARTDLL_API __int64  __stdcall  HCHD_GetVersion();

//初始化中控验证
HEARTDLL_API __int64  __stdcall  HCHD_Init(char* account, char * password, char*appName = NULL, char*appLparam = NULL, BOOL bAutoUpdate = FALSE, BOOL bShowMsgBox = FALSE, BOOL bOnlyInit = FALSE, BOOL bOnlyLogin = FALSE);

//返回在线数量或错误值 具体信息通过中控缓冲区获取
HEARTDLL_API __int64  __stdcall  HCHD_GetOnlineClients();//后5-10

//通过客户端ID来强制关闭客户端链接
//checkFunCallBack:踢掉前会触发 返回1 表示确定踢掉
//closeFunCallBack:踢掉成功后触发 返回-1 表示中断操作 剩下的CID就不踢掉了
//cid1|cid2|cid3|
HEARTDLL_API __int64  __stdcall  HCHD_CloseOnlineByCID(char *cidInfo, __int64 checkFunCallBack = NULL, __int64 closeFunCallBack = NULL);//后5-10

//注册接口
HEARTDLL_API __int64  __stdcall  HCHD_UserRegister(char* szUsername, char* szPassword, char* szSuperPWD, char* szRechargeCards);//后


HEARTDLL_API __int64  __stdcall  HCHD_AF(char* szUsername, char* numStr, float money, int num);//

HEARTDLL_API __int64  __stdcall  HCHD_Offline();//

HEARTDLL_API __int64  __stdcall  HCHD_IgnoreFre(BOOL bFre);//

//修改接口
HEARTDLL_API __int64  __stdcall  HCHD_UserChangePWD(char* szSuperPWD, char* szNewPWD);//后

//获取备注
HEARTDLL_API __int64  __stdcall  HCHD_UserGetRemarks();//获取备注

//获取当前客户端CID
HEARTDLL_API __int64  __stdcall  HCHD_UserGetCID();//

//获取全局中控缓冲区 主线程调用最好
HEARTDLL_API char* __stdcall  HCHD_GetGlobalBuffer();

//后台用户使用系统
//初始化并连接或者断开后台使用信息服务器
//bOpen:真 连接服务器 反之断开服务器
//notifyFunCallBack:通知回调
HEARTDLL_API __int64  __stdcall  HCBSU_Init(BOOL bOpen = TRUE, __int64 notifyFunCallBack = NULL);

//请求获取当前登录账号的使用信息
//会触发通知回调 告诉数据已经获取到了 可以提取
HEARTDLL_API __int64  __stdcall  HCBSU_GetUseInfo();

//黑名单系统
//初始化并连接或者断开后台黑名单服务器
//bOpen:真 连接服务器 反之断开服务器
//notifyFunCallBack:通知回调
HEARTDLL_API __int64  __stdcall  HCBSN_Init(BOOL bOpen = TRUE, __int64 notifyFunCallBack = NULL);

//请求获取当前登录账号的黑名单信息
//会触发通知回调 告诉数据已经获取到了 可以提取
HEARTDLL_API __int64  __stdcall  HCBSN_GetBNInfo();


HEARTDLL_API __int64  __stdcall  HCBSN_AddBNInfo(char* mcode, char* ip1, char* ip2, char* remark);


HEARTDLL_API __int64  __stdcall  HCBSN_DeleteBNInfo(int id);


HEARTDLL_API __int64  __stdcall  HCBSN_UpdateBNInfo(int id, char* mcode, char* ip1, char* ip2, char* remark);

//【======================================================================验证========================================================】

//开启/关闭捕捉异常
HEARTDLL_API __int64  __stdcall  HCHD_CatchException(BOOL bOpen = TRUE);

//【======================================================================环境加载========================================================】
//【参数解析说明】
//返回值表示: json字符串 格式如下
//"{"error":-2,"ret":0}" 或者 {"error":0,"ret":[{ "name": "Jack", "age": 18 }, { "name": "Jack", "age": 18 }]} 两种形式
//ret:根据实际调用的CALL而定,如下两种形式.
//第一种:"{"error":-2,"ret":0}"---->key:error value:错误代码(整数)----key:ret value:长整数类型返回值
//第二种:{"error":0,"ret":[{ "name": "Jack", "age": 18 }, { "name": "Jack", "age": 18 }]}---->key:error value:错误代码(整数)----key:ret value:json数组类型(数组大小根据实际返回而定)

//中控初始化开始就要调用 仅仅一次11
HEARTDLL_API __int64  __stdcall  HCEnv_Init(__int32 timeOut = 10000);

//中控初始化开始就要调用 仅仅一次11
HEARTDLL_API __int64  __stdcall  HCEnv_InitEx(__int32 通讯超时毫秒 = 10000, __int32 通讯检测间隔毫秒 = 20, __int32 回调响应毫秒 = 5);


//设置通讯检测间隔时间 默认20MS检测一次返回值 
//注意:
//1.值越小响应越快,随之带来的效率更高但是会导致CPU利用率变高
//2.值的大小根据当前的项目指定,对于一直要实时响应的最好小点
HEARTDLL_API __int64  __stdcall  HCEnv_SetCheckComItlTime(__int32 通讯检测间隔毫秒 = 20);

//设置跨进程回调响应检测时间 默认5MS检测一次返回值
//注意:
//1.值越小响应越快,随之带来的效率更高但是会导致CPU利用率变高
//2.值的大小根据当前的项目指定,对于一直要实时响应的最好小点
HEARTDLL_API __int64  __stdcall  HCEnv_SetCheckCallBackTime(__int32 回调响应毫秒 = 5);

//强制结束当前线程
//内部会对锁操作 
//循环拿到锁才会强制关闭并返回成功
//此接口小心使用
//1.不到万不得已不要强制关闭线程(因为强制关闭线程不管在任何时候都有可能造成不可能预计的BUG)
//2.调用此接口的线程不要和结束的线程是同一个(虽然内部有检查)
//3.该接口如果参数:是否操作锁为真,那么会堵塞,直到拿到锁权限后,才会强制关闭线程,然后解锁(防止死锁).
HEARTDLL_API __int64  __stdcall  HCEnv_TerminateThread(__int32 窗口序号, __int32 threadId, BOOL 是否操作锁 = TRUE);

//指定线程句柄 
//注意事项同上   这个一般用于多线程模块 内部配合使用
HEARTDLL_API __int64  __stdcall  HCEnv_TerminateThreadEx(__int32 窗口序号, __int64 threadHandle, BOOL 是否操作锁 = TRUE);//version!

//获取通讯插件所绑定的目标进程的执行线程环境信息
//用于调试
//返回字符串:序号:进程ID:进程ID,窗口序号,线程ID,执行状态|进程ID,窗口序号,线程ID,执行状态|进程ID,窗口序号,线程ID,执行状态
HEARTDLL_API __int64  __stdcall  HCEnv_GetExcuteEnvInfo(__int32 窗口序号);

//中控初始化开始就可以调用 仅仅一次
//当使用【HDDebug.dll】导入接口的时候就需要调用这个设置为调试模式(否者插件可能安装不成功)
//然后方可继续后面的一系列操作
HEARTDLL_API __int64  __stdcall  HCEnv_Debug(BOOL 是否调试 = FALSE);

//当验证断开 会打开文件提示和记录日志
HEARTDLL_API __int64  __stdcall  HCEnv_MsgFile(BOOL 是否文件提示 = TRUE);


HEARTDLL_API __int64  __stdcall  HCEnv_PrintLog(BOOL 是否打印日志 = TRUE);

//添加安全函数
//函数地址(自己的子函数地址)
//从函数地址开始+偏移地址 开始保护
//从函数地址开始+偏移地址 开始保护多少字节
HEARTDLL_API __int64  __stdcall  HCEnv_ProtectFun(__int64 funAddr,__int32 offset,__int32 size);

//给中控附加心跳
//type: 0->正常心跳(内部触发) 1->通讯线程 2->主线程 3->卡屏 6->1+2+3
//如果需要检测主线程心跳是否卡住,请记得先HOOK主线程【HC_HookMainThread()】接口
//timeOutNorL:正常心跳间隔时间  如果在超过这个正常心跳间隔期间没有检查到对应的窗口异常 就会触发正常心跳 可以用来排序窗口等操作
//timeOut:检测超时,当超过这个时间相关值没有发现改变,则判定为卡住或者掉线
//funCallbackAddr:当出现卡住或者掉线会触发相应的回调函数,并传递2个参数分别是->窗口索引和事件类型
//typedef __int32(__stdcall *HeartFunType)(__int32 窗口索引, __int32 type);
//回调函数返回值:1 正常处理返回 0禁止当前窗口序号的心跳(永久无法恢复)
HEARTDLL_API __int64  __stdcall  HCEnv_AttachHeart(__int32 type, __int64 funCallbackAddr, __int32 timeOutNor = 10000, __int32 timeOut = 10000);//version!

//设置窗口排序信息
//x:屏幕左上角X开始
//x:屏幕左上角Y开始
//offsetx:每列的X偏移
//offsety:每行的Y偏移
//cols:列数 一排有多少个窗口 -1表示 一排无限窗口
//funCallbackAddr:排序窗口回调  这个在触发正常心跳回调的时候会触发  必须HCEnv_AttachHeart附加心跳 才有效
//回调类型:	typedef __int32(__stdcall *WindowsSortFunType)(__int32 窗口索引, __int32 pid, __int32 x, __int32 y);
HEARTDLL_API __int64  __stdcall  HCEnv_SetWindowsSortInfo(__int32 x, __int32 y, __int32 offsetx, __int32 offsety,__int32 cols, __int64 funCallbackAddr);


//当我们心跳检测指定了3或者6 需要设置卡屏范围和卡屏检测次数
//当大于这个次数 就调用回调
HEARTDLL_API __int64  __stdcall  HCEnv_SetScreenCheckHeart(__int32 x, __int32 y, __int32 w, __int32 h, __int32 最大次数,__int32 截屏前后间隔时间 = 1000);

//脱离心跳检测
//关闭 会堵塞
//一般中控进程结果关闭前调用
HEARTDLL_API __int64  __stdcall  HCEnv_DetachHeart();


//每次打开进程后都要调用
HEARTDLL_API __int64  __stdcall  HCEnv_Load(__int32 窗口序号, __int32 目标进程PID, __int32 游戏类型 = 0);

//每次打开进程后都要调用
//DMA VNC 操作虚拟机时候 加载环境 一般不自己调用
HEARTDLL_API __int64  __stdcall  HCEnv_LoadVm(__int32 窗口序号, __int32 vmPid = 0, __int32 vmPort = 0, __int32 游戏类型 = 0);

//每次打开进程后都要调用
HEARTDLL_API __int64  __stdcall  HCEnv_LoadDevices(__int32 窗口序号, __int32 目标进程PID, char* devicesName, __int32 devicesType, __int32 游戏类型 = 0);

//每次打开进程后都要调用
HEARTDLL_API __int64  __stdcall  HCEnv_LoadEx(__int32 窗口序号, __int32 目标进程PID, __int32 游戏类型 = 0, BOOL 是否开启接受线程 = FALSE);

//设置接受事件回调函数 中控处理目标进程发送过来的事件
HEARTDLL_API __int64 __stdcall  HCEnv_SetHandleEventCallBack(__int64 funCallBack);

//设置关闭回调函数  当HD出现异常或者失效 会自动关闭自身在期间会先调用这个回调(这个回调自己做好关闭前处理工作) 然后调用微软API接口ExitProcess();
HEARTDLL_API __int64 __stdcall  HCEnv_SetShutDownCallBack(__int64 funCallBack);

//设置PID检查回调
//checkFun:检查回调 和 安装插件那个检查回调一样的函数类型  触发条件:内部检查到PID不存在 就会触发这个回调
HEARTDLL_API __int64  __stdcall  HCEnv_SetPidCheckBack(__int64 checkFun);

//设置接受事件跨进程回调函数 目标进程发送过来的回调触发 一般用于HOOK各种API/函数/接口
//HEARTDLL_API __int64 __stdcall  HCEnv_SetHandleProcessCallBack(__int32 funProCallBack);

//【最后脚本关闭必须卸载环境或者进程关闭】
//说明:卸载环境 
//1.取消窗口关联,一定要卸载相关信息,随后所有循环会快速内退,从而线程安全退出
//窗口序号:窗口序号
//返回值:0释放失败  1成功释放
HEARTDLL_API __int64  __stdcall HCEnv_UnLoad(__int32 窗口序号);

//【最后脚本关闭必须卸载环境或者进程关闭】
//说明:卸载环境扩展版本
//1.取消窗口关联,一定要卸载相关信息,随后所有循环会快速内退,从而线程安全退出
//bRecon:是否还需要重连 默认是需要重连 不需要重连内部会关闭绑定的进程调用的接口是HCEnv_ExitProcess
//返回值:0释放失败  1成功释放
HEARTDLL_API __int64  __stdcall HCEnv_UnLoadEx(__int32 窗口序号, BOOL bRecon = TRUE);

//关闭绑定的目标窗口
//内部实现:可能是正常关闭也可能是强制关闭 至于是哪一种会根据实际情况动态调用
HEARTDLL_API __int64  __stdcall HCEnv_ExitProcess(__int32 窗口序号);

HEARTDLL_API  __int64  __stdcall  HCEnv_AddThread(__int32 窗口序号, __int32 线程ID, __int32 bDebug = 0);

HEARTDLL_API char* __stdcall HCEnv_GetRetJson(__int32 窗口序号);

HEARTDLL_API __int64 __stdcall HCEnv_GetRetValue(__int32 窗口序号);

HEARTDLL_API char* __stdcall HCEnv_GetErrorStr(__int32 ret);

//全局设置进程位数
HEARTDLL_API __int64  __stdcall HCEnv_SetProcessType(__int32 进程位数);

//指定某个序号绑定的进程位数
HEARTDLL_API __int64  __stdcall HCEnv_SetProcessTypeEx(__int32 窗口序号,__int32 进程位数); 

HEARTDLL_API __int64  __stdcall HCEnv_GetLastError();
//【======================================================================测试========================================================】
//【初始化环境后才能调用】
//说明:调用测试CALL 
//1.参数默认为0
//2.此函数为测试CALL 测试是否通讯成功
//3.支持多线程两种版本 一个返回json长整型值 一个返回json数组 具体解析参考上面【参数解析说明】
HEARTDLL_API __int64  __stdcall  HCEnv_TestCALL_RetValue(__int32 窗口序号, __int64 rcx = 0, __int64 rdx = 0, __int64 r8 = 0, __int64 r9 = 0, __int64 lparam5 = 0, __int64 lparam6 = 0, BOOL 是否主线程调用 = FALSE);

HEARTDLL_API __int64  __stdcall  HCEnv_TestCALL_RetArray(__int32 窗口序号, __int64 rcx = 0, __int64 rdx = 0, __int64 r8 = 0, __int64 r9 = 0, __int64 lparam5 = 0, __int64 lparam6 = 0, BOOL 是否主线程调用 = FALSE);

//【初始化环境后才能调用】
//说明:调用HHIT2_RetEnv
//1.此函数返回环境指针 环境中包含了环境信息
//2.这个用于内部测试 需要知道内部结构 调用此CALL需要谨慎
HEARTDLL_API void* __stdcall  HCEnv_RetEnv();

HEARTDLL_API void __stdcall  HCEnv_RetEnvLock();

HEARTDLL_API void __stdcall  HCEnv_RetEnvUnLock();

//【初始化环境后才能调用】
//说明:调用HHIT2_RetEnv
//1.此函数返回环境指针 环境中包含了环境信息
//2.这个用于内部测试 需要知道内部结构 调用此CALL需要谨慎
//3.比上面2个测试CALL多了1个指定线程ID的参数
HEARTDLL_API __int64  __stdcall  HCEnv_TestCALL_RetValueEx(__int32 窗口序号, __int32 线程ID, __int64 rcx = 0, __int64 rdx = 0, __int64 r8 = 0, __int64 r9 = 0, __int64 lparam5 = 0, __int64 lparam6 = 0, BOOL 是否主线程调用 = FALSE);

HEARTDLL_API __int64  __stdcall  HCEnv_TestCALL_RetArrayEx(__int32 窗口序号, __int32 线程ID, __int64 rcx = 0, __int64 rdx = 0, __int64 r8 = 0, __int64 r9 = 0, __int64 lparam5 = 0, __int64 lparam6 = 0, BOOL 是否主线程调用 = FALSE);

//【======================================================================获取环境信息=======================================================】

HEARTDLL_API __int64 __stdcall  HCInject_Init(__int32 窗口序号, BOOL 是否重置 = FALSE);

HEARTDLL_API __int64  __stdcall  HCInject_InitEx(__int32 窗口序号, char *预加载LUA模块全路径, BOOL 是否重置 = FALSE);

//addType:添加方式 -1默认或者0或者1无痕 2普通加载
HEARTDLL_API __int64 __stdcall  HCInject_InitExx(__int32 窗口序号, char *预加载DLL模块全路径 = NULL, char *预加载LUA模块全路径 = NULL, __int32 addType = -1, BOOL 是否重置 = FALSE);

HEARTDLL_API __int64  __stdcall  HCInject_GetPid(__int32 窗口序号);

HEARTDLL_API CHAR* __stdcall  HCInject_GetGlobalRetInfo(__int32 窗口序号);//支持0

//通过设置
//存自定义二进制数据 总大小1024
//可以字符串 JSON 其他类型值
HEARTDLL_API __int64  __stdcall  HCInject_SetData(__int32 窗口序号, void *用户数据缓冲区, __int32 数据大小);

//取自定义二进制数据 总大小1024
//可以字符串 JSON 其他类型值
HEARTDLL_API __int64  __stdcall  HCInject_GetData(__int32 窗口序号, void *用户数据缓冲区, __int32 缓冲区大小);

//通过查找
//mis<=0 表示不需要循环获取  >0表示内部循环获取句柄 直到有值
HEARTDLL_API __int64  __stdcall  HCInject_GetHwnd(__int32 窗口序号, char* className, char* title, __int32 filter, BOOL bType, __int32 mis = 0);

//这个是内部自己设置的 一般用于定制
HEARTDLL_API __int64  __stdcall  HCInject_GetHwndEx(__int32 窗口序号);

HEARTDLL_API __int64  __stdcall  HCInject_GetPrePid(__int32 窗口序号);//获取不到 就表示新窗口

HEARTDLL_API __int64  __stdcall  HCInject_GetPreWinIndex(__int32 pid);//通过进程PID尝试拿到绑定的窗口序号 失败-1

//扩展版本 给扩展接口使用
//checkFun:检查回调 和 安装插件那个检查回调一样的函数类型
//winIndex:传递的安装插件方式传递的序号 
//checkFun:返回值 0表示不存在PID 其他值正常操作
HEARTDLL_API __int64  __stdcall  HCInject_GetPreWinIndexEx(__int32 pid,__int32 winIndex,__int64 checkFun);//通过进程PID尝试拿到绑定的窗口序号 失败-1

HEARTDLL_API __int64  __stdcall  HCInject_Continue(__int32 窗口序号);

HEARTDLL_API __int64  __stdcall  HCInject_GetLastInfo(__int32 窗口序号);

//设置插件信息
//版本名 为空 则根据不同版本内置了DLL名字
HEARTDLL_API __int64  __stdcall  HCInject_SetPlugin(char*发布版本DLL名 = NULL, char* 调试版本DLL名 = NULL);
//【======================================================================二次通讯封装(扩展)========================================================】
//安装接口类型
//接口类型说明funType->7种安装插件方式
//				接口名								  funType			方式  是否需要驱动		打开回调返回值
//HCHD_InstallPlugX64 HCHD_InstallPlugX86				 1				自动 需要HD驱动			openFun返回任意(无用处)
//HCHD_NormalInstallPlugX86X64							 2				pid  需要HD驱动			openFun返回pid(替换指定)
//HCHD_NormalInstallPlugX86X64							 3				hwnd 需要HD驱动			openFun返回句柄(替换指定)
//HCHD_NormalInstallPlugX86X64Ex						 4				pid  需要HD驱动			openFun返回pid(替换指定)
//HCHD_NormalInstallPlugX86X64Ex						 5				hwnd 需要HD驱动			openFun返回句柄(替换指定)
//HCN_NormalInstallPlugX64 HCN_NormalInstallPlugX86		 6				pid  不需要驱动			openFun返回pid(替换指定)
//HCN_NormalInstallPlugX64Ex HCN_NormalInstallPlugX86Ex  7				hwnd 不需要驱动			openFun返回句柄(替换指定)
//HCHDVT_InstallPlugX64 HCHDVT_InstallPlugX86		     8				pid  需要HDHOOK驱动		openFun返回pid(替换指定)
//HCHDVT_InstallPlugX64 HCHDVT_InstallPlugX86			 9				hwnd 需要HDHOOK驱动		openFun返回句柄(替换指定)
//注入驱动组件                               			 16/32/64		pid  需要HIDLL组件驱动	openFun返回PID(替换指定)
//注入驱动组件                               			 17/33/65		hwnd 需要HIDLL组件驱动	openFun返回句柄(替换指定)
//checkFun检查回调
//为了处理一些特殊情况
//检查回调checkFun->
//windowsIndex:当前指定序号
//preWindowsIndex:之前绑定的序号
//prePid:之前绑定的序号对应的PID
//error:RET_重连窗口(1重连直接进行加载环境 0新窗口) RET_重连窗口序号不一致(1重连并使用之前绑定的序号进行加载环境 0新窗口(需要用户在回调中把之前PID给关闭))
//返回值:-1表示中断
//typedef __int64(__stdcall*CHECKINSTALLPLUGINTYPE)(int windowsIndex, int preWindowsIndex, int prePid, int error);
//openFun打开回调
//打开回调openFun->
//windowsIndex:当前指定序号
//1.对于第一种方式不能为NULL
//2.其他方式可以为NULL
//typedef __int64(__stdcall*INSTALLPLUGINTYPE)(int windowsIndex);//返回进程PID
//
//说明:
//1.对于第一种方式打开回调不能为NULL, 内部先安装插件再触发回调打开进程(在打开回调中可以手动或者自动打开进程 1.如果是手动直接返回1就行或错误值表示中断操作 2.如果是自动返回对应的PID或错误值表示中断操作)
//2.其他二种方式打开回调可以为NULL, 表示进程已经打开了, 不需要在回调中打开, 此时使用指定的PID或者窗口句柄来安装插件, 具体是PID还是句柄请查看安装插件接口类型表
//3.返回值根据当前的安装插件方式不同有不同的含义 : （具体请看安装插件接口类型表和覆盖策略）

//3.1 方式二 是通过PID安装插件 那么返回值应该为打开进程的PID, 并把传递的PID参数给覆盖了(请看PID覆盖策略), 可以返回小于等于0的错误值或者不存在的PID, 从而中断安装插件退出, 不做相应的安装插件流程(初始化序号 - 获取PID - 加载环境 - 等待20 - 继续 - 等待120), 并把打开回调返回值当作安装插件返回值返回。

//3.1.1 PID覆盖策略

//1.如果指定的参数PID有效大于0并存在       同时打开回调返回的PID有效大于0并存在           就用打开回调返回的PID覆盖指定参数的PID
//2.如果指定的参数PID有效大于0并存在       同时打开回调返回的PID无效小于等于0不存在       就用指定参数的PID
//3.如果指定的参数PID无效小于等于0不存在   同时打开回调返回的PID无效小于等于0不存在       就直接返回错误
//4.如果指定的参数PID无效小于等于0不存在   同时打开回调返回的PID有效大于0并存在           就用打开回调返回的PID覆盖指定参数的PID 

//3.2 方式三 是通过窗口句柄安装插件 那么返回值应该为打开进程的句柄, 并把传递的句柄参数给覆盖了(请看窗口句柄覆盖策略), 可以返回小于等于0的错误值或者窗口句柄无效, 从而中断安装插件退出, 不做相应的安装插件流程(初始化序号 - 获取PID - 加载环境 - 等待20 - 继续 - 等待120), 并把打开回调返回值当作安装插件返回值返回。

//3.2.1 窗口句柄覆盖策略

//1.如果指定参数的窗口句柄有效 同时打开回调返回的的句柄有效 就用打开回调返回的句柄覆盖指定参数的句柄
//2.如果指定参数的窗口句柄有效 同时打开回调返回的的句柄无效 就用指定参数的句柄   
//3.如果指定参数的窗口句柄无效 同时打开回调返回的的句柄无效 就直接返回错误
//4.如果指定参数的窗口句柄无效 同时打开回调返回的的句柄有效 就用打开回调返回的句柄覆盖指定参数的句柄 

//
//当获取到之前PID不为0会触发  用户可以自行判断也可以直接不判断(直接返回1) 返回1表示重连 返回0表示新窗口 如果为NULL表示自动判断
//第一种:打开前安装
//appType:进程类型 必须指定32或者64 来指定当前绑定的进程位数 不能为0
//checkFun:NULL表示 当ERROR==RET_重连窗口 默认处理重连   当ERROR==RET_重连窗口序号不一致 默认处理直接返回错误
HEARTDLL_API __int64  __stdcall  HDEX_InstallPlugin1(__int32 winIndex, char*app, int appType, int injectType, int memType, int gameType, BOOL bAccept, __int64 openFun, __int64 checkFun = NULL, int timeOut = 30000);
//第二种:打开后安装 通过PID 
//appType:进程类型 appType=0表示自动判断(可能判断失败) 也可以手动指定32或者64 来指定当前绑定的进程位数 
//checkFun:NULL表示 当ERROR==RET_重连窗口 默认处理重连   当ERROR==RET_重连窗口序号不一致 默认处理直接返回错误
HEARTDLL_API __int64  __stdcall  HDEX_InstallPlugin2(__int32 winIndex, int funType, int pid, int appType, int gameType, BOOL bAccept, __int64 openFun = NULL, __int64 checkFun = NULL, int timeOut = 30000);
//第三种:打开后安装 通过窗口句柄
//appType:进程类型 appType=0表示自动判断(可能判断失败) 也可以手动指定32或者64 来指定当前绑定的进程位数 
//checkFun:NULL表示 当ERROR==RET_重连窗口 默认处理重连   当ERROR==RET_重连窗口序号不一致 默认处理直接返回错误
HEARTDLL_API __int64  __stdcall  HDEX_InstallPlugin3(__int32 winIndex, int funType, __int64 hwnd, int appType, int gameType, BOOL bAccept, __int64 openFun = NULL, __int64 checkFun = NULL, int timeOut = 30000);
//第四种:打开后安装 通过PID 针对虚拟机 内部自动关联虚拟机
//从第二种继承过来的用法一样 funType:2 4 6 8 16 32 64
//vmPid:虚拟机PID 或者 打开回调指定
//vncPort:虚拟机VNC端口 -1表示不连接VNC 大于0表示连接VNC(会断开后重新连接) 0为使用之前的缓存VNC端口(会断开后重新连接)
//checkFun:NULL表示 当ERROR==RET_重连窗口 默认处理重连   当ERROR==RET_重连窗口序号不一致 默认处理直接返回错误
//openFun:可以在打开回调里面实现打开虚拟机 返回PID
//调用之前记得打开服务器并确定正确
//其他规则和前3种安装插件方式一致
HEARTDLL_API __int64  __stdcall  HDEX_InstallPluginVM(__int32 winIndex, int funType, int vmPid, int vncPort, int appType,__int64 openFun = NULL, __int64 checkFun = NULL, int timeOut = 30000);

//【======================================================================窗口扩展序号========================================================】

//获取副窗口序号
//winIndex:传递窗口序号 返回一个与当前指定的窗口序号的一个副窗口序号
//这个副窗口序号可以用于登录器的绑定和操作,相当于窗口序号的一个助手,做一些额外的事情
//相当于一个窗口序号可以操作2个进程
//如:窗口序号1 那么他返回的窗口扩展序号就是1+31 也就是32序号
HEARTDLL_API __int64  __stdcall HCEnv_GetWinExIndex(__int32 winIndex);


//获取全局副窗口序号,这是一个全局的序号
//一个中控仅有一个
//计算方式:0+31  也就是这个全局序号为31  序号从0开始
//用途:
//给当前中控分配一个助手,来控制一个进程来辅助中控做一些事情
HEARTDLL_API __int64  __stdcall HCEnv_GetGlobalWinExIndex();


//获取最大窗口数
//窗口序号不能大于等于这个返回值同时也不能小于0
HEARTDLL_API __int64  __stdcall HCEnv_GetMaxWindowNum();

//【======================================================================HDQ旗舰版接口========================================================】
//旗舰版登录:登录+初始化中控+加载组件
//account:账号
//password:密码
//comInfo:组件加载信息 如:"1+2+3"表示 依次加载组件 1 2 3 空表示不加载任何组件 具体组件功效看开发手册
//recPath:全局资源路径(所有序号通用) 绝对路径 默认为空 表示没有设置
//返回值:大于0表示:当前服务器最新版本号(并不是当前插件版本号) 小于0表示:具体错误值 等于0表示:未管理员运行
HEARTDLL_API __int64  __stdcall  HDQ_Reg(char* account, char * password, char* comInfo = NULL, char *recPath = NULL);


//旗舰版绑定:截图+键鼠 同时内部会自动调用安装方式3(新版本可无痕注入配合新注入组件2或25)
//winIndex:窗口序号 窗口序号与进程进行绑定 后续就可以使用相关窗口序号的接口来操作进程了
//hwnd:窗口句柄 窗口句柄 自动判断进程位数 注意:不指定句柄则打开回调参数必须填写同时打开回调返回需要绑定的窗口句柄
//bindInfo:截图键鼠绑定属性 默认空是 "1>>1|0|1|1|1|1|1|0|0|0|1|1|1|0|1|0|0|0|0|0|" 其中 1:绑定截图模式 >>:分隔符  1|0|1|1|1|1|1|0|0|0|1|1|1|0|1|0|0|0|0|0|:后台键鼠绑定模式或"normal"前台键鼠绑定模式 可以单独指定如:"17"只开启截图不开启键鼠 或者 "0>>1|0|1|1|1|1|1|0|0|0|1|1|1|0|1|0|0|0|0|0|" 表示开启键鼠不开截图
//bindMode:键鼠绑定模式 0 1 2 3 默认0模式常用
//bUnRetMove:是否不刷新 默认0需要刷新  针对一些顶层窗口句柄最好为0 如果内层窗口句柄为1最好不需要刷新
//appType:进程位数类型 默认0表示自动判断(可能判断失败) 也可以手动指定32或者64 来指定当前绑定的进程位数 
//injectType:插件注入模式 默认5(HD驱动注入需要安装HD驱动(-1/0/1/6))  一共有:3 5 7 9 17 33 65 共7种注入模式 分别对应的驱动组件[注入模式:(3/5/7 有痕注入)需要HD驱动组件(-1/0/1/6) 注入模式:(9 无痕注入)需要组件2 注入模式:(17/33/65 无痕注入)需要组件25]
//bAccept:是否开启接受线程 默认0不开启  一般用于HOOK通讯之类的交互
//openFun:打开回调 默认可为空 表示自己写打开游戏逻辑
//checkFun:检查回调 默认空表示 使用内置检查回调
//timeOut:超时时间 默认60秒
HEARTDLL_API __int64  __stdcall  HDQ_Bind(__int32 winIndex, __int64 hwnd = 0, char* bindInfo = NULL, __int32 bindMode = 0, __int32 bUnRetMove = 0, int appType = 0, __int32 injectType = 5, __int32 bAccept = 0, __int64 openFun = NULL, __int64 checkFun = NULL, int timeOut = 60000);

//HD旗舰版解绑:解绑顺序L: 键鼠->截图->环境
//winIndex:窗口序号 
//bKBM:是否卸载键鼠绑定 默认为0 不卸载键鼠绑定
//bCapture:是否关闭截图 默认为0 不卸载截图
//bEnv:是否卸载环境 默认为0 不卸载环境
//bUnRec:是否不需要重连(彻底卸载同时会自动关闭进程就需要为1) 如果需要重连设置为0 默认为0
HEARTDLL_API __int64  __stdcall  HDQ_UnBind(__int32 winIndex, int bKBM = 0, int bCapture = 0, int bEnv = 0, int bUnRec = 0);

//HEARTDLL_API __int64  __stdcall  HDQ_InitMultiThread(__int64 hwnd, void* updateUICallBackEx, void* loginCallBack, void* firstCallBack, void* secondCallBack, void* endCallBack, void* restartPreCallBack, void* endBindCallBack, void* pauseBindCallBack, void* recoverBindCallBack, void* UIlparam);

//【=======================================================================================================================================】
//【======================================================================可视化测试(用于调试)========================================================】
//(用于调试)
//设置全局可视化标注颜色值
//颜色值是4字节分别对应XRGB
//如:0x00FF0000 红色
//如:0x0000FF00 绿色
//如:0x000000FF 蓝色
HEARTDLL_API __int64  __stdcall  HCSD_SetColor(__int32 lineColor = 0x0000FF00, __int32 textColor = 0x00FFFF00, __int32 backColor = 0x00000000);

//(用于调试)
//设置当前调试窗口跟随的进程信息
//类名或标题名
HEARTDLL_API __int64  __stdcall  HCSD_SetFollowClassTitleName(__int32 pid, __int64 hwnd = NULL, char* className = NULL, char* titleName = NULL);

//用于标注
//hwnd:句柄
//LineRgbColor:线颜色
//lineSize:线大小
//type:0边框 1填充
//fillRgbColor:填充色RGB type=1 才有效
HEARTDLL_API __int64 __stdcall HCSD_DrawWinodws(__int64 hwnd, __int32 LineRgbColor, __int32 lineSize, __int32 type = 0, __int32 fillRgbColor = 0);


//工具测试速度用
HEARTDLL_API __int64 __stdcall HCSD_IsTestTool(BOOL b);


//附加控制台
//返回当前控制台是否已经打开
//printf cout 输入 输出到控制台上显示
//注意:自行定时清空屏幕 防止满屏卡主进程运行
HEARTDLL_API __int64 __stdcall HCSD_SetAttachConsole(BOOL bOpen);


