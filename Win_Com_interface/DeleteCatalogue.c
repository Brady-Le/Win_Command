#include"DeleteCatalogue.h"
#include<string.h>
DeleteCata DeleteCata_Ctor()
{
	DeleteCata DC;
	//�ļ�Ŀ¼������szCurrentPath�ַ�������
	GetCurrentDirectory(MAX_PATH, DC.szCurrentPath);
	printf("������Ҫɾ��Ŀ¼����\n");
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
		printf("ɾ��Ŀ¼%sʧ�ܣ�\n", DC.szCurrentPath);
	else
		printf("ɾ��Ŀ¼%s�ɹ���\n", DC.szCurrentPath);
}