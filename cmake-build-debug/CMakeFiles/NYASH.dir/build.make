# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jade/CLionProjects/NYASH

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jade/CLionProjects/NYASH/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/NYASH.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/NYASH.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NYASH.dir/flags.make

CMakeFiles/NYASH.dir/main.c.o: CMakeFiles/NYASH.dir/flags.make
CMakeFiles/NYASH.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jade/CLionProjects/NYASH/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/NYASH.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NYASH.dir/main.c.o -c /home/jade/CLionProjects/NYASH/main.c

CMakeFiles/NYASH.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NYASH.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jade/CLionProjects/NYASH/main.c > CMakeFiles/NYASH.dir/main.c.i

CMakeFiles/NYASH.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NYASH.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jade/CLionProjects/NYASH/main.c -o CMakeFiles/NYASH.dir/main.c.s

CMakeFiles/NYASH.dir/processor/init.c.o: CMakeFiles/NYASH.dir/flags.make
CMakeFiles/NYASH.dir/processor/init.c.o: ../processor/init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jade/CLionProjects/NYASH/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/NYASH.dir/processor/init.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NYASH.dir/processor/init.c.o -c /home/jade/CLionProjects/NYASH/processor/init.c

CMakeFiles/NYASH.dir/processor/init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NYASH.dir/processor/init.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jade/CLionProjects/NYASH/processor/init.c > CMakeFiles/NYASH.dir/processor/init.c.i

CMakeFiles/NYASH.dir/processor/init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NYASH.dir/processor/init.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jade/CLionProjects/NYASH/processor/init.c -o CMakeFiles/NYASH.dir/processor/init.c.s

CMakeFiles/NYASH.dir/processor/prompt.c.o: CMakeFiles/NYASH.dir/flags.make
CMakeFiles/NYASH.dir/processor/prompt.c.o: ../processor/prompt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jade/CLionProjects/NYASH/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/NYASH.dir/processor/prompt.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NYASH.dir/processor/prompt.c.o -c /home/jade/CLionProjects/NYASH/processor/prompt.c

CMakeFiles/NYASH.dir/processor/prompt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NYASH.dir/processor/prompt.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jade/CLionProjects/NYASH/processor/prompt.c > CMakeFiles/NYASH.dir/processor/prompt.c.i

CMakeFiles/NYASH.dir/processor/prompt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NYASH.dir/processor/prompt.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jade/CLionProjects/NYASH/processor/prompt.c -o CMakeFiles/NYASH.dir/processor/prompt.c.s

CMakeFiles/NYASH.dir/utils/parse.c.o: CMakeFiles/NYASH.dir/flags.make
CMakeFiles/NYASH.dir/utils/parse.c.o: ../utils/parse.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jade/CLionProjects/NYASH/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/NYASH.dir/utils/parse.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NYASH.dir/utils/parse.c.o -c /home/jade/CLionProjects/NYASH/utils/parse.c

CMakeFiles/NYASH.dir/utils/parse.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NYASH.dir/utils/parse.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jade/CLionProjects/NYASH/utils/parse.c > CMakeFiles/NYASH.dir/utils/parse.c.i

CMakeFiles/NYASH.dir/utils/parse.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NYASH.dir/utils/parse.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jade/CLionProjects/NYASH/utils/parse.c -o CMakeFiles/NYASH.dir/utils/parse.c.s

CMakeFiles/NYASH.dir/commands/pwd.c.o: CMakeFiles/NYASH.dir/flags.make
CMakeFiles/NYASH.dir/commands/pwd.c.o: ../commands/pwd.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jade/CLionProjects/NYASH/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/NYASH.dir/commands/pwd.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NYASH.dir/commands/pwd.c.o -c /home/jade/CLionProjects/NYASH/commands/pwd.c

CMakeFiles/NYASH.dir/commands/pwd.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NYASH.dir/commands/pwd.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jade/CLionProjects/NYASH/commands/pwd.c > CMakeFiles/NYASH.dir/commands/pwd.c.i

