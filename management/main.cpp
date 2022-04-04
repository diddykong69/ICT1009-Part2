#include <iostream>
#include <stdlib.h>
#include "menu.h"
#include "Student.h"
#include "Lecturer.h"
#include "Authenication.h"
#include "admin.h"
#include "..\sql\sqlDB.h"

using namespace std;

Admin admin;

void globalCallback(int option) {
    std::cout << "Global Callback Selection: " << option << std::endl;
}

void option0() {
    // Admin: add student into DB
    admin.add_user("student");
}

void option1() {
    // Admin: edit user
    admin.edit_user<string>();
}

void option2() {
    // Admin: add lecturer into DB
    admin.add_user("lecturer");
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
        cout << "Hello "<<username << "\n" << "Role:" << classtype << endl;
        if(classtype == "admin"){
            Admin new_class(test.get_matri_code(), test.get_username(),test.get_first_name(),test.get_last_name(),test.get_email());
            Menu adminMenu("Select an option");
            adminMenu.addItem("Add students", &option0);
            adminMenu.addItem("Edit students", &option1);
            adminMenu.addItem("Add lecturers", &option2); // TODO
            adminMenu.addItem("Edit lectuerers", &option1);
            adminMenu.addItem("Add modules", &option2); // TODO
            adminMenu.addItem("Remove modules", &option2); // TODO
            adminMenu.addItem("Exit", &endProgram);
            adminMenu.printMenu();      
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