#include "doctor.h"
#include <iostream>

Doctor::Doctor() {}
Doctor::Doctor(string n, string i, int a, string p)
{
    doctorname = n;
    doctorid = i;
    doctorage = a;
    doctorphone = p;
}
void Doctor::setdoctorName(string n)
{
    doctorname = n;
}
void Doctor::setdoctorId(string i)
{
    doctorid = i;
}
void Doctor::setdoctorAge(int a)
{
    doctorage = a;
}
void Doctor::setdoctorPhone(string p)
{
    doctorphone = p;
}
string Doctor::getdoctorName()
{
    return doctorname;
}
string Doctor::getdoctorId()
{
    return doctorid;
}
int Doctor::getdoctorAge()
{
    return doctorage;
}
string Doctor::getdoctorPhone()
{
    return doctorphone;
}

void Doctor::displayDoctor()
{
    cout << "Doctor Name : " << doctorname << endl;
    cout << "Doctor ID : " << doctorid << endl;
    cout << "Doctor Age : " << doctorage << endl;
    cout << "Doctor Phone : " << doctorphone << endl;
}