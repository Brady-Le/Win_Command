#pragma once
#ifndef _DisplayAllFileCatalogue_H_
#define _DisplayAllFileCatalogue_H_
#include<Windows.h>

typedef struct {
	CHAR szFilePath[MAX_PATH];
	CHAR szFullPath[MAX_PATH];
	WIN32_FIND_DATA FindFileData;
	HANDLE hListFile;
	unsigned long dwTotalFileNum;
}DisplayAllFileCata;

DisplayAllFileCata DisplayAllFileCata_Ctor(LPSTR szPath);

CHAR GetszFilePath(DisplayAllFileCata* This);

CHAR GetszFullPath(DisplayAllFileCata* This);

WIN32_FIND_DATA GetFindFileData(DisplayAllFileCata* This);

HANDLE GethListFile(DisplayAllFileCata* This);

unsigned long GetdwTotalFileNum(DisplayAllFileCata* This);

int DisplayAllFileCatalogue(LPSTR szPath);

void DisplayAllCatalogue();

#endif // !_DisplayAllFileCatalogue_H_
