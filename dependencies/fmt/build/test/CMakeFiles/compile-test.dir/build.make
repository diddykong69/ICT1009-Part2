# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build"

# Include any dependencies generated for this target.
include test/CMakeFiles/compile-test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/compile-test.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/compile-test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/compile-test.dir/flags.make

test/CMakeFiles/compile-test.dir/compile-test.cc.o: test/CMakeFiles/compile-test.dir/flags.make
test/CMakeFiles/compile-test.dir/compile-test.cc.o: ../test/compile-test.cc
test/CMakeFiles/compile-test.dir/compile-test.cc.o: test/CMakeFiles/compile-test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/compile-test.dir/compile-test.cc.o"
	cd "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/test" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/compile-test.dir/compile-test.cc.o -MF CMakeFiles/compile-test.dir/compile-test.cc.o.d -o CMakeFiles/compile-test.dir/compile-test.cc.o -c "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/test/compile-test.cc"

test/CMakeFiles/compile-test.dir/compile-test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compile-test.dir/compile-test.cc.i"
	cd "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/test" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/test/compile-test.cc" > CMakeFiles/compile-test.dir/compile-test.cc.i

test/CMakeFiles/compile-test.dir/compile-test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compile-test.dir/compile-test.cc.s"
	cd "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/test" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/test/compile-test.cc" -o CMakeFiles/compile-test.dir/compile-test.cc.s

# Object files for target compile-test
compile__test_OBJECTS = \
"CMakeFiles/compile-test.dir/compile-test.cc.o"

# External object files for target compile-test
compile__test_EXTERNAL_OBJECTS =

bin/compile-test: test/CMakeFiles/compile-test.dir/compile-test.cc.o
bin/compile-test: test/CMakeFiles/compile-test.dir/build.make
bin/compile-test: test/libtest-main.a
bin/compile-test: libfmt.a
bin/compile-test: test/gtest/libgtest.a
bin/compile-test: test/CMakeFiles/compile-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/compile-test"
	cd "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/test" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/compile-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/compile-test.dir/build: bin/compile-test
.PHONY : test/CMakeFiles/compile-test.dir/build

test/CMakeFiles/compile-test.dir/clean:
	cd "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/test" && $(CMAKE_COMMAND) -P CMakeFiles/compile-test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/compile-test.dir/clean

test/CMakeFiles/compile-test.dir/depend:
	cd "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt" "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/test" "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build" "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/test" "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/test/CMakeFiles/compile-test.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : test/CMakeFiles/compile-test.dir/depend

