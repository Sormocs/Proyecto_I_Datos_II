/**
 * @file LogCons.h
 * @author Sergio MB
 * @brief LogCons es la  clase que contiene el log y la consola.
 */

#include "SFML/Graphics.hpp"
#include "CodeTxT.h"
#include <iostream>
#pragma once

/**
 * @brief Declaracion de la clase LogCons que funciona como Consola y Log.
 */
class LogCons {
private:
    int posx, posy, width, height;
    sf::RectangleShape box;
    sf::RectangleShape l;
    sf::Text sftitle;
    CodeTxT *logTxT;
    CodeTxT *consTxT;
    CodeTxT *current;
    std::string log;
    std::string cons;
    std::string title;
    sf::Color boxcol;
    sf::Color txtCol;
    sf::Font font;
    bool isCons, isLimit = false;

public:
    LogCons(int, int, int, int);
    void Build();
    void Draw(sf::RenderWindow*);
    void Switch();
    void AddCons(std::string);
    void AddLog(std::string);
    void Reset();
    bool IsCons();
    bool IsLimit();
    CodeTxT* GetCurrent();
};
