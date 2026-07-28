#include "appointmentmanager.h"
#include "doctormanager.h"
#include "patientmanager.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void AppointmentManagement::loadfile()
{
    appointments.clear();
    ifstream file("appointment.txt");

    if (!file)
    {
        return;
    }
    string appointid, patid, docid, da, ti;

    while (getline(file, appointid))
    {
        getline(file, patid);
        getline(file, docid);
        getline(file, da);
        getline(file, ti);

        appointments.push_back(Appointment(appointid, patid, docid, da, ti));
    }
    file.close();
}
void AppointmentManagement::savefile()
{
    ofstream fsave("appointment.txt");
    if (!fsave)
    {
        cout << "Error in opening file " << endl;
        return;
    }

    for (int i = 0; i < appointments.size(); i++)
    {
        fsave << appointments[i].getAppointmentId() << endl;
        fsave << appointments[i].getPatientId() << endl;
        fsave << appointments[i].getDoctorId() << endl;
        fsave << appointments[i].getDate() << endl;
        fsave << appointments[i].getTime() << endl;
    }
    fsave.close();
}
void AppointmentManagement::bookAppointment()
{
    string appointmentID;
    string patientId;
    string doctorId;
    string date;
    string time;
    try
    {
        cout << "\n----- Appointment Details -----\n";
        cout << "Enter Appointment ID : ";
        cin >> appointmentID;
        if (appointmentID.empty())
        {
            throw "Appointment ID can't be empty.";
        }
        for (int i = 0; i < appointments.size(); i++)
        {
            if (appointments[i].getAppointmentId() == appointmentID)
            {
                throw "Appointment ID already exists.";
            }
        }
        cout << "Enter Patient ID  : ";
        cin >> patientId;
        if (!pm.patientExists(patientId))
        {
            throw "Patient doesn't exist.";
        }
        cout << "Enter Doctor ID : ";
        cin >> doctorId;
        if (!dm.doctorExists(doctorId))
        {
            throw "Doctor doesn't Exist ";
        }
        cin.ignore(); 
        cout << "Date : ";
        getline(cin,date);
        if (date.empty())
        {
            throw "Invalid Date!";
        }

        cout << "Time : ";
        getline(cin,time);
        if (time.empty())
        {
            throw "Invalid Time!";
        }
        appointments.push_back(Appointment(appointmentID, patientId, doctorId, date, time));
        savefile();
        cout << "\nAppointment Booked Successfully!\n";
    }
    catch (const char *message)
    {
        cout << "Error : " << message <<"\n" << endl;
    }
}
void AppointmentManagement::cancelAppointment()
{
    string searchId;
    try
    {
        if (appointments.empty())
        {
            throw "No data found. ";
        }
        cout << "Enter Appointment ID : ";
        cin >> searchId;
        bool found = false;
        for (size_t i = 0; i < appointments.size(); i++)
        {
            if (appointments[i].getAppointmentId() == searchId)
            {
                found = true;
                appointments.erase(appointments.begin() + i);
                cout << "\nAppointment Cancelled Successfully\n";
                savefile();
                return;
            }
        }
        if (!found)
        {
            throw "No Data Found. ";
        }
    }
    catch (const char *message)
    {
        cout << "Error : " << message <<"\n" << endl;
    }
}
void AppointmentManagement::displayPatientAppointment()
{
    string patientID;
    bool found = false;
    try
    {
        if (appointments.empty())
        {
            throw "No data found. ";
        }
        cout << "Enter Patient ID : ";
        cin >> patientID;
        for (size_t i = 0; i < appointments.size(); i++)
        {
            if (appointments[i].getPatientId() == patientID)
            {
                found = true;
                appointments[i].displayappointment();
            }
        }
        if (!found)
        {
            throw "Invalid Patient ID  ";
        }
    }
    catch (const char *message)
    {
        cout << "Error : " << message <<"\n" << endl;
    }
}
void AppointmentManagement::menu()
{
    pm.loadfile();
    dm.loadfile();
    loadfile();
    int choice;

    do
    {

        cout << "==== Appointment Management ====\n";
        cout << "1. Book Appointment \n";
        cout << "2. Cancel Appointment \n";
        cout << "3. View Patient Appointment \n";
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
            bookAppointment();
            break;
        }
        case 2:
        {
            cancelAppointment();
            break;
        }
        case 3:
        {
            displayPatientAppointment();
            break;
        }
        case 4:
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
    } while (choice != 4);
}