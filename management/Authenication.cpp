#ifndef AUTHENICATION_CPP
#define AUTHENICATION_CPP

#include "Authenication.h"

Authenication::Authenication(string user, string pass){
    username = user;
    password = pass;
};

bool Authenication::authenicate(){
  int result = conn.query("select * from users where user_name = '"+username+"' AND password = '"+password+"'");
   if(result){
       return result;
   }
    role = conn.get_response()[0]["role"];
    first_name = conn.get_response()[0]["First_name"];
    last_name = conn.get_response()[0]["Last_name"];
    email = conn.get_response()[0]["email_address"];
    return result;
};

string Authenication::get_role(){
    return role;
}

string Authenication::get_email(){
    return email;
}

string Authenication::get_first_name(){
    return first_name;
}

string Authenication::get_last_name(){
    return last_name;
}

string Authenication::get_username(){
    return username;
}



/* int main(int argc, const char * argv[]) {
    Authenication user("tester","test");
    cout << bool(user.authenicate());
    cout << user.get_role();
} */
#endif