CMakeFiles/NYASH.dir/commands/pwd.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NYASH.dir/commands/pwd.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jade/CLionProjects/NYASH/commands/pwd.c -o CMakeFiles/NYASH.dir/commands/pwd.c.s

CMakeFiles/NYASH.dir/utils/tokenize.c.o: CMakeFiles/NYASH.dir/flags.make
CMakeFiles/NYASH.dir/utils/tokenize.c.o: ../utils/tokenize.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jade/CLionProjects/NYASH/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/NYASH.dir/utils/tokenize.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NYASH.dir/utils/tokenize.c.o -c /home/jade/CLionProjects/NYASH/utils/tokenize.c

CMakeFiles/NYASH.dir/utils/tokenize.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NYASH.dir/utils/tokenize.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jade/CLionProjects/NYASH/utils/tokenize.c > CMakeFiles/NYASH.dir/utils/tokenize.c.i

CMakeFiles/NYASH.dir/utils/tokenize.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NYASH.dir/utils/tokenize.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jade/CLionProjects/NYASH/utils/tokenize.c -o CMakeFiles/NYASH.dir/utils/tokenize.c.s

CMakeFiles/NYASH.dir/utils/vector.c.o: CMakeFiles/NYASH.dir/flags.make
CMakeFiles/NYASH.dir/utils/vector.c.o: ../utils/vector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jade/CLionProjects/NYASH/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/NYASH.dir/utils/vector.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NYASH.dir/utils/vector.c.o -c /home/jade/CLionProjects/NYASH/utils/vector.c

CMakeFiles/NYASH.dir/utils/vector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NYASH.dir/utils/vector.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jade/CLionProjects/NYASH/utils/vector.c > CMakeFiles/NYASH.dir/utils/vector.c.i

CMakeFiles/NYASH.dir/utils/vector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NYASH.dir/utils/vector.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jade/CLionProjects/NYASH/utils/vector.c -o CMakeFiles/NYASH.dir/utils/vector.c.s

CMakeFiles/NYASH.dir/commands/echo.c.o: CMakeFiles/NYASH.dir/flags.make
CMakeFiles/NYASH.dir/commands/echo.c.o: ../commands/echo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jade/CLionProjects/NYASH/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/NYASH.dir/commands/echo.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NYASH.dir/commands/echo.c.o -c /home/jade/CLionProjects/NYASH/commands/echo.c

CMakeFiles/NYASH.dir/commands/echo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NYASH.dir/commands/echo.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jade/CLionProjects/NYASH/commands/echo.c > CMakeFiles/NYASH.dir/commands/echo.c.i

CMakeFiles/NYASH.dir/commands/echo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NYASH.dir/commands/echo.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jade/CLionProjects/NYASH/commands/echo.c -o CMakeFiles/NYASH.dir/commands/echo.c.s

CMakeFiles/NYASH.dir/commands/cd.c.o: CMakeFiles/NYASH.dir/flags.make
CMakeFiles/NYASH.dir/commands/cd.c.o: ../commands/cd.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jade/CLionProjects/NYASH/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/NYASH.dir/commands/cd.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NYASH.dir/commands/cd.c.o -c /home/jade/CLionProjects/NYASH/commands/cd.c

CMakeFiles/NYASH.dir/commands/cd.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NYASH.dir/commands/cd.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jade/CLionProjects/NYASH/commands/cd.c > CMakeFiles/NYASH.dir/commands/cd.c.i

CMakeFiles/NYASH.dir/commands/cd.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NYASH.dir/commands/cd.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jade/CLionProjects/NYASH/commands/cd.c -o CMakeFiles/NYASH.dir/commands/cd.c.s

