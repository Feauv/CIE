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
CMAKE_SOURCE_DIR = /Users/GroverDover/cie/njgrove/homework/hw4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/GroverDover/cie/njgrove/homework/hw4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ReportGeneration.exe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ReportGeneration.exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ReportGeneration.exe.dir/flags.make

CMakeFiles/ReportGeneration.exe.dir/ReportGeneration.cpp.o: CMakeFiles/ReportGeneration.exe.dir/flags.make
CMakeFiles/ReportGeneration.exe.dir/ReportGeneration.cpp.o: ../ReportGeneration.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/GroverDover/cie/njgrove/homework/hw4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ReportGeneration.exe.dir/ReportGeneration.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReportGeneration.exe.dir/ReportGeneration.cpp.o -c /Users/GroverDover/cie/njgrove/homework/hw4/ReportGeneration.cpp

CMakeFiles/ReportGeneration.exe.dir/ReportGeneration.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReportGeneration.exe.dir/ReportGeneration.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/GroverDover/cie/njgrove/homework/hw4/ReportGeneration.cpp > CMakeFiles/ReportGeneration.exe.dir/ReportGeneration.cpp.i

CMakeFiles/ReportGeneration.exe.dir/ReportGeneration.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReportGeneration.exe.dir/ReportGeneration.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/GroverDover/cie/njgrove/homework/hw4/ReportGeneration.cpp -o CMakeFiles/ReportGeneration.exe.dir/ReportGeneration.cpp.s

CMakeFiles/ReportGeneration.exe.dir/ReportGeneration.cpp.o.requires:

.PHONY : CMakeFiles/ReportGeneration.exe.dir/ReportGeneration.cpp.o.requires

CMakeFiles/ReportGeneration.exe.dir/ReportGeneration.cpp.o.provides: CMakeFiles/ReportGeneration.exe.dir/ReportGeneration.cpp.o.requires
	$(MAKE) -f CMakeFiles/ReportGeneration.exe.dir/build.make CMakeFiles/ReportGeneration.exe.dir/ReportGeneration.cpp.o.provides.build
.PHONY : CMakeFiles/ReportGeneration.exe.dir/ReportGeneration.cpp.o.provides

CMakeFiles/ReportGeneration.exe.dir/ReportGeneration.cpp.o.provides.build: CMakeFiles/ReportGeneration.exe.dir/ReportGeneration.cpp.o


# Object files for target ReportGeneration.exe
ReportGeneration_exe_OBJECTS = \
"CMakeFiles/ReportGeneration.exe.dir/ReportGeneration.cpp.o"

# External object files for target ReportGeneration.exe
ReportGeneration_exe_EXTERNAL_OBJECTS =

ReportGeneration.exe: CMakeFiles/ReportGeneration.exe.dir/ReportGeneration.cpp.o
ReportGeneration.exe: CMakeFiles/ReportGeneration.exe.dir/build.make
ReportGeneration.exe: libhw4lib.a
ReportGeneration.exe: CMakeFiles/ReportGeneration.exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/GroverDover/cie/njgrove/homework/hw4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ReportGeneration.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ReportGeneration.exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ReportGeneration.exe.dir/build: ReportGeneration.exe

.PHONY : CMakeFiles/ReportGeneration.exe.dir/build

CMakeFiles/ReportGeneration.exe.dir/requires: CMakeFiles/ReportGeneration.exe.dir/ReportGeneration.cpp.o.requires

.PHONY : CMakeFiles/ReportGeneration.exe.dir/requires

CMakeFiles/ReportGeneration.exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ReportGeneration.exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ReportGeneration.exe.dir/clean

CMakeFiles/ReportGeneration.exe.dir/depend:
	cd /Users/GroverDover/cie/njgrove/homework/hw4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/GroverDover/cie/njgrove/homework/hw4 /Users/GroverDover/cie/njgrove/homework/hw4 /Users/GroverDover/cie/njgrove/homework/hw4/cmake-build-debug /Users/GroverDover/cie/njgrove/homework/hw4/cmake-build-debug /Users/GroverDover/cie/njgrove/homework/hw4/cmake-build-debug/CMakeFiles/ReportGeneration.exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ReportGeneration.exe.dir/depend

