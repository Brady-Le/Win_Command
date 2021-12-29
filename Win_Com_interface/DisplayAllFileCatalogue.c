#include"DisplayAllFileCatalogue.h";
#include<string.h>
#include<stdio.h>

DisplayAllFileCata DisplayAllFileCata_Ctor(LPSTR szPath)
{
	DisplayAllFileCata DAFC;
	//将szPath字符串复杂到szFilePath缓冲区
	lstrcpy(DAFC.szFilePath, szPath);
	//将\\*和szFilePath连接，构造文件目录
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
	//将szPath字符串复杂到szFilePath缓冲区
	lstrcpy(DAFC.szFilePath, szPath);
	//将\\*和szFilePath连接，构造文件目录
	lstrcat(DAFC.szFilePath, "\\*");
	DAFC.hListFile = FindFirstFile(DAFC.szFilePath, &DAFC.FindFileData);
	if (DAFC.hListFile == INVALID_HANDLE_VALUE)
	{
		//返回FindFirstFile方法错误代码并报错
		printf("错误:%d", GetLastError());
		//返回非正常终止
		return 1;
	}
	else
	{
		do
		{
			//不显示代表本级目录和上级目录的"."和".."
			if (lstrcmp(DAFC.FindFileData.cFileName, TEXT(".")) == 0 || lstrcmp(DAFC.FindFileData.cFileName, TEXT("..")) == 0)
			{
				//过滤本级目录和父级目录
				continue;
			}
			//构造成全路径
			wsprintf(DAFC.szFullPath, "%s\\%s", szPath, DAFC.FindFileData.cFileName);
			DAFC.dwTotalFileNum++;
			//打印文件名、目录名
			printf("\n%d\t%s\t", DAFC.dwTotalFileNum, DAFC.szFullPath);


			if (DAFC.FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				//判断目标文件的文件属性是否与文件夹属性一致，即判断该目标是否为文件夹
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