CMakeFiles/NYASH.dir/commands/ls.c.o: CMakeFiles/NYASH.dir/flags.make
CMakeFiles/NYASH.dir/commands/ls.c.o: ../commands/ls.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jade/CLionProjects/NYASH/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/NYASH.dir/commands/ls.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NYASH.dir/commands/ls.c.o -c /home/jade/CLionProjects/NYASH/commands/ls.c

CMakeFiles/NYASH.dir/commands/ls.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NYASH.dir/commands/ls.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jade/CLionProjects/NYASH/commands/ls.c > CMakeFiles/NYASH.dir/commands/ls.c.i

CMakeFiles/NYASH.dir/commands/ls.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NYASH.dir/commands/ls.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jade/CLionProjects/NYASH/commands/ls.c -o CMakeFiles/NYASH.dir/commands/ls.c.s

CMakeFiles/NYASH.dir/processor/sysCommands.c.o: CMakeFiles/NYASH.dir/flags.make
CMakeFiles/NYASH.dir/processor/sysCommands.c.o: ../processor/sysCommands.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jade/CLionProjects/NYASH/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/NYASH.dir/processor/sysCommands.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NYASH.dir/processor/sysCommands.c.o -c /home/jade/CLionProjects/NYASH/processor/sysCommands.c

CMakeFiles/NYASH.dir/processor/sysCommands.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NYASH.dir/processor/sysCommands.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jade/CLionProjects/NYASH/processor/sysCommands.c > CMakeFiles/NYASH.dir/processor/sysCommands.c.i

CMakeFiles/NYASH.dir/processor/sysCommands.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NYASH.dir/processor/sysCommands.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jade/CLionProjects/NYASH/processor/sysCommands.c -o CMakeFiles/NYASH.dir/processor/sysCommands.c.s

CMakeFiles/NYASH.dir/commands/pinfo.c.o: CMakeFiles/NYASH.dir/flags.make
CMakeFiles/NYASH.dir/commands/pinfo.c.o: ../commands/pinfo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jade/CLionProjects/NYASH/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/NYASH.dir/commands/pinfo.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NYASH.dir/commands/pinfo.c.o -c /home/jade/CLionProjects/NYASH/commands/pinfo.c

CMakeFiles/NYASH.dir/commands/pinfo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NYASH.dir/commands/pinfo.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jade/CLionProjects/NYASH/commands/pinfo.c > CMakeFiles/NYASH.dir/commands/pinfo.c.i

CMakeFiles/NYASH.dir/commands/pinfo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NYASH.dir/commands/pinfo.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jade/CLionProjects/NYASH/commands/pinfo.c -o CMakeFiles/NYASH.dir/commands/pinfo.c.s

CMakeFiles/NYASH.dir/commands/repeat.c.o: CMakeFiles/NYASH.dir/flags.make
CMakeFiles/NYASH.dir/commands/repeat.c.o: ../commands/repeat.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jade/CLionProjects/NYASH/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/NYASH.dir/commands/repeat.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NYASH.dir/commands/repeat.c.o -c /home/jade/CLionProjects/NYASH/commands/repeat.c

CMakeFiles/NYASH.dir/commands/repeat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NYASH.dir/commands/repeat.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jade/CLionProjects/NYASH/commands/repeat.c > CMakeFiles/NYASH.dir/commands/repeat.c.i

CMakeFiles/NYASH.dir/commands/repeat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NYASH.dir/commands/repeat.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jade/CLionProjects/NYASH/commands/repeat.c -o CMakeFiles/NYASH.dir/commands/repeat.c.s

CMakeFiles/NYASH.dir/commands/history.c.o: CMakeFiles/NYASH.dir/flags.make
CMakeFiles/NYASH.dir/commands/history.c.o: ../commands/history.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jade/CLionProjects/NYASH/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/NYASH.dir/commands/history.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NYASH.dir/commands/history.c.o -c /home/jade/CLionProjects/NYASH/commands/history.c

