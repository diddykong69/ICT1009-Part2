#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <iostream>

// header files
#include "Person.h"
#include "Module.h"
#include "../sql/sqlDB.h"

using namespace std;

class Student : public Person{
    inline static const string TYPE = "Student"; 
    private:
        sqlDB conn;
        map<int,map<string,string>> response;
        string matri_code;
        vector <Module*> modules;
    public:       
        Student(string);
        Student(string matri_code,string username,string first_name, string last_name, string email);
        ~Student();
        void setMatriCode(string& matri_code);
        string getMatriCode() const;
        void deleteModule(Module&);
        int addModule(Module&);
        Module getModule(const int&);
        void setGrades(const string&, const int&);
        string getGrades(const string&);
        string getType() const;
        int getTakingModules() const;
        void showModules() const;
        void displayDetails() const;
        Student& operator=(map<int,map<string,string>> r){
            setAdmissionNumber(r[0]["admission_number"]);
            setUsername(r[0]["user_name"]);
            setFirstName(r[0]["First_name"]);
            setLastName(r[0]["Last_name"]);
            setEmail(r[0]["email_address"]);
            return *this;
        };
};



#endif