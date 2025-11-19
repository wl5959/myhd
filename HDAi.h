#pragma once
#include <winsock2.h>
#include <windows.h>
#include "winDNS.h"
#define HEARTDLL_EXPORT_HDAI
#ifdef HEARTDLL_EXPORT_HDAI
#define HEARTDLL_API_HDAI extern "C" __declspec(dllexport) //导出
#else
#define HEARTDLL_API_HDAI extern "C" __declspec(dllimport) //导入
#endif
//【=====================================================================全局设置=====================================================】

//【初始化环境后才能调用】
//设置全局资源CALL
//设置的是资源(文件 图片)等数据的路径
//说明:调用HCRES_SetResPath
//无返回:
HEARTDLL_API_HDAI void __stdcall  HCRES_SetResPathA(char * path);
HEARTDLL_API_HDAI void __stdcall  HCRES_SetResPathW(wchar_t * path);

//设置窗口序号对应的窗口资源路径
//windIndex:窗口序号 -1表示全局资源(同 HCRES_SetResPathA/W 一个效果) 大于等于0表示设置的是窗口全局资源路径
HEARTDLL_API_HDAI void __stdcall  HCRES_SetResPathEx(__int32 windIndex, char * path);

//设置全局语言库资源CALL
//设置的是资源(字体)等数据的路径
//说明:调用HCRES_SetLanguageResPath
//无返回:
HEARTDLL_API_HDAI void __stdcall  HCRES_SetLanguageResPathA(char * path);
HEARTDLL_API_HDAI void __stdcall  HCRES_SetLanguageResPathW(wchar_t * path);
//【======================================================================找图========================================================】
//【开启截图才能调用】
//找图:以当前绑定窗口的截图为目标图片找相关的坐标点
//说明:调用HCFI_FindImage
//{"error":0, "ret" : AAA, "data" : [{"i":index, "x1" : XX, "y1" : YY, "x2" : XX, "y2" : YY "max" : 0.0f}, { "i":index,"x1" : XX,"y1" : YY,"x2" : XX,"y2" : YY "max" : 0.0f }]}
//每张图对应会有图片索引 + 2个坐标点(左上角 + 右下角) + 置信度(max)
//index:图片集合指定的索引(0开始) 如 : "洛阳.bmp|洱海.bmp|" (洛阳.bmp)索引就是0
//XX:X坐标
//YY:Y坐标
//XX YY-> -1图片打不开 -2未找到匹配点 -3匹配点小于0
//time:毫秒耗时
//data:是一个json数组,每一个元素是一个XY坐标分别对应图片路径参数的位置
//图片名字集合:以"|"分割  
//如:heart1.bmp|heart2.bmp|heart3.bmp|heart4.bmp|  
//注意:
//1.最后一个"|"不要忘记加
//2.图片越多耗时多长
//特征匹配
HEARTDLL_API_HDAI __int64  __stdcall  HCFI_FindImageA(__int32 窗口序号, char*图片名字集合, double sim = 0.8, BOOL 是否灰度图 = FALSE, BOOL 是否打开查看器 = FALSE);
HEARTDLL_API_HDAI __int64  __stdcall  HCFI_FindImageW(__int32 窗口序号, wchar_t*图片名字集合, double sim = 0.8, BOOL 是否灰度图 = FALSE, BOOL 是否打开查看器 = FALSE);


//和HCFI_FindImageA(W)一样的用法
//只是这个版本会产生2个坐标点 左上角和右下角
//json:{"error":0,"ret":AAA,"data":[{"x1":XX,"y1":YY,"x2":XX,"y2":YY},{"x1":XX,"y1":YY,"x2":XX,"y2":YY}],"time":ZZZ}
HEARTDLL_API_HDAI __int64  __stdcall  HCFI_FindImageExA(__int32 窗口序号, char*图片名字集合, double sim = 0.8, BOOL 是否灰度图 = FALSE, BOOL 是否打开查看器 = FALSE);
HEARTDLL_API_HDAI __int64  __stdcall  HCFI_FindImageExW(__int32 窗口序号, wchar_t*图片名字集合, double sim = 0.8, BOOL 是否灰度图 = FALSE, BOOL 是否打开查看器 = FALSE);

