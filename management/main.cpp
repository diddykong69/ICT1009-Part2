#include <iostream>
#include <stdlib.h>
#include <string>
#include "menu.h"
#include "Student.h"
#include "Lecturer.h"
#include "Authenication.h"
#include "admin.h"
#include "..\sql\sqlDB.h"

using namespace std;

Admin admin;
sqlDB conn;
map<int,map<string,string>> response;

void globalCallback(int option) {
    std::cout << "Global Callback Selection: " << option << std::endl;
};

void option0() {
    // Admin: add student into DB
    admin.add_user("student");
};

void option1() {
    // Admin: edit student by admission number
    conn.query("SELECT First_name, Last_name, admission_number, email_address, password FROM users WHERE role = 'student'");
    conn.print();
    admin.edit_user<string>();
};

void option2() {
    // Admin: add lecturer into DB
    admin.add_user("lecturer");
};

void option3(){
    // Admin: Add module to student
    string id, mod_name;
    cin.clear();
    cin.sync();
    conn.query("SELECT First_name, Last_name, admission_number FROM users WHERE role = 'student'");
    conn.print();
    cout << "Enter student admission number: ";
    getline(cin, id);
    conn.query("SELECT * FROM users WHERE admission_number = '" + id + "' AND role = 'student'");
    response = conn.get_response();
    Student new_student(response[0]["admission_number"]);
    new_student = response;
    new_student.displayDetails();
    cout << "Enter new module name to add to student: ";
    getline(cin, mod_name);
    Module m(mod_name);
    if (new_student.addModule(m) == 0){
        conn.query("INSERT INTO student (admission_number, module, grade) VALUES ('" + new_student.getMatriCode() + "', '" + mod_name + "', '" + new_student.getGrades(mod_name) + "');");
        cout << "Module has been added!" << endl;
        new_student.displayDetails();
    }
    
};

void option4(){ 
    // Admin: Remove modules to student
    string id, mod_name;
    cin.clear();
    cin.sync();
    conn.query("SELECT First_name, Last_name, users.admission_number, module, grade FROM student, users WHERE student.admission_number = users.admission_number;");
    conn.print();
    cout << "Enter student admission number: ";
    getline(cin, id);
    conn.query("SELECT * FROM users WHERE admission_number = '" + id + "' AND role = 'student'");
    response = conn.get_response();
    Student new_student(response[0]["admission_number"]);
    new_student = response;
    new_student.displayDetails();
    cout << "Enter module name to delete: ";
    getline(cin, mod_name);
    Module m(mod_name);
    new_student.deleteModule(m);
    conn.query("DELETE FROM student WHERE admission_number = '" + new_student.getMatriCode() + "' AND module = '" + mod_name + "';");
    cout << "Module has been deleted!" << endl;
    new_student.displayDetails();
};

void option5(){
    cout << "Showing all students" << endl;
    admin.view_users("student");
    cout << endl;
};

void option6(){ // Lecturer: Assign grades
    string id, mod_name, grades;
    cin.clear();
    cin.sync();
    conn.query("SELECT users.First_name, users.Last_name, users.admission_number, student.module, student.grade FROM users, student WHERE users.admission_number = student.admission_number");
    conn.print();
    cout << "Enter student admission number: ";
    getline(cin, id);
    conn.query("SELECT * FROM users WHERE admission_number = '" + id + "' AND role = 'student'");
    response = conn.get_response();
    Student new_student(response[0]["admission_number"]);
    new_student = response;
    new_student.displayDetails();
    if (new_student.getTakingModules() > 0){
        cout << "Enter module name to assign grades to: ";
        getline(cin, mod_name);
        cout << "Enter grade score (e.g. 75): ";
        getline(cin, grades);
        new_student.setGrades(mod_name, stoi(grades));
        new_student.displayDetails();
    }  
};

void option7(){
    // Admin : edit lecturers
    conn.query("SELECT First_name, Last_name, admission_number, email_address, password FROM users WHERE role = 'lecturer'");
    conn.print();
    admin.edit_user<string>();
}

