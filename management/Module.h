#pragma once
#ifndef MODULE_H
#define MODULE_H

#include <iostream>

using namespace std;

class Module{
    private:
        string module_name;
        int grade;

    public:
        Module(string);
        void setModuleName(string&);
        string getModuleName() const;
        void setGrades(int);
        string getGrades() const;
};

#endif