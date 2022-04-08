#ifndef ADMIN_CPP
#define ADMIN_CPP

#include <utility>

#include "admin.h"

Admin::Admin() = default;

Admin::Admin(string admission_number, string username, string first_name,
             string last_name, string email)
        : Person(std::move(admission_number), std::move(username),
                 std::move(first_name), std::move(last_name), std::move(email))
{
}

string Admin::get_own_username()
{
    return own_username;
}

int Admin::add_user(string role)
{
    string user, admission_number, email_address, pass, first_name,
            last_name, admissionNumCopy;
    cin.clear();
    cin.sync();
    cout << "Adding " << role << endl;
    cout << "Enter username to add:" << endl;
    getline(cin, user);
    cout << "Enter first name:" << endl;
    getline(cin, first_name);
    cout << "Enter last name:" << endl;
    getline(cin, last_name);
    cout << "Enter admission number (E.g. 1234567 [Letter in front not "
            "needed]:" << endl;
    getline(cin, admission_number);

    if (role == "student" && tolower(admission_number[0]) != 'p')
    {
        admission_number = fmt::format("P{}", admission_number);
    } else if ((role == "admin" || role == "lecturer")
               && tolower(admission_number[0]) != 's')
    {
        admission_number = fmt::format("S{}", admission_number);
    }

    cout << "Enter password:\n";
    getline(cin, pass);

    admissionNumCopy = admission_number;

    email_address = fmt::format(
            "{}@sit.singaporetech.edu.sg",
            admissionNumCopy.erase(0, 1)
    );

    sql_query = conn.query(
            "INSERT INTO users (user_name, admission_number, email_address, "
            "password, role, First_name, Last_name) VALUES "
            "('" + user + "', '" + admission_number + "', '" + email_address
            + "', '" + bcrypt::generateHash(pass) + "', '" + role + "', '"
            + first_name + "', '" + last_name + "');"
    );


    if (sql_query)
    {
        return 1;
    } else
    {
        cout << "New " << role << " has been added" << endl;
        return 0;
    }
}

int Admin::remove_user(string user)
{
    sql_query = conn.query(
            "DELETE FROM users WHERE user_name = '" + user + "'");

    if (sql_query)
    {
        return 1;
    }

    return 0;
}

int Admin::remove_user(int id)
{
    string id_str = to_string(id);
    sql_query = conn.query(
            "DELETE FROM users WHERE user_id = '" + id_str + "'");
    if (sql_query)
    {
        cout << "User not found." << endl;
        return 1;
    }

    return 0;
}

int Admin::view_users(string role = "%")
{
    sql_query = conn.query(
            "SELECT First_name, Last_name, admission_number, email_address FROM users WHERE role LIKE '" +
            role + "';");
    if (sql_query)
    {
        return 1;
    }

    conn.print();
    return 0;
}

#endif