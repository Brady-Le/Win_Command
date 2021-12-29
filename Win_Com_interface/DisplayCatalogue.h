#pragma once
#ifndef _DisplayCatalogue_H_
#define _DisplayCatalogue_H_
#include<Windows.h>

typedef struct {
	CHAR szCurrentDirectory[MAX_PATH];
	//当前路径的长度，也用于判断获取是否成功
	DWORD dwCurDirPathlen;
}DisplayCata;

DisplayCata DisplayCata_Ctor();

void DisplayCatalogue();

#endif // !_DisplayCatalogue_H_
