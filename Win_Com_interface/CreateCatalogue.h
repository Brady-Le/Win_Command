#pragma once
#ifndef _CreateCatalogue_H_
#define _CreateCatalogue_H_
#include<Windows.h>

typedef struct {
	//注意再次新建的时候由于之前已经成功新建，就会提示创建失败 LPSTR是Win32和VC++所使用的一种字符串数据类型
	LPSTR szDirPath;
}CreateCata;

CreateCata CreateCata_Ctor();

LPSTR GetSzDirPath(CreateCata* This);

int CreateCatalogue();
#endif // !_CreateCatalogue_H_
