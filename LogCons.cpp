
#include "LogCons.h"

LogCons::LogCons(int Posx, int Posy, int Width, int Height, int Fsize) {

    posx = Posx;
    posy = Posy;
    width = Width;
    height = Height;
    tsize = Fsize;

    Build();

}

void LogCons::Build() {

    sf::RectangleShape tempS(sf::Vector2f(width,height));
    tempS.setPosition(posx,posy);
    tempS.setFillColor(sf::Color(64,64,64,255));

    this->box = tempS;

    font.loadFromFile("../Fonts/comic-sans-ms.ttf");
}

void LogCons::Draw(sf::RenderWindow *win) {

    win->draw(box);

}

