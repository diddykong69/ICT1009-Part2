#include <iostream>
#include <sqlite3.h>
#include <string>
#include <map>
#include <cstdio>

using namespace std;
string DATABASE_NAME = "../sql/example.db";
char* CHAR_DATABASE_NAME = &DATABASE_NAME[0];
map<int,map<string,string>> mapping;
int ITERATION = 0;

class sqlDB{
    sqlite3* db;
    int exit = 0;
    char *errMsg = 0;
    static int callback(void* data, int argc, char** argv, char** azColName);
    
   public: 
    sqlDB();
    ~sqlDB();
    map<int,map<string,string>> response;
    map<int,map<string,string>>::iterator outside_ptr;
    map<string,string>::iterator inside_ptr;
    int query(string sql);
    void update();
    void print();
    
    
};