#include<stdio.h>
void max_min(int a[],int l,int u,int *max,int *min)
{
	int max1,min1,m;
	if(l==u)
	{
		*max=a[l];
		*min=a[l];
	}
	else if(l==u-1)
	{
		if(a[l]>a[u])
		{
			*max=a[l];
			*min=a[u];
		}
		else
		{
			*max=a[u];
			*min=a[l];
		}
	}
	else
	{
		m=(l+u)/2;
		max_min(a,l,m-1,max,min);
		max_min(a,m+1,u,&max1,&min1);
		if(max1>*max)
			*max=max1;
		if(min1<*min)
			*min=min1;
	}
}
main()
{
	int a[20],i,n,min,max;
	printf("Enter the size of array:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int l=0,u=n-1;
	max_min(a,l,u,&max,&min);
	printf("Maximum element:%d\n",max);
	printf("Minimum element:%d",min);
}
