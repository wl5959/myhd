#pragma once
#include <winsock2.h>
#include <windows.h>
#include "winDNS.h"
#define HEARTDLL_EXPORT_HD
#ifdef HEARTDLL_EXPORT_HD
#define HEARTDLL_API_HD extern "C" __declspec(dllexport) //导出
#else
#define HEARTDLL_API_HD extern "C" __declspec(dllimport) //导入
#endif
//【《HDDrvEx.sys》==========================================================HD模式驱动加载================================================================】
//说明
//1.加载的驱动文件名为《HDDrvEx.sys》 HD模式->不支持卸载(否则会蓝屏)
//2.调用接口进行驱动的安装
//3.支持自定义进程名 内存隐藏(0 1 2) 注入模式(0 1 2)
//4.比N模式更安全,缺点可能对于某些系统不稳定,同时不能卸载

//【打开游戏前调用】
//说明:加载驱动
HEARTDLL_API_HD __int64 __stdcall  HCHD_LoadDrv();

//说明:云下发 加载驱动或组件
//-1:HDEx正式版本(云下发 正常驱动与HCHD_LoadDrv是一个驱动) 2点/天
//0 : HDExx备用版本(云下发 适合驱动快读读写遍历) 2点/天
//1 : HDExxx定制版本(云下发 正常驱动, 可过网吧玄武盾) 3点/天
//2 : HDHOOK驱动(云下发 快速读写 VT无痕HOOK) 5点/天
//3 : HDPP保护驱动(云下发 进程保护和隐藏等保护) 2点/天
//4 : HDYOLOV识别(云下发  HYolov5 8 10 11 组件到当前路径并安装)
//5 : HDPW保护驱动(云下发 驱动深度窗口保护盾) 2点/天
//6 ：HDDExxxx过预启动驱动(云下发 正规可以过ACE 玄武 磐石预启动 功能和HD驱动一致 非特殊需求不要安装这个) 5点/天
//7 : HDPOCR识字识别(云下发 组件到当前路径并安装) 
//8 : HDPPEx驱动(云下发) 5点/天  无法和组件2共存 容易蓝屏
//9 : HDVTHOOK驱动(云下发 搭配使用) 5点/天 无法和组件2共存 容易蓝屏
//10~14:预留HD版本1档空位 0.2*0.7 共5个 根据实际情况动态调整 默认为 -1组件HD版本 2点/天
//15~19:预留HD版本2档空位 0.3*0.7 共5个 根据实际情况动态调整 默认为 -1组件HD版本 3点/天
//20~24:预留HD版本3档空位 0.5*0.7 共5个 根据实际情况动态调整 默认为 -1组件HD版本 5点/天
//25: HDDLL注入驱动(云下发 正规可以过ACE 玄武 磐石预启动) 3点/天
//100 占位
HEARTDLL_API_HD __int64 __stdcall  HCHD_LoadDrv2(__int32 type = 0);

//【打开游戏前调用】
//说明:HCHD_TestNotify 测试通讯
HEARTDLL_API_HD __int64  __stdcall  HCHD_TestNotify();


//说明:HCHD_InitFastRW 初始化快速读写
//如果使用的是HCHD_LoadDrv加载的驱动,这个时候又需要使用快速读写(HCHD_RWEx HCHD_RWExx),就需要调用这个接口初始化
//如果使用的是HCHD_LoadDrv2加载的驱动,这个时候就可以直接使用快速读写
HEARTDLL_API_HD __int64  __stdcall  HCHD_InitFastRW();

//【打开游戏前调用】
//说明:HCHD_TestLoad 测试安装
HEARTDLL_API_HD __int64  __stdcall  HCHD_TestLoad();

//【打开游戏前调用】
//说明:HCHD_CheckImage 检查模块回调 禁用
HEARTDLL_API_HD __int64  __stdcall  HCHD_CheckImage();

//【打开游戏前调用】
//说明:HCHD_ClearInject 清除注入
HEARTDLL_API_HD __int64  __stdcall  HCHD_ClearInject();

