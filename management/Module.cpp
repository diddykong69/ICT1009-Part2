#ifndef MODULE_CPP
#define MODULE_CPP

#include <string>

// header files
#include "Module.h"

using namespace std;

Module::Module(string module_name){
    setModuleName(module_name);
    grades = -1;
};
void Module::setModuleName(string& module_name){
    this->module_name = module_name;
};
string Module::getModuleName() const{
    return module_name;
};
void Module::setGrades(const int& module_grade){
    this->grades = module_grade;
};
string Module::getGrades() const{
    string ret;
    if (grades >= 80){
        ret = "A";
    }else if (grades >= 70 && grades < 80){
        ret = "B";
    }else if (grades >= 60 && grades < 70){
        ret = "C";
    }else if (grades >= 50 && grades < 60){
        ret = "D";
    }else if (grades >= 40 && grades < 50){
        ret = "E";
    }else if (grades >= 0 && grades < 40){
        ret = "F";
    }else{
        // If grades is less 0, return undefined alphabetical grade
        ret = "-";
    }
    return ret;
};

#endif