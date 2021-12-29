#include"PrintFile.h"

PrintF PrintF_Ctor()
{
	PrintF PF;
	PF.fp = fopen("a.txt", "wt+");
	return PF;
}

char Getb(PrintF* This)
{
	return This->b;
}

void PrintFile()
{
	PrintF PF = PrintF_Ctor();
	printf("输入要打印的内容:");
	scanf("%s", PF.b);
	fprintf(PF.fp, PF.b);
	fclose(PF.fp);
	printf("打印文档内容%s成功！\n", PF.b);
}