//【安装了HD驱动后调用】
//说明:注入DLL
//参数:
//injectExeName:进程名 如:"b2.exe"
//dllBits:DLL位数 32/64
//injectMode:0:注入 1:注入 2:Steam游戏注入
//memoryHide:0:不隐藏内存 1:隐藏内存 2:伪装内存
//injectData:DLL二进制数据
//injectSize:DLL二进制数据大小
//返回值:看说明 是无痕
HEARTDLL_API_HD __int64  __stdcall  HCHD_InjectX86X64(char* injectExeName, __int32 dllBits, __int32 injectMode, __int32 memoryHide, PVOID injectData, __int32 injectSize);

//指定路径注入DLL 是无痕
HEARTDLL_API_HD __int64  __stdcall  HCHD_InjectX86X64ByFile(char* injectExeName, __int32 dllBits, __int32 injectMode, __int32 memoryHide, char *DLL绝对路径A);

//安装HD插件 是无痕
HEARTDLL_API_HD __int64  __stdcall  HCHD_InstallPlugX64(char* injectExeName,__int32 injectMode, __int32 memoryHide);

//安装HD插件 是无痕
HEARTDLL_API_HD __int64  __stdcall  HCHD_InstallPlugX86(char* injectExeName,__int32 injectMode, __int32 memoryHide);

//安装HD插件 
//2个接口不是无模块注入
//pid:进程ID
//可以在打开进程的情况下注入
//驱动级别的
//普通方式注入1 有痕有模块注入
//dllBits：32/64
HEARTDLL_API_HD __int64  __stdcall  HCHD_NormalInstallPlugX86X64(__int32 pid, __int32 dllBits, BOOL bWait = TRUE);
HEARTDLL_API_HD __int64  __stdcall  HCHD_NormalInjectX86X64ByFile(__int32 pid, char *DLL绝对路径A,BOOL bWait = TRUE);
//普通方式注入2(加强版本) 无痕有模块注入
//dllBits：32/64
HEARTDLL_API_HD __int64  __stdcall  HCHD_NormalInstallPlugX86X64Ex(__int32 pid, __int32 dllBits, BOOL bWait = TRUE);
HEARTDLL_API_HD __int64  __stdcall  HCHD_NormalInjectX86X64ByFileEx(__int32 pid, char *DLL绝对路径A, BOOL bWait = TRUE);

//卸载HD插件
//说明:
//1.插件不是从游戏中卸载,而是下一次打开游戏不会加载插件了
HEARTDLL_API_HD __int64  __stdcall  HCHD_UnInstallPlug();

//【安装了HD驱动后调用】
//说明:鼠标模拟
//参数:窗口句柄,X,Y,鼠标按键代码[左/中/右](按下/弹起),毫秒延迟
//返回值:看说明
//#define 不按键 0x0
//#define 左键按下 0x1
//#define 左键弹起 0x2
//#define 右键按下 0x4
//#define 右键弹起 0x8
//#define 中键按下 0x10
//#define 中键弹起 0x20
//abx/aby:表示屏幕绝对坐标
HEARTDLL_API_HD __int64  __stdcall  HCHD_MousePress(__int32 abx, __int32 aby, __int32 mButCode, __int32 mis);

//x/y 表示窗口客户区坐标
HEARTDLL_API_HD __int64  __stdcall  HCHD_MousePressEx(__int64 hwnd, __int32 x, __int32 y, __int32 mButCode, __int32 mis);

//设置鼠标移动轨迹类型
//type:轨迹类型 -1或0 表示无轨迹  1 表示随机轨迹 2表示直线轨迹 3表示直线波动轨迹(过检测强) 
//返回:当前之前设置的类型
HEARTDLL_API_HD __int64  __stdcall  HCHD_SetMMTrackType( __int32 type);

//#define 不按键 0x0
//#define 左键按下 0x1
//#define 右键按下 0x4
//#define 中键按下 0x10
HEARTDLL_API_HD __int64  __stdcall  HCHD_MouseDown(__int64 hwnd, __int32 x, __int32 y, __int32 mButCode);

//#define 不按键 0x0
//#define 左键弹起 0x2
//#define 右键弹起 0x8
//#define 中键弹起 0x20
HEARTDLL_API_HD __int64  __stdcall  HCHD_MouseUp(__int64 hwnd, __int32 x, __int32 y, __int32 mButCode);

