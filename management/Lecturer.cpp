#ifndef LECTURER_CPP
#define LECTURER_CPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for std::find_if

// header files
#include "Person.h"
#include "Classes.h"
#include "Lecturer.h"
#include "Module.h"

using namespace std;

Lecturer::Lecturer(string username, string password, string fname, string lname, string contact, string email)
    : Person(username, password, fname, lname, contact, email)
{

}

void Lecturer::addClass(Classes &new_class){
    if(!classes.empty()){
        auto exists = false;
        // Checks if the same class has been added previously
        for (auto room : classes){
            if(room.getName() == new_class.getName()){
                cout << "Lecturer is already teaching this class!" << endl;
                exists = true;
                break;
            }
        }
        if(!exists){
            classes.push_back(new_class);
        }
    }else{
        classes.push_back(new_class);
    }
    
}

void Lecturer::deleteClass(Classes &deleted_class){
    if(!classes.empty()){
        auto iter = find_if(classes.begin(), classes.end(), [&] (Classes &c){return c.getName() == deleted_class.getName();}); // returns true if class is in the list of classes and returns the index
        if (iter != classes.end()){
            classes.erase(iter);
            cout << deleted_class.getName() << " has been removed" << endl;
        }
    }else{
        cout << "Lecturer is not teaching any classes!" << endl;
    }
}

void Lecturer::getClasses(){
    int index = 1;
    for (auto c : classes){
        cout << index << ". " << c.getName() << endl;
        ++index;
    }
}

void Lecturer::getClassList(Classes &c){
    if (!classes.empty()){
        auto is_teaching = false;
        for (auto cl : classes){
            if(cl.getName() == c.getName()){
                is_teaching = true;
                break;
            }
        }
        if(!is_teaching){
            cout << "Lecturer does not have permission to view this classlist!" << endl;
        }else{
            c.getStudentList();
        }
    }else{
        cout << "Lecturer is not teaching any classes!" << endl;
    }
    
}

// Temporary method. (Change to take in input in future version)
void Lecturer::setStudentGrades(){
    getClasses();
    int choice;
    cout << "Select class by index: ";
    cin >> choice;
    Classes cr = classes[choice-1]; // Class reference
    cr.getStudentList();
    cout << "Select student to assign grade by index: ";
    cin >> choice;
    Student s = cr.getStudent(choice-1); // Student object
    cout << "Enter a value from 1 - 100 to assign grade: ";
    cin >> choice;
    s.displayDetails();
    
    
}

void Lecturer::displayDetails(){
    Person::displayDetails();
    cout << "Classes teaching:" << endl;
    getClasses();
}

#endif