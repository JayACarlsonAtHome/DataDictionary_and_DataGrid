# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/jay/setup/clion-2016.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/jay/setup/clion-2016.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jay/ClionProjects/DataDictionary_and_DataGrid

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jay/ClionProjects/DataDictionary_and_DataGrid/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DataDictionary_and_DataGrid.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DataDictionary_and_DataGrid.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DataDictionary_and_DataGrid.dir/flags.make

CMakeFiles/DataDictionary_and_DataGrid.dir/main.cpp.o: CMakeFiles/DataDictionary_and_DataGrid.dir/flags.make
CMakeFiles/DataDictionary_and_DataGrid.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jay/ClionProjects/DataDictionary_and_DataGrid/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DataDictionary_and_DataGrid.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DataDictionary_and_DataGrid.dir/main.cpp.o -c /home/jay/ClionProjects/DataDictionary_and_DataGrid/main.cpp

CMakeFiles/DataDictionary_and_DataGrid.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataDictionary_and_DataGrid.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jay/ClionProjects/DataDictionary_and_DataGrid/main.cpp > CMakeFiles/DataDictionary_and_DataGrid.dir/main.cpp.i

CMakeFiles/DataDictionary_and_DataGrid.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataDictionary_and_DataGrid.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jay/ClionProjects/DataDictionary_and_DataGrid/main.cpp -o CMakeFiles/DataDictionary_and_DataGrid.dir/main.cpp.s

CMakeFiles/DataDictionary_and_DataGrid.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/DataDictionary_and_DataGrid.dir/main.cpp.o.requires

CMakeFiles/DataDictionary_and_DataGrid.dir/main.cpp.o.provides: CMakeFiles/DataDictionary_and_DataGrid.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/DataDictionary_and_DataGrid.dir/build.make CMakeFiles/DataDictionary_and_DataGrid.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/DataDictionary_and_DataGrid.dir/main.cpp.o.provides

CMakeFiles/DataDictionary_and_DataGrid.dir/main.cpp.o.provides.build: CMakeFiles/DataDictionary_and_DataGrid.dir/main.cpp.o


CMakeFiles/DataDictionary_and_DataGrid.dir/DataDictionary.cpp.o: CMakeFiles/DataDictionary_and_DataGrid.dir/flags.make
CMakeFiles/DataDictionary_and_DataGrid.dir/DataDictionary.cpp.o: ../DataDictionary.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jay/ClionProjects/DataDictionary_and_DataGrid/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DataDictionary_and_DataGrid.dir/DataDictionary.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DataDictionary_and_DataGrid.dir/DataDictionary.cpp.o -c /home/jay/ClionProjects/DataDictionary_and_DataGrid/DataDictionary.cpp

CMakeFiles/DataDictionary_and_DataGrid.dir/DataDictionary.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataDictionary_and_DataGrid.dir/DataDictionary.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jay/ClionProjects/DataDictionary_and_DataGrid/DataDictionary.cpp > CMakeFiles/DataDictionary_and_DataGrid.dir/DataDictionary.cpp.i

CMakeFiles/DataDictionary_and_DataGrid.dir/DataDictionary.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataDictionary_and_DataGrid.dir/DataDictionary.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jay/ClionProjects/DataDictionary_and_DataGrid/DataDictionary.cpp -o CMakeFiles/DataDictionary_and_DataGrid.dir/DataDictionary.cpp.s

CMakeFiles/DataDictionary_and_DataGrid.dir/DataDictionary.cpp.o.requires:

.PHONY : CMakeFiles/DataDictionary_and_DataGrid.dir/DataDictionary.cpp.o.requires

CMakeFiles/DataDictionary_and_DataGrid.dir/DataDictionary.cpp.o.provides: CMakeFiles/DataDictionary_and_DataGrid.dir/DataDictionary.cpp.o.requires
	$(MAKE) -f CMakeFiles/DataDictionary_and_DataGrid.dir/build.make CMakeFiles/DataDictionary_and_DataGrid.dir/DataDictionary.cpp.o.provides.build
.PHONY : CMakeFiles/DataDictionary_and_DataGrid.dir/DataDictionary.cpp.o.provides

CMakeFiles/DataDictionary_and_DataGrid.dir/DataDictionary.cpp.o.provides.build: CMakeFiles/DataDictionary_and_DataGrid.dir/DataDictionary.cpp.o


CMakeFiles/DataDictionary_and_DataGrid.dir/DataColumnHeader.cpp.o: CMakeFiles/DataDictionary_and_DataGrid.dir/flags.make
CMakeFiles/DataDictionary_and_DataGrid.dir/DataColumnHeader.cpp.o: ../DataColumnHeader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jay/ClionProjects/DataDictionary_and_DataGrid/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DataDictionary_and_DataGrid.dir/DataColumnHeader.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DataDictionary_and_DataGrid.dir/DataColumnHeader.cpp.o -c /home/jay/ClionProjects/DataDictionary_and_DataGrid/DataColumnHeader.cpp