CMakeFiles/NYASH.dir/commands/history.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NYASH.dir/commands/history.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jade/CLionProjects/NYASH/commands/history.c > CMakeFiles/NYASH.dir/commands/history.c.i

CMakeFiles/NYASH.dir/commands/history.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NYASH.dir/commands/history.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jade/CLionProjects/NYASH/commands/history.c -o CMakeFiles/NYASH.dir/commands/history.c.s

CMakeFiles/NYASH.dir/utils/list.c.o: CMakeFiles/NYASH.dir/flags.make
CMakeFiles/NYASH.dir/utils/list.c.o: ../utils/list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jade/CLionProjects/NYASH/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/NYASH.dir/utils/list.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NYASH.dir/utils/list.c.o -c /home/jade/CLionProjects/NYASH/utils/list.c

CMakeFiles/NYASH.dir/utils/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NYASH.dir/utils/list.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jade/CLionProjects/NYASH/utils/list.c > CMakeFiles/NYASH.dir/utils/list.c.i

CMakeFiles/NYASH.dir/utils/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NYASH.dir/utils/list.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jade/CLionProjects/NYASH/utils/list.c -o CMakeFiles/NYASH.dir/utils/list.c.s

CMakeFiles/NYASH.dir/processor/child_handler.c.o: CMakeFiles/NYASH.dir/flags.make
CMakeFiles/NYASH.dir/processor/child_handler.c.o: ../processor/child_handler.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jade/CLionProjects/NYASH/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/NYASH.dir/processor/child_handler.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NYASH.dir/processor/child_handler.c.o -c /home/jade/CLionProjects/NYASH/processor/child_handler.c

CMakeFiles/NYASH.dir/processor/child_handler.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NYASH.dir/processor/child_handler.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jade/CLionProjects/NYASH/processor/child_handler.c > CMakeFiles/NYASH.dir/processor/child_handler.c.i

CMakeFiles/NYASH.dir/processor/child_handler.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NYASH.dir/processor/child_handler.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jade/CLionProjects/NYASH/processor/child_handler.c -o CMakeFiles/NYASH.dir/processor/child_handler.c.s

CMakeFiles/NYASH.dir/utils/job_list.c.o: CMakeFiles/NYASH.dir/flags.make
CMakeFiles/NYASH.dir/utils/job_list.c.o: ../utils/job_list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jade/CLionProjects/NYASH/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building C object CMakeFiles/NYASH.dir/utils/job_list.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NYASH.dir/utils/job_list.c.o -c /home/jade/CLionProjects/NYASH/utils/job_list.c

CMakeFiles/NYASH.dir/utils/job_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NYASH.dir/utils/job_list.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jade/CLionProjects/NYASH/utils/job_list.c > CMakeFiles/NYASH.dir/utils/job_list.c.i

CMakeFiles/NYASH.dir/utils/job_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NYASH.dir/utils/job_list.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jade/CLionProjects/NYASH/utils/job_list.c -o CMakeFiles/NYASH.dir/utils/job_list.c.s

CMakeFiles/NYASH.dir/commands/jobs.c.o: CMakeFiles/NYASH.dir/flags.make
CMakeFiles/NYASH.dir/commands/jobs.c.o: ../commands/jobs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jade/CLionProjects/NYASH/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building C object CMakeFiles/NYASH.dir/commands/jobs.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NYASH.dir/commands/jobs.c.o -c /home/jade/CLionProjects/NYASH/commands/jobs.c

CMakeFiles/NYASH.dir/commands/jobs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NYASH.dir/commands/jobs.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jade/CLionProjects/NYASH/commands/jobs.c > CMakeFiles/NYASH.dir/commands/jobs.c.i

CMakeFiles/NYASH.dir/commands/jobs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NYASH.dir/commands/jobs.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jade/CLionProjects/NYASH/commands/jobs.c -o CMakeFiles/NYASH.dir/commands/jobs.c.s

