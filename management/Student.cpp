#ifndef STUDENT_CPP
#define STUDENT_CPP

#include <iostream>
#include <algorithm> // for std::find_if

// header files
#include "Student.h"
#include "Person.h"
#include "Classes.h"

using namespace std;

Student::Student(string matricode, string password, string first_name, string last_name, string contact, string email)
  : Person(matricode, password, first_name, last_name, email, contact)
{
  matri_code = matri_code;
}

void Student::addModule(Module &new_mod){
    if(!modules.empty()){
        auto already_taking = false;
        for (auto mod : modules){
            if(mod.getModuleName() == new_mod.getModuleName()){
                cout << "Student is already taking this module!" << endl;
                already_taking = true;
                break;
            }
            if(!already_taking){
                modules.push_back(new_mod);
            }
        }
    }else{
        modules.push_back(new_mod);
    }
}

void Student::deleteModule(Module &del_mod){
    if(!modules.empty()){
        auto iter = find_if(modules.begin(), modules.end(), [&](Module &m){return m.getModuleName() == del_mod.getModuleName();});
        if (iter != modules.end()){
            modules.erase(iter);
            cout << "Student is no longer taking " << del_mod.getModuleName() << endl;
        }else{
            cout << "Student is not taking " << del_mod.getModuleName() << endl;
        }
    }else{
        cout << "Student is not taking any modules!" << endl;
    }
}


void Student::showModules(){
    if(!modules.empty()){
        cout << "Modules taking: " << endl;
        for(auto m : modules){
            cout << m.getModuleName() << " Grades: " << m.getGrades() << endl;
        }
    }else{
        cout << "Student is not taking any modules!" << endl;
    }
}

void Student::setGrades(string mod_name, int new_grades){
    if(!modules.empty()){
        for (auto m : modules){
            if(m.getModuleName() == mod_name){
                m.setGrades(new_grades);
                cout << "Student's grade for " << m.getModuleName() << " has been assigned" << endl;
            }
        }
    }else{
        cout << "Student is not taking any modules!" << endl;
    }
}

void Student::displayDetails(){
    Person::displayDetails();
    showModules();
}


#endif