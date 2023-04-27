#include<iostream>
#include<iomanip>
#define max 20
using namespace std;
class StudentMarks
{
	int reg;
	float s[max];
	float avg;
	public:
		void input();
		void display();
		float avgr();
		Studentmarks()
		{
			int i;
			reg=0;
			for(i=1;i<=3;i++)
				s[i]=1;
			avg=0.0;
		}
};
void StudentMarks::input()
{
	int i;
	cout<<"Enter the registration no.:"<<endl;
	cin>>reg;
	cout<<"Enter the marks of 3 subjects:"<<endl;
	for(i=1;i<=3;i++)
	{
		cout<<"Subject "<<i<<":"<<endl;
		cin>>s[i];
	}
}
void StudentMarks::display()
{
	int i;
	float r;
	cout<<"Registration no.:";
	cout<<reg<<endl;
	cout<<"Subject    "<<"Maximum Marks "<<"Obtained Marks\n";
	for(i=1;i<=3;i++)
		cout<<"Subject-:"<<i<<"->"<<setw(10)<<"100"<<setw(10)<<s[i]<<endl;
	r=avgr();
	cout<<"Average value:"<<r; 
}
float StudentMarks::avgr()
{
	int sm=0;
	int i;
	for(i=1;i<=3;i++)
	{
		sm=sm+s[i];
	}
	avg=sm/3.0;
	return avg;
}
int main()
{
	StudentMarks ss;
	int ch;
	float k;
	do
	{
		cout<<"\nMenu:"<<endl;
		cout<<"1.Input\n2.Calculate average\n3.Output\n4.Exit"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				ss.input();
				break;
			case 3:
				ss.display();
				break;
			case 2:
				k=ss.avgr();
				cout<<"Average calculated successfully!"<<endl;
				break;
		}
	}while(ch!=4);
}
