#include<iostream>
using namespace std;
class student{
	char name[15];
	int roll;
	int marks[5];
	float per;
	int sum;
	public : 
	void input();
    void cal_per();
	void display();
	void grade();
};
void student::input()
{	int i;
	cout<<"Enter students Name: ";
	cin>>name;
	cout<<"Enter the Roll number: ";
	cin>>roll;
	cout<<"Enter marks of 4 subjects ";
	for(i=0;i<4;i++)
//		cout<<"Enter marks of subject"<<i+1<<endl;
		cin>>marks[i];
		
}
void student :: cal_per()
{	int i;
	for(i=0;i<4;i++)
		sum+=marks[i];
	per=((sum)/4.000);	
}
void student::grade()
{
	if(per<33)
		cout<<"Fail"<<endl;
	else if(per>33&&per<48)
		cout<<"III Div"<<endl;
	else if(per>48&&per<59)
		cout<<"II Div"<<endl;
	else if(per>60&&per<75)
		cout<<"I Div"<<endl;
	else if(per>75&&per<=100)
		cout<<"Distinction"<<endl;
}
void student::display()
{	cout<<"The details of the student is:"<<endl;
	cout<<"Name: "<<name<<endl;
	cout<<"Roll number: "<<roll<<endl;
	cout<<"The total marks is:"<<sum<<endl;
	cout<<"The percentage of student is:"<<per<<endl;
	
}
int main()
{
	student sarr[10];
	int n,i;
	cout<<"Enter the no of students:";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter the details of student"<<i+1<<endl;
		sarr[i].input();
		sarr[i].cal_per();
		sarr[i].display();
		sarr[i].grade();
	}
	return 0;
}
