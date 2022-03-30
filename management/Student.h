#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>

// header files
#include "Person.h"
#include "Module.h"

using namespace std;


class Student: public Person {
private:
  string matri_code;  
  vector <Module> modules;

public:
  Student(string matri_code, string password, string first_name, string last_name, string contact, string email);
  void setMatriCode(string&);
  int getMatriCode() const;
  void deleteModule(Module&);
  void addModule(Module&);
  void showModules();
  void setGrades(string, int);
  void displayDetails();
};

#endif