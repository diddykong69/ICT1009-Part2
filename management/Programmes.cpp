#include "Programmes.h"

Programmes::Programmes() = default;

/**
 * Creates a new programme
 */
void Programmes::createProgramme()
{
    auto askProgrammeName{
            fmt::format("What will the new programme be called?\n")
    };

    // Ask what the programme name would be & set it
    setProgrammeProperties(askProgrammeName, &this->programmeName);

    auto askAboutProgramme{
            fmt::format(
                    "What will the programme {} be about?\n",
                    this->programmeName
            )
    };

    // Ask what the programme is about & set it
    setProgrammeProperties(askAboutProgramme, &this->aboutProgramme);

    auto askProgrammeCredit{
            fmt::format(
                    "What will the total credit be for the programme {}\n",
                    this->programmeName
            )
    };

    // Ask what the total credits for the programme will be & set it
    setProgrammeProperties(askProgrammeCredit, &this->programmeCredits);

    auto askProgrammeDuration{
            fmt::format(
                    "How long will it take to complete the programme {} "
                    "(in months)\n",
                    this->programmeName
            )
    };

    // Ask how long the programme will be & set it
    setProgrammeProperties(askProgrammeDuration, &this->programmeDuration);

    auto askProgrammeEligibility{
            fmt::format(
                    "What are the requirements needed to be eligible for this "
                    "programme ({})?\n",
                    this->programmeName
            )
    };

    // Ask what the requirements to be eligible for the programme are & set it
    setProgrammeProperties(askProgrammeEligibility, &this->eligibility);

    /* Ask what degree a student of the programme can get upon completion & set
     it */
    setDegree(this->programmeName);

    // Create an INSERT INTO query for creating the programme
    auto insertQuery = fmt::format(
            "INSERT INTO programmes (programme_name, programme_description, "
            "programme_credits, programme_duration, programme_eligibility, "
            "degree) VALUES ('{programmeName}', '{aboutProgramme}', "
            "{programmeCredits}, {programmeDuration}, '{programmeEligibility}',"
            " '{programmeDegree}');",
            fmt::arg("programmeName", this->programmeName),
            fmt::arg("aboutProgramme", this->aboutProgramme),
            fmt::arg("programmeCredits", this->programmeCredits),
            fmt::arg("programmeDuration", this->programmeDuration),
            fmt::arg("programmeEligibility", this->eligibility),
            fmt::arg("programmeDegree", this->programmeDegree)
    );

    // Execute the INSERT INTO query
    this->sqlQuery = this->database.query(insertQuery);

    // Check if query was successfully executed
    if (this->sqlQuery != 0)
    {
        fmt::print(
                stderr,
                fg(fmt::color::red),
                "Something went wrong. The programme {} could not be created.\n"
                "Please try again.\n",
                this->programmeName
        );
    } else
    {
        fmt::print("Programme successfully created!\n");
    }
}

/**
 * Set the name, description, total credits, duration, eligibility & obtainable
 * degree of the programme to be created
 * @param question The question to ask user
 * @param propertyToSet The property (i.e. class variable) to set
 */
template<typename T>
void Programmes::setProgrammeProperties(const std::string &question,
                                        T *propertyToSet)
{
    bool canBreak{false};

    auto strProgrammeCreditsMemoryAddress{
            fmt::format("{}", fmt::ptr(&this->programmeCredits))
    };

    auto strProgrammeDurationMemoryAddress{
            fmt::format("{}", fmt::ptr(&this->programmeDuration))
    };

    auto strPropertyToSetMemoryAddress{
            fmt::format("{}", fmt::ptr(&*propertyToSet))
    };

    while (!canBreak)
    {
        fmt::print("{}", question);

        getline(std::cin, this->userInput);

        if (this->userInput.empty())
        {
            continue;
        }

        std::stringstream ss(this->userInput);

        if (strPropertyToSetMemoryAddress
            == strProgrammeCreditsMemoryAddress
            || strPropertyToSetMemoryAddress
               == strProgrammeDurationMemoryAddress)
        {
            if (ss >> *propertyToSet
                && ss.eof()
                && std::stoi(this->userInput) > 0)
            {
                canBreak = true;
            }
        } else
        {
            if constexpr (std::is_same_v<T, std::string>)
            {
                getline(ss, *propertyToSet);
                canBreak = true;
            }
        }
    }
}

