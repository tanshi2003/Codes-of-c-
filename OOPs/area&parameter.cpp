// area and parameter
#include<iostream>
using namespace std;
class rectangle
{
	float l,w,a,p;
	public:
		rectangle()
		{
			l=1;
			w=1;
		}
		void input();
		void display1();
		void display2();
		float area();
		float perimeter();
		float getl()           //get method
		{
			return l;
		}
		float getw()
		{
			return w;
		}
		void setl(float le)    //set method
		{
			l=le;
		}
		void setw(float wi)
		{
			l=wi;
		}
};
void rectangle::input()
{
	cout<<"Enter the length:";
	cin>>l;
	cout<<"Enter the width:";
	cin>>w;
}
void rectangle::display1()
{
	cout<<"Area of rectangle:";
	cout<<a<<endl;
}
void rectangle::display2()
{
	cout<<"Perimeter of rectangle:";
	cout<<p<<endl;
}
float rectangle::area()
{
	a=l*w;
	return a;
}
float rectangle::perimeter()
{
	p=2*(l+w);
	return p;
}
int main()
{
	rectangle r;
	int ch;
	do
	{
		cout<<"MENU:"<<endl;
		cout<<"1.Input\n2.Area\n3.Perimeter"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				r.input();
				break;
			case 2:
				if(((r.getl()>0.0)&&(r.getl()<20.0))&&((r.getw()>0.0)&&(r.getw()<20.0)))
				{
					r.area();
					r.display1();
				}
				else
					cout<<"Invalid inputs!"<<endl;
				break;
			case 3:
				if(((r.getl()>0.0)&&(r.getl()<20.0))&&((r.getw()>0.0)&&(r.getw()<20.0)))
				{
					r.perimeter();
					r.display2();
				}
				else
					cout<<"Invalid inputs!"<<endl;
				break;	
		}
	}while(ch!=4);
	return 0;
}
