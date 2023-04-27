//postfix prefix
#include<iostream>
using namespace std;
class unary
{
	int i,j;
	public:
		unary()
		{
			i=1;
			j=1;
		}
		unary(int x,int y)
		{
			i=x;
			j=y;
		}
		void input()
		{
			cout<<"Enter the value of i:"<<endl;
			cin>>i;
			cout<<"Enter the value of j:"<<endl;
			cin>>j;
		}
		void display()
		{
			cout<<"i"<<"="<<i<<endl;
			cout<<"j"<<"="<<j<<endl;
		}
		unary operator--();
		friend unary operator--(unary &,int);
		bool operator <(const unary);
		friend bool operator ==(const unary,const unary);
};
unary unary::operator--()
{
	unary t;
	t.i=--i;
	t.j=--j;
	return t;
}
unary operator--(unary &obj,int)
{
	unary t;
	t.i=obj.i;
	obj.i--;
	t.j=obj.j;
	obj.j--;
	return t;
}
bool unary::operator<(const unary t)
{
	if(i<t.i && j<t.j)
			return true;
	else
		return false;
}
bool operator==(const unary u1,const unary u2)
{
	return(u1.i==u2.i && u1.j==u2.j);
}
int main()
{
	unary obj1,obj2,obj3;
	int ch;
	do
	{
		cout<<"\nMENU:"<<endl;
		cout<<"1.Input\n2.Prefix\n3.Postfix\n4.Less than\n5.Equal to\n6.Exit"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				obj1.input();
			//	obj3.input();
				break;
			case 2:
				obj2=--obj1;
				cout<<"\nobject 1:";
				obj1.display();
				cout<<"\nobject 2:";
				obj2.display();
				break;
			case 3:
				obj2=obj1--;
				cout<<"\nobject 1:";
				obj1.display();
				cout<<"\nobject 2:";
				obj2.display();
				break;
			case 4:
				obj1.input();
				obj3.input();
				if(obj1<obj3)
					cout<<"\nObject 1 is less than Object 2!";
				else
					cout<<"\nObject 2 is less than Object 1!";
				break;
			case 5:
				obj1.input();
				obj3.input();
				if(obj1==obj3)
					cout<<"\nBoth are equal!";
				else
					cout<<"\nBoth are not equal!";
				break;
		}
	}while(ch!=6);
	return 0;
}
