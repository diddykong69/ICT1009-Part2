#pragma once
#ifndef LECTURER_H
#define LECTURER_H

#include <iostream>
#include <string>
#include <vector>

// header files
#include "Person.h"


using namespace std;

class Lecturer : public Person{
    private:
        const string type = "Lecturer";        
    public:
        Lecturer();
        Lecturer(string admission_number, string username, string first_name, string last_name, string email);
        void showClasses() const;
        // void addClasses(Classroom&);
        // void deleteClasses(Classroom&);
        // void showClassList(Classroom&) const;
        void setStudentGrades();
        void displayDetails() const;
};


#endif