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
include CMakeFiles/checkInclusion.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/checkInclusion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/checkInclusion.dir/flags.make

CMakeFiles/checkInclusion.dir/checkInclusion.cpp.o: CMakeFiles/checkInclusion.dir/flags.make
CMakeFiles/checkInclusion.dir/checkInclusion.cpp.o: ../checkInclusion.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lion/CLionProjects/untitled14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/checkInclusion.dir/checkInclusion.cpp.o"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/checkInclusion.dir/checkInclusion.cpp.o -c /Users/lion/CLionProjects/untitled14/checkInclusion.cpp

CMakeFiles/checkInclusion.dir/checkInclusion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/checkInclusion.dir/checkInclusion.cpp.i"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lion/CLionProjects/untitled14/checkInclusion.cpp > CMakeFiles/checkInclusion.dir/checkInclusion.cpp.i

CMakeFiles/checkInclusion.dir/checkInclusion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/checkInclusion.dir/checkInclusion.cpp.s"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lion/CLionProjects/untitled14/checkInclusion.cpp -o CMakeFiles/checkInclusion.dir/checkInclusion.cpp.s

# Object files for target checkInclusion
checkInclusion_OBJECTS = \
"CMakeFiles/checkInclusion.dir/checkInclusion.cpp.o"

# External object files for target checkInclusion
checkInclusion_EXTERNAL_OBJECTS =

checkInclusion: CMakeFiles/checkInclusion.dir/checkInclusion.cpp.o
checkInclusion: CMakeFiles/checkInclusion.dir/build.make
checkInclusion: CMakeFiles/checkInclusion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lion/CLionProjects/untitled14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable checkInclusion"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/checkInclusion.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/checkInclusion.dir/build: checkInclusion

.PHONY : CMakeFiles/checkInclusion.dir/build

CMakeFiles/checkInclusion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/checkInclusion.dir/cmake_clean.cmake
.PHONY : CMakeFiles/checkInclusion.dir/clean

CMakeFiles/checkInclusion.dir/depend:
	cd /Users/lion/CLionProjects/untitled14/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lion/CLionProjects/untitled14 /Users/lion/CLionProjects/untitled14 /Users/lion/CLionProjects/untitled14/cmake-build-debug /Users/lion/CLionProjects/untitled14/cmake-build-debug /Users/lion/CLionProjects/untitled14/cmake-build-debug/CMakeFiles/checkInclusion.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/checkInclusion.dir/depend

