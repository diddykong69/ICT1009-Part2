#pragma once
#ifndef LECTURER_H
#define LECTURER_H

#include <iostream>
#include <string>
#include <vector>

// header files
#include "Person.h"
#include "../sql/sqlDB.h"


using namespace std;

class Lecturer : public Person{
    private:
        sqlDB conn;
        map<int,map<string,string>> response;
        const string type = "Lecturer";
        vector <string> modules;
    public:
        Lecturer();
        Lecturer(string admission_number, string username, string first_name, string last_name, string email);
        void showModules() const;
        // void addClasses(Classroom&);
        // void deleteClasses(Classroom&);
        // void showClassList(Classroom&) const;
        void setStudentGrades();
        void displayDetails() const;
};


#endif