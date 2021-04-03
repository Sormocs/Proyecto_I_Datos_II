cmake_minimum_required(VERSION 3.17)
project(Project)

set(CMAKE_CXX_STANDARD 14)


link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

include_directories (${GTK2_INCLUDE_DIRS})
link_directories (${GTK2_LIBRARY_DIRS})


add_executable(Project main.cpp Button.cpp Button.h GUI.cpp GUI.h)
target_link_libraries(Project sfml-graphics sfml-window sfml-system)

target_link_libraries(Project ${GTK2_LIBRARIES})