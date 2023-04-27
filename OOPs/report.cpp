#include<iostream>
#include<iomanip>
using namespace std;
class Student
{
	int rollNo;
	int marks[5];
	char name[20];
	float per;
	int s;
public :void input();
	void display();
	void cal_per();
	void grade();
};
typedef struct Student LIST;
void LIST::input()
{
	int i;
	fflush(stdin);
	cout<<"Enter name of student:\n";
	cin>>name;
	cout<<"Enter Roll Number:\n";
	cin>>rollNo;
	for(i=0;i<5;i++)
	{
		cout<<"Enter marks in subject-"<<i+1<<endl;
		cin>>marks[i];
	}
}
void LIST::cal_per()
{	int i,sum;
	for(i=0;i<5;i++)
		sum+=marks[i];
	s=sum;
	per=((sum)/5.000);	
}
void LIST::grade()
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
void LIST::display()
{
	int i;
	cout<<"Name:"<<setw(13)<<name<<endl;
//	cout<<name<<endl;
	cout<<"Roll No.:"<<setw(10)<<rollNo<<endl;
	cout<<"Subject    "<<"Maximum Marks "<<"Obtained Marks\n";
	for(i=0;i<5;i++)
	 cout<<"Subject-:"<<i+1<<"->"<<setw(10)<<"100"<<setw(10)<<marks[i]<<endl;
	cout<<"The total marks is:"<<s<<endl;
	cout<<"Percentage:"<<setw(10)<<per<<endl;
}
int main()
{
	int i,n;
	LIST s[5];
	cout<<"Enter no. of student:";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter the Details of Student-"<<i+1<<endl;
		s[i].input();
		fflush(stdin);
		s[i].cal_per();
		cout<<"Details of student-"<<i+1<<endl;
		s[i].display();
		s[i].grade();
	}
	return 0;
}
