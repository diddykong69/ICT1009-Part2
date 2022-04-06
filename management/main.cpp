#include <iostream>
#include <cstdlib>
#include <string>
#include "menu.h"
#include "Student.h"
#include "Lecturer.h"
#include "Programmes.h"
#include "Authentication.h"
#include "admin.h"
#include "../sql/sqlDB.h"

using namespace std;

Admin admin;
Programmes programme;
sqlDB conn;
map<int, map<string, string>> response;

void globalCallback(int option)
{
    std::cout << "Global Callback Selection: " << option << std::endl;
}

void option0()
{
    // Admin: add student into DB
    admin.add_user("student");
}

void option1()
{
    // Admin: edit user by admission number
    admin.edit_user<string>();
}

void option2()
{
    // Admin: add lecturer into DB
    admin.add_user("lecturer");
}

void option3()
{
    // Admin: Add module to student
    string id, mod_name;
    cin.clear();
    cin.sync();
    cout << "Enter student admission number: ";
    getline(cin, id);
    conn.query("SELECT * FROM users WHERE admission_number = '" + id +
               "' AND role = 'student'");
    response = conn.get_response();
    Student new_student(response[0]["admission_number"],
                        response[0]["user_name"], response[0]["First_name"],
                        response[0]["Last_name"], response[0]["email_address"]);
    new_student.displayDetails();
    cout << "Enter new module name to add to student: ";
    getline(cin, mod_name);
    Module m(mod_name);
    new_student.addModule(m);
    conn.query(
            "INSERT INTO student (admission_number, module, grade) VALUES ('" +
            new_student.getMatriCode() + "', '" + mod_name + "', '" +
            new_student.getGrades(mod_name) + "');");
    cout << "Module has been added!" << endl;
    new_student.displayDetails();
}

void option4()
{
    // Admin: Remove modules to student
    string id, mod_name;
    cin.clear();
    cin.sync();
    cout << "Enter student admission number: ";
    getline(cin, id);
    conn.query("SELECT * FROM users WHERE admission_number = '" + id +
               "' AND role = 'student'");
    response = conn.get_response();
    Student new_student(response[0]["admission_number"],
                        response[0]["user_name"], response[0]["First_name"],
                        response[0]["Last_name"], response[0]["email_address"]);
    new_student.displayDetails();
    cout << "Enter module name to delete: ";
    getline(cin, mod_name);
    Module m(mod_name);
    new_student.deleteModule(m);
    conn.query("DELETE FROM student WHERE admission_number = '" +
               new_student.getMatriCode() + "' AND module = '" + mod_name +
               "';");
    cout << "Module has been deleted!" << endl;
    new_student.displayDetails();
}

void option5()
{
    cout << "Showing all students" << endl;
    admin.view_users("student");
    cout << endl;
}

void option6()
{ // Lecturer: Assign grades
    string id, mod_name, grades;
    cin.clear();
    cin.sync();
    cout << "Enter student admission number: ";
    getline(cin, id);
    conn.query("SELECT * FROM users WHERE admission_number = '" + id +
               "' AND role = 'student'");
    response = conn.get_response();
    Student new_student(response[0]["admission_number"],
                        response[0]["user_name"], response[0]["First_name"],
                        response[0]["Last_name"], response[0]["email_address"]);
    new_student.displayDetails();
    cout << "Enter module name to assign grades to: ";
    getline(cin, mod_name);
    cout << "Enter grade score (e.g. 75): ";
    getline(cin, grades);
    new_student.setGrades(mod_name, stoi(grades));
    new_student.displayDetails();
}

void option7()
{
    programme.createProgramme();
}

void option8()
{
    programme.displayProgrammes();
}

void option9()
{
    programme.updateProgramme();
}

void option10()
{
    programme.addCurriculum();
}

void endProgram()
{
    std::cout << "Exiting program..." << std::endl;
    exit(1);
}

int main(int argc, const char *argv[])
{
    string username;
    string password;
    string classtype;
    bool program_exit = false;
    bool login_success = false;


    while (!login_success)
    {
        // Initial login prompt; Keeps prompting if invalid user
        cout << "Please enter username: ";
        cin >> username;
        cout << "Please enter password: ";
        cin >> password;
        Authentication test(username, password);
        test.authenticate();
        classtype = "";
        classtype += test.getRole();
        if (classtype != "")
        {
            login_success = true;
        }
        else
        {
            cout << "Wrong username/password" << endl;
        }
    }
    // After login success, create a database connection object
    Authentication test(username, password);
    test.authenticate();
    cout << "Hello " << username << endl;

    while (!program_exit)
    {
        // Based on the connection object's classtype, perform different actions
        if (classtype == "admin")
        {
            Admin new_class(test.getMatriCode(), test.getUsername(),
                            test.getFirstName(), test.getLastName(),
                            test.getEmail());
            Menu adminMenu("Select an option");
            adminMenu.addItem("Add students", &option0);
            adminMenu.addItem("Edit students", &option1);
            adminMenu.addItem("Add lecturers", &option2);
            adminMenu.addItem("Edit lecturers", &option1);
            adminMenu.addItem("Add modules", &option3);
            adminMenu.addItem("Remove modules", &option4);
            adminMenu.addItem("Create programme", &option7);
            adminMenu.addItem("View info about a programme", &option8);
            adminMenu.addItem("Update a programme", &option9);
            adminMenu.addItem("Add modules to a programme", &option10);
            adminMenu.addItem("Exit", &endProgram);
            adminMenu.printMenu();
        }
        if (classtype == "student")
        {
            Student new_class(test.getMatriCode(), test.getUsername(),
                              test.getFirstName(), test.getLastName(),
                              test.getEmail());
            new_class.displayDetails();
            program_exit = true;
        }
        if (classtype == "lecturer")
        {
            Lecturer new_class(test.getMatriCode(), test.getUsername(),
                               test.getFirstName(), test.getLastName(),
                               test.getEmail());
            Menu lecturerMenu("Select an option");
            lecturerMenu.addItem("View students", &option5);
            lecturerMenu.addItem("Assign module grades to students", &option6);
            lecturerMenu.addItem("Exit", &endProgram);
            lecturerMenu.printMenu();
        }
    }

    return 0;
}