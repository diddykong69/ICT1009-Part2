#include <iostream>
#include <stdlib.h>
#include "menu.h"
#include "Student.h"
#include "..\sql\sqlDB.h"

using namespace std;

void globalCallback(int option) {
    std::cout << "Global Callback Selection: " << option << std::endl;
}

void option0() {
    std::cout << "Option 0" << std::endl;
}

void option1() {
    std::cout << "Option 1" << std::endl;
}

void option2() {
    std::cout << "Option 2" << std::endl;
}

void endProgram() {
    std::cout << "Exiting program..." << std::endl;
    exit(1);
}

int main(int argc, const char * argv[]) {
        sqlDB test;
    test.query("SELECT * FROM users;");
    test.print();
    cout << endl;
  
//     Menu studentMenu("Select an option");
//     studentMenu.addItem("View grades", &option0);
//     studentMenu.addItem("View lectuers", &option1);
//     studentMenu.addItem("View modules", &option2);
//     studentMenu.addItem("Exit", &endProgram);

//     Menu lectuererMenu("Select an option");
//     lectuererMenu.addItem("View students", &option0);
//     lectuererMenu.addItem("View modules", &option2);
//     lectuererMenu.addItem("Exit", &endProgram);

//     Menu adminMenu("Select an option");
//     adminMenu.addItem("Add/edit students", &option0);
//     adminMenu.addItem("Add/edit lecturers", &option1);
//     adminMenu.addItem("Add/edit modules", &option2);
//     adminMenu.addItem("Exit", &endProgram);

//     Student student;
//     student.setMatriCode(2);
//     student.setGrades(90);
//     student.setModules("1009");
//     student.showStudent();
    
//     // print the respective menu and get input
//     // studentMenu.printMenu();
//     // lectuererMenu.printMenu();
//     // adminMenu.printMenu();
  
 return 0;
 }