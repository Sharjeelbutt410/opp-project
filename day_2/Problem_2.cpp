#include<iostream>
using namespace std;
class Employee 
{
	public:
		string empid;
		string name;
		int salary;
	Employee(string id,string n,int s)
	{
		empid = id;
		name = n;
		salary = s*12 ;
		cout<<"Employ id is \n"<<empid<<endl;
		cout<<"Name is \n"<<name<<endl;
		cout<<"Salary is \n"<<salary<<endl;
	}

};
int main()
{
	string emid,nam;
	int sal;
	cout<<"What is id of employee :"<<endl;
	getline(cin,emid);
	cout<<"What is your name : "<<endl;
	getline(cin,nam);
	cout<<"Salary : "<<endl;
	cin>>sal;
	cin.ignore();
	cout<<endl;
	Employee O1(emid,nam,sal);
	cout<<"\n Press enter to exit!\n";
	cin.get();
	return 0;
}
