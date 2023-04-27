#include<iostream>
#include<iomanip>
using namespace std;
class employee
{
	int age;
	string depart;
	string name;
	float salary;
	int net;
public :void input();
	void display();
	void cal_sal();
};
void employee::input()
{
	int i;
	fflush(stdin);
	cout<<"Enter name of employee:\n";
	cin>>name;
	cout<<"Enter Age:\n";
	cin>>age;
	cout<<"Enter department:\n";
	cin>>depart;
	fflush(stdin);
}
void employee::cal_sal()
{
	int bs;
	float da,hra,med;
	int tax,pf;
	int gr; 
	cout<<"Enter base salary:"<<endl;
	cin>>bs;
	cout<<"Enter DA %:"<<endl;
	cin>>da;
	cout<<"Enter HRA %:"<<endl;
	cin>>hra;
	cout<<"Enter Medical Allowance %:"<<endl;
	cin>>med;
	cout<<"Enter tax deduction %:"<<endl;
	cin>>tax;
	cout<<"Enter Pf %"<<endl;
	cin>>pf;
	gr=bs+((bs*da)/100)+((bs*hra)/100)+((bs*med)/100);
	net=gr-(((bs*tax)/100)+((bs*pf)/100));
}
void employee::display()
{
	cout<<"Name of employee:";
	cout<<name;
	cout<<"\nAge:"<<age<<endl;
	cout<<"Enter department:"<<depart<<endl;
	cout<<"Net salary:"<<net<<endl;
}
int main()
{
	int i,n;
	employee s[10];
	cout<<"Enter no. of employee:";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter the Details of employee-"<<i+1<<endl;
		s[i].input();
		fflush(stdin);
		s[i].cal_sal();
		cout<<"Details of employee-"<<i+1<<endl;
		s[i].display();
	}
	return 0;
}
