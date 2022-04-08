#pragma once
#ifndef LECTURER_H
#define LECTURER_H

#include <iostream>
#include <string>
#include <vector>

// header files
#include "Person.h"
#include "Student.h"
#include "Module.h"
#include "../sql/sqlDB.h"


using namespace std;

class Lecturer : public Person{
    inline static const string TYPE = "Lecturer";
    private:
        sqlDB conn;
        map<int,map<string,string>> response;
        vector <Module*> modules;
    public:
        Lecturer(string);
        Lecturer(string admission_number, string username, string first_name, string last_name, string email);
        void showModules() const;
        int addModule(Module&);
        void deleteModule(Module&);
        void setStudentGrades(); // Able to assign new grades to students
        void displayDetails() const; // Display lecturer's details
        Lecturer& operator=(map<int,map<string,string>> r){
            setAdmissionNumber(r[0]["admission_number"]);
            setUsername(r[0]["user_name"]);
            setFirstName(r[0]["First_name"]);
            setLastName(r[0]["Last_name"]);
            setEmail(r[0]["email_address"]);
            return *this;
        };
};


#endif