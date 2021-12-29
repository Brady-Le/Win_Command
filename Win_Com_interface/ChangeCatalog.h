#pragma once
#ifndef _ChangeCatalog_H_
#define _ChangeCatalog_H_
#include<Windows.h>

typedef struct {
	//储存当前路径
	CHAR szCurrentDirectory[MAX_PATH];
	CHAR newCurrentDirectory[MAX_PATH];
	//当前路径的长度，判断获取是否成功
	DWORD dwCurDirPathlen;
}ChangeCata;

ChangeCata ChangeCata_Ctor();

CHAR GetszCurrentDir(ChangeCata* This);

CHAR GetnewCurrentDir(ChangeCata* This);

DWORD GetdwCurDirPathlen(ChangeCata* This);

void ChangeCatalog();
#endif // !_ChangeCatalog_H_
