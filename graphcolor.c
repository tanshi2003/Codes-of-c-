#include<stdio.h>
#include<stdbool.h>
int x[20],n,G[20][20],m;
int nextvalue(int k);
void mcoloring(int k)
{
	int i;
	do
	{
		nextvalue(k);
		if(x[k]==0)
			return;
		if(k==n)
			{
				for(i=1;i<=n;i++)
					printf("\t%d",x[i]);
					printf("\n");
			}
		else
			mcoloring(k+1);
	}while(k<=n);
}
int nextvalue(int k)
{
	int j;
	do
	{
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0)
				break;
		for(j=1;j<=n;j++)
		{
			if((G[k][j]!=0)&&(x[k]==x[j]))
				break;
		}
		if(j==n+1)
			break;
	}while(x[k]!=0);
}
int main()
{
	int i,j,e,v1,v2,v;				
	printf("Enter the no of vertices in graph:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			G[i][j]=0;
	printf("\nEnter the number of edges in undirected graph:\n");
	scanf("%d",&e);
	printf("\nEnter the %d pair of vertices having edge:",e);
	for(i=1;i<=e;i++)
	{
	 	scanf("%d",&v1);
	 	scanf("%d",&v2);
//	 	scanf("%d",&weight);
	 	G[v1][v2]=1;
	 	G[v2][v1]=1;
	}
	printf("\nMatrix representation of graph:\n");
	for(i=1;i<=n;i++)
		{
	 		for(j=1;j<=n;j++)
	 		{
	 			printf("%d  \t",G[i][j]);
		 	}
			printf("\n");
	 	}
	printf("Enter the no. of colors:");
	scanf("%d",&m);
	mcoloring(1);
}
