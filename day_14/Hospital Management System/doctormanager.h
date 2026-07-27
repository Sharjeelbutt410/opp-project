#ifndef DOCTORMANAGER_H
#define DOCTORMANAGER_H
#include "doctor.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class DoctorManagement
{
private:
    vector<Doctor> doctors;

public:
    void loadfile();
    void savefile();
    void addDoctor();
    void searchDoctor();
    void displayDoctor();

    bool doctorExists(string id);

    void menu();
};
#endif