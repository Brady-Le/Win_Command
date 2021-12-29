#include"DisplayFile.h"
#include<stdio.h>

// ���๹�캯��ʵ��
void EnumFileDrectory_Ctor(EnumFileDrectory* This, LPSTR szPath)
{
	//���������Ŀ¼���ļ���·�����ַ�����ʹ��ͨ���"*"
	lstrcpy(This->szFilePath, szPath);
	lstrcat(This->szFilePath, "\\*");
	This->hListFile = FindFirstFile(This->szFilePath, &This->FindFileData);//���ҵ�һ���ļ�\Ŀ¼����ò��Ҿ��
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
	//�жϾ��
	if (EFDrectory_GetListFile(This) == INVALID_HANDLE_VALUE)
	{
		printf("����:%d", GetLastError());
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
			//��ӡ�ļ�����Ŀ¼��
			printf("   %s\t\t", EFDrectory_GetFindFileData(This).cFileName);
			//�ж��ļ����ԣ��Ƿ�Ϊ�����ļ������ļ���
			if (EFDrectory_GetFindFileData(This).dwFileAttributes & FILE_ATTRIBUTE_ENCRYPTED)
			{
				printf("<����>");
			}
			//�ж��ļ����ԣ��Ƿ�Ϊ�����ļ������ļ���
			if (EFDrectory_GetFindFileData(This).dwFileAttributes & FILE_ATTRIBUTE_HIDDEN);
			{
				printf("<����>");
			}
			//�ж��ļ����ԣ��Ƿ�ΪĿ¼
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