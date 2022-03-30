#pragma once

#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>
#include <vector>

// header files
#include "Student.h"
#include "Module.h"

using namespace std;


class Classes{
    private:
        string name;
        vector <Student> students;
        int grade; // placeholder until module class has been setup
    public:
        Classes(string);
        void setName(string&);
        string getName() const;
        void addStudents(Student&);
        Student getStudent(int);
        void getStudentList();
};

#endif