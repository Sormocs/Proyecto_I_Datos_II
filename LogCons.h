#include "SFML/Graphics.hpp"
#include "CodeTxT.h"
#include <iostream>
#pragma once

class LogCons {
private:
    int posx, posy, width, height;
    sf::RectangleShape box;
    sf::RectangleShape l;
    sf::Text sftitle;
//    sf::Text logTxt;
//    sf::Text consTxt;
    CodeTxT *logTxT;
    CodeTxT *consTxT;
    CodeTxT *current;
    std::string log;
    std::string cons;
    std::string title;
    sf::Color boxcol;
    sf::Color txtCol;
    sf::Font font;
    bool isCons;

public:
    LogCons(int, int, int, int);
    void Build();
    void Draw(sf::RenderWindow*);
    void Switch();
    void AddCons();
    void AddLog();
};
