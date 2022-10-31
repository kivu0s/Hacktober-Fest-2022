/*A program to solve the m Coloring problem (Backtracking Algorithm)*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int count=0;

void print(int *helper, int n)
{
    int i;
	printf("\nSolution %d: ",++count);
	for(i=1;i<=n;i++)
		printf("%d ",helper[i]);
	printf("\n");
}

void nextvalue(int** graph, int *helper, int k, int m)
{
    int j;
	do
    {
		helper[k]=(helper[k]+1)%(m+1);
		if(helper[k]==0)
            return;
		for(j=1;j<=k-1;j++)
			if(graph[k][j]==1 && helper[k]==helper[j])
                break;
        if(j==k)
            return;
	}while(true);
}

void mColoring(int** graph, int *helper, int k, int m, int n)
{
	do
    {
		nextvalue(graph,helper,k,m);
		if(helper[k]==0)
            return;
		if(k==n)
            print(helper,n);
		else
            mColoring(graph,helper,k+1,m,n);
	}while(true);
}

int main()
{
    int i,j,m,n;
    char v;
    FILE *fp;
    char file[100];
    /*printf("Enter file name: ");
    gets(file);*/
    fp=fopen("mColoringGraph.txt","r");
    if(fp==NULL)
    {
        puts("\n!!! File not found !!!");
        exit(0);
    }
    fscanf(fp,"%d",&n);
    int* helper=(int *)malloc((n+1)*sizeof(int));
    int** graph=(int **)malloc((n+1)*sizeof(int *));
    for(i=0;i<=n;i++)
        graph[i]=(int *)malloc((n+1)*sizeof(int));
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            fscanf(fp,"%d",&graph[i][j]);
    printf("\nEnter maximum no. of Colors available: ");
	scanf("%d",&m);
    getchar();
    printf("\nEnter the starting vertex: ");
    scanf("%c",&v);
    if(v>=65 && v<(65+n))
    {
        mColoring(graph,helper,v-64,m,n);
        if(count==0)
            printf("\n!!! No Solution possible !!!");
    }
	else
        puts("!!! Invalid input. Please enter a valid vertex !!!");

    return 0;
}