CMakeFiles/NYASH.dir/commands/sig.c.o: CMakeFiles/NYASH.dir/flags.make
CMakeFiles/NYASH.dir/commands/sig.c.o: ../commands/sig.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jade/CLionProjects/NYASH/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building C object CMakeFiles/NYASH.dir/commands/sig.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NYASH.dir/commands/sig.c.o -c /home/jade/CLionProjects/NYASH/commands/sig.c

CMakeFiles/NYASH.dir/commands/sig.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NYASH.dir/commands/sig.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jade/CLionProjects/NYASH/commands/sig.c > CMakeFiles/NYASH.dir/commands/sig.c.i

CMakeFiles/NYASH.dir/commands/sig.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NYASH.dir/commands/sig.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jade/CLionProjects/NYASH/commands/sig.c -o CMakeFiles/NYASH.dir/commands/sig.c.s

CMakeFiles/NYASH.dir/commands/fg.c.o: CMakeFiles/NYASH.dir/flags.make
CMakeFiles/NYASH.dir/commands/fg.c.o: ../commands/fg.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jade/CLionProjects/NYASH/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building C object CMakeFiles/NYASH.dir/commands/fg.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NYASH.dir/commands/fg.c.o -c /home/jade/CLionProjects/NYASH/commands/fg.c

CMakeFiles/NYASH.dir/commands/fg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NYASH.dir/commands/fg.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jade/CLionProjects/NYASH/commands/fg.c > CMakeFiles/NYASH.dir/commands/fg.c.i

CMakeFiles/NYASH.dir/commands/fg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NYASH.dir/commands/fg.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jade/CLionProjects/NYASH/commands/fg.c -o CMakeFiles/NYASH.dir/commands/fg.c.s

CMakeFiles/NYASH.dir/commands/bg.c.o: CMakeFiles/NYASH.dir/flags.make
CMakeFiles/NYASH.dir/commands/bg.c.o: ../commands/bg.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jade/CLionProjects/NYASH/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Building C object CMakeFiles/NYASH.dir/commands/bg.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NYASH.dir/commands/bg.c.o -c /home/jade/CLionProjects/NYASH/commands/bg.c

CMakeFiles/NYASH.dir/commands/bg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NYASH.dir/commands/bg.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jade/CLionProjects/NYASH/commands/bg.c > CMakeFiles/NYASH.dir/commands/bg.c.i

CMakeFiles/NYASH.dir/commands/bg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NYASH.dir/commands/bg.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jade/CLionProjects/NYASH/commands/bg.c -o CMakeFiles/NYASH.dir/commands/bg.c.s

CMakeFiles/NYASH.dir/commands/replay.c.o: CMakeFiles/NYASH.dir/flags.make
CMakeFiles/NYASH.dir/commands/replay.c.o: ../commands/replay.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jade/CLionProjects/NYASH/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_22) "Building C object CMakeFiles/NYASH.dir/commands/replay.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NYASH.dir/commands/replay.c.o -c /home/jade/CLionProjects/NYASH/commands/replay.c

CMakeFiles/NYASH.dir/commands/replay.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NYASH.dir/commands/replay.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jade/CLionProjects/NYASH/commands/replay.c > CMakeFiles/NYASH.dir/commands/replay.c.i

CMakeFiles/NYASH.dir/commands/replay.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NYASH.dir/commands/replay.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jade/CLionProjects/NYASH/commands/replay.c -o CMakeFiles/NYASH.dir/commands/replay.c.s

