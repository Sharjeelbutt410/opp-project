#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<string>
using namespace std;

class Student{
    private:
    string name;
    string id;
    string phone;
    int age;
    string degree;
    public:
    Student() ;
    Student(string n,string i,string p,int a,string d);
    void setname(string n);
    void setphone(string p);
    void setage(int a);
    void setdegree(string d);
    string getname(); 
    string getid();
    string getphone();
    int getage();
    string getdegree();
    void displayStudent();
};

#endif