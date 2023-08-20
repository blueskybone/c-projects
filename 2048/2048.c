#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define MAX_NUMBER 2048

int map[4][4]; // ��ͼ
int score;	   // �֔�

void Sdir();   // ���������
void Print(); 
void Printcover();
void Printinfo();
void Printuse();

void GameInitial();
boolean GameStart();

boolean JudgeEnd();
boolean JudgeZero();
boolean JudgeWin();

boolean move;

// ���̽���
void up();
void down();
void left();
void right();

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

boolean GameStart()
{
	GameInitial();
	system("cls");
	Print();
	while (1)
	{
		move = FALSE;
		char input;
		while (input = _getch())
		{
			if (input != 'W' && input != 'S' && input != 'A' && input != 'D' && input != 'w' && input != 's' && input != 'a' && input != 'd')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				printf("\t\t\tʹ��WSAD�ƶ�\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
																			 FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
			else
				break;
		}
		switch (input)
		{
		case 'W':
			up();
		case 'w':
			up();
			break;
		case 'S':
			down();
		case 's':
			down();
			break;
		case 'A':
			left();
		case 'a':
			left();
			break;
		case 'D':
			right();
		case 'd':
			right();
			break;
		}

		if (move == FALSE)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			printf("\t\t\t��Ч�ƶ�\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
																		 FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			Sdir();
			system("cls");
			Print();
			if (JudgeWin() == TRUE)
			{
				printf("\n\n\t YOU WIN");
				Sleep(1000);
				printf("\n\n\t �Ƿ����¿�ʼ  Y/N ");
				char input;
				while (input = _getch())
				{
					if (input == 'Y' || input == 'y')
						return TRUE;
					if (input == 'N' || input == 'n')
						return FALSE;
				}
			}
			else if (JudgeZero() == FALSE && JudgeEnd() == FALSE)
			{
				printf("\n\n\t YOU LOSE");
				Sleep(1000);
				printf("\n\n\t �Ƿ����¿�ʼ  Y/N ");
				char input;
				while (input = _getch())
				{
					if (input == 'Y' || input == 'y')
						return TRUE;
					if (input == 'N' || input == 'n')
						return FALSE;
				}
			}
		}
	}
}

int main()
{
	while (1)
	{
		system("cls");
		Printcover();
		char input;
		while (input = _getch())
		{
			if (input == '1' || input == '2' || input == '3' || input == '4')
				break;
		}
		switch (input)
		{
		case '1':
			break;
		case '2':
			system("cls");
			Printuse();
			getch();
			system("cls");
			continue;
			break;
		case '3':
			system("cls");
			Printinfo();
			getch();
			system("cls");
			continue;
			break;
		case '4':
			exit(0);
			break;
		}
		while (1)
		{
			if (GameStart() == FALSE)
				return 0;
		}
	}
}

// ��������
void Sdir()
{
	if (JudgeZero() == TRUE)
	{
		int x1, y1;
		do
		{
			x1 = rand() % 4, y1 = rand() % 4;
		} while (map[x1][y1] != 0);
		if (rand() % 2 == 1)
			map[x1][y1] = 4;
		else
			map[x1][y1] = 2;
	}
}
// ����
void Printcover()
{
	printf("\n\n\n\n\n");
	printf("\t\t   ___   ___   ____  ___ \n");
	printf("\t\t  |_  | / _ \\ / / / ( _ )\n");
	printf("\t\t / __/ / // //_  _// _ | \n");
	printf("\t\t/____/ \\___/  /_/  \\___/ \n\n\n\n");
	printf("\t\t 1 ��ʼ��Ϸ       2 ��Ϸ����\n\n");
	printf("\t\t 3 ����˵��       4 �˳���Ϸ\n\n");
}
// ����Ƿ��пո�
boolean JudgeZero()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (map[i][j] == 0)
				return TRUE;
		}
	return FALSE;
}

