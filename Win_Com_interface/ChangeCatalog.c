#include"ChangeCatalog.h"
#include<string.h>

ChangeCata ChangeCata_Ctor()
{
	//��ȡ��ǰ·��
	ChangeCata ChangC;
	ChangC.dwCurDirPathlen = GetCurrentDirectory(MAX_PATH, ChangC.szCurrentDirectory);
	return ChangC;
}

CHAR GetszCurrentDir(ChangeCata* This)
{
	return This->szCurrentDirectory;
}

CHAR GetnewCurrentDir(ChangeCata* This)
{
	return This->newCurrentDirectory;
}

DWORD GetdwCurDirPathlen(ChangeCata* This)
{
	return This->dwCurDirPathlen;
}

void ChangeCatalog()
{
	ChangeCata ChangC = ChangeCata_Ctor();
	printf("���̵�ǰĿ¼Ϊ%s\n", ChangC.szCurrentDirectory);
	printf("�����µ�·��");
	scanf("%s", ChangC.newCurrentDirectory);
	lstrcpy(ChangC.szCurrentDirectory, ChangC.newCurrentDirectory);
	if (!SetCurrentDirectory(ChangC.szCurrentDirectory))
	{
		printf("�޸���·��ʧ��");
		return 1;
	}
	printf("�޸ĺ���̵�ǰĿ¼Ϊ%s\n", ChangC.szCurrentDirectory);
}