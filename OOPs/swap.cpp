#include<iostream>
using namespace std;
class swapp
{
	int a,b;
	char c,d;
	public:
		void swapnum();
		void swapalpha();
		void swapreal();
		void display();
		swap()
		{
			a=1;
			b=1;
		}
		swap(int a1,int b1)
		{
			a=a1;
			b=b1;
		}
};
void swapp::swapnum()
{
	int c;
	cout<<"Enter first no.:"<<endl;
	cin>>a;
	cout<<"Enter second no.:"<<endl;
	cin>>b;
	c=a;
	a=b;
	b=c;
}
void swapp::swapalpha()
{
	char a;
	a=c;
	c=d;
	d=a;
}
void swapp::swapreal()
{
	
}
void swapp::display()
{
	cout<<"First number:"<<endl;
	cout<<a;
	cout<<"Second number:"<<endl;
	cout<<b;
}
int main()
{
	swapp i;
	int ch;
	do
	{
		cout<<"Menu:"<<endl;
		cout<<"1.Swap numbers\n2.Swap character\n3.Swap real\n4.Display\n5.Exit"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				i.swapnum();
				break;
			case 2:
				i.swapalpha();
				break;
			case 3:
				i.swapreal();
				break;
			case 4:
				i.display();
				break;
		}
	}while(ch!=5);
	return 0;
}
