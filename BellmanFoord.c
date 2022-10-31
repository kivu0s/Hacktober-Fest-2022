/*A program to implement Bellman-Ford Algorithm for a graph to find the shortest path*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct node
{
	int weight;
	char precedence;
}GRAPHNODE;

void path(int i, GRAPHNODE *helper)
{
	if(helper[i].precedence=='N')
		return;
	else
	{
		path((int)helper[i].precedence-64,helper);
		printf("%c->%c  ",helper[i].precedence,(char)(i+64));
	}
}

void print(int vertex, int dest, GRAPHNODE *helper)
{
	int i;
	if(i!=vertex)
	{
		printf("\nShortest path from vertex %c to vertex %c: ",(char)(vertex+64),(char)(dest+64));
		path(dest,helper);
		if(helper[dest].weight!=INT_MAX)
			printf("\nThe cost is: %d units",helper[dest].weight);
		else
			printf("\nThe cost is: Infinite");
	}
}

bool bellmanFord(int vertex, int** graph, GRAPHNODE *helper, int n)
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		helper[i].weight=INT_MAX;
		helper[i].precedence='N';
	}
	helper[vertex].weight=0;
	for(i=1;i<=n-1;i++)
		for(j=0;j<=n;j++)
			for(k=0;k<=n;k++)
				if(graph[j][k]!=0 && helper[j].weight!=INT_MAX && helper[j].weight+graph[j][k]<helper[k].weight)
				{
					helper[k].weight=helper[j].weight+graph[j][k];
					helper[k].precedence=(char)(j+64);
				}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(graph[i][j]>0 && helper[i].weight!=INT_MAX && helper[i].weight+graph[i][j]<helper[j].weight)
				return false;
	return true;
}

int main()
{
    int i,j,n;
    char v,d;
	FILE *fp;
	char file[100];
	printf("Enter file name: ");
	gets(file);
	fp=fopen(file,"r");
	if(fp==NULL)
    {
        puts("\n!!! File not found !!!");
        exit(0);
    }
	fscanf(fp,"%d",&n);
    GRAPHNODE* helper=(GRAPHNODE *)malloc((n+1)*sizeof(GRAPHNODE));
    int** graph=(int **)malloc((n+1)*sizeof(int *));
    for(i=0;i<=n;i++)
        graph[i]=(int *)malloc((n+1)*sizeof(int));
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            fscanf(fp,"%d",&graph[i][j]);
    printf("\nEnter the starting vertex: ");
    scanf("%c",&v);
    getchar();
    printf("\nEnter the destination vertex: ");
    scanf("%c",&d);
    if((v>=65 && v<(65+n)) && (d>=65 && d<(65+n)))
		if(!bellmanFord(v-64,graph,helper,n))
			printf("\n!!! Negative Edge Cycle occurs !!!");
		else
			print(v-64,d-64,helper);
	else
        puts("!!! Invalid input. Please enter a valid vertex !!!");
	
	return 0;
}
