#include"ReviewString.h"
#include<stdio.h>
#include<string.h>
#include<malloc.h>

RevString RevString_Ctor(size_t length, char a[MAXLEN])
{
	RevString S;
	S.ch = (char*)malloc(MAXLEN * sizeof(char));
	S.length = length;
	S.ch = a;
	return S;
}

char GetRString(RevString* This)
{
	return This->ch;
}

void ReviewString()
{
	char a[MAXLEN];
	printf("ÇëÊäÈë×Ö·û´®\n");
	scanf("%s", a);

	size_t len = strlen(a);
	RevString RS = RevString_Ctor(len, a);

	printf("%s\n", RS.ch);
}