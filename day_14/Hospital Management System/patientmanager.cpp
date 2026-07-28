#include "patientmanager.h"
#include <iostream>
#include <fstream>

void PatientManagement::loadfile()
{
    patients.clear();
    ifstream file("patient.txt");

    if (!file)
    {
        return;
    }
    string name, id, phone, cnic;
    int age;
    while (getline(file, name))
    {
        getline(file, id);
        file >> age;
        file.ignore();
        getline(file, phone);
        getline(file, cnic);

        patients.push_back(Patient(name, id, age, phone, cnic));
    }
    file.close();
}
void PatientManagement::savefile()
{
    ofstream fsave("patient.txt");
    if (!fsave)
    {
        cout << "Error in opening file " << endl;
        return;
    }

    for (int i = 0; i < patients.size(); i++)
    {
        fsave << patients[i].getpatientName() << endl;
        fsave << patients[i].getpatientId() << endl;
        fsave << patients[i].getpatientAge() << endl;
        fsave << patients[i].getpatientPhone() << endl;
        fsave << patients[i].getpatientCnic() << endl;
    }
    fsave.close();
}
void PatientManagement::registerPatient()
{
    string name;
    string id;
    string phone;
    int age;
    string cnic;
    bool found = false;
    try
    {
        cout << "\n----- Patient Details -----\n";
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
        if (phone.length() != 11)
        {
            throw "Phone must contain exactly 11 digits.";
        }
        cin.ignore();
        cout << "Cnic (Without dashes): ";
        getline(cin, cnic);
        if (cnic.empty())
        {
            throw "Cnic can't be empty. ";
        }
        if (cnic.length() != 13)
        {
            throw "CNIC must contain exactly 13 digits.";
        }
        for (int i = 0; i < patients.size(); i++)
        {
            if (patients[i].getpatientId() == id)
            {
                found = true;
                break;
            }
        }

        if (found)
        {
            throw "Patient ID already exist. ";
        }
        else
        {
            patients.push_back(Patient(name, id, age, phone, cnic));
            cout << "\n Patient Added Successfully! \n"
                 << endl;
            savefile();
        }
    }
    catch (const char *message)
    {
        cout << "Error : " << message << "\n"
             << endl;
    }
}
void PatientManagement::searchPatient()
{
    string id;
    try
    {
        if (patients.empty())
        {
            throw "No Data Found";
        }
        cout << "Enter Patient ID : ";
        getline(cin, id);
        bool found = false;
        for (int i = 0; i < patients.size(); i++)
        {
            if (patients[i].getpatientId() == id)
            {
                cout << "\nPatient found!\n"
                     << endl;
                patients[i].displayPatient();
                found = true;
                break;
            }
        }
        if (!found)
        {
            throw "Patient not Found!";
        }
    }
    catch (const char *message)
    {
        cout << "Error : " << message << "\n"
             << endl;
    }
}
void PatientManagement::updatePatient()
{
    string searchid;
    string newname;
    string newphone;
    int newage;
    string newcnic;
    bool found = false;
    try
    {
        if (patients.empty())
        {
            throw "No Data Found";
        }
        cout << "Enter Patient ID : ";
        getline(cin, searchid);
        for (int i = 0; i < patients.size(); i++)
        {
            if (patients[i].getpatientId() == searchid)
            {
                found = true;
                cout << "Name : ";
                getline(cin, newname);
                if (newname.empty())
                {
                    throw "Invalid Name! ";
                }

                cout << "Age : ";
                cin >> newage;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    throw "Age must be a number!";
                }

                if (newage <= 0 || newage > 100)
                {
                    throw "Invalid age!";
                }

                cin.ignore();
                cout << "Phone no : ";
                cin >> newphone;
                
                
                if (newphone.length() != 11)
                {
                    throw "Phone must contain exactly 11 digits.";
                }
                cin.ignore();
                cout << "Cnic : ";
                getline(cin, newcnic);
                if (newcnic.empty())
                {
                    throw "Cnic can't be empty. ";
                }
                if (newcnic.length() != 13)
                {
                    throw "CNIC must contain exactly 13 digits.";
                }

                patients[i].setpatientName(newname);
                patients[i].setpatientAge(newage);
                patients[i].setpatientPhone(newphone);
                patients[i].setpatientCnic(newcnic);
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
        cout << "Error : " << message << "\n"
             << endl;
    }
}
void PatientManagement::deletePatient()
{
    string searchid;
    try
    {
        if (patients.empty())
        {
            throw "No Data Found";
        }
        cout << "Enter Patient ID : ";
        getline(cin, searchid);
        bool found = false;
        for (int i = 0; i < patients.size(); i++)
        {
            if (patients[i].getpatientId() == searchid)
            {
                found = true;
                patients.erase(patients.begin() + i);
                savefile();
                cout << "\nPatient deleted Successfully! \n"
                     << endl;
                break;
            }
        }
        if (!found)
        {
            throw "Patient not Found! ";
        }
    }
    catch (const char *message)
    {
        cout << "Error : " << message << "\n"
             << endl;
    }
}
bool PatientManagement::patientExists(string id)
{
    for (int i = 0; i < patients.size(); i++)
    {
        if (patients[i].getpatientId() == id)
        {
            return true;
        }
    }
    return false;
}

void PatientManagement::menu()
{
    loadfile();
    int choice;

    do
    {

        cout << "==== Patient Management ====\n";
        cout << "1. Register Patient \n";
        cout << "2. Search Patient  \n";
        cout << "3. Update Patient  \n";
        cout << "4. Delete Patient  \n";
        cout << "5. Exit \n";
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
            registerPatient();
            break;
        }
        case 2:
        {
            searchPatient();
            break;
        }
        case 3:
        {
            updatePatient();
            break;
        }
        case 4:
        {
            deletePatient();
            break;
        }

        case 5:
        {
            cout << "\nProgram Ended ..." << endl;
            break;
        }
        default:
        {
            cout << "\nInvalid Choice" << endl;
            break;
        }
        }
    } while (choice != 5);
}