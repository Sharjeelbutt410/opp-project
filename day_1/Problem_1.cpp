#include<iostream>
using namespace std;

int addition(int a,int b)
{
	int sum=0;
	sum=a+b;
	return sum;
}
int subtraction(int a,int b)
{
	int sub=0;
	sub=a-b;
	return sub;
}
int multiplication(int a,int b)
{
	int mul=1;
	mul=a*b;
	return mul;
}
int division(int a,int b)
{
	if(a,b!=0)
	{
	int div=a/b;
	return div;
	}
	else
	cout<<"Invalid!";
	return 0;
}

int main()
{
	int num1,num2; 
	char op;
	char choice;
	cout<<"\n Simple Calculator\n"<<endl;
	do
	{
	cout<<"Enter first number: ";
	cin>>num1;
		cout<<"Enter operation [ +,-,*,/ ] : ";
	cin>>op;
	cout<<"Enter second number: ";
	cin>>num2;
	switch(op)
{
	case '+':
	{
		cout<<addition(num1,num2)<<endl;
		break;
	}
	case '-':
	{
		cout<<subtraction(num1,num2)<<endl;
		break;
	}
	case '*':
	{
		cout<<multiplication(num1,num2)<<endl;
		break;
	}
	case '/':
	{
		cout<<division(num1,num2)<<endl;
		break;
	}
	default:
	{
		cout<<"Invalid! Try again";
	}

}
	cout<<"Do you want to perform another calculation (Y or N): "<<endl;
	cin>>choice;
	}while(choice=='Y'|| choice =='y');
	
	cout<<"Thanks for calculating";
	
}