//和HCFI_FindImageA(W)一样的用法
//提供了区域范围内找图 提高效率
//type:->0:返回一个圆点  1:返回矩形的左上角和右下角
HEARTDLL_API_HDAI __int64  __stdcall  HCFI_FindRangeImageA(__int32 窗口序号, __int32 x, __int32 y, __int32 w, __int32 h, char*图片名字集合, __int32 type = 0, double sim = 0.8, BOOL 是否灰度图 = FALSE, BOOL 是否打开查看器 = FALSE);
HEARTDLL_API_HDAI __int64  __stdcall  HCFI_FindRangeImageW(__int32 窗口序号, __int32 x, __int32 y, __int32 w, __int32 h, wchar_t*图片名字集合, __int32 type = 0, double sim = 0.8, BOOL 是否灰度图 = FALSE, BOOL 是否打开查看器 = FALSE);

//模版匹配和上面的2个算法不同
//sim:相似度0-1 
//type:算法类型 等于3就行 threshold才有效
HEARTDLL_API_HDAI __int64  __stdcall  HCFI_FindImageTemA(__int32 窗口序号, char*图片名字集合, double sim = 0.9, __int32 type = 5, BOOL 是否灰度图 = FALSE, BOOL 是否全部 = FALSE, BOOL 是否打开查看器 = FALSE);//可以全部
HEARTDLL_API_HDAI __int64  __stdcall  HCFI_FindImageTemW(__int32 窗口序号, wchar_t*图片名字集合, double sim = 0.9, __int32 type = 5, BOOL 是否灰度图 = FALSE, BOOL 是否全部 = FALSE, BOOL 是否打开查看器 = FALSE);//可以全部

//模版匹配和上面的2个算法不同
//sim:相似度0-1 
//type:算法类型 等于3就行 threshold才有效
//这2个接口可以指定范围
HEARTDLL_API_HDAI __int64  __stdcall  HCFI_FindRangeImageTemA(__int32 窗口序号, __int32 x, __int32 y, __int32 w, __int32 h, char*图片名字集合, double sim = 0.9, __int32 type = 5, BOOL 是否灰度图 = FALSE, BOOL 是否全部 = FALSE, BOOL 是否打开查看器 = FALSE);//可以全部
HEARTDLL_API_HDAI __int64  __stdcall  HCFI_FindRangeImageTemW(__int32 窗口序号, __int32 x, __int32 y, __int32 w, __int32 h, wchar_t*图片名字集合, double sim = 0.9, __int32 type = 5, BOOL 是否灰度图 = FALSE, BOOL 是否全部 = FALSE, BOOL 是否打开查看器 = FALSE);//可以全部

//通过指定原图中找子图
HEARTDLL_API_HDAI __int64  __stdcall  HCFI_FindImageByFile(__int32 窗口序号, char*原图名字, char*子图片名字集合, double sim = 0.8,BOOL 是否灰度图 = FALSE, BOOL 是否打开查看器 = FALSE);
HEARTDLL_API_HDAI __int64  __stdcall  HCFI_FindImageTemByFile(__int32 窗口序号, char*原图名字, char*子图片名字集合, double sim = 0.9, __int32 type = 5, BOOL 是否灰度图 = FALSE, BOOL 是否全部 = FALSE, BOOL 是否打开查看器 = FALSE);//可以全部
HEARTDLL_API_HDAI __int64  __stdcall  HCFI_FindRangeImageTemByFile(__int32 窗口序号, __int32 x, __int32 y, __int32 w, __int32 h, char*原图名字, char*图片名字集合, double sim = 0.9, __int32 type = 5, BOOL 是否灰度图 = FALSE, BOOL 是否全部 = FALSE, BOOL 是否打开查看器 = FALSE);//可以全部

