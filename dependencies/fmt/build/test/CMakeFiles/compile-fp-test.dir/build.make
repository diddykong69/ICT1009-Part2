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
include test/CMakeFiles/compile-fp-test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/compile-fp-test.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/compile-fp-test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/compile-fp-test.dir/flags.make

test/CMakeFiles/compile-fp-test.dir/compile-fp-test.cc.o: test/CMakeFiles/compile-fp-test.dir/flags.make
test/CMakeFiles/compile-fp-test.dir/compile-fp-test.cc.o: ../test/compile-fp-test.cc
test/CMakeFiles/compile-fp-test.dir/compile-fp-test.cc.o: test/CMakeFiles/compile-fp-test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/compile-fp-test.dir/compile-fp-test.cc.o"
	cd "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/test" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/compile-fp-test.dir/compile-fp-test.cc.o -MF CMakeFiles/compile-fp-test.dir/compile-fp-test.cc.o.d -o CMakeFiles/compile-fp-test.dir/compile-fp-test.cc.o -c "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/test/compile-fp-test.cc"

test/CMakeFiles/compile-fp-test.dir/compile-fp-test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compile-fp-test.dir/compile-fp-test.cc.i"
	cd "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/test" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/test/compile-fp-test.cc" > CMakeFiles/compile-fp-test.dir/compile-fp-test.cc.i

test/CMakeFiles/compile-fp-test.dir/compile-fp-test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compile-fp-test.dir/compile-fp-test.cc.s"
	cd "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/test" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/test/compile-fp-test.cc" -o CMakeFiles/compile-fp-test.dir/compile-fp-test.cc.s

test/CMakeFiles/compile-fp-test.dir/test-main.cc.o: test/CMakeFiles/compile-fp-test.dir/flags.make
test/CMakeFiles/compile-fp-test.dir/test-main.cc.o: ../test/test-main.cc
test/CMakeFiles/compile-fp-test.dir/test-main.cc.o: test/CMakeFiles/compile-fp-test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/compile-fp-test.dir/test-main.cc.o"
	cd "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/test" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/compile-fp-test.dir/test-main.cc.o -MF CMakeFiles/compile-fp-test.dir/test-main.cc.o.d -o CMakeFiles/compile-fp-test.dir/test-main.cc.o -c "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/test/test-main.cc"

test/CMakeFiles/compile-fp-test.dir/test-main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compile-fp-test.dir/test-main.cc.i"
	cd "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/test" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/test/test-main.cc" > CMakeFiles/compile-fp-test.dir/test-main.cc.i

test/CMakeFiles/compile-fp-test.dir/test-main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compile-fp-test.dir/test-main.cc.s"
	cd "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/test" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/test/test-main.cc" -o CMakeFiles/compile-fp-test.dir/test-main.cc.s

test/CMakeFiles/compile-fp-test.dir/gtest-extra.cc.o: test/CMakeFiles/compile-fp-test.dir/flags.make
test/CMakeFiles/compile-fp-test.dir/gtest-extra.cc.o: ../test/gtest-extra.cc
test/CMakeFiles/compile-fp-test.dir/gtest-extra.cc.o: test/CMakeFiles/compile-fp-test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/CMakeFiles/compile-fp-test.dir/gtest-extra.cc.o"
	cd "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/test" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/compile-fp-test.dir/gtest-extra.cc.o -MF CMakeFiles/compile-fp-test.dir/gtest-extra.cc.o.d -o CMakeFiles/compile-fp-test.dir/gtest-extra.cc.o -c "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/test/gtest-extra.cc"

test/CMakeFiles/compile-fp-test.dir/gtest-extra.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compile-fp-test.dir/gtest-extra.cc.i"
	cd "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/test" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/test/gtest-extra.cc" > CMakeFiles/compile-fp-test.dir/gtest-extra.cc.i

test/CMakeFiles/compile-fp-test.dir/gtest-extra.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compile-fp-test.dir/gtest-extra.cc.s"
	cd "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/test" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/test/gtest-extra.cc" -o CMakeFiles/compile-fp-test.dir/gtest-extra.cc.s

