#ifndef sqlDB_H
#define sqlDB_H

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

static map<int, map<string, string>> mapping;

class sqlDB
{
public:
    map<int, map<string, string>> response;

    sqlDB();

    ~sqlDB();

    int query(const string &sql);

    void update();

    void print();

    static int callback(void *data, int argc, char **argv, char **azColName);

private:
    sqlite3 *db{};
    char *errMsg{};
    map<int, map<string, string>>::iterator outside_ptr;
    map<string, string>::iterator inside_ptr;
};

#endif