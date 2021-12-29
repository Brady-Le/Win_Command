#pragma once
#ifndef _PrintFile_H_
#define _PrintFile_H_
#include <stdio.h>

typedef struct {
	char b[256];
	FILE* fp;
}PrintF;

PrintF PrintF_Ctor();

char Getb(PrintF* This);

void PrintFile();

#endif // !_PrintFile_H_
