#include<stdio.h>
void insertsort(int a[],int n);
main()
{
	int a[20],i,n;
	printf("Enter the size of array:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	insertsort(a,n);
	printf("sorted array:");
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
}
void insertsort(int a[],int n)
{
	int i,j,item;
	for(i=1;i<n;i++)
	{
		item=a[i];
		j=i-1;
		while(j>=0&&a[j]>item)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=item;
	}
}
