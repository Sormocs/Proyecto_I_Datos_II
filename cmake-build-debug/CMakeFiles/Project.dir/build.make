# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/tiquillo/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.7717.62/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/tiquillo/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.7717.62/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tiquillo/CLionProjects/Proyecto_I_Datos_II

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tiquillo/CLionProjects/Proyecto_I_Datos_II/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project.dir/flags.make

CMakeFiles/Project.dir/main.cpp.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiquillo/CLionProjects/Proyecto_I_Datos_II/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project.dir/main.cpp.o -c /home/tiquillo/CLionProjects/Proyecto_I_Datos_II/main.cpp

CMakeFiles/Project.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiquillo/CLionProjects/Proyecto_I_Datos_II/main.cpp > CMakeFiles/Project.dir/main.cpp.i

CMakeFiles/Project.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiquillo/CLionProjects/Proyecto_I_Datos_II/main.cpp -o CMakeFiles/Project.dir/main.cpp.s

CMakeFiles/Project.dir/Button.cpp.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/Button.cpp.o: ../Button.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiquillo/CLionProjects/Proyecto_I_Datos_II/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Project.dir/Button.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project.dir/Button.cpp.o -c /home/tiquillo/CLionProjects/Proyecto_I_Datos_II/Button.cpp

CMakeFiles/Project.dir/Button.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/Button.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiquillo/CLionProjects/Proyecto_I_Datos_II/Button.cpp > CMakeFiles/Project.dir/Button.cpp.i

CMakeFiles/Project.dir/Button.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/Button.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiquillo/CLionProjects/Proyecto_I_Datos_II/Button.cpp -o CMakeFiles/Project.dir/Button.cpp.s

CMakeFiles/Project.dir/CodeParser.cpp.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/CodeParser.cpp.o: ../CodeParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiquillo/CLionProjects/Proyecto_I_Datos_II/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Project.dir/CodeParser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project.dir/CodeParser.cpp.o -c /home/tiquillo/CLionProjects/Proyecto_I_Datos_II/CodeParser.cpp

CMakeFiles/Project.dir/CodeParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/CodeParser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiquillo/CLionProjects/Proyecto_I_Datos_II/CodeParser.cpp > CMakeFiles/Project.dir/CodeParser.cpp.i

CMakeFiles/Project.dir/CodeParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/CodeParser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiquillo/CLionProjects/Proyecto_I_Datos_II/CodeParser.cpp -o CMakeFiles/Project.dir/CodeParser.cpp.s

CMakeFiles/Project.dir/MemoryManager.cpp.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/MemoryManager.cpp.o: ../MemoryManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiquillo/CLionProjects/Proyecto_I_Datos_II/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Project.dir/MemoryManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project.dir/MemoryManager.cpp.o -c /home/tiquillo/CLionProjects/Proyecto_I_Datos_II/MemoryManager.cpp

CMakeFiles/Project.dir/MemoryManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/MemoryManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiquillo/CLionProjects/Proyecto_I_Datos_II/MemoryManager.cpp > CMakeFiles/Project.dir/MemoryManager.cpp.i

CMakeFiles/Project.dir/MemoryManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/MemoryManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiquillo/CLionProjects/Proyecto_I_Datos_II/MemoryManager.cpp -o CMakeFiles/Project.dir/MemoryManager.cpp.s

CMakeFiles/Project.dir/MemoryList.cpp.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/MemoryList.cpp.o: ../MemoryList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiquillo/CLionProjects/Proyecto_I_Datos_II/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Project.dir/MemoryList.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project.dir/MemoryList.cpp.o -c /home/tiquillo/CLionProjects/Proyecto_I_Datos_II/MemoryList.cpp

CMakeFiles/Project.dir/MemoryList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/MemoryList.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiquillo/CLionProjects/Proyecto_I_Datos_II/MemoryList.cpp > CMakeFiles/Project.dir/MemoryList.cpp.i

CMakeFiles/Project.dir/MemoryList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/MemoryList.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiquillo/CLionProjects/Proyecto_I_Datos_II/MemoryList.cpp -o CMakeFiles/Project.dir/MemoryList.cpp.s

# Object files for target Project
Project_OBJECTS = \
"CMakeFiles/Project.dir/main.cpp.o" \
"CMakeFiles/Project.dir/Button.cpp.o" \
"CMakeFiles/Project.dir/CodeParser.cpp.o" \
"CMakeFiles/Project.dir/MemoryManager.cpp.o" \
"CMakeFiles/Project.dir/MemoryList.cpp.o"

# External object files for target Project
Project_EXTERNAL_OBJECTS =

Project: CMakeFiles/Project.dir/main.cpp.o
Project: CMakeFiles/Project.dir/Button.cpp.o
Project: CMakeFiles/Project.dir/CodeParser.cpp.o
Project: CMakeFiles/Project.dir/MemoryManager.cpp.o
Project: CMakeFiles/Project.dir/MemoryList.cpp.o
Project: CMakeFiles/Project.dir/build.make
Project: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
Project: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
Project: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
Project: CMakeFiles/Project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tiquillo/CLionProjects/Proyecto_I_Datos_II/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project.dir/build: Project

.PHONY : CMakeFiles/Project.dir/build

CMakeFiles/Project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Project.dir/clean

CMakeFiles/Project.dir/depend:
	cd /home/tiquillo/CLionProjects/Proyecto_I_Datos_II/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tiquillo/CLionProjects/Proyecto_I_Datos_II /home/tiquillo/CLionProjects/Proyecto_I_Datos_II /home/tiquillo/CLionProjects/Proyecto_I_Datos_II/cmake-build-debug /home/tiquillo/CLionProjects/Proyecto_I_Datos_II/cmake-build-debug /home/tiquillo/CLionProjects/Proyecto_I_Datos_II/cmake-build-debug/CMakeFiles/Project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Project.dir/depend

