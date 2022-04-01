#include "admin.h"


Admin::Admin() = default;

int Admin::add_user(
        const string &user,
        const string &admissionNum,
        const string &emailAddress,
        const string &pass,
        const string &role
)
{
    sql_query = test.query(
            "INSERT INTO users (user_name, admission_number, email_address, password, role) VALUES ('" +
            user + "','" + admissionNum + "','" + emailAddress + "','" + pass +
            "','" + role + "');");

    std::cout << sql_query << std::endl;
    if (sql_query)
    {
        return 1;
    }

    return 0;
}

int Admin::remove_user(const string &user)
{
    sql_query = test.query(
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
    sql_query = test.query(
            "DELETE FROM users WHERE user_id = '" + id_str + "'");
    if (sql_query)
    {
        return 1;
    }
    return 0;
}

int Admin::view_users(string user = "%")
{
    sql_query = test.query(
            "SELECT * FROM users WHERE user_name LIKE '" + user + "';");
    if (sql_query)
    {
        return 1;
    }
    test.print();
    return 0;
}

//int main()
//{
//    Admin admin;
//    admin.view_users();
//    //admin.view_users();
//    cout << admin.add_user(
//            "testing",
//            "p0000000",
//            "0000000@sit.singaporetech.edu.sg",
//            bcrypt::generateHash("pass"),
//            "student"
//    );
//    admin.remove_user("testing");
//    cout << admin.remove_user(7);
//    admin.view_users("card");
//}