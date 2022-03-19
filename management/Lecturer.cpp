#ifndef LECTURER_CPP
#define LECTURER_CPP
#include <iostream> // cout and cin
#include <string> // npos
#include "Lecturer.h"
#include "Person.h"
#include <algorithm> // For unique and sort

using namespace std;

vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find_first_of(delimiter, pos_start)) != string::npos) {
        if(pos_end > pos_start){
            res.push_back(s.substr(pos_start, pos_end-pos_start));
        }
        pos_start = pos_end+1;
    }
    if(pos_start < s.length()){
        res.push_back(s.substr(pos_start, string::npos));
    }
    return res;
}

const string Lecturer::type = "Lecturer";
Lecturer::Lecturer(string username, string password, string first_name, string last_name, string contact, string email, vector<string>&modules)
    : Person(username, password, first_name, last_name, contact, email)
{
    vector <string> res;
    for(int i = 0; i < modules.size(); ++i){
        this->modules.push_back(modules[i]);
    }
    
}

void Lecturer::addModule(string m){
    vector <string> newModules;
    newModules = split(m, ", ");
    for(auto module : newModules){
        modules.push_back(module);
    }
    sort(modules.begin(), modules.end());
    modules.erase(unique(modules.begin(), modules.end()), modules.end());

}

void Lecturer::deleteModule(string m){
    vector <string> removeModules;
    removeModules = split(m, ", ");
    for(auto module : removeModules){
        modules.erase(remove(modules.begin(), modules.end(), module), modules.end());
    }
    
}

const string Lecturer::getType() const{
    return type;
}



void Lecturer::showModules(){
    sort(modules.begin(), modules.end());
    for (int i = 0; i < modules.size(); i++){
        if(i != 0){
            cout << ", " << modules.at(i);
        }else{
            cout << modules.at(i);
        }
    }
}

void Lecturer::DisplayDetails(){
    cout << "==============================" << endl;
    cout << "Name: " << getFirst() << " " << getLast() << endl;
    cout << "Contact: " << getContact() << endl;
    cout << "Email: " << getEmail() << endl;
    cout << "Module teaching: ";
    showModules();
    cout << endl;
}


#endif