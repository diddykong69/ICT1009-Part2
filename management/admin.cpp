#include <iostream> // cout and cin
#include <string> // npos
#include "Person.h"
#include "../sql/sqlDB.cpp"
#include <algorithm> // For unique and sort

using namespace std;

class Admin{
    private:
        sqlDB test;
        int sql_query;
    public:
    Admin();
    
    void add_user(string user, string pass, string role);
    void remove_user(string user);
    void remove_user(int id);
    int view_users(string user);

};

Admin::Admin(){
    
};

void Admin::add_user(string user, string pass, string role){
    
test.query("INSERT INTO users (username,password,Roles) VALUES ('"+user+"','"+pass+"','"+role+"');");
};

void Admin::remove_user(string user){
    test.query("DELETE FROM users WHERE username = '"+user+"'" );
};

void Admin::remove_user(int id){
    string id_str = to_string(id);
    test.query("DELETE FROM users WHERE ID = '"+id_str+"'" );
};

int Admin::view_users(string user="%"){
    sql_query = test.query("SELECT * FROM users WHERE username LIKE '"+user+"';");
    if(sql_query){
        return (1);
    };
    test.print();
    return (0);
};

int main(int argc, char** argv)
{
    Admin admin;
    admin.view_users();
    //admin.view_users();
    //admin.add_user("testing","pass","STUDENT");
    //admin.remove_user("test");
    //admin.remove_user(6);
    admin.view_users("card");

}  