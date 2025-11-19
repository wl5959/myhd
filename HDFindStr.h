#pragma once
#include <winsock2.h>
#include <windows.h>
#include "winDNS.h"
#define HEARTDLL_EXPORT_HDFS
#ifdef HEARTDLL_EXPORT_HDFS
#define HEARTDLL_API_HDFS  extern "C" __declspec(dllexport) //导出
#else
#define HEARTDLL_API_HDFS  extern "C" __declspec(dllimport) //导入
#endif

//像素识字模块
//设置字库文件 初始化要全部设置好  运行起来了就不能设置  否则冲突
HEARTDLL_API_HDFS __int64  __stdcall HCFS_SetDictFile(__int32 窗口序号, __int32 字库序号 ,char* file);

//可以用密码
HEARTDLL_API_HDFS __int64  __stdcall HCFS_SetDictFileExx(__int32 窗口序号, __int32 字库序号, char* file, char* password = NULL);

//像素识字模块扩展版本
//一次型给每个序号都设置好
//省去了自己遍历
HEARTDLL_API_HDFS __int64  __stdcall HCFS_SetDictFileEx(__int32 字库序号, char* file);

//切换当前字库文件
HEARTDLL_API_HDFS __int64  __stdcall HCFS_SwitchCurDictFile(__int32 窗口序号, __int32 字库序号);

//获取加载后的字库文件信息 json返回信息  返回值真假
//json:窗口索引,当前字库索引,加载了字库,(加载的字库序号,对应的字条数目)|... 如: info:0,1,3,(1,55)|(2,55)|(3,55)|
HEARTDLL_API_HDFS __int64  __stdcall HCFS_GetCurDictInfo(__int32 窗口序号);

//获取当前字库索引
HEARTDLL_API_HDFS __int64  __stdcall HCFS_GetCurDictIndex(__int32 窗口序号);

//单字符串找 字库是单字 OK 优化 优化字条
HEARTDLL_API_HDFS __int64  __stdcall HCFS_FindStr(__int32 窗口序号, long findX, long findY, long findW, long findH, LPCSTR str, LPCSTR color_format, double sim, __int32 bfx, __int32 dirType = 0, int spaceH = 11, int spaceV = 11, double groundRate = 0.1, BOOL bOne11 = TRUE);

//单字符串找 字库是字符串 例如:洛阳  优化 优化字条
HEARTDLL_API_HDFS __int64  __stdcall HCFS_FindStrMutil(__int32 窗口序号, long findX, long findY, long findW, long findH, LPCSTR str, LPCSTR color_format, double sim, __int32 bfx, __int32 dirType = 0, int spaceH = 11, int spaceV = 11, double groundRate = 0.1, BOOL bOne11 = TRUE);

//单字符串找 字库是字符串 例如:洛阳  多行 返回多个坐标 一行只找一列(一次) 优化 优化字条
HEARTDLL_API_HDFS __int64  __stdcall HCFS_FindStrMutilVPoints(__int32 窗口序号, long findX, long findY, long findW, long findH, LPCSTR str, LPCSTR color_format, double sim, __int32 bfx, __int32 dirType = 0, int spaceH = 11, int spaceV = 11, double groundRate = 0.1, BOOL bOne11 = TRUE);

//优化 优化字条
HEARTDLL_API_HDFS __int64  __stdcall HCFS_FindStrMutilVPointsByFile(__int32 窗口序号, long findX, long findY, long findW, long findH, LPCSTR str, LPCSTR color_format, double sim, LPCSTR iamgeName, __int32 bfx, __int32 dirType = 0, int spaceH = 11, int spaceV = 11, double groundRate = 0.1, BOOL bOne11 = TRUE);
 
//优化 优化字条
HEARTDLL_API_HDFS __int64  __stdcall HCFS_FindStrMutilVPointsByMem(__int32 窗口序号, long findX, long findY, long findW, long findH, LPCSTR str, LPCSTR color_format, double sim, BYTE* data, __int32 dataSize, __int32 bfx, __int32 dirType = 0, int spaceH = 11, int spaceV = 11, double groundRate = 0.1, BOOL bOne11 = TRUE);

//单字符串找 字库是字符串 例如:洛阳  多行多列 返回多个坐标  一行找多列(多次)  找多行
//优化 优化字条
HEARTDLL_API_HDFS __int64  __stdcall HCFS_FindStrMutilHVPoints(__int32 窗口序号, long findX, long findY, long findW, long findH, LPCSTR str, LPCSTR color_format, double sim, __int32 bfx, __int32 dirType = 0, int spaceH = 11, int spaceV = 11, double groundRate = 0.1, BOOL bOne11 = TRUE);

