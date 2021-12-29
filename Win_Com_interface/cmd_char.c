#include"cmd_char.h"

Cmd Cmd_Ctor()
{
	Cmd cmd;
	printf("\n请输入相应的操作指令:");
	scanf("%s", cmd.cc);
	return cmd;
}

char Getcc(Cmd* This)
{
	return This->cc;
}

int cmd_char()
{
	Cmd cmd = Cmd_Ctor();
	if (_stricmp(cmd.cc, "lm") == 0)
		return 1;
	else if (_stricmp(cmd.cc, "st") == 0)
		return 2;
	else if (_stricmp(cmd.cc, "rn") == 0)
		return 4;
	else if (_stricmp(cmd.cc, "nm") == 0)
		return 5;
	else if (_stricmp(cmd.cc, "cm") == 0)
		return 6;
	else if (_stricmp(cmd.cc, "ch") == 0)
		return 7;
	else if (_stricmp(cmd.cc, "sd") == 0)
		return 8;
	else if (_stricmp(cmd.cc, "cw") == 0)
		return 9;
	else if (_stricmp(cmd.cc, "dy") == 0)
		return 10;
	else if (_stricmp(cmd.cc, "na") == 0)
		return 11;
	else if (_stricmp(cmd.cc, "dt") == 0)
		return 12;
	else if (_stricmp(cmd.cc, "sm") == 0)
		return 13;
	else if (_stricmp(cmd.cc, "ml") == 0)
		return 14;
	else if (_stricmp(cmd.cc, "cl") == 0)
		return 15;
	else if (_stricmp(cmd.cc, "esc") == 0)
		return 16;
	else if (_stricmp(cmd.cc, "help") == 0)
		return 17;
	else
		return 0;
}