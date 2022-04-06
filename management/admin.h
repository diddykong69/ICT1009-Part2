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
    template <typename T>int edit_user(){
        string admission_number, field;
        T value;
        cin.clear();
        cin.sync();
        cout << "Enter admission number to edit: ";
        getline(cin, admission_number);
        cout << "Enter fieldname to modify: ";
        getline(cin, field);
        cout << "Enter new value: ";
        getline(cin, value);

        sql_query = conn.query("UPDATE users SET "+field+" = '"+value+"' WHERE admission_number = '"+admission_number+"'");
        if(sql_query){
            return (1);
        }
        return(0);
    };

};

#endif