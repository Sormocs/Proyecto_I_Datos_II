/**
 * @file CodeTxT.cpp
 * @author Sergio MB
 * @brief Definicion metodos de las clases CodeTxT y Line
 */
#include <cstring>
#include "SFML/Graphics.hpp"
#include "CodeTxT.h"

/**
 * @brief Constructor de la clase Line
 */
Line::Line() {}

/**
 * @brief Destructor de la clase Line.
 */
Line::~Line() {
    delete(this);
}

/**
 * @brief Asigna la linea siguiente..
 * @param Prev
 */
void Line::SetNext(Line* Next) {
    next = Next;
}

/**
 * @brief Asigna la linea previa.
 * @param Prev
 */
void Line::SetPrev(Line* Prev) {
    prev = Prev;
}

/**
 * @brief Asigna el numero de linea.
 * @param line
 */
void Line::SetLine(int line) {
    this->lnum = line;
}

/**
 * @brief Asigna un objeto de texto a la linea.
 * @param Val
 */
void Line::SetVal(sf::Text* Val) {
    val = Val;
}

/**
 * @brief Actualiza el string del objeto de texto de la linea.
 * @param text
 */
void Line::SetStr(std::string text) {
    val->setString(text);
}

/**
 * Obtiene el texto de la linea en el objeto de texto de sfml.
 * @return sf::Text*
 */
sf::Text* Line::getVal() {
    return val;
}

/**
 * @brief Obtiene la linea siguiente
 * @return
 */
Line* Line::getNext() {
    return next;
}

/**
 * @brief Obtiene la linea anterior
 * @return
 */
Line* Line::getPrev() {
    return prev;
}

/**
 * Obtiene el numero de la linea.
 * @return
 */
int Line::getLine() {
    return lnum;
}

//LIST_CODE
/**
 * @brief Constructor de la clase COdeTxT
 */
CodeTxT::CodeTxT() {

    posx = 0;
    posy = 0;
    lineNum = 1;
    fsize = 20;
    font.loadFromFile("../Fonts/consolas.ttf");

}

/**
 * @brief Destructor de la clase CodeTxT.
 */
CodeTxT::~CodeTxT() {
    delete this;
}

/**
 * Se encarga de insertar una linea en la lista del codigo.
 * @param str
 */
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

/**
 * @brief Asigna un valor en X para la nueva linea.
 * @param X
 */
void CodeTxT::SetPosX(int X) {
    posx = X;
}

/**
 * @brief Asigna el valor de la posicion el y para la nueva linea
 * @param Y
 */
void CodeTxT::SetPosY(int Y) {
    posy = Y;
}

/**
 * Obtiene la primera linea
 * @return Line*
 */
Line* CodeTxT::GetStart() {
    return start;
}

/**
 * @brief Obtiene la ultima linea.
 * @return Line*
 */
Line* CodeTxT::GetEnd() {
    return end;
}

/**
 * @brief Obtiene la posiocion en X por la que va colocando lineas.
 * @return int
 */
int CodeTxT::GetX() {
    return posx;
}

/**
 * @brief Obtiene la posiocion en Y por la que va colocando lineas.
 * @return int
 */
int CodeTxT::GetY() {
    return posy;
}

/**
 * Mueve hacia arriba o abajo todas las lineas dependiendo del parametro que reciba.
 * @param dir
 */
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

/**
 * @brief Se encarga de enviar una linea cada vez que se llama, retorna false al terminar.
 * @return bool
 */
bool CodeTxT::SendTxT() {

    if (tosend == end){
        std::string tosendstr = tosend->getVal()->getString();
        Client::getInstance()->Send(tosendstr);
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

/**
 * @brief Asigna el tamano de letra de las lineas.
 * @param fsize
 */
void CodeTxT::SetFsize(int fsize) {

    this->fsize = fsize;

}

/**
 * @brief Asigna un nuevo valor a la primera linea.
 * @param newstart
 */
void CodeTxT::SetStart(Line* newstart) {
    start = newstart;
}
/**
 * @brief Asigna el valor de la linea a enviar de vuelta a la primera
 */
void CodeTxT::ResetToSend() {
    tosend = start;
}
