#include"DeleteFiles.h"
#include<string.h>

DelFile DelFile_Ctor()
{
	DelFile DF;
	GetCurrentDirectory(MAX_PATH, DF.szCurrentPath);
	printf("������Ҫɾ���ļ���\n");
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
		printf("ɾ���ļ�ʧ��!");
	else
		printf("ɾ���ļ��ɹ���");
}