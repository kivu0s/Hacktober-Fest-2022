#include <stdio.h>

int main()
{
    int i,j,row,column;
    int count=0;
    printf("Enter the number of rows and columns in the matrix: ");
    scanf("%d%d",&row,&column);
    int board[row][column];
    puts("\nEnter the board elements...");
    for(i=0;i<=row-1;i++)
        for(j=0;j<=column-1;j++)
            scanf("%d",&board[i][j]);
    
    puts("\nBoard before updation...");
    for(i=0;i<=row-1;i++)
    {
        for(j=0;j<=column-1;j++)
            printf("%d   ",board[i][j]);
        printf("\n");
    }
    
    int matrix[row][column];
    for(i=0;i<=row-1;i++)
        for(j=0;j<=column-1;j++)
            matrix[i][j]=board[i][j];
            
    for(i=0;i<=row-1;i++)
        for(j=0;j<=column-1;j++)
        {
            count=0;
            if(matrix[i][j]==1)
            {  
			    if(i!=0)
                {
                    if(j!=0)
				        if(matrix[i-1][j-1]==1)
                            count++;
                    if(matrix[i-1][j]==1)
                        count++;
                    if(j!=column-1)
                        if(matrix[i-1][j+1]==1)
                            count++;
                }
                if(j!=0)
                    if(matrix[i][j-1]==1)
                        count++;
                if(j!=column-1)
                    if(matrix[i][j+1]==1)
                        count++;
                if(i!=row-1)
                {
				    if(j!=0)
                        if(matrix[i+1][j-1]==1)
                            count++;
                    if(matrix[i+1][j]==1)
                        count++;
                    if(j!=column-1)
                        if(matrix[i+1][j+1]==1)
                            count++;
                }
                    
                if(count<2 || count>3)
                    board[i][j]=0;
            }
            else if(matrix[i][j]==0)
            {
            	if(i!=0)
            	{
				    if(j!=0)
				        if(matrix[i-1][j-1]==1)
                            count++;
                    if(matrix[i-1][j]==1)
                        count++;
                    if(j!=column-1)
				        if(matrix[i-1][j+1]==1)
                            count++;
                }
                if(j!=0)
				    if(matrix[i][j-1]==1)
                        count++;
                if(j!=column-1)
				    if(matrix[i][j+1]==1)
                        count++;
                if(i!=row-1)
                {
				    if(j!=0)
					    if(matrix[i+1][j-1]==1)
                            count++;
                    if(matrix[i+1][j]==1)
                        count++;
                    if(j!=column-1)
                        if(matrix[i+1][j+1]==1)
                            count++;
                }
                
                if(count==3)
                    board[i][j]=1;
            }
            
        }
    puts("\nBoard after updation...");
    for(i=0;i<=row-1;i++)
    {
        for(j=0;j<=column-1;j++)
            printf("%d   ",board[i][j]);
        printf("\n");
    }

    return 0;
}