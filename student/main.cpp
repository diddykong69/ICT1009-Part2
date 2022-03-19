#include <iostream>
#include "Student.h"

using namespace std;

int main() {
  Student student;
  student.setMatriCode(2);
  student.setGrades(90);
  student.setModules("1009");
  student.showStudent();
}