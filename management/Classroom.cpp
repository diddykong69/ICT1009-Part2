#ifndef CLASSROOM_CPP
#define CLASSROOM_CPP

#include <iostream>
#include <string>

// header files
#include "Classroom.h"

using namespace std;

Classroom::Classroom(string classroom_name){
    setClassroomName(classroom_name);
};
void Classroom::setClassroomName(string& classroom_name){
    this->classroom_name = classroom_name;
};
string Classroom::getClassroomName() const{
    return classroom_name;
};
void Classroom::addStudent(Student& new_student){
    students.push_back(&new_student);
    cout << "Student: " << new_student.getName() << " has been added to " << getClassroomName() << endl;
};
Student Classroom::getStudent(const int& index){
    return *students.at(index);
};
void Classroom::displayStudentList(){
    if (students.empty()){
        cout << "There are no students!" << endl;
    }else{
        int iter = 1;
        for (auto student: students){
            cout << "Student " << iter << ": " << student->getName() << endl;
            iter++;
        }
    }
};

#endif