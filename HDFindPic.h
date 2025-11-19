#pragma once
#include <winsock2.h>
#include <windows.h>
#include "winDNS.h"
#define HEARTDLL_EXPORT_HDFP
#ifdef HEARTDLL_EXPORT_HDFP
#define HEARTDLL_API_HDFP  extern "C" __declspec(dllexport) //导出
#else
#define HEARTDLL_API_HDFP  extern "C" __declspec(dllimport) //导入
#endif

HEARTDLL_API_HDFP __int64  __stdcall  HCFP_Capture(__int32 窗口序号, __int32 x, __int32 y, __int32 w, __int32 h, char* fileNamePath, BOOL 是否打开查看器 = FALSE);

//找色
HEARTDLL_API_HDFP __int64  __stdcall  HCFP_FindColor(__int32 窗口序号, __int32 x, __int32 y, __int32 w, __int32 h, char* deltaColor, double sim, __int32 dirType = 0);

//在范围内 返回匹配的颜色数量和json是坐标
HEARTDLL_API_HDFP __int64  __stdcall  HCFP_FindColors(__int32 窗口序号, __int32 x, __int32 y, __int32 w, __int32 h, char* deltaColor, double sim, __int32 dirType = 0);


HEARTDLL_API_HDFP __int64  __stdcall  HCFP_FindColorsOffset(__int32 窗口序号, __int32 x, __int32 y, __int32 w, __int32 h, char* firstDeltaColor, char* deltaColor, double sim, __int32 bALL = 0, __int32 dirType = 0);

HEARTDLL_API_HDFP __int64  __stdcall  HCFP_CmpColors(__int32 窗口序号, __int32 x, __int32 y,char* deltaColor);

//多点找色确定某个图像块
//deltaXYColor:x1|y1|e3e6eb-101010|e3e6eb-101010|e3e6eb-101010|...,x2|y2|e3e6eb-101010|e3e6eb-101010|e3e6eb-101010|...
//找到返回8字节长整数包含第一个坐标点x1,y1
//低4字节x1 高4字节y1
HEARTDLL_API_HDFP __int64  __stdcall  HCFP_CmpColorExs(__int32 窗口序号, char* deltaXYColor);


HEARTDLL_API_HDFP __int64  __stdcall  HCFP_GetColor(__int32 窗口序号, __int32 x, __int32 y);


//从绑定的后台缓冲区找图
HEARTDLL_API_HDFP __int64  __stdcall  HCFP_FindPic(__int32 窗口序号,__int32 x, __int32 y, __int32 w, __int32 h, char*图片名字, char* deltaColor, double sim, __int32 dirType = 0);//FindPic__EX 用

HEARTDLL_API_HDFP __int64  __stdcall  HCFP_FindPic__(__int32 窗口序号, __int32 x, __int32 y, __int32 w, __int32 h, char*图片名字, char* deltaColor, double sim, __int32 dirType = 0);//FindPic__ 丢弃

HEARTDLL_API_HDFP __int64  __stdcall  HCFP_FindPic__EX(__int32 窗口序号, __int32 x, __int32 y, __int32 w, __int32 h, char*图片名字, char* deltaColor, double sim, __int32 dirType = 0);//FindPic__EX 丢弃

HEARTDLL_API_HDFP __int64  __stdcall  HCFP_FindPicEx(__int32 窗口序号,__int32 x, __int32 y, __int32 w, __int32 h, char*图片名字集合, char* deltaColor, double sim, __int32 dirType = 0);//FindPicEx__EX 用

HEARTDLL_API_HDFP __int64  __stdcall  HCFP_FindPicExx(__int32 窗口序号, __int32 x, __int32 y, __int32 w, __int32 h, char*图片名字集合, char* deltaColor, double sim, BOOL bAll = TRUE, __int32 dirType = 0);//FindPicEx__EX 用 返回找到所有图片的索引 

HEARTDLL_API_HDFP __int64  __stdcall  HCFP_FindPicEx__EX(__int32 窗口序号, __int32 x, __int32 y, __int32 w, __int32 h, char*图片名字集合, char* deltaColor, double sim, __int32 dirType = 0);//FindPicEx__EX 丢弃
//

HEARTDLL_API_HDFP __int64  __stdcall  HCFP_IsDisplayDead(__int32 窗口序号,__int32 x, __int32 y, __int32 w, __int32 h,__int32 mstime);

HEARTDLL_API_HDFP __int64  __stdcall  HCFP_GetRangeCRC(__int32 窗口序号, __int32 x, __int32 y, __int32 w, __int32 h);


//传入图片文件

HEARTDLL_API_HDFP __int64  __stdcall  HCFP_CmpColorsByFile(__int32 窗口序号, char*orgImageName, __int32 x, __int32 y, char* deltaColor);

HEARTDLL_API_HDFP __int64  __stdcall  HCFP_CmpColorExsByFile(__int32 窗口序号, char*orgImageName, char* deltaXYColor);

HEARTDLL_API_HDFP __int64  __stdcall  HCFP_GetColorByFile(__int32 窗口序号, char*orgImageName, __int32 x, __int32 y);
//

