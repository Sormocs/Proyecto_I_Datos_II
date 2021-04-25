#include <SFML/Graphics.hpp>
#include "RemV.h"
#pragma once

class GUI {

private:
    GUI();
    static GUI *instance;
    RemV* ramView;

public:
    static GUI* getInstance();
    void Run();
    void Shapes(sf::RenderWindow*);
    void Texts(sf::RenderWindow*);
    RemV* GetRamV();

};
