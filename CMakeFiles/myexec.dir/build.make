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
include CMakeFiles/myexec.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/myexec.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myexec.dir/flags.make

CMakeFiles/myexec.dir/src/main.c.o: CMakeFiles/myexec.dir/flags.make
CMakeFiles/myexec.dir/src/main.c.o: src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/avekemans/Documents/Numerical Geometry/NGP-master/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/myexec.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/myexec.dir/src/main.c.o -c "/home/avekemans/Documents/Numerical Geometry/NGP-master/src/main.c"

CMakeFiles/myexec.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/myexec.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/avekemans/Documents/Numerical Geometry/NGP-master/src/main.c" > CMakeFiles/myexec.dir/src/main.c.i

CMakeFiles/myexec.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/myexec.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/avekemans/Documents/Numerical Geometry/NGP-master/src/main.c" -o CMakeFiles/myexec.dir/src/main.c.s

CMakeFiles/myexec.dir/src/inputs.c.o: CMakeFiles/myexec.dir/flags.make
CMakeFiles/myexec.dir/src/inputs.c.o: src/inputs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/avekemans/Documents/Numerical Geometry/NGP-master/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/myexec.dir/src/inputs.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/myexec.dir/src/inputs.c.o -c "/home/avekemans/Documents/Numerical Geometry/NGP-master/src/inputs.c"

CMakeFiles/myexec.dir/src/inputs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/myexec.dir/src/inputs.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/avekemans/Documents/Numerical Geometry/NGP-master/src/inputs.c" > CMakeFiles/myexec.dir/src/inputs.c.i

CMakeFiles/myexec.dir/src/inputs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/myexec.dir/src/inputs.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/avekemans/Documents/Numerical Geometry/NGP-master/src/inputs.c" -o CMakeFiles/myexec.dir/src/inputs.c.s

CMakeFiles/myexec.dir/src/geometry.c.o: CMakeFiles/myexec.dir/flags.make
CMakeFiles/myexec.dir/src/geometry.c.o: src/geometry.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/avekemans/Documents/Numerical Geometry/NGP-master/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/myexec.dir/src/geometry.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/myexec.dir/src/geometry.c.o -c "/home/avekemans/Documents/Numerical Geometry/NGP-master/src/geometry.c"

CMakeFiles/myexec.dir/src/geometry.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/myexec.dir/src/geometry.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/avekemans/Documents/Numerical Geometry/NGP-master/src/geometry.c" > CMakeFiles/myexec.dir/src/geometry.c.i

CMakeFiles/myexec.dir/src/geometry.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/myexec.dir/src/geometry.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/avekemans/Documents/Numerical Geometry/NGP-master/src/geometry.c" -o CMakeFiles/myexec.dir/src/geometry.c.s

CMakeFiles/myexec.dir/src/point_list.c.o: CMakeFiles/myexec.dir/flags.make
CMakeFiles/myexec.dir/src/point_list.c.o: src/point_list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/avekemans/Documents/Numerical Geometry/NGP-master/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/myexec.dir/src/point_list.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/myexec.dir/src/point_list.c.o -c "/home/avekemans/Documents/Numerical Geometry/NGP-master/src/point_list.c"

CMakeFiles/myexec.dir/src/point_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/myexec.dir/src/point_list.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/avekemans/Documents/Numerical Geometry/NGP-master/src/point_list.c" > CMakeFiles/myexec.dir/src/point_list.c.i

CMakeFiles/myexec.dir/src/point_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/myexec.dir/src/point_list.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/avekemans/Documents/Numerical Geometry/NGP-master/src/point_list.c" -o CMakeFiles/myexec.dir/src/point_list.c.s

CMakeFiles/myexec.dir/src/point_tree.c.o: CMakeFiles/myexec.dir/flags.make
CMakeFiles/myexec.dir/src/point_tree.c.o: src/point_tree.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/avekemans/Documents/Numerical Geometry/NGP-master/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/myexec.dir/src/point_tree.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/myexec.dir/src/point_tree.c.o -c "/home/avekemans/Documents/Numerical Geometry/NGP-master/src/point_tree.c"

CMakeFiles/myexec.dir/src/point_tree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/myexec.dir/src/point_tree.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/avekemans/Documents/Numerical Geometry/NGP-master/src/point_tree.c" > CMakeFiles/myexec.dir/src/point_tree.c.i

CMakeFiles/myexec.dir/src/point_tree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/myexec.dir/src/point_tree.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/avekemans/Documents/Numerical Geometry/NGP-master/src/point_tree.c" -o CMakeFiles/myexec.dir/src/point_tree.c.s

