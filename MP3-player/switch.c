#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"face.h"
#include"switch.h"
#include"function.h"

char ch1;
struct media* HEAD, *P;

void Main_Switch()//main menu
{
	int flag = 1;
	char ch;
	while (flag)
	{
		Face();
		ch = _getch();
		switch (ch)
		{
		case '1':Player_Switch(); break;
		case '2':state(); break;
		case '3':info(); break;
		case '0':flag = 0; break;
		default:break;
		}
	}
}

void Player_Switch()
{

	P = NULL;
	int flag; flag = 1;
	while (flag)
	{
		Menu_Player();
		SongPlaying(P);
		ch1 = _getch();
		HEAD = CreatHead();

		switch (ch1)
		{
		case 'x':P = Choose_Song(HEAD, P); break;
		case ' ':Pause_Play(P); break;
		case 'a':P = Last_Play(HEAD, P); break;
		case 'd':P = Next_Play(P); break;
		case 'w':VolUp(P); break;
		case 's':VolDown(P); break;
		case 'p':Close_Play(P); break;
		case 'q':Close_Play(P); flag = 0; break;
		default:break;
		}
	}
}