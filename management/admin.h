#include <iostream> // cout and cin
#include <string> // npos
#include "Person.h"
#include "../sql/sqlDB.cpp"

using namespace std;

class Admin{
    private:
        sqlDB test;
        int sql_query;
    public:
    Admin();
    
    int add_user(string user, string pass, string role);
    int remove_user(string user);
    int remove_user(int id);
    int view_users(string user);

};