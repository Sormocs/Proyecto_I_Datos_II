cmake_minimum_required(VERSION 3.17)
project(Server)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-pthread")

add_executable(Server main.cpp Server.cpp Server.h MemoryList.cpp MemoryList.h MemoryManager.cpp MemoryManager.h CodeParser.h CodeParser.cpp)