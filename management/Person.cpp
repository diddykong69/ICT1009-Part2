#ifndef PERSON_CPP
#define PERSON_CPP

#include <string>
#include <iostream>

// header files
#include "Person.h"

using namespace std;

Person::Person()
= default;

Person::Person(string admission_number, string username, string first_name,
               string last_name, string email)
{
    setAdmissionNumber(admission_number);
    setUsername(username);
    setFirstName(first_name);
    setLastName(last_name);
    setEmail(email);
}

void Person::setAdmissionNumber(string &admissionNumber)
{
    this->admission_number = admissionNumber;
}

string Person::getAdmissionNumber() const
{
    return admission_number;
}

void Person::setUsername(string &userName)
{
    this->username = userName;
}

string Person::getUsername() const
{
    return username;
}

void Person::setFirstName(string &firstName)
{
    this->first_name = firstName;
}

string Person::getFirstName() const
{
    return first_name;
}

void Person::setLastName(string &lastName)
{
    this->last_name = lastName;
}

string Person::getLastName() const
{
    return last_name;
}

void Person::setEmail(string &emailAddress)
{
    this->email = emailAddress;
}

string Person::getEmail() const
{
    return email;
}

string Person::getName() const
{
    return first_name + " " + last_name;
}

void Person::displayDetails() const
{
    cout << "Name: " << getName() << endl;
    cout << "Email: " << getEmail() << endl;
}

#endif