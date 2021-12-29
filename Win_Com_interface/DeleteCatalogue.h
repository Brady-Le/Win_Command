#pragma once
#ifndef _DeleteCatalogue_H_
#define _DeleteCatalogue_H_
#include<Windows.h>

typedef struct {
	char Cstr[MAX_PATH];
	CHAR szCurrentPath[MAX_PATH];
}DeleteCata;

DeleteCata DeleteCata_Ctor();

char GetCstr(DeleteCata* This);

CHAR GetszCurrentPath(DeleteCata* This);

void DeleteCatalogue();
#endif // !_DeleteCatalogue_H_
