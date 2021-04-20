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

    std::string buenas = "char patricio = 'a';";

    codeParser.Declaration(buenas);

    char data = *(char*)MemoryManager::Instance()->GetValOf("patricio");

    std::cout << data << " " << std::endl;
    //printf("Tamaño de Node: %lu\n", sizeof(void*));


}

void MemoryTests(){
    auto manager = MemoryManager();
}