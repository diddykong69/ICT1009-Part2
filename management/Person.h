#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person{
    private:
        string username;
        string first_name;
        string last_name;
        string contact;
        string email;
    public:
        Person();
        Person(string username, string first_name, string last_name, string contact, string email);
        void setUsername(string&);
        string getUsername() const;
        void setFirstName(string&);
        string getFirstName() const;
        void setLastName(string&);
        string getLastName() const;
        string getName() const;
        void setContact(string&);
        string getContact() const;
        void setEmail(string&);
        string getEmail() const;
        void displayDetails() const;
};


#endif