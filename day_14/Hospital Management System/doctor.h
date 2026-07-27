#ifndef DOCTOR_H
#define DOCTOR_H
#include <iostream>
#include <string>
using namespace std;

class Doctor
{
private:
    string doctorname;
    string doctorid;
    int doctorage;
    string doctorphone;

public:
    Doctor();
    Doctor(string n, string i, int a, string p);
    void setdoctorName(string n);
    void setdoctorId(string i);
    void setdoctorAge(int a);
    void setdoctorPhone(string p);

    string getdoctorName();
    string getdoctorId();
    int getdoctorAge();
    string getdoctorPhone();

    void displayDoctor();
};
#endif