/**
 * Ask user what degree a student of the programme can obtain upon completing
 * the programme
 */
void Programmes::setDegree(
        const std::string &nameOfProgramme,
        const std::string &currDegree,
        bool isUpdate
)
{
    int selectedDegreeIndex{};

    this->degrees = {
            "Bachelor of Accountancy with Honours (BAcc (Hons))",
            "Bachelor of Arts (BA)",
            "Bachelor of Business (BBus)",
            "Bachelor of Business Administration (BBA)",
            "Bachelor of Engineering with Honours (BEng (Hons))",
            "Bachelor of Fine Arts",
            "Bachelor of Food Technology with Honours (BFT (Hons))",
            "Bachelor of Hospitality Business with Honours (BHB (Hons))",
            "Bachelor of Medicine, Bachelor of Surgery (MBBS)",
            "Bachelor of Science with Honours (BSc (Hons))",
            "Bachelor of Science in Business Administration (BSBA)",
            "Bachelor of Social Science (BSS)",
            "Master of Accountancy (MAcc)",
            "Master of Applied Science (MASc)",
            "Master of Arts (MA)",
            "Master of Arts in Teaching (MAT)",
            "Master of Business (MBus)",
            "Master of Business Administration (MBA)",
            "Master of Clinical Research (MClinRes)",
            "Master of Education (MEd)",
            "Master of Engineering (MEng)",
            "Master of Engineering Technology (MEngTech)",
            "Master of Public Administration (MPA)",
            "Master of Science (MSc)",
            "Doctor of Clinical Research (DClinRes)",
            "Doctor of Education (EdB)",
            "Doctor of Engineering (DEng)",
            "Doctor of Philosophy (PhD)"
    };

    while (true)
    {
        fmt::print(
                "Choose which degree a student of this programme "
                "({})\nwill get at the end of the programme\n",
                nameOfProgramme
        );

        if (isUpdate)
        {
            fmt::print(
                    "(Current: {})\n",
                    currDegree
            );
        }

        int index{1};
        for (const std::string &degree: this->degrees)
        {
            fmt::print(
                    "{index}) {degree}\n",
                    fmt::arg("index", index),
                    fmt::arg("degree", degree)
            );
            index++;
        }

        fmt::print("Degree selected: ");
        std::cin >> selectedDegreeIndex;
        std::cin.clear();
        std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
        );

        if (selectedDegreeIndex - 1 >= 0 &&
            selectedDegreeIndex <= degrees.size())
        {
            break;
        }
    }

    this->programmeDegree = this->degrees[selectedDegreeIndex - 1];
}

/**
 * Get every programme found in the database
 * 
 * @return int 0 if successful, 1 if fail
 */
int Programmes::getAllProgrammes()
{
    this->sqlQuery = this->database.query(
            "SELECT * FROM programmes;"
    );

    if (this->sqlQuery != 0)
    {
        fmt::print(
                fg(fmt::color::red),
                "Something went wrong. The programmes could not be displayed.\n"
                "Please try again.\n",
                this->programmeName
        );

        return -1;
    }

    return 0;
}

/**
 * Convert months to year months (E.g. 38 months -> 3 year(s) 2 month(s))
 */
std::string Programmes::monthToYearMonth(int durationInMonths)
{
    std::string duration{};
    std::string year{};
    std::string month{};

    year = fmt::format(
            "{} year(s) ",
            fmt::to_string(durationInMonths / 12)
    );
    month = fmt::format(
            "{} month(s)",
            fmt::to_string(durationInMonths - std::stoi(year) * 12)
    );

    duration = fmt::format(
            "{year}{month}",
            fmt::arg(
                    "year",
                    year = year == "0 year(s) " ? "" : year
            ),
            fmt::arg(
                    "month",
                    month = month == "0 month(s)" ? "" : month
            )
    );

    return duration;
}

