# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\Programs\CMake\bin\cmake.exe

# The command to remove a file.
RM = D:\Programs\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Programming\cpp\projects\minesweeper

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Programming\cpp\projects\minesweeper\build

# Include any dependencies generated for this target.
include CMakeFiles/Minesweeper.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Minesweeper.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Minesweeper.dir/flags.make

CMakeFiles/Minesweeper.dir/main.cpp.obj: CMakeFiles/Minesweeper.dir/flags.make
CMakeFiles/Minesweeper.dir/main.cpp.obj: CMakeFiles/Minesweeper.dir/includes_CXX.rsp
CMakeFiles/Minesweeper.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Programming\cpp\projects\minesweeper\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Minesweeper.dir/main.cpp.obj"
	C:\mingw-w64\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Minesweeper.dir\main.cpp.obj -c D:\Programming\cpp\projects\minesweeper\main.cpp

CMakeFiles/Minesweeper.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Minesweeper.dir/main.cpp.i"
	C:\mingw-w64\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Programming\cpp\projects\minesweeper\main.cpp > CMakeFiles\Minesweeper.dir\main.cpp.i

CMakeFiles/Minesweeper.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Minesweeper.dir/main.cpp.s"
	C:\mingw-w64\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Programming\cpp\projects\minesweeper\main.cpp -o CMakeFiles\Minesweeper.dir\main.cpp.s

# Object files for target Minesweeper
Minesweeper_OBJECTS = \
"CMakeFiles/Minesweeper.dir/main.cpp.obj"

# External object files for target Minesweeper
Minesweeper_EXTERNAL_OBJECTS =

Minesweeper.exe: CMakeFiles/Minesweeper.dir/main.cpp.obj
Minesweeper.exe: CMakeFiles/Minesweeper.dir/build.make
Minesweeper.exe: D:/Programming/cpp/libraries/SFML-2.5.1/lib/libsfml-graphics-s-d.a
Minesweeper.exe: include/libTile.a
Minesweeper.exe: include/libBoard.a
Minesweeper.exe: include/libEventHandler.a
Minesweeper.exe: include/libEventLog.a
Minesweeper.exe: include/libMouseAction.a
Minesweeper.exe: include/libTile.a
Minesweeper.exe: include/libBoard.a
Minesweeper.exe: include/libTile.a
Minesweeper.exe: include/libBoard.a
Minesweeper.exe: D:/Programming/cpp/libraries/SFML-2.5.1/lib/libsfml-graphics-s-d.a
Minesweeper.exe: D:/Programming/cpp/libraries/SFML-2.5.1/lib/libsfml-window-s-d.a
Minesweeper.exe: D:/Programming/cpp/libraries/SFML-2.5.1/lib/libsfml-system-s-d.a
Minesweeper.exe: D:/Programming/cpp/libraries/SFML-2.5.1/lib/libfreetype.a
Minesweeper.exe: CMakeFiles/Minesweeper.dir/linklibs.rsp
Minesweeper.exe: CMakeFiles/Minesweeper.dir/objects1.rsp
Minesweeper.exe: CMakeFiles/Minesweeper.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Programming\cpp\projects\minesweeper\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Minesweeper.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Minesweeper.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Minesweeper.dir/build: Minesweeper.exe

.PHONY : CMakeFiles/Minesweeper.dir/build

CMakeFiles/Minesweeper.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Minesweeper.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Minesweeper.dir/clean

CMakeFiles/Minesweeper.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Programming\cpp\projects\minesweeper D:\Programming\cpp\projects\minesweeper D:\Programming\cpp\projects\minesweeper\build D:\Programming\cpp\projects\minesweeper\build D:\Programming\cpp\projects\minesweeper\build\CMakeFiles\Minesweeper.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Minesweeper.dir/depend
