#include <iostream>
#include "GUI.h"
#include <thread>
#include <SFML/Graphics.hpp>

void RunGUI(){
    GUI::getInstance()->Run();
}
int main(){

    std::thread GUI (RunGUI);

    GUI.join();

    return 0;
}

