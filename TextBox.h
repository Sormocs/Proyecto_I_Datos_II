/**
 * @file TextBox.h
 * @author Sergio MB
 * @brief Declaracion de la clase TextBox, que corresponde al area donde se introduce el codigo
 */

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "CodeTxT.h"
#pragma once

/**
 * @brief Clase text box, la cual crea un area que permite introducir texto y guarda cada linea como un elemento de una lista.
 */
class TextBox {
private:
    int sizey, sizex, posy, posx, fontsize, indx, indy, currLine, xlimit, ylimit;
    sf::Color bgcolor, fontcolor;
    bool selected = false;
    sf::RectangleShape box;
    sf::RectangleShape tInd;
    CodeTxT *code;
    CodeTxT *lineC;
    Line *current;

    sf::Font font;

public:
    TextBox(int, sf::Color, bool, int, int, int, int, sf::Color);
    void Build();
    void CheckClick(float ,float);
    void Draw(sf::RenderWindow*);
    void DrawLines(sf::RenderWindow*);
    bool isSelected();
    void Write(char);
    void Delete();
    void NewLine();
    Line* GetCurrent();
    CodeTxT* GetCode();
};
