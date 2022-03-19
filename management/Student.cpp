#include "Student.h"
#include <iostream>

using namespace std;

void Student::setMatriCode(int Code) {
  if (Code < 0) {
    cout << "Invalid entry";
  } else {
    MatriCode = Code;
  }
}

void Student::setGrades(int Grade) {
  if (Grade >= 90 && Grade <= 100) {
    StudentGrade = "A*";
  } else if (Grade >= 80 && Grade < 90) {
    StudentGrade = "A";
  } else if (Grade >= 70 && Grade < 80) {
    StudentGrade = "B";
  } else if (Grade >= 60 && Grade < 70) {
    StudentGrade = "C";
  } else if (Grade >= 50 && Grade < 60) {
    StudentGrade = "D";
  } else if (Grade >= 0 && Grade < 50) {
    StudentGrade = "F";
  } else {
    cout << "Invalid";
  }
}

void Student::setModules(string Mod) {
  Module = Mod;
}

void Student::showStudent() {
  cout << "Matri Code:";
  cout << MatriCode;
  cout << "\nGrades:";
  cout << StudentGrade;
  cout << "\nModule:";
  cout << Module;
  cout << "\n";
}