#include<stdio.h>
void bubblesort(int a[],int n);
main()
{
	int a[20],i,n;
	printf("Enter the size of array:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	bubblesort(a,n);
	printf("sorted array:");
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
}  
void bubblesort(int a[],int n)
{
	int i,j,t;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
		 	{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
		 	}
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
