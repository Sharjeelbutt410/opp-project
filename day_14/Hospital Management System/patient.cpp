#include "patient.h"
#include <iostream>

Patient::Patient() {}

Patient::Patient(string n, string i, int a, string p, string c)
{
    patientname = n;
    patientid = i;
    patientage = a;
    patientphone = p;
    patientcnic = c;
}
void Patient::setpatientName(string n)
{
    patientname = n;
}
void Patient::setpatientId(string i)
{
    patientid = i;
}
void Patient::setpatientAge(int a)
{
    patientage = a;
}
void Patient::setpatientPhone(string p)
{
    patientphone = p;
}
void Patient::setpatientCnic(string c)
{
    patientcnic = c;
}
string Patient::getpatientName()
{
    return patientname;
}
string Patient::getpatientId()
{
    return patientid;
}
int Patient::getpatientAge()
{
    return patientage;
}
string Patient::getpatientPhone()
{
    return patientphone;
}
string Patient::getpatientCnic()
{
    return patientcnic;
}
void Patient::displayPatient()
{
    cout << "Patient Name : " << patientname << endl;
    cout << "Patient ID : " << patientid << endl;
    cout << "Patient Age : " << patientage << endl;
    cout << "Patient Phone : " << patientphone << endl;
    cout << "Patient Cnic : " << patientcnic << endl;
}