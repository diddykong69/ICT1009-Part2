#include <iostream>
#include <cstdlib>
#include <string>
#include "menu.h"
#include "Student.h"
#include "Lecturer.h"
#include "Authentication.h"
#include "admin.h"
#include "Programmes.h"
#include "fmt/core.h"

Admin admin;
Programmes programmes;
sqlDB conn;

enum class Roles
{
    adminRole,
    lecturerRole,
    studentRole
};

void adminOption1()
{
    admin.add_user("student");
}

void adminOption2()
{
    if (int result{
                conn.query(
                        "SELECT First_name, Last_name, admission_number, "
                        "email_address, password FROM users WHERE role = 'student'"
                )
        };
            result != 0)
    {
        fmt::print(
                stderr,
                fg(fmt::color::red),
                "Something went wrong. We weren't able to get any students "
                "for you to edit.\nPlease try again.\n"
        );
    }

    conn.print();
    admin.edit_user<std::string>();
}

void adminOption3()
{
    admin.add_user("lecturer");
}

void adminOption4()
{
    if (int result{
                conn.query(
                        "SELECT First_name, Last_name, admission_number, "
                        "email_address, password FROM users WHERE "
                        "role = 'lecturer';"
                )
        };
            result != 0)
    {
        fmt::print(
                stderr,
                fg(fmt::color::red),
                "Something went wrong. We weren't able to get any lecturers.\n"
                "Please try again.\n"
        );
    }

    conn.print();
    admin.edit_user<std::string>();
}

void adminOption5()
{
    std::string admissionNum{};
    std::string moduleName{};

    int result{};

    map<int, map<string, string>> studentInfo{};

    result = conn.query(
            "SELECT First_name, Last_name, admission_number "
            "FROM users WHERE role = 'student'"
    );

    if (result != 0)
    {
        fmt::print(
                stderr,
                fg(fmt::color::red),
                "Something went wrong. We weren't able to get any students.\n"
                "Please try again.\n"
        );
    }

    conn.print();

    fmt::print(
            "Enter the admission number of the student you want to assign "
            "a module to:\n"
    );

    std::cin >> admissionNum;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    result = conn.query(
            fmt::format(
                    "SELECT * FROM users WHERE admission_number = '{}' AND "
                    "role = 'student';",
                    admissionNum
            )
    );

    if (result != 0)
    {
        fmt::print(
                stderr,
                fg(fmt::color::red),
                "Something went wrong. Unable to obtain student {}.\n"
                "Please try again.\n",
                admissionNum
        );
    }

    studentInfo = conn.response;

    Student studentGettingModule(studentInfo[0]["admission_number"]);

    studentGettingModule = studentInfo;

    fmt::print(
            "Enter the name of the module student {} {} will take:\n",
            studentInfo[0]["First_name"],
            studentInfo[0]["Last_name"]
    );

    getline(std::cin, moduleName);

    Module academicModule(moduleName);

    if (studentGettingModule.addModule(academicModule) == 0)
    {
        result = conn.query(
                fmt::format(
                        "INSERT INTO student (admission_number, module, "
                        "grade) VALUES ('{admission_number}', '{module}', "
                        "'{grade}');",
                        fmt::arg(
                                "admission_number",
                                studentGettingModule.getMatriCode()
                        ),
                        fmt::arg("module", moduleName),
                        fmt::arg(
                                "grade",
                                studentGettingModule.getGrades(moduleName)
                        )
                )
        );

        if (result != 0)
        {
            fmt::print(
                    stderr,
                    fg(fmt::color::red),
                    "Failed to add student {name} to the module "
                    "{moduleName}",
                    fmt::arg("name", studentGettingModule.getName()),
                    fmt::arg("moduleName", moduleName)
            );
        }

        fmt::print(
                "Successfully added module {moduleName} to student {name}\n",
                fmt::arg("moduleName", moduleName),
                fmt::arg("name", studentGettingModule.getName())
        );

        studentGettingModule.displayDetails();
    }
}

void adminOption6()
{
    int result{};

    std::string admissionNum{};
    std::string moduleName{};

    map<int, map<string, string>> studentInfo{};

    result = conn.query(
            "SELECT First_name, Last_name, users.admission_number, module, "
            "grade FROM student, users WHERE student.admission_number = "
            "users.admission_number;"
    );

    if (result != 0)
    {
        fmt::print(
                stderr,
                fg(fmt::color::red),
                "Something went wrong. Unable to obtain students.\n"
                "Please try again.\n"
        );
    }

    conn.print();

    fmt::print(
            "Enter the admission number of the student you want to remove "
            "a module from:\n"
    );

    std::cin >> admissionNum;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    result = conn.query(
            fmt::format(
                    "SELECT * FROM users WHERE admission_number = '{}' AND "
                    "role = 'student';",
                    admissionNum
            )
    );

    if (result != 0)
    {
        fmt::print(
                stderr,
                fg(fmt::color::red),
                "Something went wrong. Unable to obtain student {}.\n"
                "Please try again.\n",
                admissionNum
        );
    }

    studentInfo = conn.response;

    Student studentLosingModule(conn.response[0]["admission_number"]);

    studentLosingModule = studentInfo;

    fmt::print(
            "Enter the name of the module student {} will be removed from:\n",
            studentLosingModule.getName()
    );

    getline(std::cin, moduleName);

    Module academicModule(moduleName);

    studentLosingModule.deleteModule(academicModule);

    result = conn.query(
            fmt::format(
                    "DELETE FROM student WHERE admission_number = "
                    "'{admission_number}' AND module = '{module_name}';",
                    fmt::arg("admission_number", admissionNum),
                    fmt::arg("module_name", moduleName)
            )
    );

    if (result != 0)
    {
        fmt::print(
                stderr,
                fg(fmt::color::red),
                "The module {module_name} could not be removed from student "
                "{admission_number}. Please try again.\n",
                fmt::arg("module_name", moduleName),
                fmt::arg("admission_number", admissionNum)
        );
    }

    fmt::print(
            "The module {module_name} has been successfully removed from "
            "student {admission_number}.\n",
            fmt::arg("module_name", moduleName),
            fmt::arg("admission_number", admissionNum)
    );

    studentLosingModule.displayDetails();
}

