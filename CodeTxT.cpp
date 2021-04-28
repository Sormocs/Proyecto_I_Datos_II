#include <cstring>
#include "SFML/Graphics.hpp"
#include "CodeTxT.h"

Line::Line() {}

Line::~Line() {
    delete(this);
}

void Line::SetNext(Line* Next) {
    next = Next;
}

void Line::SetPrev(Line* Prev) {
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
    fsize = 20;
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
    txt->setCharacterSize(fsize);
    txt->setPosition(posx,posy);

    if (start == nullptr){

        Line *temp = new Line();
        temp->SetVal(txt);
        temp->SetNext(nullptr);
        temp->SetPrev(nullptr);
        temp->SetLine(lineNum);
        start = temp;
        tosend = start;
        end = start;
        lineNum ++;

    } else{

        Line *temp = new Line();
        temp->SetVal(txt);
        temp->SetLine(lineNum);
        end->SetNext(temp);
        temp->SetNext(nullptr);
        end = temp;
        lineNum ++;

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
    std::cout << "Current amount of lines: " << num << std::endl;
}

void CodeTxT::CoutCode() {
    Line *temp = start;
    while(temp != nullptr){
        std::string gotten = temp->getVal()->getString();
        std::cout << gotten << std::endl;
        temp = temp->getNext();
    }
}

void CodeTxT::Move(std::string dir) {
    Line* temp = start;
    if (dir == "up"){
        while (temp != nullptr){
            temp->getVal()->setPosition(posx,temp->getVal()->getPosition().y-24);
            temp = temp->getNext();
        }
    } else {
        while (temp != nullptr){
            temp->getVal()->setPosition(posx,temp->getVal()->getPosition().y+24);
            temp = temp->getNext();
        }
    }
}
using namespace std::literals::chrono_literals;
bool CodeTxT::SendTxT() {

    if (tosend == end){
        std::string tosendstr = tosend->getVal()->getString();
        Client::getInstance()->Send(tosendstr);
        std::this_thread::sleep_for(0.5s);
        Client::getInstance()->Send("FINISHED");
        tosend = start;
        return false;
    } else {
        std::string tosendstr = tosend->getVal()->getString();
        Client::getInstance()->Send(tosendstr);
        tosend = tosend->getNext();
        return true;
    }
}

void CodeTxT::SetFsize(int fsize) {

    this->fsize = fsize;

}


void CodeTxT::SetStart(Line* newstart) {
    start = newstart;
}
