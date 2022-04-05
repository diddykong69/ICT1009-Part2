#ifndef PERSON_CPP
#define PERSON_CPP

#include <string>
#include <iostream>

// header files
#include "Person.h"

using namespace std;

Person::Person(){

};

Person::Person(string admission_number, string username, string first_name, string last_name, string email){
    setAdmissionNumber(admission_number);
    setUsername(username);
    setFirstName(first_name);
    setLastName(last_name);
    setEmail(email);
};

void Person::setAdmissionNumber(string& admission_number){
    this->admission_number = admission_number;
};

string Person::getAdmissionNumber() const{
    return admission_number;
};

void Person::setUsername(string& username){
    this->username = username;
};
string Person::getUsername() const{
    return username;
};
void Person::setFirstName(string& first_name){
    this->first_name = first_name;
};
string Person::getFirstName() const{
    return first_name;
};
void Person::setLastName(string& last_name){
    this->last_name = last_name;
};
string Person::getLastName() const{
    return last_name;
};
void Person::setEmail(string& email){
    this->email = email;
};
string Person::getEmail() const{
    return email;
};
string Person::getName() const{
    return first_name + " " + last_name;
}
void Person::displayDetails() const{
    cout << "Name: " << getName() << endl;
    cout << "Email: " << getEmail() << endl;
};

#endif