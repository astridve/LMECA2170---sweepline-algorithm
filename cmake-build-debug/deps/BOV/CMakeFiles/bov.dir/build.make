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
CMAKE_BINARY_DIR = "/home/avekemans/Documents/Numerical Geometry/NGP-master/cmake-build-debug"

# Include any dependencies generated for this target.
include deps/BOV/CMakeFiles/bov.dir/depend.make
# Include the progress variables for this target.
include deps/BOV/CMakeFiles/bov.dir/progress.make

# Include the compile flags for this target's objects.
include deps/BOV/CMakeFiles/bov.dir/flags.make

deps/BOV/CMakeFiles/bov.dir/src/BOV.c.o: deps/BOV/CMakeFiles/bov.dir/flags.make
deps/BOV/CMakeFiles/bov.dir/src/BOV.c.o: ../deps/BOV/src/BOV.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/avekemans/Documents/Numerical Geometry/NGP-master/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object deps/BOV/CMakeFiles/bov.dir/src/BOV.c.o"
	cd "/home/avekemans/Documents/Numerical Geometry/NGP-master/cmake-build-debug/deps/BOV" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bov.dir/src/BOV.c.o -c "/home/avekemans/Documents/Numerical Geometry/NGP-master/deps/BOV/src/BOV.c"

deps/BOV/CMakeFiles/bov.dir/src/BOV.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bov.dir/src/BOV.c.i"
	cd "/home/avekemans/Documents/Numerical Geometry/NGP-master/cmake-build-debug/deps/BOV" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/avekemans/Documents/Numerical Geometry/NGP-master/deps/BOV/src/BOV.c" > CMakeFiles/bov.dir/src/BOV.c.i

deps/BOV/CMakeFiles/bov.dir/src/BOV.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bov.dir/src/BOV.c.s"
	cd "/home/avekemans/Documents/Numerical Geometry/NGP-master/cmake-build-debug/deps/BOV" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/avekemans/Documents/Numerical Geometry/NGP-master/deps/BOV/src/BOV.c" -o CMakeFiles/bov.dir/src/BOV.c.s

# Object files for target bov
bov_OBJECTS = \
"CMakeFiles/bov.dir/src/BOV.c.o"

# External object files for target bov
bov_EXTERNAL_OBJECTS =

deps/BOV/lib/libbov.a: deps/BOV/CMakeFiles/bov.dir/src/BOV.c.o
deps/BOV/lib/libbov.a: deps/BOV/CMakeFiles/bov.dir/build.make
deps/BOV/lib/libbov.a: deps/BOV/CMakeFiles/bov.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/avekemans/Documents/Numerical Geometry/NGP-master/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library lib/libbov.a"
	cd "/home/avekemans/Documents/Numerical Geometry/NGP-master/cmake-build-debug/deps/BOV" && $(CMAKE_COMMAND) -P CMakeFiles/bov.dir/cmake_clean_target.cmake
	cd "/home/avekemans/Documents/Numerical Geometry/NGP-master/cmake-build-debug/deps/BOV" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bov.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
deps/BOV/CMakeFiles/bov.dir/build: deps/BOV/lib/libbov.a
.PHONY : deps/BOV/CMakeFiles/bov.dir/build

deps/BOV/CMakeFiles/bov.dir/clean:
	cd "/home/avekemans/Documents/Numerical Geometry/NGP-master/cmake-build-debug/deps/BOV" && $(CMAKE_COMMAND) -P CMakeFiles/bov.dir/cmake_clean.cmake
.PHONY : deps/BOV/CMakeFiles/bov.dir/clean

deps/BOV/CMakeFiles/bov.dir/depend:
	cd "/home/avekemans/Documents/Numerical Geometry/NGP-master/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/avekemans/Documents/Numerical Geometry/NGP-master" "/home/avekemans/Documents/Numerical Geometry/NGP-master/deps/BOV" "/home/avekemans/Documents/Numerical Geometry/NGP-master/cmake-build-debug" "/home/avekemans/Documents/Numerical Geometry/NGP-master/cmake-build-debug/deps/BOV" "/home/avekemans/Documents/Numerical Geometry/NGP-master/cmake-build-debug/deps/BOV/CMakeFiles/bov.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : deps/BOV/CMakeFiles/bov.dir/depend

