#include<stdio.h>
void selectsort(int a[],int n);
main()
{
	int a[20],i,n,x,k,flag;
	printf("Enter the size of array:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	selectsort(a,n);
	printf("sorted array:");
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
}
void selectsort(int a[],int n)
{
	int i,j,t,k;
	for(i=1;i<n-1;i++)
		{
			k=i;
			for(j=i+1;j<n;j++)
		 	{
				if(a[j]<a[k])
					k=j;
		 	}
		if(i!=k)
		{
			t=a[i];
			a[i]=a[k];
			a[k]=t;
		}
		}
}
