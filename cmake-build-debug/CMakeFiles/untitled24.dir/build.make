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
CMAKE_COMMAND = /snap/clion/107/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/107/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tamir/CLionProjects/untitled24

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tamir/CLionProjects/untitled24/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untitled24.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled24.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled24.dir/flags.make

CMakeFiles/untitled24.dir/main.c.o: CMakeFiles/untitled24.dir/flags.make
CMakeFiles/untitled24.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tamir/CLionProjects/untitled24/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/untitled24.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/untitled24.dir/main.c.o   -c /home/tamir/CLionProjects/untitled24/main.c

CMakeFiles/untitled24.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled24.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tamir/CLionProjects/untitled24/main.c > CMakeFiles/untitled24.dir/main.c.i

CMakeFiles/untitled24.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled24.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tamir/CLionProjects/untitled24/main.c -o CMakeFiles/untitled24.dir/main.c.s

CMakeFiles/untitled24.dir/osqueue.c.o: CMakeFiles/untitled24.dir/flags.make
CMakeFiles/untitled24.dir/osqueue.c.o: ../osqueue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tamir/CLionProjects/untitled24/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/untitled24.dir/osqueue.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/untitled24.dir/osqueue.c.o   -c /home/tamir/CLionProjects/untitled24/osqueue.c

CMakeFiles/untitled24.dir/osqueue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled24.dir/osqueue.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tamir/CLionProjects/untitled24/osqueue.c > CMakeFiles/untitled24.dir/osqueue.c.i

CMakeFiles/untitled24.dir/osqueue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled24.dir/osqueue.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tamir/CLionProjects/untitled24/osqueue.c -o CMakeFiles/untitled24.dir/osqueue.c.s

CMakeFiles/untitled24.dir/threadPool.c.o: CMakeFiles/untitled24.dir/flags.make
CMakeFiles/untitled24.dir/threadPool.c.o: ../threadPool.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tamir/CLionProjects/untitled24/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/untitled24.dir/threadPool.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/untitled24.dir/threadPool.c.o   -c /home/tamir/CLionProjects/untitled24/threadPool.c

CMakeFiles/untitled24.dir/threadPool.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled24.dir/threadPool.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tamir/CLionProjects/untitled24/threadPool.c > CMakeFiles/untitled24.dir/threadPool.c.i

CMakeFiles/untitled24.dir/threadPool.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled24.dir/threadPool.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tamir/CLionProjects/untitled24/threadPool.c -o CMakeFiles/untitled24.dir/threadPool.c.s

# Object files for target untitled24
untitled24_OBJECTS = \
"CMakeFiles/untitled24.dir/main.c.o" \
"CMakeFiles/untitled24.dir/osqueue.c.o" \
"CMakeFiles/untitled24.dir/threadPool.c.o"

# External object files for target untitled24
untitled24_EXTERNAL_OBJECTS =

untitled24: CMakeFiles/untitled24.dir/main.c.o
untitled24: CMakeFiles/untitled24.dir/osqueue.c.o
untitled24: CMakeFiles/untitled24.dir/threadPool.c.o
untitled24: CMakeFiles/untitled24.dir/build.make
untitled24: CMakeFiles/untitled24.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tamir/CLionProjects/untitled24/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable untitled24"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/untitled24.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled24.dir/build: untitled24

.PHONY : CMakeFiles/untitled24.dir/build

CMakeFiles/untitled24.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/untitled24.dir/cmake_clean.cmake
.PHONY : CMakeFiles/untitled24.dir/clean

CMakeFiles/untitled24.dir/depend:
	cd /home/tamir/CLionProjects/untitled24/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tamir/CLionProjects/untitled24 /home/tamir/CLionProjects/untitled24 /home/tamir/CLionProjects/untitled24/cmake-build-debug /home/tamir/CLionProjects/untitled24/cmake-build-debug /home/tamir/CLionProjects/untitled24/cmake-build-debug/CMakeFiles/untitled24.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untitled24.dir/depend
