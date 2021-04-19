#include "Button.h"

Button::Button(int Posx, int Posy, int Width, int Height,int Fsize ,std::string Text, sf::Color Color) {

    posx = Posx;
    posy = Posy;
    width = Width;
    height = Height;
    text = Text;
    color = Color;
    fsize = Fsize;

    Build();

}

void Button::Build() {

    sf::RectangleShape figure(sf::Vector2f(width,height));
    figure.setPosition(posx,posy);
    figure.setFillColor(color);
    figure.setOutlineColor(sf::Color(0,0,0));
    figure.setOutlineThickness(3);

    font.loadFromFile("../Fonts/consolas.ttf");
    sText.setString(this->text);
    sText.setCharacterSize(fsize);
    sText.setFont(font);
    sText.setPosition(posx+(width/2-sText.getLocalBounds().width/2),posy+(height/2-sText.getLocalBounds().height/2)-8);
    sText.setFillColor(sf::Color(255,255,255,255));

    this->area = figure;

}

bool Button::Clicked(int x, int y) {
    if (posx < x && x < posx + width && posy < y && y < posy + height){
        return true;

    } else {
        return false;
    }
}

void Button::MouseOver(int x, int y) {
    if (posx < x && x < posx + width && posy < y && y < posy + height){

        area.setOutlineColor(sf::Color(255,255,255,255));

    } else {

        area.setOutlineColor(sf::Color(255,255,255,0));

    }
}

void Button::Draw(sf::RenderWindow *win) {

    win->draw(area);
    win->draw(sText);

}
