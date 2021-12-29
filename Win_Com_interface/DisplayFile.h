#pragma once
#ifndef _DisplayFile_H_
#define _DisplayFile_H_
#include<Windows.h>

typedef struct {
	//继承父类WIN32_FIND_DATA、HANDLE和CHAR
	WIN32_FIND_DATA FindFileData;
	HANDLE hListFile;
	CHAR szFilePath[MAX_PATH];
}EnumFileDrectory;

//EnumerateFileInDrectory构造函数
void EnumFileDrectory_Ctor(EnumFileDrectory *This, LPCWSTR szPath);

//获取EnumFileDrectory属性声明
WIN32_FIND_DATA EFDrectory_GetFindFileData(EnumFileDrectory *This);
HANDLE EFDrectory_GetListFile(EnumFileDrectory* This);
CHAR EFDrectory_GetFilePath(EnumFileDrectory* This);

//实现DisplayFIle方法
DWORD EnumerateFileInDrectory(EnumFileDrectory *This);
void DisplayFile();

#endif // !1
