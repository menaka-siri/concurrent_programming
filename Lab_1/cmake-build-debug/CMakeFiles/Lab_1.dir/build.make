# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.6

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\JetBrains\CLion 2016.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\JetBrains\CLion 2016.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\CSE\Sem_8\Concurrent\Labs\Lab_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CSE\Sem_8\Concurrent\Labs\Lab_1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab_1.dir/flags.make

CMakeFiles/Lab_1.dir/main.cpp.obj: CMakeFiles/Lab_1.dir/flags.make
CMakeFiles/Lab_1.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CSE\Sem_8\Concurrent\Labs\Lab_1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab_1.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab_1.dir\main.cpp.obj -c D:\CSE\Sem_8\Concurrent\Labs\Lab_1\main.cpp

CMakeFiles/Lab_1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_1.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CSE\Sem_8\Concurrent\Labs\Lab_1\main.cpp > CMakeFiles\Lab_1.dir\main.cpp.i

CMakeFiles/Lab_1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_1.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CSE\Sem_8\Concurrent\Labs\Lab_1\main.cpp -o CMakeFiles\Lab_1.dir\main.cpp.s

CMakeFiles/Lab_1.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Lab_1.dir/main.cpp.obj.requires

CMakeFiles/Lab_1.dir/main.cpp.obj.provides: CMakeFiles/Lab_1.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Lab_1.dir\build.make CMakeFiles/Lab_1.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Lab_1.dir/main.cpp.obj.provides

CMakeFiles/Lab_1.dir/main.cpp.obj.provides.build: CMakeFiles/Lab_1.dir/main.cpp.obj


# Object files for target Lab_1
Lab_1_OBJECTS = \
"CMakeFiles/Lab_1.dir/main.cpp.obj"

# External object files for target Lab_1
Lab_1_EXTERNAL_OBJECTS =

Lab_1.exe: CMakeFiles/Lab_1.dir/main.cpp.obj
Lab_1.exe: CMakeFiles/Lab_1.dir/build.make
Lab_1.exe: CMakeFiles/Lab_1.dir/linklibs.rsp
Lab_1.exe: CMakeFiles/Lab_1.dir/objects1.rsp
Lab_1.exe: CMakeFiles/Lab_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CSE\Sem_8\Concurrent\Labs\Lab_1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lab_1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lab_1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab_1.dir/build: Lab_1.exe

.PHONY : CMakeFiles/Lab_1.dir/build

CMakeFiles/Lab_1.dir/requires: CMakeFiles/Lab_1.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/Lab_1.dir/requires

CMakeFiles/Lab_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lab_1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lab_1.dir/clean

CMakeFiles/Lab_1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CSE\Sem_8\Concurrent\Labs\Lab_1 D:\CSE\Sem_8\Concurrent\Labs\Lab_1 D:\CSE\Sem_8\Concurrent\Labs\Lab_1\cmake-build-debug D:\CSE\Sem_8\Concurrent\Labs\Lab_1\cmake-build-debug D:\CSE\Sem_8\Concurrent\Labs\Lab_1\cmake-build-debug\CMakeFiles\Lab_1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab_1.dir/depend

