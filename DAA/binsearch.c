#include<stdio.h>
int Binsearch(int a[],int l,int u,int x);
main()
{
	int a[20],i,n,x,k;
	printf("Enter the size of array:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int l=0,u=n-1;
	printf("Enter the searching element:");
	scanf("%d",&x);
	k=Binsearch(a,l,u,x);
	if(k!=0)
		printf("Element present at pos=%d",k+1);
	else
		printf("Element not present!");
	
}
int Binsearch(int a[],int l,int u,int x)
{
	int m;
	if(l==u)
	{
		if(x==a[l])
			return(l);
		else
			return 0;
	}
	else
	{
		m=(l+u)/2;
		if(x==a[m])
			return m;
		else if(x<a[m])
			return Binsearch(a,l,m-1,x);
		else
			return Binsearch(a,m+1,u,x);
	}
}
