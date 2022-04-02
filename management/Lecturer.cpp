#ifndef LECTURER_CPP
#define LECTURER_CPP

// header files
#include "Lecturer.h"

using namespace std;

ostream& operator<< (ostream& out, const Lecturer& lec){
        out << lec.getUsername() << "\n" << lec.getFirstName() << "\n" << lec.getLastName() << "\n" << lec.getContact() << "\n" << lec.getEmail() << "\n";
        for (auto classroom : lec.classrooms){
            out << classroom->getClassroomName() << "\n";
        }
        return out;
};


Lecturer::Lecturer(){

}

Lecturer::Lecturer(string username, string first_name, string last_name, string contact, string email)
    : Person(username, first_name, last_name, contact, email)
{

};
void Lecturer::showClasses() const{
    int index = 1;
    cout << "Classes teaching: " << endl;
    for (auto classroom : classrooms){
        cout << index << ". " << classroom->getClassroomName() << endl;
        index++;
    }
};
void Lecturer::addClasses(Classroom& new_class){
    if (classrooms.empty()){
        classrooms.push_back(&new_class);
        cout << "Lecturer is now assigned to " << new_class.getClassroomName() << endl;
    }else{
        // Check if lecturer is already teaching the class
        bool already_teaching = false;
        for (auto classroom : classrooms){
            if (classroom->getClassroomName() == new_class.getClassroomName()){
                already_teaching = true;
                cout << "Lecturer is already teaching this class!" << endl;
                break;
            }
        }
        if (!already_teaching){
            classrooms.push_back(&new_class);
            cout << "Lecturer is now assigned to " << new_class.getClassroomName() << endl;
        }
    }
};
void Lecturer::deleteClasses(Classroom& deleted_class){
    if (classrooms.empty()){
        cout << "Lecturer is not teaching any classes!" << endl;
    }else{
        auto iter = classrooms.begin();
        for (auto classroom : classrooms){
            if (classroom->getClassroomName() == deleted_class.getClassroomName()){
                classrooms.erase(iter);
                cout << "Lecturer is no longer teaching " << deleted_class.getClassroomName() << endl;
            }
            iter++;
        }
    }
};
void Lecturer::showClassList(Classroom& selected_class) const{
    if (classrooms.empty()){
        cout << "Lecturer is not teaching any classes!" << endl;
    }else{
        bool is_teaching = false;
        for (auto classroom : classrooms){
            if (classroom->getClassroomName() == selected_class.getClassroomName()){
                is_teaching = true;
                break;
            }
        }
        if (is_teaching){
            selected_class.displayStudentList();
        }else{
            cout << "Lecturer does not have permission to view this classlist!" << endl;
        }
    }
};
void Lecturer::setStudentGrades(){
    int choice;
    showClasses();
    cout << "Select class by index: ";
    cin >> choice;
    auto cr = classrooms[choice-1];
    cr->displayStudentList();
    cout << "Select student to assign grade by index: ";
    cin >> choice;
    auto sr = cr->getStudent(choice-1);
    sr.showModules();
    cout << "Select modules from list by index: ";
    cin >> choice;
    auto m = sr.getModule(choice-1);    
    cout << "Enter grade score for " << m.getModuleName() << ": ";
    cin >> choice;
    sr.setGrades(m.getModuleName(), choice);
    cout << "Grades for " << m.getModuleName() << " have been updated successfully" << endl;
    cout << "Old grades: " << m.getGrades() << endl;
    cout << "New grades: " << sr.getGrades(m.getModuleName()) << endl;
};
void Lecturer::displayDetails() const{
    Person::displayDetails();
    cout << "Classes teaching: " << endl;
    showClasses();
};


#endif