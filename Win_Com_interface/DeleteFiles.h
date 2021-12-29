#pragma once
#ifndef _DeleteFiles_H_
#define _DeleteFiles_H_
#include<Windows.h>

typedef struct {
	char DFstr[30];
	CHAR szCurrentPath[MAX_PATH];
}DelFile;

DelFile DelFile_Ctor();

char GetDFstr(DelFile* This);

void DeleteFiles();


#endif // !_DeleteFiles_H_
