# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Project\mianshi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Project\mianshi\build

# Utility rule file for ExperimentalTest.

# Include the progress variables for this target.
include CMakeFiles/ExperimentalTest.dir/progress.make

CMakeFiles/ExperimentalTest:
	"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\ctest.exe" -D ExperimentalTest

ExperimentalTest: CMakeFiles/ExperimentalTest
ExperimentalTest: CMakeFiles/ExperimentalTest.dir/build.make

.PHONY : ExperimentalTest

# Rule to build all files generated by this target.
CMakeFiles/ExperimentalTest.dir/build: ExperimentalTest

.PHONY : CMakeFiles/ExperimentalTest.dir/build

CMakeFiles/ExperimentalTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ExperimentalTest.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ExperimentalTest.dir/clean

CMakeFiles/ExperimentalTest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Project\mianshi D:\Project\mianshi D:\Project\mianshi\build D:\Project\mianshi\build D:\Project\mianshi\build\CMakeFiles\ExperimentalTest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ExperimentalTest.dir/depend

