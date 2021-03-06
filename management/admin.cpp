#ifndef ADMIN_CPP
#define ADMIN_CPP


#include "admin.h"

Admin::Admin(){ };

Admin::Admin(string admission_number, string username, string first_name, string last_name, string email)
    :Person(admission_number, username,first_name,last_name,email){ 
    
};

string Admin::get_own_username(){
    return own_username;
}

int Admin::add_user(string role){
    string user, admission_number, email_address, pass, first_name, last_name;
    cin.clear();
    cin.sync();
    cout << "Adding " << role << ":\n";
    cout << "Enter username to add: ";
    getline(cin, user);
    cout << "Enter first name: ";
    getline(cin, first_name);
    cout << "Enter last name: ";
    getline(cin, last_name);
    cout << "Enter admission number (e.g. P1234567): ";
    getline(cin, admission_number);
    cout << "Enter email address: (e.g. email@sit.singaporetech.edu.sg)";
    getline(cin, email_address);
    cout << "Enter password: ";
    getline(cin, pass);

    
    sql_query = conn.query("INSERT INTO users (user_name, admission_number, email_address, password, role, First_name, Last_name) VALUES ('" + user + "', '" + admission_number + "', '" + email_address + "', '" + pass + "', '" + role + "', '" + first_name + "', '" + last_name + "');");
    if(sql_query){
        return 1;
    }else{
        cout << "New " << role << " has been added" << endl;
        return 0;
    }
    
};

int Admin::remove_user(string user){
    sql_query = conn.query("DELETE FROM users WHERE user_name = '"+user+"'" );
    if(sql_query){
    return 1;
};
return 0;
};

int Admin::remove_user(int id){
    string id_str = to_string(id);
    sql_query = conn.query("DELETE FROM users WHERE user_id = '"+id_str+"'" );
    if(sql_query){
        cout << "User not found." << endl;
    return 1;
};
return 0;
};

int Admin::view_users(string role="%"){
    sql_query = conn.query("SELECT First_name, Last_name, admission_number, email_address FROM users WHERE role LIKE '"+role+"';");
    if(sql_query){
        return (1);
    };
    conn.print();
    return (0);
};


#endif