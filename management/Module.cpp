#ifndef MODULE_CPP
#define MODULE_CPP

#include <iostream>
#include <string>

// header files
#include "Module.h"

using namespace std;

Module::Module(string moduleName){
    setModuleName(moduleName);
}

void Module::setModuleName(string &moduleName){
    module_name = moduleName;
}

string Module::getModuleName() const{
    return module_name;
}

void Module::setGrades(int grade){
    this->grade = grade;
}

string Module::getGrades() const{
    string ret;
    if (grade >= 80){
        ret = "A";
    }else if (grade >= 70 && grade < 80){
        ret = "B";
    }else if (grade >= 60 && grade < 70){
        ret = "C";
    }else if (grade >= 50 && grade < 60){
        ret = "D";
    }else{
        ret = "F";
    }
    return ret;
}


#endif
