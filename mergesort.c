#include<stdio.h>
void merge(int a[20],int l,int mid,int h)
{
	int m,j,i,b[20],k;
	m=l;j=mid+1;i=l;
	while(m<=mid && j<=h)
	{
		if(a[m]<a[j])
		{
			b[i]=a[m];
			m=m+1;
			i=i+1;
		}
		else
		{
			b[i]=a[j];
			j=j+1;
			i=i+1;
		}
	}
	if(m>mid)
	{
		for(k=j;k<=h;k++)
		{
			b[i]=a[k];k=k+1;
		}
    }
	if(j>h)
	{
		for(k=m;k<=mid;k++)
		{
			b[i]=a[k];k=k+1;
		}
	}
	for(k=l;k<=h;k++)
		a[k]=b[k];
}
void mergesort(int a[20],int l,int h)
{
	int mid;
	if(l<h)
	{
		mid=(l+h)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,h);
		merge(a,l,mid,h);
	}
}
main()
{
	int a[20],b[20],i,n;
	printf("Enter the size of array:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int l=0;
	int h=n-1;
	mergesort(a,l,h);
	printf("sorted array:");
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
}
