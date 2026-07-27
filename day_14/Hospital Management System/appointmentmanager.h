#ifndef APPOINTMENTMANAGER_H
#define APPOINTMENTMANAGER_H
#include "appointment.h"
#include "patientmanager.h"
#include "doctormanager.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class AppointmentManagement
{
private:
    PatientManagement pm;
    DoctorManagement dm;
    vector<Appointment> appointments;

public:
    void loadfile();
    void savefile();
    void bookAppointment();
    void cancelAppointment();
    void displayPatientAppointment();
    void menu();
};

#endif