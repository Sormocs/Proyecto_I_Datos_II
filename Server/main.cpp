#include <iostream>
#include "Server.h"
#include "MemoryManager.h"
#include <thread>
#include "CodeParser.h"
#include "Sjson.h"

void RunServer(){

    std::cout << "Server Running" << std::endl;
    Server::getInstance()->Start();

}

void MemoryTests();

int main() {

    //MemoryTests();

    std::thread RunS (RunServer);

    //JsonTest();

    RunS.join();

    return 0;
}

void MemoryTests(){
    CodeParser* codeParser = CodeParser::Instance();
    codeParser->CheckLine("int linea = 123;");
    std::cout << MemoryManager::Instance()->GetValOfInt("linea") << std::endl;
    codeParser->CheckLine("double fg = 256.478;");
    std::cout << MemoryManager::Instance()->GetValOfDouble("fg") << std::endl;

}