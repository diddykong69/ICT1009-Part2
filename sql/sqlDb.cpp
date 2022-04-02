// you need to compile with -l sqlite3.... example: g++ sqlDb.cpp -l sqlite3

#ifndef sqlDB_CPP
#define sqlDB_CPP

#include "sqlDB.h"

int ITERATION = 0;
sqlDB::sqlDB()
{

    exit = sqlite3_open(CHAR_DATABASE_NAME, &db);
    if (exit)
    {
        std::cerr << "Error open DB " << sqlite3_errmsg(db) << std::endl;
    }
    else
    {
        std::cout << "Opened Database Successfully!" << std::endl;
    }
};

sqlDB::~sqlDB(){
sqlite3_close(db);
}

int sqlDB::query(string sql)
{
    string data("CALLBACK FUNCTION");
    mapping.clear();
    int rc = sqlite3_exec(db, sql.c_str(), callback, (void *)data.c_str(), &errMsg);
    update();
    if (rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", errMsg);
        //cerr << "Error: " << errMsg << endl;
        sqlite3_free(errMsg);
        return 1;
    }
    else
    {
        cout << "Operation OK!" << endl;
    }
    
    return (0);
}

void sqlDB::print()
{
    if (response.size() == 0){
        cout << "No data found.";
    }
    else{

    for (outside_ptr = response.begin(); outside_ptr != response.end(); outside_ptr++)
    {
        if (outside_ptr->first == 0)
        {
            for (inside_ptr = outside_ptr->second.begin(); inside_ptr != outside_ptr->second.end(); inside_ptr++)
            {
                printf("%-10s | ", inside_ptr->first.c_str());
            }
            cout << endl;
        }

        for (inside_ptr = outside_ptr->second.begin(); inside_ptr != outside_ptr->second.end(); inside_ptr++)
        {
            printf("%-10s | ", inside_ptr->second.c_str());
        }
        cout << endl;
    }}
};

void sqlDB::update()
{
    ITERATION = 0;
    response = mapping;
};

int sqlDB::callback(void *data, int argc, char **argv, char **azColName)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        // printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        mapping[ITERATION][azColName[i]] = argv[i] ? argv[i] : "NULL";
    }
    ITERATION += 1;
    return 0;
}

 map<int,map<string,string>> sqlDB::get_response(){
     return response;
 }

/* int main(int argc, char** argv)
{
    sqlDB test;
    test.query("SELECT * FROM users;");
    cout << test.response[0]["username"];
    //test.print();
    cout << endl;
}    */

#endif