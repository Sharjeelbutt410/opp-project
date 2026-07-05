#include<iostream>
#include<string>
using namespace std;

class Person{
	protected:
		string name;
		Person(string nam)
		{
			name = nam;
		}
	public:
		void displayname()
		{
			cout<<"Name : "<<name<<endl;
			
		}
	
};
class Student: public Person
{
	private:
		int rollno,semester;
		string department;
	public:
	Student(string nam,int roll,string dep,int sem)
	:Person(nam)
	{
		
		rollno = roll;
		department = dep;
		semester = sem;
		
		
	}
	void display()
	{
		displayname();
		cout<<"Roll no : "<<rollno<<endl;
		cout<<"Department : "<<department<<endl;
		cout<<"Semester : "<<semester<<endl;
	}
};

int main(){
	string name,dept;
	int roll,sem;

	cout<<"Enter your name : ";
	getline(cin,name);
	cout<<"Roll no : ";
	cin>>roll;
	cin.ignore();
	cout<<"Department : ";
	getline(cin,dept);
	cout<<"Semester : ";
	cin>>sem;
	cout<<"\n ===Student Detail=== \n"<<endl;
	Student s2(name,roll,dept,sem);
	s2.display();
	
	
	
}
