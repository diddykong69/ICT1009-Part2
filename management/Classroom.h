#pragma once
#ifndef CLASSROOM_H
#define CLASSROOM_H

#include <string>
#include <vector>

// header files
#include "Student.h"

using namespace std;

class Classroom{
    private:
        string classroom_name;
        vector <Student*> students;
    public:
        Classroom(string);
        void setClassroomName(string&);
        string getClassroomName() const;
        void addStudent(Student&);
        Student getStudent(const int&);
        void displayStudentList();
};

#endif