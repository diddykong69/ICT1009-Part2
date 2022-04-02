#ifndef ADMIN_CPP
#define ADMIN_CPP


#include "admin.h"

Admin::Admin(string usr){
    own_username = usr;
    
};

string Admin::get_own_username(){
    return own_username;
}

int Admin::add_user(string user,string admission_number,string email_address, string pass, string role){
    
sql_query = test.query("INSERT INTO users (user_name,admission_number,email_address,password,role) VALUES ('"+user+"','"+admission_number+"','"+email_address+"','"+pass+"','"+role+"');");
if(sql_query){
    return 1;
};
return 0;
};

int Admin::remove_user(string user){
    sql_query = test.query("DELETE FROM users WHERE user_name = '"+user+"'" );
    if(sql_query){
    return 1;
};
return 0;
};

int Admin::remove_user(int id){
    string id_str = to_string(id);
    sql_query = test.query("DELETE FROM users WHERE user_id = '"+id_str+"'" );
    if(sql_query){
        cout << "User not found." << endl;
    return 1;
};
return 0;
};

int Admin::view_users(string user="%"){
    sql_query = test.query("SELECT * FROM users WHERE user_name LIKE '"+user+"';");
    if(sql_query){
        return (1);
    };
    test.print();
    return (0);
};

template <typename T>int Admin::edit_user(string user,string field, T value){
    sql_query = test.query("UPDATE users SET "+field+" = '"+value+"' WHERE user_name = '"+user+"'");
    if(sql_query){
        return (1);
    }
    return(0);
};

/* int main(int argc, char** argv)
{
    Admin admin("testing");
    admin.view_users();
    admin.add_user("tester","P0123459","tester@sit.singaporetech.edu.sg","test","admin");
    //admin.edit_user("Raymous","role","student");
    admin.view_users();
    //admin.view_users();
    //cout << admin.add_user("testing","pass","STUDENT");
    //admin.remove_user("test");
    //cout << admin.remove_user(7);

    //Wadmin.view_users("card");

}; */

#endif