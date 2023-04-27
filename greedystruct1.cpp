#include<stdio.h>
struct knaps
{
	int id;
	float p;
	float w;
};
int n;
void sort(struct knaps *kn,int n)
{
	int i,j;
	struct knaps temp;
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-1;j++)
		{
			if(kn[j].p/kn[j].w<kn[j+1].p/kn[j+1].w)
			{
				temp=kn[j];
				kn[j]=kn[j+1];
				kn[j+1]=temp;
			}
		}
	}
}
void knapsack(struct knaps *kn,float m)
{
	float x[10],u,profit=0;
	int i,j;
	for(i=1;i<=n;i++)
		x[i]=0;
	u=m;
	for(i=1;i<=n;i++)
	{
		if(kn[i].w>u)
			break;
		x[i]=1;
		u=u-kn[i].w;
		profit+=kn[i].p;
	}
	if(i<=n)
	{
		x[i]=u/kn[i].w;
		profit+=(kn[i].p*x[i]);
	}
	printf("\nThe optimal solution vector:\n");
	for(i=1;i<=n;i++)
		printf("x[%d]=%2f\t",kn[i].id,x[i]);
	printf("\n The profit=%2f",profit);
}
main()
{
	int i,j;
	struct knaps kn[10],temp;
	float m;
	printf("\nEnter the number of elements:");
	scanf("%d",&n);
	printf("\nEnter object id,profit and weight of %d objects \n",n);
	for(i=1;i<=n;i++)
		scanf("%d%f%f",&kn[i].id,&kn[i].p,&kn[i].w);
	printf("\nEnter the capacity of the knapsack:");
	scanf("%f",&m);
	printf("\nobjectid\tprofit\t\tweight\t\tprofit/weight\n");
	for(i=1;i<=n;i++)
		printf("%d\t\t%f\t%f\t%2f\n",kn[i].id,kn[i].p,kn[i].w,kn[i].p/kn[i].w);
	sort(kn,n);
	knapsack(kn,m);
}