CMakeFiles/DataDictionary_and_DataGrid.dir/DataColumnHeader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataDictionary_and_DataGrid.dir/DataColumnHeader.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jay/ClionProjects/DataDictionary_and_DataGrid/DataColumnHeader.cpp > CMakeFiles/DataDictionary_and_DataGrid.dir/DataColumnHeader.cpp.i

CMakeFiles/DataDictionary_and_DataGrid.dir/DataColumnHeader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataDictionary_and_DataGrid.dir/DataColumnHeader.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jay/ClionProjects/DataDictionary_and_DataGrid/DataColumnHeader.cpp -o CMakeFiles/DataDictionary_and_DataGrid.dir/DataColumnHeader.cpp.s

CMakeFiles/DataDictionary_and_DataGrid.dir/DataColumnHeader.cpp.o.requires:

.PHONY : CMakeFiles/DataDictionary_and_DataGrid.dir/DataColumnHeader.cpp.o.requires

CMakeFiles/DataDictionary_and_DataGrid.dir/DataColumnHeader.cpp.o.provides: CMakeFiles/DataDictionary_and_DataGrid.dir/DataColumnHeader.cpp.o.requires
	$(MAKE) -f CMakeFiles/DataDictionary_and_DataGrid.dir/build.make CMakeFiles/DataDictionary_and_DataGrid.dir/DataColumnHeader.cpp.o.provides.build
.PHONY : CMakeFiles/DataDictionary_and_DataGrid.dir/DataColumnHeader.cpp.o.provides

CMakeFiles/DataDictionary_and_DataGrid.dir/DataColumnHeader.cpp.o.provides.build: CMakeFiles/DataDictionary_and_DataGrid.dir/DataColumnHeader.cpp.o


# Object files for target DataDictionary_and_DataGrid
DataDictionary_and_DataGrid_OBJECTS = \
"CMakeFiles/DataDictionary_and_DataGrid.dir/main.cpp.o" \
"CMakeFiles/DataDictionary_and_DataGrid.dir/DataDictionary.cpp.o" \
"CMakeFiles/DataDictionary_and_DataGrid.dir/DataColumnHeader.cpp.o"

# External object files for target DataDictionary_and_DataGrid
DataDictionary_and_DataGrid_EXTERNAL_OBJECTS =

DataDictionary_and_DataGrid: CMakeFiles/DataDictionary_and_DataGrid.dir/main.cpp.o
DataDictionary_and_DataGrid: CMakeFiles/DataDictionary_and_DataGrid.dir/DataDictionary.cpp.o
DataDictionary_and_DataGrid: CMakeFiles/DataDictionary_and_DataGrid.dir/DataColumnHeader.cpp.o
DataDictionary_and_DataGrid: CMakeFiles/DataDictionary_and_DataGrid.dir/build.make
DataDictionary_and_DataGrid: CMakeFiles/DataDictionary_and_DataGrid.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jay/ClionProjects/DataDictionary_and_DataGrid/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable DataDictionary_and_DataGrid"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DataDictionary_and_DataGrid.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DataDictionary_and_DataGrid.dir/build: DataDictionary_and_DataGrid

.PHONY : CMakeFiles/DataDictionary_and_DataGrid.dir/build

CMakeFiles/DataDictionary_and_DataGrid.dir/requires: CMakeFiles/DataDictionary_and_DataGrid.dir/main.cpp.o.requires
CMakeFiles/DataDictionary_and_DataGrid.dir/requires: CMakeFiles/DataDictionary_and_DataGrid.dir/DataDictionary.cpp.o.requires
CMakeFiles/DataDictionary_and_DataGrid.dir/requires: CMakeFiles/DataDictionary_and_DataGrid.dir/DataColumnHeader.cpp.o.requires

.PHONY : CMakeFiles/DataDictionary_and_DataGrid.dir/requires

CMakeFiles/DataDictionary_and_DataGrid.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DataDictionary_and_DataGrid.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DataDictionary_and_DataGrid.dir/clean

CMakeFiles/DataDictionary_and_DataGrid.dir/depend:
	cd /home/jay/ClionProjects/DataDictionary_and_DataGrid/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jay/ClionProjects/DataDictionary_and_DataGrid /home/jay/ClionProjects/DataDictionary_and_DataGrid /home/jay/ClionProjects/DataDictionary_and_DataGrid/cmake-build-debug /home/jay/ClionProjects/DataDictionary_and_DataGrid/cmake-build-debug /home/jay/ClionProjects/DataDictionary_and_DataGrid/cmake-build-debug/CMakeFiles/DataDictionary_and_DataGrid.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DataDictionary_and_DataGrid.dir/depend

