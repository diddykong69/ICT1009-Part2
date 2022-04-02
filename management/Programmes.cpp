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
    setDegree();

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
                fg(fmt::color::red),
                "Something went wrong. The programme {} could not be created.\n"
                "Please try again.\n",
                this->programmeName
        );
    }
    else
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
void Programmes::setProgrammeProperties(const string &question,
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
        }
        else
        {
            if (ss >> *propertyToSet && !this->userInput.empty())
            {
                canBreak = true;
            }
        }
    }
}

/**
 * Ask user what degree a student of the programme can obtain upon completing
 * the programme
 */
void Programmes::setDegree()
{
    int selectedDegreeIndex{};

    this->degrees = {
            "Bachelor of Accountancy with Honours (BAcc (Hons))",
            "Bachelor of Arts (BA)",
            "Bachelor of Business (BBus)",
            "Bachelor of Business Administration (BBA)",
            "Bachelor of Engineering with Honours (BEng (Hons))",
            "Bachelor of Fine Arts",
            "Bachelor of Food Techology with Honours (BFT (Hons))",
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
            "Master of Engineering Techology (MEngTech)",
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
                this->programmeName
        );

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
        std::cin.ignore();

        if (selectedDegreeIndex - 1 >= 0 &&
            selectedDegreeIndex <= degrees.size())
        {
            break;
        }
    }

    this->programmeDegree = this->degrees[selectedDegreeIndex - 1];
}

void Programmes::displayProgrammes()
{
    int programmeIndex{};

    this->sqlQuery = this->database.query(
            "SELECT programme_name, programme_description, programme_credits, "
            "programme_duration, programme_eligibility, degree FROM programmes;"
    );

    if (this->sqlQuery != 0)
    {
        fmt::print(
                fg(fmt::color::red),
                "Something went wrong. The programmes could not be displayed.\n"
                "Please try again.\n",
                this->programmeName
        );
    }

    while (programmeIndex != this->database.response.size() + 1)
    {
        fmt::print(
                "Programmes available in SIT "
                "(Enter the programme's index no. for more info!)\n"
        );

        for (int i = 0; i < this->database.response.size(); i++)
        {
            fmt::print(
                    "{}) {}\n",
                    i + 1,
                    this->database.response[i]["programme_name"]
            );
        }

        fmt::print("{}) Go back\n", this->database.response.size() + 1);

        fmt::print("View more info about programme: ");
        std::cin >> programmeIndex;
        std::cin.ignore();

        if (programmeIndex >= 1 && programmeIndex <= database.response.size())
        {
            fmt::print(
                    fmt::emphasis::underline,
                    "{}\n",
                    database.response[programmeIndex - 1]["programme_name"]
            );

            fmt::print(
                    "About:\n{about}\n\nTotal credits:\n{credits}\n\n"
                    "Duration:\n{duration}\n\nDegree:\n{degree}\n\n"
                    "Eligibility:\n{eligibility}\n\n",
                    fmt::arg(
                            "about",
                            this->database.response
                            [programmeIndex - 1]["programme_description"]
                    ),
                    fmt::arg(
                            "credits",
                            this->database.response
                            [programmeIndex - 1]["programme_credits"]
                    ),
                    fmt::arg(
                            "duration",
                            this->database.response
                            [programmeIndex - 1]["programme_duration"]
                    ),
                    fmt::arg(
                            "degree",
                            this->database.response
                            [programmeIndex - 1]["degree"]
                    ),
                    fmt::arg(
                            "eligibility",
                            this->database.response
                            [programmeIndex - 1]["programme_eligibility"]
                    )
            );
        }
        else if (programmeIndex == this->database.response.size() + 1)
        {
            // Go back
        }
    }
}


int main()
{
    Programmes p1;
//    p1.createProgramme();
    p1.displayProgrammes();

    return 0;
}