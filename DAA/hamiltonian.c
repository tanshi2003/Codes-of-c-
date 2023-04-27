#include<stdio.h>
int G[10][10],x[10],n;
void nextvalue(int k)
{
	int j;
	do
	{
		x[k]=(x[k]+1)%(n+1);
		if(x[k]==0)
			return;
		if(G[x[k-1]][x[k]]!=0)
		{
			for(j=1;j<=k-1;j++)
				if(x[j]==x[k])
					break;
			if(j==k)
				if((k<n)||((k==n)&&G[x[n]][x[1]]!=0))
					return;
		}
	}while(x[k]!=0);
}
void hamiltonian(int k)
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
			hamiltonian(k+1);
	}while(k<=n);
}
int main()
{
	int i,j,e,v1,v2,v;				
	printf("Enter the no. of vertices in graph:");
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
	x[1]=1;
	printf("Solutions are:\n");
	hamiltonian(2);
}
