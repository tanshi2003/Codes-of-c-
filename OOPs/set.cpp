#include<iostream>
using namespace std;
class set
{
	int n;
	int ar[6];
	public:
		set()
		{
			int i;
			n=3;
		//	cout<<"Default constructor called!";
			for(i=0;i<n;i++)
				ar[i]=1;
			sort();
		}
		set(int a,int b,int c)
		{
		//  cout<<"Parametrized constructor called!";
			ar[0]=a;
			ar[1]=b;
			ar[2]=c;
			sort();
		}
/*		set(set &s1)
		{
		//  cout<<"Copy Constructor called!";
			ar[0]=s1.ar[0];
			ar[1]=s1.ar[1];
			ar[2]=s1.ar[2];
			n=3;
		}    */
		void input();
		set intersect(set s);
		set union1(set s);
		int getn()
		{	return n;
		}
		void display();
		void sort();
		~set()
		{
			cout<<"Destructor called!"<<endl;
		}
};
void set::input()
{
	int i;
	n=3;
	for(i=0;i<n;i++)
		cin>>ar[i];
	sort();
}
set set::intersect(set s)
{	
	set st;
	st.n=0;
	int i=0,j=0,k=0,l=0;
	while(i<n)
	{
		while(j<n)
		{
			if(ar[i]==s.ar[j])
			{
				st.ar[k++]=ar[i];
				l=j;
				st.n=k;
				j++;
				break;	
			}
			j++;
		}
		if(j==n)
			j=l;
		i++;
	}
	st.sort();
	return st;
}
set set::union1(set s)
{
	set st;
	int i,j=0,k=0,l=0;
	set st2=intersect(s);
	for(i=0;i<n;i++)
	{
		st.ar[i]=ar[k++];
	}
	st.n=3;
	i=0;
	while(i<st2.n)
	{
		while(j<3)
		{
			if(st2.ar[i]==s.ar[j])
			{
				j++;
				break;
			}
			else
			{
				st.ar[k++]=s.ar[j];
				st.n=k;
			}
			j++;
		}
		i++;
	}
	if(i==st2.n)
	{
		for(l=j;l<3;l++)
		{
			st.ar[k++]=s.ar[l];
			st.n=k;
		}
	}
	st.sort();
	return st;
}
void set::display()
{
	int i;
	for(i=0;i<n;i++)
		cout<<ar[i]<<"\t";
	cout<<endl;
}
void set::sort()
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(ar[j]>ar[j+1])
			{	temp=ar[j];
				ar[j]=ar[j+1];
				ar[j+1]=temp;
			}
		}
	}
}
int main()
{
	int ch;
	set s1,s2,s3;       //default constructor
	do
	{
		cout<<"Menu:"<<endl;
		cout<<"1.Input\n2.Intersection\n3.Union\n4.Display"<<endl;
		cout<<"Enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter 1st set elements:";
				s1.input();
				cout<<"Enter 2nd set elements:";
				s2.input();
				break;
			case 2:
				cout<<"Intersection of two sets:"<<endl;
				s3=s1.intersect(s2);
				if(s3.getn()==0)
					cout<<"No elements!"<<endl;
				else
					s3.display();
				break;
			case 3:
				cout<<"Union of two sets:"<<endl;
				s3=s1.union1(s2);
				s3.display();
				break;
			case 4:
				cout<<"1st set elements:";
				s1.display();
				cout<<"2nd set elements:";
				s2.display();
				break;
		}
	}while(ch!=5);
	return 0;
}
