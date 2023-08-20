#pragma once

#include<stdio.h>
#include<conio.h>
#include<io.h>
#include<windows.h>
#include<string.h>
//#include <mmsystem.h>

#include "bass.h"

#pragma comment(lib, "bass.lib")
#define PATH "D:\\music\\" //media storage path
#define LENGTH_MAX 200
#pragma warning(disable : 4996)

int K = 0;		//check status 'pause' or 'playing'
//extern char ch1;

HSTREAM music_stream;
int volume = 100;

void InitBASS();
struct media*Choose_Song(struct media* HEAD, struct media* P);
void Pause_Play(struct media* p);
void Close_Play(struct media* p);
int Print_List(struct media* head);
struct media* CreatHead();
void SongPlaying(struct media* p);
void VolUp(struct media* p);
void VolDown(struct media* p);
struct media* Next_Play(struct media* p);
struct media* Last_Play(struct media* head, struct media* p);
void setVolume(int m_volume);

struct media            
{
	int num;
	char name[LENGTH_MAX];
	struct media* next;
};

void InitBASS()
{
	
	BASS_SetConfig(BASS_CONFIG_DEV_DEFAULT, 1);
	//初始化BASS音频库
	BASS_Init(
		-1,//默认设备
		44100,//输出采样率44100
		BASS_DEVICE_CPSPEAKERS,
		NULL,
		NULL
	);
}

struct media* CreatHead()
{
	struct media* head, *p, *q;
	head = (struct media*)malloc(sizeof(struct media));
	long Handle;
	struct _finddata_t FileInfo;
	
	char folder[50];
	sprintf(folder, "%s%s", PATH, "*.mp3");
	if ((Handle = _findfirst(folder, &FileInfo)) == -1L)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | COMMON_LVB_UNDERSCORE);
		printf("\n\t没有找到匹配的项目\n\t请将.mp3文件放入同路径music文件夹中,重新选曲播放\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
			FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		system("pause");
		head = NULL;
		return head;
	}
	else
	{
		int i = 1;
		p = (struct media*)malloc(sizeof(struct media));
		q = head;
		p->num = i;
		strcpy(p->name, FileInfo.name);
		q->next = p;
		q = p;

		while (_findnext(Handle, &FileInfo) == 0)
		{
			i++;
			p = (struct media*)malloc(sizeof(struct media));
			p->num = i; strcpy(p->name, FileInfo.name);
			q->next = p;
			q = p;
		}
		p->next = NULL;
		_findclose(Handle);
	}
	return head;
}

//print all filename of '.mp3'，return count of files
int Print_List(struct media* head)
{
	system("CLS");
	struct media* p1;
	p1 = head->next;
	int i = 0;
	printf("\t  ╔══════════════════════════════════════════════════════\n");
	while (p1 != NULL)
	{
		printf("\t  ║   %d. %s\n", p1->num, p1->name);
		p1 = p1->next;
		i++;
	}
	return i;
}
//print playing song's name
void SongPlaying(struct media *p)
{
	if (p == NULL)return;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("\n\t\t\t\t当前播放: %s \n", p->name);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

struct media* Choose_Song(struct media* HEAD, struct media *P)
{
	if (HEAD == NULL)//文件夹为空，头指针设为空
		return HEAD;
	else
	{
		int max = Print_List(HEAD);
		int num = -1;
		struct media* p;//返回该工作指针
		p = HEAD->next;
		do
		{
			printf("\n\t请输入歌曲序号: ");

			scanf("%d", &num);
			while (getchar() != '\n')continue;//清除缓冲区，如果用户输入字符将会死循环
			if (!(num > 0 && num <= max))
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED );
				printf("\t请输入歌曲对应序号1~ %d !\n", max);
				fflush(stdin);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
					FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
		} while (!(num > 0 && num <= max));//得到合法的序号

		while (p->num != num)p = p->next;
		printf("\n\t\t即将播放:%s\n", p->name);
		Sleep(250);

		if (P != NULL)Close_Play(P);
		Pause_Play(p);
		return p;
	}

}

void Close_Play(struct media* p)//close file
{

	if (p == NULL)
	{
		//if (ch1 != 'q')//进播放器不做操作退出时，删掉这个判断会误显示下面提示
		{
			printf("\n\t\t\t当前无正在播放歌曲,请选曲播放\n");
			Sleep(500);
		}
		return;
	}

	BASS_ChannelStop(music_stream);
	BASS_StreamFree(music_stream);
	music_stream = NULL;
	//	char cmd[100];
	//char pathname[100];
	//sprintf(pathname, "%s%s", PATH, p->name);
	//GetShortPathName(pathname, pathname, 50);
	// sprintf(cmd, "close %s", pathname);
	// mciSendString(cmd, NULL, 0, NULL);
	K = 0;//change status to 'pause'
}

