/**
 * @file main.cpp
 * @brief Archivo main el cual ejectuta el codigo inicial y los threads.
 */

#include <iostream>
#include <thread>
#include "Client.h"
#include "GUI.h"

/**
 * @brief Funcion que inicia el thread del GUI.
 */
void RunGUI(){
    GUI::getInstance()->Run();
}

/**
 * @brief Funcion que se encarga de iniciar el thread del cliente para que se conecte al server.
 */
void RunClient(){

    Client::getInstance()->Start();
    std::cout << "Client Running" << std::endl;
}

/**
 * @brief Funcion main que corre el programa.
 * @return
 */
int main(){

    std::thread RunG (RunGUI);
    std::thread RunC (RunClient);

    RunC.join();
    RunG.join();


    return 0;
}
