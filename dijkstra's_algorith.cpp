#include<stdio.h>
#define INFINITY 9999
#define MAX 10

 
int main()
{
	int G[MAX][MAX],i,j,n,u;
	printf("Enter no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			printf("Enter cost at (%d,%d) : ",i+1,j+1);
			scanf("%d",&G[i][j]);
		}
	
	printf("\nEnter the starting node:");
	scanf("%d",&u);
	
	int cost[MAX][MAX],distance[MAX],pred[MAX];
	int visited[MAX],count,mindistance,nextnode;
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];
	
	for(i=0;i<n;i++)
	{
		distance[i]=cost[u][i];
		pred[i]=u;
		visited[i]=0;
	}
	
	distance[u]=0;
	visited[u]=1;
	count=1;
	
	while(count<n-1)
	{
		mindistance=INFINITY;
		
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
						
			visited[nextnode]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}
 	int min=0;
	for(i=0;i<n;i++)
		if(i!=u)
		{
			printf("\nDistance of node%d=%d",i,distance[i]);
			printf("\nPath=%d",i);
			min=min+distance[i];
			j=i;
			do
			{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=u);
	}
	printf("\nTotal Distance : %d",min);
}

