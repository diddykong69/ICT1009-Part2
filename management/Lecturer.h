#pragma once

#ifndef LECTURER_H
#define LECTURER_H

#include <iostream>
#include <string>
#include <vector>

// header files
#include "Person.h"
#include "Classes.h"

using namespace std;

class Lecturer : public Person{
    private:
        static const string type;
        string username;
        string password;
        vector <Classes> classes;
    public:
        Lecturer(string username, string password, string fname, string lname, string email, string contact);
        void getClasses();
        void deleteClass(Classes&);
        void addClass(Classes&);
        void getClassList(Classes&);
        void displayDetails();
};

#endif