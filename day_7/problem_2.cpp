#include<iostream>
using namespace std;

class Student{
	private:
		string name;
		string regno;
		float cgpa;
	public:
		Student(string n,string r,float c)
		{
			name = n;
			regno = r;
			cgpa = c;
		}
		string getName()
		{
			return name;
		}
		bool operator<(Student other)
		{
			return cgpa < other.cgpa;
		}
		bool operator>(Student other)
		{
			return cgpa > other.cgpa;
		}
		bool operator==(Student other)
		{
			return cgpa == other.cgpa;
		}
		void display()
		{
			cout<<"Name : "<<name<<endl;
			cout<<"Registration no : "<<regno<<endl;
			cout<<"CGPA : "<<cgpa<<endl;
		}
};

int main()
{
	string name,regno;
	float cgpa;
	cout<<"Name : ";
	getline(cin,name);
	cout<<"Registration no : ";
	cin>>regno;
	cout<<"Cgpa : ";
	cin>>cgpa;
	Student s1(name,regno,cgpa);
	cout<<"\n"<<endl;
	
	
	cout<<"Name : ";
	getline(cin,name);
	cout<<"Registration no : ";
	cin>>regno;
	cout<<"Cgpa : ";
	cin>>cgpa;
	cout<<"\n"<<endl;
	Student s2(name,regno,cgpa);
	cout<<"\n"<<endl;
	
	if(s1 > s2)
	{
		cout<<s1.getName()<<" has higher CGPA "<<endl;
	}
	else if(s1 < s2)
	{
		cout<<s2.getName()<<" has higher CGPA "<<endl;
	}
	else
	{
		cout<<"Both have same CGPA "<<endl;
	}
	return 0;
}
