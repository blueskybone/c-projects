#pragma once

#include <stdio.h>
#include <windows.h>

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
	printf("\t\t\t\t║  /_/   /_____/_/  |_/_/_____/_/ |_|     2.0  Ver║\n");
	printf("\t\t\t\t║                                                 ║\n");
	printf("\t\t\t\t╚═════════════════════════════════════════════════╝\n\n\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("\t\t\t\t    1.进入播放\t\t\t2.使用说明\n\n");
	printf("\t\t\t\t    3.程序说明\t\t\t0.退出程序\n\n");

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
	printf("\t\t 1.曲库默认路径为  D:\\music\\ \n\t\t  PATH宏定义在function.h开头\n\n");
	printf("\t\t 2.播放内核已改为BASS,播放时将bass.dll文件与exe文件置于同路径下。\n\n");
	printf("\t\t 3.mp3文件名不宜超过200个字符，可能卡死。\n\n\n");

	printf("\t\t\t\t\t\t\t\t\t\t创建时间：2020.7.22\n");
	printf("\t\t\t\t\t\t\t\t\t\t最后更新：2023.8.19\n\n");
	system("pause");
}

void info()
{
	system("CLS");
	printf("\n\n");
	printf("\t\t    源代码：https://github.com/blueskybone/c-projects/tree/master/MusicPlayer\n");
	printf("\t\t    作者初学作品，代码结构较混乱，请酌情参考。\n\n");
	system("pause");
}