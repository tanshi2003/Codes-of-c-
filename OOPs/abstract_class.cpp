//Abstract class program
#include<iostream>
using namespace std;
class person
{
	protected:
		char name[40];
	public:
		void getName()
		{
			cout<<"Enter name:\n ";
			cin>>name;
		}
		void putName()
		{
			cout<<"Name is "<<name<<endl;
		}
		virtual void getData()=0;
		virtual bool isOutstanding()=0;
};
class student:public person
{
	float gpa;
	public:
		void getData()
		{
			person::getName();
			cout<<"Enter student's GPA:";
			cin>>gpa;	
		}
		bool isOutstanding()
		{
			return(gpa>3.5)?true:false;
		}	
};
class professor:public person
{
	int numPubs;
	public:
		void getData()
		{
			person::getName();
			cout<<"Enter the professor's publications:";
			cin>>numPubs;
		}
		bool isOutstanding()
		{
			return(numPubs>100)?true:false;
		}
};
int main()
{
	person* persPtr[100];
	int n=0;
	char choice;
	do
	{
		cout<<"Enter Student or Professor(s/p):";
		cin>>choice;
		if(choice=='s')
			persPtr[n]=new student;
		else
			persPtr[n]=new professor;
		persPtr[n++]->getData();
		cout<<"Enter another(y/n):";
		cin>>choice;
	}while(choice=='y');
	for(int j=0;j<n;j++)
	{
		persPtr[j]->putName();
		if(persPtr[j]->isOutstanding())
			cout<<"This person is outstanding!"<<endl;
	}
	return 0;
}
