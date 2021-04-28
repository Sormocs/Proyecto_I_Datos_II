#include <iostream>
#include <thread>
#include "Client.h"
#include "GUI.h"

void RunGUI(){
    GUI::getInstance()->Run();
}

void RunClient(){

    Client::getInstance()->Start();
    std::cout << "Client Running" << std::endl;
}

int main(){

    std::thread RunG (RunGUI);
    std::thread RunC (RunClient);

    RunC.join();
    RunG.join();


    return 0;
}
