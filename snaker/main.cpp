#include <graphics.h>
#include <conio.h>
#include <vector>
#include <iostream>
#include <objidl.h>
#include <time.h>
using namespace std;
//蛇
struct Snake
{
	int x;				//坐标x（左上角）
	int y;				//坐标y（左上角）
	int state;			//方向
};
vector <Snake> snake;//使用vector构造蛇

					 //食物
struct Food
{
	int x;				//坐标x（左上角）
	int y;				//坐标y（左上角）
	void drawfood()		//画出食物
	{
		setfillcolor(COLORREF RGB(255, 33, 1));
		solidrectangle(x + 1, y + 1, x + 9, y + 9);
	}
}food;

int speed = 150;		//蛇的速度
int score;			//得分

					//函数声明
void Face();				//封面
void Des();					//说明
void Infor();				//备注
void End(int mega);			//封底

void InitialGame();			//初始化
void CreatMap();			//初始化地图
void CreatSnake();			//初始化蛇
void DrawSnake(int mega);	//蛇的绘制
void MoveSnake();			//蛇的移动
void KeyCom();				//键盘交互
void Score();				//显示分数
void Tips1();				//显示提示（游戏中）
void Tips2();				//显示提示（撞墙后）
int EatFood();				//判定吃食物
int WallHit();				//判定撞墙
int BodyHit();				//判定自撞
void InsertSnake();			//增加蛇节数
void NewFood();				//生成食物
void Speed();				//改变速度



int main()
{

	initgraph(800, 600);

	
	while (1)
	{
		Face();
		char input;
		while (input = _getch())
		{
			if (input == '1' || input == '2' || input == '3' || input == '4')
				break;
		}
		switch (input) 
		{
			case '1': break;
			case '2':Des(); continue; break;
			case '3':Infor(); continue; break;
			case '4': exit(0); break;
		}
		while (1)
		{
			InitialGame();
			int mega = rand() % 10;
			bool reborn = true;
			while (1)				//核心
			{
				DrawSnake(mega);
				MoveSnake();
				food.drawfood();
				if (BodyHit() || WallHit())		//判定撞墙||撞自己
				{
					Tips2();					//显示提示
					char regame = _getch();		//选择重生
					reborn = (regame == 'y');
					break;
				}
				if (EatFood())					//判定吃食物
				{
					InsertSnake();
					NewFood();
					food.drawfood();
					score += 10;
					Score();
					Speed();
				}
				Sleep(speed);					//控制速度
			}
			if (!reborn) 
			{
				End(mega);							//封底
				closegraph();
				break;
			}
		}

		break;
	}
	return 0;

}
//主界面
void Face()
{
	IMAGE ima;
	loadimage(&ima, ".\\pic\\theme.jpg");
	putimage(0, 0, &ima);
	char topic[] = "GLUTTONOUS SNAKE";
	char choice[4][50] = { "1.PLAY", "2.DESCRIPTION" ,"3.INFOR","4.EXIT" };
	setbkmode(0);
	settextstyle(80, 0, "Showcard Gothic");
	settextcolor(COLORREF RGB(88, 195, 142));
	outtextxy(100, 190, topic);

	settextstyle(30, 0, "Comic Sans MS");
	settextcolor(YELLOW);//COLORREF RGB(163, 254, 255)

	outtextxy(220, 300, choice[0]);
	outtextxy(390, 300, choice[1]);
	outtextxy(220, 360, choice[2]);
	outtextxy(390, 360, choice[3]);

}
//说明
void Des()
{
	cleardevice();

	IMAGE ima;
	loadimage(&ima, ".\\pic\\Groudon.jpg");
	putimage(0, 0, &ima);
	char descrip[5][100] = { "1.Use up, down, left, right to control Rayquaza's direction of travel.","2.Rayquaza's body grows each time it is fed.","3.When Rayquaza hits the wall or its own body, the game ends.","4.After reaching 200 scores he will evolve, 30% into Shiny Rayquaza.","(any key to return)" };
	settextstyle(25, 0, "Comic Sans MS");
	settextcolor(COLORREF RGB(255, 255, 255));

	outtextxy(50, 80, descrip[0]);
	outtextxy(50, 120, descrip[1]);
	outtextxy(50, 160, descrip[2]);
	outtextxy(50, 200, descrip[3]);
	outtextxy(250, 300, descrip[4]);

	_getch();
	cleardevice();

}
//备注板
void Infor()
{
	cleardevice();
	IMAGE ima;
	loadimage(&ima, ".\\pic\\Kyogre.jpg");
	putimage(0, 0, &ima);
	char infor[5][200] = { "素材来源于网络","程序使用图形库EasyX开发，官网：easyx.cn","VS编译报错：outtextxy未定义标识符。解决：项目->project属性->高级->字符集改为使用多字节字符集","2020.9.23", };

	settextstyle(20, 0, "微软雅黑");
	settextcolor(COLORREF RGB(255, 255, 255));

	outtextxy(50, 80, infor[0]);
	outtextxy(50, 120, infor[1]);
	outtextxy(50, 140, infor[2]);
	outtextxy(400, 450, infor[3]);

	_getch();
	cleardevice();
}
//画地图
void CreatMap()
{
	IMAGE ima;
	loadimage(&ima, ".\\pic\\Rayquaza.jpg");
	putimage(0, 0, &ima);
}

