#include <iostream>
#include "GUI.h"
#include <thread>
#include "Client.h"


void RunGUI(){
    GUI::getInstance()->Run();
}

void RunClient(){

    Client::getInstance()->Start();
    std::cout << "Client Running" << std::endl;
}

int main(){

    std::thread GUI (RunGUI);
    //std::thread RunC (RunClient);

    //RunC.join();
    GUI.join();


    return 0;
}
