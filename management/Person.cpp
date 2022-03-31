#ifndef PERSON_CPP
#define PERSON_CPP

#include <string>
#include <iostream>

// header files
#include "Person.h"

using namespace std;

Person::Person(string username, string password, string first_name, string last_name, string contact, string email){
    setUsername(username);
    setPassword(password);
    setFirstName(first_name);
    setLastName(last_name);
    setContact(contact);
    setEmail(email);
};
void Person::setUsername(string& username){
    this->username = username;
};
string Person::getUsername() const{
    return username;
};
void Person::setPassword(string& password){
    this->password = password;
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
void Person::setContact(string& contact){
    this->contact = contact;
};
string Person::getContact() const{
    return contact;
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
    cout << "Contact: " << getContact() << endl;
    cout << "Email: " << getEmail() << endl;
};

#endif