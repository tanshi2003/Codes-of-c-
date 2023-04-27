#include<stdio.h>
#include<math.h>
int x[20];
void Nqueen(int k,int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(place(k,i))
		{
			x[k]=i;
			if(k==n)
				{
					for(i=1;i<=n;i++)
						printf("\t%d",x[i]);
						printf("\n");
				}
			else 
				Nqueen(k+1,n);
		}
	}
}
int place(int k,int i)
{
	int j;
	for(j=1;j<=k-1;j++)
	{
		if((x[j]==i)||(abs(x[j]-i)==abs(j-k)))
			return 0;
			
	}
	return 1;
}

int main()
{
	int n,i,j;
	printf("Enter the number of queens:");
	scanf("%d",&n);
	Nqueen(1,n);
	return 0;
}
