
#include <stdio.h> 
#include<time.h>
#include<stdlib.h>
#include <windows.h> 
#include <conio.h>

#define MAX_NUMBER 2048

/*变量声明*/ 
int map [4][4];                  //地图
int color [4][4];                //标记，在逻辑块用
int Score;                       //分數 
int count;                       //判定GAMEOVER的循环数
int Print ();                    //打印界面
void Sdir ();                    //生成随机数
void Printcover ();               //生成封面 
void Judgeend ();                 
void Judgezero ();
void Printinfo ();
void Printuse ();
int T,x1,y1,judgeend,judgezero;
int Topscore=16;
char input;


//键盘交互
void up ();
void down ();
void left ();
void right ();

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
 } 

int main(){
	//封面
	back2:
	system("cls");
	Printcover();
	back1:
	char input=_getch();
	if(input!='1'&&input!='2'&&input!='3'&&input!='4')goto back1;
	else
	{
		switch(input)
		{
			case '1':break;
			case '2':
			{
				system("cls");
				Printuse();
				getch();
				system("cls");
				goto back2;
				break;
			}
				
			case '3':
				{
					system("cls");
					Printinfo();
					getch();
					system("cls");
				    goto back2;
				    break;
			    }
			case '4':goto stop;break;
		}
		
	}
	
	system("cls"); 
		
	srand((int)time(0));      //生成随机种子 
	for(int i = 0; i < 4; i++)
	for(int j = 0; j < 4; j++)
	{
		map[i][j]=0,color[i][j]=0;
	} 
	Sdir ();
	Sdir ();                  //初始化
	 
	do 
	{ 
	system("cls");         
	Print ();
	T=0;
	back:                   //无效移动/输入错误
    char input=_getch();
    if(input!='W' && input!='S' && input!='A' && input!= 'D'&&input!='w' && input!='s' && input!='a' && input!= 'd')
   {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		printf("\t\t\t[WARNING]使用WSAD移动\n"); 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);
		goto back;
}
else
{
	    switch ( input )
	    {
		case 'W': up () ; break;
		case 'w': up () ; break;
		case 'S': down() ;break;
		case 's': down() ;break;
		case 'A': left() ;break;
		case 'a': left() ;break;
		case 'D': right() ;break;
		case 'd': right() ;break;
		default: break; 
     	} 
     	
     	if(T!=0)Sdir();////////有效移动，结束判断框，进入end judge 
     	else
     	{
     		Judgezero();
     		if(judgezero==0)
     		{   backto:
     			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	        	printf("\t\t\t[ERROR]无效移动\n"); 
	    	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		        FOREGROUND_GREEN | FOREGROUND_BLUE);
		    goto back;
			}
			else
			{
				Judgeend();
				if(judgeend!=0)goto backto;
				else
				{
			    printf("\t\t\t\t\t YOU LOST!\n");Sleep(1000);
		 	    printf("\t\t\t\t\t 是否重新开始（是 Y/ 否 N）");      
				 while(1)
			{   char input=_getch();
				if(input=='Y'||input=='y')goto back2;
		        if(input=='N'||input=='n')goto stop;
			}                   
		 	    break;                
				}
			}
		}
}

for(int i = 0; i < 4; i++)   //判断结束条件2 WIN 
	 for(int j = 0; j < 4 ; j++)
	 {
	 	if(map[i][j]==Topscore)Topscore*=2;
		 
		 if(map[i][j] == MAX_NUMBER ) /////////改数字==改上限 
		 {
		 	system("cls");
	        Print();
	        printf("\t\t\t\t\t YOU WIN! \n");Sleep(1000);
	        printf("\t\t\t\t\t 是否重新开始（是 Y/ 否 N）");
			
			while(1)
			{   char input=_getch();
				if(input=='Y'||input=='y')goto back2;
		        if(input=='N'||input=='n')goto stop;
			} 
		 }
	 }	                          
	 
	}
	while(1); 
    //结束 
    stop:
	system("cls");
	printf("\t\t\t\t\t blueskybone\n");Sleep(1000);
	printf("\n\t\t\t\t\tTHANKS FOR PLAYING\n") ;Sleep(1000);
	printf("\n\n\t\t\t\t\t按任意键结束游戏\n");getch();
	return 0;
} 


