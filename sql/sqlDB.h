#include <iostream>
#include <sqlite3.h>
#include <functional>
#include <string>
#include <map>
#include <cstdio>
#include <experimental/source_location>
#include <regex>
#include "fmt/core.h"

using namespace std;

class sqlDB
{
public:
    sqlite3 *db{};
    char *errMsg{};

    map<int, map<string, string>> response;
    map<int, map<string, string>>::iterator outside_ptr;
    map<string, string>::iterator inside_ptr;

    sqlDB();

    ~sqlDB();

    bool connectToDB();

    int query(const string &sql);

    void update();

    void print();

    static int callback(void *data, int argc, char **argv, char **azColName);
};