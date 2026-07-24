#include "student.h"
#include <iostream>

Student::Student() {}
Student::Student(string n, string i, string p, int a, string d)
{
    name = n;
    id = i;
    phone = p;
    age = a;
    degree = d;
}
void Student::setname(string n)
{
    name = n;
}
void Student::setphone(string p)
{
    phone = p;
}
void Student::setage(int a)
{
    age = a;
}
void Student::setdegree(string d)
{
    degree = d;
}
string Student::getname()
{
    return name;
}
string Student::getid()
{
    return id;
}
string Student::getphone()
{
    return phone;
}
int Student::getage()
{
    return age;
}
string Student::getdegree()
{
    return degree;
}
void Student::displayStudent()
{
    cout << "Name : " << name << endl;
    cout << "ID : " << id << endl;
    cout << "Phone : " << phone << endl;
    cout << "Age : " << age << endl;
    cout << "Degree : " << degree << endl;
}
