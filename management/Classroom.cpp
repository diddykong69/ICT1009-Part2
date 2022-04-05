#ifndef CLASSROOM_CPP
#define CLASSROOM_CPP

#include <iostream>
#include <string>

// header files
#include "Classroom.h"

using namespace std;

Classroom::Classroom(std::string classroomName)
{
    setClassroomName(classroomName);
};

void Classroom::setClassroomName(std::string &nameOfClassroom)
{
    this->classroomName = nameOfClassroom;
};

std::string Classroom::getClassroomName() const
{
    return classroomName;
};

void Classroom::addStudent(Student &newStudent)
{
    students.push_back(&newStudent);
    std::cout
            << "Student: "
            << newStudent.getName()
            << " has been added to "
            << getClassroomName()
            << std::endl;
}

Student Classroom::getStudent(const int &index)
{
    return *students.at(index);
}

void Classroom::displayStudentList()
{
    if (students.empty())
    {
        std::cout << "There are no students!" << std::endl;
    }
    else
    {
        int iter = 1;
        for (auto student: students)
        {
            std::cout
            << "Student "
            << iter << ": "
            << student->getName()
            << std::endl;
            iter++;
        }
    }
}

#endif