#include <SFML/Graphics.hpp>
#pragma once


class Button {

private:

    int posx, posy, width, height, fsize;
    sf::Color bgcolor;
    std::string text = "";
    sf::Text sText;
    sf::Font font;
    sf::RectangleShape area;
    sf::Color color;

public:

    Button(int, int, int, int, int, std::string, sf::Color);
    void Build();
    bool Clicked(int, int);
    int getPosx();
    int getPosy();
    void MouseOver(int, int);
    void Draw(sf::RenderWindow*);


};



