# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/GroverDover/cie/njgrove/homework/hw1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/GroverDover/cie/njgrove/homework/hw1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/hw1.exe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hw1.exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw1.exe.dir/flags.make

CMakeFiles/hw1.exe.dir/hw1.cpp.o: CMakeFiles/hw1.exe.dir/flags.make
CMakeFiles/hw1.exe.dir/hw1.cpp.o: ../hw1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/GroverDover/cie/njgrove/homework/hw1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hw1.exe.dir/hw1.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw1.exe.dir/hw1.cpp.o -c /Users/GroverDover/cie/njgrove/homework/hw1/hw1.cpp

CMakeFiles/hw1.exe.dir/hw1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw1.exe.dir/hw1.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/GroverDover/cie/njgrove/homework/hw1/hw1.cpp > CMakeFiles/hw1.exe.dir/hw1.cpp.i

CMakeFiles/hw1.exe.dir/hw1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw1.exe.dir/hw1.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/GroverDover/cie/njgrove/homework/hw1/hw1.cpp -o CMakeFiles/hw1.exe.dir/hw1.cpp.s

CMakeFiles/hw1.exe.dir/hw1.cpp.o.requires:

.PHONY : CMakeFiles/hw1.exe.dir/hw1.cpp.o.requires

CMakeFiles/hw1.exe.dir/hw1.cpp.o.provides: CMakeFiles/hw1.exe.dir/hw1.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw1.exe.dir/build.make CMakeFiles/hw1.exe.dir/hw1.cpp.o.provides.build
.PHONY : CMakeFiles/hw1.exe.dir/hw1.cpp.o.provides

CMakeFiles/hw1.exe.dir/hw1.cpp.o.provides.build: CMakeFiles/hw1.exe.dir/hw1.cpp.o


# Object files for target hw1.exe
hw1_exe_OBJECTS = \
"CMakeFiles/hw1.exe.dir/hw1.cpp.o"

# External object files for target hw1.exe
hw1_exe_EXTERNAL_OBJECTS =

hw1.exe: CMakeFiles/hw1.exe.dir/hw1.cpp.o
hw1.exe: CMakeFiles/hw1.exe.dir/build.make
hw1.exe: libhw1lib.a
hw1.exe: CMakeFiles/hw1.exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/GroverDover/cie/njgrove/homework/hw1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hw1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw1.exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw1.exe.dir/build: hw1.exe

.PHONY : CMakeFiles/hw1.exe.dir/build

CMakeFiles/hw1.exe.dir/requires: CMakeFiles/hw1.exe.dir/hw1.cpp.o.requires

.PHONY : CMakeFiles/hw1.exe.dir/requires

CMakeFiles/hw1.exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw1.exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw1.exe.dir/clean

CMakeFiles/hw1.exe.dir/depend:
	cd /Users/GroverDover/cie/njgrove/homework/hw1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/GroverDover/cie/njgrove/homework/hw1 /Users/GroverDover/cie/njgrove/homework/hw1 /Users/GroverDover/cie/njgrove/homework/hw1/cmake-build-debug /Users/GroverDover/cie/njgrove/homework/hw1/cmake-build-debug /Users/GroverDover/cie/njgrove/homework/hw1/cmake-build-debug/CMakeFiles/hw1.exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw1.exe.dir/depend

