// matrix
#include<iostream>
using namespace std;
class matrix
{
	int arr[5][5],r,c;
	public:
		matrix()
		{	
			int i,j;
			r=c=3;
			for(i=0;i<r;i++)
				for(j=0;j<c;j++)
					arr[i][j]=1;
		}
		void input();
		void display();
		matrix operator+(matrix m);
		matrix operator-(matrix m);
		matrix operator*(matrix m);
		friend ostream & operator <<(ostream &, matrix );
		friend istream & operator >>(istream &,matrix &);
		int getr()
		{
			return r;
		}
		int getc()
		{
			return c;
		}
};
istream & operator >>(istream &in,matrix &m)
{
	int i,j;
	cout<<"Enter your matrix elements:"<<endl;
	for(i=0;i<m.r;i++)
		for(j=0;j<m.c;j++)
			in>>m.arr[i][j];		
}
ostream & operator <<(ostream &out, matrix m)
{
	int i,j;
	out<<"Your resultant matrix elements are:"<<endl;
	for(i=0;i<m.r;i++)
	{
		for(j=0;j<m.c;j++)
			out<<m.arr[i][j]<<"\t";
		out<<"\n";
	}
}
void matrix::input()
{
	int i,j;
	cout<<"Enter no. of rows:";
	cin>>r;
	cout<<"Enter no. of columns:";
	cin>>c;
	cout<<"Enter your matrix elements:"<<endl;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			cin>>arr[i][j];
}
void matrix::display()
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			cout<<arr[i][j]<<"\t";
		cout<<"\n";
	}
}
matrix matrix::operator+(matrix m)
{
	int i,j;
	matrix t;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			t.arr[i][j]=arr[i][j]+m.arr[i][j];
	t.r=r;
	t.c=c;
	return t;
}
matrix matrix::operator-(matrix m)
{
	int i,j;
	matrix t;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			t.arr[i][j]=arr[i][j]-m.arr[i][j];
	t.r=r;
	t.c=c;
	return t;
}
matrix matrix::operator*(matrix m)
{
	int i,j,k;
	matrix t;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			t.arr[i][j]=0;
			for(k=0;k<c;k++)
				t.arr[i][j]=t.arr[i][k]+(arr[k][j]+m.arr[i][j]);
		}
	}
	t.r=r;
	t.c=c;
	return t;		
}
int main()
{
	matrix m1,m2,m3;
	int ch;
	do
	{
		cout<<"\nMenu:"<<endl;
		cout<<"1.Input\n2.Sum\n3.Subtraction\n4.Multiplication\n5.Display\n6.Exit"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				m1.input();
				m2.input();
				break;
			case 2:
				if(m1.getr()==m2.getr()&& m1.getc()==m2.getc())
				{
					m3=m1+m2;
					cout<<"Addition successful!";
				}
				else
					cout<<"No addition performed!";
				break;
			case 3:
				if(m1.getr()==m2.getr()&& m1.getc()==m2.getc())
				{
					m3=m1-m2;
					cout<<"Addition successful!";
				}
				else
					cout<<"No subtraction performed!";
				break;
			case 4:
				if(m1.getc()==m2.getr())
				{
					m3=m1*m2;
					cout<<"Multiplication successful!";
				}
				else
					cout<<"No multiplication performed!";
				break;
			case 5:
				cout<<"First matrix:"<<endl;
				m1.display();
				cout<<"Second matrix:"<<endl;
				m2.display();
				cout<<"Your resultant matrix elements are:"<<endl;
				m3.display();
				break;
		}
	}while(ch!=6);
}
