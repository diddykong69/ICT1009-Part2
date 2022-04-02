#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream> // cout and cin
#include "../sql/sqlDB.h"
#include "../dependencies/Bcrypt/bcrypt.h"

using namespace std;

class Person{
    private:
        string username;
        string password;
        string first_name;
        string last_name;
        string contact;
        string email;
        int userID;
        
        sqlDB Database;
    public:
        Person(string username, string password, string first_name, string last_name, string contact, string email);
        void setUsername(string&);
        string getUsername() const;
        void setPassword(string&);
        // TODO: implement authentication checking in future
        int getUserID();
        bool checkLogin();
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