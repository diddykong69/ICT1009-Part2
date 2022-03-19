#include <iostream>

class Student {
protected:
  int MatriCode;
  const char *StudentGrade;
  std::string Module;

public:
  void setMatriCode(int);
  void setGrades(int);
  void setModules(std::string);
  void showStudent();
};