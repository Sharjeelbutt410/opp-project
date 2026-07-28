#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include <iostream>
#include <string>

class Appointment
{
private:
    std::string appointmentId;
    std::string patientId;
    std::string doctorId;
    std::string date;
    std::string time;

public:
    Appointment();
    Appointment(std::string aid, std::string pid, std::string did, std::string d, std::string t);

    void setAppointmentId(std::string aid);
    void setPatientId(std::string pid);
    void setDoctorId(std::string did);
    void setDate(std::string da);
    void setTime(std::string t);

    std::string getAppointmentId();
    std::string getDoctorId();
    std::string getPatientId();
    std::string getDate();
    std::string getTime();

    void displayappointment();
};

#endif