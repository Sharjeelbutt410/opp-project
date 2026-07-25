#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H
#include "student.h"

#include<vector>


class StudentManager{
    private:
    vector<Student> student;
    public:
    void loadfile();
    void savefile();
    void addStudent();
    void searchStudent();
    void updateStudent();
    void deleteStudent();
    void displayAll();
    void menu();

};

#endif