/**
 * Show info about a programme
 */
void Programmes::displayProgrammes()
{
    int programmeIndex{};

    getAllProgrammes();

    while (programmeIndex != this->database.response.size() + 1)
    {
        Menu::displayProgrammesOrModulesMenu(
                "Programmes available in SIT "
                "(Enter the programme's index no. for more info!)\n",
                "View more info about programme: ",
                this->database.response,
                this->userInput
        );

        std::stringstream ss(this->userInput);

        if (ss >> programmeIndex && ss.eof())
        {
            if (programmeIndex >= 1
                && programmeIndex <= database.response.size())
            {
                fmt::print(
                        fmt::emphasis::underline,
                        "{}\n",
                        this->database.response[programmeIndex - 1]
                        ["programme_name"]
                );

                fmt::print(
                        "About:\n{about}\n\nTotal credits:\n{credits}\n\n"
                        "Duration:\n{duration}\n\nDegree:\n{degree}\n\n"
                        "Eligibility:\n{eligibility}\n\n",
                        fmt::arg(
                                "about",
                                this->database.response
                                [programmeIndex -
                                 1]["programme_description"]
                        ),
                        fmt::arg(
                                "credits",
                                this->database.response
                                [programmeIndex - 1]["programme_credits"]
                        ),
                        fmt::arg(
                                "duration",
                                monthToYearMonth(
                                        std::stoi(
                                                this->database.response
                                                [programmeIndex - 1]
                                                ["programme_duration"]
                                        )
                                )
                        ),
                        fmt::arg(
                                "degree",
                                this->database.response
                                [programmeIndex - 1]["degree"]
                        ),
                        fmt::arg(
                                "eligibility",
                                this->database.response
                                [programmeIndex -
                                 1]["programme_eligibility"]
                        )
                );
            }
        }
    }
}

/**
 * Query for updating programmes
 * @param colName Column to update
 * @param newVal The new value that the column will have
 * @param id Which row to update
 * @return 0 if successful, -1 if not
 */
template<typename T>
int Programmes::setUpdateQuery(const std::string &colName, T newVal, int id)
{
    auto updateQuery = fmt::format(
            "UPDATE programmes SET {column_name} = {value} WHERE "
            "programme_id = {id};",
            fmt::arg("column_name", colName),
            fmt::arg("value", newVal),
            fmt::arg("id", id)
    );

    this->sqlQuery = this->database.query(updateQuery);

    if (this->sqlQuery != 0)
    {
        fmt::print(
                fg(fmt::color::red),
                "Failed to update. Please try again.\n"
        );

        return -1;
    }

    return 0;
}

/**
 *
 * @param results A map containing the values of every programme
 * @param programmeIndex The index of the programme user selected
 */
