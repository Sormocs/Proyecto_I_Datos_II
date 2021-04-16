#include <iostream>
#include "Server.h"
#include "MemoryManager.h"
#include <thread>

void RunServer(){

    Server::getInstance()->Start();
    std::cout << "Server Running" << std::endl;

}

void MemoryTests();

int main() {

    MemoryTests();

//    std::thread RunS (RunServer);

//    RunS.join();

    return 0;
}

void MemoryTests(){
    auto manager = MemoryManager();
}