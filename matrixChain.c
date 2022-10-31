/*A program to find the minimum number of multiplications needed to multiply the matrix chain and the optimal parenthesization for the sequence of matrices*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void fill(int** array, int n, int value)
{
    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            array[i][j]=value;
}

int matrixChainOrder(int *p, int** s, int n)
{
	int i,j,k,len,cost;
    int** m=(int **)malloc((n+1)*sizeof(int *));
    for(i=0;i<=n;i++)
        m[i]=(int *)malloc((n+1)*sizeof(int));
    fill(m,n,0);
	for(len=2;len<=n;len++)
		for(i=1;i<=(n-len+1);i++)
        {
			j=i+len-1;
			m[i][j]=INT_MAX;
			for(k=i;k<=j-1;k++)
            {
				cost=m[i][k]+m[k+1][j]+(p[i-1]*p[j]*p[k]);
				if(cost<m[i][j])
                {
					m[i][j]=cost;
					s[i][j]=k;
				}
			}
		}
    puts("\nMatrix M...");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%6d",m[i][j]);
        printf("\n");
    }
    puts("\nMatrix S...");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%6d",s[i][j]);
        printf("\n");
    }

    return cost;
}

void printOptimalParenthesis(int** s, int i, int j)
{
	if(i==j)
		printf("A%d",i);
	else
	{
		printf("(");
		printOptimalParenthesis(s,i,s[i][j]);
		printOptimalParenthesis(s,s[i][j]+1,j);
		printf(")");
	}
}
/*
void pop(int s[40][40],int i,int j){
	if(i==j)printf("A%d",i);
	else{
		printf("(");
		pop(s,i,s[i][j]);
		pop(s,s[i][j]+1,j);
		printf(")");
	}
}
*/
int main()
{
	int i,n,start,end;
	printf("Enter the total no. of matrix: ");
	scanf("%d",&n);
    int* p=(int *)malloc((n+1)*sizeof(int));
    int** s=(int **)malloc((n+1)*sizeof(int *));
    for(i=0;i<=n;i++)
        s[i]=(int *)malloc((n+1)*sizeof(int));
    fill(s,n,0);
	printf("\nEnter the dimensions of the matrices: ");
	for(i=0;i<=n;i++)
		scanf("%d",&p[i]);
	printf("\nEnter the matrix number to start the multiplication: ");
	scanf("%d",&start);
	printf("Enter the matrix number to end the multiplication: ");
	scanf("%d",&end);
	printf("\nMinimum no. of multiplications: %d units\n",matrixChainOrder(p,s,n));
	printf("\nSequence of the matrices to be multiplied: ");
	printOptimalParenthesis(s,start,end);

	return 0;
}