//【安装了HD驱动后调用】
//说明:键盘模拟
//参数:虚拟键码(按下/弹起),毫秒延迟
//返回值:看说明
HEARTDLL_API_HD __int64  __stdcall  HCHD_KbPress(__int32 virtualKeyCode, __int32 mis);

HEARTDLL_API_HD __int64  __stdcall  HCHD_KbDown(__int32 virtualKeyCode);

HEARTDLL_API_HD __int64  __stdcall  HCHD_KbUp(__int32 virtualKeyCode);
//【安装了HD驱动后调用】
//说明:读写 速度不适合大量遍历
//参数:进程ID,目标地址,数据缓冲区指针,数据缓冲区大小,读写类型[0=读内存;1=写内存;2=强写内存]
//返回值:看说明
HEARTDLL_API_HD __int64  __stdcall  HCHD_RW(__int32 pid, __int64 targetAddress, __int64 bufferAddress, __int32 bufferOfBytes, __int32 rwType);


//这个读取接口能实现百万级别的读写
HEARTDLL_API_HD __int64  __stdcall  HCHD_RWExx(__int32 pid, __int64 targetAddress, __int64 bufferAddress, __int32 bufferOfBytes, __int32 rwType);


//这个读取接口能实现百万级别的读写
//开始快读读写
HEARTDLL_API_HD __int64  __stdcall  HCHD_BeginRWEx(__int32 pid);

//【安装了HD驱动后调用】
//说明:读写 适合快速遍历
//参数:进程ID,目标地址,数据缓冲区指针,数据缓冲区大小,读写类型[0=读内存;1=写内存;2=强写内存]
//返回值:看说明
HEARTDLL_API_HD __int64  __stdcall  HCHD_RWEx(__int64 targetAddress, __int64 bufferAddress, __int32 bufferOfBytes, __int32 rwType);

//这个读取接口能实现百万级别的读写
//结束快速读写
HEARTDLL_API_HD __int64  __stdcall  HCHD_EndRWEx();


//【安装了HD驱动后调用】
//说明:进程保护
//参数:进程ID,操作[1=开启保护;0=关闭保护]
//返回值:看说明
HEARTDLL_API_HD __int64  __stdcall  HCHD_PP(__int32 pid, BOOL bOpen);

//【安装了HD驱动后调用】
//说明:进程隐藏
//参数:进程ID
//返回值:看说明
HEARTDLL_API_HD __int64  __stdcall  HCHD_PHide(__int32 pid);

//【安装了HD驱动后调用】
//说明:进程显示
//参数:进程ID
//返回值:看说明
HEARTDLL_API_HD __int64  __stdcall  HCHD_PShow(__int32 pid);

//【安装了HD驱动后调用】强力版本 只能隐藏不能恢复
//说明:进程隐藏强力版本
//参数:进程ID
//返回值:看说明
HEARTDLL_API_HD __int64  __stdcall  HCHD_PHideEx(__int32 pid);

//【安装了HD驱动后调用】
//说明:进程强杀
//参数:进程名
//返回值:看说明
HEARTDLL_API_HD __int64  __stdcall  HCHD_PPKill(char* processName, __int32 pid);

//【安装了HD驱动后调用】
//说明:地址是否可读
//参数:进程ID 地址 大小(只能是4或者8)
HEARTDLL_API_HD __int64  __stdcall  HCHD_AddrIsRead(__int32 pid, __int64 addr,__int32 size);

//【安装了HD驱动后调用】
//说明:申请内存
//参数:进程ID,申请大小,内存保护属性,是否申请高位内存,缓冲区指针
//返回值:看说明
HEARTDLL_API_HD __int64  __stdcall  HCHD_MemoryAllocate(__int32 pid, __int64 memorySize, __int32 memoryProtect, BOOL bHighAddress, __int64 pOutBuffer);

//指定内存地址申请内存
HEARTDLL_API_HD __int64  __stdcall  HCHD_MemoryAllocateEx(__int32 pid, __int64 memoryAddr, __int64 memorySize, __int32 memoryProtect, BOOL bHighAddress, __int64 pOutBuffer);

//【安装了HD驱动后调用】
//说明:释放内存
//参数:进程ID,内存地址
//返回值:看说明
HEARTDLL_API_HD __int64  __stdcall  HCHD_MemoryFree(__int32 pid, __int64 memoryAddress);