void Programmes::updateProgrammeProperty(
        map<int, map<string, string>> &results,
        int programmeIndex
)
{
    int userSelection{};
    int id;
    int currCredits{
            std::stoi(results[programmeIndex]["programme_credits"])
    };
    int currDuration{
            std::stoi(results[programmeIndex]["programme_duration"])
    };

    std::string colName;
    std::string currProgrammeName{
            results[programmeIndex]["programme_name"]
    };
    std::string duration{};
    std::string year{};
    std::string month{};
    std::string currDegree{
            results[programmeIndex]["degree"]
    };

    while (userSelection != 7)
    {
        fmt::print(
                "(Programme: {})\nWhat would you like to update?\n"
                "1) Name\n2) Description\n3) Total credits\n"
                "4) Duration\n5) Eligibility\n6) Degree\n"
                "7) Update another programme\nUpdate: ",
                currProgrammeName
        );

        getline(std::cin, this->userInput);
        std::stringstream ss(this->userInput);

        if (ss >> userSelection && ss.eof())
        {
            id = std::stoi(results[programmeIndex]["programme_id"]);

            switch (userSelection)
            {
                case 1:
                    setProgrammeProperties(
                            fmt::format(
                                    "What would you like to rename the "
                                    "programme {} to?"
                                    "\n",
                                    currProgrammeName
                            ),
                            &this->programmeName
                    );

                    colName = "programme_name";

                    setUpdateQuery(
                            colName,
                            fmt::format("'{}'", this->programmeName),
                            id
                    );

                    currProgrammeName = this->programmeName;
                    break;

                case 2:
                    setProgrammeProperties(
                            fmt::format(
                                    "What would the programme {} be about?\n",
                                    currProgrammeName
                            ),
                            &this->aboutProgramme
                    );

                    colName = "programme_description";

                    setUpdateQuery(
                            colName,
                            fmt::format("'{}'", this->aboutProgramme),
                            id
                    );

                    break;

                case 3:
                    setProgrammeProperties(
                            fmt::format(
                                    "What would you like to change the total "
                                    "credits for the programme {name} to?\n"
                                    "(Current: {credits} credits)\n",
                                    fmt::arg("name", currProgrammeName),
                                    fmt::arg("credits", currCredits)
                            ),
                            &this->programmeCredits
                    );

                    colName = "programme_credits";

                    setUpdateQuery(
                            colName,
                            this->programmeCredits,
                            id
                    );

                    currCredits = this->programmeCredits;
                    break;

                case 4:
                    duration = monthToYearMonth(currDuration);

                    setProgrammeProperties(
                            fmt::format(
                                    "What would you like to change the total "
                                    "duration of the programme {name} to "
                                    "(in months)?\n(Current: {duration})\n",
                                    fmt::arg("name", currProgrammeName),
                                    fmt::arg("duration", duration)
                            ),
                            &this->programmeDuration
                    );

                    colName = "programme_duration";

                    setUpdateQuery(
                            colName,
                            this->programmeDuration,
                            id
                    );

                    currDuration = this->programmeDuration;

                    break;

                case 5:
                    setProgrammeProperties(
                            fmt::format(
                                    "What are the new requirements needed to be "
                                    "eligible for the programme {}?\n",
                                    currProgrammeName
                            ),
                            &this->eligibility
                    );

                    colName = "programme_eligibility";

                    setUpdateQuery(
                            colName,
                            fmt::format("'{}'", this->eligibility),
                            id
                    );

                    break;

                case 6:
                    setDegree(currProgrammeName, currDegree, true);

                    colName = "degree";

                    setUpdateQuery(
                            colName,
                            fmt::format("'{}'", this->programmeDegree),
                            id
                    );

                    currDegree = this->programmeDegree;

                    break;

                default:
                    break;
            }
        }
    }
}

/**
 * Update a programme
 */
void Programmes::updateProgramme()
{
    int programmeIndex{};

    map<int, map<string, string>> results{};

    while (programmeIndex != results.size() + 1)
    {
        getAllProgrammes();
        results = this->database.response;

        Menu::displayProgrammesOrModulesMenu(
                "Which programme would you like to make changes to?\n",
                "Update programme: ",
                results,
                this->userInput
        );

        std::stringstream ss(this->userInput);

        if (ss >> programmeIndex
            && ss.eof()
            && programmeIndex >= 1
            && programmeIndex <= results.size())
        {
            updateProgrammeProperty(results, programmeIndex - 1);
        }
    }
}

/**
 * Extract every integer from a given string using regex & store any matches in
 * a set
 * @param extractFrom The string to extract integers from
 * @return A set with all the integers found in the given string
 */
