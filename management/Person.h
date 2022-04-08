#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person
{
private:
    string admission_number;
    string username;
    string first_name;
    string last_name;
    string email;
public:
    Person();

    Person(string admission_number, string username, string first_name,
           string last_name, string email);

    void setAdmissionNumber(string &);

    [[nodiscard]] string getAdmissionNumber() const;

    void setUsername(string &);

    [[nodiscard]] string getUsername() const;

    void setFirstName(string &);

    [[nodiscard]] string getFirstName() const;

    void setLastName(string &);

    [[nodiscard]] string getLastName() const;

    [[nodiscard]] string getName() const;

    void setEmail(string &);

    [[nodiscard]] string getEmail() const;

    virtual void displayDetails() const;
};


#endif