#include"DeleteCatalogue.h"
#include<string.h>
DeleteCata DeleteCata_Ctor()
{
	DeleteCata DC;
	//文件目录保存再szCurrentPath字符数组中
	GetCurrentDirectory(MAX_PATH, DC.szCurrentPath);
	printf("请输入要删除目录名称\n");
	scanf("%s", DC.Cstr);
	strcat(DC.szCurrentPath, "\\");
	strcat(DC.szCurrentPath, DC.Cstr);
	return DC;
}

char GetCstr(DeleteCata* This)
{
	return This->Cstr;
}

CHAR GetszCurrentPath(DeleteCata* This)
{
	return This->szCurrentPath;
}

void DeleteCatalogue()
{
	DeleteCata DC = DeleteCata_Ctor();
	if (RemoveDirectory(DC.szCurrentPath) == 0)
		printf("删除目录%s失败！\n", DC.szCurrentPath);
	else
		printf("删除目录%s成功！\n", DC.szCurrentPath);
}