std::set<int> Programmes::intFromStr(const std::string &extractFrom)
{
    std::set<int> extractedIntegers{};
    regex pattern("[0-9]+");

    for (auto it = sregex_iterator(extractFrom.begin(), extractFrom.end(),
                                   pattern);
         it != sregex_iterator();
         it++)
    {
        smatch match = *it;
        extractedIntegers.insert(std::stoi(match.str(0)));
    }

    return extractedIntegers;
}

/**
 * Check how much credit a programme has left
 * @param selectedProgrammeID The id of the programme to check
 * @return The credits a programme has left
 */
int Programmes::getCreditsLeft(int selectedProgrammeID)
{
    this->sqlQuery = this->database.query(
            fmt::format(
                    "SELECT programme_credits FROM programmes WHERE "
                    "programme_id = {}",
                    selectedProgrammeID
            )
    );

    int currCredits{std::stoi(this->database.response[0]["programme_credits"])};

    this->sqlQuery = this->database.query(
            fmt::format(
                    "SELECT module_credit FROM modules WHERE module_id "
                    "IN (SELECT module_id from curricula where "
                    "programme_id = {});",
                    selectedProgrammeID
            )
    );

    if (this->sqlQuery != 0)
    {
        fmt::print(
                stderr,
                fg(fmt::color::red),
                "Unable to retrieve the credits of modules already "
                "assigned to {}\n",
                this->programmeName
        );
    }

    for (auto a = 0;
         a < this->database.response.size() && currCredits - std::stoi(
                 this->database.response[a]["module_credit"]
         ) >= 0; a++)
    {
        currCredits -= std::stoi(
                this->database.response[a]["module_credit"]
        );
    }

    return currCredits;
}

/**
 * Check if there's enough credit for a module to be assigned to a programme
 * @param selectedProgrammeID the programme's id
 * @param moduleCredit How much credit a module is
 * @return true if insufficient, else false
 */
bool Programmes::insufficientCredits(int selectedProgrammeID, int moduleCredit)
{
    int currCredits{getCreditsLeft(selectedProgrammeID)};

    if (currCredits - moduleCredit < 0)
    {
        fmt::print(
                fg(fmt::color::red),
                "Unable to add module. Insufficient credit.\nTotal "
                "credits: {total}\nCredits left: {left}\n",
                fmt::arg("total", this->programmeCredits),
                fmt::arg("left", currCredits)
        );

        return true;
    }

    return false;
}

/**
 * Continuation from addCurriculum()
 * @param selectedProgrammeID The programme_id of the programme modules are to
 * be assigned to
 */
