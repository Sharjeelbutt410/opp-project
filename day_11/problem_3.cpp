#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Student{
    private:
    string name;
    public:
    Student(string n)
    {
        name = n;
    }
    string getname()
    {
        return name;
    }

};
class Teacher{
    private:
    string name;
    vector<Student> student;
    public:
    Teacher(string n)
    {
        name = n;
    }
    void addstudent(Student s)
    {
        student.push_back(s);
    }
    string getname()
    {
        return name;
    }
    void displaystudent()
    {
        cout<<"Teacher : "<<name<<endl;

        for(int i= 0; i < student.size(); i++)
        {
            cout<<i + 1 <<"." << student[i].getname()<<endl; 
        }
    }
};
class Department{
    private:
    string department;
    vector<Teacher> teacher;
    vector<Student> student;
    public:
    Department(string d)
    {
        department = d;
    }
    void addteacher(Teacher t)
    {
        teacher.push_back(t);
    }
    void addstudent(Student s)
    {
        student.push_back(s);
    }
    void displaydepartment()
    {
        cout<<"Department : "<<department<<endl;
        cout<<"Teachers :"<<endl;
        for(int i = 0; i < teacher.size(); i++)
        {
            cout<<i + 1<<". "<<teacher[i].getname()<<endl;
        }
        cout<<"Students : "<<endl;
        for(int i = 0; i < student.size(); i++)
        {
            cout<<i + 1<<". "<<student[i].getname()<<endl;
        }
    }
};
class University{
    private:
    string university;
    vector<Department> department;

    public:
    University(string u)
    {
        university = u;
    }
    void adddepartment(Department d)
    {
        department.push_back(d);
    }

    void displayuniversity()
    {
        cout<<"University : "<<university<<endl;

        for(int i = 0; i < department.size(); i++)
        {
            department[i].displaydepartment();
        }
    }
};

int main()
{
    //students
    Student s1("Ali");
    Student s2("Ahmad");
    Student s3("Zubair");
    Student s4("Ahmar");

    //Teacher
    Teacher t1("Mr. Bilal");
    Teacher t2("Mr .Sarwar");

    t1.addstudent(s1);
    t1.addstudent(s2);

    t2.addstudent(s3);
    t2.addstudent(s4);

    Department d1("Software Engeerin0g");

    d1.addteacher(t1);
    d1.addteacher(t2);

    d1.addstudent(s1);
    d1.addstudent(s2);
    d1.addstudent(s3);
    d1.addstudent(s4);

    University u("University of Agriculture Faisalabad ");
    u.adddepartment(d1);

    u.displayuniversity();

    t1.displaystudent();
    t2.displaystudent();
    d1.displaydepartment();
}