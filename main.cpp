#include <iostream>
#include "GUI.h"
#include <thread>
#include "Client.h"
#include "Server/CodeParser.h"

void TestParser(){
    CodeParser codeParser = CodeParser();
    std::string ejemplo = "int entero = 25;";
//    std::cout << codeParser.ContainsStr(ejemplo, "entero");
}

void RunGUI(){
    GUI::getInstance()->Run();
}

void RunClient(){

    Client::getInstance()->Start();
    std::cout << "Client Running" << std::endl;
}

int main(){

//    std::thread GUI (RunGUI);
//    //std::thread RunC (RunClient);
//
//    //RunC.join();
//    GUI.join();

    TestParser();

    return 0;
}
