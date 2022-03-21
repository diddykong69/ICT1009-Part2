#include <iostream>
#include "Person.h"

class Student: public Person {
protected:
  int MatriCode;
  const char *StudentGrade;
  std::string Module;

public:
  void setMatriCode(int);
  void setGrades(int);
  void setModules(std::string);
  int getMatriCode() const;
  string getGrades() const;
  string getModules() const;
  void showStudent();
};