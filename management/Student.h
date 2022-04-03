#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

// header files
#include "Person.h"
#include "Module.h"
#include "../sql/sqlDB.h"

using namespace std;

class Student : public Person{
    private:
        sqlDB conn;
        map<int,map<string,string>> response;
        string matri_code;
        vector <Module*> modules;
        const string type = "Student";
    public:
        Student();
        Student(string matri_code,string username,string first_name, string last_name, string email);
        ~Student();
        void setMatriCode(string& matri_code);
        string getMatriCode() const;
        void deleteModule(Module&);
        void addModule(Module&);
        Module getModule(const int&);
        void setGrades(const string&, const int&);
        string getGrades(const string&);
        string getType() const;
        void showModules() const;
        void displayDetails() const;
};

#endif