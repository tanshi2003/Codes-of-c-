//bfs using matrix representation
#include<stdio.h>
#define max 20
int g[10][10],n,q[20],front=0,rear=-1,visited[10];  //global declaration
void bfs(int v);
void bft();
void dfs(int v);
void dft();
main()
{
	int i,j,e,ch,v1,v2,v;
	printf("\nEnter the number of vertices in the graph:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			g[i][j]=0;
	}
	printf("\nEnter the number of edges in the undirected graph:\n");
	scanf("%d",&e);
	printf("\nEnter the %d pair of vertices having edge between them:",e);
	for(i=1;i<=e;i++)
	{
		scanf("%d%d",&v1,&v2);
		g[v1][v2]=1;
		g[v2][v1]=1;
	}
	printf("\nMatrix representation of graph\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d\t",g[i][j]);
	printf("\n");
	}
	do
	{
		printf("\n1.bfs\n2.bft\n3.dfs\n4.dft\n5.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		for(i=1;i<=n;i++)     //all vertices are visited
			visited[i]=0;
		switch(ch)
		{
			case 1:
				printf("\nEnter the starting vertex for bfs:");
				scanf("%d",&v);
				printf("\nBFS of the graph is \n");
				bfs(v);
				break;
			case 2:
				printf("\nBFT of the graph is \n");
				bft(1);
				break;
			case 3:
				printf("\nEnter the dfs index:");
				scanf("%d",&v);
				printf("\nDFS of the graph is\n");
				dfs(v);
				break;
			case 4:
				printf("\nDFT of the graph is\n");
				dft(1);
				break;
			case 5:
				printf("Thank you!");
				break;
			default:printf("Wrong choice\n");
			break;
		}
	}while(ch!=5);
}
int deleteq()        //delete function
{
	int v;
	if(rear<front)
		return 0;
	else
		{
			v=q[front];
			front++;
			return v;
		}
}
void insertq(int x)      //insert function
{
	if(rear==max-1)
	{
		printf("\nQueue is full!");
		return;
	}
	else
	{
		rear++;
		q[rear]=x;
	}
}
int emptyq()
{
	if(rear<front)
		return 1;
	else
		return 0;
}
void bfs(int v)
{
	int w,x;
	visited[v]=1;
	printf("%d\t",v);
	insertq(v);
	while(!emptyq())
	{
		v=deleteq();
		for(w=1;w<=n;w++)
		{
			if(g[v][w]==1)
			{
				if(visited[w]==0)
				{
					visited[w]=1;
					printf("%d\t",w);
					insertq(w);
				}
			}
		}
	}
}
void bft()
{
	int i;
	for(i=1;i<=n;i++)
		visited[i]=0;
	for(i=1;i<=n;i++)
	{
		if(visited[i]==0)
			bfs(i);
	}
}
void dfs(int v)
{
	int i;
	visited[v]=1;
	printf("%d\t",v);
	for(i=1;i<=n;i++)
	{
		if(g[v][i]==1 && visited[i]==0)
			dfs(i);
	}
}
void dft()
{
	int i;
	for(i=1;i<=n;i++)
		visited[i]=0;
	for(i=1;i<=n;i++)
	{
		if(visited[i]==0)
			dfs(i);
	}
}
