#ifndef PATIENTMANAGER_H
#define PATIENTMANAGER_H
#include "patient.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PatientManagement
{
private:
    vector<Patient> patients;

public:
    void loadfile();
    void savefile();
    void registerPatient();
    void searchPatient();
    void updatePatient();
    void deletePatient();
    bool patientExists(string id);
    void menu();
};
#endif