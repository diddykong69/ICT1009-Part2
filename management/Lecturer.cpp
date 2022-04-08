#ifndef LECTURER_CPP
#define LECTURER_CPP

// header files
#include "Lecturer.h"

using namespace std;


Lecturer::Lecturer(string admission_number){
    setAdmissionNumber(admission_number);
    int no_result = conn.query("SELECT * FROM lecturers WHERE admission_number = '"+admission_number+"'");
    if (!no_result)
    {
        response = conn.get_response();
        for(int i=0; i < response.size();i++){
            Module *mod = new Module(response[i]["modules"]);
            modules.push_back(mod);
        }
    }
}


Lecturer::Lecturer(string admission_number, string username, string first_name, string last_name, string email)
    : Person(admission_number, username, first_name, last_name, email)
{
    int no_result = conn.query("SELECT * FROM lecturers WHERE admission_number = '"+admission_number+"'");
    if (!no_result)
    {
        response = conn.get_response();
        for(int i=0; i < response.size();i++){            
            Module *mod = new Module(response[i]["modules"]);
            modules.push_back(mod);
        }
    }
};


void Lecturer::showModules() const{    
    int index = 1;
    for (auto module : modules){
        cout << index << ". " << module->getModuleName() << endl;
        index++;
    }
};

void Lecturer::deleteModule(Module& mod_name){
    auto iter = modules.begin();
    for (auto mod : modules){
        if (mod->getModuleName() == mod_name.getModuleName()){
            modules.erase(iter);
            cout << "Lecturer is no longer teaching " << mod_name.getModuleName() << endl;
        }
        iter++;
    }
}
int Lecturer::addModule(Module& mod_name){
    for (auto mod : modules){
        if (mod->getModuleName() == mod_name.getModuleName()){
            cout << "Lecturer is already teaching this module" << endl;
            return -1;
        }
        modules.push_back(&mod_name);
    }
    return 0;
}

void Lecturer::setStudentGrades(){
    vector <Module> modules;
    cout << "Showing all students:" << endl;
    int choice;
    int result = conn.query("SELECT users.First_name, users.Last_name, users.admission_number, users.email_address, users.user_name, student.module, student.grade FROM users, student WHERE users.role = 'student' AND users.admission_number = student.admission_number");    
    if (!result){
        response = conn.get_response();
        for (int i = 0; i < response.size(); i++){
            cout << i+1 << ". " << response[i]["First_name"] << " " << response[i]["Last_name"] << " | Module name: " << response[i]["module"] << " Grade: " << response[i]["grade"] << endl;
        }
    }
    cout << "Select student to assign grade by index (e.g. 1): ";
    cin >> choice;
    choice = choice - 1;
    string module_name = response[choice]["module"];
    Student temp_student(response[choice]["admission_number"], response[choice]["user_name"], response[choice]["First_name"], response[choice]["Last_name"], response[choice]["email_address"]);
    
    cout << "Assign new grade value (e.g. 50): ";
    cin >> choice;
    temp_student.setGrades(module_name, choice);
    temp_student.displayDetails();

}
void Lecturer::displayDetails() const{
    Person::displayDetails();
    cout << "Classes teaching: " << endl;
    showModules();
};


#endif