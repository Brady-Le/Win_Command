#include"ChangeCatalog.h"
#include<string.h>

ChangeCata ChangeCata_Ctor()
{
	//获取当前路径
	ChangeCata ChangC;
	ChangC.dwCurDirPathlen = GetCurrentDirectory(MAX_PATH, ChangC.szCurrentDirectory);
	return ChangC;
}

CHAR GetszCurrentDir(ChangeCata* This)
{
	return This->szCurrentDirectory;
}

CHAR GetnewCurrentDir(ChangeCata* This)
{
	return This->newCurrentDirectory;
}

DWORD GetdwCurDirPathlen(ChangeCata* This)
{
	return This->dwCurDirPathlen;
}

void ChangeCatalog()
{
	ChangeCata ChangC = ChangeCata_Ctor();
	printf("进程当前目录为%s\n", ChangC.szCurrentDirectory);
	printf("输入新的路径");
	scanf("%s", ChangC.newCurrentDirectory);
	lstrcpy(ChangC.szCurrentDirectory, ChangC.newCurrentDirectory);
	if (!SetCurrentDirectory(ChangC.szCurrentDirectory))
	{
		printf("修改新路径失败");
		return 1;
	}
	printf("修改后进程当前目录为%s\n", ChangC.szCurrentDirectory);
}