boolean JudgeEnd()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++)
		{
			if (map[i][j] == map[i][j + 1])
			{
				return TRUE;
			}
		}
	for (int j = 0; j < 4; j++)
		for (int i = 0; i < 3; i++)
		{
			if (map[i][j] == map[i + 1][j])
			{
				return TRUE;
			}
		}
	return FALSE;
}
boolean JudgeWin()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (map[i][j] == MAX_NUMBER)
			{
				return TRUE;
			}
		}
	return FALSE;
}
void GameInitial()
{
	score = 0;
	move = FALSE;
	srand((int)time(0));
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			map[i][j] = 0;
		}
	Sdir();
	Sdir();
}
// ��ӡ��Ϸ����
void Print()
{
	printf("\n\n\n\n");
	printf("\t�X�T�T�T�T�T�T�T�j�T�T�T�T�T�T�T�j�T�T�T�T�T�T�T�j�T�T�T�T�T�T�T�[\n");
	printf("\t�U       �U       �U       �U       �U\n");
	printf("\t");
	for (int j = 0; j < 4; j++)
	{
		if (map[0][j] == 0)
		{
			printf("�U    ", map[0][j]);
		}
		else
		{
			printf("�U   %d", map[0][j]);
		}
		int q = 10;
		int sec = 0;
		while ((map[0][j] / q) > 0)
		{
			q = q * 10;
			sec++;
		}
		for (int io = 0; io < 3 - sec; io++)
			printf(" ");
	}
	printf("�U\n");
	printf("\t�U       �U       �U       �U       �U\n");
	printf("\t�d�T�T�T�T�T�T�T�p�T�T�T�T�T�T�T�p�T�T�T�T�T�T�T�p�T�T�T�T�T�T�T�g\n");
	printf("\t�U       �U       �U       �U       �U\n");
	printf("\t");
	for (int j = 0; j < 4; j++)
	{
		if (map[1][j] == 0)
		{
			printf("�U    ", map[1][j]);
		}
		else
		{
			printf("�U   %d", map[1][j]);
		}
		int q = 10;
		int sec = 0;
		while ((map[1][j] / q) > 0)
		{
			q = q * 10;
			sec++;
		}
		for (int io = 0; io < 3 - sec; io++)
			printf(" ");
	}
	printf("�U\n");

	printf("\t�U       �U       �U       �U       �U\n");
	printf("\t�d�T�T�T�T�T�T�T�p�T�T�T�T�T�T�T�p�T�T�T�T�T�T�T�p�T�T�T�T�T�T�T�g\n");
	printf("\t�U       �U       �U       �U       �U\n");
	printf("\t");
	for (int j = 0; j < 4; j++)
	{
		if (map[2][j] == 0)
		{
			printf("�U    ", map[2][j]);
		}
		else
		{
			printf("�U   %d", map[2][j]);
		}
		int q = 10;
		int sec = 0;
		while ((map[2][j] / q) > 0)
		{
			q = q * 10;
			sec++;
		}
		for (int io = 0; io < 3 - sec; io++)
			printf(" ");
	}
	printf("�U\n");
	printf("\t�U       �U       �U       �U       �U\n");
	printf("\t�d�T�T�T�T�T�T�T�p�T�T�T�T�T�T�T�p�T�T�T�T�T�T�T�p�T�T�T�T�T�T�T�g\n");
	printf("\t�U       �U       �U       �U       �U\n");
	printf("\t");
	for (int j = 0; j < 4; j++)
	{
		if (map[3][j] == 0)
		{
			printf("�U    ", map[3][j]);
		}
		else
		{
			printf("�U   %d", map[3][j]);
		}

		int q = 10;
		int sec = 0;
		while ((map[3][j] / q) > 0)
		{
			q = q * 10;
			sec++;
		}
		for (int io = 0; io < 3 - sec; io++)
			printf(" ");
	}
	printf("�U\n");

	printf("\t�U       �U       �U       �U       �U\n");
	printf("\t�^�T�T�T�T�T�T�T�m�T�T�T�T�T�T�T�m�T�T�T�T�T�T�T�m�T�T�T�T�T�T�T�a\n");
	printf("\n\n\t SCORE  %d\n", score);
}
void Printinfo()
{
	printf("\n\n\n\n\t ���߳�ѧ��Ʒ������ṹ�ϻ��ң�����ο��� \n");
	printf("\n\n\n\n\t ����ʱ�䣺 2019-7-23 \n");
	printf("\t �����£� 2023-8-15\n");
}
void Printuse()
{
	printf("\n\n\n\n\t 1.ʹ�ü���wsad�����������ҡ� \n");
	printf("\n\n\n\n\t 2.��ͬ������ײʱ������ӡ� \n");
	printf("\n\n\n\n\t 3.ÿ�λ���ʱ���ڿհ���������µ�����2��4�� \n");
	printf("\n\n\n\n\t 4.��������2048��ʤ�����޷��ƶ�ʱ���䡣 \n");
}
// ���������߼�
void up()
{
	int color[4][4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			color[i][j] = 0;

	for (int j = 0; j < 4; j++)
	{
		for (int i = 1; i < 4; i++)
		{
			if (map[i][j] != 0)
			{
				if (map[i - 1][j] == 0)
				{
					int x = i - 1;
					while (map[x][j] == 0 && x >= 0)
						x--;
					swap(&map[i][j], &map[x + 1][j]);
					i = x + 1;
					move = TRUE;
				}

				if (map[i][j] == map[i - 1][j] && color[i - 1][j] == 0)
				{
					map[i][j] = 0;
					map[i - 1][j] *= 2;
					color[i - 1][j] = 1;
					score += 10;
					move = TRUE;
				}
			}
		}
	}
}

void down()
{
	int color[4][4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			color[i][j] = 0;

	for (int j = 0; j < 4; j++)
	{
		for (int i = 2; i >= 0; i--)
		{
			if (map[i][j] != 0)
			{
				if (map[i + 1][j] == 0)
				{
					int x = i + 1;
					while (map[x][j] == 0 && x < 4)
						x++;
					swap(&map[i][j], &map[x - 1][j]);
					i = x - 1;
					if (i == 3)
						i--;
					move = TRUE;
				}

				if (map[i][j] == map[i + 1][j] && color[i + 1][j] == 0)
				{
					map[i][j] = 0;
					map[i + 1][j] *= 2;
					color[i + 1][j] = 1;
					score += 10;
					move = TRUE;
				}
			}
		}
	}
}
void left()
{
	int color[4][4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			color[i][j] = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			if (map[i][j] != 0)
			{
				if (map[i][j - 1] == 0)
				{
					int x = j - 1;
					while (map[i][x] == 0 && x >= 0)
						x--;
					swap(&map[i][j], &map[i][x + 1]);
					j = x + 1;
					move = TRUE;
				}

				if (map[i][j] == map[i][j - 1] && color[i][j - 1] == 0)
				{
					map[i][j] = 0;
					map[i][j - 1] *= 2;
					color[i][j - 1] = 1;
					score += 10;
					move = TRUE;
				}
			}
		}
	}
}
void right()
{
	int color[4][4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			color[i][j] = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 2; j >= 0; j--)
		{
			if (map[i][j] != 0)
			{
				if (map[i][j + 1] == 0)
				{
					int x = j + 1;
					while (map[i][x] == 0 && x < 4)
						x++;
					swap(&map[i][j], &map[i][x - 1]);
					j = x - 1;
					if (j == 3)
						j--;
					move = TRUE;
				}

				if (map[i][j] == map[i][j + 1] && color[i][j + 1] == 0)
				{
					map[i][j] = 0;
					map[i][j + 1] *= 2;
					color[i][j + 1] = 1;
					score += 10;
					move = TRUE;
				}
			}
		}
	}
}
