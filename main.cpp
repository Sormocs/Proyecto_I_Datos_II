#include <iostream>
#include "GUI.h"
#include <thread>
#include <SFML/Graphics.hpp>
#include "CodeParser.h"

void RunGUI(){
    GUI::getInstance()->Run();
}
int main(){

    std::thread GUI (RunGUI);

    GUI.join();

    return 0;
}

