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
CMAKE_COMMAND = /tmp/cmake-3.23.0/bin/cmake

# The command to remove a file.
RM = /tmp/cmake-3.23.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/DL/Documents/GitHub/ICT1009-Part2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/users/dl/documents/github/ICT1009-Part2/cmake-build-debug

# Include any dependencies generated for this target.
include dependencies/fmt/CMakeFiles/fmt.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include dependencies/fmt/CMakeFiles/fmt.dir/compiler_depend.make

# Include the progress variables for this target.
include dependencies/fmt/CMakeFiles/fmt.dir/progress.make

# Include the compile flags for this target's objects.
include dependencies/fmt/CMakeFiles/fmt.dir/flags.make

dependencies/fmt/CMakeFiles/fmt.dir/src/format.cc.o: dependencies/fmt/CMakeFiles/fmt.dir/flags.make
dependencies/fmt/CMakeFiles/fmt.dir/src/format.cc.o: /mnt/c/Users/DL/Documents/GitHub/ICT1009-Part2/dependencies/fmt/src/format.cc
dependencies/fmt/CMakeFiles/fmt.dir/src/format.cc.o: dependencies/fmt/CMakeFiles/fmt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/users/dl/documents/github/ICT1009-Part2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object dependencies/fmt/CMakeFiles/fmt.dir/src/format.cc.o"
	cd /mnt/c/users/dl/documents/github/ICT1009-Part2/cmake-build-debug/dependencies/fmt && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT dependencies/fmt/CMakeFiles/fmt.dir/src/format.cc.o -MF CMakeFiles/fmt.dir/src/format.cc.o.d -o CMakeFiles/fmt.dir/src/format.cc.o -c /mnt/c/Users/DL/Documents/GitHub/ICT1009-Part2/dependencies/fmt/src/format.cc

dependencies/fmt/CMakeFiles/fmt.dir/src/format.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fmt.dir/src/format.cc.i"
	cd /mnt/c/users/dl/documents/github/ICT1009-Part2/cmake-build-debug/dependencies/fmt && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/DL/Documents/GitHub/ICT1009-Part2/dependencies/fmt/src/format.cc > CMakeFiles/fmt.dir/src/format.cc.i

dependencies/fmt/CMakeFiles/fmt.dir/src/format.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fmt.dir/src/format.cc.s"
	cd /mnt/c/users/dl/documents/github/ICT1009-Part2/cmake-build-debug/dependencies/fmt && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/DL/Documents/GitHub/ICT1009-Part2/dependencies/fmt/src/format.cc -o CMakeFiles/fmt.dir/src/format.cc.s

dependencies/fmt/CMakeFiles/fmt.dir/src/os.cc.o: dependencies/fmt/CMakeFiles/fmt.dir/flags.make
dependencies/fmt/CMakeFiles/fmt.dir/src/os.cc.o: /mnt/c/Users/DL/Documents/GitHub/ICT1009-Part2/dependencies/fmt/src/os.cc
dependencies/fmt/CMakeFiles/fmt.dir/src/os.cc.o: dependencies/fmt/CMakeFiles/fmt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/users/dl/documents/github/ICT1009-Part2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object dependencies/fmt/CMakeFiles/fmt.dir/src/os.cc.o"
	cd /mnt/c/users/dl/documents/github/ICT1009-Part2/cmake-build-debug/dependencies/fmt && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT dependencies/fmt/CMakeFiles/fmt.dir/src/os.cc.o -MF CMakeFiles/fmt.dir/src/os.cc.o.d -o CMakeFiles/fmt.dir/src/os.cc.o -c /mnt/c/Users/DL/Documents/GitHub/ICT1009-Part2/dependencies/fmt/src/os.cc

dependencies/fmt/CMakeFiles/fmt.dir/src/os.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fmt.dir/src/os.cc.i"
	cd /mnt/c/users/dl/documents/github/ICT1009-Part2/cmake-build-debug/dependencies/fmt && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/DL/Documents/GitHub/ICT1009-Part2/dependencies/fmt/src/os.cc > CMakeFiles/fmt.dir/src/os.cc.i

dependencies/fmt/CMakeFiles/fmt.dir/src/os.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fmt.dir/src/os.cc.s"
	cd /mnt/c/users/dl/documents/github/ICT1009-Part2/cmake-build-debug/dependencies/fmt && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/DL/Documents/GitHub/ICT1009-Part2/dependencies/fmt/src/os.cc -o CMakeFiles/fmt.dir/src/os.cc.s

# Object files for target fmt
fmt_OBJECTS = \
"CMakeFiles/fmt.dir/src/format.cc.o" \
"CMakeFiles/fmt.dir/src/os.cc.o"

# External object files for target fmt
fmt_EXTERNAL_OBJECTS =

dependencies/fmt/libfmtd.a: dependencies/fmt/CMakeFiles/fmt.dir/src/format.cc.o
dependencies/fmt/libfmtd.a: dependencies/fmt/CMakeFiles/fmt.dir/src/os.cc.o
dependencies/fmt/libfmtd.a: dependencies/fmt/CMakeFiles/fmt.dir/build.make
dependencies/fmt/libfmtd.a: dependencies/fmt/CMakeFiles/fmt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/users/dl/documents/github/ICT1009-Part2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libfmtd.a"
	cd /mnt/c/users/dl/documents/github/ICT1009-Part2/cmake-build-debug/dependencies/fmt && $(CMAKE_COMMAND) -P CMakeFiles/fmt.dir/cmake_clean_target.cmake
	cd /mnt/c/users/dl/documents/github/ICT1009-Part2/cmake-build-debug/dependencies/fmt && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fmt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
dependencies/fmt/CMakeFiles/fmt.dir/build: dependencies/fmt/libfmtd.a
.PHONY : dependencies/fmt/CMakeFiles/fmt.dir/build

dependencies/fmt/CMakeFiles/fmt.dir/clean:
	cd /mnt/c/users/dl/documents/github/ICT1009-Part2/cmake-build-debug/dependencies/fmt && $(CMAKE_COMMAND) -P CMakeFiles/fmt.dir/cmake_clean.cmake
.PHONY : dependencies/fmt/CMakeFiles/fmt.dir/clean

dependencies/fmt/CMakeFiles/fmt.dir/depend:
	cd /mnt/c/users/dl/documents/github/ICT1009-Part2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/DL/Documents/GitHub/ICT1009-Part2 /mnt/c/Users/DL/Documents/GitHub/ICT1009-Part2/dependencies/fmt /mnt/c/users/dl/documents/github/ICT1009-Part2/cmake-build-debug /mnt/c/users/dl/documents/github/ICT1009-Part2/cmake-build-debug/dependencies/fmt /mnt/c/users/dl/documents/github/ICT1009-Part2/cmake-build-debug/dependencies/fmt/CMakeFiles/fmt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : dependencies/fmt/CMakeFiles/fmt.dir/depend

