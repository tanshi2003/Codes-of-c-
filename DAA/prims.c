#include<stdio.h>
#define MAX 20
void prims(int cost[10][10],int n);
int near[10],t[10][2],costmst=0;
int weight;
main()
{
	int i,n,j,e,v1,v2,v,cost[10][10];				
	printf("Enter the no of vertices in graph:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cost[i][j]=999;
	printf("\nEnter the number of edges in undirected graph:\n");
	scanf("%d",&e);
	printf("\nEnter the %d pair of vertices having edge and weight between them:",e);
	for(i=1;i<=e;i++)
	{
	 	scanf("%d",&v1);
	 	scanf("%d",&v2);
	 	scanf("%d",&weight);
	 	cost[v1][v2]=weight;
	 	cost[v2][v1]=weight;
	}
	printf("\nMatrix representation of graph:\n");
	for(i=1;i<=n;i++)
		{
	 		for(j=1;j<=n;j++)
	 		{
	 			printf("%d  \t",cost[i][j]);
		 	}
			printf("\n");
	 	}
	prims(cost ,n);
	printf("\nThe minimum spanning tree edges are:\n");
	for(i=1;i<=n-1;i++)
	{
		printf("edge(%d,%d) cost=%d",t[i][1],t[i][2],cost[t[i][1]][t[i][2]]);
		printf("\n");
	}
	printf("Cost of mst=%d",costmst);
}
void prims(int cost[10][10], int n)
{
	int i,k,l,j,v,min,q,w;
	min=999;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			if(min>cost[i][j])
			{
				min=cost[i][j];
				k=i;
				l=j;
			}
	}
	t[1][1]=k;  
	t[1][2]=l;
	costmst +=cost[k][l];    //update the cost of MST
	for(i=1;i<=n;i++)    //initialise near value of vertices
	{
		if(cost[i][k]<cost[i][l])
			near[i]=k;
		else 
			near[i]=l;
	}
	near[k]=0; near[l]=0;
	for(i=2;i<=n-1;i++)  // selecting remaining n-2 edges
	{
		min=999;
		for(v=1;v<=n;v++)
		{
			if(near[v]!=0 && (cost[v][near[v]]<min))
			{
				min=cost[v][near[v]];
				j=v;
			}
		}
		t[i][1]=j;
		t[i][2]=near[j];
		costmst+=cost[j][near[j]];
		near[j]=0;
		for(k=1;k<=n;k++)
		{
			if(near[k]!=0 && cost[k][j]<cost[k][near[k]])
				near[k]=j;
		}
	}
}
