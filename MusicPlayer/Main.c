#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"face.h"
#include"function.h"

struct media* HEAD, *P;

void Player_Switch();
int main()
{
    char ch;
	while (1)
	{
		Face();
		ch = _getch();
		switch (ch)
		{
		case '1':Player_Switch(); break;
		case '2':state(); break;
		case '3':info(); break;
		case '0':return 0; break;
		default:break;
		}
	}
}

void Player_Switch()
{
	P = NULL;
	int flag = 1;
	InitBASS();
	while (flag)
	{
		Menu();
		SongPlaying(P);
		char ch1 = _getch();
		HEAD = CreatHead();

		switch (ch1)
		{
		case 'x':P = Choose_Song(HEAD, P); break;
		case ' ':Pause_Play(P); break;
		case 'a':P = Last_Play(HEAD, P); break;
		case 'd':P = Next_Play(P); break;
		case 'w':Vol_Up(P); break;
		case 's':Vol_Down(P); break;
		case 'p':Close_Play(P); break;
		case 'q':Close_Play(P); flag = 0; break;
		default:break;
		}
	}
}