HEARTDLL_API_HDFP __int64  __stdcall  HCFP_FindColorByFile(__int32 窗口序号, char*orgImageName, __int32 x, __int32 y, __int32 w, __int32 h, char* deltaColor, double sim, __int32 dirType = 0);

HEARTDLL_API_HDFP __int64  __stdcall  HCFP_FindColorsByFile(__int32 窗口序号, char*orgImageName, __int32 x, __int32 y, __int32 w, __int32 h, char* deltaColor, double sim, __int32 dirType = 0);

HEARTDLL_API_HDFP __int64  __stdcall  HCFP_FindColorsOffsetByFile(__int32 窗口序号, char*orgImageName, __int32 x, __int32 y, __int32 w, __int32 h, char* firstDeltaColor, char* deltaColor, double sim, __int32 bALL = 0, __int32 dirType = 0);

HEARTDLL_API_HDFP __int64  __stdcall  HCFP_FindPicByFile(__int32 窗口序号, char*orgImageName, __int32 x, __int32 y, __int32 w, __int32 h, char*图片名字, char* deltaColor, double sim, __int32 dirType = 0);

HEARTDLL_API_HDFP __int64  __stdcall  HCFP_FindPicExByFile(__int32 窗口序号, char*orgImageName, __int32 x, __int32 y, __int32 w, __int32 h, char*图片名字集合, char* deltaColor, double sim, __int32 dirType = 0);

HEARTDLL_API_HDFP __int64  __stdcall  HCFP_FindPicExxByFile(__int32 窗口序号, char*orgImageName, __int32 x, __int32 y, __int32 w, __int32 h, char*图片名字集合, char* deltaColor, double sim, BOOL bAll = TRUE, __int32 dirType = 0);//FindPicEx__EX 用 返回找到所有图片的索引 


//传入的图片内存数据 自行维护
HEARTDLL_API_HDFP __int64  __stdcall  HCFP_CmpColorsByMem(__int32 窗口序号, BYTE* data, __int32 dataSize, __int32 x, __int32 y, char* deltaColor);

HEARTDLL_API_HDFP __int64  __stdcall  HCFP_CmpColorExsByMem(__int32 窗口序号, BYTE* data, __int32 dataSize, char* deltaXYColor);

HEARTDLL_API_HDFP __int64  __stdcall  HCFP_GetColorByMem(__int32 窗口序号, BYTE* data, __int32 dataSize, __int32 x, __int32 y);
//

HEARTDLL_API_HDFP __int64  __stdcall  HCFP_FindColorByMem(__int32 窗口序号, BYTE* data, __int32 dataSize, __int32 x, __int32 y, __int32 w, __int32 h, char* deltaColor, double sim, __int32 dirType = 0);

HEARTDLL_API_HDFP __int64  __stdcall  HCFP_FindColorsByMem(__int32 窗口序号, BYTE* data, __int32 dataSize, __int32 x, __int32 y, __int32 w, __int32 h, char* deltaColor, double sim, __int32 dirType = 0);

HEARTDLL_API_HDFP __int64  __stdcall  HCFP_FindColorsOffsetByMem(__int32 窗口序号, BYTE* data, __int32 dataSize, __int32 x, __int32 y, __int32 w, __int32 h, char* firstDeltaColor, char* deltaColor, double sim, __int32 bALL = 0, __int32 dirType = 0);

HEARTDLL_API_HDFP __int64  __stdcall  HCFP_FindPicByMem(__int32 窗口序号, BYTE* data, __int32 dataSize, __int32 x, __int32 y, __int32 w, __int32 h, char*图片名字, char* deltaColor, double sim, __int32 dirType = 0);

HEARTDLL_API_HDFP __int64  __stdcall  HCFP_FindPicExByMem(__int32 窗口序号, BYTE* data, __int32 dataSize, __int32 x, __int32 y, __int32 w, __int32 h, char*图片名字集合, char* deltaColor, double sim, __int32 dirType = 0);

HEARTDLL_API_HDFP __int64  __stdcall  HCFP_FindPicExxByMem(__int32 窗口序号, BYTE* data, __int32 dataSize, __int32 x, __int32 y, __int32 w, __int32 h, char*图片名字集合, char* deltaColor, double sim, BOOL bAll = TRUE, __int32 dirType = 0);

//子图传入内存数据集合
//地址1,长度1|地址2,长度2|地址3,长度3  数值用十进制表示
HEARTDLL_API_HDFP __int64  __stdcall  HCFP_FindPicExFromMem(__int32 窗口序号, __int32 x, __int32 y, __int32 w, __int32 h, char*子图内存地址集合字符串, char* deltaColor, double sim, __int32 dirType = 0);

HEARTDLL_API_HDFP __int64  __stdcall  HCFP_FindPicExxFromMem(__int32 窗口序号, __int32 x, __int32 y, __int32 w, __int32 h, char*子图内存地址集合字符串, char* deltaColor, double sim, BOOL bAll = TRUE, __int32 dirType = 0);