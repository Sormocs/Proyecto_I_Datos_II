/**
 * @file GUI.h
 * @author Sergio MB
 * @brief Declaracion de GUI con sus metodos y atributos.
 */

#include <SFML/Graphics.hpp>
#include "RemV.h"
#include "LogCons.h"
#include "TextBox.h"
#include "Button.h"
#pragma once

/**
 * @brief Clase GUI que se encarga de conectar los mensajes recibidos del cliente con el resto del programa, funcionando como
 * una especie de Facade para el cliente y el resto de procesos en el server.
 */
class GUI {

private:
    GUI();
    static GUI *instance;
    RemV* ramView;
    LogCons* lc;
    bool isRunning = false;
    TextBox* codeA;
    Button* next;
    Button* stop;
    Button* clearlog;
    Button* runBtn;

public:
    static GUI* getInstance();
    void Run();
    RemV* GetRamV();
    LogCons* GetLogCons();
    void Stop();

};
