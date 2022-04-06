#pragma once
#ifndef MODULE_H
#define MODULE_H

#include <string>

using namespace std;

class Module{
    private:
        string module_name;
        string grades;
    public:
        Module(string);
        Module(string, string);
        void setModuleName(string&);
        string getModuleName() const;
        void setGrades(const int&);
        string getGrades() const; // Returns the alphabetical grade value
};


#endif