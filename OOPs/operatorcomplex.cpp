// complex number add. sub.
#include<iostream>
#include<math.h>
using namespace std;
class complex
{
	float real;
	float imag;
public: void input();
		void display();
		complex operator+(complex c);
		complex operator-(complex c);
		complex operator*(complex c);
		complex operator/(complex c);
		complex conjugate();
		float modulus();
		friend ostream & operator <<(ostream &, complex );
		friend istream & operator >>(istream &,complex &);
};
istream & operator >>(istream &in,complex &c)
{
	cout<<"Enter the real part:";
	in>>c.real;
	cout<<"Enter the imaginary part:";
	in>>c.imag;
	return in;
}
ostream & operator <<(ostream &out, complex c)
{
	if(c.imag>0)
		out<<c.real<<"+i"<<c.imag<<endl;
	else if(c.imag==0) 
		out<<c.real<<endl;
	else
		out<<c.real<<c.imag<<"i"<<endl;
}
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
complex complex::operator+(complex c)
{
	complex t;
	t.real=real+c.real;
	t.imag=imag+c.imag;
	return t;
}
complex complex::operator-(complex c)
{
	complex t;
	t.real=real-c.real;
	t.imag=imag-c.imag;
	return t;
}  
complex complex::operator*(complex c)
{
	complex t;
	t.real=((real*(c.real))-(imag*(c.imag)));
	t.imag=(((c.real)*imag)+((c.imag)*real));
	return t;
}
complex complex::operator/(complex c)
{
	complex t;
	t=operator*(c.conjugate());
	t.real=t.real/c.modulus();
	t.imag=t.imag/c.modulus();
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
	cout<<"\n1.Input 1st complex number\n2.Input 2nd complex number\n3.Addition\n4.Subtraction\n5.Multiplication\n6.Division\n
	7.Display 1st complex no.\n8.Display 2nd complex no.\n9.Result\n10.Exit"<<endl;
	cout<<"Enter your choice:";
	cin>>ch;
	switch(ch)
	{
		case 1:
			c1.input();    //cin>>c1;
			break;
		case 2:
		//	c2.input();    
			cin>>c2;
			break;
		case 3:
		//	c3=c1.operator+(c2);
			c3=c1+c2;
			cout<<"Addition Successful!"<<endl;
			break;
		case 4:
			//c3=c1.operator-(c2);
			c3=c1-c2;
			cout<<"Subtraction Successful!"<<endl;
			break; 
		case 5:
		//	c3=c1.operator*(c2);
			c3=c1*c2;
			cout<<"Multiplication Successful!"<<endl;
			break; 
		case 6:
		//	c3=c1.operator/(c2);
			c3=c1/c2;
			cout<<"Division successful!"<<endl;
			break;
		case 7:
			cout<<"1st complex:";
			c1.display();       //cout<<c1;
			break;
		case 8:
			cout<<"2nd complex:";
		//	c2.display();       
			cout<<c2;
			break;
		case 9:
			cout<<"Result:";
			c3.display();       //cout<<c3;
			break;
	}
    }while(ch!=10);
    return 0;
}
