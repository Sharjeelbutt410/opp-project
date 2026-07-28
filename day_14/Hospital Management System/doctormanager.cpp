#include "doctormanager.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void DoctorManagement::loadfile()
{
    doctors.clear();
    ifstream file("doctor.txt");

    if (!file)
    {
        return;
    }
    string name, id, phone;
    int age;
    while (getline(file, name))
    {
        getline(file, id);
        file >> age;
        file.ignore();
        getline(file, phone);

        doctors.push_back(Doctor(name, id, age, phone));
    }
    file.close();
}
void DoctorManagement::savefile()
{
    ofstream fsave("doctor.txt");
    if (!fsave)
    {
        cout << "Error in opening file " << endl;
        return;
    }

    for (int i = 0; i < doctors.size(); i++)
    {
        fsave << doctors[i].getdoctorName() << endl;
        fsave << doctors[i].getdoctorId() << endl;
        fsave << doctors[i].getdoctorAge() << endl;
        fsave << doctors[i].getdoctorPhone() << endl;
    }
    fsave.close();
}
void DoctorManagement::addDoctor()
{
    string name;
    string id;
    string phone;
    int age;
    bool found = false;
    try
    {
        cout << "\n----- Doctor Details -----\n";
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
            throw "ID can't be empty. ";
        }

        cout << "Age: ";
        cin >> age;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            throw "Age must be a number!";
        }

        if (age <= 0 || age > 100)
        {
            throw "Invalid age!";
        }

        cin.ignore();
        cout << "Phone no : ";
        cin >> phone;
        if (phone.empty())
        {
            throw "Phone no can't be empty.";
        }
        if (phone.length() != 11)
        {
            throw "Phone must contain exactly 11 digits.";
        }
        cin.ignore();
        for (int i = 0; i < doctors.size(); i++)
        {
            if (doctors[i].getdoctorId() == id)
            {
                found = true;
                break;
            }
        }

        if (found)
        {
            throw "Doctor ID already exist. ";
        }
        else
        {
            doctors.push_back(Doctor(name, id, age, phone));
            cout << "\n Doctor Added Successfully! \n"
                 << endl;
            savefile();
        }
    }
    catch (const char *message)
    {
        cout << "Error : " << message <<"\n" << endl;
    }
}
void DoctorManagement::searchDoctor()
{
    string id;
    try
    {
        if(doctors.empty())
        {
            throw "No Data Found";
        }
        cout << "Enter Doctor ID : ";
        getline(cin, id);
        bool found = false;
        for (int i = 0; i < doctors.size(); i++)
        {
            if (doctors[i].getdoctorId() == id)
            {
                cout << "\nDoctor found!\n"
                     << endl;
                doctors[i].displayDoctor();
                found = true;
                break;
            }
        }
        if (!found)
        {
            throw "Doctor not Found!";
        }
    }
    catch (const char *message)
    {
        cout << "Error : " << message << endl;
    }
}
void DoctorManagement::displayDoctor()
{
    try
    {
        if (doctors.empty())
        {
            throw "No Data Found! ";
        }
        else
        {
            for (int i = 0; i < doctors.size(); i++)
            {
                cout << "======= Doctor " << i + 1 << " ======= \n"
                     << endl;
                doctors[i].displayDoctor();
                cout << "---------------\n";
            }
        }
    }
    catch (const char *message)
    {
        cout << "Error : " << message <<"\n" << endl;
    }
}

bool DoctorManagement::doctorExists(string id)
{
    for (int i = 0; i < doctors.size(); i++)
    {
        if (doctors[i].getdoctorId() == id)
        {
            return true;
        }
    }
    return false;
}

void DoctorManagement::menu()
{

    loadfile();
    int choice;

    do
    {

        cout << "==== Doctor Management ====\n";
        cout << "1. Add Doctor \n";
        cout << "2. Search Doctor \n";
        cout << "3. Display Doctor \n";
        cout << "4. Exit \n";
        cout << "Enter your choice : ";
        cin >> choice;
        if (cin.fail())
        {
            cout << "\nInvalid! " << endl;
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
            addDoctor();
            break;
        }
        case 2:
        {
            searchDoctor();
            break;
        }
        case 3:
        {
            displayDoctor();
            break;
        }
        case 4:
        {
            cout <<"\nProgram Ended ..." << endl;
            break;
        }
        default:
        {
            cout <<"\nInvalid Choice" << endl;
            break;
        }
        }
    } while (choice != 4);
}
