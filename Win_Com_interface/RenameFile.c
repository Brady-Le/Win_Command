#include"RenameFile.h"
#include<stdio.h>

RenameF RenameF_Ctor()
{
	RenameF RF;
	printf("请输入要修改的文件的名称:\n");
	scanf("%s", RF.oldname);
	printf("请输入新的文件名称:\n");
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
		puts("文件重命名成功!");
	else
		perror("文件重命名失败!");
}