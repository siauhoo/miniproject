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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/charles.cxh/CLionProjects/MiniProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/charles.cxh/CLionProjects/MiniProject/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MiniProject.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/MiniProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MiniProject.dir/flags.make

CMakeFiles/MiniProject.dir/main.cpp.o: CMakeFiles/MiniProject.dir/flags.make
CMakeFiles/MiniProject.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/charles.cxh/CLionProjects/MiniProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MiniProject.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MiniProject.dir/main.cpp.o -c /Users/charles.cxh/CLionProjects/MiniProject/main.cpp

CMakeFiles/MiniProject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MiniProject.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/charles.cxh/CLionProjects/MiniProject/main.cpp > CMakeFiles/MiniProject.dir/main.cpp.i

CMakeFiles/MiniProject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MiniProject.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/charles.cxh/CLionProjects/MiniProject/main.cpp -o CMakeFiles/MiniProject.dir/main.cpp.s

CMakeFiles/MiniProject.dir/Stocks.cpp.o: CMakeFiles/MiniProject.dir/flags.make
CMakeFiles/MiniProject.dir/Stocks.cpp.o: ../Stocks.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/charles.cxh/CLionProjects/MiniProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MiniProject.dir/Stocks.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MiniProject.dir/Stocks.cpp.o -c /Users/charles.cxh/CLionProjects/MiniProject/Stocks.cpp

CMakeFiles/MiniProject.dir/Stocks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MiniProject.dir/Stocks.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/charles.cxh/CLionProjects/MiniProject/Stocks.cpp > CMakeFiles/MiniProject.dir/Stocks.cpp.i

CMakeFiles/MiniProject.dir/Stocks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MiniProject.dir/Stocks.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/charles.cxh/CLionProjects/MiniProject/Stocks.cpp -o CMakeFiles/MiniProject.dir/Stocks.cpp.s

CMakeFiles/MiniProject.dir/File.cpp.o: CMakeFiles/MiniProject.dir/flags.make
CMakeFiles/MiniProject.dir/File.cpp.o: ../File.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/charles.cxh/CLionProjects/MiniProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MiniProject.dir/File.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MiniProject.dir/File.cpp.o -c /Users/charles.cxh/CLionProjects/MiniProject/File.cpp

CMakeFiles/MiniProject.dir/File.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MiniProject.dir/File.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/charles.cxh/CLionProjects/MiniProject/File.cpp > CMakeFiles/MiniProject.dir/File.cpp.i

CMakeFiles/MiniProject.dir/File.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MiniProject.dir/File.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/charles.cxh/CLionProjects/MiniProject/File.cpp -o CMakeFiles/MiniProject.dir/File.cpp.s

CMakeFiles/MiniProject.dir/Snapshot.cpp.o: CMakeFiles/MiniProject.dir/flags.make
CMakeFiles/MiniProject.dir/Snapshot.cpp.o: ../Snapshot.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/charles.cxh/CLionProjects/MiniProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MiniProject.dir/Snapshot.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MiniProject.dir/Snapshot.cpp.o -c /Users/charles.cxh/CLionProjects/MiniProject/Snapshot.cpp

CMakeFiles/MiniProject.dir/Snapshot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MiniProject.dir/Snapshot.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/charles.cxh/CLionProjects/MiniProject/Snapshot.cpp > CMakeFiles/MiniProject.dir/Snapshot.cpp.i

CMakeFiles/MiniProject.dir/Snapshot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MiniProject.dir/Snapshot.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/charles.cxh/CLionProjects/MiniProject/Snapshot.cpp -o CMakeFiles/MiniProject.dir/Snapshot.cpp.s

