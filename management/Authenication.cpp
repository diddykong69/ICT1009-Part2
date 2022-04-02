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
    return result;
};

string Authenication::get_role(){
    return role;
}



/* int main(int argc, const char * argv[]) {
    Authenication user("tester","test");
    cout << bool(user.authenicate());
    cout << user.get_role();
} */
#endif

