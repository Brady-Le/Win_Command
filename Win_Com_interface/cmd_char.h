#pragma once
#ifndef _Cmd_Char_H_
#define _Cmd_Char_H_

typedef struct {
	char cc[1000];
}Cmd;

Cmd Cmd_Ctor();

char Getcc(Cmd* This);

int cmd_char();
#endif // !_Cmd_Char_H_
