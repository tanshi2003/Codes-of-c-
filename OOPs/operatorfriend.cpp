
#include<iostream>
#include<math.h>
using namespace std;
class complex
{
	float real;
	float imag;
public: void input();
		void display();
		friend complex operator+(complex,complex);
		friend complex operator-(complex,complex);
		friend complex operator*(complex,complex);
		friend complex operator/(complex,complex);
		complex conjugate();
		float modulus();
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
complex operator+(complex c1,complex c2)
{
	complex t;
	t.real=c1.real+c2.real;
	t.imag=c1.imag+c2.imag;
	return t;
}
complex operator-(complex c1,complex c2)
{
	complex t;
	t.real=c1.real-c2.real;
	t.imag=c1.imag-c2.imag;
	return t;
}  
complex operator*(complex c1,complex c2)
{
	complex t;
	t.real=((c1.real*(c2.real))-(c1.imag*(c2.imag)));
	t.imag=(((c2.real)*c1.imag)+((c2.imag)*c1.real));
	return t;
}
complex operator/(complex c1,complex c2)
{
	complex t;
	t=operator*(c1,c2.conjugate());
	t.real=t.real/c2.modulus();
	t.imag=t.imag/c2.modulus();
	return t;
}
float complex::modulus()
{
	float mod;
	mod=(real*real)+imag*imag;
	return mod;
}
complex complex::conjugate()
{
	complex c;
	c.real=real;
	c.imag=(-1*imag);
	return c;
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
		//	c3=operator+(c1,c2);
			c3=c1+c2;
			cout<<"Addition Successful!"<<endl;
			break;
		case 4:
		//	c3=operator-(c1,c2);
			c3=c1-c2;
			cout<<"Subtraction Successful!"<<endl;
			break; 
		case 5:
		//	c3=operator*(c1,c2);
			c3=c1*c2;
			cout<<"Multiplication Successful!"<<endl;
			break; 
		case 6:
		//	c3=operator/(c1,c2);
			c3=c1/c2;
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
