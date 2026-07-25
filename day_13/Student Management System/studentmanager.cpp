#include "studentmanager.h"
#include <iostream>
#include <fstream>

void StudentManager::loadfile()
{
    ifstream file("student.txt");

    if (!file)
    {
        return;
    }
    string name, id, phone, degree;
    int age;
    while (getline(file, name))
    {
        getline(file, id);
        getline(file, phone);
        file >> age;
        file.ignore();
        getline(file, degree);

        student.push_back(Student(name, id, phone, age, degree));
    }
    file.close();
}
void StudentManager::savefile()
{
    ofstream fsave("student.txt");
    if (!fsave)
    {
        cout << "Error in opening file " << endl;
    }

    for (int i = 0; i < student.size(); i++)
    {
        fsave << student[i].getname() << endl;
        fsave << student[i].getid() << endl;
        fsave << student[i].getphone() << endl;
        fsave << student[i].getage() << endl;
        fsave << student[i].getdegree() << endl;
    }
    fsave.close();
}
void StudentManager::addStudent()
{
    string name;
    string id;
    string phone;
    int age;
    string degree;
    bool found = false;
    try
    {
        cout << "\n----- Student Details -----\n";
        cout << "Name :";
        getline(cin, name);
        if (name.empty())
        {
            throw "Invalid Name! ";
        }

        cout << "ID : ";
        cin >> id;
        if (id.empty())
        {
            throw "Invalid ID! ";
        }
        cout << "Phone no : ";
        cin >> phone;
        cout << "Age: ";
        cin >> age;
        if (age <= 0 || age > 100)
        {
            throw "Invalid age!";
            cin.ignore();
        }

        cin.ignore();
        cout << "Degree : ";
        getline(cin, degree);
        if (degree.empty())
        {
            throw "Invalid Degree! ";
        }
        for (int i = 0; i < student.size(); i++)
        {
            if (student[i].getid() == id)
            {
                found = true;
                break;
            }
        }

        if (found)
        {
            throw "Student ID already exist. ";
        }
        else
        {
            student.push_back(Student(name, id, phone, age, degree));
            cout << "\n Student Added Successfully! \n"
                 << endl;
            savefile();
        }
    }
    catch (const char *message)
    {
        cout << "Error : " << message << endl;
    }
}
void StudentManager::searchStudent()
{
    string id;
    try
    {
        cout << "Enter STudent ID : ";
        getline(cin, id);
        bool found = false;
        for (int i = 0; i < student.size(); i++)
        {
            if (student[i].getid() == id)
            {
                cout << "\nStudent found!\n"
                     << endl;
                student[i].displayStudent();
                found = true;
                break;
            }
        }
        if (!found)
        {
            throw "Student not Found!";
        }
    }
    catch (const char *message)
    {
        cout << "Error : " << message << endl;
    }
}
void StudentManager::updateStudent()
{
    string searchid;
    string newname;
    string newphone;
    int newage;
    string newdegree;
    bool found = false;
    try
    {
        cout << "Enter Student ID : ";
        getline(cin, searchid);
        for (int i = 0; i < student.size(); i++)
        {
            if (student[i].getid() == searchid)
            {
                found = true;
                cout << "Name : ";
                getline(cin, newname);
                if (newname.empty())
                {
                    throw "Invalid Name! ";
                }
                cout << "Phone no : ";
                cin >> newphone;
                cout << "Age : ";
                cin >> newage;
                if (newage <= 0 || newage > 100)
                {
                    throw "Invalid age!";
                }

                cin.ignore();
                cout << "Degree : ";
                getline(cin, newdegree);
                if (newdegree.empty())
                {
                    throw "Invalid ID! ";
                }

                student[i].setname(newname);
                student[i].setage(newage);
                student[i].setphone(newphone);
                student[i].setdegree(newdegree);
                savefile();

                cout << "\nUpdated Successfully \n"
                     << endl;

                break;
            }
        }
        if (!found)
        {
            throw "Invalid Id!";
        }
    }
    catch (const char *message)
    {
        cout << "Error : " << message << endl;
    }
}
void StudentManager::deleteStudent()
{
    string searchid;
    try
    {
        cout << "Enter Student ID : ";
        getline(cin, searchid);
        bool found = false;
        for (int i = 0; i < student.size(); i++)
        {
            if (student[i].getid() == searchid)
            {
                found = true;
                student.erase(student.begin() + i);
                savefile();
                cout << "\nStudent deleted Successfully! \n"
                     << endl;
                break;
            }
        }
        if (!found)
        {
            throw "Student not Found! ";
        }
    }
    catch (const char *message)
    {
        cout << "Error : " << message << endl;
    }
}
void StudentManager::displayAll()
{
    try
    {
        if (student.empty())
        {
            throw "No Data Found! ";
        }
        else
        {
            for (int i = 0; i < student.size(); i++)
            {
                cout << "======= Student " << i + 1 << " ======= \n" << endl;
                student[i].displayStudent();
                cout<< "---------------\n";
            }
        }
    }
    catch (const char *message)
    {
        cout << "Error : " << message << endl;
    }
}
void StudentManager::menu()
{
    int choice;

    do
    {

        cout << "====Student Management System====\n";
        cout << "1. Add Students \n";
        cout << "2. Search Student \n";
        cout << "3. Update Student \n";
        cout << "4. Delete Student \n";
        cout << "5. Display All Students \n";
        cout << "6. Exit \n";
        cout << "Enter your choice : ";
        cin >> choice;
        if (cin.fail())
        {
            cout << "Invalid! " << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            choice = 0;
            continue;
        }

        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            addStudent();
            break;
        }
        case 2:
        {
            searchStudent();
            break;
        }
        case 3:
        {
            updateStudent();
            break;
        }
        case 4:
        {
            deleteStudent();
            break;
        }
        case 5:
        {
            displayAll();
            break;
        }
        case 6:
        {
            cout << "Program Ended ..." << endl;
            break;
        }
        default:
        {
            cout << "Invalid Choice" << endl;
            break;
        }
        }
    } while (choice != 6);
}