#include<stdio.h>
void minheapify(int i);
void buildminheap();
void kruskals();
int e[10],g[10][10],nv,ne,p[10];
main()
{
	int i,j,v1,v2,w;
	printf("\nEnter the number of vertices in the graph:");
	scanf("%d",&nv);
	for(i=1;i<=nv;i++)
		for(j=1;j<=nv;j++)
			g[i][j]=99;
	
	printf("\nEnter the number of edges in the undirected graph\n");
	scanf("%d",&ne);
	printf("\nEnter %d pair of vertices having edge b/w them and edge-cost\n",ne);
	for(i=1;i<=ne;i++)
	{
		scanf("%d%d%d",&v1,&v2,&w);
		g[v1][v2]=w;
		g[v2][v1]=w;
		e[i]=w;
	}
	printf("\nMatrix representation\n");
	for(i=1;i<=nv;i++)
	{
	
		for(j=1;j<=nv;j++)
			printf("%d\t",g[i][j]);
			printf("\n");
	}
	kruskals();
}
int find(int x)
{
	int r=x;
	while(p[r]>0)
	{
			r=p[r];
		}
	return r;
}
void dounion(int j,int k)
{
	p[j]=k;
}
int deleteminheap()
{
	int x;
	x=e[1];
	e[1]=e[ne];
	ne--;
	minheapify(1);
	return x;
}
void kruskals()
{
	int i,j,k,t[10][2],x,q,w,v1,v2,mstcost=0,s,r,flag;
	buildminheap();
	printf("\nArray after min heap:\n");
	printf("\n");
	for(i=1;i<=ne;i++)
		printf("%d ",e[i]);
	for(j=1;j<=nv;j++)
		p[j]=-1;
	i=1;
	while(i<=nv-1 && ne>0)
	{
		x=deleteminheap();
		for(q=1;q<=nv;q++)
		{
			for(w=1;w<=nv;w++)
			{
				if(g[q][w]==x)
				{
					v1=q;
					v2=w;
			}
		}
	}
		s=find(v1);
		r=find(v2);
		if(s!=r)
		{
			t[i][1]=v1;
			t[i][2]=v2;
			i++;
			dounion(v1,v2);
			mstcost +=g[v1][v2];
		}
	}
	if(i<nv-1)
		printf("\nNo minimum spanning tree");
	else
	{
		printf("\nThe spanning tree:\n");
		for(i=1;i<=nv-1;i++)
		{
			printf("\n");
			printf("Edge(%d,%d) cost=%d",t[i][1],t[i][2],g[t[i][1]][t[i][2]]);
		}
		printf("\nMinimum cost=%d",mstcost);
	}
}
void buildminheap()
{
	int i;
	for(i=ne/2;i>=1;i--)
		minheapify(i);
}
void minheapify(int i)
{
	int small,l,r,temp;
	l=2*i;
	r=2*i+1;
	if(l<=ne && (e[l]<e[i]))
		small=l;
	else
		small=i;
	if(r<=ne && (e[r]<e[small]))
		small=r;
	if(i!=small)
	{
		temp=e[i];
		e[i]=e[small];
		e[small]=temp;
		minheapify(small);
	}
}
