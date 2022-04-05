#pragma once
#ifndef CLASSROOM_H
#define CLASSROOM_H

#include <string>
#include <vector>

// header files
#include "Student.h"

using namespace std;

class Classroom
{
private:
    std::string classroomName;
    std::vector<Student *> students;
public:
    explicit Classroom(std::string);

    void setClassroomName(std::string &);

    std::string getClassroomName() const;

    void addStudent(Student &);

    Student getStudent(const int &);

    void displayStudentList();
};

#endif