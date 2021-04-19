#include "TextBox.h"
#include "CodeTxT.h"

TextBox::TextBox(int fsize, sf::Color fontColor, bool sel, int Sizex, int Sizey, int Posx, int Posy, sf::Color Bgcolor) {

    fontsize = fsize;
    sizex = Sizex;
    sizey = Sizey;
    posx = Posx;
    posy = Posy;
    selected = sel;
    bgcolor = Bgcolor;
    fontcolor = fontColor;

    indx = posx + 7;
    indy = posy + 10;

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

    sf::RectangleShape ind(sf::Vector2f(7,15));
    ind.setPosition(indx,indy);
    ind.setFillColor(sf::Color::White);

    this->tInd = ind;

    //sf::Font font;
//    font.loadFromFile("../Fonts/consolas.ttf");

//    txtbox.setString(text);
//    txtbox.setFont(font);
//    txtbox.setString("");
//    txtbox.setCharacterSize(fontsize);
//    txtbox.setColor(fontcolor);
//    txtbox.setPosition(posx + 5,posy + 5);
    CodeTxT *lineList = new CodeTxT();
    code = lineList;
    code->SetPosX(posx + 5);
    code->SetPosY(posy + 5);
    code->Insert("");
    current = code->GetStart();
    currLine = current->getLine();
}

void TextBox::Draw(sf::RenderWindow* win) {

    win->draw(box);

    if (selected) {
        tInd.setPosition(indx, indy);
        win->draw(tInd);
    }
    Line *current = code->GetStart();
    while (current != nullptr){
        sf::Text *todraw = current->getVal();
        win->draw(*todraw);
        current = current->getNext();
    }
//    txtbox.setString(text);
//    win->draw(txtbox);
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
    std::string valstr = current->getVal()->getString();
    valstr += character;
    current->SetStr(valstr);
    indx = posx + 14 + current->getVal()->getLocalBounds().width -2;
}

void TextBox::Delete() {

    if (current->getVal()->getString() == "" && current->getPrev() != nullptr ){

        Line *temp = current;
        current = current->getPrev();
        currLine = current->getLine();
        code->Delete(temp);

        indy -= 24;
        indx = posx + 14 + current->getVal()->getLocalBounds().width -2;

    } else if (current->getVal()->getString() != ""){
        std::string text = current->getVal()->getString();
        text.erase(text.end() - 1, text.end());
        current->getVal()->setString(text);
        indx = posx + 14 + current->getVal()->getLocalBounds().width -2;
    }

//    if (text != "") {
//        std::string c = "\n";
//        if (&text[text.length()-1] == c){
//            text.erase(text.end()-1,text.end());
//            txtbox.setString(text);
//            //indy = posy + 12 - txtbox.getLocalBounds().height + 3;
//            indy -= 24;
//            indx = posx + 14 + txtbox.getLocalBounds().width - 3;
//        } else {
//            text.erase(text.end() - 1, text.end());
//            txtbox.setString(text);
//            indx = posx + 14 + txtbox.getLocalBounds().width - 3;
//        }
//    }
}

void TextBox::NewLine() {

    code->SetPosY(code->GetY() + 24);
    code->Insert("");
    current = code->GetEnd();
    currLine = current->getLine();
    indx = posx + 7;
    indy += 24;

//    if (text != ""){
//        text += "\n";
//        //indy = posy + 12 + txtbox.getLocalBounds().height + 3;
//        indy += 24;
//        indx = posx + 10;
//    }
}


