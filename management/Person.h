#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person{
    private:
        string admission_number;
        string username;
        string first_name;
        string last_name;
        string email;
    public:
        Person();
        Person(string admission_number, string username, string first_name, string last_name, string email);
        void setAdmissionNumber(string&);
        string getAdmissionNumber() const;
        void setUsername(string&);
        string getUsername() const;
        void setFirstName(string&);
        string getFirstName() const;
        void setLastName(string&);
        string getLastName() const;
        string getName() const;
        void setEmail(string&);
        string getEmail() const;
        void displayDetails() const;
};


#endif