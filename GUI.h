#include <SFML/Graphics.hpp>
#pragma once

class GUI {

private:
    GUI();
    static GUI *instance;
    std::string lnumstr = "1";

public:
    static GUI* getInstance();
    void Run();
    void Shapes(sf::RenderWindow*);
    void Texts(sf::RenderWindow*);

};
