#ifndef ADMIN_H
#define ADMIN_H

#include <iostream> // cout and cin
#include <string> // npos
#include "Person.h"
#include "../sql/sqlDB.h"

using namespace std;

class Admin: public Person{
    private:
        sqlDB test;
        int sql_query;
        string own_username;
    public:
    Admin(string admission_number, string username, string first_name, string last_name, string email);
    string get_own_username();
    int add_user(string);
    int remove_user(string user);
    int remove_user(int id);
    int view_users(string user);
    template <typename T>int edit_user(string user,string field, T value);

};

#endif