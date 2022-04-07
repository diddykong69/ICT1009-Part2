#ifndef Authentication_CPP
#define Authentication_CPP

#include "Authentication.h"

Authentication::Authentication()
= default;

Authentication::Authentication(string user, string pass)
{
    username = user;
    password = pass;
};

bool Authentication::authenticate()
{
    while (true)
    {
        fmt::print("Enter your username:\n");
        std::cin >> this->username;
        std::cin.clear();
        std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
        );

        fmt::print("Enter your password:\n");
        getline(std::cin, this->password);

        int result = this->conn.query(
                fmt::format(
                        "SELECT * FROM users WHERE user_name = '{0}' OR '{0}' "
                        "COLLATE NOCASE IN (admission_number, email_address) "
                        "COLLATE NOCASE;",
                        username
                )
        );

        if (result != 0)
        {
            fmt::print(
                    stderr,
                    fg(fmt::color::red),
                    "Something went wrong on our end. Try running the "
                    "program again.\n"
            );

            return false;
        }

        if (!bcrypt::validatePassword(
                password,
                conn.get_response()[0]["password"]
        ))
        {
            fmt::print(
                    fg(fmt::color::red),
                    "We were unable to locate your username/password. Please "
                    "try again\n"
            );

            continue;
        }

        this->role = conn.get_response()[0]["role"];
        this->first_name = conn.get_response()[0]["First_name"];
        this->last_name = conn.get_response()[0]["Last_name"];
        this->email = conn.get_response()[0]["email_address"];
        this->matri_code = conn.get_response()[0]["admission_number"];

        return true;
    }
}

//bool Authentication::authenticate(){
//    int result = conn.query(
//        fmt::format(
//            "SELECT * FROM users WHERE user_name = '{}';",
//            this->username
//        )
//    );
//
//    if (result != 0)
//    {
//        fmt::print(
//            stderr,
//            fg(fmt::color::red),
//            "Unable to authenticate user. Please try again.\n"
//        );
//
//        return false;
//    }
//
//    if (!bcrypt::validatePassword(password, conn.get_response()[0]["password"]))
//    {
//        fmt::print(
//            stderr,
//            fg(fmt::color::red),
//            "Sorry, but it seems as if you have entered either your username or password "
//            "incorrectly. Please try again.\n"
//        );
//
//        return false;
//    }
//
//    this->role = conn.get_response()[0]["role"];
//    this->first_name = conn.get_response()[0]["First_name"];
//    this->last_name = conn.get_response()[0]["Last_name"];
//    this->email = conn.get_response()[0]["email_address"];
//    this->matri_code = conn.get_response()[0]["admission_number"];
//
//    return result;
//};

string Authentication::getRole()
{
    return this->role;
}

string Authentication::getEmail()
{
    return this->email;
}

string Authentication::getFirstName()
{
    return this->first_name;
}

string Authentication::getLastName()
{
    return this->last_name;
}

string Authentication::getUsername()
{
    return this->username;
}

string Authentication::getMatriCode()
{
    return this->matri_code;
}

#endif