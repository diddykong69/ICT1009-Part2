#ifndef CLASSES_CPP
#define CLASSES_CPP

#include <iostream>
#include <string>

// header files
#include "Classes.h"
#include "Student.h"

using namespace std;

Classes::Classes(string name){
    setName(name);
}

void Classes::setName(string &name){
    this->name = name;
}

string Classes::getName() const{
    return name;
}

void Classes::addStudents(Student &new_student){
    students.push_back(new_student);
    cout << "Student: " << new_student.getFirst() << " " << new_student.getLast() << " has been added to " << getName() << endl;
}

void Classes::getStudentList(){
    if (!students.empty()){
        cout << "Displaying class list for class: " << getName() << endl;
        for (int i = 0; i < students.size(); ++i){
            cout << "Student " << i+1 << ": " << students[i].getFirst() << " " << students[i].getLast() << endl;
        }
    }else{
        cout << "Class " << getName() << " does not have any students" << endl;
    }
}

Student Classes::getStudent(int index){
    Student &ret = students[index];
    return ret;
}


#endif