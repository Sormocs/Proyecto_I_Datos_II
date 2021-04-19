#include <cstring>
#include "SFML/Graphics.hpp"
#include "CodeTxT.h"

Line::Line() {}

Line::~Line() {
    delete(this);
}

void Line::SetNext(Line *Next) {
    next = Next;
}

void Line::SetPrev(Line *Prev) {
    prev = Prev;
}

void Line::SetLine(int line) {
    this->lnum = line;
}

void Line::SetVal(sf::Text* Val) {
    val = Val;
}

void Line::SetStr(std::string text) {
    val->setString(text);
}

sf::Text* Line::getVal() {
    return val;
}

Line* Line::getNext() {
    return next;
}

Line* Line::getPrev() {
    return prev;
}

int Line::getLine() {
    return lnum;
}

//LIST_CODE

CodeTxT::CodeTxT() {

    posx = 0;
    posy = 0;
    lineNum = 1;
    font.loadFromFile("../Fonts/consolas.ttf");

}

CodeTxT::~CodeTxT() {
    delete this;
}

void CodeTxT::Insert(std::string str) {
    sf::Text *txt = new sf::Text;
    txt->setString(str);
    txt->setFont(font);
    txt->setColor(sf::Color(255,255,255,255));
    txt->setCharacterSize(20);
    txt->setPosition(posx,posy);

    if (start == nullptr){
        Line *temp = new Line();
        temp->SetVal(txt);
        temp->SetNext(nullptr);
        temp->SetPrev(nullptr);
        temp->SetLine(lineNum);
        start = temp;
        end = start;
        std::cout << "Insert lnum: " << lineNum << std::endl;
        lineNum ++;
        CoutLineNum();
    } else{
        Line *temp = new Line();
        temp->SetVal(txt);
        temp->SetLine(lineNum);
        temp->SetPrev(end);
        temp->SetNext(nullptr);
        end = temp;
        std::cout << "Insert lnum: " << lineNum << std::endl;
        lineNum ++;
        CoutLineNum();
    }
}

void CodeTxT::Delete(Line *delme) {

    Line *temp = start;
    while (temp != nullptr){
        if (temp == delme) {
            std::cout << "is in" << std::endl;
            temp->getPrev()->SetNext(temp->getNext());
            std::cout << "first done" << std::endl;
            temp->getNext()->SetPrev(temp->getPrev());
            std::cout << "second done" << std::endl;
            delete(temp);
            std::cout << "deleted" << std::endl;
            CoutLineNum();
            break;
        }
        else{
            temp = temp->getNext();
        }
    }
}

void CodeTxT::SetPosX(int X) {
    posx = X;
}

void CodeTxT::SetPosY(int Y) {
    posy = Y;
}

Line* CodeTxT::GetStart() {
    return start;
}

Line* CodeTxT::GetEnd() {
    return end;
}

int CodeTxT::GetX() {
    return posx;
}

int CodeTxT::GetY() {
    return posy;
}

void CodeTxT::CoutLineNum() {
    Line *temp = start;
    int num = 0;
    while(temp != nullptr){
        num++;
        temp = temp->getNext();
    }
    std::cout << num << std::endl;
}