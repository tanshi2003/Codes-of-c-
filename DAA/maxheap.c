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
void insert_maxheap(int a[20],int *n,int x)
{
	int i,item;
	printf("Enter the inserting no.:");
	scanf("%d",&x);
	*n=*n+1; a[*n]=x;
	i=*n; item=x;
	while(i>1 && a[i/2]<item)
	{
		a[i]=a[i/2];
		i=i/2;
	}
	a[i]=item;
}
int delmax(int a[],int *n)
{
	int x=0;
	if(*n==0)
		printf("Max heap is empty!");
	else
		{
			x=a[1];  
			a[1]=a[*n];
			*n=*n-1;
			max_heapify(a,1,*n);
		}
		return(x);
}

void main()
{
	int ch,i,n,item,a[20],x;
	do
	{
	printf("\n1.Create max heap\n2.Insert\n3.Delete\n4.exit");
	printf("\nEnter your choice!");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
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
			break;
		case 2:
			insert_maxheap(a,&n,x);
			printf("\n Max heap afrter inserting elements\n");
			for(i=1;i<=n;i++)
				printf("%d\t",a[i]);
			break;
		case 3:
			item=delmax(a,&n);
			if(item!=0)
				printf("\n Deleted element is=%d",item);
			printf("\n max heap after deletion\n");
			for(i=1;i<=n;i++)
				printf("%d\t",a[i]);
			break;
	}
	}while(ch!=4);
}
	

