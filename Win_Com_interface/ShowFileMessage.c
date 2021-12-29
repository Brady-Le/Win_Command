#include"ShowFileMessage.h"

ShowFileMess ShowFileMess_Ctor()
{
	ShowFileMess SFM;
	printf("请输入要打开的文本名称:\n");
	scanf("%s", SFM.str);
	return SFM;
}

FILE* Getfp(ShowFileMess* This)
{
	return This->fp;
}

char Getstr(ShowFileMess* This)
{
	return This->str;
}

char Getch(ShowFileMess* This)
{
	return This->ch;
}

int ShowFileMessage()
{
	ShowFileMess SFM = ShowFileMess_Ctor();
	if ((SFM.fp = fopen(SFM.str, "rt")) == NULL)
	{
		printf("\n打开文件失败%s!", SFM.str);
		return 1;
	}
	SFM.ch = fgetc(SFM.fp);
	while (SFM.ch != EOF)
	{
		putchar(SFM.ch);
		SFM.ch = fgetc(SFM.fp);
	}
	printf("\n");
	fclose(SFM.fp);
}