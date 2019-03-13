#include<stdio.h>

int a,b,u,v,i,j,k,min,mincost=0,cost[10][10],parent[10]={0},ne=1,n,sorter[100],temp;

int main(){
	printf("Enter Size Of Graph : ");
	scanf("%d",&n);
	for(i=0;i<n*n;i++){
			printf("\nEnter Cost At %d : ",i+1);
			scanf("%d",&sorter[i]);
	}
	for(i=0;i<n*n;i++){
		for(j=0;j<n*n;j++){
			if(sorter[j]>sorter[j+1]){
				temp=sorter[j];
				sorter[j]=sorter[j+1];
				sorter[j+1]=temp;
			}
		}
	}
	k=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
				cost[i][j]=sorter[++k];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d, ",cost[i][j]);
		}
	}
	//MATRIX SORTED]
	while(ne<n){
		for(i=0,min=999;i<n;i++)
			for(j=0;j<n;j++)
				if(cost[i][j]<min)
					if(parent[i]==0){
						min=cost[i][j];
						a=u=i;
						b=v=j;
					}
					if(parent[u]==0||parent[v]==0){
						printf("Edge %d(%d,%d) Cost : %d",ne++,a,b,min);
						mincost+=min;
						parent[b]=1;
					}
				cost[i][j]=cost[j][i]=999;
	}
	printf("\nMincost : %d",mincost);
}
