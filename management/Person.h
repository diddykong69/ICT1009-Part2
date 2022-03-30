#pragma once

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person{
    private:
        // Idenfication info
        string username; // Username for login
        string password; // Password for login
        // Person info
        string fname; // First name
        string lname; // Last name
        string contact; // Phone number
        string email; // Email
    public:
        Person(string username, string password, string fname, string lname, string contact, string email);        
        void setUser(string username); // Sets username
        string getUser() const; // Gets username
        void setPassword(string password); // Sets password
        bool validatePassword(string password); // validates password
        void setFirst(string first); // Sets first name
        string getFirst() const; // Gets first name
        void setLast(string last); // Sets last name 
        string getLast() const; // Gets last name
        void setContact(string contact); // Sets contact info
        string getContact() const; // Gets contact info
        void setEmail(string email); // Sets email info
        string getEmail() const; // Gets email info
        void displayDetails();
};

#endif