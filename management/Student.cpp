#ifndef STUDENT_CPP
#define STUDENT_CPP

#include <iostream>
#include <string>
#include <utility>

// header files
#include "Student.h"

using namespace std;

Student::Student(string matri_code)
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

Student::Student(string matri_code, string username, string first_name,
                 string last_name, string email)
        : Person(matri_code, std::move(username), std::move(first_name),
                 std::move(last_name), std::move(email))
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
        if (mod->getGrades() != "-")
        {
            conn.query("UPDATE student SET grade = '" + mod->getGrades() +
                       "' WHERE admission_number = '" + matri_code +
                       "' AND module = '" + mod->getModuleName() + "'");
        }
    }
}

void Student::setMatriCode(string &matriCode)
{
    this->matri_code = matriCode;
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
    } else
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

int Student::addModule(Module &new_module)
{
    for (auto mod: modules)
    {
        if (mod->getModuleName() == new_module.getModuleName())
        {
            cout << "Student is already taking this module!" << endl;
            return -1;
        }
    }
    modules.push_back(&new_module);
    return 0;
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

string Student::getType()
{
    return TYPE;
}

void Student::showModules() const
{
    if (modules.empty())
    {
        cout << "Student is not taking any modules" << endl;
    } else
    {
        cout << "Modules taking:" << endl;
        auto index = 1;
        for (auto module: modules)
        {
            cout << "- " << module->getModuleName() << " (Grade given: " <<
                 module->getGrades() << ")" << endl;
            index++;
        }
    }
}

int Student::getTakingModules() const
{
    int takingModules = (int) modules.size();
    return takingModules;
}

void Student::displayDetails() const
{
    cout << "Displaying details for: " << endl;
    Person::displayDetails();
    cout << "Type: " << getType() << endl;
    showModules();
}

#endif