#include"guide.h"
#include<stdio.h>
#include"Help.h"

void guide()
{
	char gd[10];
	printf("������help�������ָ��:\n");
	scanf("%s", gd);
	while (_stricmp(gd, "help"))
	{
		printf("����������������룡\n");
		scanf("%s", gd);
	}
	Help();
}