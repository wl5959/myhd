#pragma once
#include <winsock2.h>
#include <windows.h>
#include "winDNS.h"
#define HEARTDLL_EXPORT
#ifdef HEARTDLL_EXPORT
#define HEARTDLL_API extern "C" __declspec(dllexport) //导出
#else
#define HEARTDLL_API extern "C" __declspec(dllimport) //导入
#endif

//【======================================================================通用-CALL========================================================】

//【初始化环境后才能调用】
//说明:调用通用CALL
//1.参数默认为0
//2.传递的地址 一定是目标进程的地址 不是调用进程的地址 切记！
HEARTDLL_API __int64  __stdcall  HC_CALL(__int32 窗口序号, __int64 CALL地址, __int64 rcx = 0, __int64 rdx = 0, __int64 r8 = 0, __int64 r9 = 0, __int64 lparam5 = 0, __int64 lparam6 = 0, __int64 lparam7 = 0, __int64 lparam8 = 0, BOOL 是否主线程调用 = FALSE);


HEARTDLL_API __int64  __stdcall  HC_CALLX86(__int32 窗口序号, __int32 CALL地址, __int32 ecx = 0,__int32 lparam1 = 0, __int32 lparam2 = 0, __int32 lparam3 = 0, __int32 lparam4 = 0, __int32 lparam5 = 0, __int32 lparam6 = 0, __int32 lparam7 = 0, __int32 lparam8 = 0, __int32 lparamNum = 0, __int32 addEsp = -1, BOOL 是否主线程调用 = FALSE);


//【初始化环境之前调用】
//说明:挂接主线程 句柄用HCInject_GetHwnd()获取,是否有效句柄,自己检查窗口类名
//注意:所有需要主线程调用的CALL 都需要先挂接主线程
HEARTDLL_API __int64  __stdcall  HC_HookMainThread(__int32 窗口序号, __int64 窗口句柄);


//【《hit2Inject86.dll》======================================================================YM悠米加速器定制《32位》========================================================】

//【初始化环境后才能调用】
//说明:调用悠米加速器打开批量添加对话框
//特别注意:这个CALL是32位 DLL《hit2Inject86.dll》用的,其他使用方法不变
HEARTDLL_API __int64  __stdcall  HC_OpenIPDialog_YM(__int32 窗口序号, BOOL 是否主线程调用 = FALSE);

//【初始化环境后才能调用】
//说明:调用悠米加速器打开IP管理窗口
//特别注意:这个CALL是32位 DLL《hit2Inject86.dll》用的,其他使用方法不变
HEARTDLL_API __int64  __stdcall  HC_OpenIPManager_YM(__int32 窗口序号, BOOL 是否主线程调用 = FALSE);

//【======================================================================HIT2台服定制-截止20230817失效========================================================】

//【初始化环境后才能调用】
//说明:调用丢弃物品CALL
HEARTDLL_API __int64  __stdcall  HHIT2_DisCardGoods(__int32 窗口序号, __int64 发包组件, __int64 物品CID , __int32 数量,BOOL 是否主线程调用 = FALSE);

//【======================================================================B2韩服定制======================================================================】

//【初始化环境后才能调用】
//说明:调用获取人物信息CALL
//json:{"error":0,"ret":[{ "name": "Jack","level":26, "curHp": 588, "maxHp": 999, "curMp": 255, "maxMp": 666,"gold": 99999, "diamond": 999999}]}
HEARTDLL_API __int64  __stdcall  HB2_GetPlayerInfo(__int32 窗口序号, BOOL 是否主线程调用 = FALSE);

//【初始化环境后才能调用】
//说明:调用获取背包信息CALL
//json:{"error":0,"flag":99,"ret":[{ "id": 1111,"tId":22222,"dId":33333 ,"num": 588},{ "id": 1111,"tId":22222,"dId":33333 , "num": 588},{ "id": 1111,"tId":22222, "dId":33333 ,"num": 588}]}
//id:物品ID  tId:物品临时ID  dId:物品描述ID  num:物品数量  flag这里表示背包总格子
HEARTDLL_API __int64  __stdcall  HB2_GetBagInfo(__int32 窗口序号, BOOL 是否主线程调用 = FALSE);

//【初始化环境后才能调用】
//说明:调用获取快捷栏遍历信息CALL
//有2个CALL 1为前10个 2为后10个
//json:{"error":0,"ret":[{ "index": 0,"id": 1111,"bAct":0},{ "index": 1,"id": 2222,"bAct":1}]}
//index索引从0开始 id是物品或者技能ID(固定的那个ID) bAct是否激活
HEARTDLL_API __int64  __stdcall  HB2_GetShortCutInfo1(__int32 窗口序号, BOOL 是否主线程调用 = FALSE);
HEARTDLL_API __int64  __stdcall  HB2_GetShortCutInfo2(__int32 窗口序号, BOOL 是否主线程调用 = FALSE);

//【初始化环境后才能调用】
//说明:调用获取人物坐标CALL
//json:{"error":0,"ret":[{"x":125,"y":125,"z":125}]}
HEARTDLL_API __int64  __stdcall  HB2_GetPlayerXYZ(__int32 窗口序号, BOOL 是否主线程调用 = FALSE);

//【初始化环境后才能调用】
//说明:调用获取人物当前地图ID CALL 
//json:{"error":0,"ret":[{"mapId":1993}]}
HEARTDLL_API __int64  __stdcall  HB2_GetPlayerCurMapId(__int32 窗口序号, BOOL 是否主线程调用 = FALSE);