//通过指定图片内存数据中找子图
HEARTDLL_API_HDAI __int64  __stdcall  HCFI_FindImageByMem(__int32 窗口序号, BYTE*data, __int32 dataSize, char*子图片名字集合, double sim = 0.8, BOOL 是否灰度图 = FALSE, BOOL 是否打开查看器 = FALSE);
HEARTDLL_API_HDAI __int64  __stdcall  HCFI_FindImageTemByMem(__int32 窗口序号, BYTE*data, __int32 dataSize, char*子图片名字集合, double sim = 0.9, __int32 type = 5, BOOL 是否灰度图 = FALSE, BOOL 是否全部 = FALSE, BOOL 是否打开查看器 = FALSE);//可以全部
HEARTDLL_API_HDAI __int64  __stdcall  HCFI_FindRangeImageTemByMem(__int32 窗口序号, __int32 x, __int32 y, __int32 w, __int32 h, BYTE*data, __int32 dataSize, char*图片名字集合, double sim = 0.9, __int32 type = 5, BOOL 是否灰度图 = FALSE, BOOL 是否全部 = FALSE, BOOL 是否打开查看器 = FALSE);//可以全部


//子图来源内存
HEARTDLL_API_HDAI __int64  __stdcall  HCFI_FindImageTemFromMem(__int32 窗口序号,char*子图内存地址集合字符串, double sim = 0.9, __int32 type = 5, BOOL 是否灰度图 = FALSE, BOOL 是否全部 = FALSE, BOOL 是否打开查看器 = FALSE);//可以全部
HEARTDLL_API_HDAI __int64  __stdcall  HCFI_FindRangeImageTemFromMem(__int32 窗口序号, __int32 x, __int32 y, __int32 w, __int32 h,char*子图内存地址集合字符串, double sim = 0.9, __int32 type = 5, BOOL 是否灰度图 = FALSE, BOOL 是否全部 = FALSE, BOOL 是否打开查看器 = FALSE);//可以全部
//【======================================================================识字模块========================================================】
//【初始化环境后才能调用】learn to read  recognition character
//初始化识字服务
//说明:调用HCRC_InitRCServer
HEARTDLL_API_HDAI __int64  __stdcall  HCRC_InitRCServer(__int32 窗口序号, char *语言库名字);

//切换识字服务:主要针对语言字体文件的切换
//内部实现原理:先停止之前的服务(HCRC_StopRCServer)重新初始化(HCRC_InitRCServer)然后重新开启(HCRC_OpenRCServer)
//说明:调用HCRC_SwitchRCServer
HEARTDLL_API_HDAI __int64  __stdcall  HCRC_SwitchRCServer(__int32 窗口序号, char *语言库名字);

//【初始化识字服务后才能调用】
//打开识字服务
//说明:调用HCRC_OpenRCServer
HEARTDLL_API_HDAI __int64  __stdcall  HCRC_OpenRCServer(__int32 窗口序号);

//【打开识字服务后才能调用】
//停止识字服务
//说明:调用HCRC_StopRCServer
HEARTDLL_API_HDAI __int64  __stdcall  HCRC_StopRCServer(__int32 窗口序号);

//【打开识字服务后才能调用】
//图片识字
//说明:调用HCRC_RecognitionCharA HCRC_RecognitionCharW
//成功返回:
//{"error":0,"ret":AAA,"data":[{"image":XXX},{"image":YYY}],"time":ZZZ}
//XXX->图片识别后的结果(字符串) 
//每一个{"image":XXX}是一个识别的字符串,对应<参数:图片名字集合>索引
//二值化阈值:工具的裁剪功能上可以实时编辑查看,确定阈值后填写
//置信度:0到100之间
HEARTDLL_API_HDAI __int64  __stdcall  HCRC_RecognitionCharA(__int32 窗口序号, char*图片名字, int 二值化阈值 = 127, int 置信度 = 80, BOOL 开启灰度图 = TRUE, BOOL 是否打开查看器 = FALSE);
HEARTDLL_API_HDAI __int64  __stdcall  HCRC_RecognitionCharW(__int32 窗口序号, wchar_t*图片名字, int 二值化阈值 = 127, int 置信度 = 80, BOOL 开启灰度图 = TRUE, BOOL 是否打开查看器 = FALSE);

