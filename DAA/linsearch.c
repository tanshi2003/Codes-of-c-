#include<stdio.h>
int linsearch(int a[],int n,int x,int *);

main()
{
	int a[20],i,n,x,k,flag;
	printf("Enter the size of array:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the searching element:");
	scanf("%d",&x);
	k=linsearch(a,n,x,&flag);
	if(flag==0)
		printf("Element is not present!");
	else
	{
//		printf("Element is present!\n");
		printf("Element is present at pos=%d",k+1);
	}
}
int linsearch(int a[],int n,int x,int *flag)
{
	int i=0;
	*flag=0;
	while((i<n)&&(a[i]!=x))
		i=i+1;
	if(a[i]==x)
		*flag=1;
	else
		*flag=0;
	return(i);
}
