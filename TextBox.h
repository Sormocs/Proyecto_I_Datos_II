#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "CodeTxT.h"
#pragma once

class TextBox {
private:
    int sizey, sizex, posy, posx, fontsize, indx, indy, currLine, xlimit, ylimit;
    sf::Color bgcolor, fontcolor;
    bool selected = false;
    sf::RectangleShape box;
    sf::RectangleShape tInd;
    CodeTxT *code;
    Line *current;

    sf::Font font;

public:
    TextBox(int, sf::Color, bool, int, int, int, int, sf::Color);
    void Build();
    void CheckClick(float ,float);
    void Draw(sf::RenderWindow*);
    bool isSelected();
    void Write(char);
    void Delete();
    void NewLine();
    Line* GetCurrent();
    CodeTxT* GetCode();
};
