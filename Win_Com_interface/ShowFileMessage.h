#pragma once
#ifndef _ShowFileMessage_H_
#define _ShowFileMessage_H_
#include<stdio.h>

typedef struct {
	FILE* fp;
	char str[20];
	char ch;
}ShowFileMess;

ShowFileMess ShowFileMess_Ctor();

FILE* Getfp(ShowFileMess* This);

char Getstr(ShowFileMess* This);

char Getch(ShowFileMess* This);

int ShowFileMessage();
#endif // !_ShowFileMessage_H_