test/CMakeFiles/compile-fp-test.dir/util.cc.o: test/CMakeFiles/compile-fp-test.dir/flags.make
test/CMakeFiles/compile-fp-test.dir/util.cc.o: ../test/util.cc
test/CMakeFiles/compile-fp-test.dir/util.cc.o: test/CMakeFiles/compile-fp-test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object test/CMakeFiles/compile-fp-test.dir/util.cc.o"
	cd "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/test" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/compile-fp-test.dir/util.cc.o -MF CMakeFiles/compile-fp-test.dir/util.cc.o.d -o CMakeFiles/compile-fp-test.dir/util.cc.o -c "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/test/util.cc"

test/CMakeFiles/compile-fp-test.dir/util.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compile-fp-test.dir/util.cc.i"
	cd "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/test" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/test/util.cc" > CMakeFiles/compile-fp-test.dir/util.cc.i

test/CMakeFiles/compile-fp-test.dir/util.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compile-fp-test.dir/util.cc.s"
	cd "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/test" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/test/util.cc" -o CMakeFiles/compile-fp-test.dir/util.cc.s

test/CMakeFiles/compile-fp-test.dir/__/src/os.cc.o: test/CMakeFiles/compile-fp-test.dir/flags.make
test/CMakeFiles/compile-fp-test.dir/__/src/os.cc.o: ../src/os.cc
test/CMakeFiles/compile-fp-test.dir/__/src/os.cc.o: test/CMakeFiles/compile-fp-test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object test/CMakeFiles/compile-fp-test.dir/__/src/os.cc.o"
	cd "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/test" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/compile-fp-test.dir/__/src/os.cc.o -MF CMakeFiles/compile-fp-test.dir/__/src/os.cc.o.d -o CMakeFiles/compile-fp-test.dir/__/src/os.cc.o -c "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/src/os.cc"

test/CMakeFiles/compile-fp-test.dir/__/src/os.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compile-fp-test.dir/__/src/os.cc.i"
	cd "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/test" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/src/os.cc" > CMakeFiles/compile-fp-test.dir/__/src/os.cc.i

test/CMakeFiles/compile-fp-test.dir/__/src/os.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compile-fp-test.dir/__/src/os.cc.s"
	cd "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/test" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/src/os.cc" -o CMakeFiles/compile-fp-test.dir/__/src/os.cc.s

# Object files for target compile-fp-test
compile__fp__test_OBJECTS = \
"CMakeFiles/compile-fp-test.dir/compile-fp-test.cc.o" \
"CMakeFiles/compile-fp-test.dir/test-main.cc.o" \
"CMakeFiles/compile-fp-test.dir/gtest-extra.cc.o" \
"CMakeFiles/compile-fp-test.dir/util.cc.o" \
"CMakeFiles/compile-fp-test.dir/__/src/os.cc.o"

# External object files for target compile-fp-test
compile__fp__test_EXTERNAL_OBJECTS =

bin/compile-fp-test: test/CMakeFiles/compile-fp-test.dir/compile-fp-test.cc.o
bin/compile-fp-test: test/CMakeFiles/compile-fp-test.dir/test-main.cc.o
bin/compile-fp-test: test/CMakeFiles/compile-fp-test.dir/gtest-extra.cc.o
bin/compile-fp-test: test/CMakeFiles/compile-fp-test.dir/util.cc.o
bin/compile-fp-test: test/CMakeFiles/compile-fp-test.dir/__/src/os.cc.o
bin/compile-fp-test: test/CMakeFiles/compile-fp-test.dir/build.make
bin/compile-fp-test: test/gtest/libgtest.a
bin/compile-fp-test: test/CMakeFiles/compile-fp-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ../bin/compile-fp-test"
	cd "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/test" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/compile-fp-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/compile-fp-test.dir/build: bin/compile-fp-test
.PHONY : test/CMakeFiles/compile-fp-test.dir/build

test/CMakeFiles/compile-fp-test.dir/clean:
	cd "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/test" && $(CMAKE_COMMAND) -P CMakeFiles/compile-fp-test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/compile-fp-test.dir/clean

test/CMakeFiles/compile-fp-test.dir/depend:
	cd "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt" "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/test" "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build" "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/test" "/mnt/c/users/b2/downloads/ICT1009-Part2 (1)/ICT1009-Part2/dependencies/fmt/build/test/CMakeFiles/compile-fp-test.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : test/CMakeFiles/compile-fp-test.dir/depend

