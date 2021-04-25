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

using namespace std::literals::chrono_literals;

void JsonTest(){

    Sjson vars = Sjson();
    vars.AddVar("int","20","S35WS334","2");
    vars.AddVar("double","20.456","A35W67U4","1");
    json obj = vars.GetObj();
    std::string sobj = obj.dump();
    std::cout << sobj << std::endl;
    std::cout << obj["var0"]["value"] << std::endl;
    json reobj = json::parse(sobj);
    std::cout << reobj["var0"]["value"] << std::endl;
    std::cout << obj.size() << std::endl;

    std::this_thread::sleep_for(10s);
    Server::getInstance()->Send("WAIT 5 MORE");
    std::this_thread::sleep_for(5s);
    std::string tosend = "JSON"+sobj;
    Server::getInstance()->Send(tosend);

}

int main() {

    //MemoryTests();

    std::thread RunS (RunServer);

    //JsonTest();

    RunS.join();

    return 0;
}

void MemoryTests(){
    CodeParser* codeParser = CodeParser::Instance();
    codeParser->Declaration("int linea = 123;");
    std::cout << MemoryManager::Instance()->GetValOfInt("linea") << std::endl;
    codeParser->Declaration("double fg = 256.478;");
    std::cout << MemoryManager::Instance()->GetValOfDouble("fg") << std::endl;

}