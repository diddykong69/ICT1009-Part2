#pragma once

#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>
#include <vector>

// header files
#include "Student.h"

using namespace std;


class Classes{
    private:
        string name;
        vector <Student> students;
    public:
        Classes(string);
        void setName(string&);
        string getName() const;
        void addStudents(Student&);
        void getStudentList();
};

#endif