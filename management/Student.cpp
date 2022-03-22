#include "Student.h"
#include "Person.h"
#include <iostream>

using namespace std;

Student::Student(string username, string password, string first_name, string last_name, string contact, string email, int matriCode, string grades, string module)
  : Person(username, password, first_name, last_name, contact, email)
{
  this->MatriCode = matriCode;
  this->StudentGrade = grades;

}

void Student::setMatriCode(int Code) {
  if (Code < 0) {
    cout << "Invalid entry";
  } else {
    this->MatriCode = Code;
  }
}

int Student::getMatriCode() const{
  return MatriCode;
}

void Student::setGrades(int Grade) {
  if (Grade >= 90 && Grade <= 100) {
    this->StudentGrade = "A*";
  } else if (Grade >= 80 && Grade < 90) {
    this->StudentGrade = "A";
  } else if (Grade >= 70 && Grade < 80) {
    this->StudentGrade = "B";
  } else if (Grade >= 60 && Grade < 70) {
    this->StudentGrade = "C";
  } else if (Grade >= 50 && Grade < 60) {
    this->StudentGrade = "D";
  } else if (Grade >= 0 && Grade < 50) {
    this->StudentGrade = "F";
  } else {
    this->StudentGrade = "Invalid";
  }
}

string Student::getGrades() const{
  return StudentGrade;
}

void Student::setModules(string Mod) {
  this->Module = Mod;
}

string Student::getModules() const{
  return Module;
}

//Below is kinda like testing code for me to see if it works, but if u want to implement something out of it then go ahead

void Student::showStudent(){
  cout << "Matri Code:";
  cout << getMatriCode();
  cout << "\nGrades:";
  cout << getGrades();
  cout << "\nModule:";
  cout << getModules();
  cout << "\n";
}