#include<iostream>
using namespace std;
class complex
{
	float real;
	int imag;
public: void input();
		void display();
		complex add(complex c);
		complex sub(complex c);
		complex mul(complex c);
		complex div(complex c);
};
void complex::input()
{
	cout<<"Enter the real part:";
	cin>>real;
	cout<<"Enter the imaginary part:";
	cin>>imag;
}
void complex::display()
{
	if(imag>0)
		cout<<real<<"+i"<<imag<<endl;
	else if(imag==0) 
		cout<<real<<endl;
	else
		cout<<real<<imag<<"i"<<endl;	
}
complex complex::add(complex c)
{
	complex t;
	t.real=real+c.real;
	t.imag=imag+c.imag;
	return t;
}
complex complex::sub(complex c)
{
	complex t;
	t.real=real-c.real;
	t.imag=imag-c.imag;
	return t;
}  
complex complex::mul(complex c)
{
	complex t;
	t.real=(real*(c.real))-(imag*(c.imag));
	t.imag=((c.real)*imag)+((c.imag)*real);
}
complex complex::div(complex c)
{
	
}
int main()
{
	int ch;
	complex c1,c2,c3;
	do
	{
	cout<<"Menu";
	cout<<"\n1.Input 1st complex number\n2.Input 2nd complex number\n3.Addition\n4.Subtraction\n5.Multiplication\n6.Division\n7.Display 1st complex no.\n8.Display 2nd complex no.\n9.Result\n10.Exit"<<endl;
	cout<<"Enter your choice:";
	cin>>ch;
	switch(ch)
	{
		case 1:
			c1.input();
			break;
		case 2:
			c2.input();
			break;
		case 3:
			c3=c1.add(c2);
			cout<<"Addition Successful!"<<endl;
			break;
		case 4:
			c3=c1.sub(c2);
			cout<<"Subtraction Successful!"<<endl;
			break; 
		case 5:
			c3=c1.mul(c2);
			cout<<"Multiplication Successful!"<<endl;
			break; 
		case 6:
			c3=c1.div(c2);
			cout<<"Division successful!"<<endl;
			break;
		case 7:
			cout<<"1st complex:";
			c1.display();
			break;
		case 8:
			cout<<"2nd complex:";
			c2.display();
			break;
		case 9:
			cout<<"Result:";
			c3.display();
			break;
	}
    }while(ch!=10);
    return 0;
}
