//you need to compile with -l sqlite3.... example: g++ sqlDb.cpp -l sqlite3

#include <iostream>
#include <sqlite3.h>
#include <string>
#include <map>

using namespace std;
string DATABASE_NAME = "example.db";
char* CHAR_DATABASE_NAME = &DATABASE_NAME[0];
map<int,map<string,string>> mapping;
int ITERATION = 0;

class sqlDB{
    sqlite3* db;
    int exit = 0;
    static int callback(void* data, int argc, char** argv, char** azColName);
    
   public: 
    sqlDB();
    map<int,map<string,string>> response;
    map<int,map<string,string>>::iterator outside_ptr;
    map<string,string>::iterator inside_ptr;
    int select(string sql);
    void update();
    void print();
    
    
};

sqlDB::sqlDB(){
    
    exit = sqlite3_open(CHAR_DATABASE_NAME, &db);
    if (exit)
    {
        std::cerr << "Error open DB " << sqlite3_errmsg(db) << std::endl;
    }else{
        std::cout << "Opened Database Successfully!" << std::endl;
    }
};

int sqlDB::select(string sql){
    string data("CALLBACK FUNCTION");
    int rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data.c_str(), NULL);
  
    if (rc != SQLITE_OK)
        cerr << "Error SELECT" << endl;
    else {
        cout << "Operation OK!" << endl;
    }
    sqlite3_close(db);
    return (0);
}

void sqlDB::print(){
    update();
    for(outside_ptr = response.begin(); outside_ptr!=response.end();outside_ptr++){
        for(inside_ptr = outside_ptr->second.begin(); inside_ptr != outside_ptr->second.end();inside_ptr++){
            cout << "First Key is "<<outside_ptr->first
            << " And second key is "<< inside_ptr->first
            << " and the value is "<< inside_ptr->second<<endl;
        }
        
    }
};

void sqlDB::update(){
    response = mapping;
};

int sqlDB::callback(void* data, int argc, char** argv, char** azColName)
{
    int i;
  
    for (i = 0; i < argc; i++) {
        //printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        mapping[ITERATION][azColName[i]] =  argv[i] ? argv[i] : "NULL";
    }
    ITERATION += 1;
    return 0;
}



int main(int argc, char** argv)
{
    sqlDB test;
    test.select("SELECT * FROM PERSON;");
    test.print();

}