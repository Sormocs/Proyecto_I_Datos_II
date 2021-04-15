#include <iostream>
#include "Server.h"
#include <thread>

void RunServer(){

    Server::getInstance()->Start();
    std::cout << "Server Running" << std::endl;

}

int main() {

    std::thread RunS (RunServer);

    RunS.join();

    return 0;
}
