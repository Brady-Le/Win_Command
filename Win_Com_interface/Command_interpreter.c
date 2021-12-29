//命令解释接口
#include"Command_interpreter.h"
#include"guide.h"
#include"cmd_char.h"
#include"Esc.h"
#include"Help.h"

//中断命令接口
#include "DisplayFile.h"
#include "GetTime.h"
#include "ReviewString.h"
#include "CreateCatalogue.h"
#include "DeleteCatalogue.h"
#include "ChangeCatalog.h"
#include "DisplayCatalogue.h"
#include "DeleteCatalogue.h"
#include "PrintFile.h"
#include "RenameFile.h"
#include "ShowFileMessage.h"
#include "ShowVersion.h"
#include "DisplayAllFileCatalogue.h"
#include "ClearScreen.h"
#include "DeleteFiles.h"

#include<stdio.h>

void Command_interpreter()
{
	int a;
	guide();
	while (1)
	{
		a = cmd_char();
		switch (a)
		{
		case 1:
			DisplayFile();
			break;
		case 2:
			GetTime();
			break;
		case 4:
			ReviewString();
			break;
		case 5:
			CreateCatalogue();
			break;
		case 6:
			DeleteCatalogue();
			break;
		case 7:
			ChangeCatalog();
			break;
		case 8:
			DisplayCatalogue();
			break;
		case 9:
			DeleteFiles();
			break;
		case 10:
			PrintFile();
			break;
		case 11:
			RenameFile();
			break;
		case 12:
			ShowFileMessage();
			break;
		case 13:
			ShowVersion();
			break;
		case 14:
			DisplayAllCatalogue();
			break;
		case 15:
			ClearScreen();
			break;
		case 16:
			Esc();
			break;
		case 17:
			Help();
			break;
		case 0:
			printf("无法识别的指令，请输入正确的指令!\n");
			break;
		default:
			break;
		}
	}
}