CMakeFiles/myexec.dir/src/segment_tree.c.o: CMakeFiles/myexec.dir/flags.make
CMakeFiles/myexec.dir/src/segment_tree.c.o: src/segment_tree.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/avekemans/Documents/Numerical Geometry/NGP-master/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/myexec.dir/src/segment_tree.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/myexec.dir/src/segment_tree.c.o -c "/home/avekemans/Documents/Numerical Geometry/NGP-master/src/segment_tree.c"

CMakeFiles/myexec.dir/src/segment_tree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/myexec.dir/src/segment_tree.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/avekemans/Documents/Numerical Geometry/NGP-master/src/segment_tree.c" > CMakeFiles/myexec.dir/src/segment_tree.c.i

CMakeFiles/myexec.dir/src/segment_tree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/myexec.dir/src/segment_tree.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/avekemans/Documents/Numerical Geometry/NGP-master/src/segment_tree.c" -o CMakeFiles/myexec.dir/src/segment_tree.c.s

CMakeFiles/myexec.dir/src/sweepline.c.o: CMakeFiles/myexec.dir/flags.make
CMakeFiles/myexec.dir/src/sweepline.c.o: src/sweepline.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/avekemans/Documents/Numerical Geometry/NGP-master/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/myexec.dir/src/sweepline.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/myexec.dir/src/sweepline.c.o -c "/home/avekemans/Documents/Numerical Geometry/NGP-master/src/sweepline.c"

CMakeFiles/myexec.dir/src/sweepline.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/myexec.dir/src/sweepline.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/avekemans/Documents/Numerical Geometry/NGP-master/src/sweepline.c" > CMakeFiles/myexec.dir/src/sweepline.c.i

CMakeFiles/myexec.dir/src/sweepline.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/myexec.dir/src/sweepline.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/avekemans/Documents/Numerical Geometry/NGP-master/src/sweepline.c" -o CMakeFiles/myexec.dir/src/sweepline.c.s

# Object files for target myexec
myexec_OBJECTS = \
"CMakeFiles/myexec.dir/src/main.c.o" \
"CMakeFiles/myexec.dir/src/inputs.c.o" \
"CMakeFiles/myexec.dir/src/geometry.c.o" \
"CMakeFiles/myexec.dir/src/point_list.c.o" \
"CMakeFiles/myexec.dir/src/point_tree.c.o" \
"CMakeFiles/myexec.dir/src/segment_tree.c.o" \
"CMakeFiles/myexec.dir/src/sweepline.c.o"

# External object files for target myexec
myexec_EXTERNAL_OBJECTS =

bin/myexec: CMakeFiles/myexec.dir/src/main.c.o
bin/myexec: CMakeFiles/myexec.dir/src/inputs.c.o
bin/myexec: CMakeFiles/myexec.dir/src/geometry.c.o
bin/myexec: CMakeFiles/myexec.dir/src/point_list.c.o
bin/myexec: CMakeFiles/myexec.dir/src/point_tree.c.o
bin/myexec: CMakeFiles/myexec.dir/src/segment_tree.c.o
bin/myexec: CMakeFiles/myexec.dir/src/sweepline.c.o
bin/myexec: CMakeFiles/myexec.dir/build.make
bin/myexec: deps/BOV/lib/libbov.a
bin/myexec: deps/BOV/deps/glad/libglad.a
bin/myexec: deps/BOV/deps/glfw/src/libglfw3.a
bin/myexec: /usr/lib/x86_64-linux-gnu/librt.so
bin/myexec: /usr/lib/x86_64-linux-gnu/libm.so
bin/myexec: CMakeFiles/myexec.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/avekemans/Documents/Numerical Geometry/NGP-master/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable bin/myexec"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myexec.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/myexec.dir/build: bin/myexec
.PHONY : CMakeFiles/myexec.dir/build

CMakeFiles/myexec.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/myexec.dir/cmake_clean.cmake
.PHONY : CMakeFiles/myexec.dir/clean

CMakeFiles/myexec.dir/depend:
	cd "/home/avekemans/Documents/Numerical Geometry/NGP-master" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/avekemans/Documents/Numerical Geometry/NGP-master" "/home/avekemans/Documents/Numerical Geometry/NGP-master" "/home/avekemans/Documents/Numerical Geometry/NGP-master" "/home/avekemans/Documents/Numerical Geometry/NGP-master" "/home/avekemans/Documents/Numerical Geometry/NGP-master/CMakeFiles/myexec.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/myexec.dir/depend

