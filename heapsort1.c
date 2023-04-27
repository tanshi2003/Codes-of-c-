#include<stdio.h>
void max_heapify(int a[20],int i,int n)
{
	int l,r,t,large;
	l=2*i;r=2*i+1;
	if(l<=n && a[l]>a[i])
		large=l;
	else
		large=i;
	if(r<=n && a[r]>a[large])
		large=r;
	if(i!=large)
	{
		t=a[i];
		a[i]=a[large];
		a[large]=t;
		max_heapify(a,large,n);
	}
}
void create_max_heap(int a[],int n)
{
	int i;
	for(i=n/2;i>=1;i--)
		max_heapify(a,i,n);
}
void heapsort(int a[],int n)
{
	int i,t;
	create_max_heap(a,n);
	for(i=n;i>=2;i--)
	{
		t=a[1];
		a[1]=a[i];
		a[i]=t;
		max_heapify(a,1,i-1);
	}
}
void main()
{
	int i,n,a[20];
	printf("Enter the size of array:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("\n Array elements are:\n");
	for(i=1;i<=n;i++)
		printf("%d\t",a[i]);
	create_max_heap(a,n);
	printf("\n Max heap elements are\n");
	for(i=1;i<=n;i++)
		printf("%d\t",a[i]);
	heapsort(a,n);
	printf("\n Sorted Array elements are:\n");
	for(i=1;i<=n;i++)
		printf("%d\t",a[i]);
}

