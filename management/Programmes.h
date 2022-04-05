#ifndef ICT1009_PART2_PROGRAMMES_H
#define ICT1009_PART2_PROGRAMMES_H

#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include "../sql/sqlDB.h"
#include "Menu.h"
#include "fmt/core.h"
#include "fmt/color.h"

class Menu;

class Programmes
{
public:
    Programmes();

    void createProgramme();

    void displayProgrammes();

    void updateProgramme();

    void addCurriculum();

    void removeCurriculum();

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

    int getAllProgrammes();

    static std::string monthToYearMonth(int durationInMonths);

    template<typename T>
    int setUpdateQuery(const std::string &colName, T newVal, int id);

    void updateProgrammeProperty(
            std::map<int, std::map<std::string, std::string>> &results,
            int programmeIndex
    );

    static std::set<int> intFromStr(const std::string &extractFrom);

    int getCreditsLeft(int selectedProgrammeID);

    bool insufficientCredits(int selectedProgrammeID, int moduleCredit);

    void addModulesToProgramme(int selectedProgrammeID);

    void removeModulesFromProgramme(int selectedProgrammeIndex);
};

#endif //ICT1009_PART2_PROGRAMMES_H