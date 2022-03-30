#pragma once

#ifndef LECTURER_H
#define LECTURER_H

#include <iostream>
#include <string>
#include <vector>

// header files
#include "Person.h"
#include "Classes.h"
#include "Module.h"

using namespace std;

class Lecturer : public Person{
    private:
        static const string type;
        vector <Classes> classes;
    public:
        Lecturer(string username, string password, string fname, string lname, string contact, string email);
        void getClasses();
        void deleteClass(Classes&);
        void addClass(Classes&);
        void getClassList(Classes&);
        void setStudentGrades();
        void displayDetails();
};

#endif