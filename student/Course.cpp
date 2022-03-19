#include "Course.h"

#include <utility>

Course::Course(
        std::string courseName,
        std::string courseAbbreviation,
        std::string courseType,
        std::string courseDescription,
        std::string degreeTitle,
        std::string degreeAbbreviation,
        int totalCredits,
        int courseDuration
) : courseName(std::move(courseName)),
    courseAbbreviation(std::move(courseAbbreviation)),
    courseType(std::move(courseType)),
    courseDescription(std::move(courseDescription)),
    degreeTitle(std::move(degreeTitle)),
    degreeAbbreviation(std::move(degreeAbbreviation)),
    totalCredits(totalCredits),
    courseDuration(courseDuration)
{}

void Course::createCourse()
{
    std::cout << "What will the name of the course be?" << std::endl;
    getline(std::cin, this->courseName);
    std::cout << "Enter an abbreviation for the course" << std::endl;
    getline(std::cin, this->courseAbbreviation);
}

void Course::showCourses()
{

}

void Course::showCourseDetail()
{

}
