#pragma once
#ifndef _ChangeCatalog_H_
#define _ChangeCatalog_H_
#include<Windows.h>

typedef struct {
	//���浱ǰ·��
	CHAR szCurrentDirectory[MAX_PATH];
	CHAR newCurrentDirectory[MAX_PATH];
	//��ǰ·���ĳ��ȣ��жϻ�ȡ�Ƿ�ɹ�
	DWORD dwCurDirPathlen;
}ChangeCata;

ChangeCata ChangeCata_Ctor();

CHAR GetszCurrentDir(ChangeCata* This);

CHAR GetnewCurrentDir(ChangeCata* This);

DWORD GetdwCurDirPathlen(ChangeCata* This);

void ChangeCatalog();
#endif // !_ChangeCatalog_H_
