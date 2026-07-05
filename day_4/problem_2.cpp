#include<iostream>
#include<string>
using namespace std;

class Employee
{
	protected:
		string name;
		string id;
		float basicsalary;
	Employee(string n,string d)
	{
		name = n;
		id = d;
		basicsalary = 40000;
	}
	void display()
	{
		cout<<"Employee Name : "<<name<<endl;
		cout<<"Employee Id : "<<id<<endl;
		cout<<"Basic : "<<basicsalary<<endl;
	}
};
class Manager:public Employee
{
	private:
		float bonus;
		float total;
	public:

	Manager(string n,string id,float bo)
	:Employee(n,id)
	{
		bonus += bo;
	}
	void calculatesalary()
	{
		total = basicsalary + bonus;
		
		display();
		cout<<"Bonus : "<<bonus<<endl;
		cout<<"Manager Salary : "<<total<<endl;
		
	}
};
class Developer:public Employee
{
	private:
		float overtime;
		float total;
	public:
	Developer(string n,string id,int ov)
	:Employee(n,id)
	{
		overtime = ov ;
	}
	void calculatesalary()
	{
		total = basicsalary + (overtime * 500);
		
		display();
		cout<<"Overtime :"<<overtime<<endl;
		cout<<"Toatl  : "<<total<<endl;
	}
};

int main()
{
	string name;
	string id;

		cout<<"Employee Name : ";
		getline(cin,name);
		cout<<"Employee Id : ";
		getline(cin,id);
		cout<<"\n===Manager===\n"<<endl;
		Manager m(name,id,10000);
		m.calculatesalary();
		
		cout<<"\n"<<endl;
		cout<<"Employee Name : ";
		getline(cin,name);
		cout<<"Employee Id : ";
		getline(cin,id);
		cout<<"\n===Developer===\n"<<endl;
		Developer d(name,id,8);
		d.calculatesalary();
}
