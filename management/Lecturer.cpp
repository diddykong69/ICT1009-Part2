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

using namespace std;

Lecturer::Lecturer(string username, string password, string fname, string lname, string email, string contact)
    : Person(fname, lname, email, contact)
{
    this->username = username;
	this->password = password;
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
    for (auto c : classes){
        cout << c.getName() << endl;
    }
}

void Lecturer::getClassList(Classes &c){
    c.getStudentList();
}

void Lecturer::displayDetails(){
    Person::displayDetails();
    cout << "Classes teaching:" << endl;
    getClasses();
}

#endif