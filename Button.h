#include <SFML/Graphics.hpp>
#include <iostream>
#pragma once

class Button {
private:
    sf::String text;

public:
    Button(sf::String txt);
    void Draw(sf::Window win);

};



