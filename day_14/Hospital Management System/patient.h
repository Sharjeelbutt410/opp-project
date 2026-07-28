#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>
#include <string>
using namespace std;

class Patient
{
private:
    string patientname;
    string patientid;
    int patientage;
    string patientphone;
    string patientcnic;

public:
    Patient();
    Patient(string n, string i, int a, string p, string c);

    void setpatientName(string n);
    void setpatientId(string i);
    void setpatientAge(int a);
    void setpatientPhone(string p);
    void setpatientCnic(string c);
    string getpatientName();
    string getpatientId();
    int getpatientAge();
    string getpatientPhone();
    string getpatientCnic();
    void displayPatient();
};
#endif