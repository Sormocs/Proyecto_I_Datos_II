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
CMAKE_COMMAND = /snap/clion/151/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/151/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Server.dir/flags.make

CMakeFiles/Server.dir/main.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Server.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/main.cpp.o -c /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/main.cpp

CMakeFiles/Server.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/main.cpp > CMakeFiles/Server.dir/main.cpp.i

CMakeFiles/Server.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/main.cpp -o CMakeFiles/Server.dir/main.cpp.s

CMakeFiles/Server.dir/Server.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/Server.cpp.o: ../Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Server.dir/Server.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/Server.cpp.o -c /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/Server.cpp

CMakeFiles/Server.dir/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/Server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/Server.cpp > CMakeFiles/Server.dir/Server.cpp.i

CMakeFiles/Server.dir/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/Server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/Server.cpp -o CMakeFiles/Server.dir/Server.cpp.s

CMakeFiles/Server.dir/MemoryList.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/MemoryList.cpp.o: ../MemoryList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Server.dir/MemoryList.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/MemoryList.cpp.o -c /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/MemoryList.cpp

CMakeFiles/Server.dir/MemoryList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/MemoryList.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/MemoryList.cpp > CMakeFiles/Server.dir/MemoryList.cpp.i

CMakeFiles/Server.dir/MemoryList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/MemoryList.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/MemoryList.cpp -o CMakeFiles/Server.dir/MemoryList.cpp.s

CMakeFiles/Server.dir/MemoryManager.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/MemoryManager.cpp.o: ../MemoryManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Server.dir/MemoryManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/MemoryManager.cpp.o -c /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/MemoryManager.cpp

CMakeFiles/Server.dir/MemoryManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/MemoryManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/MemoryManager.cpp > CMakeFiles/Server.dir/MemoryManager.cpp.i

CMakeFiles/Server.dir/MemoryManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/MemoryManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/MemoryManager.cpp -o CMakeFiles/Server.dir/MemoryManager.cpp.s

CMakeFiles/Server.dir/CodeParser.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/CodeParser.cpp.o: ../CodeParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Server.dir/CodeParser.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/CodeParser.cpp.o -c /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/CodeParser.cpp

CMakeFiles/Server.dir/CodeParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/CodeParser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/CodeParser.cpp > CMakeFiles/Server.dir/CodeParser.cpp.i

CMakeFiles/Server.dir/CodeParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/CodeParser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/CodeParser.cpp -o CMakeFiles/Server.dir/CodeParser.cpp.s

CMakeFiles/Server.dir/TextList.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/TextList.cpp.o: ../TextList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Server.dir/TextList.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/TextList.cpp.o -c /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/TextList.cpp

CMakeFiles/Server.dir/TextList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/TextList.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/TextList.cpp > CMakeFiles/Server.dir/TextList.cpp.i

CMakeFiles/Server.dir/TextList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/TextList.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/TextList.cpp -o CMakeFiles/Server.dir/TextList.cpp.s

CMakeFiles/Server.dir/Sjson.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/Sjson.cpp.o: ../Sjson.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Server.dir/Sjson.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/Sjson.cpp.o -c /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/Sjson.cpp

CMakeFiles/Server.dir/Sjson.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/Sjson.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/Sjson.cpp > CMakeFiles/Server.dir/Sjson.cpp.i

CMakeFiles/Server.dir/Sjson.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/Sjson.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/Sjson.cpp -o CMakeFiles/Server.dir/Sjson.cpp.s

# Object files for target Server
Server_OBJECTS = \
"CMakeFiles/Server.dir/main.cpp.o" \
"CMakeFiles/Server.dir/Server.cpp.o" \
"CMakeFiles/Server.dir/MemoryList.cpp.o" \
"CMakeFiles/Server.dir/MemoryManager.cpp.o" \
"CMakeFiles/Server.dir/CodeParser.cpp.o" \
"CMakeFiles/Server.dir/TextList.cpp.o" \
"CMakeFiles/Server.dir/Sjson.cpp.o"

# External object files for target Server
Server_EXTERNAL_OBJECTS =

Server: CMakeFiles/Server.dir/main.cpp.o
Server: CMakeFiles/Server.dir/Server.cpp.o
Server: CMakeFiles/Server.dir/MemoryList.cpp.o
Server: CMakeFiles/Server.dir/MemoryManager.cpp.o
Server: CMakeFiles/Server.dir/CodeParser.cpp.o
Server: CMakeFiles/Server.dir/TextList.cpp.o
Server: CMakeFiles/Server.dir/Sjson.cpp.o
Server: CMakeFiles/Server.dir/build.make
Server: CMakeFiles/Server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Server.dir/build: Server

.PHONY : CMakeFiles/Server.dir/build

CMakeFiles/Server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Server.dir/clean

CMakeFiles/Server.dir/depend:
	cd /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/cmake-build-debug /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/cmake-build-debug /home/sormocs/CLionProjects/Proyecto_I_Datos_II/Server/cmake-build-debug/CMakeFiles/Server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Server.dir/depend