void adminOption7()
{
    programmes.createProgramme();
}

void adminOption8()
{
    programmes.displayProgrammes();
}

void adminOption9()
{
    programmes.updateProgramme();
}

void adminOption10()
{
    programmes.addCurriculum();
}

void adminOption11()
{
    programmes.removeCurriculum();
}

void lecturerOption1()
{
    fmt::print("Showing all students\n");
    admin.view_users("student");
}

void lecturerOption2()
{
    int result{};
    std::string admissionNum{};
    std::string moduleName{};
    std::string score{};

    result = conn.query(
            "SELECT users.First_name, users.Last_name, users.admission_number, "
            "student.module, student.grade FROM users, student WHERE "
            "users.admission_number = student.admission_number"
    );

    if (result != 0)
    {
        fmt::print(
                stderr,
                fg(fmt::color::red),
                "Something went wrong. Unable to obtain students.\n"
                "Please try again.\n"
        );
    }

    conn.print();

    fmt::print(
            "Enter the admission number of the student you would like to "
            "grade:\n"
    );

    std::cin >> admissionNum;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    result = conn.query(
            fmt::format(
                    "SELECT * FROM users WHERE admission_number COLLATE NOCASE "
                    "= '{}' AND role = 'student'",
                    admissionNum
            )
    );

    if (result != 0)
    {
        fmt::print(
                stderr,
                fg(fmt::color::red),
                "Something went wrong. Unable to obtain student {}.\n"
                "Please try again.\n",
                admissionNum
        );
    }

    Student studentToGrade(conn.response[0]["admission_number"]);
    studentToGrade.showModules();

    if (studentToGrade.getTakingModules() > 0)
    {
        fmt::print("Enter the name of the module you would like to grade:\n");
        getline(std::cin, moduleName);

        fmt::print("Enter a score (E.g. 75):\n");
        std::cin >> score;
        std::cin.clear();
        std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
        );

        studentToGrade.setGrades(moduleName, std::stoi(score));
        studentToGrade.displayDetails();
    }
}

void logOut()
{
    fmt::print("Goodbye!\n");
    std::exit(EXIT_SUCCESS);
}

int main()
{
    bool loggedIn{true};

    const std::map<std::string, Roles, std::less<>> roles{
            {"adminRole",    Roles::adminRole},
            {"lecturerRole", Roles::lecturerRole},
            {"studentRole",  Roles::studentRole}
    };

    Authentication user{};

    try
    {
        if (!user.authenticate())
        {
            return -1;
        }

        std::string role{user.getRole()};
        std::ranges::transform(
                role.begin(),
                role.end(),
                role.begin(),
                ::tolower
        );

        role = fmt::format("{}Role", role);

        while (loggedIn)
        {
            switch (roles.at(role))
            {
                case Roles::adminRole:
                {
                    Admin administrator(
                            user.getMatriCode(),
                            user.getUsername(),
                            user.getFirstName(),
                            user.getLastName(),
                            user.getEmail()
                    );

                    Menu adminMenu(
                            fmt::format(
                                    "Hello {}! What would you like to do "
                                    "today?",
                                    administrator.getName()
                            )
                    );

                    adminMenu.addItem("Add students", &adminOption1);
                    adminMenu.addItem("Edit students", &adminOption2);
                    adminMenu.addItem("Add lecturers", &adminOption3);
                    adminMenu.addItem("Edit lecturers", &adminOption4);
                    adminMenu.addItem("Add modules to student", &adminOption5);
                    adminMenu.addItem("Remove modules from student",
                                      &adminOption6);
                    adminMenu.addItem("Create a programme", &adminOption7);
                    adminMenu.addItem("View info about a programme",
                                      &adminOption8);
                    adminMenu.addItem("Update existing programme",
                                      &adminOption9);
                    adminMenu.addItem(
                            "Add 1 or more module(s) to a programme",
                            &adminOption10
                    );
                    adminMenu.addItem(
                            "Remove 1 or more module(s) from a programme",
                            &adminOption11
                    );
                    adminMenu.addItem("Log out", &logOut);
                    adminMenu.printMenu();

                    break;
                }
                case Roles::lecturerRole:
                {
                    Lecturer lecturer(
                            user.getMatriCode(),
                            user.getUsername(),
                            user.getFirstName(),
                            user.getLastName(),
                            user.getEmail()
                    );

                    Menu lecturerMenu(
                            fmt::format(
                                    "Hello {}! What would you like to do "
                                    "today?",
                                    lecturer.getName()
                            )
                    );

                    lecturerMenu.addItem("View students", &lecturerOption1);
                    lecturerMenu.addItem(
                            "Assign module grades to students",
                            &lecturerOption2
                    );

                    lecturerMenu.addItem("Log out", &logOut);
                    lecturerMenu.printMenu();

                    break;
                }
                case Roles::studentRole:
                {
                    Student student(
                            user.getMatriCode(),
                            user.getUsername(),
                            user.getFirstName(),
                            user.getLastName(),
                            user.getEmail()
                    );

                    student.displayDetails();

                    loggedIn = false;

                    break;
                }
                default:
                    loggedIn = false;
            }
        }
    }
    catch (int e)
    {
        fmt::print(
                stderr,
                fg(fmt::color::red),
                "Error code: {}\n",
                e
        );
    }

    return 0;
}