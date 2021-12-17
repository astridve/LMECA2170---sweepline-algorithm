# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/avekemans/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5284.51/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/avekemans/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5284.51/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/avekemans/Documents/Numerical Geometry/NGP-master"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/avekemans/Documents/Numerical Geometry/NGP-master"

# Include any dependencies generated for this target.
include deps/BOV/deps/glad/CMakeFiles/glad.dir/depend.make
# Include the progress variables for this target.
include deps/BOV/deps/glad/CMakeFiles/glad.dir/progress.make

# Include the compile flags for this target's objects.
include deps/BOV/deps/glad/CMakeFiles/glad.dir/flags.make

deps/BOV/deps/glad/CMakeFiles/glad.dir/src/glad.c.o: deps/BOV/deps/glad/CMakeFiles/glad.dir/flags.make
deps/BOV/deps/glad/CMakeFiles/glad.dir/src/glad.c.o: deps/BOV/deps/glad/src/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/avekemans/Documents/Numerical Geometry/NGP-master/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object deps/BOV/deps/glad/CMakeFiles/glad.dir/src/glad.c.o"
	cd "/home/avekemans/Documents/Numerical Geometry/NGP-master/deps/BOV/deps/glad" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glad.dir/src/glad.c.o -c "/home/avekemans/Documents/Numerical Geometry/NGP-master/deps/BOV/deps/glad/src/glad.c"

deps/BOV/deps/glad/CMakeFiles/glad.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glad.dir/src/glad.c.i"
	cd "/home/avekemans/Documents/Numerical Geometry/NGP-master/deps/BOV/deps/glad" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/avekemans/Documents/Numerical Geometry/NGP-master/deps/BOV/deps/glad/src/glad.c" > CMakeFiles/glad.dir/src/glad.c.i

deps/BOV/deps/glad/CMakeFiles/glad.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glad.dir/src/glad.c.s"
	cd "/home/avekemans/Documents/Numerical Geometry/NGP-master/deps/BOV/deps/glad" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/avekemans/Documents/Numerical Geometry/NGP-master/deps/BOV/deps/glad/src/glad.c" -o CMakeFiles/glad.dir/src/glad.c.s

# Object files for target glad
glad_OBJECTS = \
"CMakeFiles/glad.dir/src/glad.c.o"

# External object files for target glad
glad_EXTERNAL_OBJECTS =

deps/BOV/deps/glad/libglad.a: deps/BOV/deps/glad/CMakeFiles/glad.dir/src/glad.c.o
deps/BOV/deps/glad/libglad.a: deps/BOV/deps/glad/CMakeFiles/glad.dir/build.make
deps/BOV/deps/glad/libglad.a: deps/BOV/deps/glad/CMakeFiles/glad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/avekemans/Documents/Numerical Geometry/NGP-master/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libglad.a"
	cd "/home/avekemans/Documents/Numerical Geometry/NGP-master/deps/BOV/deps/glad" && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean_target.cmake
	cd "/home/avekemans/Documents/Numerical Geometry/NGP-master/deps/BOV/deps/glad" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glad.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
deps/BOV/deps/glad/CMakeFiles/glad.dir/build: deps/BOV/deps/glad/libglad.a
.PHONY : deps/BOV/deps/glad/CMakeFiles/glad.dir/build

deps/BOV/deps/glad/CMakeFiles/glad.dir/clean:
	cd "/home/avekemans/Documents/Numerical Geometry/NGP-master/deps/BOV/deps/glad" && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean.cmake
.PHONY : deps/BOV/deps/glad/CMakeFiles/glad.dir/clean

deps/BOV/deps/glad/CMakeFiles/glad.dir/depend:
	cd "/home/avekemans/Documents/Numerical Geometry/NGP-master" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/avekemans/Documents/Numerical Geometry/NGP-master" "/home/avekemans/Documents/Numerical Geometry/NGP-master/deps/BOV/deps/glad" "/home/avekemans/Documents/Numerical Geometry/NGP-master" "/home/avekemans/Documents/Numerical Geometry/NGP-master/deps/BOV/deps/glad" "/home/avekemans/Documents/Numerical Geometry/NGP-master/deps/BOV/deps/glad/CMakeFiles/glad.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : deps/BOV/deps/glad/CMakeFiles/glad.dir/depend

