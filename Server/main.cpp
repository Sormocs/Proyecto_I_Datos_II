#include <iostream>
#include "Server.h"
#include "MemoryManager.h"
#include <thread>
#include "CodeParser.h"

void RunServer(){

    Server::getInstance()->Start();
    std::cout << "Server Running" << std::endl;

}

void MemoryTests();

void ParseTest();

int main() {

    ParseTest();

//    std::thread RunS (RunServer);

//    RunS.join();

    return 0;
}

void ParseTest(){
    CodeParser codeParser = CodeParser();

    std::string buenas = "int patricio = 78;";

    codeParser.Declaration(buenas);

    int data = *(int*)MemoryManager::Instance()->GetValOf("patricio");

    std::cout << data << std::endl;

}

void MemoryTests(){
    auto manager = MemoryManager();
}