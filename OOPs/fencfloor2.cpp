#include<iostream>
using namespace std;
class plot
{
	float length;
	float breadth;
	public:
	plot()
	{
	}
  	plot(float l,float b)
	{
		length=l;
		breadth=b;
	}
	void input();
	float fencing(float rate);
	float flooring(float rate);
	float rate();
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
	int ch,c;
	float k,rate,l,b;
	do 
	{
		cout<<"Menu:"<<endl;
		cout<<"1.By default object\n2.By parametrized object\n3.Exit"<<endl;
		cout<<"Enter your choice:";
		cin>>c;
		switch(c)
		{
			case 1:	do
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
								cout<<"Cost of fencing="<<k<<"Rs/m"<<endl;
								break;
							case 3:
								cout<<"enter the rate:";
								cin>>rate;
								k=p1.flooring(rate);
								cout<<"Cost of flooring="<<k<<"Rs/m^2"<<endl;
								break;
						}
					}while(ch!=4);
					break;
			case 2:
				cout<<"Enter the length for parametrize object:";
				cin>>l;
				cout<<"Enter the breadth for parametrize object:";
				cin>>b;
				plot p2(l,b);
				do
					{
					cout<<"Menu:"<<endl;
					cout<<"1.Calculate fencing\n2.Calculate flooring\n3.Exit\n";
					cout<<"Enter your choice:";
					cin>>ch;
					switch(ch)
						{
							case 1:
								cout<<"enter the rate:";
								cin>>rate;
								k=p2.fencing(rate);
								cout<<"Cost of fencing="<<k<<"Rs/m"<<endl;
								break;
							case 2:
								cout<<"enter the rate:";
								cin>>rate;
								k=p2.flooring(rate);
								cout<<"Cost of flooring="<<k<<"Rs/m^2"<<endl;
								break;
						}
					}while(ch!=3);
					break;
	}
	}while(ch!=3);
	return 0;
}
