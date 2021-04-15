#include "TextBox.h"

TextBox::TextBox(int fsize, sf::Color fontColor, bool sel, int Sizex, int Sizey, int Posx, int Posy, sf::Color Bgcolor) {

    fontsize = fsize;
    sizex = Sizex;
    sizey = Sizey;
    posx = Posx;
    posy = Posy;
    selected = sel;
    bgcolor = Bgcolor;
    fontcolor = fontColor;

    Build();

}

void TextBox::Build() {

    sf::RectangleShape box(sf::Vector2f(sizex,sizey));
    box.setPosition(posx,posy);
    box.setFillColor(sf::Color(bgcolor));

    if (selected){
        box.setOutlineColor(sf::Color::White);
        box.setOutlineThickness(4);
    } else{
        box.setOutlineColor(sf::Color(255,255,255,0));
    }

    this->box = box;

    //sf::Font font;
    font.loadFromFile("../Fonts/arial.ttf");

    txtbox.setString(text);
    txtbox.setFont(font);
    txtbox.setString("");
    txtbox.setCharacterSize(fontsize);
    txtbox.setColor(fontcolor);
    txtbox.setPosition(posx + 5,posy + 5);
}

void TextBox::Draw(sf::RenderWindow* win) {

    win->draw(box);

    txtbox.setString(text);
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

    } else{
        selected = false;
        box.setOutlineColor(sf::Color(255,255,255,0));

    }
}

void TextBox::Write(char val) {
    std::string character = std::string(1,val);
    text += character;
    std::cout << text << std::endl;
}

void TextBox::Delete() {
    if (text != "") {
        text.erase(text.end()-1,text.end());
    }
}

void TextBox::NewLine() {
    if (text != ""){
        text += "\n";
    }
}

bool TextBox::isEmpty() {
    if (text == ""){
        return true;
    }
    return false;
}
