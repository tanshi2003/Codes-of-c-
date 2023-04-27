#include<iostream>
using namespace std;
class change
{
	public:
	float swap(int &a,int &b)
	{
		int t;
		t=a;
		a=b;
		b=t;
	}
	float swap(char &c,char &d)
	{
		char t;
		t=c;
		c=d;
		d=t;
	}
	float swap(float &m,float &n)
	{
		float t;
		t=m;
		m=n;
		n=t;
	}
};
int main()
{
	change c1;
	int ch,a,b;
	char c,d;
	float m,n;
	do
	{
		cout<<"Menu:"<<endl;
		cout<<"Swapping:"<<endl;
		cout<<"1.Integers\n2.Character\n3.Reals\n4.Exit"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter first no.:";
				cin>>a;
				cout<<"Enter second no.:";
				cin>>b;
				cout<<"Before swapped:"<<endl<<"1st:- "<<a<<endl<<"2nd:- "<<b<<endl;
				c1.swap(a,b);
				cout<<"After swapped:"<<endl<<"1st:- "<<a<<endl<<"2nd:- "<<b<<endl;
				break;
			case 2:
				cout<<"Enter first character:";
				cin>>c;
				cout<<"Enter second character:";
				cin>>d;
				cout<<"Before swapped:"<<endl<<"1st:- "<<c<<endl<<"2nd:- "<<d<<endl;
				c1.swap(c,d);
				cout<<"After swapped:"<<endl<<"1st:- "<<c<<endl<<"2nd:- "<<d<<endl;
				break;
			case 3:
				cout<<"Enter first real value:";
				cin>>m;
				cout<<"Enter second real value:";
				cin>>n;
				cout<<"Before swapped:"<<endl<<"1st:- "<<m<<endl<<"2nd:- "<<n<<endl;
				c1.swap(m,n);
				cout<<"After swapped:"<<endl<<"1st:- "<<m<<endl<<"2nd:- "<<n<<endl;
				break;
		}
	}while(ch!=4);
}