//优化 优化字条
HEARTDLL_API_HDFS __int64  __stdcall HCFS_FindStrMutilHVPointsByFile(__int32 窗口序号, long findX, long findY, long findW, long findH, LPCSTR str, LPCSTR color_format, double sim, LPCSTR iamgeName, __int32 bfx, __int32 dirType = 0, int spaceH = 11, int spaceV = 11, double groundRate = 0.1, BOOL bOne11 = TRUE);

//优化 优化字条
HEARTDLL_API_HDFS __int64  __stdcall HCFS_FindStrMutilHVPointsByMem(__int32 窗口序号, long findX, long findY, long findW, long findH, LPCSTR str, LPCSTR color_format, double sim, BYTE* data, __int32 dataSize, __int32 bfx, __int32 dirType = 0, int spaceH = 11, int spaceV = 11, double groundRate = 0.1, BOOL bOne11 = TRUE);

//多字符串找 字库是单字 全部找 OK 优化 优化字条
HEARTDLL_API_HDFS __int64  __stdcall HCFS_FindStrEx(__int32 窗口序号, long findX, long findY, long findW, long findH, LPCSTR str, LPCSTR color_format, double sim, __int32 bfx, __int32 dirType = 0, int spaceH = 11, int spaceV = 11, double groundRate = 0.1, BOOL bOne11 = TRUE);

//多字符串找 字库是单字 找到一个就返回 OK 优化 优化字条
HEARTDLL_API_HDFS __int64  __stdcall HCFS_FindStrExx(__int32 窗口序号, long findX, long findY, long findW, long findH, LPCSTR str, LPCSTR color_format, double sim, __int32 bfx, __int32 dirType = 0, int spaceH = 11, int spaceV = 11, double groundRate = 0.1, BOOL bOne11 = TRUE);

//单字符串找 字库是字符串  查找多个字符串  例如:洛阳|背景|耳机| 全部找 优化字条
HEARTDLL_API_HDFS __int64  __stdcall HCFS_FindStrMutilsEx(__int32 窗口序号, long findX, long findY, long findW, long findH, LPCSTR strs, LPCSTR color_format, double sim, __int32 bfx, __int32 dirType = 0, int spaceH = 11, int spaceV = 11, double groundRate = 0.1, BOOL bOne11 = TRUE);

//多字符串找 字库是字符串 查找多个字符串  例如:洛阳|背景|耳机|  找到一个就返回 优化字条
HEARTDLL_API_HDFS __int64  __stdcall HCFS_FindStrMutilsExx(__int32 窗口序号, long findX, long findY, long findW, long findH, LPCSTR strs, LPCSTR color_format, double sim, __int32 bfx, __int32 dirType = 0, int spaceH = 11, int spaceV = 11, double groundRate = 0.1, BOOL bOne11 = TRUE);
//
//单 多字符串找 都兼容 |分割 找到一个就返回 字库是字符串或单字 OK 优化字条
//判断规则:  拼接+完整 1.有完整先识别完整 2.无完整按拼接处理 3.有分隔符|,统一按完整字符串处理
HEARTDLL_API_HDFS __int64  __stdcall HCFS_FindStrMutilsAuto(__int32 窗口序号, long findX, long findY, long findW, long findH, LPCSTR strs, LPCSTR color_format, double sim, __int32 bfx, __int32 dirType = 0, int spaceH = 11, int spaceV = 11, double groundRate = 0.1, BOOL bOne11 = TRUE);

//OK 
//全部查或单个找并返回 优化字条 
HEARTDLL_API_HDFS __int64  __stdcall HCFS_FindStrMutilsAutoEx(__int32 窗口序号, long findX, long findY, long findW, long findH, LPCSTR strs, LPCSTR color_format, double sim, __int32 bfx, __int32 dirType = 0, __int32 bFindOne = 0, int spaceH = 11, int spaceV = 11, double groundRate = 0.1, BOOL bOne11 = TRUE);
//
//可以通过指定图片来获取截图数据 其他功能和HCFS_FindStrMutilsAuto一致 优化字条 
HEARTDLL_API_HDFS __int64  __stdcall HCFS_FindStrMutilsAutoByFile(__int32 窗口序号, long findX, long findY, long findW, long findH, LPCSTR strs, LPCSTR color_format, double sim, LPCSTR iamgeName,__int32 bfx, __int32 dirType = 0, int spaceH = 11, int spaceV = 11, double groundRate = 0.1, BOOL bOne11 = TRUE);

