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
include CMakeFiles/subarraySum.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/subarraySum.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/subarraySum.dir/flags.make

CMakeFiles/subarraySum.dir/subarraySum.cpp.o: CMakeFiles/subarraySum.dir/flags.make
CMakeFiles/subarraySum.dir/subarraySum.cpp.o: ../subarraySum.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lion/CLionProjects/untitled14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/subarraySum.dir/subarraySum.cpp.o"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/subarraySum.dir/subarraySum.cpp.o -c /Users/lion/CLionProjects/untitled14/subarraySum.cpp

CMakeFiles/subarraySum.dir/subarraySum.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/subarraySum.dir/subarraySum.cpp.i"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lion/CLionProjects/untitled14/subarraySum.cpp > CMakeFiles/subarraySum.dir/subarraySum.cpp.i

CMakeFiles/subarraySum.dir/subarraySum.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/subarraySum.dir/subarraySum.cpp.s"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lion/CLionProjects/untitled14/subarraySum.cpp -o CMakeFiles/subarraySum.dir/subarraySum.cpp.s

# Object files for target subarraySum
subarraySum_OBJECTS = \
"CMakeFiles/subarraySum.dir/subarraySum.cpp.o"

# External object files for target subarraySum
subarraySum_EXTERNAL_OBJECTS =

subarraySum: CMakeFiles/subarraySum.dir/subarraySum.cpp.o
subarraySum: CMakeFiles/subarraySum.dir/build.make
subarraySum: CMakeFiles/subarraySum.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lion/CLionProjects/untitled14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable subarraySum"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/subarraySum.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/subarraySum.dir/build: subarraySum

.PHONY : CMakeFiles/subarraySum.dir/build

CMakeFiles/subarraySum.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/subarraySum.dir/cmake_clean.cmake
.PHONY : CMakeFiles/subarraySum.dir/clean

CMakeFiles/subarraySum.dir/depend:
	cd /Users/lion/CLionProjects/untitled14/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lion/CLionProjects/untitled14 /Users/lion/CLionProjects/untitled14 /Users/lion/CLionProjects/untitled14/cmake-build-debug /Users/lion/CLionProjects/untitled14/cmake-build-debug /Users/lion/CLionProjects/untitled14/cmake-build-debug/CMakeFiles/subarraySum.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/subarraySum.dir/depend
