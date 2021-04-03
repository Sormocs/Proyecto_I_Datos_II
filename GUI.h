#include <SFML/Graphics.hpp>
#pragma once

class GUI {

private:
    GUI();
    static GUI *instance;

public:
    static GUI* getInstance();
    void Run();
    void Shapes(sf::RenderWindow*);

};

