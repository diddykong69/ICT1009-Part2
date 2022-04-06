#ifndef menu_h
#define menu_h

#include <iostream>
#include <stdio.h>
#include <vector>
#include "menu_item.h"
#include "../sql/sqlDB.h"
#include "fmt/core.h"

class Menu
{

public:
    //Constructor & Destructor
    Menu();

    Menu(std::string);

    Menu(void(*)(int));

    Menu(std::string, void(*)(int));

    void addItem(std::string);          // Add item from title
    void addItem(std::string,
                 void(*)());    // Add item from title and function pointer

    // Print Menu
    void printMenu();

    static void displayProgrammesOrModulesMenu(
            const std::string_view &topText,
            const std::string_view &bottomText,
            std::map<int, std::map<std::string, std::string>> &results,
            std::string &userInput,
            bool forModules = false
    );

private:

    // Menu items
    std::vector<MenuItem *> menuItems;

    // Item count
    int count = 0;

    // Menu header
    std::string header;
    bool hasHeader = false;

    // Global callback
    void (*globalCallbackPtr)(int) = nullptr;
};

#endif /* menu_h */