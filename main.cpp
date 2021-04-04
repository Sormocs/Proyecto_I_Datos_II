#include <iostream>
#include <SFML/Graphics.hpp>

#include "CodeParser.h"

void ParserTest();
void Screen();

int main()
{

    //Screen();
    ParserTest();

    return 0;
}

void ParserTest() {
    CodeParser* codeParser = new CodeParser();
    int signPos = NOT_IN_STRING;
    int plusPos = NOT_IN_STRING;
    int minusPos = NOT_IN_STRING;
    std::string ajua = "15 - 12;";

    //codeParser->DelAddSubSign(ajua, minusPos, plusPos, signPos);

    //std::cout << "Minus: " << minusPos << " Plus: " << plusPos << " Sign: " << signPos << " string " << ajua << std::endl;
    //std::cout << ajua.substr(3,-1) << std::endl;
    //std::cout << codeParser->ExtractNumber(" 12 ") << std::endl;
    //std::cout << codeParser->AddSubtract(" 2 + 2") << std::endl;
    std::cout << codeParser->Multiply(" 2 * 2") << std::endl;
}

void Screen(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "Algo :v",sf::Style::Close);
    sf::RectangleShape shape(sf::Vector2f(120.f,50.f));
    shape.setPosition(300,100);
    shape.setFillColor(sf::Color::Red);
    float mouse[2] = {};

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonReleased){
                mouse[0] = sf::Mouse::getPosition(window).x;
                mouse[1] = sf::Mouse::getPosition(window).y;

            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}