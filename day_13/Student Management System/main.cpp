#include "studentmanager.h"
#include<iostream>
using namespace std;

int main()
{
    StudentManager manager;
    manager.loadfile();
    manager.savefile();
    manager.menu();

    return 0;
}