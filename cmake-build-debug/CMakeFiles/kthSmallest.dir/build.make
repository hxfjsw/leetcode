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
include CMakeFiles/kthSmallest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/kthSmallest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kthSmallest.dir/flags.make

CMakeFiles/kthSmallest.dir/kthSmallest.cpp.o: CMakeFiles/kthSmallest.dir/flags.make
CMakeFiles/kthSmallest.dir/kthSmallest.cpp.o: ../kthSmallest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lion/CLionProjects/untitled14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/kthSmallest.dir/kthSmallest.cpp.o"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/kthSmallest.dir/kthSmallest.cpp.o -c /Users/lion/CLionProjects/untitled14/kthSmallest.cpp

CMakeFiles/kthSmallest.dir/kthSmallest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kthSmallest.dir/kthSmallest.cpp.i"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lion/CLionProjects/untitled14/kthSmallest.cpp > CMakeFiles/kthSmallest.dir/kthSmallest.cpp.i

CMakeFiles/kthSmallest.dir/kthSmallest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kthSmallest.dir/kthSmallest.cpp.s"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lion/CLionProjects/untitled14/kthSmallest.cpp -o CMakeFiles/kthSmallest.dir/kthSmallest.cpp.s

# Object files for target kthSmallest
kthSmallest_OBJECTS = \
"CMakeFiles/kthSmallest.dir/kthSmallest.cpp.o"

# External object files for target kthSmallest
kthSmallest_EXTERNAL_OBJECTS =

kthSmallest: CMakeFiles/kthSmallest.dir/kthSmallest.cpp.o
kthSmallest: CMakeFiles/kthSmallest.dir/build.make
kthSmallest: CMakeFiles/kthSmallest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lion/CLionProjects/untitled14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable kthSmallest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kthSmallest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kthSmallest.dir/build: kthSmallest

.PHONY : CMakeFiles/kthSmallest.dir/build

CMakeFiles/kthSmallest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/kthSmallest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/kthSmallest.dir/clean

CMakeFiles/kthSmallest.dir/depend:
	cd /Users/lion/CLionProjects/untitled14/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lion/CLionProjects/untitled14 /Users/lion/CLionProjects/untitled14 /Users/lion/CLionProjects/untitled14/cmake-build-debug /Users/lion/CLionProjects/untitled14/cmake-build-debug /Users/lion/CLionProjects/untitled14/cmake-build-debug/CMakeFiles/kthSmallest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kthSmallest.dir/depend

