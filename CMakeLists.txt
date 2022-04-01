cmake_minimum_required(VERSION 3.22)
project(ICT1009-Part2)

set(CMAKE_CXX_STANDARD 20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/fmt/build")

add_library(bcrypt dependencies/Bcrypt/bcrypt.cpp dependencies/Bcrypt/blowfish.cpp)
target_include_directories(bcrypt PRIVATE dependencies/Bcrypt)

add_executable(
        ${CMAKE_PROJECT_NAME}
        sql/sqlDB.cpp
        sql/sqlDB.h
        management/main.cpp
        management/admin.cpp
        management/admin.h
        management/Classroom.cpp
        management/Classroom.h
        management/Lecturer.cpp
        management/Lecturer.h
        management/menu.cpp
        management/menu.h
        management/menu_item.cpp
        management/menu_item.h
        management/Module.cpp
        management/Module.h
        management/Person.cpp
        management/Person.h
        management/Student.cpp
        management/Student.h
        management/Programmes.cpp
        management/Programmes.h
)

add_subdirectory(dependencies/fmt)

find_package(${CMAKE_MODULE_PATH}/fmt)

target_link_libraries(${CMAKE_PROJECT_NAME} LINK_PUBLIC sqlite3)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE bcrypt)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE fmt::fmt)