#ifndef ADMIN_H
#define ADMIN_H

#include <iostream> // cout and cin
#include <string> // npos
#include "Person.h"
#include "../sql/sqlDB.h"

using namespace std;

class Admin{
    private:
        sqlDB test;
        int sql_query;
        string own_username;
    public:
    Admin(string usr);
    string get_own_username();
    int add_user(string user,string admission_number,string email_address, string pass, string role);
    int remove_user(string user);
    int remove_user(int id);
    int view_users(string user);
    template <typename T>int edit_user(string user,string field, T value);

};

#endif