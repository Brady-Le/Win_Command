#include"DisplayCatalogue.h"

DisplayCata DisplayCata_Ctor()
{
	DisplayCata DC;
	//��ȡ��ǰ·��
	DC.dwCurDirPathlen = GetCurrentDirectory(MAX_PATH, DC.szCurrentDirectory);
	return DC;
}

void DisplayCatalogue()
{
	DisplayCata DC;
	DC.dwCurDirPathlen = GetCurrentDirectory(MAX_PATH, DC.szCurrentDirectory);
	if (DC.dwCurDirPathlen == 0)
	{
		printf("��ȡ��ǰĿ¼ʧ�ܣ�\n");
		return 1;
	}
	printf("���̵�ǰĿ¼Ϊ%s\n", DC.szCurrentDirectory);
}