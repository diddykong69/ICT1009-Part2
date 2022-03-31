#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

// header files
#include "Person.h"
#include "Module.h"

using namespace std;

class Student : public Person{
    private:
        string matri_code;
        vector <Module*> modules;
        const string type = "Student";
    public:
        Student(string matri_code, string password, string first_name, string last_name, string contact, string email);
        void setMatriCode(string& matri_code);
        string getMatriCode() const;
        void deleteModule(Module&);
        void addModule(Module&);
        Module getModule(const int&);
        void setGrades(const string&, const int&);
        string getType() const;
        void showModules() const;
        void displayDetails() const;
};

#endif