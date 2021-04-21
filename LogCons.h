#include "SFML/Graphics.hpp"
#include <iostream>
#pragma once

class LogCons {
private:
    int posx, posy, width, height, tsize;
    sf::RectangleShape box;
    sf::Text logTxt;
    sf::Text consTxt;
    std::string log;
    std::string cons;
    sf::Color boxcol;
    sf::Color txtCol;
    sf::Font font;
    bool isLog;
    bool isCons;

public:
    LogCons(int, int, int, int ,int);
    void Build();
    void Draw(sf::RenderWindow*);
};
