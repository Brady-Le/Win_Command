#pragma once
#ifndef _ReviewString_H_
#define _ReviewString_H_
#define MAXLEN 255
#include<string.h>
typedef struct {
	char* ch;
	size_t length;
}RevString;

RevString RevString_Ctor(size_t length, char a[MAXLEN]);

char GetRString(RevString* This);

void ReviewString();

#endif // !_ReviewString_H_