//初始化游戏
void InitialGame()
{
	cleardevice();
	CreatMap();
	CreatSnake();
	NewFood();
	Tips1();
	score = 0;
	Score();
	srand((unsigned int)time(NULL));
}
//初始化蛇
void CreatSnake()
{
	vector<Snake>().swap(snake);//清空vector
	for (int i = 0; i < 4; i++)
	{
		Snake tmp;
		tmp.x = 170 - i * 10;
		tmp.y = 130;
		tmp.state = 4;
		snake.push_back(tmp);
	}
}
//蛇的移动
void MoveSnake()
{

	for (int i = snake.size() - 1; i > 0; i--)
	{
		snake[i] = snake[i - 1];
	}

	switch (snake[0].state)
	{
	case 1:snake.front().y -= 10; break;
	case 2:snake.front().y += 10; break;
	case 3:snake.front().x -= 10; break;
	case 4:snake.front().x += 10; break;
	default:outtextxy(100, 80, "ERROR!!"); break;
	}

	while (_kbhit())			//检测键盘输入
	{
		KeyCom();
	}
}
//判定撞墙
int WallHit()
{
	if (snake.front().x > 570 || snake.front().x < 30 || snake.front().y>520 || snake.front().y < 70)
	{
		return 1;
	}
	return 0;
}
//判定自撞
int BodyHit()
{
	for (int i = 1; i < snake.size() - 1; i++)
	{
		if (snake.front().x == snake[i].x && snake.front().y == snake[i].y)
			return 1;
	}
	return 0;
}
//判定吃食物
int EatFood()
{
	if (snake.front().x == food.x && snake.front().y == food.y)
		return 1;
	else return 0;
}
//蛇的绘制
void DrawSnake(int mega)
{

	//每次只绘制头部与尾部两个方块，无需每次清屏后绘制背景和整条蛇，避免闪烁
	{
		if (score < 200)				//分数<200->烈空坐
		{
			setlinecolor(COLORREF RGB(254, 226, 129));
			setfillcolor(COLORREF RGB(88, 195, 142));
		}
		else 					//分数>=200->原始烈空坐
		{

			if (mega <= 2)		//随机数<=2->闪光烈空坐
			{
				setlinecolor(COLORREF RGB(255, 1, 43));
				setfillcolor(COLORREF RGB(27, 24, 27));
			}
			else
			{
				setlinecolor(COLORREF RGB(236, 136, 107));
				setfillcolor(COLORREF RGB(102, 173, 146));
			}
		}
		fillrectangle(snake[0].x, snake[0].y, snake[0].x + 10, snake[0].y + 10);
	}
	IMAGE ima;
	loadimage(&ima, ".\\pic\\Rayquaza.jpg");
	putimage(snake.back().x, snake.back().y, 11, 11, &ima, snake.back().x, snake.back().y);
	//尾部覆盖使用背景的一部分，实现两个图层的效果

}
//蛇的增长
void InsertSnake()
{
	Snake tmp;
	switch (snake.back().state)
	{
	case 1: tmp = snake.back(); tmp.y += 10; break;
	case 2:tmp = snake.back(); tmp.y -= 10; break;
	case 3:tmp = snake.back(); tmp.x += 10; break;
	case 4:tmp = snake.back(); tmp.x -= 10; break;
	default:break;
	}
	snake.push_back(tmp);
}
//键盘交互
void KeyCom()
{

	char sta[4];
	int key = _getch();
	switch (key)
	{
	case 72:if (snake.front().state != 2) snake.front().state = 1; break;	//上
	case 80:if (snake.front().state != 1)snake.front().state = 2; break;	//下
	case 75:if (snake.front().state != 4)snake.front().state = 3; break;	//左
	case 77:if (snake.front().state != 3)snake.front().state = 4; break;	//右
	case 112:system("pause"); break;			//p
	}
}
//显示分数
void Score()
{
	IMAGE img;
	loadimage(&img, ".\\pic\\score.jpg");
	putimage(610, 70, &img);
	char scores[10];
	sprintf_s(scores, "%d", score);
	settextstyle(35, 0, "Comic Sans MS");
	settextcolor(YELLOW);
	outtextxy(620, 80, "SCORE:");
	outtextxy(620, 120, scores);

}
//生成食物
void NewFood()
{
	int x, y;
	while (1)
	{
		int flag = 0;
		x = rand() % 57;
		y = rand() % 52;
		if (x < 3 || y < 7)continue;

		for (int i = 0; i < snake.size() - 1; i++)
			if (x == snake[i].x / 10 && y == snake[i].y / 10)
			{
				flag = 1;
				break;
			}
		if (flag == 0)break;
	}

	food.x = x * 10; food.y = y * 10;
}

