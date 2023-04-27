#include<iostream>
class set
{
	int a,b,c;
	public:
		set()
		{
			a=1;
			b=1;
			c=1;
		}
		set(int x,int y,int z)
		{
			a=x;
			b=y;
			c=z;
		}
		set(&s);
		void intersect(set s);
		void union1(set s);
		void display();
		~set()
}
