#include<iostream>
#include<string>
#include<vector>
using namespace std;

class student
{
private:
	
	int age;
	float marks;
	
public: 
	student(int m,float a)
	{
		setage(a);
		setmarks(m);
	}
	void setmarks(float m)
	{
		if(m>=0 && m<=100)
		{
			marks = m;
		}
		else
		{
			cout<<"\n Invalid Marks! \n"<<endl;
		}
	}
	void setage(int a)
	{
		if(a>=16 && a<=40)
		{
			age = a;
		}
		else
		{
			cout<<"\n Invalid age! \n"<<endl;
		}
	}
	void display()
	{
		cout<<"Marks :"<<marks<<endl;
		cout<<"Age : "<<age<<endl;
	}


	
};
int main()
{
	student s1;
	int a;
	float m;
	cout<<"Enter marks : ";
	cin>>m;
	cout<<"Enter age : ";
	cin>>a;
	s1 student(m,a)
}
