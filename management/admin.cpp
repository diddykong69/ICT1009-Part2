#include "admin.h"

Admin::Admin(){
    
};

int Admin::add_user(string user, string pass, string role){
    
sql_query = test.query("INSERT INTO users (username,password,Roles) VALUES ('"+user+"','"+pass+"','"+role+"');");
if(sql_query){
    return 1;
};
return 0;
};

int Admin::remove_user(string user){
    sql_query = test.query("DELETE FROM users WHERE username = '"+user+"'" );
    if(sql_query){
    return 1;
};
return 0;
};

int Admin::remove_user(int id){
    string id_str = to_string(id);
    sql_query = test.query("DELETE FROM users WHERE ID = '"+id_str+"'" );
    if(sql_query){
    return 1;
};
return 0;
};

int Admin::view_users(string user="%"){
    sql_query = test.query("SELECT * FROM users WHERE username LIKE '"+user+"';");
    if(sql_query){
        return (1);
    };
    test.print();
    return (0);
};

/* int main(int argc, char** argv)
{
    Admin admin;
    admin.view_users();
    //admin.view_users();
    cout << admin.add_user("testing","pass","STUDENT");
    //admin.remove_user("test");
    cout << admin.remove_user(7);
    admin.view_users("card");

}    */