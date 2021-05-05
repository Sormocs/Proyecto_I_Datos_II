#include <iostream>
#include "Server.h"
#include "MemoryManager.h"
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
    codeParser->AddLine("int linea = 123;\n");
    codeParser->AddLine("double fg = 256.478 + linea;\n");
    codeParser->AddLine("struct {\n");
    codeParser->AddLine("int var = 25;\n");
    codeParser->AddLine("char = 'a';\n");
    codeParser->AddLine("} claseA;");
    codeParser->Parse();
    std::cout << MemoryManager::Instance()->GetValOfInt("linea") << std::endl;
    std::cout << MemoryManager::Instance()->GetValOfDouble("fg") << std::endl;
    std::cout << MemoryManager::Instance()->GetValOfStruct("claseA") << std::endl;

}