//全部或单个查找并返回  优化字条 
HEARTDLL_API_HDFS __int64  __stdcall HCFS_FindStrMutilsAutoByFileEx(__int32 窗口序号, long findX, long findY, long findW, long findH, LPCSTR strs, LPCSTR color_format, double sim, LPCSTR iamgeName, __int32 bfx, __int32 dirType = 0, __int32 bFindOne = 0, int spaceH = 11, int spaceV = 11, double groundRate = 0.1, BOOL bOne11 = TRUE);

//可以通过指定图片数据获取截图数据 其他功能和HCFS_FindStrMutilsAuto一致 优化字条 
HEARTDLL_API_HDFS __int64  __stdcall HCFS_FindStrMutilsAutoByMem(__int32 窗口序号, long findX, long findY, long findW, long findH, LPCSTR strs, LPCSTR color_format, double sim, BYTE* data, __int32 dataSize, __int32 bfx, __int32 dirType = 0, int spaceH = 11, int spaceV = 11, double groundRate = 0.1, BOOL bOne11 = TRUE);

//可以通过指定图片数据获取截图数据 其他功能和HCFS_FindStrMutilsAuto一致
//全部或单个查找并返回
HEARTDLL_API_HDFS __int64  __stdcall HCFS_FindStrMutilsAutoByMemEx(__int32 窗口序号, long findX, long findY, long findW, long findH, LPCSTR strs, LPCSTR color_format, double sim, BYTE* data, __int32 dataSize, __int32 bfx, __int32 dirType = 0, __int32 bFindOne = 0, int spaceH = 11, int spaceV = 11, double groundRate = 0.1, BOOL bOne11 = TRUE);

//识别字符串 多行 字库是字符串或单字 优化 优化字条
HEARTDLL_API_HDFS __int64  __stdcall HCFS_Ocr(__int32 窗口序号, long findX, long findY, long findW, long findH, LPCSTR color_format, double sim, __int32 bfx, __int32 dirType = 0, int spaceH = 11, int spaceV = 11, double groundRate = 0.1, BOOL bOne11 = TRUE);

//可以通过指定图片数据获取截图数据 识别字符串 多行 字库是字符串或单字 优化 优化字条 
HEARTDLL_API_HDFS __int64  __stdcall HCFS_OcrByFile(__int32 窗口序号, long findX, long findY, long findW, long findH, LPCSTR color_format, double sim, LPCSTR iamgeName, __int32 bfx, __int32 dirType = 0, int spaceH = 11, int spaceV = 11, double groundRate = 0.1, BOOL bOne11 = TRUE);

//可以通过指定图片数据获取截图数据 识别字符串 多行 字库是字符串或单字 优化 优化字条 
HEARTDLL_API_HDFS __int64  __stdcall HCFS_OcrByMem(__int32 窗口序号, long findX, long findY, long findW, long findH, LPCSTR color_format, double sim, BYTE* data, __int32 dataSize, __int32 bfx, __int32 dirType = 0, int spaceH = 11, int spaceV = 11, double groundRate = 0.1, BOOL bOne11 = TRUE);


//调试
//单 多字符串找 都兼容 |分割 找到一个就返回 字库是字符串或单字 OK 优化字条
//判断规则:  拼接+完整 1.有完整先识别完整 2.无完整按拼接处理 3.有分隔符|,统一按完整字符串处理
//0序号
//优化
//
HEARTDLL_API_HDFS __int64  __stdcall HCFS_FindStrMutilsAuto_Debug(long findX, long findY, long findW, long findH, LPCSTR strs, LPCSTR color_format, double sim, __int32 scaleSzie, LPCSTR iamgeName, __int32 bfx,__int32 bAll, int spaceH = 11, int spaceV = 11, double groundRate = 0.1, BOOL bOne11 = TRUE);

//关闭所有调试窗口
HEARTDLL_API_HDFS __int64  __stdcall HCFS_CloseALLWindow_Debug();


//设置拼接字或者OCR 每个字/数字/字母/符号 之间的横向X或者纵向Y的间距
//在这个间距范围内 视为一个整体字符串
HEARTDLL_API_HDFS __int64  __stdcall HCFS_SetCharSpaceHV(int lenH = 11, int lenV = 11);

//设置11行中 是否只有一个字
//如果多个字存在 识别速度会慢些
//返回当前开关状态
HEARTDLL_API_HDFS __int64  __stdcall HCFS_IsOne11(BOOL b = TRUE);

//设置字周围一个像素 上下左右的像素占比
//越高 可能识别的不准确
//这个相当于一个容错率占比
//返回当前设置后的占比
//默认0.1
HEARTDLL_API_HDFS double  __stdcall HCFS_GroundRate(double rate = 0.1);