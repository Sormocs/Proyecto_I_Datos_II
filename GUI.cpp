#include "GUI.h"

GUI *GUI::instance = nullptr;

GUI::GUI() {}

GUI* GUI::getInstance() {
    if (instance == nullptr){
        instance = new GUI;
    }
    return instance;
}

void GUI::Run() {
    sf::RenderWindow window(sf::VideoMode(1700, 800), "C! IDE",sf::Style::Close);
    float mouse[2] = {};
    sf::RenderWindow* winptr = &window;

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
        Shapes(winptr);
        window.display();
    }
}

void GUI::Shapes(sf::RenderWindow* ptr) {
    sf::RectangleShape rect1(sf::Vector2f(1700.f,60.f));
    rect1.setPosition(0,0);
    rect1.setFillColor(sf::Color::Cyan);
    ptr->draw(rect1);
}