//【安装了HD驱动后调用】
//说明:内存属性修改
//参数:进程ID,内存地址,内存大小,新的保护
//返回值:看说明
HEARTDLL_API_HD __int64  __stdcall  HCHD_MemoryProtect(__int32 pid, __int64 memoryAddress, __int64 memoryOfBytes, __int32 newProtect);

//【安装了HD驱动后调用】
//说明:内存隐藏
//参数:进程ID,内存地址,内存大小
//返回值:看说明
HEARTDLL_API_HD __int64  __stdcall HCHD_MemoryHide(__int32 pid, __int64 memoryAddress, __int64 memoryOfBytes);

//【安装了HD驱动后调用】
//说明:内存查询
//参数:进程ID,内存地址,缓冲区指针[这里固定使用的是64位的MEMORY_BASIC_INFORMATION结构体,结构体大=48] MEMORY_BASIC_INFORMATION
//返回值:看说明
HEARTDLL_API_HD __int64  __stdcall HCHD_MemoryQuery(__int32 pid, __int64 memoryAddress, PVOID pOutBuffer);

//【安装了HD驱动后调用】
//说明:获取进程主模块信息
//参数:进程ID,模块基址缓冲区指针
//返回值:看说明
HEARTDLL_API_HD __int64  __stdcall HCHD_GetMainModuleBase(__int32 pid, __int64 outBuffer);

//【安装了HD驱动后调用】
//说明:获取进程指定模块基址
//参数:进程ID,模块名,模块基址缓冲区指针
//返回值:看说明
HEARTDLL_API_HD __int64  __stdcall HCHD_GetModuleBase(__int32 pid, char* moduleName, __int64 outBuffer);

//【安装了HD驱动后调用】
//说明:获取进程指定模块的函数地址
//参数:进程ID,模块名,函数名,地址缓冲区指针
//返回值:看说明
HEARTDLL_API_HD __int64  __stdcall HCHD_GetModuleCallAddr(__int32 pid, char* moduleName, char* callName, __int64 outBuffer);

//【安装了HD驱动后调用】
//说明:内存特征码查询
//参数:进程ID,起始搜索地址,特征码(二进制缓冲区不是字符串),特征码长度(字节单位),要搜索的内存保护属性,结果保存缓冲区
//返回值:看说明
HEARTDLL_API_HD __int64  __stdcall HCHD_MemoryFindCode(__int32 pid, __int64 address, __int64 siginCode, __int32 siginCodeSize, __int32 iProtect, __int64 outBuffer);

//【安装了HD驱动后调用】
//说明:开启动态虚拟机器码
//参数:类型
//0=全部开启
//1=注册表
//2=硬盘序列号
//3=网卡序列号
//4=本地文件特征
//5=微端设备序列号
//6=网络代理设备序列号
//7=图形处理器(GPU-GUID)
//8=分区序列号
//9=固态硬盘序列号
//10=主板BIOS序列号
//11=硬盘数据卷序列号(静态)
//12=硬盘数据卷序列号(动态)
//返回值:看说明
HEARTDLL_API_HD __int64  __stdcall HCHD_ChangeMachineKey(__int32 type);


HEARTDLL_API_HD __int64  __stdcall HCHD_NTNCaptureScreen(__int64 hWnd, BOOL Enable);


//【安装了HD驱动后调用】
//说明:内存远线程执行函数
//参数:进程ID,CALL地址
//返回值:看说明
HEARTDLL_API_HD __int64  __stdcall HCHD_NTThreadRunCall(__int32 pid, __int64 callAddress);


//【安装了HD驱动后调用】
//说明:句柄/进程PID提权
//参数:进程
//返回值:看说明
HEARTDLL_API_HD __int64  __stdcall HCHD_PcrocessRoot(__int32 pid);

HEARTDLL_API_HD __int64  __stdcall HCHD_HandleRoot(__int64 handle);




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////hdhook VT组件//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

HEARTDLL_API_HD __int64  __stdcall HCHDVT_AllocateMemory(__int32 pid, __int32 size);//申请内存

HEARTDLL_API_HD __int64  __stdcall HCHDVT_FreeMemory(__int32 pid, __int64 addr, __int32 size);//释放内存

