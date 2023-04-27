#include<iostream>
using namespace std;
class list
{
	int arr[10];
	int n;
	public:
		list()
		{
			int i;
			for(i=0;i<10;i++)
				arr[i]=0;
		}
		list(int a[])
		{
			int i;
			for(i=0;i<10;i++)
				arr[i]=a[i];
		}
		void input();
		void display();
		friend void bubblesort(list &);
};
void list::input()
{
	int i;
	cout<<"Enter the no. of elements:";
	cin>>n;
	cout<<"Enter the no. of elements:";
	for(i=0;i<n;i++)
		cin>>arr[i];
}
void list::display()
{
	int i;
	cout<<"Elements are:";
	for(i=0;i<n;i++)
		cout<<arr[i]<<endl;
}
void bubblesort(list &l)
{
	int i,j,t;
	for(i=0;i<l.n-1;i++)
		for(j=0;j<l.n-i-1;j++)
			if(l.arr[j]>l.arr[j+1])
		 	{
				t=l.arr[j];
				l.arr[j]=l.arr[j+1];
				l.arr[j+1]=t;
		 	}
}
int main()
{
	int ch;
	list l1;
	do
	{
		cout<<"Menu:"<<endl;
		cout<<"1.Input\n2.Bubble sort\n3.Display\n4.Exit"<<endl;
		cout<<"Enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				l1.input();
				break;
			case 2:
				bubblesort(l1);
				l1.display();
				break;
			case 3:
				l1.display();
				break;
		}
	}while(ch!=4);
	return 0;
}
