#include<stdio.h>
int b[20];
void merge(int a[20],int l,int mid,int h)
{
	int m,j,i,k;
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
			b[i]=a[k];i++;
		}
    }
	if(j>h)
	{
		for(k=m;k<=mid;k++)
		{
			b[i]=a[k];i++;
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
			if(i!=j)             //we can remove it too!
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
int Partition1(int a[20],int l,int h)
{
	int x,temp,j,i;
	x=a[l];
	i=l;
	for(j=l+1;j<=h;j++)
	{
		if(a[j]<x)
		{
			i=i+1;
			if(i!=j)             //we can remove it too!
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	a[l]=a[i];
	a[i]=x;
	return i;
}
void Quicksort1(int a[20],int l,int h)
{
	int q;
	if(l<h)
	{
		q=Partition1(a,l,h);
		Quicksort1(a,l,q-1);
		Quicksort1(a,q+1,h);
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
	int a[20],i,n,x,k,ch,h,flag;
	int l,u;
	do
	{
		printf("\nMENU:\n");
		printf("1.Linear search\n2.Binary search\n3.Merge sort\n4.Quick sort last pivot\n5.Quick sort first pivot\n6.Heap sort\n7.Exit\n");
		printf("Enter your choice:\n");
		scanf("%d",&ch);
		if(ch<7)
		{
			printf("Enter the size of array:");
			scanf("%d",&n);
			printf("Enter the elements:");
			for(i=1;i<=n;i++)
				scanf("%d",&a[i]);  
		}
		else
			break;
		switch(ch)
		{
			case 1:
				printf("Enter the searching element:");
				scanf("%d",&x);
				k=linsearch(a,n,x,&flag);
				if(flag==0)
					printf("Element is not present!");
				else
				{
					printf("Element is present at pos=%d",k);
				}
				break;
			case 2:
				printf("Enter the searching element:");
				scanf("%d",&x);
				l=1; u=n;
				k=Binsearch(a,l,u,x);
				if(k!=0)
					printf("Element present at pos=%d",k);
				else
					printf("Element not present!");
				break;
			case 3:
				l=1; u=n;
				mergesort(a,l,u);
				printf("sorted array:");
				for(i=1;i<=n;i++)
					printf("%d\n",a[i]);
				break;
			case 4:
				l=1; u=n;
				Quicksort(a,l,u);
				printf("sorted array:");
				for(i=1;i<=n;i++)
					printf("%d\n",a[i]);
				break;
			case 5:
				l=1; u=n;
				Quicksort1(a,l,u);
				printf("sorted array:");
				for(i=1;i<=n;i++)
					printf("%d\n",a[i]);
				break;
			case 6:
				create_max_heap(a,n);
				printf("\n Max heap elements are\n");
				for(i=1;i<=n;i++)
					printf("%d\t",a[i]);
				heapsort(a,n);
				printf("\n Sorted Array elements are:\n");
				for(i=1;i<=n;i++)
					printf("%d\t",a[i]);
				break;
		}
	}while(ch!=7);
}