CMakeFiles/MiniProject.dir/UpdateLevel.cpp.o: CMakeFiles/MiniProject.dir/flags.make
CMakeFiles/MiniProject.dir/UpdateLevel.cpp.o: ../UpdateLevel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/charles.cxh/CLionProjects/MiniProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/MiniProject.dir/UpdateLevel.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MiniProject.dir/UpdateLevel.cpp.o -c /Users/charles.cxh/CLionProjects/MiniProject/UpdateLevel.cpp

CMakeFiles/MiniProject.dir/UpdateLevel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MiniProject.dir/UpdateLevel.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/charles.cxh/CLionProjects/MiniProject/UpdateLevel.cpp > CMakeFiles/MiniProject.dir/UpdateLevel.cpp.i

CMakeFiles/MiniProject.dir/UpdateLevel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MiniProject.dir/UpdateLevel.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/charles.cxh/CLionProjects/MiniProject/UpdateLevel.cpp -o CMakeFiles/MiniProject.dir/UpdateLevel.cpp.s

CMakeFiles/MiniProject.dir/DeleteLevel.cpp.o: CMakeFiles/MiniProject.dir/flags.make
CMakeFiles/MiniProject.dir/DeleteLevel.cpp.o: ../DeleteLevel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/charles.cxh/CLionProjects/MiniProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/MiniProject.dir/DeleteLevel.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MiniProject.dir/DeleteLevel.cpp.o -c /Users/charles.cxh/CLionProjects/MiniProject/DeleteLevel.cpp

CMakeFiles/MiniProject.dir/DeleteLevel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MiniProject.dir/DeleteLevel.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/charles.cxh/CLionProjects/MiniProject/DeleteLevel.cpp > CMakeFiles/MiniProject.dir/DeleteLevel.cpp.i

CMakeFiles/MiniProject.dir/DeleteLevel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MiniProject.dir/DeleteLevel.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/charles.cxh/CLionProjects/MiniProject/DeleteLevel.cpp -o CMakeFiles/MiniProject.dir/DeleteLevel.cpp.s

# Object files for target MiniProject
MiniProject_OBJECTS = \
"CMakeFiles/MiniProject.dir/main.cpp.o" \
"CMakeFiles/MiniProject.dir/Stocks.cpp.o" \
"CMakeFiles/MiniProject.dir/File.cpp.o" \
"CMakeFiles/MiniProject.dir/Snapshot.cpp.o" \
"CMakeFiles/MiniProject.dir/UpdateLevel.cpp.o" \
"CMakeFiles/MiniProject.dir/DeleteLevel.cpp.o"

# External object files for target MiniProject
MiniProject_EXTERNAL_OBJECTS =

MiniProject: CMakeFiles/MiniProject.dir/main.cpp.o
MiniProject: CMakeFiles/MiniProject.dir/Stocks.cpp.o
MiniProject: CMakeFiles/MiniProject.dir/File.cpp.o
MiniProject: CMakeFiles/MiniProject.dir/Snapshot.cpp.o
MiniProject: CMakeFiles/MiniProject.dir/UpdateLevel.cpp.o
MiniProject: CMakeFiles/MiniProject.dir/DeleteLevel.cpp.o
MiniProject: CMakeFiles/MiniProject.dir/build.make
MiniProject: CMakeFiles/MiniProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/charles.cxh/CLionProjects/MiniProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable MiniProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MiniProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MiniProject.dir/build: MiniProject
.PHONY : CMakeFiles/MiniProject.dir/build

CMakeFiles/MiniProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MiniProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MiniProject.dir/clean

CMakeFiles/MiniProject.dir/depend:
	cd /Users/charles.cxh/CLionProjects/MiniProject/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/charles.cxh/CLionProjects/MiniProject /Users/charles.cxh/CLionProjects/MiniProject /Users/charles.cxh/CLionProjects/MiniProject/cmake-build-debug /Users/charles.cxh/CLionProjects/MiniProject/cmake-build-debug /Users/charles.cxh/CLionProjects/MiniProject/cmake-build-debug/CMakeFiles/MiniProject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MiniProject.dir/depend

