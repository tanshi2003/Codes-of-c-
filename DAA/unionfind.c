#include<stdio.h>
void sunion(int i,int j);
int find(int i);
void wunion(int i,int j);
int cfind(int i);
int p[20],n;
void main()
{
	int i,c,x,k,r1,r2;
	printf("Enter the no.of elements:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		p[i]=-1;
	printf("\n P[i]=\t");
	for(i=1;i<=n;i++)
		printf("%d\t",p[i]);
	printf("\n ele[i]=");
	for(i=1;i<=n;i++)
		printf(" %d\t",i);
	do
	{
		printf("\n1.simple union\n2.simple find\n3.exit");
		printf("\nEnter your choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("Enter the root of two tress:");
				scanf("%d%d",&r1,&r2);
				if((p[r1]==-1)&&(p[r2]==-1))
					sunion(r1,r2);
				else
					printf("Invalid roots!");
				break;
			case 2:
				printf("Enter the searching no.:");
				scanf("%d",&x);
				k=find(x);
				printf("The element %d is in the tree whose node is %d",x,k);
				break;
		}
			printf("\n p[i]= \t");
			for (i=1;i<=n;i++)
				printf("%d\t",p[i]);
			printf("\n ele [i]=");
			for (i=1;i<=n;i++) 
				printf ("%d\t",i);
	}while(c!=3);
	
}
void sunion(int i,int j)
{
	p[i]=j;
}
int find(int i)
{
	int j;
	j=i;
	while(p[j]>0)
		j=p[j];
	return(j);
}

