/**
 * @file RemV.H
 * @author Sergio MB
 * @brief File que cotiene la clase para el RAM viewer
 */

#include "json.hpp"
#include "SFML/Graphics.hpp"
#include "CodeTxT.h"
using json = nlohmann::json;
#pragma once


/**
 * @brief Clase RemV que funciona para el RAM viewer.
 */
class RemV {
private:

    int posx,posy,width,height;
    bool drawt = false;
    sf::Color color;
    sf::RectangleShape area;
    sf::RectangleShape col1;
    sf::RectangleShape col2;
    sf::RectangleShape col3;
    sf::RectangleShape row1;
    sf::Text rtitles;
    sf::Font font;
    CodeTxT* type;
    CodeTxT* val;
    CodeTxT* addr;
    CodeTxT* refs;
    json j;

public:

    RemV(int, int, int, int, sf::Color);
    void Build();
    void Draw(sf::RenderWindow*);
    void BuildText();
    void SetJson(json js);
    void Reset();
    void SetDrawt(bool flag);

};



