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

    sf::Text text;
    text.setPosition(posx+(width/2-text.getLocalBounds().width/2),posy+(height/2-text.getLocalBounds().height/2));

    this->area = figure;

}

bool Button::Clicked(int x, int y) {
    if (posx < x && x < posx + width && posy < y && y < posy + height){
        return true;

    } else {
        return false;
    }
}
