#include<stdio.h>
int x[20],w[20],m;
void sumofsubset(int s,int k,int r)
{
	int i;
	x[k]=1;
	if(s+w[k]==m)
		{
			for(i=1;i<=k;i++)
				printf("\t%d",x[i]);
				printf("\n");
		}
	else if(s+w[k]+w[k+1]<=m)
		sumofsubset(s+w[k],k+1,r-w[k]);
	if((s+r-w[k]>=m)&&(s+w[k+1]<=m))
		{
			x[k]=0;
			sumofsubset(s,k+1,r-w[k]);
		}
}
int main()
{
	int i,n,j,t,sm=0;
	printf("Enter the number of sum of subset:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);
		sm=sm+w[i];
	}
	printf("Enter the knapsack total weight:");
	scanf("%d",&m);
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(w[j]>w[j+1])
		 	{
				t=w[j];
				w[j]=w[j+1];
				w[j+1]=t;
		 	}
	sumofsubset(0,1,sm);
}
