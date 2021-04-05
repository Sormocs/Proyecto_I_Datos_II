#include "TextBox.h"

TextBox::TextBox(int fsize, sf::Color fontcolor, bool sel, int Sizex, int Sizey, int Posx, int Posy, sf::Color Bgcolor) {

    sizex = Sizex;
    sizey = Sizey;
    posx = Posx;
    posy = Posy;
    selected = sel;
    bgcolor = Bgcolor;

    txtbox.setCharacterSize(fsize);
    txtbox.setColor(fontcolor);

    //sf::Font font;
    //if (!font.loadFromFile("../Fonts//arial.ttf")){
        //exit(500);
    //}
    //txtbox.setFont(font);

    sf::RectangleShape box(sf::Vector2f(sizex,sizey));
    box.setPosition(posx,posy);
    box.setFillColor(sf::Color(bgcolor));

    if (sel){
        box.setOutlineColor(sf::Color::White);
        box.setOutlineThickness(4);
    } else{
        box.setOutlineColor(sf::Color(255,255,255,0));
    }

    this->box = box;

    txtbox.setPosition(posx + 5,posy + 5);

}

void TextBox::Draw(sf::RenderWindow* win) {

    txtbox.setString(text);

    win->draw(box);
    win->draw(txtbox);
}

bool TextBox::isSelected() {
    return selected;
}

void TextBox::CheckClick(float x, float y) {
    if (posx < x && x < posx + sizex && posy < y && y < posy + sizey){
        selected = true;
        box.setOutlineColor(sf::Color::White);
        box.setOutlineThickness(4);
        std::cout << "Clicked inside" << std::endl;
    } else{
        selected = false;
        box.setOutlineColor(sf::Color(255,255,255,0));
        std::cout << "Clicked Outside" << std::endl;
    }
}

void TextBox::Write(char val) {
    std::cout << "is in" << std::endl;
    std::string character = std::string(1,val);
    std::cout << "Still good" << std::endl;
    text += character;
    std::cout << text << std::endl;
}