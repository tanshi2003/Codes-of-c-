#include<iostream>
using namespace std;
class inlinemc
{
	public:
		float mul(float x,float y);
		float cube(float x);
};
inline float inlinemc::mul(float x,float y)
{
	float i;
	i=x*y;
	return i;
}
inline float inlinemc::cube(float x)
{
	float i;
	i=x*x*x;
	return i;
}
int main()
{
	inlinemc i1;
	int ch;
	float k,x,y;
	do
	{
		cout<<"Menu:"<<endl;
		cout<<"1.Calculate multiplication\n2.Calculate cube\n3.Exit\n";
		cout<<"Enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"enter the value x:";
				cin>>x;
				cout<<"enter the value y:";
				cin>>y;
				k=i1.mul(x,y);
				cout<<"Multiplication="<<k<<endl;
				break;
			case 2:
				cout<<"enter the value of x:";
				cin>>x;
				k=i1.cube(x);
				cout<<"Cube="<<k<<endl;
				break;
		}
	}while(ch!=3);
	return 0;
}

