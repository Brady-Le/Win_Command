#include"RenameFile.h"
#include<stdio.h>

RenameF RenameF_Ctor()
{
	RenameF RF;
	printf("������Ҫ�޸ĵ��ļ�������:\n");
	scanf("%s", RF.oldname);
	printf("�������µ��ļ�����:\n");
	scanf("%s", RF.newname);
	return RF;
}

char Getoldname(RenameF* This)
{
	return This->oldname;
}

char Getnewname(RenameF* This)
{
	return This->newname;
}

void RenameFile()
{
	RenameF RF = RenameF_Ctor();
	RF.result = rename(RF.oldname, RF.newname);
	if (RF.result == 0)
		puts("�ļ��������ɹ�!");
	else
		perror("�ļ�������ʧ��!");
}