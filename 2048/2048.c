#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define MAX_NUMBER 2048

int map[4][4]; // 地图
int score;	   // 分數

void Sdir();   // 生成随机数
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

// 键盘交互
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
				printf("\t\t\t使用WSAD移动\n");
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
			printf("\t\t\t无效移动\n");
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
				printf("\n\n\t 是否重新开始  Y/N ");
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
				printf("\n\n\t 是否重新开始  Y/N ");
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

// 生成数字
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
// 封面
void Printcover()
{
	printf("\n\n\n\n\n");
	printf("\t\t   ___   ___   ____  ___ \n");
	printf("\t\t  |_  | / _ \\ / / / ( _ )\n");
	printf("\t\t / __/ / // //_  _// _ | \n");
	printf("\t\t/____/ \\___/  /_/  \\___/ \n\n\n\n");
	printf("\t\t 1 开始游戏       2 游戏规则\n\n");
	printf("\t\t 3 程序说明       4 退出游戏\n\n");
}
// 检查是否还有空格
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
// 打印游戏界面
void Print()
{
	printf("\n\n\n\n");
	printf("\t╔═══════╦═══════╦═══════╦═══════╗\n");
	printf("\t║       ║       ║       ║       ║\n");
	printf("\t");
	for (int j = 0; j < 4; j++)
	{
		if (map[0][j] == 0)
		{
			printf("║    ", map[0][j]);
		}
		else
		{
			printf("║   %d", map[0][j]);
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
	printf("║\n");
	printf("\t║       ║       ║       ║       ║\n");
	printf("\t╠═══════╬═══════╬═══════╬═══════╣\n");
	printf("\t║       ║       ║       ║       ║\n");
	printf("\t");
	for (int j = 0; j < 4; j++)
	{
		if (map[1][j] == 0)
		{
			printf("║    ", map[1][j]);
		}
		else
		{
			printf("║   %d", map[1][j]);
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
	printf("║\n");

	printf("\t║       ║       ║       ║       ║\n");
	printf("\t╠═══════╬═══════╬═══════╬═══════╣\n");
	printf("\t║       ║       ║       ║       ║\n");
	printf("\t");
	for (int j = 0; j < 4; j++)
	{
		if (map[2][j] == 0)
		{
			printf("║    ", map[2][j]);
		}
		else
		{
			printf("║   %d", map[2][j]);
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
	printf("║\n");
	printf("\t║       ║       ║       ║       ║\n");
	printf("\t╠═══════╬═══════╬═══════╬═══════╣\n");
	printf("\t║       ║       ║       ║       ║\n");
	printf("\t");
	for (int j = 0; j < 4; j++)
	{
		if (map[3][j] == 0)
		{
			printf("║    ", map[3][j]);
		}
		else
		{
			printf("║   %d", map[3][j]);
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
	printf("║\n");

	printf("\t║       ║       ║       ║       ║\n");
	printf("\t╚═══════╩═══════╩═══════╩═══════╝\n");
	printf("\n\n\t SCORE  %d\n", score);
}
void Printinfo()
{
	printf("\n\n\n\n\t 作者初学作品，代码结构较混乱，酌情参考。 \n");
	printf("\n\n\n\n\t 创建时间： 2019-7-23 \n");
	printf("\t 最后更新： 2023-8-15\n");
}
void Printuse()
{
	printf("\n\n\n\n\t 1.使用键盘wsad控制上下左右。 \n");
	printf("\n\n\n\n\t 2.相同数字相撞时数字相加。 \n");
	printf("\n\n\n\n\t 3.每次滑动时，在空白随机生成新的数字2或4。 \n");
	printf("\n\n\n\n\t 4.出现数字2048则胜利。无法移动时判输。 \n");
}
// 上下左右逻辑
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