# Object files for target NYASH
NYASH_OBJECTS = \
"CMakeFiles/NYASH.dir/main.c.o" \
"CMakeFiles/NYASH.dir/processor/init.c.o" \
"CMakeFiles/NYASH.dir/processor/prompt.c.o" \
"CMakeFiles/NYASH.dir/utils/parse.c.o" \
"CMakeFiles/NYASH.dir/commands/pwd.c.o" \
"CMakeFiles/NYASH.dir/utils/tokenize.c.o" \
"CMakeFiles/NYASH.dir/utils/vector.c.o" \
"CMakeFiles/NYASH.dir/commands/echo.c.o" \
"CMakeFiles/NYASH.dir/commands/cd.c.o" \
"CMakeFiles/NYASH.dir/commands/ls.c.o" \
"CMakeFiles/NYASH.dir/processor/sysCommands.c.o" \
"CMakeFiles/NYASH.dir/commands/pinfo.c.o" \
"CMakeFiles/NYASH.dir/commands/repeat.c.o" \
"CMakeFiles/NYASH.dir/commands/history.c.o" \
"CMakeFiles/NYASH.dir/utils/list.c.o" \
"CMakeFiles/NYASH.dir/processor/child_handler.c.o" \
"CMakeFiles/NYASH.dir/utils/job_list.c.o" \
"CMakeFiles/NYASH.dir/commands/jobs.c.o" \
"CMakeFiles/NYASH.dir/commands/sig.c.o" \
"CMakeFiles/NYASH.dir/commands/fg.c.o" \
"CMakeFiles/NYASH.dir/commands/bg.c.o" \
"CMakeFiles/NYASH.dir/commands/replay.c.o"

# External object files for target NYASH
NYASH_EXTERNAL_OBJECTS =

NYASH: CMakeFiles/NYASH.dir/main.c.o
NYASH: CMakeFiles/NYASH.dir/processor/init.c.o
NYASH: CMakeFiles/NYASH.dir/processor/prompt.c.o
NYASH: CMakeFiles/NYASH.dir/utils/parse.c.o
NYASH: CMakeFiles/NYASH.dir/commands/pwd.c.o
NYASH: CMakeFiles/NYASH.dir/utils/tokenize.c.o
NYASH: CMakeFiles/NYASH.dir/utils/vector.c.o
NYASH: CMakeFiles/NYASH.dir/commands/echo.c.o
NYASH: CMakeFiles/NYASH.dir/commands/cd.c.o
NYASH: CMakeFiles/NYASH.dir/commands/ls.c.o
NYASH: CMakeFiles/NYASH.dir/processor/sysCommands.c.o
NYASH: CMakeFiles/NYASH.dir/commands/pinfo.c.o
NYASH: CMakeFiles/NYASH.dir/commands/repeat.c.o
NYASH: CMakeFiles/NYASH.dir/commands/history.c.o
NYASH: CMakeFiles/NYASH.dir/utils/list.c.o
NYASH: CMakeFiles/NYASH.dir/processor/child_handler.c.o
NYASH: CMakeFiles/NYASH.dir/utils/job_list.c.o
NYASH: CMakeFiles/NYASH.dir/commands/jobs.c.o
NYASH: CMakeFiles/NYASH.dir/commands/sig.c.o
NYASH: CMakeFiles/NYASH.dir/commands/fg.c.o
NYASH: CMakeFiles/NYASH.dir/commands/bg.c.o
NYASH: CMakeFiles/NYASH.dir/commands/replay.c.o
NYASH: CMakeFiles/NYASH.dir/build.make
NYASH: CMakeFiles/NYASH.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jade/CLionProjects/NYASH/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_23) "Linking C executable NYASH"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NYASH.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NYASH.dir/build: NYASH
.PHONY : CMakeFiles/NYASH.dir/build

CMakeFiles/NYASH.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NYASH.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NYASH.dir/clean

CMakeFiles/NYASH.dir/depend:
	cd /home/jade/CLionProjects/NYASH/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jade/CLionProjects/NYASH /home/jade/CLionProjects/NYASH /home/jade/CLionProjects/NYASH/cmake-build-debug /home/jade/CLionProjects/NYASH/cmake-build-debug /home/jade/CLionProjects/NYASH/cmake-build-debug/CMakeFiles/NYASH.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NYASH.dir/depend

