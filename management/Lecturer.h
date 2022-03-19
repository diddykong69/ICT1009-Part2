#pragma once

#ifndef LECTURER_H
#define LECTURER_H

#include <iostream>
#include <string>
#include <vector>
#include "Person.h"

using namespace std;

class Lecturer : public Person{
    private:
        static const string type; // Either lecturer, admin or student

        // School related info
        vector<string> modules;

    public:
        Lecturer(string username, string password, string first_name, string last_name, string contact, string email, vector<string> &modules);
        const string getType() const;
        void showModules();
        void addModule(string modules);
        void deleteModule(string modules);
        void DisplayDetails();

};

#endif