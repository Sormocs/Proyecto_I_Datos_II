#include <SFML/Graphics.hpp>
#include "RemV.h"
#include "LogCons.h"
#pragma once

class GUI {

private:
    GUI();
    static GUI *instance;
    RemV* ramView;
    LogCons* lc;

public:
    static GUI* getInstance();
    void Run();
    RemV* GetRamV();
    LogCons* GetLogCons();

};
