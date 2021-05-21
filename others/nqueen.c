#include<stdio.h>

#define n 16

//n queen problem


void printsolution(int board[n][n])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		printf("%d\t",board[i][j]);
		printf("\n");
	}
	
}


int issafe(int board[n][n],int row,int col)
{
	int i,j;
	
	for(i=0;i<col;i++)
	if(board[row][i])
	return 0;
	
	for(i=row,j=col;i>=0 && j>=0;i--,j--)
	if(board[i][j])
       return 0;
   for(i=row,j=col;i<n && j>=0;i++,j--)
	if(board[i][j])
       return 0;  


return 1;	   	
}

int solveNQutil(int board[n][n],int col)
{
	int row,i;
	if(col>=n)
	return 1;
	 
	 for(i=0;i<n;i++)
	 
	 {
	 	if(issafe(board,i,col)){
		 
	 	board[i][col]=1;
	 	
	 	if(solveNQutil(board,col+1))
	 	return 1;
	 	
	 	board[i][col]=0;
	 	
	    }
   }
	 return 0;
}


void solveNQ()
{
	int i,j,board[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		board[i][j]=0;
	}
	
	if(!solveNQutil(board,0))
	printf("solution doesnot exist\n");
	
	printsolution(board);
}


int main()
{
	
	solveNQ();
	return 0;
}
