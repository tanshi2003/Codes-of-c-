#include<iostream>
using namespace std;
class pp
{
	int a,b;
	public:
	void input();
	void prime();
	void perfect();
};
void pp::input()
{
	cout<<"Enter the first range:";
	cin>>a;
	cout<<"Enter the last range:";
	cin>>b;
}
void pp::prime()
{
	int i,j,flag;
	for(i=a;i<b;i++)
	{
		if(i==1||i==0)
			continue;
		flag=0;
		for(j=2;j<=i/2;j++)
		{
			if(i%j==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			cout<<i<<endl;		
	}
}
void pp::perfect()
{
	int i,j;
	for(i=a;i<=b;i++)
	{
		int s=0;
		for(j=1;j<i;j++)
		{
			if(i%j==0)
				s=s+j;
		}
		if(s==i)
			cout<<i<<endl;
	}
}
int main()
{
	int ch,k;
	pp f1;
	f1.input();
	do
	{
	cout<<"Menu";
	cout<<"\n1.Prime\n2.Perfect\n3.Exit\n";
	cout<<"Enter your choice:";
	cin>>ch;
	switch(ch)
	{
		case 1:
			f1.prime();
			break;
		case 2:
			f1.perfect();
			break;
	}
    }while(ch!=3);
    return 0;
}
