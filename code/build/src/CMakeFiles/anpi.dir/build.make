# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pablo/Documents/ANPI/Proyecto2/Proyecto_2/code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pablo/Documents/ANPI/Proyecto2/Proyecto_2/code/build

# Include any dependencies generated for this target.
include src/CMakeFiles/anpi.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/anpi.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/anpi.dir/flags.make

src/CMakeFiles/anpi.dir/paths.cpp.o: src/CMakeFiles/anpi.dir/flags.make
src/CMakeFiles/anpi.dir/paths.cpp.o: ../src/paths.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pablo/Documents/ANPI/Proyecto2/Proyecto_2/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/anpi.dir/paths.cpp.o"
	cd /home/pablo/Documents/ANPI/Proyecto2/Proyecto_2/code/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/anpi.dir/paths.cpp.o -c /home/pablo/Documents/ANPI/Proyecto2/Proyecto_2/code/src/paths.cpp

src/CMakeFiles/anpi.dir/paths.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/anpi.dir/paths.cpp.i"
	cd /home/pablo/Documents/ANPI/Proyecto2/Proyecto_2/code/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pablo/Documents/ANPI/Proyecto2/Proyecto_2/code/src/paths.cpp > CMakeFiles/anpi.dir/paths.cpp.i

src/CMakeFiles/anpi.dir/paths.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/anpi.dir/paths.cpp.s"
	cd /home/pablo/Documents/ANPI/Proyecto2/Proyecto_2/code/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pablo/Documents/ANPI/Proyecto2/Proyecto_2/code/src/paths.cpp -o CMakeFiles/anpi.dir/paths.cpp.s

src/CMakeFiles/anpi.dir/paths.cpp.o.requires:

.PHONY : src/CMakeFiles/anpi.dir/paths.cpp.o.requires

src/CMakeFiles/anpi.dir/paths.cpp.o.provides: src/CMakeFiles/anpi.dir/paths.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/anpi.dir/build.make src/CMakeFiles/anpi.dir/paths.cpp.o.provides.build
.PHONY : src/CMakeFiles/anpi.dir/paths.cpp.o.provides

src/CMakeFiles/anpi.dir/paths.cpp.o.provides.build: src/CMakeFiles/anpi.dir/paths.cpp.o


# Object files for target anpi
anpi_OBJECTS = \
"CMakeFiles/anpi.dir/paths.cpp.o"

# External object files for target anpi
anpi_EXTERNAL_OBJECTS =

src/libanpi.a: src/CMakeFiles/anpi.dir/paths.cpp.o
src/libanpi.a: src/CMakeFiles/anpi.dir/build.make
src/libanpi.a: src/CMakeFiles/anpi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pablo/Documents/ANPI/Proyecto2/Proyecto_2/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libanpi.a"
	cd /home/pablo/Documents/ANPI/Proyecto2/Proyecto_2/code/build/src && $(CMAKE_COMMAND) -P CMakeFiles/anpi.dir/cmake_clean_target.cmake
	cd /home/pablo/Documents/ANPI/Proyecto2/Proyecto_2/code/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/anpi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/anpi.dir/build: src/libanpi.a

.PHONY : src/CMakeFiles/anpi.dir/build

src/CMakeFiles/anpi.dir/requires: src/CMakeFiles/anpi.dir/paths.cpp.o.requires

.PHONY : src/CMakeFiles/anpi.dir/requires

src/CMakeFiles/anpi.dir/clean:
	cd /home/pablo/Documents/ANPI/Proyecto2/Proyecto_2/code/build/src && $(CMAKE_COMMAND) -P CMakeFiles/anpi.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/anpi.dir/clean

src/CMakeFiles/anpi.dir/depend:
	cd /home/pablo/Documents/ANPI/Proyecto2/Proyecto_2/code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pablo/Documents/ANPI/Proyecto2/Proyecto_2/code /home/pablo/Documents/ANPI/Proyecto2/Proyecto_2/code/src /home/pablo/Documents/ANPI/Proyecto2/Proyecto_2/code/build /home/pablo/Documents/ANPI/Proyecto2/Proyecto_2/code/build/src /home/pablo/Documents/ANPI/Proyecto2/Proyecto_2/code/build/src/CMakeFiles/anpi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/anpi.dir/depend

