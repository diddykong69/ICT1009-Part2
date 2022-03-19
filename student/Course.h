#ifndef COURSE_MANAGEMENT_COURSE_H
#define COURSE_MANAGEMENT_COURSE_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include "Module.h"

class Course
{
public:
    Course(std::string courseName, std::string courseAbbreviation,
           std::string courseType, std::string courseDescription,
           std::string degreeTitle,
           std::string degreeAbbreviation, int totalCredits,
           int courseDuration);

    void createCourse();

    void showCourses();

    void showCourseDetail();

private:
    std::string courseName{};
    std::string courseAbbreviation{};
    std::string courseType{};
    std::string courseDescription{};
    int totalCredits{};
    int courseDuration{};
    std::vector<Module> modules{};
    std::unordered_map<std::string, std::string> degrees = {
            {
                "BAcc (Hons)",
                "Bachelor of Accountancy with Honours"
            },
            {
                "BEng (Hons)",
                "Bachelor of Engineering with Honours"
            },
            {
                "BSc (Hons)",
                "Bachelor of Science with Honours"
            },
            {
                "BFA",
                "Bachelor of Fine Arts"
            },
            {
                "BBA",
                "Bachelor of Business Administration"
            },
            {
                "BFT (Hons)",
                "Bachelor of Food Technology with Honours"
            },
            {
                "BHB (Hons)",
                "Bachelor of Hospitality Business with Honours"
            },
            {
                "BA",
                "Bachelor of Arts"
            },
            {
              "MEng",
              "Master of Engineering"
            },
            {
                "MEngTech",
                "Master of Engineering Technology"
            },
            {
                "MSc",
                "Master of Science"
            },
            {
                "MClinRes",
                "Master of Clinical Research"
            },
            {
                "DClinRes",
                "Doctor of Clinical Research"
            },
            {
                "DEng",
                "Doctor of Engineering",
            }

    };
};

#endif //COURSE_MANAGEMENT_COURSE_H