void Programmes::addModulesToProgramme(int selectedProgrammeID)
{
    std::map<int, std::map<std::string, std::string>> allModulesResults{};

    auto canBreak{false};

    auto currCredits{this->programmeCredits};
    int moduleCredit{};
    int moduleID{};

    while (true)
    {
        auto selectModulesQuery{
                fmt::format(
                        "SELECT * FROM modules WHERE module_id NOT IN "
                        "(SELECT module_id FROM curricula WHERE "
                        "programme_id = {});",
                        selectedProgrammeID
                )
        };

        this->sqlQuery = this->database.query(selectModulesQuery);

        // Check if query was successfully executed
        if (this->sqlQuery != 0)
        {
            fmt::print(
                    stderr,
                    fg(fmt::color::red),
                    "Unable to retrieve modules\n"
            );
        }

        allModulesResults = this->database.response;

        Menu::displayProgrammesOrModulesMenu(
                fmt::format(
                        "Which module(s) would you like students of {}\nto "
                        "learn?\n(Note: You can add more than 1 module in 1 go."
                        "Anything can be a delimiter.)\n",
                        this->programmeName
                ),
                "Module(s) selected: ",
                allModulesResults,
                this->userInput,
                true
        );

        for (std::set<int> selectedModules{intFromStr(this->userInput)};
             int i: selectedModules)
        {
            if (i == allModulesResults.size() + 1)
            {
                canBreak = true;
                continue;
            }

            auto selectedModule{
                    fmt::format(
                            "{}: {}",
                            allModulesResults[i - 1]["module_code"],
                            allModulesResults[i - 1]["module_name"]
                    )
            };

            this->sqlQuery = this->database.query(
                    fmt::format(
                            "SELECT module_id, module_credit FROM modules "
                            "WHERE module_code = '{}';",
                            allModulesResults[i - 1]["module_code"]
                    )
            );

            if (this->sqlQuery != 0)
            {
                fmt::print(
                        stderr,
                        fg(fmt::color::red),
                        "Unable to retrieve module id & credits of {}\n",
                        allModulesResults[i - 1]["module_name"]
                );
            }

            moduleID = std::stoi(this->database.response[0]["module_id"]);

            moduleCredit = std::stoi(
                    this->database.response[0]["module_credit"]
            );

            if (insufficientCredits(selectedProgrammeID, moduleCredit))
            {
                continue;
            }

            auto insertQuery{
                    fmt::format(
                            "INSERT INTO curricula (programme_id, module_id) "
                            "VALUES ({programme}, {module});",
                            fmt::arg("programme", selectedProgrammeID),
                            fmt::arg("module", moduleID)
                    )
            };

            this->sqlQuery = this->database.query(insertQuery);

            // Check if query was successfully executed
            if (this->sqlQuery != 0)
            {
                fmt::print(
                        stderr,
                        fg(fmt::color::red),
                        "Unable to add module(s). Please try again.\n"
                );
            } else
            {
                fmt::print(
                        "The module {module} has been successfully assigned\n"
                        "to the programme {programme}.\n",
                        fmt::arg("programme", this->programmeName),
                        fmt::arg("module", selectedModule)
                );

                currCredits -= moduleCredit;
            }
        }

        if (canBreak)
        {
            break;
        }
    }
}

/**
 * Assign module to programme
 */
void Programmes::addCurriculum()
{
    int selectedProgrammeID{};

    std::string selectedModule{};

    getAllProgrammes();

    std::map<int, std::map<std::string, std::string>> allProgrammesResults{
            this->database.response
    };

    std::map<int, std::map<std::string, std::string>> allModulesResults{};

    while (selectedProgrammeID != allProgrammesResults.size() + 1)
    {
        Menu::displayProgrammesOrModulesMenu(
                "Which programme would you like to add modules to?\n",
                "Programme selected: ",
                allProgrammesResults,
                this->userInput
        );

        if (std::stringstream ss(this->userInput);
                ss >> selectedProgrammeID && ss.eof() &&
                selectedProgrammeID >= 1 &&
                selectedProgrammeID <= allProgrammesResults.size())
        {
            this->programmeName = allProgrammesResults[
                    selectedProgrammeID - 1
            ]["programme_name"];

            this->programmeCredits = std::stoi(
                    allProgrammesResults[
                            selectedProgrammeID - 1
                    ]["programme_credits"]);

            addModulesToProgramme(selectedProgrammeID);
        }
    }
}

/**
 * Remove module(s) from a programme (cont.)
 * @param selectedProgrammeIndex The programme to remove module(s) from
 */
