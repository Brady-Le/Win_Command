#include"Command_interpreter.h"

int main()
{
	int i = 0, j = 3;
	char d[10];
	printf("\n                               欢迎进入此系统               \n");
	ShowVersion();
	printf("请输入cmd进入命令解释器:");
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
			printf("你还有%d次机会!", j);
			printf("请输入cmd进入命令解释器:");
			scanf("%s", d);
		}
	}
	printf("连续输入错误，退出程序!");
	return 0;
}