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
    friend ostream & operator<<(ostream& out, const Lecturer& lec);
    friend istream & operator>>(istream& in, Lecturer& lec);
    private:
        const string type = "Lecturer";
        vector <Classroom*> classrooms;
    public:
        Lecturer();
        Lecturer(string username, string first_name, string last_name, string contact, string email);
        void showClasses() const;
        void addClasses(Classroom&);
        void deleteClasses(Classroom&);
        void showClassList(Classroom&) const;
        void setStudentGrades();
        void displayDetails() const;
};

ostream& operator<<(ostream& out, const Lecturer& lec);
istream & operator>>(istream& in, Lecturer& lec);

#endif