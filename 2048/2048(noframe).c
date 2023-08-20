#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
#include <windows.h> 
#include <conio.h>

#define MAX_NUMBER 2048

int map [4][4];                  
boolean move;                           

void GameInitial();
void Print ();
void Sdir ();
boolean JudgeEnd ();                 
boolean JudgeZero ();
boolean JudgeWin ();

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
	GameInitial();
  	system("cls");
	Print ();
	do 
	{ 
		move = FALSE;	
		char input;
		do{input=_getch();}
    	while(input!='W' && input!='S' && input!='A' && input!= 'D'
		 && input!= 'w' && input!= 's' && input!= 'a' && input!= 'd');
	    switch ( input )
	    {
			case 'W':
			case 'w':
			   	up () ; break;
			case 'S':
			case 's':
			 	down() ;break;
		    case 'A':
			case 'a': 
				left() ;break;
		    case 'D':
			case 'd':
				right() ;break;
     	} 
		if(move == TRUE) 	
		{
			Sdir();
			system("cls");Print();
			if(JudgeWin()==TRUE)
			{
				printf("\n\n\t YOU WIN");Sleep(1000);
				exit(0);
			}
			if(JudgeZero()==FALSE && JudgeEnd()==FALSE)
			{
				printf("\n\n\t YOU LOSE");Sleep(1000);
				exit(0);
			}
		}
	}
	while(1); 
	return 0;
} 

// generate random number and location
void Sdir()
{   
	if(JudgeZero() == TRUE)
	{
		int x1, y1;
		do {x1=rand()%4,y1=rand()%4;}
		while(map[x1][y1]!=0);
		if(rand()%2==1)map[x1][y1]=4;
		else map[x1][y1]=2;
	}
}
void GameInitial()
{
	srand((int) time(0));     
	for(int i = 0; i < 4; i++)
	for(int j = 0; j < 4; j++)
	{
		map[i][j]=0;
	} 
	move = FALSE;
	Sdir ();
	Sdir ();
}

// check if zero
boolean JudgeZero()
 {      
	for(int i=0;i<4;i++)
 	for(int j=0;j<4;j++)
 	{
 		if(map[i][j]==0)
 		return TRUE;
	}
 	return FALSE;
 }

boolean JudgeEnd()
 {
 	for(int i=0;i<4;i++)
 	for(int j=0;j<3;j++)
 	{
 		if(map[i][j]==map[i][j+1])
 		{
 			return TRUE;
		}
	}
	for(int j=0;j<4;j++)
 	for(int i=0;i<3;i++)
 	{
 		if(map[i][j]==map[i+1][j])
 		{
 			return TRUE;
		}
	}
	return FALSE;
 }
 
 boolean JudgeWin()
 {
 	for(int j=0;j<4;j++)
 	for(int i=0;i<4;i++)
 	{
 		if(map[i][j] == MAX_NUMBER)
 		{
 			return TRUE;
		}
	}
	return FALSE;
 }
 
void Print()
{ 
	printf("\n");
    for(int j=0;j<4;j++)
      {   
	  	  printf("   %d",map[0][j]);
          int q=10;int sec=0;
	      while((map[0][j]/q)>0)
	           { 
			   q=q*10;
			   sec++;
			   }
		 for(int io=0;io<3-sec;io++)printf(" ");
	}
	printf("\n");
	printf("\n");
	for(int j=0;j<4;j++)
	{   
		printf("   %d",map[1][j]);
    	int q=10;int sec=0;
		while((map[1][j]/q)>0)
		{   
			q=q*10;
			sec++;
		}
	for(int io=0;io<3-sec;io++)printf(" ");
	}
	printf("\n");
	printf("\n");
   for(int j=0;j<4;j++)
	{   
		printf("   %d",map[2][j]);
    	int q=10;int sec=0;
		while((map[2][j]/q)>0)
		{   
			q=q*10;
			sec++;
		}
	for(int io=0;io<3-sec;io++)printf(" ");
	}
	printf("\n");
	printf("\n");
   for(int j=0;j<4;j++)
	{   printf("   %d",map[3][j]);
    	int q=10;int sec=0;
		while((map[3][j]/q)>0)
		{   
			q=q*10;
			sec++;
		}
	for(int io=0;io<3-sec;io++)printf(" ");
	}
} 

void up()
{
	int color [4][4];  
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
					i=x+1;move = TRUE;
				}
				
				if(map[i][j]==map[i-1][j]&&color[i-1][j]==0)
				{
					map[i][j]=0;map[i-1][j]*=2;color[i-1][j]=1;move = TRUE;
				}
			
			}
		}
	}
}

void down()
{
	int color [4][4];  
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
					move = TRUE;
				}
				
				if(map[i][j]==map[i+1][j]&&color[i+1][j]==0)
				{
					map[i][j]=0;map[i+1][j]*=2;color[i+1][j]=1;move = TRUE;
				}
			
			}
		}
	}
}
void left()
{
	int color [4][4];  
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
					j=x+1;move = TRUE;
				}
				
				if(map[i][j]==map[i][j-1]&&color[i][j-1]==0)
				{
					map[i][j]=0;map[i][j-1]*=2;color[i][j-1]=1;move = TRUE;
				}
			
			}
		}
	}
}
void right()
{
	int color [4][4];   
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
					j=x-1;if(j==3)j--;move = TRUE;
				}
				
				if(map[i][j]==map[i][j+1]&&color[i][j+1]==0)
				{
					map[i][j]=0;map[i][j+1]*=2;color[i][j+1]=1;move = TRUE;
				}
			
			}
		}
	}
}
