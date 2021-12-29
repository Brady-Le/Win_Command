#pragma once
#ifndef _RenameFile_H_
#define _RenameFIle_H_

typedef struct {
	char oldname[30];
	char newname[30];
	int result;
}RenameF;

RenameF RenameF_Ctor();

char Getoldname(RenameF* This);

char Getnewname(RenameF* This);

void RenameFile();
#endif // !_RenameFile_H_
