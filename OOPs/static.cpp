#include<iostream>
using namespace std;
class staticExample
{
	int i;
	static int s;
	public:
		staticExample()
		{
			i=10;
			s=1;
		}
		staticExample(int x,int y)
		{
			i=x;
			s=y;
		}
		void display()
		{
			cout<<"i="<<i;
			cout<<"\ns="<<s<<endl;
		}
		static void test(int x)
		{
			s=x;
			staticExample t;
			t.i=10;
		}  
};
int staticExample::s;
int main()
{
	int x;
	staticExample obj1(10,20);
	cout<<"Case 1:"<<endl;
	obj1.display();
	staticExample obj2(100,200);
	obj2.display();
	obj1.display();
	cout<<"Case 2:"<<endl;
	cout<<"Enter the value of x:";
	cin>>x;
	obj1.test(x);
	obj1.display();
}
