# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /snap/clion/149/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/149/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sormocs04/CLionProjects/Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sormocs04/CLionProjects/Project/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ProjectV2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ProjectV2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProjectV2.dir/flags.make

CMakeFiles/ProjectV2.dir/main.cpp.o: CMakeFiles/ProjectV2.dir/flags.make
CMakeFiles/ProjectV2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sormocs04/CLionProjects/Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ProjectV2.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProjectV2.dir/main.cpp.o -c /home/sormocs04/CLionProjects/Project/main.cpp

CMakeFiles/ProjectV2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjectV2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sormocs04/CLionProjects/Project/main.cpp > CMakeFiles/ProjectV2.dir/main.cpp.i

CMakeFiles/ProjectV2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjectV2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sormocs04/CLionProjects/Project/main.cpp -o CMakeFiles/ProjectV2.dir/main.cpp.s

CMakeFiles/ProjectV2.dir/TextBox.cpp.o: CMakeFiles/ProjectV2.dir/flags.make
CMakeFiles/ProjectV2.dir/TextBox.cpp.o: ../TextBox.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sormocs04/CLionProjects/Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ProjectV2.dir/TextBox.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProjectV2.dir/TextBox.cpp.o -c /home/sormocs04/CLionProjects/Project/TextBox.cpp

CMakeFiles/ProjectV2.dir/TextBox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjectV2.dir/TextBox.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sormocs04/CLionProjects/Project/TextBox.cpp > CMakeFiles/ProjectV2.dir/TextBox.cpp.i

CMakeFiles/ProjectV2.dir/TextBox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjectV2.dir/TextBox.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sormocs04/CLionProjects/Project/TextBox.cpp -o CMakeFiles/ProjectV2.dir/TextBox.cpp.s

CMakeFiles/ProjectV2.dir/GUI.cpp.o: CMakeFiles/ProjectV2.dir/flags.make
CMakeFiles/ProjectV2.dir/GUI.cpp.o: ../GUI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sormocs04/CLionProjects/Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ProjectV2.dir/GUI.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProjectV2.dir/GUI.cpp.o -c /home/sormocs04/CLionProjects/Project/GUI.cpp

CMakeFiles/ProjectV2.dir/GUI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjectV2.dir/GUI.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sormocs04/CLionProjects/Project/GUI.cpp > CMakeFiles/ProjectV2.dir/GUI.cpp.i

CMakeFiles/ProjectV2.dir/GUI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjectV2.dir/GUI.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sormocs04/CLionProjects/Project/GUI.cpp -o CMakeFiles/ProjectV2.dir/GUI.cpp.s

CMakeFiles/ProjectV2.dir/CodeParser.cpp.o: CMakeFiles/ProjectV2.dir/flags.make
CMakeFiles/ProjectV2.dir/CodeParser.cpp.o: ../CodeParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sormocs04/CLionProjects/Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ProjectV2.dir/CodeParser.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProjectV2.dir/CodeParser.cpp.o -c /home/sormocs04/CLionProjects/Project/CodeParser.cpp

CMakeFiles/ProjectV2.dir/CodeParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjectV2.dir/CodeParser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sormocs04/CLionProjects/Project/CodeParser.cpp > CMakeFiles/ProjectV2.dir/CodeParser.cpp.i

CMakeFiles/ProjectV2.dir/CodeParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjectV2.dir/CodeParser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sormocs04/CLionProjects/Project/CodeParser.cpp -o CMakeFiles/ProjectV2.dir/CodeParser.cpp.s

CMakeFiles/ProjectV2.dir/Client.cpp.o: CMakeFiles/ProjectV2.dir/flags.make
CMakeFiles/ProjectV2.dir/Client.cpp.o: ../Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sormocs04/CLionProjects/Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ProjectV2.dir/Client.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProjectV2.dir/Client.cpp.o -c /home/sormocs04/CLionProjects/Project/Client.cpp

CMakeFiles/ProjectV2.dir/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjectV2.dir/Client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sormocs04/CLionProjects/Project/Client.cpp > CMakeFiles/ProjectV2.dir/Client.cpp.i

CMakeFiles/ProjectV2.dir/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjectV2.dir/Client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sormocs04/CLionProjects/Project/Client.cpp -o CMakeFiles/ProjectV2.dir/Client.cpp.s

CMakeFiles/ProjectV2.dir/Button.cpp.o: CMakeFiles/ProjectV2.dir/flags.make
CMakeFiles/ProjectV2.dir/Button.cpp.o: ../Button.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sormocs04/CLionProjects/Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ProjectV2.dir/Button.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProjectV2.dir/Button.cpp.o -c /home/sormocs04/CLionProjects/Project/Button.cpp

CMakeFiles/ProjectV2.dir/Button.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjectV2.dir/Button.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sormocs04/CLionProjects/Project/Button.cpp > CMakeFiles/ProjectV2.dir/Button.cpp.i

CMakeFiles/ProjectV2.dir/Button.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjectV2.dir/Button.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sormocs04/CLionProjects/Project/Button.cpp -o CMakeFiles/ProjectV2.dir/Button.cpp.s

