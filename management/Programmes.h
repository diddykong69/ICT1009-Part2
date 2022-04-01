#ifndef ICT1009_PART2_PROGRAMMES_H
#define ICT1009_PART2_PROGRAMMES_H

#include <iostream>
#include <vector>
#include "../sql/sqlDB.h"
#include "fmt/core.h"
#include "fmt/color.h"

class Programmes
{
public:
    Programmes();

    void createProgramme();

    void displayProgrammes();

private:
    sqlDB database{};

    int sqlQuery{};
    int programmeCredits{};
    int programmeDuration{};

    std::string programmeName{};
    std::string aboutProgramme{};
    std::string eligibility{};
    std::string programmeDegree{};

    std::vector<std::string> degrees{};

    void setProgrammeName();

    void setAboutProgramme();

    void setProgrammeCredits();

    void setProgrammeDuration();

    void setProgrammeEligibility();

    void setDegree();

};

#endif //ICT1009_PART2_PROGRAMMES_H