#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <iostream> // cout and cin
#include <string> // npos
#include <map>
#include "../sql/sqlDB.h"
#include "../sql/sqlDB.h"

using namespace std;

class Authentication
{
private:
    sqlDB conn;
    string username;
    string password;
    string role;
    string firstName;
    string lastName;
    string email;
    string matriCode;
public:
    Authentication(string username, string password);

    bool authenicate();

    string getRole();

    string getUsername();

    string getFirstName();

    string getLastName();

    string getEmail();

    string getMatriCode();
};

#endif