#pragma once

#include <stdio.h>
#include <windows.h>

void Face()
{
	system("CLS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("\n\n\n");
	printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t\t�U         __  _______ _____                       �U\n");
	printf("\t\t\t\t�U        /  |/  / __ \\__  /                       �U\n");
	printf("\t\t\t\t�U       / /|_/ / /_/ //_ <                        �U\n");
	printf("\t\t\t\t�U      / /  / / ____/__/ /                        �U\n");
	printf("\t\t\t\t�U     /_/__/_/_/    /___/ ____________            �U\n");
	printf("\t\t\t\t�U     / __ \\/ /   /   \\ \\/ / ____/ __ \\           �U\n");
	printf("\t\t\t\t�U    / /_/ / /   / /| |\\  / __/ / /_/ /           �U\n");
	printf("\t\t\t\t�U   / ____/ /___/ ___ |/ / /___/ __ _/            �U\n");
	printf("\t\t\t\t�U  /_/   /_____/_/  |_/_/_____/_/ |_|     2.0  Ver�U\n");
	printf("\t\t\t\t�U                                                 �U\n");
	printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("\t\t\t\t    1.���벥��\t\t\t2.ʹ��˵��\n\n");
	printf("\t\t\t\t    3.����˵��\t\t\t0.�˳�����\n\n");

}

void Menu()
{
	system("CLS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("\t\t\t	             ___  __   _____  _________\n");
	printf("\t\t\t ________________   / _ \\/ /  / _ \\ \\/ / __/ _ \\   ________________\n");
	printf("\t\t\t/___/___/___/___/  / ___/ /__/ __ |\\  / _// , _/  /___/___/___/___/\n");
	printf("\t\t\t                  /_/  /____/_/ |_|/_/___/_/|_|\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	printf("\t\t\t\t                                                  \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t\t�U                                                �U\n");
	printf("\t\t\t\t�U *x.ѡ������               *space.����/��ͣ     �U\n");
	printf("\t\t\t\t�U                                                �U\n");
	printf("\t\t\t\t�U *a.��һ��                 *d.��һ��            �U\n");
	printf("\t\t\t\t�U                                                �U\n");
	printf("\t\t\t\t�U *w.����+                  *s.����-             �U\n");
	printf("\t\t\t\t�U                                                �U\n");
	printf("\t\t\t\t�U *p.ֹͣ����               *q.���ز˵�          �U\n");
	printf("\t\t\t\t�U                                                �U\n");
	printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void state()
{
	system("CLS");

	printf("\n\n\n");
	printf("\t\t 1.����Ĭ��·��Ϊ  D:\\music\\ \n\t\t  PATH�궨����function.h��ͷ\n\n");
	printf("\t\t 2.�����ں��Ѹ�ΪBASS,����ʱ��bass.dll�ļ���exe�ļ�����ͬ·���¡�\n\n");
	printf("\t\t 3.mp3�ļ������˳���200���ַ������ܿ�����\n\n\n");

	printf("\t\t\t\t\t\t\t\t\t\t����ʱ�䣺2020.7.22\n");
	printf("\t\t\t\t\t\t\t\t\t\t�����£�2023.8.19\n\n");
	system("pause");
}

void info()
{
	system("CLS");
	printf("\n\n");
	printf("\t\t    Դ���룺https://github.com/blueskybone/c-projects/tree/master/MusicPlayer\n");
	printf("\t\t    ���߳�ѧ��Ʒ������ṹ�ϻ��ң�������ο���\n\n");
	system("pause");
}