# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_SOURCE_DIR = "/Users/danielbill/Disk Google/School/Master/2 semestr/FIDBS/fidbs1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/danielbill/Disk Google/School/Master/2 semestr/FIDBS/fidbs1/cmake-build-release"

# Include any dependencies generated for this target.
include CMakeFiles/fidbs1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fidbs1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fidbs1.dir/flags.make

CMakeFiles/fidbs1.dir/main.cpp.o: CMakeFiles/fidbs1.dir/flags.make
CMakeFiles/fidbs1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/danielbill/Disk Google/School/Master/2 semestr/FIDBS/fidbs1/cmake-build-release/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fidbs1.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fidbs1.dir/main.cpp.o -c "/Users/danielbill/Disk Google/School/Master/2 semestr/FIDBS/fidbs1/main.cpp"

CMakeFiles/fidbs1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fidbs1.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/danielbill/Disk Google/School/Master/2 semestr/FIDBS/fidbs1/main.cpp" > CMakeFiles/fidbs1.dir/main.cpp.i

CMakeFiles/fidbs1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fidbs1.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/danielbill/Disk Google/School/Master/2 semestr/FIDBS/fidbs1/main.cpp" -o CMakeFiles/fidbs1.dir/main.cpp.s

CMakeFiles/fidbs1.dir/cMemory.cpp.o: CMakeFiles/fidbs1.dir/flags.make
CMakeFiles/fidbs1.dir/cMemory.cpp.o: ../cMemory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/danielbill/Disk Google/School/Master/2 semestr/FIDBS/fidbs1/cmake-build-release/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/fidbs1.dir/cMemory.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fidbs1.dir/cMemory.cpp.o -c "/Users/danielbill/Disk Google/School/Master/2 semestr/FIDBS/fidbs1/cMemory.cpp"

CMakeFiles/fidbs1.dir/cMemory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fidbs1.dir/cMemory.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/danielbill/Disk Google/School/Master/2 semestr/FIDBS/fidbs1/cMemory.cpp" > CMakeFiles/fidbs1.dir/cMemory.cpp.i

CMakeFiles/fidbs1.dir/cMemory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fidbs1.dir/cMemory.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/danielbill/Disk Google/School/Master/2 semestr/FIDBS/fidbs1/cMemory.cpp" -o CMakeFiles/fidbs1.dir/cMemory.cpp.s

# Object files for target fidbs1
fidbs1_OBJECTS = \
"CMakeFiles/fidbs1.dir/main.cpp.o" \
"CMakeFiles/fidbs1.dir/cMemory.cpp.o"

# External object files for target fidbs1
fidbs1_EXTERNAL_OBJECTS =

fidbs1: CMakeFiles/fidbs1.dir/main.cpp.o
fidbs1: CMakeFiles/fidbs1.dir/cMemory.cpp.o
fidbs1: CMakeFiles/fidbs1.dir/build.make
fidbs1: CMakeFiles/fidbs1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/danielbill/Disk Google/School/Master/2 semestr/FIDBS/fidbs1/cmake-build-release/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable fidbs1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fidbs1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fidbs1.dir/build: fidbs1

.PHONY : CMakeFiles/fidbs1.dir/build

CMakeFiles/fidbs1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fidbs1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fidbs1.dir/clean

CMakeFiles/fidbs1.dir/depend:
	cd "/Users/danielbill/Disk Google/School/Master/2 semestr/FIDBS/fidbs1/cmake-build-release" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/danielbill/Disk Google/School/Master/2 semestr/FIDBS/fidbs1" "/Users/danielbill/Disk Google/School/Master/2 semestr/FIDBS/fidbs1" "/Users/danielbill/Disk Google/School/Master/2 semestr/FIDBS/fidbs1/cmake-build-release" "/Users/danielbill/Disk Google/School/Master/2 semestr/FIDBS/fidbs1/cmake-build-release" "/Users/danielbill/Disk Google/School/Master/2 semestr/FIDBS/fidbs1/cmake-build-release/CMakeFiles/fidbs1.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/fidbs1.dir/depend
