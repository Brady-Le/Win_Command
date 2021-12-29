#include"DisplayAllFileCatalogue.h";
#include<string.h>
#include<stdio.h>

DisplayAllFileCata DisplayAllFileCata_Ctor(LPSTR szPath)
{
	DisplayAllFileCata DAFC;
	//��szPath�ַ������ӵ�szFilePath������
	lstrcpy(DAFC.szFilePath, szPath);
	//��\\*��szFilePath���ӣ������ļ�Ŀ¼
	lstrcat(DAFC.szFilePath, "\\*");
	DAFC.hListFile = FindFirstFile(DAFC.szFilePath, &DAFC.FindFileData);
	return DAFC;
}

CHAR GetszFilePath(DisplayAllFileCata* This)
{
	return This->szFilePath;
}

CHAR GetszFullPath(DisplayAllFileCata* This)
{
	return This->szFullPath;
}

WIN32_FIND_DATA GetFindFileData(DisplayAllFileCata* This)
{
	return This->FindFileData;
}

unsigned long GetdwTotalFileNum(DisplayAllFileCata* This)
{
	return This->dwTotalFileNum;
}

HANDLE GethListFile(DisplayAllFileCata* This)
{
	return This->hListFile;
}

int DisplayAllFileCatalogue(LPSTR szPath)
{
	DisplayAllFileCata DAFC;
	//��szPath�ַ������ӵ�szFilePath������
	lstrcpy(DAFC.szFilePath, szPath);
	//��\\*��szFilePath���ӣ������ļ�Ŀ¼
	lstrcat(DAFC.szFilePath, "\\*");
	DAFC.hListFile = FindFirstFile(DAFC.szFilePath, &DAFC.FindFileData);
	if (DAFC.hListFile == INVALID_HANDLE_VALUE)
	{
		//����FindFirstFile����������벢����
		printf("����:%d", GetLastError());
		//���ط�������ֹ
		return 1;
	}
	else
	{
		do
		{
			//����ʾ������Ŀ¼���ϼ�Ŀ¼��"."��".."
			if (lstrcmp(DAFC.FindFileData.cFileName, TEXT(".")) == 0 || lstrcmp(DAFC.FindFileData.cFileName, TEXT("..")) == 0)
			{
				//���˱���Ŀ¼�͸���Ŀ¼
				continue;
			}
			//�����ȫ·��
			wsprintf(DAFC.szFullPath, "%s\\%s", szPath, DAFC.FindFileData.cFileName);
			DAFC.dwTotalFileNum++;
			//��ӡ�ļ�����Ŀ¼��
			printf("\n%d\t%s\t", DAFC.dwTotalFileNum, DAFC.szFullPath);


			if (DAFC.FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				//�ж�Ŀ���ļ����ļ������Ƿ����ļ�������һ�£����жϸ�Ŀ���Ƿ�Ϊ�ļ���
				printf("<DIR>");
				DisplayAllFileCatalogue(DAFC.szFullPath);
			}
		} while (FindNextFile(DAFC.hListFile, &DAFC.FindFileData));
	}
	return 0;
}

void DisplayAllCatalogue()
{
	int argc = 1;
	if (argc == 2)
	{
		DisplayAllFileCatalogue(NULL);
	}
	else
	{
		CHAR szCurrentPath[MAX_PATH];
		GetCurrentDirectory(MAX_PATH, szCurrentPath);
		DisplayAllFileCatalogue(szCurrentPath);
	}
	printf("\n");
}