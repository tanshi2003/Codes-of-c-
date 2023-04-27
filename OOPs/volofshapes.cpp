// volumes of shapes 
#include<iostream>
using namespace std;
class rectangle
{
	protected:
	float l,w,a,p;
	public:
		rectangle()
		{
			l=1;
			w=1;
			a,p=1;
		}
		void input1();
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
class cuboid:public rectangle
{
	float v,lg,b,h;
	public:
		void input();
		void display();
		cuboid()
		{
		lg,b,h,v=1;	
		}
		float volume();
};
void rectangle::input1()
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
void cuboid::input()
{
	cout<<"Enter the length:";
	cin>>lg;
	cout<<"Enter the breadth:";
	cin>>b;
	cout<<"Enter the height:";
	cin>>h;
}
void cuboid::display()
{
	cout<<"Volume of cuboid:";
	cout<<v<<endl;
}
float cuboid::volume()
{
	v=lg*b*h;
	return v;
}
int main()
{
	rectangle r;
	cuboid c;
	int ch,ch1,ch2;
	do
	{
		cout<<"MENU:"<<endl;
		cout<<"1.Rectangle\n2.Cuboid"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				do
				{
				cout<<"MENU:"<<endl;
				cout<<"1.Input\n2.Area\n3.Perimeter"<<endl;
				cout<<"Enter your choice:"<<endl;
				cin>>ch1;
				switch(ch1)
				{
					case 1:
						r.input1();
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
				}while(ch1!=4);
				break;
			case 2:
				do
				{
				cout<<"MENU:"<<endl;
				cout<<"1.Input\n2.Volume"<<endl;
				cout<<"Enter your choice:"<<endl;
				cin>>ch2;
				switch(ch2)
				{
					case 1:
						c.input();
						break;
					case 2:
						c.volume();
						c.display();
						break;
				}
				}while(ch2!=3);
				break;
		}
	}while(ch!=3);
	return 0;
}
