#include "sqlDB.h"

auto ITERATION = 0;

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
    if (sqlite3_open(dbFileAbsolutePath.c_str(), &db) != SQLITE_OK)
    {
        fmt::print(
                stderr,
                fg(fmt::color::red),
                "Error opening database: {}\n",
                sqlite3_errmsg(db)
        );
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
    int rc = sqlite3_exec(
            db,
            sql.c_str(),
            callback,
            (void *) data.c_str(),
            &errMsg
    );
    update();
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
        return 1;
    }

    return 0;
}

void sqlDB::print()
{
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
}

void sqlDB::update()
{
    ITERATION = 0;
    response = mapping;
}

int sqlDB::callback(void *data, int argc, char **argv, char **azColName)
{
    for (int i = 0; i < argc; i++)
    {
        mapping[ITERATION][azColName[i]] = argv[i] ? argv[i] : "NULL";
    }
    ITERATION += 1;
    return 0;
}

map<int, map<string, string>> sqlDB::get_response() const
{
    return response;
}