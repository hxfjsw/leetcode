# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lion/CLionProjects/untitled14

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lion/CLionProjects/untitled14/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AccountsMerge.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AccountsMerge.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AccountsMerge.dir/flags.make

CMakeFiles/AccountsMerge.dir/AccountsMerge.cpp.o: CMakeFiles/AccountsMerge.dir/flags.make
CMakeFiles/AccountsMerge.dir/AccountsMerge.cpp.o: ../AccountsMerge.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lion/CLionProjects/untitled14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AccountsMerge.dir/AccountsMerge.cpp.o"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AccountsMerge.dir/AccountsMerge.cpp.o -c /Users/lion/CLionProjects/untitled14/AccountsMerge.cpp

CMakeFiles/AccountsMerge.dir/AccountsMerge.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AccountsMerge.dir/AccountsMerge.cpp.i"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lion/CLionProjects/untitled14/AccountsMerge.cpp > CMakeFiles/AccountsMerge.dir/AccountsMerge.cpp.i

CMakeFiles/AccountsMerge.dir/AccountsMerge.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AccountsMerge.dir/AccountsMerge.cpp.s"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lion/CLionProjects/untitled14/AccountsMerge.cpp -o CMakeFiles/AccountsMerge.dir/AccountsMerge.cpp.s

# Object files for target AccountsMerge
AccountsMerge_OBJECTS = \
"CMakeFiles/AccountsMerge.dir/AccountsMerge.cpp.o"

# External object files for target AccountsMerge
AccountsMerge_EXTERNAL_OBJECTS =

AccountsMerge: CMakeFiles/AccountsMerge.dir/AccountsMerge.cpp.o
AccountsMerge: CMakeFiles/AccountsMerge.dir/build.make
AccountsMerge: CMakeFiles/AccountsMerge.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lion/CLionProjects/untitled14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AccountsMerge"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AccountsMerge.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AccountsMerge.dir/build: AccountsMerge

.PHONY : CMakeFiles/AccountsMerge.dir/build

CMakeFiles/AccountsMerge.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AccountsMerge.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AccountsMerge.dir/clean

CMakeFiles/AccountsMerge.dir/depend:
	cd /Users/lion/CLionProjects/untitled14/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lion/CLionProjects/untitled14 /Users/lion/CLionProjects/untitled14 /Users/lion/CLionProjects/untitled14/cmake-build-debug /Users/lion/CLionProjects/untitled14/cmake-build-debug /Users/lion/CLionProjects/untitled14/cmake-build-debug/CMakeFiles/AccountsMerge.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AccountsMerge.dir/depend