//【打开识字服务后才能调用】
//范围图片识字
//说明:调用HCRC_RecognitionCharExA HCRC_RecognitionCharExW
//类似HCRC_RecognitionCharX 
//多了一个矩形范围内识字的参数(x1,y1)左上角 (x2,y2)右下角
//二值化阈值:工具的裁剪功能上可以实时编辑查看,确定阈值后填写
//置信度:0到100之间
HEARTDLL_API_HDAI __int64  __stdcall  HCRC_RecognitionCharExA(__int32 窗口序号, char*图片名字, __int32 x1 = -1, __int32 y1 = -1, __int32 w = -1, __int32 h = -1, int 二值化阈值 = 127, int 置信度 = 80, BOOL 开启灰度图 = TRUE, BOOL 是否打开查看器 = FALSE);
HEARTDLL_API_HDAI __int64  __stdcall  HCRC_RecognitionCharExW(__int32 窗口序号, wchar_t*图片名字, __int32 x1 = -1, __int32 y1 = -1, __int32 w = -1, __int32 h = -1, int 二值化阈值 = 127, int 置信度 = 80, BOOL 开启灰度图 = TRUE, BOOL 是否打开查看器 = FALSE);

//【打开识字服务后才能调用】
//内存+范围 识字
//二值化阈值:工具的裁剪功能上可以实时编辑查看,确定阈值后填写
//置信度:0到100之间
HEARTDLL_API_HDAI __int64  __stdcall  HCRC_RecognitionCharByMemoryA(__int32 窗口序号, __int64 pData, __int32 宽度, __int32 高度, __int32 x1 = -1, __int32 y1 = -1, __int32 w = -1, __int32 h = -1, int 二值化阈值 = 127, int 置信度 = 80, BOOL 开启灰度图 = TRUE, BOOL 是否打开查看器 = FALSE);
HEARTDLL_API_HDAI __int64  __stdcall  HCRC_RecognitionCharByMemoryW(__int32 窗口序号, __int64 pData, __int32 宽度, __int32 高度, __int32 x1 = -1, __int32 y1 = -1, __int32 w = -1, __int32 h = -1, int 二值化阈值 = 127, int 置信度 = 80, BOOL 开启灰度图 = TRUE, BOOL 是否打开查看器 = FALSE);

//【======================================================================YOLO模块========================================================】
//特别注意:
//内部实现上,Yolo是使用了全局的静态模型. 所有的对象是共用模型. 所以在多线程的使用上要特别注意.
//对于同一个序号的模型,在多线程上是排队执行的
//设置全局模型文件(初始化设置,不要在识别执行的时候设置)
//type:模型序号/类型(自定义枚举值 常量值) -1表示空模型序号 不要重复了
//classNames:类别名 如:精灵|NPC|怪物|玩家|动物 “|”隔开
//width:训练模型用到的训练宽度
//height:训练模型用到的训练高度
//file:onne文件或者加密文件
//password:密码:没有为空(0)就行
//注意:
//1.添加文件和序号的绑定,并真正的加载模型资源到内存
//2.单线程全局初始化设置
//3.文件数量理论上无限,但是别太多了,很占内存
//4.如果不切换那么默认使用第一个设置的序号模型
HEARTDLL_API_HDAI __int64 __stdcall HCYOLO_SetModelFile(__int32 type, char* classNames, char *file, __int32 width, __int32 height, char* password);

//index:模型序号
//全局切换
//-1表示停止模型识别
//成功返回当前切换的模型序号
HEARTDLL_API_HDAI __int64 __stdcall HCYOLO_SwitchModelFile(__int32 type);

//图片来源窗口序号对应的后台截图
//conf:置信度
//iou:用于对多个检测框进行合并.  越大越不容易合并(很多框重叠). 越小越容易合并(可能会把正常的框也给合并). 一般在0.4-0.6之间
//bDebug:是否打开调试窗口查看
HEARTDLL_API_HDAI __int64 __stdcall HCYOLO_Excute(__int32 窗口序号, float conf = 0.7f, float iou = 0.4f, BOOL bDebug = FALSE);

//图片来源文件
//conf:置信度
//iou:用于对多个检测框进行合并.  越大越不容易合并(很多框重叠). 越小越容易合并(可能会把正常的框也给合并). 一般在0.4-0.6之间
//bDebug:是否打开调试窗口查看
HEARTDLL_API_HDAI __int64 __stdcall HCYOLO_ExcuteByFile(__int32 窗口序号, char *file, float conf = 0.7f, float iou = 0.4f, BOOL bDebug = FALSE);

