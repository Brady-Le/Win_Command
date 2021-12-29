#include"DisplayFile.h"
#include<stdio.h>

// 父类构造函数实现
void EnumFileDrectory_Ctor(EnumFileDrectory* This, LPSTR szPath)
{
	//构造代表子目录和文件夹路径的字符串，使用通配符"*"
	lstrcpy(This->szFilePath, szPath);
	lstrcat(This->szFilePath, "\\*");
	This->hListFile = FindFirstFile(This->szFilePath, &This->FindFileData);//查找第一个文件\目录，获得查找句柄
}

WIN32_FIND_DATA EFDrectory_GetFindFileData(EnumFileDrectory* This)
{
	return This->FindFileData;
}

HANDLE EFDrectory_GetListFile(EnumFileDrectory* This)
{
	return This->hListFile;
}

CHAR EFDrectory_GetFilePath(EnumFileDrectory* This)
{
	return This->szFilePath;
}

DWORD EnumerateFileInDrectory(EnumFileDrectory* This)
{
	//判断句柄
	if (EFDrectory_GetListFile(This) == INVALID_HANDLE_VALUE)
	{
		printf("错误:%d", GetLastError());
		return 1;
	}
	else
	{
		do
		{
			//if (lstrcmp(EFDrectory_GetFindFileData(This).cFileName, TEXT(".")) == 0 || lstrcmp(EFDrectory_GetFindFileData(This).cFileName, TEXT("..")) == 0)
			//{
			//	continue;
			//}
			//打印文件名，目录名
			printf("   %s\t\t", EFDrectory_GetFindFileData(This).cFileName);
			//判断文件属性，是否为加密文件或者文件夹
			if (EFDrectory_GetFindFileData(This).dwFileAttributes & FILE_ATTRIBUTE_ENCRYPTED)
			{
				printf("<加密>");
			}
			//判断文件属性，是否为隐藏文件或者文件夹
			if (EFDrectory_GetFindFileData(This).dwFileAttributes & FILE_ATTRIBUTE_HIDDEN);
			{
				printf("<隐藏>");
			}
			//判断文件属性，是否为目录
			if (EFDrectory_GetFindFileData(This).dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
			{
				printf("<DIR>");
			}
			printf("\n");
		} while (FindNextFile(This->hListFile, &This->FindFileData));
	}
	return 0;
}

void DisplayFile()
{
	int argc = 1;
	EnumFileDrectory EFD;

	if (argc == 2)
	{
		EnumerateFileInDrectory(NULL);
	}
	else
	{
		CHAR szCurrentPath[MAX_PATH];
		GetCurrentDirectory(MAX_PATH, szCurrentPath);
		EnumFileDrectory_Ctor(&EFD, szCurrentPath);
		EnumerateFileInDrectory(&EFD);
	}
	printf("\n");
}