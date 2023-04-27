#include<iostream>
#include<string.h>
using namespace std;
class Student
{
	protected:
		int regno;
		int marks[3];
	public:
		Student()       //default constructor
		{
			regno=1;
			int i;
			for(i=0;i<3;i++)	
				marks[i]=30;
		}
		Student(int reg,int* m)             //parametrized constructor
		{
			regno=reg;
			int i;
			for(i=0;i<3;i++)
				marks[i]=m[i];
		}
		void Input()
		{
			int i;
			cout<<"Enter the registration number: ";
			cin>>regno;
			cout<<"Enter marks for 3 subjects out of 100: "<<endl;
			for(i=0;i<3;i++)
			{
				cout<<"Enter marks for sub"<<i+1<<": ";
				cin>>marks[i];
			}		
		}
		float Average()
		{
			int i;
			float avg=0;
			for(i=0;i<3;i++)
				avg+=marks[i];
			avg=avg/3.0;
			return avg;			
		}		
};
class Result:public Student
{
	public:
		Result()
		{			
		}
		Result(int reg,int* m):Student(reg,m)
		{
		}
	string functioncal_result(int min)
	{
		int i;
		for(i=0;i<3;i++)
		{
			if(marks[i]<min)
				break;
		}
		if(i==3)
			return "PASS";
		else 
			return "Not Passed";
	}
	void functioncal_result(int min, int merit)
	{	if(functioncal_result(min)=="PASS" && Average()>merit)
		{
			cout<<"MERIT RECEIVED\n";
		}
		else{
			cout<<"NO MERIT RECEIVED"<<endl;
		}
	}
};
int main()
{
	int ch,min,merit,i;
	Result R1;
	do
	{
		cout<<"MENU"<<endl;
		cout<<"1.Input\n2.Result\n3.Merit\n4.Exit\n";
		cout<<"Enter a choice: "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter the details : "<<endl;
				R1.Input();
				break;
			case 2:
				cout<<"Enter the minimum marks to pass: ";
				cin>>min;
				cout<<"Average: "<<R1.Average()<<endl;
				cout<<"Result: "<<R1.functioncal_result(min)<<endl;;
				break;
			case 3:
				cout<<"Enter the minimum marks to pass: ";
				cin>>min;
				cout<<"Enter the merit marks: ";
				cin>>merit;
			//	cout<<"Eligible for Merit?"<<endl;
				R1.functioncal_result(min,merit);
				break;					
		}		
	}while(ch!=4);
	
}


