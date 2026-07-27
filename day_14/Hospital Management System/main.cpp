#include "patientmanager.h"
#include "doctormanager.h"
#include "appointmentmanager.h"
#include <iostream>
using namespace std;

int main()
{
    PatientManagement patientManager;
    DoctorManagement doctorManager;
    AppointmentManagement appointmentManager;
    int choice;
    do
    {
        cout << "\n===== Hospital Management System =====\n";
        cout << "1. Patient Management " << endl;
        cout << "2. Doctor Management " << endl;
        cout << "3. Appointment Management " << endl;
        cout << "4. Exit \n"
             << endl;
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
            patientManager.menu();
            break;
        }
        case 2:
        {
            doctorManager.menu();
            break;
        }
        case 3:
        {
            appointmentManager.menu();
            break;
        }
        case 4:
        {
            cout << "\nThanks for using Hospital Management System\n ";
            break;
        }

        default:
            cout << "Invalid choice!\n";
            break;
        }
    } while (choice != 4);
    cout << "\n Press enter to exit!\n";
    cin.get();
    return 0;
}