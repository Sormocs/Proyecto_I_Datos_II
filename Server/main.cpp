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

    MemoryTests();

    //std::thread RunS (RunServer);

    //JsonTest();

    //RunS.join();

    return 0;
}

void MemoryTests(){
    CodeParser* codeParser = CodeParser::Instance();
    codeParser->AddLine("int linea = 123;");
    codeParser->AddLine("double fg = 256.478 + linea;");
    codeParser->AddLine("struct {");
    codeParser->AddLine("int var = 25;");
    codeParser->AddLine("char = 'a';");
    codeParser->AddLine("} claseA;");
    std::cout << MemoryManager::Instance()->GetValOfInt("linea") << std::endl;
    std::cout << MemoryManager::Instance()->GetValOfDouble("fg") << std::endl;
    std::cout << MemoryManager::Instance()->GetValOfStruct("claseA") << std::endl;

}