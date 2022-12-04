#include <stdio.h> 
#include<time.h>
#include<stdlib.h>
#include <windows.h> 
#include <conio.h>
/*变量声明*/ 
int map [4][4];                  //地图
int color [4][4];                //标记，在逻辑块用
int Score;                       //分數 
int count;                       //判定GAMEOVER的循环数
int Print ();                    //打印界面
void Sdir ();                    //生成随机数
void Judgeend ();                 
void Judgezero ();
int T,x1,y1,judgeend,judgezero;
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
		
	srand((int) time(0));      //生成随机种子 
  // 初始化界面为0，生成两个随机数
	for(int i = 0; i < 4; i++)
	for(int j = 0; j < 4; j++)
	{
		map[i][j]=0,color[i][j]=0;
	} 
	Sdir ();
	Sdir ();
  
  // 游戏主循环结构
	do 
	{ 
		  Print ();
		  T=0;
		  do{input=_getch();}
    	while(input!='W' && input!='S' && input!='A' && input!= 'D');
	    switch ( input )
	    {
			  case 'W': up () ; break;
			  case 'S': down() ;break;
			  case 'A': left() ;break;
			  case 'D': right() ;break;
     	} 
    
     	if(T!=0)// T不为0说明为有效移动
		 {
		 	  for(int i = 0; i < 4; i++)   // 判定2048存在 
	 		  for(int j = 0; j < 4 ; j++)
	 	    {
		 	    if(map[i][j] == 2048 ) // 存在2048，游戏结束
		 	    {
	        	printf("\t\t\t\t\t YOU WIN! \n");Sleep(1000);break; 
		 	    }
	    	}
	 	    Sdir();
		 }
     	else	//无效移动
     	{
        // 判定场内是否有0
     		Judgezero();
     		if(judgezero==0)
     		{   
	        	printf("\t\t\t[ERROR]无效移动！\n"); 
				    Sleep(1000);    
		  	}
			  else // 场内没有0，再次判定场内存在相同数字相邻
			  {
				  Judgeend();
				  if(judgeend!=0)
            {
					    printf("\t\t\t[ERROR]无效移动！\n"); 
					    Sleep(1000);    
				    } 
				  else// 场内没有0，也没有相同数字相邻，判输
				    {
					   //判输 
			    	  printf("\t\t\t\t\t YOU LOST!\n");Sleep(1000);              
		 	    	  break;
				    }
			  }
		}                   
	}
	while(1); 
    //结束 
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
// 判定场内是否还有0 
 void Judgezero()
 {      
 		count=0;
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
// 判定场内是否有相同元素相邻（未输局） 
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
 
////////////////////////////////////打印游戏界面
int Print()
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

//////////////////////上下左右逻辑////////////////// 
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