void option8(){
    // Admin: add module to lecturer
    string id, mod_name;
    cin.clear();
    cin.sync();
    conn.query("SELECT First_name, Last_name, admission_number FROM users WHERE role = 'lecturer'");
    conn.print();
    cout << "Enter lecturer admission number: ";
    getline(cin, id);
    conn.query("SELECT * FROM users WHERE admission_number = '" + id + "' AND role = 'lecturer'");
    response = conn.get_response();
    Lecturer new_lecturer(response[0]["admission_number"]);
    new_lecturer = response;
    cout << "Enter new module name to add to lecturer: ";
    getline(cin, mod_name);
    Module m(mod_name);
    if (new_lecturer.addModule(m) == 0){
        conn.query("INSERT INTO lecturers (admission_number, modules) VALUES ('" + new_lecturer.getAdmissionNumber() + "', '" + mod_name + "');");
        cout << "Module has been added!" << endl;    
        new_lecturer.displayDetails();    
    }
}

void option9(){
    // Admin: Remove modules to lecturer
    string id, mod_name;
    cin.clear();
    cin.sync();
    conn.query("SELECT First_name, Last_name, users.admission_number, modules FROM lecturers, users WHERE lecturers.admission_number = users.admission_number;");
    conn.print();
    cout << "Enter lecturer admission number: ";
    getline(cin, id);
    conn.query("SELECT * FROM users WHERE admission_number = '" + id + "' AND role = 'lecturer'");
    response = conn.get_response();
    Lecturer new_lecturer(response[0]["admission_number"]);
    new_lecturer = response;
    new_lecturer.displayDetails();
    cout << "Enter module name to delete: ";
    getline(cin, mod_name);
    Module m(mod_name);
    new_lecturer.deleteModule(m);
    conn.query("DELETE FROM lecturers WHERE admission_number = '" + new_lecturer.getAdmissionNumber() + "' AND modules = '" + mod_name + "'");
    new_lecturer.displayDetails();
}

void endProgram() {
    std::cout << "Exiting program..." << std::endl;
    exit(1);
};


int main(int argc, const char * argv[]) {
    try
    {
    
    string username;
    string password;
    string classtype;
    bool program_exit = false;
    bool login_success = false;


    while(!login_success){
        // Initial login prompt; Keeps prompting if invalid user
        cout << "Please enter username: ";
        cin >> username;
        cout << "Please enter password: ";
        cin >> password;
        Authenication test(username,password);
        test.authenicate();
        classtype = "";
        classtype += test.get_role();
        if (classtype != ""){
            login_success = true;            
        }else{
            cout << "Wrong username/password" << endl;
        }
    }
    // After login success, create a database connection object
    Authenication test(username,password);
    test.authenicate();
    cout << "Hello "<<username << endl;

    while(!program_exit){
        // Based on the connection object's classtype, perform different actions
        if(classtype == "admin"){
            Admin new_class(test.get_matri_code(), test.get_username(),test.get_first_name(),test.get_last_name(),test.get_email());
            Menu adminMenu("Select an option");
            adminMenu.addItem("Add students", &option0);
            adminMenu.addItem("Edit students", &option1);
            adminMenu.addItem("Add lecturers", &option2);
            adminMenu.addItem("Edit lectuerers", &option7);
            adminMenu.addItem("Add modules to lecturer", &option8);
            adminMenu.addItem("Remove modules from lecturer", &option9);
            adminMenu.addItem("Add modules to student", &option3);
            adminMenu.addItem("Remove modules from student", &option4);
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
            new_class.displayDetails();   
            Menu lectuererMenu("Select an option");
            lectuererMenu.addItem("View students", &option5);
            lectuererMenu.addItem("Assign module grades to students", &option6);
            lectuererMenu.addItem("Exit", &endProgram);
            lectuererMenu.printMenu();            
        }
    }

    }
    catch(int e)
    {
         cout <<"Error code:"<< e << endl;
    }
    
    
 return 0;
 }