void Programmes::removeModulesFromProgramme(int selectedProgrammeIndex)
{
    std::map<int, std::map<std::string, std::string>> allModulesResults{};

    auto canBreak{false};

    auto maxCredits{this->programmeCredits};
    int moduleCredit{};
    int moduleID{};

    while (true)
    {
        auto currCredits{getCreditsLeft(selectedProgrammeIndex)};

        this->sqlQuery = this->database.query(
                fmt::format(
                        "SELECT * FROM modules WHERE module_id IN (SELECT "
                        "module_id FROM curricula WHERE programme_id = {});",
                        selectedProgrammeIndex
                )
        );

        if (this->sqlQuery != 0)
        {
            fmt::print(
                    stderr,
                    fg(fmt::color::red),
                    "Unable to retrieve modules of the programme {}\n",
                    this->programmeName
            );
        }

        allModulesResults = this->database.response;

        Menu::displayProgrammesOrModulesMenu(
                fmt::format(
                        "Which module(s) would you like to remove from the "
                        "programme {}? (Note: You can add more than 1 module"
                        " in 1 go. Anything can be a delimiter.)\n",
                        this->programmeName
                ),
                "Modules to remove: ",
                allModulesResults,
                this->userInput,
                true
        );

        for (std::set<int> selectedModules{intFromStr(this->userInput)};
             int i: selectedModules)
        {
            if (i == allModulesResults.size() + 1)
            {
                canBreak = true;
                continue;
            }

            auto selectedModule{
                    fmt::format(
                            "{}: {}",
                            allModulesResults[i - 1]["module_code"],
                            allModulesResults[i - 1]["module_name"]
                    )
            };

            this->sqlQuery = this->database.query(
                    fmt::format(
                            "SELECT module_id, module_credit FROM modules WHERE "
                            "module_code = '{}';",
                            allModulesResults[i - 1]["module_code"]
                    )
            );

            if (this->sqlQuery != 0)
            {
                fmt::print(
                        stderr,
                        fg(fmt::color::red),
                        "Unable to retrieve module id & credits of {}\n",
                        allModulesResults[i - 1]["module_name"]
                );
            }

            moduleID = std::stoi(this->database.response[0]["module_id"]);

            moduleCredit = std::stoi(
                    this->database.response[0]["module_credit"]
            );

            if (currCredits + moduleCredit > maxCredits)
            {
                fmt::print(
                        "You cannot exceed the total credits set for the "
                        "programme {}",
                        this->programmeName
                );

                continue;
            }

            auto deleteQuery{
                    fmt::format(
                            "DELETE FROM curricula WHERE programme_id = "
                            "{programme_id} AND module_id = {module_id}",
                            fmt::arg("programme_id", selectedProgrammeIndex),
                            fmt::arg("module_id", moduleID)
                    )
            };

            this->sqlQuery = this->database.query(deleteQuery);

            // Check if query was successfully executed
            if (this->sqlQuery != 0)
            {
                fmt::print(
                        stderr,
                        fg(fmt::color::red),
                        "Unable to remove module(s). Please try again.\n"
                );
            } else
            {
                fmt::print(
                        "The module {module} has been successfully removed\n"
                        "from the programme {programme}.\n",
                        fmt::arg("programme", this->programmeName),
                        fmt::arg("module", selectedModule)
                );

                currCredits += moduleCredit;
            }

        }

        if (canBreak)
        {
            break;
        }
    }
}

/**
 * Remove module(s) from a programme
 */
void Programmes::removeCurriculum()
{
    int selectedProgrammeIndex{};

    while (true)
    {
        this->sqlQuery = this->database.query(
                "SELECT programme_id, programme_name, programme_credits from "
                "programmes where programme_id in "
                "(select programme_id from curricula);"
        );
        if (this->sqlQuery != 0)
        {
            fmt::print(
                    stderr,
                    fg(fmt::color::red),
                    "Unable to retrieve curricula\n"
            );
        }

        std::map<int, std::map<std::string, std::string>> curriculaResults
                = this->database.response;

        Menu::displayProgrammesOrModulesMenu(
                "Which programme would you like to remove modules from?\n",
                "Programme selected: ",
                curriculaResults,
                this->userInput
        );

        if (std::stringstream ss(this->userInput);
                ss >> selectedProgrammeIndex && ss.eof() &&
                selectedProgrammeIndex >= 1 &&
                selectedProgrammeIndex <= curriculaResults.size())
        {
            this->programmeName = curriculaResults[
                    selectedProgrammeIndex - 1
            ]["programme_name"];

            this->programmeCredits = std::stoi(
                    curriculaResults[
                            selectedProgrammeIndex - 1
                    ]["programme_credits"]
            );
            removeModulesFromProgramme(selectedProgrammeIndex);
        }

        if (selectedProgrammeIndex == curriculaResults.size() + 1)
        {
            break;
        }
    }
}