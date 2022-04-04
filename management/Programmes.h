#ifndef ICT1009_PART2_PROGRAMMES_H
#define ICT1009_PART2_PROGRAMMES_H

#include <iostream>
#include <vector>
#include <sstream>
#include "../sql/sqlDB.h"
#include "fmt/core.h"
#include "fmt/color.h"

class Programmes
{
public:
    Programmes();

    void createProgramme();

    void displayProgrammes();

    void updateProgramme();

private:
    sqlDB database{};

    int sqlQuery{};
    int programmeCredits{};
    int programmeDuration{};

    std::string programmeName{};
    std::string aboutProgramme{};
    std::string eligibility{};
    std::string programmeDegree{};
    std::string userInput{};

    std::vector<std::string> degrees{};

    template<typename T>
    void setProgrammeProperties(const std::string &question, T *propertyToSet);

    void setDegree(
            const std::string &nameOfProgramme,
            const std::string &currDegree = "",
            bool isUpdate = false
    );

    void getAllProgrammes();

    std::string monthToYearMonth(int durationInMonths);

    void displayProgrammesMenu(
            const std::string_view &topText,
            const std::string_view &bottomText
    );

    template<typename T>
    void setUpdateQuery(const std::string &colName, T newVal, int id);

    void updateProgrammeProperty(
            std::map<int, std::map<std::string, std::string>> &results,
            int programmeIndex
    );
};

#endif //ICT1009_PART2_PROGRAMMES_H