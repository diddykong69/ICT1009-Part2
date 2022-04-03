#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <iostream> // cout and cin
#include <string> // npos
#include <map>
#include "../sql/sqlDB.h"

using namespace std;



class Authenication{
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
    Authenication(string user, string password);
    bool authenicate();    
    string get_role();
    string get_username();
    string get_first_name();
    string get_last_name();
    string get_email();
    string get_matri_code();
};

#endif