HEARTDLL_API_HD __int64  __stdcall HCHDVT_Read(__int32 pid, __int64 addr, void* data, __int32 size);//读内存

HEARTDLL_API_HD __int64  __stdcall HCHDVT_Write(__int32 pid, __int64 addr, void* data, __int32 size);//写内存

HEARTDLL_API_HD __int64  __stdcall HCHDVT_GetModule(__int32 pid, char* moduleName);//取模块地址

HEARTDLL_API_HD __int64  __stdcall HCHDVT_GetModuleFun(__int32 pid, __int64 moduleAddr, char* funName);//取模块函数地址

HEARTDLL_API_HD __int64  __stdcall HCHDVT_Hook(__int32 pid, __int64 addr, void* data, __int32 size, __int32 type);//无痕HOOK内存

HEARTDLL_API_HD __int64  __stdcall HCHDVT_RemoteCall(__int32 pid, void* data, __int32 size);//远程CALL

HEARTDLL_API_HD __int64  __stdcall HCHDVT_InjectX64(__int32 pid, void* data, __int32 size);//注入x64 DLL

HEARTDLL_API_HD __int64  __stdcall HCHDVT_InjectX86(__int32 pid, void* data, __int32 size);//注入x86 DLL

HEARTDLL_API_HD __int64  __stdcall HCHDVT_InstallPlugX64(__int32 pid);//注入x64插件

HEARTDLL_API_HD __int64  __stdcall HCHDVT_InstallPlugX86(__int32 pid);//注入x86插件

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////hdpp组件//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


HEARTDLL_API_HD __int64  __stdcall HCHDPP_Protect(__int32 pid);//保护+隐藏 进程


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////hdpw组件//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//打开窗口保护
//可以多次指定 内部会把指定的保护窗口句柄以及所属子窗口一起保护
//hwnd:目标窗口句柄 一般为父窗口句柄
HEARTDLL_API_HD __int64  __stdcall HCHDPW_OnProtect(__int64 hwnd);

//取消所有窗口保护
HEARTDLL_API_HD __int64  __stdcall HCHDPW_OffProtect();

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////hdvtpp组件//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//打开窗口保护
//可以多次指定 内部会把指定的保护窗口句柄以及所属子窗口一起保护
//hwnd:目标窗口句柄 一般为父窗口句柄
//进程容量支持100个
//父窗口句柄容量支持100个
//子窗口总共容量支持512个
//驱动组件9+8
HEARTDLL_API_HD __int64  __stdcall HCHDVTPP_OnProtect(__int64 hwnd);


//取消所有窗口保护和进程PID
HEARTDLL_API_HD __int64  __stdcall HCHDVTPP_OffProtect();


//反截图
//hWnd:窗口句柄
//type 0关闭 1开启反截图模式1 2开启反截图模式2
HEARTDLL_API_HD __int64  __stdcall HCHDVTPP_OnCapture(__int64 hwnd, int type);

//pid::窗口PID
//targetAddr:目标地址
//readSize:读大小
//buffer:存读数据的缓冲区 注意:缓冲区大小一定要大于等于 读大小 最好相等
//type: 1 普通读写1 2加强模式2 3物理读写3
//注意:最好用2或者3 经过测试:3的速度相对比2一倍
HEARTDLL_API_HD __int64  __stdcall HCHDVTPP_ReadBytes(__int64 pid, __int64 targetAddr, __int32 readSize, __int64 buffer, int type);//读字节集

//pid::窗口PID
//targetAddr:目标地址
//readSize:写大小
//buffer:存写数据的缓冲区
//type: 1 普通读写1 2加强模式2 3物理读写3
//注意:普通读写可能写不成功  最好用2或者3 经过测试:3的速度相对比2一倍
HEARTDLL_API_HD __int64  __stdcall HCHDVTPP_WriteBytes(__int64 pid, __int64 targetAddr, __int32 writeSize, __int64 buffer, int type);//读字节集


//主线程调用CALL
//pid::窗口PID
//shellCodeBuffer:执行代码shellcode机器码缓冲区
//bufferSize:执行代码shellcode字节数
HEARTDLL_API_HD __int64  __stdcall HCHDVTPP_Call(__int64 pid, __int64 shellCodeBuffer, __int32 bufferSize);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////预留组件//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