//生成数字 
void Sdir()
{   
	do {
		 x1=rand()%4,y1=rand()%4;
	}
	while(map[x1][y1]!=0);
	if(rand()%2==1)map[x1][y1]=4;
	else map[x1][y1]=2;
}
//封面
void Printcover()
{
printf("\n\n\n\n\n");
printf("\t\t\t 222222222222222         000000000            444444444       888888888     \n") ;
printf("\t\t\t2:::::::::::::::22     00:::::::::00         4::::::::4     88:::::::::88   \n") ;
printf("\t\t\t2::::::222222:::::2  00:::::::::::::00      4:::::::::4   88:::::::::::::88 \n") ;
printf("\t\t\t2222222     2:::::2 0:::::::000:::::::0    4::::44::::4  8::::::88888::::::8\n") ;
printf("\t\t\t            2:::::2 0::::::0   0::::::0   4::::4 4::::4  8:::::8     8:::::8\n") ;
printf("\t\t\t            2:::::2 0:::::0     0:::::0  4::::4  4::::4  8:::::8     8:::::8\n") ;
printf("\t\t\t         2222::::2  0:::::0     0:::::0 4::::4   4::::4   8:::::88888:::::8 \n") ;
printf("\t\t\t    22222::::::22   0:::::0 000 0:::::04::::444444::::444  8:::::::::::::8  \n") ;
printf("\t\t\t  22::::::::222     0:::::0 000 0:::::04::::::::::::::::4 8:::::88888:::::8 \n") ;
printf("\t\t\t 2:::::22222        0:::::0     0:::::04444444444:::::4448:::::8     8:::::8\n") ;
printf("\t\t\t2:::::2             0:::::0     0:::::0          4::::4  8:::::8     8:::::8\n") ;
printf("\t\t\t2:::::2             0::::::0   0::::::0          4::::4  8:::::8     8:::::8\n") ;
printf("\t\t\t2:::::2       2222220:::::::000:::::::0          4::::4  8::::::88888::::::8\n") ;
printf("\t\t\t2::::::2222222:::::2 00:::::::::::::00         44::::::44 88:::::::::::::88 \n") ;
printf("\t\t\t2::::::::::::::::::2   00:::::::::00           4::::::::4   88:::::::::88   \n") ;
printf("\t\t\t22222222222222222222     000000000             4444444444     888888888     \n\n\n\n") ;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED);
			printf("\t\t\t\t 1 开始游戏       2 游戏规则\n");
            printf("\t\t\t\t 3 程序说明       4 退出游戏\n");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

 } 
 void Judgezero()
 {      count=0;
        judgezero=0;
 		do {
		 x1=rand()%4,y1=rand()%4;count++;
		 if(count>50)
		 {  
		    judgezero=1;
		 	break;
		 }
	   }while(map[x1][y1]!=0);
 }
 
 void Judgeend()
 {
    judgeend=0;
 	for(int i=0;i<4;i++)
 	for(int j=0;j<3;j++)
 	{
 		if(map[i][j]==map[i][j+1])
 		{
 			judgeend=1;break;
		}
	}
	for(int j=0;j<4;j++)
 	for(int i=0;i<3;i++)
 	{
 		if(map[i][j]==map[i+1][j])
 		{
 			judgeend=1;break;
		}
	}
	
 }
 
