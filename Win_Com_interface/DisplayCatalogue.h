#pragma once
#ifndef _DisplayCatalogue_H_
#define _DisplayCatalogue_H_
#include<Windows.h>

typedef struct {
	CHAR szCurrentDirectory[MAX_PATH];
	//��ǰ·���ĳ��ȣ�Ҳ�����жϻ�ȡ�Ƿ�ɹ�
	DWORD dwCurDirPathlen;
}DisplayCata;

DisplayCata DisplayCata_Ctor();

void DisplayCatalogue();

#endif // !_DisplayCatalogue_H_
