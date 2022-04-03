#ifndef STUDENT_CPP
#define STUDENT_CPP

#include <iostream>
#include <string>
#include <algorithm>

// header files
#include "Student.h"

using namespace std;

Student::Student(string matri_code, string username,string first_name, string last_name, string email)
    : Person(username,first_name, last_name, email)
{
    setMatriCode(matri_code);
    int no_result = conn.query("SELECT * FROM student WHERE admission_number = '"+matri_code+"'");
    if (!no_result)
    {
        response = conn.get_response();
        for(int i=0; i < response.size();i++){
            Module *mod = new Module(response[i]["module"], stoi(response[i]["grade"]));
            modules.push_back(mod);
        }
    }
};
void Student::setMatriCode(string& matri_code){
    this->matri_code = matri_code;
};
string Student::getMatriCode() const{
    return matri_code;
};
void Student::deleteModule(Module& delete_module){
    if (modules.empty()){
        cout << "Student is not taking any modules!" << endl;
    }else{
        auto iter = modules.begin();
        for (auto module : modules){
            if (module->getModuleName() == delete_module.getModuleName()){
                modules.erase(iter);
                cout << "Student is no longer taking " << delete_module.getModuleName() << endl;
            }
            iter++;
        }
    }
};
void Student::addModule(Module& new_module){
    if (modules.empty()){
        modules.push_back(&new_module);
        cout << "Student: " << getName() << " is now taking " << new_module.getModuleName() << endl;
    }else{
        bool already_taking = false;
        for (auto module : modules){
            if (module->getModuleName() == new_module.getModuleName()){
                already_taking = true;
                cout << "Student is already taking " << new_module.getModuleName() << endl;
                break;
            }
        }
        if (!already_taking){
            modules.push_back(&new_module);
            cout << "Student: " << getName() << " is now taking " << new_module.getModuleName() << endl;
        }
    }
};
void Student::setGrades(const string& module_name, const int& new_grades){
    for (auto module : modules){
        if (module->getModuleName() == module_name){
            module->setGrades(new_grades);
            cout << "New grades have been assigned for module "  << module_name << endl;
        }
    }
};
string Student::getGrades(const string& module_name){
    for (auto module : modules){
        if (module->getModuleName() == module_name){
            return module->getGrades();
        }
    }
    return "-";
};
Module Student::getModule(const int& index){
    return *modules[index];
};
string Student::getType() const{
    return type;
};
void Student::showModules() const{
    if (modules.empty()){
        cout << "Student is not taking any modules" << endl;
    }else{
        int index = 1;
        cout << "Modules taking:" << endl;
        for (auto module : modules){
            cout << module->getModuleName();
            cout << index << ". " << module->getModuleName() << " Grades: " << module->getGrades() << endl;
            index++;
        }
    }
};
void Student::displayDetails() const{
    cout << "Displaying details for: " << endl;
    Person::displayDetails();
    cout << "Type: " << getType() << endl;
    showModules();
};

#endif