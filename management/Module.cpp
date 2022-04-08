#ifndef MODULE_CPP
#define MODULE_CPP

#include <string>
#include <utility>

// header files
#include "Module.h"

using namespace std;

Module::Module(string module_name)
{
    setModuleName(module_name);
    setGrades(-1);
}

Module::Module(string module_name, string grade)
{
    setModuleName(module_name);
    this->grades = std::move(grade);
}

void Module::setModuleName(string &moduleName)
{
    this->module_name = moduleName;
}

string Module::getModuleName() const
{
    return module_name;
}

void Module::setGrades(const int &score)
{
    string ret;
    if (score >= 80)
    {
        ret = "A";
    }
    else if (score >= 70 && score < 80)
    {
        ret = "B";
    }
    else if (score >= 60 && score < 70)
    {
        ret = "C";
    }
    else if (score >= 50 && score < 60)
    {
        ret = "D";
    }
    else if (score >= 40 && score < 50)
    {
        ret = "E";
    }
    else if (score >= 0 && score < 40)
    {
        ret = "F";
    }
    else
    {
        ret = "-";
    }
    this->grades = ret;
}

string Module::getGrades() const
{
    return grades;
}

#endif