CMakeFiles/ProjectV2.dir/Json.cpp.o: CMakeFiles/ProjectV2.dir/flags.make
CMakeFiles/ProjectV2.dir/Json.cpp.o: ../Json.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sormocs04/CLionProjects/Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ProjectV2.dir/Json.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProjectV2.dir/Json.cpp.o -c /home/sormocs04/CLionProjects/Project/Json.cpp

CMakeFiles/ProjectV2.dir/Json.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjectV2.dir/Json.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sormocs04/CLionProjects/Project/Json.cpp > CMakeFiles/ProjectV2.dir/Json.cpp.i

CMakeFiles/ProjectV2.dir/Json.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjectV2.dir/Json.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sormocs04/CLionProjects/Project/Json.cpp -o CMakeFiles/ProjectV2.dir/Json.cpp.s

CMakeFiles/ProjectV2.dir/CodeTxT.cpp.o: CMakeFiles/ProjectV2.dir/flags.make
CMakeFiles/ProjectV2.dir/CodeTxT.cpp.o: ../CodeTxT.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sormocs04/CLionProjects/Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ProjectV2.dir/CodeTxT.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProjectV2.dir/CodeTxT.cpp.o -c /home/sormocs04/CLionProjects/Project/CodeTxT.cpp

CMakeFiles/ProjectV2.dir/CodeTxT.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjectV2.dir/CodeTxT.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sormocs04/CLionProjects/Project/CodeTxT.cpp > CMakeFiles/ProjectV2.dir/CodeTxT.cpp.i

CMakeFiles/ProjectV2.dir/CodeTxT.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjectV2.dir/CodeTxT.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sormocs04/CLionProjects/Project/CodeTxT.cpp -o CMakeFiles/ProjectV2.dir/CodeTxT.cpp.s

CMakeFiles/ProjectV2.dir/LogCons.cpp.o: CMakeFiles/ProjectV2.dir/flags.make
CMakeFiles/ProjectV2.dir/LogCons.cpp.o: ../LogCons.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sormocs04/CLionProjects/Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/ProjectV2.dir/LogCons.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProjectV2.dir/LogCons.cpp.o -c /home/sormocs04/CLionProjects/Project/LogCons.cpp

CMakeFiles/ProjectV2.dir/LogCons.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjectV2.dir/LogCons.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sormocs04/CLionProjects/Project/LogCons.cpp > CMakeFiles/ProjectV2.dir/LogCons.cpp.i

CMakeFiles/ProjectV2.dir/LogCons.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjectV2.dir/LogCons.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sormocs04/CLionProjects/Project/LogCons.cpp -o CMakeFiles/ProjectV2.dir/LogCons.cpp.s

# Object files for target ProjectV2
ProjectV2_OBJECTS = \
"CMakeFiles/ProjectV2.dir/main.cpp.o" \
"CMakeFiles/ProjectV2.dir/TextBox.cpp.o" \
"CMakeFiles/ProjectV2.dir/GUI.cpp.o" \
"CMakeFiles/ProjectV2.dir/CodeParser.cpp.o" \
"CMakeFiles/ProjectV2.dir/Client.cpp.o" \
"CMakeFiles/ProjectV2.dir/Button.cpp.o" \
"CMakeFiles/ProjectV2.dir/Json.cpp.o" \
"CMakeFiles/ProjectV2.dir/CodeTxT.cpp.o" \
"CMakeFiles/ProjectV2.dir/LogCons.cpp.o"

# External object files for target ProjectV2
ProjectV2_EXTERNAL_OBJECTS =

ProjectV2: CMakeFiles/ProjectV2.dir/main.cpp.o
ProjectV2: CMakeFiles/ProjectV2.dir/TextBox.cpp.o
ProjectV2: CMakeFiles/ProjectV2.dir/GUI.cpp.o
ProjectV2: CMakeFiles/ProjectV2.dir/CodeParser.cpp.o
ProjectV2: CMakeFiles/ProjectV2.dir/Client.cpp.o
ProjectV2: CMakeFiles/ProjectV2.dir/Button.cpp.o
ProjectV2: CMakeFiles/ProjectV2.dir/Json.cpp.o
ProjectV2: CMakeFiles/ProjectV2.dir/CodeTxT.cpp.o
ProjectV2: CMakeFiles/ProjectV2.dir/LogCons.cpp.o
ProjectV2: CMakeFiles/ProjectV2.dir/build.make
ProjectV2: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
ProjectV2: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
ProjectV2: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
ProjectV2: CMakeFiles/ProjectV2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sormocs04/CLionProjects/Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable ProjectV2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ProjectV2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProjectV2.dir/build: ProjectV2

.PHONY : CMakeFiles/ProjectV2.dir/build

CMakeFiles/ProjectV2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ProjectV2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ProjectV2.dir/clean

CMakeFiles/ProjectV2.dir/depend:
	cd /home/sormocs04/CLionProjects/Project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sormocs04/CLionProjects/Project /home/sormocs04/CLionProjects/Project /home/sormocs04/CLionProjects/Project/cmake-build-debug /home/sormocs04/CLionProjects/Project/cmake-build-debug /home/sormocs04/CLionProjects/Project/cmake-build-debug/CMakeFiles/ProjectV2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ProjectV2.dir/depend

