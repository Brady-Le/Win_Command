#include"CreateCatalogue.h"
#include<stdio.h>

CreateCata CreateCata_Ctor()
{
	CreateCata CC;
	char a[300];
	printf("������Ҫ����Ŀ¼������:\n");
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
		//����ԭ�ͣ�
		//	BOOL CreateDirectory(
		//		LPCWSTR lpPathName,
		//		LPSECURITY_ATTRIBUTES lpSecurityAttributes
		//	 pPathName����ָ�룬ָ��һ���ս������ַ��������ַ���ָ��Ҫ������Ŀ¼��·����);

	{
		printf("����Ŀ¼%sʧ��\n", CC.szDirPath);
		return 1;
	}
	printf("����Ŀ¼%s�ɹ�\n", CC.szDirPath);
}