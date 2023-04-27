#include<iostream>
using namespace std;
class plot
{
	float length;
	float breadth;
	public: 
	void input();
	float fencing(float rate);
	float flooring(float rate);
};
void plot::input()
{
	cout<<"Enter the length:";
	cin>>length;
	cout<<"Enter the breadth:";
	cin>>breadth;
}
float plot::fencing(float rate)
{
	float l;
	l=(2*(length+breadth))*rate;
	return l;
}
float plot::flooring(float rate)
{
	float l;
	l=(length*breadth)*rate;
	return l;
}
int main()
{
	plot p1;
	int ch;
	float k,rate;
	do
	{
		cout<<"Menu:"<<endl;
		cout<<"1.Read length & breadth\n2.Calculate fencing\n3.Calculate flooring\n4.Exit\n";
		cout<<"Enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				p1.input();
				break;
			case 2:
				cout<<"enter the rate:";
				cin>>rate;
				k=p1.fencing(rate);
				cout<<"Cost="<<k<<endl;
				break;
			case 3:
				cout<<"enter the rate:";
				cin>>rate;
				k=p1.flooring(rate);
				cout<<"Cost="<<k<<endl;
				break;
		}
	}while(ch!=4);
	return 0;
}
