# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/thawne/CLionProjects/A1034_diagram

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/thawne/CLionProjects/A1034_diagram/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/A1034_diagram.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/A1034_diagram.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/A1034_diagram.dir/flags.make

CMakeFiles/A1034_diagram.dir/main.cpp.o: CMakeFiles/A1034_diagram.dir/flags.make
CMakeFiles/A1034_diagram.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/thawne/CLionProjects/A1034_diagram/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/A1034_diagram.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/A1034_diagram.dir/main.cpp.o -c /Users/thawne/CLionProjects/A1034_diagram/main.cpp

CMakeFiles/A1034_diagram.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/A1034_diagram.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/thawne/CLionProjects/A1034_diagram/main.cpp > CMakeFiles/A1034_diagram.dir/main.cpp.i

CMakeFiles/A1034_diagram.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/A1034_diagram.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/thawne/CLionProjects/A1034_diagram/main.cpp -o CMakeFiles/A1034_diagram.dir/main.cpp.s

CMakeFiles/A1034_diagram.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/A1034_diagram.dir/main.cpp.o.requires

CMakeFiles/A1034_diagram.dir/main.cpp.o.provides: CMakeFiles/A1034_diagram.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/A1034_diagram.dir/build.make CMakeFiles/A1034_diagram.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/A1034_diagram.dir/main.cpp.o.provides

CMakeFiles/A1034_diagram.dir/main.cpp.o.provides.build: CMakeFiles/A1034_diagram.dir/main.cpp.o


# Object files for target A1034_diagram
A1034_diagram_OBJECTS = \
"CMakeFiles/A1034_diagram.dir/main.cpp.o"

# External object files for target A1034_diagram
A1034_diagram_EXTERNAL_OBJECTS =

A1034_diagram: CMakeFiles/A1034_diagram.dir/main.cpp.o
A1034_diagram: CMakeFiles/A1034_diagram.dir/build.make
A1034_diagram: CMakeFiles/A1034_diagram.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/thawne/CLionProjects/A1034_diagram/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable A1034_diagram"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/A1034_diagram.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/A1034_diagram.dir/build: A1034_diagram

.PHONY : CMakeFiles/A1034_diagram.dir/build

CMakeFiles/A1034_diagram.dir/requires: CMakeFiles/A1034_diagram.dir/main.cpp.o.requires

.PHONY : CMakeFiles/A1034_diagram.dir/requires

CMakeFiles/A1034_diagram.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/A1034_diagram.dir/cmake_clean.cmake
.PHONY : CMakeFiles/A1034_diagram.dir/clean

CMakeFiles/A1034_diagram.dir/depend:
	cd /Users/thawne/CLionProjects/A1034_diagram/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/thawne/CLionProjects/A1034_diagram /Users/thawne/CLionProjects/A1034_diagram /Users/thawne/CLionProjects/A1034_diagram/cmake-build-debug /Users/thawne/CLionProjects/A1034_diagram/cmake-build-debug /Users/thawne/CLionProjects/A1034_diagram/cmake-build-debug/CMakeFiles/A1034_diagram.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/A1034_diagram.dir/depend