//图片来源内存
//conf:置信度
//iou:用于对多个检测框进行合并.  越大越不容易合并(很多框重叠). 越小越容易合并(可能会把正常的框也给合并). 一般在0.4-0.6之间
//bDebug:是否打开调试窗口查看
HEARTDLL_API_HDAI __int64 __stdcall HCYOLO_ExcuteByMem(__int32 窗口序号, BYTE *imageData, __int32 dataSize, float conf = 0.7f, float iou = 0.4f, BOOL bDebug = FALSE);



//【=====================================================================通用YOLO模块========================================================】组件 使用ncnn模型
//发布版本用ncnn模型
//调试版本用工具测试
//ncnn模型
//bin ＝ “yolov5n.ncnn.bin”
//param ＝ “yolov5n.ncnn.param”
//从内存中加载模型
//版本 5 8 10 11 四个版本，选一个
//模型数据
//模型参数数据 
//是否GPU 默认假
//推理尺寸 训练模型填的多少，默认640
//备注:一个进程 仅同时支持一个版本的模型
HEARTDLL_API_HDAI __int64 __stdcall HCYOLO_AddModel(__int32 ver, void* modeData, __int32 modeDataSize, void* modeLparam, __int32 modeLparamSize, __int32 size = 640, BOOL bGpu = FALSE, char* password = NULL);


//从文件加载模型
//版本 5 8 10 11 四个版本，选一个
//模型文件 
//模型参数 
//是否GPU 默认假
//推理尺寸 训练模型填的多少，默认640
HEARTDLL_API_HDAI __int64 __stdcall HCYOLO_AddModelFile(__int32 ver, char* modeFileName, char* modeLparamName, __int32 size = 640, BOOL bGpu = FALSE, char* password = NULL);


//识别从后台
//image:支持绝对和相对路径
//结果从json获取
//%d,%f,%f,%f,%f,%f,%d|
//类别,X1,Y1,X2,Y2,置信度,耗时|
HEARTDLL_API_HDAI __int64 __stdcall HCYOLO_Identify(__int32 窗口序号,float conf = 0.7f, float iou = 0.4f, BOOL bDebug = FALSE);


//识别从文件
//image:支持绝对和相对路径
//结果从json获取
//%d,%f,%f,%f,%f,%f,%d|
//类别,X1,Y1,X2,Y2,置信度,耗时|
HEARTDLL_API_HDAI __int64 __stdcall HCYOLO_IdentifyByFile(__int32 窗口序号, char* image, float conf = 0.7f, float iou = 0.4f, BOOL bDebug = FALSE);


//识别从内存
//结果从json获取
//%d,%f,%f,%f,%f,%f,%d|
//类别,X1,Y1,X2,Y2,置信度,耗时|
HEARTDLL_API_HDAI __int64 __stdcall HCYOLO_IdentifyByMem(__int32 窗口序号, void* imgData,__int32 imgDataSize, float conf = 0.7f, float iou = 0.4f, BOOL bDebug = FALSE);



//【=====================================================================通用Paddle Ocr V5模块========================================================】组件 使用onnx模型
//添加onnx模型并开启OCR服务
//det_infer:训练模型onnx 如:ch_PP-OCRv5_mobile_det.onnx
//cls_infer:校验模型onnx 如:ch_PP-OCRv5_rec_mobile_infer.onnx
//rec_infer:方向模型onnx 如:ch_ppocr_mobile_v2.0_cls_infer.onnx 一般不指定默认使用官方默认的
//keys:字典字库文件txt 如:ppocrv5_dict.txt 一般官方有字集文件 如果没有就自己写一个 一行一个字
//parameterjson:参数json格式字符串
//password:模型加解密密码 调试版本不能使用加载模型
//返回:
//多次调用会自动关闭之前的服务然后重启
//json配置:"{ \"cpu_mem\":0,\"cpu_threads\":2,\"use_gpu\":false,\"gpu_id\":-1,\"gpu_mem\":1024,\"padding\":50,\"maxSideLen\":1024,\"boxScoreThresh\":0.5,\"boxThresh\":0.3,\"unClipRatio\":1.6,\"doAngle\":true,\"mostAngle\":true,\"visualize\":false,\"enable_log\":false,\"isOutputConsole\":true}";
HEARTDLL_API_HDAI __int64 __stdcall HCPOCR_AddModel(char* det_infer, char* cls_infer, char* rec_infer, char* keys,char* parameterjson,char* password = NULL);

