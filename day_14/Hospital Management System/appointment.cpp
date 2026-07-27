#include "appointment.h"
#include <iostream>
#include <string>
using namespace std;

Appointment::Appointment() {}
Appointment::Appointment(string aid, string pid, string did, string d, string t)
{
    appointmentId = aid;
    patientId = pid;
    doctorId = did;
    date = d;
    time = t;
}
void Appointment::setAppointmentId(string aid)
{
    appointmentId = aid;
}
void Appointment::setPatientId(string pid)
{
    patientId = pid;
}
void Appointment::setDoctorId(string did)
{
    doctorId = did;
}
void Appointment::setDate(string d)
{
    date = d;
}
void Appointment::setTime(string t)
{
    time = t;
}
string Appointment::getAppointmentId()
{
    return appointmentId;
}
string Appointment::getPatientId()
{
    return patientId;
}
string Appointment::getDoctorId()
{
    return doctorId;
}
string Appointment::getDate()
{
    return date;
}
string Appointment::getTime()
{
    return time;
}
void Appointment::displayappointment()
{
    cout << "Appointment ID : " << appointmentId << endl;
    cout << "Patient ID : " << patientId << endl;
    cout << "Doctor ID : " << doctorId << endl;
    cout << "Date : " << date << endl;
    cout << "Time : " << time << endl;
}
