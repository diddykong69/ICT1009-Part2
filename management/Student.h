#include <iostream>
#include "Person.h"


using namespace std;


class Student: public Person {
protected:
  int MatriCode;
  string StudentGrade;
  string Module;

public:
  Student(string username, string password, string first_name, string last_name, string contact, string email, int matriCode, string grades, string module);
  void setMatriCode(int);
  void setGrades(int);
  void setModules(string);
  int getMatriCode() const;
  string getGrades() const;
  string getModules() const;
  void showStudent();
};