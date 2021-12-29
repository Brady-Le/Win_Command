#include"CreateCatalogue.h"
#include<stdio.h>

CreateCata CreateCata_Ctor()
{
	CreateCata CC;
	char a[300];
	printf("请输入要创建目录的名称:\n");
	scanf("%s", a);
	CC.szDirPath = a;
	return CC;
}

LPSTR GetSzDirPath(CreateCata* This)
{
	return This->szDirPath;
}

int CreateCatalogue()
{
	CreateCata CC = CreateCata_Ctor();
	if (!CreateDirectory(CC.szDirPath, NULL))
		//函数原型：
		//	BOOL CreateDirectory(
		//		LPCWSTR lpPathName,
		//		LPSECURITY_ATTRIBUTES lpSecurityAttributes
		//	 pPathName：长指针，指向一个空结束的字符串，该字符串指定要创建的目录的路径。);

	{
		printf("创建目录%s失败\n", CC.szDirPath);
		return 1;
	}
	printf("创建目录%s成功\n", CC.szDirPath);
}