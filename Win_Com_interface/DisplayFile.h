#pragma once
#ifndef _DisplayFile_H_
#define _DisplayFile_H_
#include<Windows.h>

typedef struct {
	//�̳и���WIN32_FIND_DATA��HANDLE��CHAR
	WIN32_FIND_DATA FindFileData;
	HANDLE hListFile;
	CHAR szFilePath[MAX_PATH];
}EnumFileDrectory;

//EnumerateFileInDrectory���캯��
void EnumFileDrectory_Ctor(EnumFileDrectory *This, LPCWSTR szPath);

//��ȡEnumFileDrectory��������
WIN32_FIND_DATA EFDrectory_GetFindFileData(EnumFileDrectory *This);
HANDLE EFDrectory_GetListFile(EnumFileDrectory* This);
CHAR EFDrectory_GetFilePath(EnumFileDrectory* This);

//ʵ��DisplayFIle����
DWORD EnumerateFileInDrectory(EnumFileDrectory *This);
void DisplayFile();

#endif // !1