//控制速度
void Speed()
{
	if (score <= 50)
		speed = 150;
	else if (score <= 100)
		speed = 130;
	else if (score <= 150)
		speed = 100;
	else if (score <= 200)
		speed = 80;
	else if (score <= 250)
		speed = 60;
}
//显示提示1
void Tips1()
{
	IMAGE img;
	loadimage(&img, ".\\pic\\tips.jpg");
	putimage(610, 200, &img);
	char tips[7][30] = { "press the Arrow ","keys to control ","Rayquaza","press"," 'p' ","to pause","any key to resume" };
	settextstyle(25, 0, "Comic Sans MS");
	settextcolor(YELLOW);
	outtextxy(615, 210, tips[0]);
	outtextxy(615, 240, tips[1]);
	settextcolor(COLORREF RGB(1, 255, 35));
	outtextxy(615, 270, tips[2]);
	settextcolor(YELLOW);
	outtextxy(615, 320, tips[3]);
	settextcolor(COLORREF RGB(252, 49, 83));
	outtextxy(660, 320, tips[4]);
	settextcolor(YELLOW);
	outtextxy(690, 320, tips[5]);
	outtextxy(615, 350, tips[6]);
}
//显示提示2
void Tips2()
{
	IMAGE img;
	loadimage(&img, ".\\pic\\tips.jpg");
	putimage(610, 200, &img);
	char tips[8][40] = { "Rayquaza"," fell","from the sky.","press"," 'y' ","to re-","spawn","any key to exit" };
	settextstyle(25, 0, "Comic Sans MS");
	settextcolor(COLORREF RGB(1, 255, 35));
	outtextxy(615, 210, tips[0]);
	settextcolor(YELLOW);
	outtextxy(694, 210, tips[1]);
	outtextxy(615, 240, tips[2]);
	outtextxy(615, 290, tips[3]);
	settextcolor(COLORREF RGB(252, 49, 83));
	outtextxy(660, 290, tips[4]);
	settextcolor(YELLOW);
	outtextxy(690, 290, tips[5]);
	outtextxy(615, 320, tips[6]);
	outtextxy(615, 350, tips[7]);
}
//结束画面
void End(int mega)
{
	cleardevice();
	IMAGE img;
	if (score < 200)
	{
		loadimage(&img, ".\\pic\\end1.jpg");
		settextcolor(COLORREF RGB(88, 195, 142));
	}
	else if (mega > 2)
	{
		loadimage(&img, ".\\pic\\end2.jpg");
		settextcolor(COLORREF RGB(88, 195, 142));
	}
	else
	{
		loadimage(&img, ".\\pic\\end3.jpg");
		settextcolor(RED);
	}
	putimage(250, 200, &img);
	char end[2][10] = { "THE", "END" };
	setbkmode(0);
	settextstyle(80, 0, "Showcard Gothic");
	outtextxy(240, 100, end[0]);
	Sleep(1000);
	outtextxy(400, 100, end[1]);
	Sleep(3000);
}
