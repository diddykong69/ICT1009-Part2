#ifndef ADMIN_H
#define ADMIN_H

#include <iostream> // cout and cin
#include <string> // npos
#include "Person.h"
#include "../sql/sqlDB.h"
#include "../dependencies/Bcrypt/bcrypt.h"

using namespace std;

class Admin: public Person{
    private:
        sqlDB test;
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
    template <typename T>int edit_user(){
        string user, field;
        T value;
        cin.clear();
        cin.sync();
        cout << "Enter username to edit: ";
        getline(cin, user);
        cout << "Enter fieldname to modify: ";
        getline(cin, field);
        cout << "Enter new value: ";
        getline(cin, value);

        sql_query = test.query("UPDATE users SET "+field+" = '"+value+"' WHERE user_name = '"+user+"'");
        if(sql_query){
            return (1);
        }
        return(0);
    };

};

#endif