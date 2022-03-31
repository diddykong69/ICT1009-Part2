#pragma once
#ifndef LECTURER_H
#define LECTURER_H

#include <iostream>
#include <string>
#include <vector>

// header files
#include "Person.h"
#include "Classroom.h"

using namespace std;

class Lecturer : public Person{
    private:
        const string type = "Lecturer";
        vector <Classroom*> classrooms;
    public:
        Lecturer(string username, string password, string first_name, string last_name, string contact, string email);
        void showClasses() const;
        void addClasses(Classroom&);
        void deleteClasses(Classroom&);
        void showClassList(Classroom&) const;
        void setStudentGrades();
        void displayDetails() const;
};

#endif