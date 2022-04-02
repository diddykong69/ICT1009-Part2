#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <iostream> // cout and cin
#include <string> // npos
#include <map>
#include "../sql/sqlDB.h"
#include "admin.h"

using namespace std;



class Authenication{
    private:
    sqlDB conn;
    string username;
    string password;
    string role;
    public:
    Authenication(string user, string password);
    bool authenicate();    
    string get_role();
};

#endif