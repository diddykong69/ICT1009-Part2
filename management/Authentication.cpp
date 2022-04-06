#ifndef AUTHENTICATION_CPP
#define AUTHENTICATION_CPP

#include "Authentication.h"

#include <utility>

Authentication::Authentication(
        std::string username,
        std::string password
) : username(std::move(username)),
    password(std::move(password))
{}

bool Authentication::authenticate()
{
    int result = conn.query(
            "SELECT * FROM users where user_name = '" + username +
            "' AND password = '" + bcrypt::generateHash(password) + "'"
    );

    if (result != 0)
    {
        return false;
    }

    role = conn.get_response()[0]["role"];
    firstName = conn.get_response()[0]["first_name"];
    lastName = conn.get_response()[0]["last_name"];
    email = conn.get_response()[0]["email_address"];
    matriCode = conn.get_response()[0]["admission_number"];

    return true;
}

string Authentication::getRole()
{
    return role;
}

string Authentication::getEmail()
{
    return email;
}

string Authentication::getFirstName()
{
    return firstName;
}

string Authentication::getLastName()
{
    return lastName;
}

string Authentication::getUsername()
{
    return username;
}

string Authentication::getMatriCode()
{
    return matriCode;
}

/* int main(int argc, const char * argv[]) {
    Authentication user("tester","test");
    cout << bool(user.authenticate());
    cout << user.getRole();
} */
#endif