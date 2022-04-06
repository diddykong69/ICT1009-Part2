#ifndef ADMIN_H
#define ADMIN_H

#include <iostream> // cout and cin
#include <string> // npos
#include "Person.h"
#include "../sql/sqlDB.h"

using namespace std;

class Admin: public Person{
    private:
        sqlDB conn;
        int sql_query;
        string own_username;
    public:
    Admin();
    Admin(string admission_number, string username, string first_name, string last_name, string email);
    string get_own_username();
    int add_user(string);
    int remove_user(string user);
    int remove_user(int id);
    int add_module(string);
    int view_users(string role);
    template <typename T>int edit_user();

};

#endif