#include<stdio.h>
float p[10],w[10];
//void knapsack(int n,float m);
void knapsack(int n,float m)
{
	float x[10],u,profit=0;
	int i,j;
	for(i=1;i<=n;i++)
		x[i]=0;
	u=m;
	for(i=1;i<=n;i++)
	{
		if(w[i]>u)
			break;
		x[i]=1.0;
		u=u-w[i];
//		profit+=kn[i].p;
	}
	if(i<=n)
		x[i]=u/w[i];
//	for(i=1;i<=n;i++)
//		printf(x[i]);
	printf("\nThe optimal solution vector:\n");
	for(i=1;i<=n;i++)
		printf("x[%d]=%0.2f\t",i,x[i]);
	for(i=1;i<=n;i++)
		profit +=p[i]*x[i];
	printf("\nThe optimal profit=%.2f",profit);
}
main()
{
	int i,j,n;
	float m,temp;
	printf("\nEnter the number of elements:");
	scanf("%d",&n);
	printf("\nEnter profit and weight of %d objects \n",n);
	for(i=1;i<=n;i++)
		scanf("%f%f",&p[i],&w[i]);
	printf("\nEnter the capacity of the knapsack:");
	scanf("%f",&m);
	printf("\nobjectid\tprofit\t\tweight\t\tprofit/weight\n");
	for(i=1;i<=n;i++)
		printf("%d\t\t%f\t%f\t%.2f\n",i,p[i],w[i],p[i]/w[i]);
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(p[j]/w[j]<p[j+1]/w[j+1])
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
				
				temp=w[j];
				w[j]=w[j+1];
				w[j+1]=temp;
			}
		}
	}
	printf("\nobject-id\t profit\t weight\t profit/weight \n");
	for(i=1;i<=n;i++)
		printf("\t%d\t%0.2f\t%0.2f\t %0.2f\n",i,p[i],w[i],p[i]/w[i]);
	knapsack(n,m);
}
