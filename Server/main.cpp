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

int main() {

    MemoryTests();

//    std::thread RunS (RunServer);
//
//    RunS.join();

    return 0;
}

void MemoryTests(){
    CodeParser codeParser = CodeParser();
    codeParser.Declaration("int linea = 123;");
    std::cout << *(int*)MemoryManager::Instance()->GetValOf("linea") << std::endl;
    codeParser.Declaration("double Luis = 256.478;");
    std::cout << *(double*)MemoryManager::Instance()->GetValOf("Luis") << std::endl;
}