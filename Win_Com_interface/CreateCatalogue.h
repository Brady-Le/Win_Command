#pragma once
#ifndef _CreateCatalogue_H_
#define _CreateCatalogue_H_
#include<Windows.h>

typedef struct {
	//ע���ٴ��½���ʱ������֮ǰ�Ѿ��ɹ��½����ͻ���ʾ����ʧ�� LPSTR��Win32��VC++��ʹ�õ�һ���ַ�����������
	LPSTR szDirPath;
}CreateCata;

CreateCata CreateCata_Ctor();

LPSTR GetSzDirPath(CreateCata* This);

int CreateCatalogue();
#endif // !_CreateCatalogue_H_
