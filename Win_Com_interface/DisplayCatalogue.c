#include"DisplayCatalogue.h"

DisplayCata DisplayCata_Ctor()
{
	DisplayCata DC;
	//获取当前路径
	DC.dwCurDirPathlen = GetCurrentDirectory(MAX_PATH, DC.szCurrentDirectory);
	return DC;
}

void DisplayCatalogue()
{
	DisplayCata DC;
	DC.dwCurDirPathlen = GetCurrentDirectory(MAX_PATH, DC.szCurrentDirectory);
	if (DC.dwCurDirPathlen == 0)
	{
		printf("获取当前目录失败！\n");
		return 1;
	}
	printf("进程当前目录为%s\n", DC.szCurrentDirectory);
}