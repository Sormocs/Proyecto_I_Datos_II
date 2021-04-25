#include "Button.h"
#include "SFML/Graphics.hpp"
#include "Client.h"
#include <thread>
#include <iostream>
#pragma once

class Line{
private:
    int x,y,lnum;
    sf::Text *val;
    Line* next = nullptr;
    Line* prev = nullptr;

public:
    Line();
    ~Line();
    Line* getNext();
    Line* getPrev();
    sf::Text* getVal();
    int getLine();
    void SetNext(Line*);
    void SetPrev(Line*);
    void SetVal(sf::Text*);
    void SetLine(int);
    void SetStr(std::string);
};

class CodeTxT {

private:
    int lineNum, posx, posy;
    Line *start = nullptr;
    Line *end = nullptr;
    sf::Font font;

public:
    CodeTxT();
    ~CodeTxT();
    void Insert(std::string);
    void SetPosX(int);
    void SetPosY(int);
    int GetY();
    int GetX();
    Line* GetStart();
    Line* GetEnd();
    void CoutLineNum();
    void CoutCode();
    void Move(std::string);
    void SendTxT();

};


