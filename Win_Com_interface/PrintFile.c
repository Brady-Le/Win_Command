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
	printf("����Ҫ��ӡ������:");
	scanf("%s", PF.b);
	fprintf(PF.fp, PF.b);
	fclose(PF.fp);
	printf("��ӡ�ĵ�����%s�ɹ���\n", PF.b);
}