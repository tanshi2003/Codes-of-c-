#include<stdio.h>
#include<conio.h>
//gr=adjacency matrix c=cost matrix dist[]=distance matrix (distance from source to other vertex
void dijkstra(int v,int n ,int dist[20]);
int c[20][20],gr[20][20];
int main()
{
	int i,e,n,j,k,v,dist[20];
	printf("Enter total no of vertices in graph:\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			gr[i][j]=0;
	printf("\nEnter the total no.of edge:");
	scanf("%d",&e);
	for(i=1;i<=e;i++)  //cost matrix diagonal 0 and all other 99 if no edge 
		for(j=1;j<=e;j++)
	{
		if(i==j)
			c[i][j]=0;
		else
			c[i][j]=99;
	}
	for(k=1;k<=e;k++)
	{
		printf("Enter two vertices for edge%d and cost:\n",k);
		scanf("%d",&i);
		scanf("%d",&j);
		scanf("%d",&c[i][j]);
		gr[i][j]=1;
// printf(" \n enter the cost of edge %d",k);
//scanf("%d",&c[i][j]); 
	}
	for(i=1;i<=n;i++)
	{
		printf("\n\n");
		for(j=1;j<=n;j++)
			printf("\t%d",gr[i][j]);
	}
	printf("\nCost matrix is");
	for(i=1;i<=n;i++)
	{
		printf("\n\n");
		for(j=1;j<=n;j++)
			printf("\t%d",c[i][j]);
		
	}
	printf("\nEnter the source vertex:");
	scanf("%d",&v);
	dijkstra(v,n,dist);
	return 0;
}
void dijkstra(int v,int n,int dist[20])
{
	int i,j,k,s[20],u,min;
	for(i=1;i<=n;i++)
	{// intialising the set[] and dist[]
		dist[i]=c[v][i];
		s[i]=0;
	}
	s[v]=1;    //adding source vertex v to set s
	dist[v]=0;  // distance from source to source
	u=v;
	for(k=2;k<=n;k++)
	{
		min=99;  //find a vertex u not in s[] and dist[u] is min
		for(i=1;i<=n;i++)
		{
			if((s[i]==0) && (dist[i]<min))
			{
				min=dist[i];
				u=i;
			}
		}
		s[u]=1;
		printf("\nDistance: V%d to V%d is =%d",v,u,dist[u]);
		//update dist value of other vertices
		for(j=1;j<=n;j++)
		{
			if((gr[u][j]==1) && (s[j]!=1))
			{
				if(dist[j]> (dist[u]+c[u][j]))
				dist[j]= dist[u]+c[u][j];
				
			}
			
		}
		
	}
}  
