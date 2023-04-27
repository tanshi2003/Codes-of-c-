#include<stdio.h>
class check
{
	char ch;
public:
	bool input();
	bool isalpha();
	bool isalpha2();
	bool isspec();
	bool isdigit();
	int isvowel();
};
bool check::input()
{
//	char ch;
	printf("Enter a character:");
	scanf("%c",&ch);
}
bool check::isalpha()
{
	if((ch>=65)&&(ch<=90))
		return true;
	else
		return false;
}
bool check::isalpha2()
{
	if((ch>=97)&&(ch<=122))
		return true;
	else
		return false;
}
bool check::isdigit()
{
	if((ch>=48)&&(ch<=57))
		return true;
	else
		return false;
}
bool check::isspec()
{
	if(((ch<48)||(ch>57))&&((ch<65)||(ch>90))&&((ch<97)||(ch>122)))
		return true;
	else
		return false;
}
int check::isvowel()
{
	if(((ch>=65)&&(ch<=90))||((ch>=97)&&(ch<=122)))
	{
		if((ch=='a')||(ch=='e')||(ch=='i')||(ch=='o')||(ch=='u')||(ch=='A')||(ch=='E')||(ch=='I')||(ch=='O')||(ch=='U'))
			return 1;
		else
			return 2;
	}
	else
		return(3);
}
int main()
{
	int c;
	check c1;
	c1.input();
	do
	{
	printf("\nMenu:\n");
	printf("\n1.Alphabet\n2.Digit/special character\n3.Vowel\n4.Exit");
	printf("\nEnter your choice!");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			if(c1.isalpha()==true)
				printf("Its an upper case alphabet!");
			else if(c1.isalpha2()==true)
				printf("Its a lower case!");
			else
				printf("Its not an alphabet!");
			break;
		case 2:
			if(c1.isdigit()==true)
				printf("Its a digit!");
			else if(c1.isspec()==true)
				printf("Its a special character!");
			else
				printf("Its neither a digit nor a special character!");
			break;
		case 3:
			if(c1.isvowel()==1)
				printf("Its a vowel!");
			else if(c1.isvowel()==2)
				printf("Its a consonant!");
			else
				printf("Neither a vowel nor a consonant!");
			break;
	}
	}while(c!=4);
	return 0;
}
