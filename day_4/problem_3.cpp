#include<iostream>
#include<string>
using namespace std;

class Person{
	protected:
		string name;
		int age;
		string phoneno;
	public:
	Person(string n,int a,string no)
	{
		name = n;
		age = a;
		phoneno = no;
	}
	void display()
	{
		cout<<"Name : "<<name<<endl;
		cout<<"Age : "<<age<<endl;
		cout<<"Phone no : "<<phoneno<<endl;
	}
};
class Student: public Person{
	private:
		string regno;
		string section;
		string department;
		string degree;
	public:
		Student(string n,int a,string no,string reg,string dep,string sec,string deg)
		:Person(n,a,no)
		{
			regno = reg;
			department = dep;
			section = sec;
			degree = deg;
		}
	void displaystudent()
	{
		display();
		cout<<"Registration no : "<<regno<<endl;
		cout<<"Department : "<<department<<endl;
		cout<<"Degree : "<<degree<<endl;
		cout<<"Section : "<<section<<endl;
	}
};
class Teacher:public Person{
	private:
		int id;
		string department;
		string desigination;
	public:
		Teacher(string n,int a,string no,string dep,string des)
		:Person(n,a,no)
		{
			department = dep;
			desigination = des;
		}
	void displayteacher()
	{
		display();

		cout<<"Department : "<<department<<endl;
		cout<<"Desigination : "<<desigination;
	}
};
class Principal:public Person{
	private:
		string campus;
	public:
		Principal(string n,int a,string no,string camp)
		:Person(n,a,no)
		{
			campus = camp;
		}
	void displayprincipal()
	{
		display();
		cout<<"Campus : "<<campus<<endl;
	}
};

int main()
{
	string name;
	int age;
	string phoneno;
	string regno;
	string department;
	string section;
	string degree;
	string desigination;
	string campus;
	
	//Student
	
	cout<<"\n ===For Students=== \n"<<endl;
	
	cout<<"Name : ";
	getline(cin,name);
	cout<<"Age : ";
	cin>>age;
	cout<<"Phone no : ";
	cin>>phoneno;
	cin.ignore();
	cout<<"Registration no : ";
	getline(cin,regno);
	cout<<"Department : ";
	getline(cin,department);
	cout<<"Degree : ";
	getline(cin,degree);
	cout<<"Section : ";
	cin>>section;
	cin.ignore();
	Student s(name,age,phoneno,regno,department,section,degree);
	cout<<"\n-------Student-------\n"<<endl;
	s.displaystudent();
	cout<<"\n "<<endl;
	

	//Teacher
	
	cout<<"\n ===For Teachers=== \n"<<endl;
	
	cout<<"Name : ";
	getline(cin,name);
	cout<<"Age : ";
	cin>>age;
	cout<<"Phone no : ";
	cin>>phoneno;
	cin.ignore();
	cout<<"Desigination : ";
	cin>>desigination;
	cin.ignore();
	Teacher t(name,age,phoneno,department,desigination);
	cout<<"\n-------Teacher-------\n"<<endl;
	t.displayteacher();
	cout<<"\n "<<endl;
	
	//Principal
	
	cout<<"\n ===For Principal=== \n"<<endl;
	
	cout<<"Name : ";
	getline(cin,name);
	cout<<"Age : ";
	cin>>age;
	cout<<"Phone no : ";
	cin>>phoneno;
	cin.ignore();
	cout<<"Campus : ";
	cin>>campus;
	cin.ignore();
	Principal p(name,age,phoneno,campus);
	cout<<"\n-------Principal-------\n"<<endl;
	p.displayprincipal();
	cout<<"\n "<<endl;
	
	cout<<"\n Press enter to exit \n "<<endl;
	cin.get();
}
