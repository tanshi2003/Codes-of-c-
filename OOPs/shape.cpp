#include<iostream>
using namespace std;
class Shape
{
	public:
	float Findarea(float l,float b)
	{
		return(l*b);
	}
	float Findarea(float s)
	{
		return(s*s);
	}
	float Findarea(int b,int h)
	{
		int r;
		r=0.5*b*h;
		return(r);
	}
	float Findarea(int r)
	{
		int a;
		a=3.14*r*r;
		return(a);
	}
};
int main()
{
	Shape s1;
	int ch,k;
	float l,br,s,b,h,r;
	do
	{
		cout<<"Menu:"<<endl;
		cout<<"1.Rectangle\n2.Square\n3.Triangle\n4.Circle\n5.Exit"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter the length:";
				cin>>l;
				cout<<"Enter the breadth:";
				cin>>br;
				k=s1.Findarea(l,br);
				cout<<"Area of rectangle:"<<k<<endl;
				break;
			case 2:
				cout<<"Enter the side:";
				cin>>s;
				k=s1.Findarea(s);
				cout<<"Area of square:"<<k<<endl;
				break;
			case 3:
				cout<<"Enter the base:";
				cin>>b;
				cout<<"Enter the height:";
				cin>>h;
				k=s1.Findarea(b,h);
				cout<<"Area of triangle:"<<k<<endl;
				break;
			case 4:
				cout<<"Enter the radius:";
				cin>>r;
				k=s1.Findarea(r);
				cout<<"Area of circle:"<<k<<endl;
				break;
		}
	}while(ch!=5);
}
