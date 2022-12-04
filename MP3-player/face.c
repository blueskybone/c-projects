#include"stdio.h"
#include"windows.h"
#include"face.h"
void Face()
{
	system("CLS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("\n\n\n");
	printf("\t\t\t\t╔═════════════════════════════════════════════════╗\n");
	printf("\t\t\t\t║         __  _______ _____                       ║\n");
	printf("\t\t\t\t║        /  |/  / __ \\__  /                       ║\n");
	printf("\t\t\t\t║       / /|_/ / /_/ //_ <                        ║\n");
	printf("\t\t\t\t║      / /  / / ____/__/ /                        ║\n");
	printf("\t\t\t\t║     /_/__/_/_/    /___/ ____________            ║\n");
	printf("\t\t\t\t║     / __ \\/ /   /   \\ \\/ / ____/ __ \\           ║\n");
	printf("\t\t\t\t║    / /_/ / /   / /| |\\  / __/ / /_/ /           ║\n");
	printf("\t\t\t\t║   / ____/ /___/ ___ |/ / /___/ __ _/            ║\n");
	printf("\t\t\t\t║  /_/   /_____/_/  |_/_/_____/_/ |_|     1.0  Ver║\n");
	printf("\t\t\t\t║                                                 ║\n");
	printf("\t\t\t\t╚═════════════════════════════════════════════════╝\n\n\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("\t\t\t\t    1.进入播放\t\t\t2.使用说明\n\n");
	printf("\t\t\t\t    3.程序说明\t\t\t0.退出程序\n\n");

}

void Menu_Player()
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
	printf("\t\t\t\t╔════════════════════════════════════════════════╗\n");
	printf("\t\t\t\t║                                                ║\n");
	printf("\t\t\t\t║ *x.选曲播放               *space.播放/暂停     ║\n");
	printf("\t\t\t\t║                                                ║\n");
	printf("\t\t\t\t║ *a.上一曲                 *d.下一曲            ║\n");
	printf("\t\t\t\t║                                                ║\n");
	printf("\t\t\t\t║ *w.音量+                  *s.音量-             ║\n");
	printf("\t\t\t\t║                                                ║\n");
	printf("\t\t\t\t║ *p.停止播放               *q.返回菜单          ║\n");
	printf("\t\t\t\t║                                                ║\n");
	printf("\t\t\t\t╚════════════════════════════════════════════════╝\n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void state()
{
	system("CLS");

	printf("\n\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("\t\t\t\t\t使用说明\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("\t\t 1.请将要播放的.mp3歌曲文件放入默认路径\" D:\\music\\ \"下\n\t\t  (若要更改路径，直接修改function.c中PATH的宏定义再编译)\n\n\n");
	printf("\t\t 2.本程序使用的播放接口为win32MCI接口，微软多年前已经停止维护，比特率超过128kbps的文件无法播放。\n\n\n");
	printf("\t\t 3.mp3文件名不宜超过200个字符，程序会卡死\n\n\n");
	printf("\t\t 4.程序运行时允许向默认文件夹加入新的.mp3文件，使用\"选曲播放\"选项更新文件列表\n\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("\t\t\t\t\t\t\t\t\t\t2020.7.22\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	system("pause");
}

void info()
{
	system("CLS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("\n\n\t\t  程序说明\n\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("\t\t  开发环境：Visual Studio 2013 / win10\n\n\n");
	printf("\t\t  1.本程序使用的接口是win32自带的MCI，超过128kbps的mp3无法播放。这个接口较适合初学者学习使用。\n\n\n");
	printf("\t\t  2.本程序是作者的初学作品，很多代码结构不规范，不建议过度学习源码。建议参考以下文章 \n");
	printf("\t\t  mciSendString()的用法 https://blog.sina.com.cn/s/blog_49f037d60100pi2f.html \n");
	printf("\t\t  清除缓冲区的几种方法 https://blog.csdn.net/konghouy/article/details/80560383 \n");
	system("pause");
}