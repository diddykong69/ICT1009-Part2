#ifndef Authentication_CPP
#define Authentication_CPP

#include "Authentication.h"

Authentication::Authentication(string user, string pass){
    username = user;
    password = pass;
};

bool Authentication::authenticate(){
    int result = conn.query(
        fmt::format(
            "SELECT * FROM users WHERE user_name = '{}';",
            this->username
        )
    );

    if (result != 0)
    {
        fmt::print(
            stderr,
            fg(fmt::color::red),
            "Unable to authenticate user. Please try again.\n"
        );

        return false;
    }

    if (!bcrypt::validatePassword(password, conn.get_response()[0]["password"]))
    {
        fmt::print(
            stderr,
            fg(fmt::color::red),
            "Sorry, but it seems as if you have entered either your username or password "
            "incorrectly. Please try again.\n"
        );

        return false;
    }

    this->role = conn.get_response()[0]["role"];
    this->first_name = conn.get_response()[0]["First_name"];
    this->last_name = conn.get_response()[0]["Last_name"];
    this->email = conn.get_response()[0]["email_address"];
    this->matri_code = conn.get_response()[0]["admission_number"];

    return result;
};

string Authentication::getRole(){
    return this->role;
}

string Authentication::getEmail(){
    return this->email;
}

string Authentication::getFirstName(){
    return this->first_name;
}

string Authentication::getLastName(){
    return this->last_name;
}

string Authentication::getUsername(){
    return this->username;
}

string Authentication::getMatriCode(){
    return this->matri_code;
}

#endif