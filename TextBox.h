#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#pragma once
#define DELETE_KEY 8;
#define ESCAPE_KEY 27;

class TextBox {
private:
    int sizey, sizex, posy, posx, fontsize;
    sf::Text txtbox;
    sf::Color bgcolor, fontcolor;
    bool selected = false;
    bool reachlimit = false;
    int limit;
    std::string text = "";
    sf::RectangleShape box;

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
    bool isEmpty();
};



