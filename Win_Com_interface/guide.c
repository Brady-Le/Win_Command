#include"guide.h"
#include<stdio.h>
#include"Help.h"

void guide()
{
	char gd[10];
	printf("请输入help进入操作指南:\n");
	scanf("%s", gd);
	while (_stricmp(gd, "help"))
	{
		printf("输入错误，请重新输入！\n");
		scanf("%s", gd);
	}
	Help();
}