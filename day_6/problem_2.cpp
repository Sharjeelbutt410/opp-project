#include<iostream>
using namespace std;
//class Employee{
//	public:
//		 = 0;
//};
class  Employee{
	protected:
		string name;
		int age;
		string id;
		float basicsalary;
	public:
		Employee(string n,int a,string i)
		{
			name = n;
			age = a;
			id = i;
			basicsalary = 40000;
		}

		virtual void salary() = 0;
};
class permanentEmployee:public Employee{
	public:
		permanentEmployee(string n,int a,string i)
		:Employee(n,a,i)
		{
	
		}
		
		void salary()
		{
			cout<<"Permenant Employee Salary : "<<basicsalary * 3 <<endl;
		}
		
};
class contractEmployee:public Employee{

	public:
		contractEmployee(string n,int a,string i)
		:Employee(n,a,i)
		{

		}
		void salary()
		{
			
			cout<<"Contract Employee Salary : "<< basicsalary * 1.5 <<endl;
		}

};

int main()
{
	
	
	string name;
	int age;
	string id;
	
	//Permanent
	cout<<"-----Permanent Employee-----\n"<<endl;
	cout<<"Name : ";
	getline(cin,name);
	cout<<"Age : ";
	cin>>age;
	cout<<"ID : ";
	cin>>id;
	permanentEmployee p(name,age,id);
	p.salary();
	cin.ignore();
	
	//Contract
	cout<<"\n-----Contract Employee-----\n"<<endl;
	cout<<"Name : ";
	getline(cin,name);
	cout<<"Age : ";
	cin>>age;
	cout<<"ID : ";
	cin>>id;
	contractEmployee c(name,age,id);
	c.salary();
	
}
