//job sequencing
#include<stdio.h>
struct job
{
	int id;
	int p;
	int d;
};
struct job jb[10];
void jobseq(int n);
void main()
{
	int n,i,j;
	struct job temp;
	printf("\nEnter the number of jobs:");
	scanf("%d",&n);
	printf("\nEnter the job number profit and deadline of %d jobs\n",n);
	for(i=1;i<=n;i++)
		scanf("%d%d%d",&jb[i].id,&jb[i].p,&jb[i].d);
	printf("\njob no. profit \tdeadline\n");
	for(i=1;i<=n;i++)
		printf("\n%d\t%d\t%d",jb[i].id,jb[i].p,jb[i].d);
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-i;j++)
			if(jb[j].p<jb[j+1].p)
			{
				temp=jb[j];
				jb[j]=jb[j+1];
				jb[j+1]=temp;
			}
	}
	jobseq(n);
}
void jobseq(int n)
{
	int j[10],k,i,r,totalprofit=0,q;
	jb[0].d=0;
	jb[0].p=0;
	j[0]=0;
	j[1]=1;
	k=1;
	totalprofit=totalprofit+jb[1].p;
	for(i=2;i<=n;i++)
	{
		r=k;
		while(jb[r].d>jb[i].d && jb[r].d!=r)
			r=r-1;
		if(jb[r].d<=jb[i].d && jb[i].d>r)
		{
			for(q=k;q>=r+1;q--)
				j[q+1]=j[q];
			j[r+1]=i;
			totalprofit =totalprofit+jb[i].p;
			k=k+1;
		}
	}
	printf("\n Subsets of job\n {");
	for(i=1;i<=k;i++)
		printf("%d,",jb[j[i]].id);
	printf("}\nTotal profit=%d",totalprofit);
}
