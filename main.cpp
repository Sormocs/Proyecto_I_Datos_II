#include <iostream>
#include "GUI.h"
#include <thread>

void RunGUI(){
    GUI::getInstance()->Run();
}
int main(){

    std::thread GUI (RunGUI);

    GUI.join();

    return 0;
}