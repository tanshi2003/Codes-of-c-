#include<stdio.h>
int Partition(int a[20],int l,int h)
{
	int x,temp,j,i;
	x=a[h];
	i=l-1;
	for(j=l;j<=h-1;j++)
	{
		if(a[j]<x)
		{
			i=i+1;
			if(i!=j)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	a[h]=a[i+1];
	a[i+1]=x;
	return i+1;
}
void Quicksort(int a[20],int l,int h)
{
	int q;
	if(l<h)
	{
		q=Partition(a,l,h);
		Quicksort(a,l,q-1);
		Quicksort(a,q+1,h);
	}
}
void main()
{
	int a[20],i,n;
	printf("Enter the size of array:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int l=0;
	int h=n-1;
	Quicksort(a,l,h);
	printf("sorted array:");
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
}
