//bfs,bft,dfs using linked list representation
#include<stdio.h>
#include<stdlib.h>
#define max 20
typedef struct nodetype
{
	int info;
	struct nodetype *next;
}node;
node *getnode()
{
	node *p;
	p=(node*)malloc(sizeof(node));
	return p;
}
void bft();
void bfs(int v);
void dfs(int v);
void dft();
node *h[10];
int n,visited[10],g[10],q[20],rear=-1,front=0;
main()
{
	int i,k,ch,v;
	node *p,*r;
	printf("\nEnter the number of vertices:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		h[i]=getnode();
		h[i]->info=i;
		p=h[i];
		printf("\nEnter the number of vertices adjacent from %d=",i);
		scanf("%d",&k);
		printf("\nEnter those %d vertices adjacent from %d\n",k,i);
		while(k>=1)
		{
			scanf("%d",&v);
			r=getnode();
			r->info=v;
			r->next=NULL;
			p->next=r;
			p=p->next;
			k--;
		}
	}
	printf("\nList representation of graph:\n");
	for(i=1;i<=n;i++)
	{
		printf("Head[%d]->",i);
		p=h[i]->next;
		while(p!=NULL)
		{
			printf("%d->",p->info);
			p=p->next;
		}
		printf("NULL");
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
				printf("\nBFS of the graph is:\n");
				bfs(v);
				break;
			case 2:
				printf("\nBFT of the graph is:\n");
				bft(1);
				break;
			case 3:
				printf("\nEnter the dfs index:");
				scanf("%d",&v);
				printf("\nDFS of the graph is:\n");
				dfs(v);
				break;
			case 4:
				printf("\nDFT of the graph is:\n");
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
	int x;
	if(rear<front)
		return 0;
	else
		{
			x=q[front];
			front++;
			return x;
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
	int x;
	node *p;
	visited[v]=1;
	printf("%d\t",v);
	insertq(v);
	while(!emptyq())
	{
		x=deleteq();
		p=h[x];
		while(p!=NULL)
		{
			if(visited[p->info]==0)
				{
					visited[p->info]=1;
					printf("%d\t",p->info);
					insertq(p->info);
				}
				p=p->next;
		}
	}
}
void bft()
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(visited[i]==0)
			bfs(i);
	}
}
void dfs(int v)
{
	node *p;
	visited[v]=1;
	printf("%d\t",v);
	p=h[v];
	while(p!=NULL)
	{
		if(visited[p->info]==0)
			dfs(p->info);
		p=p->next;
	}
}
void dft()
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(visited[i]==0)
			dfs(i);
	}
}
