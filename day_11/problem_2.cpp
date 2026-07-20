#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Employee{
    private:
    string name;
    string id;
    string phone;
    public:
    Employee(string n,string i,string p)
    {
        name = n;
        id = i;
        phone = p;
    }
    string getname()
    {
        return name;
    }
    string getid()
    {
        return id;
    }
    string getphone()
    {
        return phone;
    }
};
class Department{
    private:
    string department;
    vector<Employee> employee;
    public:
    Department(string d)
    {
        department = d;
    }
    void addemployee(Employee e)
    {
        employee.push_back(e);
    }
    void displayemployee()
    {
        cout<<"\nDepartment : "<<department<<endl;

        for(int i = 0; i < employee.size(); i++)
        {
            cout<<"Employee " << i + 1 << ":"<<endl;
            cout<<"Name :"<<employee[i].getname()<<endl;
            cout<<"ID :"<<employee[i].getid()<<endl;
            cout<<"Phone :"<<employee[i].getphone()<<endl;
            cout<<"--------------------------------\n";
        }
    }
};

int main()
{
    string department;
    int choice;
    string name,id,phone;

    cout<<"Department : ";
    getline(cin,department);

    Department d(department);

    cout<<"How many employee you want to enter : ";
    cin>>choice;
    cin.ignore();

    for(int i = 0; i < choice; i++)
    {
        cout<<"----Employee "<< i+1 <<" detail ----"<<endl;
        cout<<"Name : ";
        getline(cin,name);
        cout<<"ID : ";
        getline(cin,id);
        cout<<"Phone : ";
        getline(cin,phone);
        Employee e(name,id,phone);
        cout<<endl;
        d.addemployee(e);
    }
    d.displayemployee();
    return 0;
}