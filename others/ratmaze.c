//rat maze problem my solution
#include<stdio.h>
#define R 6
#define C 6



int ratmaze(int maze[R][C],int row,int col)
{
	int i,j;
	printf("%d-%d\n",row,col);
	if(row==R-1 && col==C-1 && maze[row][col]==1)
	return 1;
	if(maze[row][col]==0)
	return 0;
	
	if(maze[row][col]==1)
	{
		if(row<=R-1 && col+1<=C-1)
		{
		
		if(ratmaze(maze,row,col+1))
		{
		printf("move to (%d,%d)\n",row,col+1);
		return 1;
	   }
		
		
		else
		maze[row][col+1]=0;
	   }
	   
	   if(row+1<=R-1 && col<=C-1)
		{
		
		if(ratmaze(maze,row+1,col))
		{
		printf("move to (%d,%d)\n",row+1,col);
		return 1;
	    }
		else
		maze[row+1][col]=0;
	  }
	}
}

void solvemaze(int maze[R][C],int row,int col)
{
	if(maze[0][0]==0 || maze[row-1][col-1]==0)
	{
		printf("solution doesnot exists");
		return;
	}
	
	else
	{
		if(ratmaze(maze,0,0))
		return;
		else
		{
		printf("solution doesnot exists");
		return;
	    }
		
	}
}

int main()
{
	int maze[R][C]={{1,0,0,0,0,0},{1,1,0,0,0,0},{0,1,1,0,0,0},{0,1,1,0,0,0},{0,0,1,1,1,1},{0,0,1,1,0,1}};
	solvemaze(maze,R,C);
}
