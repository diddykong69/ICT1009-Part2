#include <iostream> // cout and cin
#include <string> // npos
#include "Person.h"
#include "sqlDB.h"
#include <algorithm> // For unique and sort

using namespace std;

class Admin: public Person, sqlDB{
    private:
    string username;
    string password;
    public:
    Admin(string user, string pass);
    void add_user(string username);
    void remove_user(string username);
    void view_users();

};

Admin::Admin(string user, string pass){
    username = user;
    password = pass;
};

void view_user(){
    
};

