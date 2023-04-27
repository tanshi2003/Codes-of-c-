#include<iostream>
using namespace std;
class cal
{
	int n;
	public:
		void input();
		int all();
		int odd();
		int even();
		int opos();
		int epos();
};
void cal::input()
{
//	int n;
	cout<<"Enter a no.:";
	cin>>n;
}
int cal::all()
{
	int r,s=0,n1=n;
	while(n1>0)
	{
		r=n1%10;
		s=s+r;
		n1=n1/10;	
	}
	return(s);
}
int cal::odd()
{
	int r,s=0,n1=n;
	while(n1>0)
	{
		r=n1%10;
		if(r%2==1)
			s=s+r;
		n1=n1/10;	
	}
	return(s);
}
int cal::even()
{
	int r,s=0,n1=n;
	while(n1>0)
	{
		r=n1%10;
		if(r%2!=1)
			s=s+r;
		n1=n1/10;	
	}
	return(s);
}
int cal::opos()
{
	int r,a[20],c=0,i,p=0,n1=n;
	while(n1>0)
	{
		r=n1%10;
		a[c]=r;
		c++;
		n1=n1/10;	
	}
	for(i=0;i<=c;i++)
	{
		if(i%2==1)
			p=p+a[i];
	}
	return(p);
}
int cal::epos()
{
	int r,a[20],c=0,i,p=0,n1=n;
	while(n1>0)
	{
		r=n1%10;
		a[c]=r;
		c++;
		n1=n1/10;	
	}
	for(i=0;i<=c;i++)
	{
		if(i%2==0)
			p=p+a[i];
	}
	return(p);
}
int main()
{
	int ch,k,s,c=1;
	cal d1;
	d1.input();
	do
	{
	cout<<endl<<"Menu:"<<endl;
	cout<<endl<<"1.All\n2.Odd"<<endl<<"3.Even"<<endl<<"4.Odd positioned"<<endl<<"5.Even positioned"<<endl<<"6.Exit"<<endl;
	cout<<"Enter your choice:";
	cin>>ch;
	switch(ch)
	{
		case 1:
			k=d1.all();
			cout<<"Sum of all digits:"<<k;
			break;
		case 2:
			k=d1.odd();
			cout<<"Sum of all odd digits:"<<k;
			break;
		case 3:
			k=d1.even();
			cout<<"Sum of all even digits:"<<k;
			break;
		case 4:
			k=d1.opos();
			cout<<"Sum of all odd positioned digits:"<<k;
			break;
		case 5:
			k=d1.epos();
			cout<<"Sum of all even positioned digits:"<<k;
			break;
	}
	}while(ch!=6);
	return(0);
}
