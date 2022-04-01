#include "Programmes.h"

Programmes::Programmes() = default;

void Programmes::createProgramme()
{
    setProgrammeName();
    setAboutProgramme();
    setProgrammeCredits();
    setProgrammeDuration();
    setProgrammeEligibility();
    setDegree();

    std::string insertQuery = fmt::format(
            "INSERT INTO programmes (programme_name, programme_description, "
            "programme_credits, programme_duration, programme_eligibility, "
            "degree, created_by, updated_by) VALUES ('{programmeName}', "
            "'{aboutProgramme}', {programmeCredits}, {programmeDuration}, "
            "'{programmeEligibility}', '{programmeDegree}', '{createdBy}', "
            "'{updatedBy}');",
            fmt::arg("programmeName", this->programmeName),
            fmt::arg("aboutProgramme", this->aboutProgramme),
            fmt::arg("programmeCredits", this->programmeCredits),
            fmt::arg("programmeDuration", this->programmeDuration),
            fmt::arg("programmeEligibility", this->eligibility),
            fmt::arg("programmeDegree", this->programmeDegree),
            fmt::arg("createdBy", 1),
            fmt::arg("updatedBy", 1)
    );

    this->sqlQuery = this->database.query(insertQuery);

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

void Programmes::setProgrammeName()
{
    fmt::print("What will the new programme be called?\n");
    getline(std::cin, this->programmeName);
}

void Programmes::setAboutProgramme()
{
    fmt::print("What will the programme {} be about?\n", this->programmeName);
    getline(std::cin, this->aboutProgramme);
}

void Programmes::setProgrammeCredits()
{
    fmt::print(
            "What will the total credit be for the programme {}\n",
            this->programmeName
    );
    std::cin >> this->programmeCredits;
    std::cin.ignore();
}

void Programmes::setProgrammeDuration()
{
    fmt::print(
            "How long will it take to complete the programme {} (in months)\n",
            this->programmeName
    );
    std::cin >> this->programmeDuration;
    std::cin.ignore();
}

void Programmes::setProgrammeEligibility()
{
    fmt::print(
            "What are the requirements to enroll in the programme {}?\n",
            this->programmeName
    );
    getline(std::cin, this->eligibility);
}

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

    fmt::print(
            "Choose which degree a student of this programme ({0})\nwill {1}\n",
            this->programmeName,
            "get at the end of the programme"
    );

    int index{1};
    for (const std::string &degree: degrees)
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
    this->programmeDegree = degrees[selectedDegreeIndex];
}

void Programmes::displayProgrammes()
{
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

    database.print();
}

//int main()
//{
//    Programmes p1;
//    p1.createProgramme();
//    p1.displayProgrammes();
//
//    return 0;
//}