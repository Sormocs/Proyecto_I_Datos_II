cmake_minimum_required(VERSION 3.17)
project(ProjectV2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-pthread")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

add_executable(ProjectV2 main.cpp TextBox.cpp TextBox.h GUI.cpp GUI.h Client.cpp Client.h Button.cpp Button.h Json.cpp Json.h CodeTxT.cpp CodeTxT.h)
target_link_libraries(ProjectV2 sfml-graphics sfml-window sfml-system)
