#include"DeleteFiles.h"
#include<string.h>

DelFile DelFile_Ctor()
{
	DelFile DF;
	GetCurrentDirectory(MAX_PATH, DF.szCurrentPath);
	printf("请输入要删除文件名\n");
	scanf("%s", DF.DFstr);
	strcat(DF.szCurrentPath, "\\");
	strcat(DF.szCurrentPath, DF.DFstr);
	return DF;
}

char GetDFstr(DelFile* This)
{
	return This->DFstr;
}

void DeleteFiles()
{
	DelFile DF = DelFile_Ctor();
	if (!DeleteFile(DF.szCurrentPath))
		printf("删除文件失败!");
	else
		printf("删除文件成功！");
}