void Pause_Play(struct media* p)//pause_play switcher
{
	//char cmd[100];
	if (p == NULL)
	{
		printf("\n\t\t\t当前无正在播放歌曲,请选曲播放\n");
		Sleep(500);
		return;
	}
	if (music_stream == NULL)
	{
		TCHAR file[MAX_PATH] = { 0 };
		sprintf(file, "%s%s", PATH, p->name);
		GetShortPathName(file, file, 50);
		music_stream = BASS_StreamCreateFile(FALSE, file, 0, 0, 0);
		setVolume(volume);
	}
	if (K == 1)//status == 'playing'
	{
		if(!BASS_ChannelPause(music_stream));
		// char pathname[100];
		// sprintf(pathname, "%s%s", PATH, p->name);
		// GetShortPathName(pathname, pathname, 50);
		// sprintf(cmd, "pause %s", pathname);
		// mciSendString(cmd, NULL, 0, NULL);
		K = 0;
	}
	else if (K == 0)//status == 'pause' or 'stop'
	{

		if(!BASS_ChannelPlay(music_stream,FALSE));
		// char pathname[100];
		// sprintf(pathname, "%s%s", PATH, p->name);
		// GetShortPathName(pathname, pathname, 50);
		// sprintf(cmd, "open %s", pathname);
		// mciSendString(cmd, NULL, 0, NULL);
		// sprintf(cmd, "play %s repeat", pathname);
		// mciSendString(cmd, NULL, 0, NULL);
		K = 1;
	}
}

struct media* Last_Play(struct media* head, struct media* p)
{
	if (p == NULL)
	{
		printf("\n\t\t\t当前无歌曲正在播放,请选曲播放\n");
		Sleep(500);
		return p;
	}
	int n;
	n = p->num;
	n--;
	if (n != 0)
	{
		//close playing file, point previous one, play it.
		Close_Play(p);
		p = head->next;
		while (p != NULL && p->num != n)p = p->next;
		Pause_Play(p);
	}
	else
	{
		printf("\n\t\t\t当前是第一首\n");
		Sleep(500);
	}
	return p;
}
struct media* Next_Play(struct media *p)
{

	if (p == NULL)
	{
		printf("\n\t\t\t当前无歌曲正在播放,请选曲播放\n");
		Sleep(500);
		return p;
	}
	if (p->next != NULL)
	{
		//close playing file, point previous one, play it.
		Close_Play(p);
		p = p->next;
		Pause_Play(p);
	}
	else
	{
		printf("\n\t\t\t当前是最后一首\n");
		Sleep(500);
	}
	return p;
}


void setVolume(int m_volume)
{
	float bVolume = (float)m_volume / 100.0f;
	BASS_ChannelSetAttribute(music_stream, BASS_ATTRIB_VOL, bVolume);
}
void Vol_Down(struct media *p)
{
	if (p == NULL)
	{
		printf("\n\t\t\t当前无歌曲正在播放,请选曲播放\n");
		Sleep(500);
		return;
	}

	if (volume > 0)
		volume  = volume - 5;
	setVolume(volume);

	//TCHAR cmd[256]; 
	//TCHAR volume[256];
	//int nVolume; 

	// float volume = static_cast<float>(m_volume) / 100.0f;
	// BASS_ChannelSetAttribute(music_stream, BASS_ATTRIB_VOL, volume);

	// char pathname[100];
	// sprintf(pathname, "%s%s", PATH, p->name);
	// GetShortPathName(pathname, pathname, 50);
	// sprintf(cmd, "status %s volume", pathname); //pathname2为音乐的路径
	// mciSendString(cmd, volume, sizeof(volume), 0); // 获取当前音量至 volume 字符串中

	//nVolume = atoi(volume); // 字符串转化为整型

	// sprintf(cmd, "setaudio %s volume to %i", pathname, nVolume - 50); // 生成媒体命令，设置音量减 50
	// mciSendString(cmd, NULL, 0, NULL); // 执行媒体命令
}

void Vol_Up(struct media* p)
{
	if (p == NULL)
	{
		printf("\n\t\t\t当前无歌曲正在播放,请选曲播放\n");
		Sleep(500);
		return;
	}
	
	if (volume < 100)
		volume += 5;
	setVolume(volume);

	// TCHAR cmd[256]; // 媒体命令
	// TCHAR volume[256]; // 音量(字符串)
	// int nVolume; // 音量(整型)
	// char pathname[100];
	// sprintf(pathname, "%s%s", PATH, p->name);
	// GetShortPathName(pathname, pathname, 50);
	// sprintf(cmd, "status %s volume", pathname); //pathname2为音乐的路径
	// mciSendString(cmd, volume, sizeof(volume), 0); // 获取当前音量至 volume 字符串中

	//nVolume = atoi(volume); // 字符串转化为整型

	// sprintf(cmd, "setaudio %s volume to %i", pathname, nVolume + 50); // 生成媒体命令，设置音量加 50
	// mciSendString(cmd, NULL, 0, NULL); // 执行媒体命令
}
