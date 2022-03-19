#ifndef PERSON_CPP
#define PERSON_CPP

#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

Person::Person(string username, string password, string fname, string lname, string contact, string email){
    setUser(username);
    setPassword(password);
    setFirst(fname);
    setLast(lname);
    setContact(contact);
    setEmail(email);
}

void Person::setUser(string username){
    this->username = username;
}

string Person::getUser() const{
    return username;
}

void Person::setPassword(string password){
    this->password = password;
}

bool Person::validatePassword(string password){
    return this->password == password;
}

void Person::setFirst(string first){
    fname = first;
}

string Person::getFirst() const{
    return fname;
}

void Person::setLast(string last){
    lname = last;
}

string Person::getLast() const{
    return lname;
}

void Person::setContact(string contact){
    this->contact = contact;
}

string Person::getContact() const{
    return contact;
}

void Person::setEmail(string email){
    this->email = email;
}

string Person::getEmail() const{
    return email;
}



#endif