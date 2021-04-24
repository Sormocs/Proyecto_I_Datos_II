
#include "LogCons.h"

LogCons::LogCons(int Posx, int Posy, int Width, int Height) {

    posx = Posx;
    posy = Posy;
    width = Width;
    height = Height;
    isCons = false;
    title = "Log";

    Build();

}

void LogCons::Build() {

    sf::RectangleShape tempS(sf::Vector2f(width,height));
    tempS.setPosition(posx,posy);
    tempS.setFillColor(sf::Color(64,64,64,255));

    this->box = tempS;

    sf::RectangleShape tempL(sf::Vector2f(1550,5));
    tempL.setPosition(0,posy + 34);
    tempL.setFillColor(sf::Color(230,230,230,255));

    l = tempL;

    font.loadFromFile("../Fonts/comic-sans-ms.ttf");

    sftitle.setFont(font);
    sftitle.setCharacterSize(22);
    sftitle.setColor(sf::Color(255,255,255,255));
    sftitle.setString(title);
    sftitle.setPosition(posx + 15, posy + 5);


    CodeTxT *templog = new CodeTxT;
    logTxT = templog;
    logTxT->SetPosX(15);
    logTxT->SetPosY(posy + 45);
    logTxT->Insert("Welcome to C!");

    current = logTxT;

    CodeTxT *tempcons = new CodeTxT;
    consTxT = tempcons;
    consTxT->Insert("");

//    logTxt.setFont(font);
//    logTxt.setCharacterSize(20);
//    logTxt.setColor(sf::Color(255,255,255,255));
//    logTxt.setString(log);
//    logTxt.setPosition(posx + 5, posy + 30);
//
//    consTxt.setFont(font);
//    consTxt.setCharacterSize(20);
//    consTxt.setColor(sf::Color(255,255,255,255));
//    consTxt.setString(cons);
//    consTxt.setPosition(posx + 5, posy + 30);
}

void LogCons::Draw(sf::RenderWindow *win) {

    win->draw(box);
    win->draw(sftitle);
    win->draw(l);

    if (isCons){
        //win->draw(consTxt);
    } else {
        //win->draw(logTxt);
    }
    Line *temp = current->GetStart();
    while (temp != nullptr){
        sf::Text *todraw = temp->getVal();
        win->draw(*todraw);
        temp = temp->getNext();
    }
}

void LogCons::Switch() {
    if (isCons){
        title = "Log";
        sftitle.setString(title);
        isCons = false;
        current = logTxT;
    } else {
        title = "Console";
        sftitle.setString(title);
        isCons = true;
        current = consTxT;
    }
}

