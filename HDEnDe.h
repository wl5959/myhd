#pragma once
#include <winsock2.h>
#include <windows.h>
#include "winDNS.h"
#define HEARTDLL_EXPORT_HDENDE
#ifdef HEARTDLL_EXPORT_HDENDE
#define HEARTDLL_API_HDENDE  extern "C" __declspec(dllexport) //导出
#else
#define HEARTDLL_API_HDENDE  extern "C" __declspec(dllimport) //导入
#endif
//【======================================================================加密解密模块===========================================================】
//说明:HCENDE_Encryption 加密
//1.加密组件文件,返回密钥同时保持加密后的(.hd)后缀的组件文件
HEARTDLL_API_HDENDE __int64  __stdcall  HCENDE_Encryption(char*pAccount, char*pPassword, char * fileFullPath, BYTE *pOutKeyBuffer, DWORD outKeyBufferSize, DWORD *keySize);


//说明:HCENDE_Decryption 解密
//1.解密组件文件,传递一个(.hd)密文组件文件({keyBuffer})和解密密钥({keyBuffer})
//2.调用后解密出明文组件,同时保存到当前密文的路径下(明文文件名为:{componentName}.dll)
HEARTDLL_API_HDENDE __int64  __stdcall  HCENDE_Decryption(char * fileFullPath, char * componentName, BYTE *keyBuffer, DWORD keySize);


//【======================================================================加密解密模块===========================================================】 文件 字库 图片 等

//加密文件 原文件-加密-输出加密文件
//返回实际加密文件字节大小
HEARTDLL_API_HDENDE __int64  __stdcall  HCENDE_EncrypFile(char*pPassword, char * fileFullPath, char * outFullPath);

//加密文件 原文件-加密-输出加密内存
//返回实际加密内存字节大小
HEARTDLL_API_HDENDE __int64  __stdcall  HCENDE_EncrypMem(char*pPassword, char * fileFullPath, char * outBuffer, __int32 outBufferSize);


//加密文件 加密文件-解密-输出原文件
//返回实际原文件字节大小
HEARTDLL_API_HDENDE __int64  __stdcall  HCENDE_DecrypFile(char*pPassword, char * fileFullPath, char * outFullPath);


//加密文件 加密文件-解密-输出原内存
//返回实际原内存字节大小
HEARTDLL_API_HDENDE __int64  __stdcall  HCENDE_DecrypMem(char*pPassword, char * fileFullPath, char * outBuffer, __int32 outBufferSize);


//加密文件 原加密内存-解密-输出原内存
//返回实际原内存字节大小
HEARTDLL_API_HDENDE __int64  __stdcall  HCENDE_DecrypFromMemMem(char*pPassword, char * inBuffer, __int32 inBufferSize, char * outBuffer, __int32 outBufferSize);