//【初始化环境后才能调用】
//说明:调用获取当前任务章节ID
//json:{"error":0,"ret":[{"CTaskId":1993,"index":1}]}
//CTaskId:章节ID大于0的值 index:小任务序号从1开始递增,0为失败
HEARTDLL_API __int64  __stdcall  HB2_GetCurChapterTaskId(__int32 窗口序号, BOOL 是否主线程调用 = FALSE);


//【初始化环境后才能调用】
//说明:调用遍历已结任务章节ID信息(主线+支线)
//json:{"error":0,"ret":[{"CTaskId":1993,"index":1,"curNum":2},{"CTaskId":1998,"index":2,"curNum":2}]}
//CTaskId:章节ID大于0的值 index:小任务序号从1开始递增,0为失败 num:任务当前进度(数量)
HEARTDLL_API __int64  __stdcall  HB2_GetAChapterTask(__int32 窗口序号, BOOL 是否主线程调用 = FALSE);


//【初始化环境后才能调用】
//说明:调用人物是否移动CALL
HEARTDLL_API __int64  __stdcall  HB2_PlayerIsMove(__int32 窗口序号, BOOL 是否主线程调用 = FALSE);


//【初始化环境后才能调用】
//说明:调用人物是否自动使用药品状态
HEARTDLL_API __int64  __stdcall  HB2_IsAutoUseMed(__int32 窗口序号, BOOL 是否主线程调用 = FALSE);

//【初始化环境后才能调用】
//说明:调用移动CALL
//成功返回:
//{"error":0,"ret":XXXX} XXXX是寻路CALL的返回值 ret:-1表示CALL偏移为NULL,联系管理员 -2表示参数有误
HEARTDLL_API __int64  __stdcall  HB2_Move(__int32 窗口序号, __int32 地图ID, __int32 x, __int32 y, __int32 z, BOOL 是否主线程调用 = FALSE);

//【初始化环境后才能调用】
//说明:调用传送点CALL
//传送点ID:是固定的 通过特征码自行获取-><488B742468488BC8  0x35 1 CALL的rdx就是传送点ID> 日期:20230824
HEARTDLL_API __int64  __stdcall  HB2_PassPoint(__int32 窗口序号, __int32 传送点ID,BOOL 是否主线程调用 = FALSE);

//【初始化环境后才能调用】
//说明:调用使用物品CALL
HEARTDLL_API __int64  __stdcall  HB2_UseGoods(__int32 窗口序号, __int64 物品ID, __int64  物品数量, __int64 物品临时ID, __int64 物品描述ID, BOOL 是否主线程调用 = FALSE);

//【初始化环境后才能调用】
//说明:调用化身遍历CALL
//json:{"error":0,"ret":[{ "id": 0,"xLevel": 1111,"type":0},{ "id": 0,"xLevel": 1111,"type":0}]}
//id:化身ID xLevel:化身星级 type:化身品质 0 1 2 3 依次递增+1 白 绿 蓝...
HEARTDLL_API __int64  __stdcall  HB2_GetHuaShen(__int32 窗口序号, BOOL 是否主线程调用 = FALSE);

//【初始化环境后才能调用】
//说明:调用化身遍历CALL
//json:{"error":0,"ret":[{ "id": 0,"level":1,"xLevel": 2,"type":0},{ "id": 0,"level":1,"xLevel": 2,"type":0}]}
//id:化身ID level:等级 xLevel:星级 type:化身品质 0 1 2 3 依次递增+1 白 绿 蓝...
HEARTDLL_API __int64  __stdcall  HB2_GetChongWu(__int32 窗口序号, BOOL 是否主线程调用 = FALSE);


//【======================================================================扩展DLL========================================================】
//【暂时不用】
HEARTDLL_API __int64  __stdcall  HCEX_CallInterface(__int32 窗口序号, char*函数名, __int64 rcx = 0, __int64 rdx = 0, __int64 r8 = 0, __int64 r9 = 0, __int64 lparam5 = 0, __int64 lparam6 = 0, BOOL 是否主线程调用 = FALSE);



//【======================================================================调试========================================================】
//【初始化环境后才能调用】
//调试信息打印
//说明:调用HHIT2_Debug
HEARTDLL_API __int64  __stdcall  HC_Debug(__int32 窗口序号, __int32 bOpen = 1);


//【========================================================================COC韩服===================================================】
//【初始化环境才有效】
//说明:调用HCCOC_InvitePlayer 邀请玩家入队
HEARTDLL_API __int64  __stdcall  HCCOC_InvitePlayer(__int32 窗口序号, char* 玩家名字, __int32 名字长度, BOOL 是否主线程调用 = FALSE);


//【初始化环境才有效】
//说明:调用HCCOC_CreateTeam 创建队伍
HEARTDLL_API __int64  __stdcall  HCCOC_CreateTeam(__int32 窗口序号, __int32 最低等级, __int32 最高等级, BOOL 是否自动邀请, BOOL 是否主线程调用 = FALSE);


//【初始化环境才有效】
//说明:调用HCCOC_DeleteTeamPlayer 踢队员
HEARTDLL_API __int64  __stdcall  HCCOC_DeleteTeamPlayer(__int32 窗口序号, __int64 队伍ID, BOOL 是否主线程调用 = FALSE);


//【初始化环境才有效】
//说明:调用HCCOC_RemoveTeam 解散队伍
HEARTDLL_API __int64  __stdcall  HCCOC_RemoveTeam(__int32 窗口序号,BOOL 是否主线程调用 = FALSE);

//【初始化环境才有效】
//说明:调用HCCOC_BuyGoods 购买商品
HEARTDLL_API __int64  __stdcall  HCCOC_BuyGoods(__int32 窗口序号, __int64 商品ID, __int64 商品数量, BOOL 是否主线程调用 = FALSE);

//【=================================================================================================================================】