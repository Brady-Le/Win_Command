#include"Command_interpreter.h"

int main()
{
	int i = 0, j = 3;
	char d[10];
	printf("\n                               ��ӭ�����ϵͳ               \n");
	ShowVersion();
	printf("������cmd�������������:");
	scanf("%s", d);
	for (i = 0; i < 2; i++)
	{
		if (_stricmp(d, "cmd") == 0)
		{
			Command_interpreter();
		}
		else
		{
			j = j - 1;
			printf("�㻹��%d�λ���!", j);
			printf("������cmd�������������:");
			scanf("%s", d);
		}
	}
	printf("������������˳�����!");
	return 0;
}