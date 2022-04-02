// you need to compile with -l sqlite3.... example: g++ sqlDb.cpp -l sqlite3
#include "sqlDB.h"

//map<int, map<string, string>> mapping;
int ITERATION = 0;

sqlDB::sqlDB()
{
    // Get this file's absolute path
    std::string currFileAbsolutePath =
            std::experimental::source_location::current().file_name();

    // Get this file's file name
    std::string currFileName = currFileAbsolutePath.substr(
            currFileAbsolutePath.find_last_of("/\\") + 1
    );

    std::string pattern = fmt::format("{}$", currFileName);

    /* Using regex, replace this file's file name with the file name of the DB
    to get the absolute path to the database file */
    std::string dbFileAbsolutePath = std::regex_replace(
        currFileAbsolutePath, std::regex(pattern), "PMSDB.db"
    );

    /* Attempt to open database with the DB absolute path obtained.
     If it doesn't work, fallback to relative and if that doesn't work,
     notify user that the database cannot be opened */
    if (sqlite3_open(dbFileAbsolutePath.c_str(), &db) != SQLITE_OK ||
        sqlite3_open("../sql/PMSDB.db", &db) != SQLITE_OK)
    {
        std::cerr
        << "Error opening database: "
        << sqlite3_errmsg(db)
        << std::endl;
    }
}

sqlDB::~sqlDB()
{
    sqlite3_close(db);
}

int sqlDB::query(const string &sql)
{
    string data("CALLBACK FUNCTION");
    mapping.clear();
    int rc = sqlite3_exec(db, sql.c_str(), callback, (void *) data.c_str(),
                          &errMsg);
    update();
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        //cerr << "Error: " << errMsg << endl;
        sqlite3_free(errMsg);
        return 1;
    }

    return 0;
}

void sqlDB::print()
{
    update();
    if (response.empty())
    {
        cout << "No data found.";
    }
    else
    {

        for (outside_ptr = response.begin();
             outside_ptr != response.end(); outside_ptr++)
        {
            if (outside_ptr->first == 0)
            {
                for (inside_ptr = outside_ptr->second.begin();
                     inside_ptr != outside_ptr->second.end(); inside_ptr++)
                {
                    printf("%-10s | ", inside_ptr->first.c_str());
                }
                cout << endl;
            }

            for (inside_ptr = outside_ptr->second.begin();
                 inside_ptr != outside_ptr->second.end(); inside_ptr++)
            {
                printf("%-10s | ", inside_ptr->second.c_str());
            }
            cout << endl;
        }
    }
};

void sqlDB::update()
{
    ITERATION = 0;
    response = mapping;
};

int sqlDB::callback(void *data, int argc, char **argv, char **azColName)
{
    for (int i = 0; i < argc; i++)
    {
        // printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        mapping[ITERATION][azColName[i]] = argv[i] ? argv[i] : "NULL";
    }
    ITERATION += 1;
    return 0;
}

/* int main(int argc, char** argv)
{
    sqlDB test;
    test.query("SELECT * FROM users;");
    test.print();

}   */