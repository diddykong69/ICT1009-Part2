#ifndef STUDENT_CPP
#define STUDENT_CPP

#include <iostream>
#include <string>

// header files
#include "Student.h"

using namespace std;

Student::Student(string matri_code, string username, string first_name,
                 string last_name, string email)
        : Person(matri_code, username, first_name, last_name, email)
{
    setMatriCode(matri_code);
    int no_result = conn.query(
            "SELECT * FROM student WHERE admission_number = '" + matri_code +
            "'");
    if (!no_result)
    {
        response = conn.get_response();
        for (auto i = 0; i < response.size(); i++)
        {
            auto *mod = new Module(response[i]["module"],
                                     response[i]["grade"]);
            modules.push_back(mod);
        }
    }
}

Student::~Student()
{
    for (auto mod: modules)
    {
        conn.query("UPDATE student SET grade = '" + mod->getGrades() +
                   "' WHERE admission_number = '"
                   + matri_code + "' AND module = '" + mod->getModuleName() +
                   "'");
    }
}

void Student::setMatriCode(string &matri_code)
{
    this->matri_code = matri_code;
}

string Student::getMatriCode() const
{
    return matri_code;
}

void Student::deleteModule(Module &delete_module)
{
    if (modules.empty())
    {
        cout << "Student is not taking any modules!" << endl;
    }
    else
    {
        auto iter = modules.begin();
        for (auto module: modules)
        {
            if (module->getModuleName() == delete_module.getModuleName())
            {
                modules.erase(iter);
                cout << "Student is no longer taking "
                     << delete_module.getModuleName() << endl;
            }
            iter++;
        }
    }
}

void Student::addModule(Module &new_module)
{
    modules.push_back(&new_module);
}

void Student::setGrades(const string &module_name, const int &new_grades)
{
    for (auto module: modules)
    {
        if (module->getModuleName() == module_name)
        {
            module->setGrades(new_grades);
            cout << "New grades have been assigned for module " << module_name
                 << endl;
        }
    }
}

string Student::getGrades(const string &module_name)
{
    for (auto module: modules)
    {
        if (module->getModuleName() == module_name)
        {
            return module->getGrades();
        }
    }
    return "-";
}

string Student::getType() const
{
    return type;
}

void Student::showModules() const
{
    if (modules.empty())
    {
        cout << "Student is not taking any modules" << endl;
    }
    else
    {
        cout << "Modules taking:" << endl;
        int index = 1;
        for (auto module: modules)
        {
            cout << index << ". " << module->getModuleName() << " Grades: "
                 << module->getGrades() << endl;
            index++;
        }
    }
}

void Student::displayDetails() const
{
    cout << "Displaying details for: " << endl;
    Person::displayDetails();
    cout << "Type: " << getType() << endl;
    showModules();
}

#endif