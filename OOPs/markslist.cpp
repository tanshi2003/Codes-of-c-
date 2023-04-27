#include<iostream>
using namespace std;
class studentmarks{
	int regno;
//	int s1,s2,s3;
	int marks[];
	int avg;
	int sum;
	public : 
	void input();
    void cal_avg();
	void display();
	studentmarks()
	{
		regno=1;
//		s1=1;
//		s2=1;
//		s3=1;
		avg=0;
		sum=0;
//		marks[3]={};
	}
};
void studentmarks::input()
{	int i;
	cout<<"Enter students Registration no.: ";
	cin>>regno;
//	cout<<"Enter marks of 3 subjects:"<<endl;
	for(i=0;i<3;i++)
	{
		cout<<"Enter marks of subject "<<i+1<<endl;
		cin>>marks[i];
	}
		
}
void studentmarks::cal_avg()
{	int i;
	for(i=0;i<3;i++)
		sum+=marks[i];
	avg=((sum)/3);
}
void studentmarks::display()
{
	int i;
	cout<<"The marks list of the student is:"<<endl;
	cout<<"Registration no.: "<<regno<<endl;
	for(i=0;i<3;i++)
	{
		cout<<"Marks of subject "<<i+1<<":";
		cout<<marks[i]<<endl;
	}
	cout<<"The average marks of student is:"<<avg<<endl;
	
}
int main()
{
	studentmarks sarr[10];
	int n,i;
	cout<<"Enter the no of students:";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter the details of student"<<i+1<<endl;
		sarr[i].input();
		sarr[i].cal_avg();
		sarr[i].display();
	}
	return 0;
}
