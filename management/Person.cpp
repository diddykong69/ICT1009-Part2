#ifndef PERSON_CPP
#define PERSON_CPP

#include <string>
#include <iostream>

// header files
#include "Person.h"

using namespace std;

Person::Person(string username, string password, string first_name, string last_name, string contact, string email){
    setUsername(username);
    setPassword(password);
    setFirstName(first_name);
    setLastName(last_name);
    setContact(contact);
    setEmail(email);
};
void Person::setUsername(string& username){
    this->username = username;
};
string Person::getUsername() const{
    return username;
};
void Person::setPassword(string& password){
    this->password = password;
};
void Person::setFirstName(string& first_name){
    this->first_name = first_name;
};
string Person::getFirstName() const{
    return first_name;
};
void Person::setLastName(string& last_name){
    this->last_name = last_name;
};
string Person::getLastName() const{
    return last_name;
};
void Person::setContact(string& contact){
    this->contact = contact;
};
string Person::getContact() const{
    return contact;
};
void Person::setEmail(string& email){
    this->email = email;
};
string Person::getEmail() const{
    return email;
};
string Person::getName() const{
    return first_name + " " + last_name;
}
void Person::displayDetails() const{
    cout << "Name: " << getName() << endl;
    cout << "Contact: " << getContact() << endl;
    cout << "Email: " << getEmail() << endl;
};


// static int callback(void* data, int argc, char** argv, char** azColName)
//     {
//         int i;
//         fprintf(stderr, "%s: ", (const char*)data);
    
//         for (i = 0; i < argc; i++) {
//             printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
//         }
    
//         printf("\n");
//         return 0;
//     }


// int Person::getUserID(){
    

//     sqlite3* DB;
//     char* messaggeError;
//     int exit = sqlite3_open("sql\PMSDB.db", &DB);
//     string sql("SELECT * FROM user_ID;");
//     if (exit) {
//         std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
//         return (-1);
//     }
//     else
//         std::cout << "Opened Database Successfully!" << std::endl;
  
//     int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL);
  
//     if (rc != SQLITE_OK)
//         cerr << "Error SELECT" << endl;
//     else {
//         cout << "Operation OK!" << endl;
//     }
  
//     sqlite3_close(DB);
//     return (0);
// }

#endif