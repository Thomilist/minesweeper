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
include include/ms/CMakeFiles/Board.dir/depend.make

# Include the progress variables for this target.
include include/ms/CMakeFiles/Board.dir/progress.make

# Include the compile flags for this target's objects.
include include/ms/CMakeFiles/Board.dir/flags.make

include/ms/CMakeFiles/Board.dir/board.cpp.obj: include/ms/CMakeFiles/Board.dir/flags.make
include/ms/CMakeFiles/Board.dir/board.cpp.obj: include/ms/CMakeFiles/Board.dir/includes_CXX.rsp
include/ms/CMakeFiles/Board.dir/board.cpp.obj: ../include/ms/board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Programming\cpp\projects\minesweeper\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object include/ms/CMakeFiles/Board.dir/board.cpp.obj"
	cd /d D:\Programming\cpp\projects\minesweeper\build\include\ms && C:\mingw-w64\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Board.dir\board.cpp.obj -c D:\Programming\cpp\projects\minesweeper\include\ms\board.cpp

include/ms/CMakeFiles/Board.dir/board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Board.dir/board.cpp.i"
	cd /d D:\Programming\cpp\projects\minesweeper\build\include\ms && C:\mingw-w64\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Programming\cpp\projects\minesweeper\include\ms\board.cpp > CMakeFiles\Board.dir\board.cpp.i

include/ms/CMakeFiles/Board.dir/board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Board.dir/board.cpp.s"
	cd /d D:\Programming\cpp\projects\minesweeper\build\include\ms && C:\mingw-w64\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Programming\cpp\projects\minesweeper\include\ms\board.cpp -o CMakeFiles\Board.dir\board.cpp.s

# Object files for target Board
Board_OBJECTS = \
"CMakeFiles/Board.dir/board.cpp.obj"

# External object files for target Board
Board_EXTERNAL_OBJECTS =

include/ms/libBoard.a: include/ms/CMakeFiles/Board.dir/board.cpp.obj
include/ms/libBoard.a: include/ms/CMakeFiles/Board.dir/build.make
include/ms/libBoard.a: include/ms/CMakeFiles/Board.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Programming\cpp\projects\minesweeper\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libBoard.a"
	cd /d D:\Programming\cpp\projects\minesweeper\build\include\ms && $(CMAKE_COMMAND) -P CMakeFiles\Board.dir\cmake_clean_target.cmake
	cd /d D:\Programming\cpp\projects\minesweeper\build\include\ms && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Board.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
include/ms/CMakeFiles/Board.dir/build: include/ms/libBoard.a

.PHONY : include/ms/CMakeFiles/Board.dir/build

include/ms/CMakeFiles/Board.dir/clean:
	cd /d D:\Programming\cpp\projects\minesweeper\build\include\ms && $(CMAKE_COMMAND) -P CMakeFiles\Board.dir\cmake_clean.cmake
.PHONY : include/ms/CMakeFiles/Board.dir/clean

include/ms/CMakeFiles/Board.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Programming\cpp\projects\minesweeper D:\Programming\cpp\projects\minesweeper\include\ms D:\Programming\cpp\projects\minesweeper\build D:\Programming\cpp\projects\minesweeper\build\include\ms D:\Programming\cpp\projects\minesweeper\build\include\ms\CMakeFiles\Board.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : include/ms/CMakeFiles/Board.dir/depend
