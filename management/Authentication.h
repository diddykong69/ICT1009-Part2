#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <iostream> // cout and cin
#include <string> // npos
#include <map>
#include <utility>
#include "../sql/sqlDB.h"
#include "../dependencies/Bcrypt/bcrypt.h"
#include "fmt/core.h"

using namespace std;

class Authentication{
private:
    sqlDB conn;
    string username;
    string password;
    string role;
    string first_name;
    string last_name;
    string email;
    string matri_code;
public:
    Authentication(string user, string password);
    bool authenticate();    
    string getRole();
    string getUsername();
    string getFirstName();
    string getLastName();
    string getEmail();
    string getMatriCode();
};

#endif