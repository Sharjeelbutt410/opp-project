#include<iostream>
using namespace std;
int primeno(int n)
{
	int test= 1;
	if(n<=1)
	{
	return	test =0 ;
	}
	else
	{
		for(int i=2; i<n; i++)
		{
			if(n%i==0)
			{
			return	test = 0;
				
			}
			
		}
	}

}
double factorial(double n)
{
	double fact=1;
	for(int i=1; i<=n; i++)
	{
		fact*=i;
	}
	return fact;
}
double fibonacci(int n)
{
	int first = 0;
	int second = 1;
	int next;
	for(int i=0; i<n; i++)
	{
		cout<<first<<" ";
		next = first + second;
		first = second;
		second = next;
		
	}
}
int gcf(int a,int b)
{
	int c;
	while(b!=0)
	{
		c=b;
		b=a%b;
		a=c;
	}
	return a;
	
}
int lcm(int a,int b)
{
	int c = gcf(a,b);
	int lcmofno = (a*b)/c;
	return lcmofno;
}

int main()
{
	double num1,num2;
	cout<<"Enter two numbers : "<<endl;
	cin>>num1>>num2;
	
	//PRIME OR NOT

	int prime = primeno(num1);
	if(prime !=0)
	{
		cout<<num1<<" is prime number.\n"<<endl;
		
	}
	else
	{
		cout<<num1<<" is not a prime number. \n"<<endl;
	}
	int	 prime2 = primeno(num2);
	if(prime2 !=0)
	{
		cout<<num2<<" is prime number.\n"<<endl;
		
	}
	else
	{
		cout<<num2<<" is not a prime number. \n"<<endl;
	}

	//FACTORIAL
	
	cout<<"Factorial of "<<num1<<" is : "<<factorial(num1)<<endl;
	cout<<"Factorial of "<<num2<<" is : "<<factorial(num2)<<endl;	
	
	//FIBONACCI SERIES

	cout<<"Fibonacci series of "<<num1 <<" is : "<<endl;
	fibonacci(num1);
	cout<<"\n";
	cout<<"Fibonacci series of "<<num2 <<" is : "<<endl;
	fibonacci(num2);
	cout<<"\n";

	//GCF

	cout<<"Gcf is \n"<<gcf(num1,num2)<<endl;

	//LCM

	cout<<"Lcm is \n"<<lcm(num1,num2)<<endl;	
	
}
