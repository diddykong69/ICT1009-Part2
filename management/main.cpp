#include <iostream>
#include <stdlib.h>
#include "menu.h"
#include "Student.h"
#include "Lecturer.h"
#include "Authenication.h"
#include "admin.h"
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
    string username;
    string password;
    string classtype;
    bool program_exit = false;

    Menu studentMenu("Select an option");
    studentMenu.addItem("View grades", &option0);
    studentMenu.addItem("View lectuers", &option1);
    studentMenu.addItem("View modules", &option2);
    studentMenu.addItem("Exit", &endProgram);

    Menu lectuererMenu("Select an option");
    lectuererMenu.addItem("View students", &option0);
    lectuererMenu.addItem("View modules", &option2);
    lectuererMenu.addItem("Exit", &endProgram);


    while(!program_exit){
        cout << "Please enter username: ";
        cin >> username;
        cout << "Please enter password: ";
        cin >> password;
        Authenication test(username,password);
        test.authenicate();
        classtype = test.get_role();
        cout << "Hello "<<username << "\n" << " Role:" << classtype << endl;
        if(classtype == "admin"){
            Admin new_class(test.get_matri_code(), test.get_username(),test.get_first_name(),test.get_last_name(),test.get_email());
            Menu adminMenu("Select an option");
            adminMenu.addItem("Add students", &new_class.add_user("student"););
            adminMenu.addItem("Edit students", &option0);
            adminMenu.addItem("Add lecturers", &option1);
            adminMenu.addItem("Edit lectuerers", &option1);
            adminMenu.addItem("Add modules", &option2);
            adminMenu.addItem("Remove modules", &option2);
            adminMenu.addItem("Exit", &endProgram);           
        }
        if (classtype == "student"){
            Student new_class(test.get_matri_code(),test.get_username(),test.get_first_name(),test.get_last_name(),test.get_email());
            new_class.displayDetails();  
            program_exit = true;          
        }

        if (classtype == "lecturer"){
            Lecturer new_class(test.get_matri_code(), test.get_username(), test.get_first_name(), test.get_last_name(), test.get_email());
            // new_class.displayDetails();
            lectuererMenu.printMenu();            
        }
    }
    
    
    
  
    
//     // print the respective menu and get input

  //     // studentMenu.printMenu();
 return 0;
 }