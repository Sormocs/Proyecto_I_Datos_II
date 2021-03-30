#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
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

    return 0;
}