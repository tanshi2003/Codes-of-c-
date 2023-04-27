//simple interest and compound interest
#include<iostream>
#include<math.h>
using namespace std;
class interest
{
	protected:
		float p,r,t;
	public:
		void input()
		{
			cout<<"Enter the value of principle:";
			cin>>p;
			cout<<"Enter the value of rate of interest:";
			cin>>r;
			cout<<"Enter the value of time:";
			cin>>t;
		}
		virtual float calcinterest();
};
class simpleinterest:public interest
{
	float si;
	public:
		float calcinterest()
		{
			void input();
			si=(p*r*t)/100;
			return si;
		}
};
class compoundinterest:public interest
{
	float ci,c;
	public:
		float calcinterest()
		{
			void input();
			c=p*(1+r);
			ci=pow(c,t);
			return ci;	
		}
};
int main()
{
//	interest i;
	interest *i;
	simpleinterest sm;
	compoundinterest cm;
	int ch;
	float s,c;
	do
	{
		cout<<"MENU:"<<endl;
		cout<<"1.Simple interest\n2.Compound interest\n";
		cout<<"Enter your choice:"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				i=&sm;
				i->calcinterest();
				cout<<"Simple interest"<<s<<endl;
				break;
			case 2:
				i=&cm;
				i->calcinterest();
				cout<<"Compound interest"<<c<<endl;
				break;
		}
	}while(ch!=3);
	return 0;	
}
