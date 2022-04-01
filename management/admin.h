#include <iostream> // cout and cin
#include <string> // npos
#include "Person.h"
#include "../sql/sqlDB.h"
#include "../dependencies/Bcrypt/bcrypt.h"

class Admin
{
private:
    sqlDB test;
    int sql_query{};
public:
    Admin();

    int add_user(
            const string &user,
            const string &admissionNum,
            const string &emailAddress,
            const string &pass,
            const string &role
    );

    int remove_user(const string &user);

    int remove_user(int id);

    int view_users(string user);
};