//打印游戏界面
int Print()
{ 

	printf("\n\n\n\n");
	printf("\t\t\t╔═══════╦═══════╦═══════╦═══════╗\n");
    printf("\t\t\t║       ║       ║       ║       ║\n");
    printf("\t\t\t");
    for(int j=0;j<4;j++)
      {   
          if(map[0][j]==0)
          {
          	printf("║    ",map[0][j]);
		  }
		  else
		  {
		  	 printf("║   %d",map[0][j]);
		  }
          int q=10;int sec=0;
	      while((map[0][j]/q)>0)
	           { q=q*10;sec++;}
	for(int io=0;io<3-sec;io++)printf(" ");
	
}
printf("║\n");
  
    printf("\t\t\t║       ║       ║       ║       ║\n");
    printf("\t\t\t╠═══════╬═══════╬═══════╬═══════╣\n");
    printf("\t\t\t║       ║       ║       ║       ║\n");
    printf("\t\t\t");
	for(int j=0;j<4;j++)
{     
	if(map[1][j]==0)
          {
          	printf("║    ",map[1][j]);
		  }
		  else
		  {
		  	 printf("║   %d",map[1][j]);
		  }
    int q=10;int sec=0;
	while((map[1][j]/q)>0)
	{   q=q*10;
		sec++;
	}
	for(int io=0;io<3-sec;io++)printf(" ");
	
}
printf("║\n");
	
	
    printf("\t\t\t║       ║       ║       ║       ║\n");
    printf("\t\t\t╠═══════╬═══════╬═══════╬═══════╣\n");
    printf("\t\t\t║       ║       ║       ║       ║\n");
     printf("\t\t\t");
   for(int j=0;j<4;j++)
{   
 	if(map[2][j]==0)
    {
       	printf("║    ",map[2][j]);
	}
	else
	 {
		printf("║   %d",map[2][j]);
	}
    int q=10;int sec=0;
	while((map[2][j]/q)>0)
	{   q=q*10;
		sec++;
	}
	for(int io=0;io<3-sec;io++)printf(" ");
	
}
    printf("║\n");
    printf("\t\t\t║       ║       ║       ║       ║\n");
    printf("\t\t\t╠═══════╬═══════╬═══════╬═══════╣\n");
    printf("\t\t\t║       ║       ║       ║       ║\n");
     printf("\t\t\t");
   for(int j=0;j<4;j++)
{   
	if(map[3][j]==0)
    {
       	printf("║    ",map[3][j]);
	}
	else
	 {
		printf("║   %d",map[3][j]);
	}

    int q=10;int sec=0;
	while((map[3][j]/q)>0)
	{   q=q*10;
		sec++;
	}
	for(int io=0;io<3-sec;io++)printf(" ");
}
    printf("║\n");
   
    printf("\t\t\t║       ║       ║       ║       ║\n");
    printf("\t\t\t╚═══════╩═══════╩═══════╩═══════╝\n");
    printf("\n\n\t\t\t SCORE  %d\n",Score);
    printf("\n\n\t\t\t LEVEL：");
    switch(Topscore)
    {
    	case 16:{
    		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_GREEN);
    		printf("0\n");
    		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			break;
		}
		case 32:{
			printf("1\n");
			break;
		}
		case 64:{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN);
			printf("2\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			break;
		}
		case 128:{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_BLUE);
			printf("3\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			break;
		}
		case 256:{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_GREEN | FOREGROUND_BLUE);
			printf("4\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			break;
		}
		case 512:{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_BLUE);
			printf("5\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			break;
		}
		case 1024:{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_GREEN);
			printf("6\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			break;
		}
		case 2048:{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED);
			printf("MAX\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			break;
		}
	}
	
} 
void Printinfo()
{
	printf("\n本程序属于作者的初学作品，代码结构较混乱，且不当使用太多goto语句，请酌情参考。\n");
}
void Printuse()
{
	printf("\n\n\n\n\t\t\t\t 1.使用键盘wsad控制上下左右。 \n");
	printf("\n\n\n\n\t\t\t\t 2.相同数字相撞时数字会相加。 \n");
	printf("\n\n\n\n\t\t\t\t 3.每次滑动时,空白处会随机刷新一个2或4。 \n");
	printf("\n\n\n\n\t\t\t\t 4.当界面中最大数字是2048时,游戏胜利。当界面不可运动时,游戏结束; \n");
}
///////////////上下左右逻辑////////////////// 
void up()
{
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
	color[i][j]=0;
	
   for(int j=0;j<4;j++)
	{
		for(int i=1;i<4;i++)
		{
			if(map[i][j]!=0)
			{	if(map[i-1][j]==0)
				{
					int x=i-1;
					while(map[x][j]==0&&x>=0)x--;
					swap(&map[i][j],&map[x+1][j]);
					i=x+1;T++;
				}
				
				if(map[i][j]==map[i-1][j]&&color[i-1][j]==0)
				{
					map[i][j]=0;map[i-1][j]*=2;color[i-1][j]=1;Score+=10;T++;
				}
			
			}
		}
	}
}

void down()
{
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
	color[i][j]=0;
	
	for(int j=0;j<4;j++)
	{
		for(int i=2;i>=0;i--)
		{
			if(map[i][j]!=0)
			{	if(map[i+1][j]==0)
				{
					int x=i+1;
					while(map[x][j]==0&&x<4)x++;
					swap(&map[i][j],&map[x-1][j]);
					i=x-1;if(i==3)i--;
					T++;
				}
				
				if(map[i][j]==map[i+1][j]&&color[i+1][j]==0)
				{
					map[i][j]=0;map[i+1][j]*=2;color[i+1][j]=1;Score+=10;T++;
				}
			
			}
		}
	}
}
void left()

{
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
	color[i][j]=0;
	
	for(int i=0;i<4;i++)
	{
		for(int j=1;j<4;j++)
		{
			if(map[i][j]!=0)
			{	if(map[i][j-1]==0)
				{
					int x=j-1;
					while(map[i][x]==0&&x>=0)x--;
					swap(&map[i][j],&map[i][x+1]);
					j=x+1;T++;
				}
				
				if(map[i][j]==map[i][j-1]&&color[i][j-1]==0)
				{
					map[i][j]=0;map[i][j-1]*=2;color[i][j-1]=1;Score+=10;T++;
				}
			
			}
		}
	}
}
void right()
{

	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
	color[i][j]=0;
	
	for(int i=0;i<4;i++)
	{
		for(int j=2;j>=0;j--)
		{
			if(map[i][j]!=0)
			{	if(map[i][j+1]==0)
				{
					int x=j+1;
					while(map[i][x]==0&&x<4)x++;
					swap(&map[i][j],&map[i][x-1]);
					j=x-1;if(j==3)j--;T++;
				}
				
				if(map[i][j]==map[i][j+1]&&color[i][j+1]==0)
				{
					map[i][j]=0;map[i][j+1]*=2;color[i][j+1]=1;Score+=10;T++;
				}
			
			}
		}
	}
}