//基于截图缓存识别
//windIndex:窗口序号
//x,y,w,h:左上角+宽度+高度 全为-1表示全图 内部自动修正
//conf:每个字或字符的相似度 当retText为真同时大于0 表示对每个字符置信度进程过滤(返回匹配的字符数量) 当retText为真同时conf小于等于0表示直接返回字符串(不过滤)(有字符串返回1空字符串返回0)
//fType:过滤类型 0 默认表示字符串每个字符的相似度的总和然后求平均值,最后conf和这个平均值比较(返回值表示匹配的字符串数量) 1 表示每个字符单独的相似度比较(返回值表示匹配的字符数量)
//retText:是否仅返回文本信息 设置为真表示需要对文本进程处理 具体如何处理看conf置信度的值大小 反之设置为假包含各种坐标属性json信息(始终返回1 需要自行解析json)
//bDebug:是否调试查看识别图片
//返回:看conf和retText参数解析
//字符串是utf-8编码
HEARTDLL_API_HDAI __int64 __stdcall HCPOCR_Identify(__int32 windIndex, int x = -1, int y = -1, int w = -1, int h = -1, float conf = 0.7f, int fType  = 0, BOOL retText = TRUE, BOOL bDebug = FALSE);


//基于指定图片文件识别
//windIndex:窗口序号
//imageFile:图片路径(绝对路径或者相对路径)
//conf:每个字或字符的相似度 当retText为真同时大于0 表示对每个字符置信度进程过滤(返回匹配的字符数量) 当retText为真同时conf小于等于0表示直接返回字符串(不过滤)(有字符串返回1空字符串返回0)
//fType:过滤类型 0 默认表示字符串每个字符的相似度的总和然后求平均值,最后conf和这个平均值比较(返回值表示匹配的字符串数量) 1 表示每个字符单独的相似度比较(返回值表示匹配的字符数量)
//retText:是否仅返回文本信息 设置为真表示需要对文本进程处理 具体如何处理看conf置信度的值大小 反之设置为假包含各种坐标属性json信息(始终返回1 需要自行解析json)
//bDebug:是否调试查看识别图片
//返回:看conf和retText参数解析
//字符串是utf-8编码
HEARTDLL_API_HDAI __int64 __stdcall HCPOCR_IdentifyByFile(__int32 windIndex, char* imageFile, float conf = 0.7f, int fType = 0, BOOL retText = TRUE, BOOL bDebug = FALSE);

//基于指定图片内存识别
//windIndex:窗口序号
//imagebytedata:一般是BMP图片数据 包含头+数据
//size:图片数据大小
//conf:每个字或字符的相似度 当retText为真同时大于0 表示对每个字符置信度进程过滤(返回匹配的字符数量) 当retText为真同时conf小于等于0表示直接返回字符串(不过滤)(有字符串返回1空字符串返回0)
//fType:过滤类型 0 默认表示字符串每个字符的相似度的总和然后求平均值,最后conf和这个平均值比较(返回值表示匹配的字符串数量) 1 表示每个字符单独的相似度比较(返回值表示匹配的字符数量)
//retText:是否仅返回文本信息 设置为真表示需要对文本进程处理 具体如何处理看conf置信度的值大小 反之设置为假包含各种坐标属性json信息(始终返回1 需要自行解析json)
//bDebug:是否调试查看识别图片
//返回:看conf和retText参数解析
//字符串是utf-8编码
HEARTDLL_API_HDAI __int64 __stdcall HCPOCR_IdentifyByMem(__int32 windIndex, void* imagebytedata, int size, float conf = 0.7f, int fType = 0, BOOL retText = TRUE, BOOL bDebug = FALSE);



//关闭OCR服务
HEARTDLL_API_HDAI __int64 __stdcall HCPOCR_Close();


//获取最近的错误信息
//windIndex:窗口序号
//返回:
//字符串是utf-8编码
HEARTDLL_API_HDAI __int64 __stdcall HCPOCR_GetLastError(__int32 windIndex);